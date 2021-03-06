/*
  PI4IOE5V96248.h
  PI4IOE5V96248 I2C IO expander Header File
  By: Ilia Baranov
  BLueprint Foundry
  Date: March 5th, 2021
  License: BSD 3 Clause
*/


#include "Arduino.h"

#ifndef PI4IOE5V96248_H
#define PI4IOE5V96248_H

class PI4IOE5V96248
{
  private:  // These private functions are not available to Arduino sketches.
    byte deviceAddress; // I2C Address of PI4IOE5V96248
    byte value[48]; // tracking pin values for chip

  public:  // These public functions are available to Arduino sketches.
    PI4IOE5V96248();
    byte begin(byte address = 0x23); // Example PI4IOE5V96248 I2C address, depends on setting for AD0, AD1, AD2
    void writePin(byte pin, byte highLow);
    void writeAll(byte highLow[48]);
    byte readPin(byte pin);
    byte * readAll();

}; //PI4IOE5V96248 class
#endif  // PI4IOE5V96248_H
