/*
  Basic demo for PI4IOE5V96248 I2C IO expander
  By: Ilia Baranov
  BLueprint Foundry
  Date: March 5th, 2021
  License: BSD 3 Clause
  This example demonstrates how to set and read single pins and sets of pins on the PI4IOE5V96248

*/
#include <Wire.h>
#include "PI4IOE5V96248.h"

PI4IOE5V96248 io_exp; // Object for communicating with the io expander
const byte PI4IOE5V96248_ADDRESS = 0x23;  // Example PI4IOE5V96248 I2C address, depends on setting for AD0, AD1, AD2

void setup() {
  Serial.begin(115200);
  Wire.begin(25,23); //Join I2C bus, set SDA and SCL pins respectively (tested on ESP32, remove pins if using another chip)
  Wire.setClock(400000); //Set speed to 400Khz, chip supports up to 1Mhz

  delay(100); //give system chance to stabilize, likely not needed.

  // Call io_exp.begin(<address>) to initialize the PI4IOE5V96248. Successfully communication = return 1.
  // NOTE: Requires Wire.begin to already have been called.
  if (!io_exp.begin(PI4IOE5V96248_ADDRESS))
  {
     Serial.println("Failed to init PI4IOE5V96248 :(");
     while(1); //loop forever
  }
  Serial.println("PI4IOE5V96248 found! :)");
}

void loop() {
}
