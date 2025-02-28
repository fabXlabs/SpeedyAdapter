#include <Arduino.h>
#include <WiFi.h>

bool state = 0;

void setup() {
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(4, INPUT_PULLDOWN);
  state = 0;
  digitalWrite(1, 0);
  digitalWrite(0, 0);
  WiFi.mode(WIFI_OFF);
}

void loop() {
  if (!state) { // off
    if (digitalRead(4) == HIGH) {
      digitalWrite(0, 1);
      delay(2000);
      digitalWrite(1, 1);
      delay(500);
      digitalWrite(1, 0);
      state = 1;
    }
  } else {
    if (digitalRead(4) == LOW) {
      ESP.restart();
    }
  }
}
