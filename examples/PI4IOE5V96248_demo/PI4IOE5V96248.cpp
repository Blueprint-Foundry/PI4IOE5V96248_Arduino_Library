/*
  PI4IOE5V96248.cpp
  PI4IOE5V96248 I2C IO expander Source File
  By: Ilia Baranov
  BLueprint Foundry
  Date: March 5th, 2021
  License: BSD 3 Clause
*/

#include <Wire.h>
#include "Arduino.h"
#include "PI4IOE5V96248.h"

PI4IOE5V96248::PI4IOE5V96248()
{
  value[0] = HIGH; //fill state array with HIGH on init, as this is state of chip on power on
  memcpy( ((char*)value) + sizeof(value[0]), value, sizeof(value) - sizeof(value[0]));
}

byte PI4IOE5V96248::begin(byte address)
{
  // Store the received parameter into member variables
  deviceAddress =  address;

  Wire.beginTransmission(address);
  if (!Wire.endTransmission()) { // default value to verify communication, a 0 means we got an ack
    return 1; //if successful
  }

  return 0;
}
