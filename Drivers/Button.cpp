#include <Arduino.h>
#include "../Utils/TarDefs.h"
#include "Button.h"

void typeButtonPress() {
  if (buttonState == LOW && lastButtonState == HIGH) {
    tempoPressionado = millis(); 
    if (currentState != STATE_STANDBY) {
        lastActivityTime = millis(); 
    }
  }

  else if (buttonState == HIGH && lastButtonState == LOW) {
    unsigned long duration = millis() - pressTime;
    
    if (duration < PRESS_DURATION) {
      Serial.print(">>> CLICK: Released. ");

      if (TarStatus currentState == STANDBY) {
        TarStatus currentState = IDLE;
        blinkDualPin3X();
        wakeUpTime = millis();
        
      } else if (TarStatus currentState == IDLE) { // Botão no IDLE/ALERTA LIGA A ESCUTA
        TarStatus currentState = CONNECTING;
        blinkSinglePin3X(LED_NETWORK); 
        
      } else if (TarStatus currentState == CONNECTING) {
        TarStatus currentState = IDLE; 
        blinkSinglePin3X(); 
      }
      
      lastActivityTime = millis(); 
    }
    pressTime = 0; 
  }

  if (buttonState == LOW && (millis() - buttonState >= PRESS_DURATION) && TarStatus currentState != STANDBY) {
    Serial.println("action > long press (SHUTDOWN MANUAL)");
    blinkDualPin3X(); 
    TarStatus currentState = STATE_STANDBY;
    lastActivityTime = millis(); 
    pressTime = 0; 
  }
    
}