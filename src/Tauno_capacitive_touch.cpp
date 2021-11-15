/*
 * Tauno_capacitive_touch.cpp
 * Started: 14.11.2021
 * Edited: 15.11.2021
 * Copyright 2021 Tauno Erik
 * https://taunoerik.art/
 *
 */

#include <Arduino.h>
#include "Tauno_capacitive_touch.h"

Tauno_capacitive_touch::Tauno_capacitive_touch(
  uint8_t SEND_PIN,
  uint8_t RECEIVE_PIN)
  : new_SEND_PIN(SEND_PIN),
    new_RECEIVE_PIN(RECEIVE_PIN),
    trigger_level(0)
{}

Tauno_capacitive_touch::~Tauno_capacitive_touch() {
 // Cleanup
}

void Tauno_capacitive_touch::begin() {
  pinMode(new_SEND_PIN, OUTPUT);
  pinMode(new_RECEIVE_PIN, INPUT);

  digitalWrite(new_SEND_PIN, LOW);
  // Calibrate
  trigger_level = calibrate_treigger_level(30);
}

/*
  Returns raw time value.
  We set SEND_PIN high and will wait when RECEIVE_PIN reads high.
  And we'll return the difference.
*/
uint32_t Tauno_capacitive_touch::read_raw() {
  uint32_t start = GET_CURRENT_TIME; //time_us_32();
  uint32_t end = 0;

  digitalWrite(new_SEND_PIN, HIGH);

  while (digitalRead(new_RECEIVE_PIN) < HIGH)
  {
    // Wait till reads HIGH.
  }

  end = GET_CURRENT_TIME; //time_us_32();
  digitalWrite(new_SEND_PIN, LOW);
  
  return (end-start);
}


/*
  Returns: raw value minus trigger level.
  If we don't touch then the value is nicely zero.
*/
uint32_t Tauno_capacitive_touch::read() {

  uint32_t value = read_raw();
  if (value > trigger_level){
    return (value - trigger_level);
  } else {
    return 0;
  }
}

/*
  Returns true or false.
*/
bool Tauno_capacitive_touch::read_bool() {
  if (read() > 0) {
    return true;
  } else {
    return false;
  }
}


/*
  Returns calibrated trigger level.
  Reads ~50 values and finds the highest value.
  The trigger level is slightly higher (*1.3) than the noise.
*/
uint32_t Tauno_capacitive_touch::calibrate_treigger_level(uint8_t samples) {
  if (samples < 1) {
    return 0;
  }

  uint32_t value = 0;

  for (uint8_t i = 0; i < samples; i++){
    uint32_t new_value =  read_raw();
    if (new_value > value){
      value = new_value;
    }
    delay(1);
  }
  
  return (value*1.3); 
}
