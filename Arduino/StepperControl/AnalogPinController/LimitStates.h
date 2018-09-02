#ifndef LIMIT_SWITCH_DEFINITIONS_H
#define LIMIT_SWITCH_DEFINITIONS_H

#include "CommonDefinitions.h"
#include "CncInterface.h"
#include "StateBuffer.h"

namespace LimitSwitch {

  const SHORT PIN_LS_X_MIN            =  2;
  const SHORT PIN_LS_X_MAX            =  3;
  const SHORT PIN_LS_Y_MIN            =  4;
  const SHORT PIN_LS_Y_MAX            =  5;
  const SHORT PIN_LS_Z_MIN            =  6;
  const SHORT PIN_LS_Z_MAX            =  7;

  //-----------------------------------------------------------------
  class LimitStates : public StateBuffer {

    public:
      LimitStates() 
      : StateBuffer()
      {}

      explicit LimitStates(const unsigned int value) 
      : StateBuffer(value)
      {}
      
      //-------------------------------------------------------------
      virtual void init() {
        initInputPin(PIN_LS_X_MIN, LIMIT_SWITCH_OFF);
        initInputPin(PIN_LS_X_MAX, LIMIT_SWITCH_OFF);
        initInputPin(PIN_LS_Y_MIN, LIMIT_SWITCH_OFF);
        initInputPin(PIN_LS_Y_MAX, LIMIT_SWITCH_OFF);
        initInputPin(PIN_LS_Z_MIN, LIMIT_SWITCH_OFF);
        initInputPin(PIN_LS_Z_MAX, LIMIT_SWITCH_OFF);
      }

      //-------------------------------------------------------------
      virtual void evaluate() {
        setBit(BIT_LS_X_MIN, readPin(PIN_LS_X_MIN) == LIMIT_SWITCH_ON);
        setBit(BIT_LS_X_MAX, readPin(PIN_LS_X_MAX) == LIMIT_SWITCH_ON);
      
        setBit(BIT_LS_Y_MIN, readPin(PIN_LS_Y_MIN) == LIMIT_SWITCH_ON);
        setBit(BIT_LS_Y_MAX, readPin(PIN_LS_Y_MIN) == LIMIT_SWITCH_ON);
        
        setBit(BIT_LS_Z_MIN, readPin(PIN_LS_Z_MIN) == LIMIT_SWITCH_ON);
        setBit(BIT_LS_Y_MAX, readPin(PIN_LS_Z_MAX) == LIMIT_SWITCH_ON);

        setBit(BIT_2,        false);
        setBit(BIT_1,        false);
      }
      
      //-------------------------------------------------------------
      virtual void report() {
        headline();
        Serial.print(CR);
        Serial.print("LS Report:");
        Serial.print(CR);
      
        Serial.print("LS Value: ");
        Serial.print(getValue());
        Serial.print(BLANK3);
        Serial.print("'");
        Serial.print(getValueAsString());
        Serial.print("'");
        Serial.print(CR);
      
        Serial.print("PIN Values: ");
        Serial.print(CR);
        Serial.print(PIN_LS_X_MIN); Serial.print(EQUAL); Serial.print(readPin(PIN_LS_X_MIN)); Serial.print(CR);
        Serial.print(PIN_LS_X_MAX); Serial.print(EQUAL); Serial.print(readPin(PIN_LS_X_MAX)); Serial.print(CR);
        Serial.print(PIN_LS_Y_MIN); Serial.print(EQUAL); Serial.print(readPin(PIN_LS_Y_MIN)); Serial.print(CR);
        Serial.print(PIN_LS_Y_MAX); Serial.print(EQUAL); Serial.print(readPin(PIN_LS_Y_MAX)); Serial.print(CR);
        Serial.print(PIN_LS_Z_MIN); Serial.print(EQUAL); Serial.print(readPin(PIN_LS_Z_MIN)); Serial.print(CR);
        Serial.print(PIN_LS_Z_MAX); Serial.print(EQUAL); Serial.print(readPin(PIN_LS_Z_MAX)); Serial.print(CR);
      }
  };
} // namespace
  
#endif