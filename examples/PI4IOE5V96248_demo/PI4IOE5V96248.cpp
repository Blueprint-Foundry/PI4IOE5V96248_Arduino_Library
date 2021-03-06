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
  value[0] = 0xFF; //fill state array with HIGH on init, as this is state of chip on power on
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

void PI4IOE5V96248::writePin(byte port, byte pin, byte highLow)
{
  //only write if needed. Set sign value in array and send the array
  if (highLow == HIGH) value[port] |= 1UL << pin ; //set pin (set to 1 or HIGH)
  else value[port] &= ~(1UL << pin) ; //clear pin (set to 0 or LOW)
  writeAll(value);
}

void PI4IOE5V96248::writePort(byte port, byte portValue)
{
  //only write if needed. Set hex value in array and send the array
  value[port] = portValue;
  writeAll(value);
}

void PI4IOE5V96248::writeAll(byte highLow[6])
{
  Wire.beginTransmission(deviceAddress);
  for (int i = 0; i < 6; i++) {
    Wire.write(highLow[i]);
  }
  Wire.endTransmission();
}

byte PI4IOE5V96248::readPin(byte port, byte pin) {
  //store pin mode, set to read (if needed), read pin, reset to stored mode (if needed)
}

byte * PI4IOE5V96248::readAll() {
}
