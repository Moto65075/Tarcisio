#include "Leds.h"
#include "../Utils/TarDefs.h"

void setLedsState(bool led1, bool led2, bool led3) {
    digitalWrite(LED_PRINCIPAL, led1 ? HIGH : LOW);
    digitalWrite(LED_PRIMARY_STATUS, led2 ? HIGH : LOW); 
    digitalWrite(LED_NETWORK, led3 ? HIGH : LOW);
}

void blinkDualPin3X() {
  for (int i = 0; i < 3; i++) {
    setLeds(true, true, true); 
    delay(TEMPO_PISCADA_FEEDBACK);
    setLeds(false, false, false); 
    delay(TEMPO_PISCADA_FEEDBACK);
  }
}

void blinkSinglePin3X(int pin) {
  bool statusState = (pin == PINO_LED_STATUS) ? !digitalRead(PINO_LED_STATUS) : digitalRead(PINO_LED_STATUS);
  bool esperaState = (pin == PINO_LED_ESPERA) ? !digitalRead(PINO_LED_ESPERA) : digitalRead(PINO_LED_ESPERA);
  bool alertaState = (pin == PINO_LED_ALERTA) ? !digitalRead(PINO_LED_ALERTA) : digitalRead(PINO_LED_ALERTA);

  for (int i = 0; i < 3; i++) {
    digitalWrite(pin, HIGH);
    delay(TEMPO_PISCADA_FEEDBACK);
    digitalWrite(pin, LOW);
    delay(TEMPO_PISCADA_FEEDBACK);
  }
  
  setLeds(statusState, esperaState, alertaState);
}
