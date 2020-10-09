#include <SoftwareSerial.h>
#include "ArdoVal.h"
#include "ArdoObj.h"
#include "ArdoEnv.h"
#include "MainLoop.h"
#include "CncStep.h"
#include "CncCtrl.h"

#ifndef SKETCH_COMPILE 
  #define CNC_CONTROLLER_LOG_FUNCTION()  \
    { \
        const wxString logStr(wxString::Format("Controller::%s", __FUNCTION__)); \
        ARDO_DEBUG_MESSAGE('D', logStr); \
    }
#else
  #define CNC_CONTROLLER_LOG_FUNCTION()
#endif

/////////////////////////////////////////////////////////////////////////////////////
namespace CtrlParameter {
  
  template <class T>
  void print(unsigned char pid, T value, int8_t indent=1) {
    for (auto i=0; i<indent; i++) Serial.print(BLANK1); \
    Serial.print(pid);   Serial.print(TEXT_SEPARATOR); \
    Serial.print(value); Serial.write(TEXT_CLOSE);
  }
};

/////////////////////////////////////////////////////////////////////////////////////
CncArduinoController::CncArduinoController()
/////////////////////////////////////////////////////////////////////////////////////
: ArduinoCmdDecoderGetter       () 
, ArduinoCmdDecoderSetter       ()
, ArduinoCmdDecoderMove         () 
, ArduinoCmdDecoderMoveSequence ()
, ArduinoPositionRenderer       ()
, ArduinoAccelManager           ()
, X                             ( new CncAxisX(StepperSetup( this, PIN_X_STP, PIN_X_DIR, PIN_X_MIN_LIMIT, PIN_X_MAX_LIMIT, PID_INC_DIRECTION_VALUE_X )) )
, Y                             ( new CncAxisY(StepperSetup( this, PIN_Y_STP, PIN_Y_DIR, PIN_Y_MIN_LIMIT, PIN_Y_MAX_LIMIT, PID_INC_DIRECTION_VALUE_Y )) )
, Z                             ( new CncAxisZ(StepperSetup( this, PIN_Z_STP, PIN_Z_DIR, PIN_Z_MIN_LIMIT, PIN_Z_MAX_LIMIT, PID_INC_DIRECTION_VALUE_Z )) )
, testManager                   (NULL)
, impulseCalculator             ()
, lastI2CData                   ()
, posReplyState                 (OFF)
, probeMode                     (OFF)
, pause                         (OFF)
, I2CAvailable                  (false)
, interactiveMoveActive         (false)
, cfgF1000_MMSEC                (0)
, cmsF1000_MMMin                (0)
, posReplyCounter               (0)
, posReplyThreshold             (100)
, tsMoveStart                   (0L)
, tsMoveLast                    (0L)
, interactiveValueX             (0)
, interactiveValueY             (0)
, interactiveValueZ             (0)
{  
  ArduinoPositionRenderer::setupSteppers(X, Y, Z);
}
/////////////////////////////////////////////////////////////////////////////////////
CncArduinoController::~CncArduinoController() {
/////////////////////////////////////////////////////////////////////////////////////
  delete X; X = NULL;
  delete Y; Y = NULL;
  delete Z; Z = NULL;
}
/////////////////////////////////////////////////////////////////////////////////////
void CncArduinoController::printConfig() {
/////////////////////////////////////////////////////////////////////////////////////
  int limitState = -1, supportState = -1;
  if ( isI2CAvailable() == true ) {
    if ( ArduinoMainLoop::readI2CSlave(lastI2CData) ) {
      limitState   = (int)lastI2CData.limitState;
      supportState = (int)lastI2CData.supportState;
    }
  }

  Serial.print(PID_CONTROLLER); Serial.print(TEXT_SEPARATOR); Serial.write(TEXT_CLOSE);

    CtrlParameter::print(PID_SETUP_ID,                         SETUP_ID);
    CtrlParameter::print(PID_POS_REPLY_THRESHOLD,              getPosReplyThreshold());
    CtrlParameter::print(PID_PROBE_MODE,                       isProbeMode());
    CtrlParameter::print(PID_ENABLE_STEPPERS,                  AE::digitalRead(PIN_ENABLE_STEPPER));
    CtrlParameter::print(PID_TOOL_SWITCH,                      AE::digitalRead(PIN_ENABLE_TOOL));
    CtrlParameter::print(PID_I2C_AVAILABEL,                    isI2CAvailable());
    CtrlParameter::print(PID_I2C_LIMIT_VALUE,                  limitState);
    CtrlParameter::print(PID_I2C_SUPPORT_VALUE,                supportState);

    X->printConfig();
    Y->printConfig();
    Z->printConfig();
}
/////////////////////////////////////////////////////////////////////////////////////
bool CncArduinoController::evaluateI2CAvailable() {
/////////////////////////////////////////////////////////////////////////////////////
  CNC_CONTROLLER_LOG_FUNCTION();
  
  // first: try to request data
  I2CAvailable = ArduinoMainLoop::readI2CSlave(lastI2CData);

  // On demand try a second one
  if ( I2CAvailable == false ) {
    AE::delay(1000);
    I2CAvailable = ArduinoMainLoop::readI2CSlave(lastI2CData);
  }

  ARDO_DEBUG_VALUE("I2CAvailable", I2CAvailable);
  return I2CAvailable;
}
/////////////////////////////////////////////////////////////////////////////////////
bool CncArduinoController::evaluateI2CData() {
/////////////////////////////////////////////////////////////////////////////////////
  if ( isI2CAvailable() == false )
    return false;
  
  // request data
  return ArduinoMainLoop::readI2CSlave(lastI2CData);
}
/////////////////////////////////////////////////////////////////////////////////////
void CncArduinoController::reset() {
/////////////////////////////////////////////////////////////////////////////////////
    CNC_CONTROLLER_LOG_FUNCTION();

    posReplyCounter     = 0;
    posReplyThreshold   = 100;

    posReplyState       = false;
    probeMode           = false;

    interactiveValueX   = 0;
    interactiveValueY   = 0;
    interactiveValueZ   = 0;
    
    X->reset();
    Y->reset();
    Z->reset();
    
    X->resetPosition();
    Y->resetPosition();
    Z->resetPosition();
    
    ArduinoAccelManager::reset();
}
/////////////////////////////////////////////////////////////////////////////////////
void CncArduinoController::turnOff() {
/////////////////////////////////////////////////////////////////////////////////////
  switchToolState (TOOL_STATE_OFF, FORCE);
  enableStepperPin(ENABLE_STATE_OFF);
}
/////////////////////////////////////////////////////////////////////////////////////
bool CncArduinoController::isReadyToRun() {
/////////////////////////////////////////////////////////////////////////////////////
  CNC_CONTROLLER_LOG_FUNCTION();
  bool ret = true;

  if ( READ_EXT_INNTERRUPT_PIN == EXTERNAL_INTERRRUPT_ON ) {
    LastErrorCodes::clear(); 
    ArduinoMainLoop::pushMessage(MT_ERROR, E_EXTERNEL_INTERRUPT); 
    ret = false; 
  }

  if ( X->isReadyToRun() == false ) { 
    ArduinoMainLoop::pushMessage(MT_ERROR, E_STEPPER_NOT_READY_TO_RUN, "X");    
    ret = false; 
  }
  
  if ( Y->isReadyToRun() == false ){ 
    ArduinoMainLoop::pushMessage(MT_ERROR, E_STEPPER_NOT_READY_TO_RUN, "Y");    
    ret = false; 
  }
  
  if ( Z->isReadyToRun() == false ) { 
    ArduinoMainLoop::pushMessage(MT_ERROR, E_STEPPER_NOT_READY_TO_RUN, "Z");
    ret = false; 
  }

  if ( isReadyToRender() == false) {
    // message already created by class ArduinoPositionRenderer
    ret = false;
  }
  
  return ret;
}
/////////////////////////////////////////////////////////////////////////////////////
void CncArduinoController::broadcastInterrupt() {
/////////////////////////////////////////////////////////////////////////////////////
  // Turn off ...
  switchToolState (TOOL_STATE_OFF, FORCE);
  enableStepperPin(ENABLE_STATE_OFF);

  // Show Interrupt LED
  ArduinoMainLoop::switchOutputPinState(PIN_INTERRUPT_LED, ON);

  X->interrupt();
  Y->interrupt();
  Z->interrupt();
  
  ArduinoMainLoop::pushMessage(MT_ERROR, E_INTERRUPT);
}
/////////////////////////////////////////////////////////////////////////////////////
bool CncArduinoController::sendCurrentLimitStates(bool force) {
/////////////////////////////////////////////////////////////////////////////////////
  const bool xMin = READ_LMT_PIN_X_MIN == LimitSwitch::LIMIT_SWITCH_ON;
  const bool xMax = READ_LMT_PIN_X_MAX == LimitSwitch::LIMIT_SWITCH_ON;
  const bool yMin = READ_LMT_PIN_Y_MIN == LimitSwitch::LIMIT_SWITCH_ON;
  const bool yMax = READ_LMT_PIN_Y_MAX == LimitSwitch::LIMIT_SWITCH_ON;
  const bool zMin = READ_LMT_PIN_Z_MIN == LimitSwitch::LIMIT_SWITCH_ON;
  const bool zMax = READ_LMT_PIN_Z_MAX == LimitSwitch::LIMIT_SWITCH_ON;

  CncInterface::ILS::States ls( xMin, xMax, yMin, yMax,zMin, zMax );   
  
  // the states will be only sent if one of them is activ or they should be forced
  if ( ls.hasLimits() || force )
    ArduinoMainLoop::writeLongValues(PID_LIMIT, ls.xLimit(), ls.yLimit(), ls.zLimit());
    
  return ls.hasLimits();
}
/////////////////////////////////////////////////////////////////////////////////////
bool CncArduinoController::processHeartbeat() {
/////////////////////////////////////////////////////////////////////////////////////
  unsigned char limitState    = 0;
  unsigned char supportState  = 0;

  const bool xMin = READ_LMT_PIN_X_MIN == LimitSwitch::LIMIT_SWITCH_ON;
  const bool xMax = READ_LMT_PIN_X_MAX == LimitSwitch::LIMIT_SWITCH_ON;
  const bool yMin = READ_LMT_PIN_Y_MIN == LimitSwitch::LIMIT_SWITCH_ON;
  const bool yMax = READ_LMT_PIN_Y_MAX == LimitSwitch::LIMIT_SWITCH_ON;
  const bool zMin = READ_LMT_PIN_Z_MIN == LimitSwitch::LIMIT_SWITCH_ON;
  const bool zMax = READ_LMT_PIN_Z_MAX == LimitSwitch::LIMIT_SWITCH_ON;

  CncInterface::ILS::States ls( xMin, xMax, yMin, yMax,zMin, zMax );   
  limitState = ls.getValue();

  ArduinoMainLoop::sendHeartbeat(limitState, supportState);
  return true;
}
/////////////////////////////////////////////////////////////////////////////////////
bool CncArduinoController::evaluateLimitStates(int8_t& xLimit, int8_t& yLimit, int8_t& zLimit) {
/////////////////////////////////////////////////////////////////////////////////////
  const bool xMin = READ_LMT_PIN_X_MIN == LimitSwitch::LIMIT_SWITCH_ON;
  const bool xMax = READ_LMT_PIN_X_MAX == LimitSwitch::LIMIT_SWITCH_ON;
  const bool yMin = READ_LMT_PIN_Y_MIN == LimitSwitch::LIMIT_SWITCH_ON;
  const bool yMax = READ_LMT_PIN_Y_MAX == LimitSwitch::LIMIT_SWITCH_ON;
  const bool zMin = READ_LMT_PIN_Z_MIN == LimitSwitch::LIMIT_SWITCH_ON;
  const bool zMax = READ_LMT_PIN_Z_MAX == LimitSwitch::LIMIT_SWITCH_ON;

  CncInterface::ILS::States ls( xMin, xMax, yMin, yMax,zMin, zMax );   
  xLimit = ls.xLimit();
  yLimit = ls.yLimit();
  zLimit = ls.zLimit();
    
  return ls.hasLimits();
}
///////////////////////////////////////////////////////
byte CncArduinoController::performTest() {
///////////////////////////////////////////////////////
  #ifdef USE_CNC_TEST
    if ( testManager == NULL )
      testManager = new ArduinoTestManager(this);
      
    return testManager->performTest();
  #endif

  ArduinoMainLoop::pushMessage(MT_ERROR, E_UNKNOW_COMMAND, CMD_PERFORM_TEST);

  return RET_OK;
}
/////////////////////////////////////////////////////////////////////////////////////
void CncArduinoController::setSpeedValue_MMSec1000(int32_t f, bool activateAcceleration) {
/////////////////////////////////////////////////////////////////////////////////////
  cfgF1000_MMSEC = ArdoObj::absolute(f);
  ArduinoAccelManager::activate(activateAcceleration);

  ARDO_DEBUG_VALUE("F [mm/sec]", cfgF1000_MMSEC / 1000.0)
  if ( activateAcceleration == false ) {
    ARDO_DEBUG_VALUE("ArduinoAccelManager", "Is deactivated!")
  }
}
/////////////////////////////////////////////////////////////////////////////////////
void CncArduinoController::setupAccelProfile(const ArduinoCmdDecoderSetter::Result& st) {
/////////////////////////////////////////////////////////////////////////////////////
  typedef ArduinoAccelManager::Function Function;
  Function fA(st.values[ 6].asFloat(), st.values[ 7].asFloat(), st.values[ 8].asFloat());
  Function fD(st.values[ 9].asFloat(), st.values[10].asFloat(), st.values[11].asFloat());

  // FEEDRATE_X,Y,Z         = 3
  // PULSE_WIDTH_HIGH_X,Y,Z = 3
  // FA                     = 3
  // FD                     = 3
  if ( st.valueCount != 3 + 3 + 3 + 3 )
  {
    // Function the members Feedrate as well as HighPulseWidth leave unchanged
    // Function fA, fD was initilaizes with default values
    ArduinoMainLoop::pushMessage(MT_ERROR, E_INVALID_PARAM_STREAM_LEN);       
    
  } else {  

    X->setFeedrate(st.values[0].asFloat());
    Y->setFeedrate(st.values[1].asFloat());
    Z->setFeedrate(st.values[2].asFloat());

    X->setHighPulseWidth(round(st.values[3].asFloat()));
    Y->setHighPulseWidth(round(st.values[4].asFloat()));
    Z->setHighPulseWidth(round(st.values[5].asFloat()));
  }

  // Pepare some speed  values  
  ArduinoAccelManager::Setup(X->getFeedrate(), Y->getFeedrate(), Z->getFeedrate());
  ArduinoAccelManager::initialize(fA, fD);  

  if ( true ) {
    ARDO_DEBUG_VALUE("AccelProfile::FeedrateX", X->getFeedrate())
    ARDO_DEBUG_VALUE("AccelProfile::FeedrateY", Y->getFeedrate())
    ARDO_DEBUG_VALUE("AccelProfile::FeedrateZ", Z->getFeedrate())
    
    ARDO_DEBUG_VALUE("AccelProfile::HighPulseWidthX", X->getHighPulseWidth())
    ARDO_DEBUG_VALUE("AccelProfile::HighPulseWidthY", Y->getHighPulseWidth())
    ARDO_DEBUG_VALUE("AccelProfile::HighPulseWidthZ", Z->getHighPulseWidth())

    ARDO_DEBUG_VALUE("AccelProfile::fA.A_1000", fA.getA_1000())
    ARDO_DEBUG_VALUE("AccelProfile::fA.B_1000", fA.getB_1000())
    ARDO_DEBUG_VALUE("AccelProfile::fA.C_1000", fA.getC_1000())
    ARDO_DEBUG_VALUE("AccelProfile::fD.A_1000", fD.getA_1000())
    ARDO_DEBUG_VALUE("AccelProfile::fD.B_1000", fD.getB_1000())
    ARDO_DEBUG_VALUE("AccelProfile::fD.C_1000", fD.getC_1000())
  }
}
/////////////////////////////////////////////////////////////////////////////////////
void CncArduinoController::switchToolState(bool state, bool force) {
/////////////////////////////////////////////////////////////////////////////////////
  if ( force == false ) {
    // Don't enable the tool during a probe mode phase
    if ( isProbeMode() == ON ) {
      AE::digitalWrite(PIN_ENABLE_TOOL, TOOL_STATE_OFF);
      return;
    }
  }
  
  AE::digitalWrite(PIN_ENABLE_TOOL, state);

  // give the tool a portion of time to run properly
  if ( state == TOOL_STATE_ON )
    AE::delay(1000);
}
//////////////////////////////////////////////////////////////////////////////
bool CncArduinoController::enableStepperPin(bool state){
//////////////////////////////////////////////////////////////////////////////
  if ( isProbeMode() == OFF )   AE::digitalWrite(PIN_ENABLE_STEPPER, state);
  else                          AE::digitalWrite(PIN_ENABLE_STEPPER, ENABLE_STATE_OFF);

  AE::delayMicroseconds(10);
  return state;
}
//////////////////////////////////////////////////////////////////////////////
bool CncArduinoController::getEnableStepperPinState(){
//////////////////////////////////////////////////////////////////////////////
  return AE::digitalRead(PIN_ENABLE_STEPPER);
}
/////////////////////////////////////////////////////////////////////////////////////
bool CncArduinoController::isAnyLimitActive() {
/////////////////////////////////////////////////////////////////////////////////////
  static int8_t xLimit, yLimit, zLimit;
  return evaluateLimitStates(xLimit, yLimit, zLimit);
}
/////////////////////////////////////////////////////////////////////////////////////
bool CncArduinoController::observeSerialFrontByte(byte& retValue) {
/////////////////////////////////////////////////////////////////////////////////////
  byte serialFrontByte = CMD_INVALID;

  if ( ArduinoMainLoop::peakSerial(serialFrontByte) == false ) {
    // nothing available
    retValue = RET_OK;
    return true;
  }

  if ( ArdoObj::isSignal(serialFrontByte) == true ) {
    // remove the signal from serial
    Serial.read();
    
    // process the signal
    return processSignal(serialFrontByte, retValue);
  }

  // no signal detected, leave serial unchanged
  retValue = RET_OK;
  return true;
}
/////////////////////////////////////////////////////////////////////////////////////
byte CncArduinoController::acceptGetter() {
/////////////////////////////////////////////////////////////////////////////////////
  return decodeGetter();  
}
/////////////////////////////////////////////////////////////////////////////////////
byte CncArduinoController::acceptSetter() {
/////////////////////////////////////////////////////////////////////////////////////
  return decodeSetter();    
}
/////////////////////////////////////////////////////////////////////////////////////
void CncArduinoController::updateInteractiveMoveValues(int8_t dx, int8_t dy, int8_t dz) {
/////////////////////////////////////////////////////////////////////////////////////
  interactiveValueX = dx;
  interactiveValueY = dy;
  interactiveValueZ = dz;
}
/////////////////////////////////////////////////////////////////////////////////////
byte CncArduinoController::cancelInteractiveMove(byte) {
/////////////////////////////////////////////////////////////////////////////////////  
  cmsF1000_MMMin = FLT_FACT;
  ArduinoAccelManager::finalize();

  interactiveMoveActive = false;
  updateInteractiveMoveValues(0, 0, 0);
  
  return RET_OK;  
}
/////////////////////////////////////////////////////////////////////////////////////
byte CncArduinoController::acceptInteractiveMove(byte) {
/////////////////////////////////////////////////////////////////////////////////////
  if ( ArduinoAccelManager::isInteractiveMoveType() == true ) {
    ArduinoMainLoop::pushMessage(MT_ERROR, E_OTHER_MOVE_CMD_ACTIVE);
    return RET_ERROR;
  }
  
  // For intractive moves the impulse count at the move start isn't defined - by concept.
  // Therefore, to get a fully supported acceleration at the begining a value of 0 is used here,
  // which initialzes the accel manager to the interactive mode. The deacceleration phase isn't much
  // imported here, because we can loose steps . . . 
  const uint32_t defaultImpulses = 0;
  if ( cfgF1000_MMSEC && ArduinoAccelManager::initMove(defaultImpulses, cfgF1000_MMSEC) == false )
    return RET_ERROR;

  // initialize movement
  updateInteractiveMoveValues(0, 0, 0);

  byte ret    = RET_OK;
  tsMoveStart = ArdoTs::now();
  tsMoveLast  = tsMoveStart;

  setPosReplyState(true);
  setPosReplyThreshold(posReplyThreshold);
  setProbeMode(OFF);
  enableStepperPin(ENABLE_STATE_ON);

  interactiveMoveActive = true;
  while ( interactiveMoveActive == true ) {
    ret = directMove(interactiveValueX, interactiveValueY, interactiveValueZ);
    
    if ( ret != RET_OK )
      break;
  }

  cancelInteractiveMove(0);
  sendCurrentPositions(PID_XYZ_POS_MAJOR, true);
  setPosReplyState(false);
  
  return ret;  
}
/////////////////////////////////////////////////////////////////////////////////////
byte CncArduinoController::acceptMove(byte cmd) {
/////////////////////////////////////////////////////////////////////////////////////
  if ( ArduinoAccelManager::isInteractiveMoveType() == true ) {
    ArduinoMainLoop::pushMessage(MT_ERROR, E_OTHER_MOVE_CMD_ACTIVE);
    return RET_ERROR;
  }

  setPosReplyState(true);
  const byte ret = decodeMove(cmd);

  if ( ret == RET_QUIT ) {
    // 0.0 isn't valid here because it will be ignored
    cmsF1000_MMMin = FLT_FACT;
    ArduinoAccelManager::finalize();
  }
  
  sendCurrentPositions(PID_XYZ_POS_MAJOR, true);
  setPosReplyState(false);
  return ret;
}
/////////////////////////////////////////////////////////////////////////////////////
byte CncArduinoController::acceptMoveSequence(byte cmd) {
/////////////////////////////////////////////////////////////////////////////////////
  if ( ArduinoAccelManager::isInteractiveMoveType() == true ) {
    ArduinoMainLoop::pushMessage(MT_ERROR, E_OTHER_MOVE_CMD_ACTIVE);
    return RET_ERROR;
  }

  setPosReplyState(true);
  const byte ret = decodeMoveSequence(cmd);
  
  sendCurrentPositions(PID_XYZ_POS_MAJOR, true);
  setPosReplyState(false);
  return ret;
}
/////////////////////////////////////////////////////////////////////////////////////
bool CncArduinoController::processSignal(byte sig) { byte b; return processSignal(sig, b); }
bool CncArduinoController::processSignal(byte sig, byte& retValue) {
/////////////////////////////////////////////////////////////////////////////////////
  switch ( sig ) {
    case SIG_SOFTWARE_RESET:
                #ifdef SKETCH_COMPILE
                  //softwareReset();   
                #endif  
                return false;
    
    // interrupt handling
    case SIG_INTERRUPPT:
                // dont remove the signal from serial, so an explizit reset have to be called by the interface
                broadcastInterrupt();

                // Signalize an error
                retValue = RET_INTERRUPT;
                return false;

    case SIG_HALT:
                // Options:
                //  - Returning false here signalize an error and the complete run cycle (PC) stopps as a result.
                //  - Returning true here stopps the current move (while loop), so far so good, but the current run cycle 
                //    continue with the next existing move command which is not the meaning of HALT.
                switchToolState(TOOL_STATE_OFF, FORCE);
                
                retValue = RET_HALT;
                return false;
                
    case SIG_QUIT_MOVE:
                cancelInteractiveMove(SIG_QUIT_MOVE);
                retValue = RET_QUIT;
                return false; 

    case SIG_UPDATE:
                // remove the signal from serial
                return processSignalUpdate(retValue);

    case SIG_PAUSE:
                pause = PAUSE_ACTIVE;
                
                // Don't return here - see the pause handling below
                break;

    case SIG_RESUME:
                pause = PAUSE_INACTIVE;

                // Don't return here - see the pause handling below
                break;
  }


  // ----------------------------------------------------------
  // pause handling
  if ( pause == PAUSE_ACTIVE ) {

     static const short PAUSE_WAIT_DELAY = 50;
     static const short HB_MOD           = 1000 / PAUSE_WAIT_DELAY;
     
     switchToolState( pause == PAUSE_ACTIVE ? TOOL_STATE_OFF : TOOL_STATE_ON, FORCE);

     // loop
     unsigned short counter = 0;
     while ( ArduinoMainLoop::checkSerialForPauseCommands(pause) == PAUSE_ACTIVE ) {
         
      if ( counter%HB_MOD == 0 )
        processHeartbeat();
        
      AE::delay(PAUSE_WAIT_DELAY);
      counter ++;
     }
     
     pause = PAUSE_INACTIVE;
     switchToolState( pause == PAUSE_ACTIVE ? TOOL_STATE_OFF : TOOL_STATE_ON, FORCE);
  }
  
  retValue = RET_OK;
  return true;
}
/////////////////////////////////////////////////////////////////////////////////////
bool CncArduinoController::processSignalUpdate(byte& retValue) {
/////////////////////////////////////////////////////////////////////////////////////
  byte b[1];
  
  // read length
  if ( !ArduinoMainLoop::readSerialBytesWithTimeout(b, 1) )
    return false;

  const int8_t cmdLen = (int8_t)b[0];
    
  // read PID
  if ( !ArduinoMainLoop::readSerialBytesWithTimeout(b, 1) )
    b[0] = 0;

  bool ret = false;
  switch ( b[0] ) {
    
    case PID_XYZ_INTERACTIVE_POS: {
      int32_t dx; if ( ArduinoMainLoop::readInt8(dx) == false )    dx = 0;
      int32_t dy; if ( ArduinoMainLoop::readInt8(dy) == false )    dy = 0;
      int32_t dz; if ( ArduinoMainLoop::readInt8(dz) == false )    dz = 0;

      // Check the serail again
      byte serialFrontByte = CMD_INVALID;
      if ( ArduinoMainLoop::peakSerial(serialFrontByte) == true ) {
        // Skip this command if one of the following commands is present as next
        switch ( serialFrontByte ) {
          case SIG_QUIT_MOVE:
          case SIG_UPDATE:    Serial.read();
                              return processSignal(serialFrontByte, retValue);
        }
      }

      // init the movment update
      // As Int8 to resolve also negative values
      updateInteractiveMoveValues((int8_t)dx, (int8_t)dy, (int8_t)dz);
      
      ret       = true;
      retValue  = RET_OK;
      
      break;
    }
    
    default: {
      
      // remove unknown update
      for( int i = 0; i < ArdoObj::minimum(Serial.available(), (int)cmdLen); i++)
        Serial.read();
        
      ret       = false;
      retValue  = RET_ERROR;
    }
  }

  return ret;
}
/////////////////////////////////////////////////////////////////////////////////////
void CncArduinoController::sendCurrentPositions(unsigned char pid, bool force) {
/////////////////////////////////////////////////////////////////////////////////////
  if ( posReplyState == false )
    return;

  if ( isReplyDue() || force == true ) 
  {
    posReplyCounter = 0;

    switch ( pid ) {
      case PID_X_POS: ArduinoMainLoop::writeLongValue(pid, X->getPosition());
                      break;
                      
      case PID_Y_POS: ArduinoMainLoop::writeLongValue(pid, Y->getPosition()); 
                      break;
                      
      case PID_Z_POS: ArduinoMainLoop::writeLongValue(pid, Z->getPosition());
                      break;

      case PID_XYZ_POS: 
      case PID_XYZ_POS_MAJOR: 
      case PID_XYZ_POS_DETAIL: 
                      ArduinoMainLoop::writeLongValues(pid, 
                                      X->getPosition(),
                                      Y->getPosition(),
                                      Z->getPosition(),
                                      cmsF1000_MMMin);
                      break;

      default:        ; // do nothing

    }
    
    //Serial.flush();
  }
}
/////////////////////////////////////////////////////////////////////////////////////
byte CncArduinoController::checkRuntimeEnv() {
/////////////////////////////////////////////////////////////////////////////////////
  static byte retValue = RET_ERROR;
  if ( Serial.available() ) {
    if ( observeSerialFrontByte(retValue) == false )
      return retValue;
  }

  if ( READ_EXT_INNTERRUPT_PIN == EXTERNAL_INTERRRUPT_ON ) {
    ArduinoMainLoop::pushMessage(MT_ERROR, E_EXTERNEL_INTERRUPT); 
    return RET_ERROR;
  }

  if ( isProbeMode() == OFF ) {
    
    if ( READ_IS_TOOL_POWERED_PIN == TOOL_STATE_OFF ) {
      ArduinoMainLoop::pushMessage(MT_ERROR, E_TOOL_NOT_ENALED); 
      return RET_ERROR;
    }
  }
  
  return RET_OK;   
}
/////////////////////////////////////////////////////////////////////////////////////
void CncArduinoController::notifyMovePartBefore() {
/////////////////////////////////////////////////////////////////////////////////////
  RS::stepSignatureIndex = GET_AxisSignatureIndex(RS::stepSignature);
  ArduinoAccelManager::initNextImpulse(RS::stepSignatureIndex);
}
/////////////////////////////////////////////////////////////////////////////////////
void CncArduinoController::notifyMovePartAfter() {
/////////////////////////////////////////////////////////////////////////////////////
  // *******************************************************************************
  // Speed measurement
  //                      cmsF1000_MMMin   = FLT_FACT * 60 * 1000 * [um/us] 
  //                                     --> FLT_FACT * 60 *        [nm/us] 
  //                                     --> FLT_FACT * 60 *        [mm/sec] 
  //                                     --> FLT_FACT *             [mm/min] 
  #define MEASURE_SPEED  \
        if ( bReply ) \
          cmsF1000_MMMin = 60L * FLT_FACT * 1000L * curDistV_UM / ArdoTs::timespan(tsMoveLast); 
  // *******************************************************************************

  // *******************************************************************************
  // delay management
  // #define NO_SPEED_DELAY
  #ifdef NO_SPEED_DELAY
                        #define WAIT_US(us)   {}          
  #else
                        #define WAIT_US(us)   { AE::delayMicroseconds(us); }        
  #endif  
  // *******************************************************************************

  // initalize position management
  posReplyCounter++;
  
  // speed management
  if ( cfgF1000_MMSEC > 0 ) {
    const bool bReply              = isReplyDue();
    const int32_t curDistV_UM      = ArduinoAccelManager::Setup::feedRate_UM[RS::stepSignatureIndex];
    
    // determine the time deviation between the measured and configured sight
    const int32_t currentTimeDistance_US   = getCurrentTargetSpeedDelay_US();

    // don't put anything between the lines of the section below
    {
      // determine the rest delay and perform it
      const int32_t tsShould_US   = tsMoveLast  + currentTimeDistance_US;
      const int32_t rest_US       = tsShould_US - ArdoTs::now();
      if ( rest_US > 3 )
        WAIT_US(rest_US)

      // measure the current speed again on demand
      MEASURE_SPEED
    }

    // this has to be the last action within this function
    tsMoveLast = ArdoTs::now();
  }
  
  // finalize position management
  if ( isReplyDue() )
    sendCurrentPositions(PID_XYZ_POS_DETAIL, false);  

  #undef MEASURE_SPEED
  #undef WAIT_US
}
/////////////////////////////////////////////////////////////////////////////////////
void CncArduinoController::notifyACMStateChange(State ) {
/////////////////////////////////////////////////////////////////////////////////////
}
/////////////////////////////////////////////////////////////////////////////////////
void CncArduinoController::notifyACMInitMove() {
/////////////////////////////////////////////////////////////////////////////////////
}  
/////////////////////////////////////////////////////////////////////////////////////
byte CncArduinoController::setHighPulseWidth(AxisId aid, int32_t width) {
/////////////////////////////////////////////////////////////////////////////////////  
  switch ( aid ) {
    case IDX_X: X->setHighPulseWidth(width); break;
    case IDX_Y: Y->setHighPulseWidth(width); break;
    case IDX_Z: Z->setHighPulseWidth(width); break;
  }

  return RET_OK;
}
/////////////////////////////////////////////////////////////////////////////////////
byte CncArduinoController::setDirection(AxisId aid, int32_t steps) { 
/////////////////////////////////////////////////////////////////////////////////////
  switch ( aid ) {
    case IDX_X: return X->setDirection(steps);
    case IDX_Y: return Y->setDirection(steps);
    case IDX_Z: return Z->setDirection(steps);
  }

  return RET_ERROR;
}
/////////////////////////////////////////////////////////////////////////////////////
byte CncArduinoController::performStep(AxisId aid) {
/////////////////////////////////////////////////////////////////////////////////////
  switch ( aid ) {
    case IDX_X: return X->performStep();
    case IDX_Y: return Y->performStep();
    case IDX_Z: return Z->performStep();
  }

  return RET_ERROR;
}
/////////////////////////////////////////////////////////////////////////////////////
byte CncArduinoController::initiateStep(AxisId aid) {
/////////////////////////////////////////////////////////////////////////////////////
  switch ( aid ) {
    case IDX_X: return X->initiateStep();
    case IDX_Y: return Y->initiateStep();
    case IDX_Z: return Z->initiateStep();
  }

  return RET_ERROR;
}
/////////////////////////////////////////////////////////////////////////////////////
byte CncArduinoController::finalizeStep(AxisId aid) {
/////////////////////////////////////////////////////////////////////////////////////
  switch ( aid ) {
    case IDX_X: return X->finalizeStep();
    case IDX_Y: return Y->finalizeStep();
    case IDX_Z: return Z->finalizeStep();
  }

  return RET_ERROR;
}
/////////////////////////////////////////////////////////////////////////////////////
byte CncArduinoController::process(const ArduinoCmdDecoderGetter::Result& gt) {
/////////////////////////////////////////////////////////////////////////////////////
#ifndef SKETCH_COMPILE   

  #define DBG_GETTER1(p, v1) { \
    if ( AE::ardoConfigGetTraceGetters() ) { \
      ARDO_DEBUG_VALUE("Getter PID", wxString::Format("[%03d] - %s(%ld)", (int)gt.pid, AE::ardoGetPidLabel(gt.pid), v1)); \
    } \
  }
    
  #define DBG_GETTER2(p, v1, v2) { \
    if ( AE::ardoConfigGetTraceGetters() ) { \
      ARDO_DEBUG_VALUE("Getter PID", wxString::Format("[%03d] - %s(%ld, %ld)", (int)gt.pid, AE::ardoGetPidLabel(gt.pid), v1, v2)); \
    } \
  }
    
  #define DBG_GETTER3(p, v1, v2, v3) { \
    if ( AE::ardoConfigGetTraceGetters() ) { \
      ARDO_DEBUG_VALUE("Getter PID", wxString::Format("[%03d] - %s(%ld, %ld, %ld)", (int)gt.pid, AE::ardoGetPidLabel(gt.pid), v1, v2, v3)); \
    } \
  }

