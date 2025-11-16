#ifndef TARDEFS_H
#define TARDEFS_H

#include <Arduino.h>

// PIN DEFINITIONS

const int LED_PRINCIPAL = 13;
const int LED_PRIMARY_STATUS = 14;
const int LED_NETWORK = 4;
const int BUTTON_PIN = 0;

// TAR STATUS DEFINITIONS

enum TarStatus {
    STAND_BY,
    LISTENING,
    PLAYING,
    BLUETOOTH_PAIRING,
    CONNECTING,
    CONNECTED,
    ERROR_STATE
    IDLE
}

enum Button {
    SHORT_PRESS,
    LONG_PRESS,
    DOUBLE_PRESS,
    THREE_PRESS,
    RELEASE
}

// TIME DEFINITIONS

unsigned long pressTime = 0;
unsigned long lastActivityTime = 0; 
unsigned long wakeUpTime = 0; 
const long BLINK_INTERVAL = 500;
const long PRESS_DURATION = 500;
const long STANDBY_TIMEOUT = 50000;
const long TRY_CONNECT_INTERVAL = 10000;
const long BT_PAIRING_DURATION = 30000;
const long WAKEUP_TIME = 0;
const long ESP_SLEEP_WAKEUP_EXT = 0;
const long GUARD_TIME = 3000;

// STATE VARIABLES

int buttonState = HIGH;
int lastButtonState = HIGH;
int typeButtonPress = "";

#endif