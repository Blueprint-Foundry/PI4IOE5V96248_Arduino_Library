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
    byte value[6]; // tracking pin values for chip, expressed as hex values per port (6 ports total)
    byte read_io[6];

  public:  // These public functions are available to Arduino sketches.
    PI4IOE5V96248();
    byte begin(byte address = 0x23); // Example PI4IOE5V96248 I2C address, depends on setting for AD0, AD1, AD2
    void writePin(byte port, byte pin, byte highLow);
    void writePort(byte port, byte portValue);
    void writeAll(byte highLow[6]);
    byte readPin(byte port, byte pin);
    byte readPort(byte port);
    byte * readAll();
    byte * returnValue();

}; //PI4IOE5V96248 class
#endif  // PI4IOE5V96248_H
