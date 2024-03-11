/*********************************************************
  This is a library for the MPR121 12-channel Capacitive touch sensor

  Designed specifically to work with the MPR121 Breakout in the Adafruit shop
  ----> https://www.adafruit.com/products/

  These sensors use I2C communicate, at least 2 pins are required
  to interface

  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
**********************************************************/

//Edited by Nicholas Petersen 2024
//Upload the script to your LIQ HD system and open the serial plotter on the Arduino IDE 
//to visually test lick threshold settings! It is recomended to test only 2-4 sensors because
//the serial plotter begins to run slowly. If the serial plotter is running to quickly to visualize 
//detected licks, you can slow it down by adding a delay (change "delay_time"). 
//Run this test on a fully built LIQ system in its experimental environment because certain
//changes, such as wire length, will affect the necessary threshold settings. 


#include <Wire.h>
#include "Adafruit_MPR121.h"

#ifndef _BV
#define _BV(bit) (1 << (bit))
#endif

// You can have up to 4 on one i2c bus but one is enough for testing!
Adafruit_MPR121 cap = Adafruit_MPR121();

// Keeps track of the last pins touched
// so we know when buttons are 'released'
uint16_t lasttouched = 0;
uint16_t currtouched = 0;

//Parameters to define
#define MPR121_address 0x5A     //Change this to the I2C address of your sensor board you are testing
#define sensor_number 2         //define how many sensors on the board you want to test, starting in order from sensor #0 to #11 ("2" = sensors #0 and #1)
int touch_threshold = 2;        //board default = 12, LIQ HD default = 2
int release_threshold = 0;      //board default = 6, LIQ HD default = 0
int debounce = 0;               //range 0-7, LIQ HD default = 0
int current = 16;               //Range of 1-63uA, Board default and LIQ HD default = 16
int delay_time = 0;             //increase to slow down serial plotter

bool touch[sensor_number]; //do not change

//=================================================================================================================================

void setup() {
  Serial.begin(115200);

  if (!cap.begin(MPR121_address)) { 
    while (1);
  }

  cap.setThresholds(touch_threshold, release_threshold);  //set sensitivity of touch and release of capacitive sensors
  //cap.writeRegister(MPR121_CONFIG1, current);             // default, 16uA charge current

  cap.writeRegister(MPR121_DEBOUNCE, debounce);
  cap.writeRegister(MPR121_MHDR, 1);
  cap.writeRegister(MPR121_NHDR, 10);
  cap.writeRegister(MPR121_NCLR, 1);
  cap.writeRegister(MPR121_FDLR, 2);

  cap.writeRegister(MPR121_MHDF, 1);
  cap.writeRegister(MPR121_NHDF, 5);
  cap.writeRegister(MPR121_NCLF, 3);
  cap.writeRegister(MPR121_FDLF, 1);

  cap.writeRegister(MPR121_NHDT, 1);
  cap.writeRegister(MPR121_NCLT, 5);
  cap.writeRegister(MPR121_FDLT, 1);
}

void loop() {
  // Get the currently touched pads
  currtouched = cap.touched();

  for (uint8_t i = 0; i < sensor_number; i++) {
    // it if *is* touched and *wasnt* touched before, alert!
    if ((currtouched & _BV(i)) && !(lasttouched & _BV(i))) {
      touch[i] = true;
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched & _BV(i)) && (lasttouched & _BV(i))) {
      touch[i] = false;
    }
  }

  // reset our state
  lasttouched = currtouched;

  for (uint8_t i = 0; i < sensor_number; i++) {  //change "i < #" to number of sensors you want to visualize
    int t = cap.baselineData(i) - cap.filteredData(i);
    float w;
    float x = float(i);
    if (touch[i]) {
      w = touch_threshold + (x / 2);
    } else {
      w = 0 + (x / 2);
    }
    Serial.print(t);
    Serial.print("\t");
    Serial.print(w);
    Serial.print("\t");
  }
  Serial.println();
  delay(delay_time);
  return;
}
