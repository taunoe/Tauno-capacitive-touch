/*
 * Example of reading a capacitive touch button.
 * Uses a high value resistor e.g. 50K - 50M between send pin and receive pin.
 * Started: 14.11.2021
 * Edited: 15.11.2021
 * Copyright 2021 Tauno Erik
 * https://taunoerik.art/
 *
 */

#include <Tauno_capacitive_touch.h>

const uint32_t BAUD_RATE = 115200;

const int SEND_PIN = 0;    // Rasperry Pi Pico GP0
const int RECEIVE_PIN = 1; // Rasperry Pi Pico GP1

//On Arduino Uno
//const int SEND_PIN = 4;
//const int RECEIVE_PIN = 2;

Tauno_capacitive_touch Sensor(SEND_PIN, RECEIVE_PIN);

void setup() {
  Serial.begin(BAUD_RATE);
  Serial.println("Capacitive touch button demo!");
  Sensor.begin();
}

void loop() {

  // Read raw value
  uint32_t value1 = Sensor.read_raw();
  Serial.print(" Sensor.read_raw():");
  Serial.print(value1);

  // Read calibrated value 0=no touch or higher=touch
  uint32_t value2 = Sensor.read();
  Serial.print(" Sensor.read():");
  Serial.print(value2);

  // Read boolean: 0=false=no touch or 1=true=touch
  bool value3 = Sensor.read_bool();
  Serial.print(" Sensor.read_bool():");
  Serial.println(value3);

  delay(50);
}