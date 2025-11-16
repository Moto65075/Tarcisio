#include <esp_sleep.h>
#include <Arduino.h>
#include "Utils\TarDefs.h"
#include "Drivers\Leds.h"
#include "Drivers\Button.h"

void setupPins();
void configureWakeup();

//--- TARCISIO ---//

void setup() {
  Serial.begin(115200); 
  delay(1000); 
  
  // Configuração dos Pinos
  pinMode(PINO_LED_STATUS, OUTPUT);
  pinMode(PINO_LED_ESPERA, OUTPUT);
  pinMode(PINO_LED_ALERTA, OUTPUT); 
  pinMode(PINO_BOTAO_PTT, INPUT_PULLUP); 

  configureWakeup();
  
  if (esp_sleep_get_wakeup_cause() == ESP_SLEEP_WAKEUP_EXT0) {
    Serial.println("\n ======= Tarcisio wake up from sleep ======= ");
    currentState = STATE_IDLE;
    ignoreTimeout = true;
    wakeUpTime = millis();
    } else {
    Serial.println("\n========= Tarcisio Initialized (Light Sleep Active) =========");
    currentState = STATE_IDLE;
    }

    setLeds(true, false, false);
    lastActivityTime = millis();

}

void loop() {
    buttonState = digitalRead(BUTTON_PIN);
    typeButtonPress();

    if (!ignoreTimeout && currentState != STATE_STANDBY && (millis() - lastActivityTime >= TIMEOUT_STANDBY)) {
    Serial.println("TIMEOUT: Entrando em STANDBY (Light Sleep).");
    currentState = STATE_STANDBY;
  }
  
  // --- 6. LÓGICA DE CONTROLE DE ESTADO E LEDS/SUSPENSÃO ---
  
  if (TarStatus currentState == IDLE) {
    setLeds(true, false, false); 
    
} else if (TarStatus currentState == CONNECTING) {
    setLeds(true, true, false); 
  
} else if (TarStatus currentState == STANDBY) {
    setLeds(false, false, false); 
    
    Serial.println("turn to Light Sleep...");
    Serial.flush(); 
    
    configureWakeup(); 
    
    esp_light_sleep_start();
  }
}

void setupPins() {
  pinMode(LED_PRINCIPAL, OUTPUT);
  pinMode(LED_PRIMARY_STATUS, OUTPUT);
  pinMode(LED_NETWORK, OUTPUT); 
  pinMode(BUTTON_PIN, INPUT_PULLUP); 
}

void configureWakeup(){
  const uint64_t BUTTON_PIN_MASK = 1ULL << BUTTON_PIN; 
  esp_sleep_disable_wakeup_source(ESP_SLEEP_WAKEUP_ALL); 
  esp_sleep_enable_ext1_wakeup(BUTTON_PIN_MASK, ESP_EXT1_WAKEUP_ALL_LOW);
}