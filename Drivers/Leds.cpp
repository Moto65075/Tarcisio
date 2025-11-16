#include "Leds.h"

void setLedsState(bool led1, bool led2, bool led3) {
    digitalWrite(LED_PRINCIPAL, led1 ? HIGH : LOW);
    digitalWrite(LED_PRIMARY_STATUS, led2 ? HIGH : LOW); 
    digitalWrite(LED_NETWORK, led3 ? HIGH : LOW);
}

void led3Blink() {
    setLedsState(false, false, true); 
    delay(500);
    setLedsState(false, false, false);
    delay(500);
}

void allLedsblink() {
    setLedsState(true, true, true);
    delay(500);
    setLedsState(true, true, true);
    delay(500);
}