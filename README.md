# PI4IOE5V96248_Arduino_Library
Arduino Library for PI4IOE5V96248
This chip is an I2C IO expander chip, with 48 I/O pins configurable over I2C.
The library is really basic, mostly using the Wire library. It is made just to provide some convinience functions for users.

### Note: This chip defaults to all pins HIGH on power on. This is expected since it's mostly designed as a LED driver chip, but good to note.
The other quirk is that pins must be set to HIGH to read the value from them. This makes input from this chip not great.

Software is licensed under BSD 3 Clause: https://opensource.org/licenses/BSD-3-Clause   
Documentation is licensed under Attribution-ShareAlike 2.0 Generic (CC BY-SA 2.0): https://creativecommons.org/licenses/by-sa/2.0/   
All rights reserved by Blueprint Foundry.
