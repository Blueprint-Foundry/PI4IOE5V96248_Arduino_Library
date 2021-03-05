/*
  Basic demo for PI4IOE5V96248 I2C IO expander
  By: Ilia Baranov
  BLueprint Foundry
  Date: March 5th, 2021
  License: BSD 3 Clause
  This example demonstrates how to set and read single pins and sets of pins on the PI4IOE5V96248

*/
#include <Wire.h>
#include <PI4IOE5V96248.h>

PI4IOE5V96248 io_exp; // Object for communicating with the io expander
const byte PI4IOE5V96248_ADDRESS = 0x3E;  // PI4IOE5V96248 I2C address

void setup() {
  Serial.begin(115200);
  Wire.begin(); //Join I2C bus

  delay(500);
}

void loop() {
}