#else

  #define DBG_GETTER1(p, v1)
  #define DBG_GETTER2(p, v1, v2)
  #define DBG_GETTER3(p, v1, v2, v3)
  
#endif 

  typedef ArduinoMainLoop AML;

  //---------------------------------------------------------------------------------
  auto writeGetterValue1 = [&](unsigned char pid, int32_t val1 )                              { DBG_GETTER1(pid, val1);             AML::writeGetterValue (pid, val1);              };
  auto writeGetterValue2 = [&](unsigned char pid, int32_t val1, int32_t val2)                 { DBG_GETTER2(pid, val1, val2);       AML::writeGetterValues(pid, val1, val2);        };
  auto writeGetterValue3 = [&](unsigned char pid, int32_t val1, int32_t val2, int32_t val3 )  { DBG_GETTER3(pid, val1, val2, val3); AML::writeGetterValues(pid, val1, val2, val3);  };
  
  auto writeLimitGetter = [&]() {
    int8_t x = LimitSwitch::LIMIT_UNKNOWN;
    int8_t y = LimitSwitch::LIMIT_UNKNOWN;
    int8_t z = LimitSwitch::LIMIT_UNKNOWN;

    evaluateLimitStates(x, y, z);
    writeGetterValue3(PID_LIMIT, x, y, z);
  };

  //---------------------------------------------------------------------------------
  switch ( gt.pid ) {
    
    case PID_QUERY_READY_TO_RUN:          writeGetterValue1(PID_QUERY_READY_TO_RUN,           (int32_t)isReadyToRun()); break;
    case PID_ENABLE_STEPPERS:             writeGetterValue1(PID_ENABLE_STEPPERS,              (int32_t)getEnableStepperPinState()); break;
    
    
    case PID_X_POS:                       writeGetterValue1(PID_X_POS,                        X->getPosition()); break;
    case PID_Y_POS:                       writeGetterValue1(PID_Y_POS,                        Y->getPosition()); break;
    case PID_Z_POS:                       writeGetterValue1(PID_Z_POS,                        Z->getPosition()); break;

    case PID_XY_POS:                      writeGetterValue2(PID_XY_POS,                       X->getPosition(), Y->getPosition()); break;
    case PID_XYZ_POS:                     writeGetterValue3(PID_XYZ_POS,                      X->getPosition(), Y->getPosition(), Z->getPosition()); break;

    case PID_LIMIT:                       writeLimitGetter(); break;
    
    default:                              writeGetterValue1(PID_UNKNOWN, 0);
                                      
                                          AML::pushMessage(MT_ERROR, E_INVALID_GETTER_ID, gt.pid);
                                          return RET_ERROR;
  }

  return RET_OK;
}
/////////////////////////////////////////////////////////////////////////////////////
byte CncArduinoController::process(const ArduinoCmdDecoderSetter::Result& st) {
/////////////////////////////////////////////////////////////////////////////////////
#ifndef SKETCH_COMPILE   
  if ( AE::ardoConfigGetTraceSetters() ) {
    ARDO_DEBUG_VALUE("Setter PID", wxString::Format("[%03d] - %s", (int)st.pid, AE::ardoGetPidLabel(st.pid)));

    wxString values;
    for( int i=0; i<st.valueCount; i++ ) {
      if ( st.values[i].isFloat )  { values.append(wxString::Format("[%d]=%f",  i, st.values[i].asFloat())); } 
      else                         { values.append(wxString::Format("[%d]=%ld", i, st.values[i].l)); }

      if ( i != st.valueCount - 1 )
        values.append(",");
    }

    ARDO_DEBUG_VALUE(" Values", wxString::Format("{%s}", values));
  }
#endif

  typedef ArduinoMainLoop AML;
  //---------------------------------------------------------------------------------
  switch ( st.pid ) {
    case PID_X_POS:                   X->setPosition(st.values[0].l); break;
    case PID_Y_POS:                   Y->setPosition(st.values[0].l); break;
    case PID_Z_POS:                   Z->setPosition(st.values[0].l); break;

    case PID_INC_DIRECTION_VALUE_X:   X->setIncrementDirectionValue(st.values[0].l);  break;
    case PID_INC_DIRECTION_VALUE_Y:   Y->setIncrementDirectionValue(st.values[0].l);  break;
    case PID_INC_DIRECTION_VALUE_Z:   Z->setIncrementDirectionValue(st.values[0].l);  break;
    
    case PID_POS_REPLY_THRESHOLD:     setPosReplyThreshold(st.values[0].l);           break;
    
    case PID_SPEED_MM_SEC:            setSpeedValue_MMSec1000(st.values[0].l);        break;

    case PID_ENABLE_STEPPERS:         enableStepperPin(st.values[0].asBool());        break;

    case PID_PROBE_MODE:              setProbeMode(st.values[0].asBool());            break;
    case PID_TOOL_SWITCH:             switchToolState(st.values[0].asBool());         break;
    
    case PID_ACCEL_PROFILE:           setupAccelProfile(st); 
                                      break;

    default:                          AML::pushMessage(MT_ERROR, E_INVALID_PARAM_ID, st.pid);
                                      return RET_ERROR;
  }
  
  return RET_OK;
}
/////////////////////////////////////////////////////////////////////////////////////
byte CncArduinoController::process(const ArduinoCmdDecoderMoveSequence::Result& seq) {
/////////////////////////////////////////////////////////////////////////////////////
  switch ( seq.cmd ) {
    case CMD_MOVE_SEQUENCE:  return renderMove(seq.dx, seq.dy, seq.dz);
    default:                 return renderMove(seq.dx, seq.dy, seq.dz);
  }
  
  return RET_OK;
}
/////////////////////////////////////////////////////////////////////////////////////
byte CncArduinoController::initialize(const ArduinoCmdDecoderMoveSequence::Result& seq) {
/////////////////////////////////////////////////////////////////////////////////////  
  ARDO_DEBUG_MESSAGE('S', "MoveSequence started")
  
  tsMoveStart = ArdoTs::now();
  tsMoveLast  = tsMoveStart;

  const int32_t ic = seq.impulseCount;// impulseCalculator.calculate(seq.lengthX, seq.lengthY, seq.lengthZ);
  if ( ic < 0 )
    return RET_ERROR;
   
  if ( cfgF1000_MMSEC && ArduinoAccelManager::initMove(ic, cfgF1000_MMSEC) == false )
    return RET_ERROR;
 
  return RET_OK;
}
/////////////////////////////////////////////////////////////////////////////////////
byte CncArduinoController::finalize(const ArduinoCmdDecoderMoveSequence::Result&) {
/////////////////////////////////////////////////////////////////////////////////////  
  sendCurrentPositions(PID_XYZ_POS_MAJOR, true);
  ARDO_DEBUG_MESSAGE('S', "MoveSequence finished")

  return RET_OK;
}
/////////////////////////////////////////////////////////////////////////////////////
byte CncArduinoController::process(const ArduinoCmdDecoderMove::Result& mv) {
/////////////////////////////////////////////////////////////////////////////////////
  // select underlying mechanism 
  switch ( mv.cmd ) {
    case CMD_MOVE_UNIT_LIMIT_IS_FREE: return moveUntilLimitIsFree (mv.dx, mv.dy, mv.dz);
    default:                          return movePosition         (mv.dx, mv.dy, mv.dz);
  }

  return RET_ERROR;
}
/////////////////////////////////////////////////////////////////////////////////////
byte CncArduinoController::moveUntilLimitIsFree(int32_t dx, int32_t dy, int32_t dz) {
/////////////////////////////////////////////////////////////////////////////////////
  bool retX = true;
  bool retY = true;
  bool retZ = true;
  
  if ( dx != 0 ) { retX = X->resolveLimit(); }
  if ( dy != 0 ) { retY = Y->resolveLimit(); }
  if ( dz != 0 ) { retZ = Z->resolveLimit(); }

  //PRINT_DEBUG_VALUE("retX", retX);
  //PRINT_DEBUG_VALUE("retY", retY);
  //PRINT_DEBUG_VALUE("retZ", retZ);
  
  return (retX == true && retY == true && retZ == true) ? RET_OK : RET_LIMIT;
}
/////////////////////////////////////////////////////////////////////////////////////
byte CncArduinoController::movePosition(int32_t dx, int32_t dy, int32_t dz) {
/////////////////////////////////////////////////////////////////////////////////////
  // avoid empty processing
  if ( dx == 0 && dy == 0 && dz == 0 ) 
    return RET_OK;

  const int32_t ic = impulseCalculator.calculate(dx, dy, dz);

  if ( ic < 0 )
    return RET_ERROR;

  tsMoveStart = ArdoTs::now();
  tsMoveLast  = tsMoveStart;
  
  if ( cfgF1000_MMSEC && initMove(ic, cfgF1000_MMSEC) == false )
    return RET_ERROR;

  return renderMove(dx, dy, dz);
}
