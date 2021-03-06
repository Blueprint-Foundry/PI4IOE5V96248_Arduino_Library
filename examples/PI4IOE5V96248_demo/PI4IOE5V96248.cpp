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

//init function, fills port value array with 0xFF
PI4IOE5V96248::PI4IOE5V96248()
{
  value[0] = 0xFF; //fill state array with HIGH on init, as this is state of chip on power on
  memcpy( ((char*)value) + sizeof(value[0]), value, sizeof(value) - sizeof(value[0]));
}

//communication check, simply checks if chip responds with Ack
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

//sets a single pin on the chip, requires port and pin number, and value to set
void PI4IOE5V96248::writePin(byte port, byte pin, byte highLow)
{
  //Set sign value in array and send the port hex value
  if (highLow == HIGH) value[port] |= 1UL << pin ; //set pin (set to 1 or HIGH)
  else value[port] &= ~(1UL << pin) ; //clear pin (set to 0 or LOW)
  writePort(port, value[port]);
}

//Sets an entire port at once, usually the fastest way to set values for this chip
//Note: Port outputs are changed as soon as write is done for each port.
void PI4IOE5V96248::writePort(byte port, byte portValue)
{
  //only write if needed. Set hex value in array and send the array
  if (value[port] != portValue) {
    value[port] = portValue;
    Wire.beginTransmission(deviceAddress);
    for (int i = 0; i <= port; i++) { //only write up to port number, no benefit writing more
      Wire.write(value[i]);
    }
    Wire.endTransmission();
  }
}

//sets all pins/ports on the chip
void PI4IOE5V96248::writeAll(byte highLow[6])
{
  Wire.beginTransmission(deviceAddress);
  for (int i = 0; i < 6; i++) {
    Wire.write(highLow[i]);
  }
  Wire.endTransmission();
}

//Sets a specific pin high, reads value, resets pin to original state,
// and returns read value
byte PI4IOE5V96248::readPin(byte port, byte pin) {
  //store pin mode, set to read (if needed), read pin, reset to stored mode (if needed)
}

//Sets all pins to high, and then reads all values, reset pins to original state,
// and returns read values
byte * PI4IOE5V96248::readAll() {
}

//returns private value variable, which tracks what the chip is set to.
//Does not actually read from the chip
byte * PI4IOE5V96248::returnValue() {
  return value;
}
