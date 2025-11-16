#ifndef LEDS_H
#define LEDS_H
#include <Arduino.h>

void setLedsState(bool led1, bool led2, bool led3);
void blinkDualPin3X();
void blinkSinglePin3X(int pin)

#endif