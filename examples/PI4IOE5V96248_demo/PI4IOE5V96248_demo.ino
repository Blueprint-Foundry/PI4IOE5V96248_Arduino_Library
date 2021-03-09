/*
  Basic demo for PI4IOE5V96248 I2C IO expander
  By: Ilia Baranov
  BLueprint Foundry
  Date: March 5th, 2021
  License: BSD 3 Clause
  This example demonstrates how to set and read single pins and sets of pins on the PI4IOE5V96248
  Note that this chip requires all pins to be set every time you write something, so the write pin
  function is only useful for comprehensability. Effeciency wise it's faster to set all pins.

*/
#include <Wire.h>
#include <PI4IOE5V96248.h>

PI4IOE5V96248 io_exp; // Object for communicating with the io expander
const byte PI4IOE5V96248_ADDRESS = 0x23;  // Example PI4IOE5V96248 I2C address, depends on setting for AD0, AD1, AD2

void setup() {
  Serial.begin(115200);
  Wire.begin(25, 23); //Join I2C bus, set SDA and SCL pins respectively (tested on ESP32, remove pins if using another chip)
  Wire.setClock(400000); //Set speed to 400Khz, chip supports up to 1Mhz

  delay(100); //give system chance to stabilize, likely not needed.

  // Call io_exp.begin(<address>) to initialize the PI4IOE5V96248. Successfully communication = return 1.
  // NOTE: Requires Wire.begin to already have been called.
  if (!io_exp.begin(PI4IOE5V96248_ADDRESS))
  {
    Serial.println("Failed to init PI4IOE5V96248 :(");
    while (1); //loop forever
  }
  Serial.println("PI4IOE5V96248 found! :)");
}

//Convinience function to print values
void printout() {
  byte * stored = io_exp.returnValue();
  for (int i = 0; i < 6; i++) { //example printing initialized 0xFF(all on) values
    Serial.print("  [");
    Serial.print(i);
    Serial.print("]: ");
    Serial.print(stored[i], HEX);
  }
  Serial.println();
}

byte test[6] = {0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF};
void loop() {
  printout();
  delay(3000);
  io_exp.writePin(0, 7, LOW); // set a single pin on port 0 (pin 5 numerically on the chip)
  printout();
  delay(3000);
  io_exp.writePort(1, 0x00); //set an entire port to a hex byte value
  printout();
  delay(3000);
  io_exp.writeAll(test); //set the entire chip to an array of hex byte values
  printout();
  delay(3000);
  Serial.println (io_exp.readPort(0), HEX); //read from port 0, will return whatever the pins were set to
  delay(3000);
  Serial.println (io_exp.readPin(0, 1), HEX); //read from port 0, pin 1, will return whatever the pins were set to
}
