/*
 * Example of reading a multiple capacitive touch buttons.
 * Uses a high value resistor e.g. 50K - 50M between send pin and receive pin.
 * Started: 15.11.2021
 * Edited: 15.11.2021
 * Copyright 2021 Tauno Erik
 * https://taunoerik.art/
 *
 */

#include <Tauno_capacitive_touch.h>

const uint32_t BAUD_RATE = 115200;

// First button
const int SEND_PIN_1 = 0;    // Rasperry Pi Pico GP0
const int RECEIVE_PIN_1 = 1; // Rasperry Pi Pico GP1
Tauno_capacitive_touch Sensor_1(SEND_PIN_1, RECEIVE_PIN_1);

// Second button
const int SEND_PIN_2 = 2;    // Rasperry Pi Pico GP0
const int RECEIVE_PIN_2 = 3; // Rasperry Pi Pico GP1
Tauno_capacitive_touch Sensor_2(SEND_PIN_2, RECEIVE_PIN_2);

void setup() {
  Serial.begin(BAUD_RATE);
  Serial.println("Capacitive touch button demo!");

  // Acivate buttons
  Sensor_1.begin();
  Sensor_2.begin();
}

void loop() {

  // Read sensor 1 value
  uint32_t value1 = Sensor_1.read();
  Serial.print("Sensor_1:");
  Serial.print(value1);
  Serial.print("\t");

  // Read sensor 2 value
  uint32_t value2 = Sensor_2.read();
  Serial.print("Sensor_2:");
  Serial.println(value2);

  delay(50);
}