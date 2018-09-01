
#define SKETCH_COMPILE = TRUE

#include "LimitSwitchDefinitions.h"
#include "SupportPinDefinitions.h"

// ------------------------------------------------------------
// Outout Pins - only analog output pins are valid here
const SHORT PIN_LS_ANALOG_OUT       =  8;
const SHORT PIN_SP_ANALOG_OUT       =  9;
  
// ------------------------------------------------------------
// globals
LimitSwitch::LimitStates    limitStates;
SupportPin::SupportStates   supportStates;

//-------------------------------------------------------------
inline void encodeSupportState() {
  supportStates.reset();
  supportStates.evaluate();
}
//-------------------------------------------------------------
inline void encodeLimitState() {
  limitStates.reset();
  limitStates.evaluate();
}
//-------------------------------------------------------------
inline void writeSupportState() {
  analogWrite(PIN_SP_ANALOG_OUT, supportStates.getValue());
}
//-------------------------------------------------------------
inline void writeLimitState() {
  analogWrite(PIN_LS_ANALOG_OUT, limitStates.getValue());
}
//-------------------------------------------------------------
void setup() {
  Serial.begin(57600);
  Serial.setTimeout(1000);
  Serial.flush();

  supportStates.init();
  supportStates.reset();
  writeSupportState();

  limitStates.init();
  limitStates.reset();
  writeLimitState();
}
//-------------------------------------------------------------
void loop() {
  // For debugging only
  if ( Serial.available() > 0 ) {
    byte c = Serial.read();

    if ( c != '\0' ) {
      limitStates.report();
      supportStates.report();
    }
  }

  // Normal processing
  encodeLimitState();
  writeLimitState();

  encodeSupportState();
  writeSupportState();
}

