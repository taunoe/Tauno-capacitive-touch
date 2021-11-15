/*
 * Tauno_capacitive_touch.h
 * Started: 14.11.2021
 * Edited: 15.11.2021
 * Copyright 2021 Tauno Erik
 * https://taunoerik.art/
 *
 */

#if !defined(LIB_TAUNO_CAPACITIVE_TOUCH_H)
#define LIB_TAUNO_CAPACITIVE_TOUCH_H

#include <Arduino.h>

#if defined(ARDUINO_ARCH_MBED_RP2040) || defined(ARDUINO_ARCH_RP2040)
  #define GET_CURRENT_TIME time_us_32()
//#elif defined(__AVR__)
#else
  #define GET_CURRENT_TIME micros()
#endif

class Tauno_capacitive_touch {
  private:
    uint8_t new_SEND_PIN;
    uint8_t new_RECEIVE_PIN;
    uint16_t trigger_level;

  public:
    Tauno_capacitive_touch( uint8_t SEND_PIN, uint8_t RECEIVE_PIN);

    ~Tauno_capacitive_touch();

    void begin();  // Initializes pins.

    uint32_t read_raw(); // Returns raw time value.
    uint32_t read();     // Returns  = (raw value - trigger level).
    bool read_bool(); // Returns True or False.

    uint32_t calibrate_treigger_level(uint8_t samples); // Calgulates trigger level

};


#endif // LIB_TAUNO_CAPACITIVE_TOUCH_H
