#include "Arduino.h"

// Binary bit pattern for PORTB for the digits 0 - F (ie including hex chars A through F)
/*
    Worked example:

    Figure 4 uses LED segments b,c,f,g all others are not lit.
    
         ---a---
      f |       | b
        |__ g __|
        |       |
      e |       | c
         ---d--- 

    So if the bit pattern on the PORTB pins represents 1 through g (x=decimal point)
    we need bits set as follows:

    abcdefgx
    01100110

    Connect the pins 1 - 7 from the Arduino to the respective pins for your LED (all are different).
    Connect the Common Cathode pin(s) to ground via a 220Ω resistor.

    In the table below you will see that "4" is indeed the above bit pattern.
*/
const uint8_t _digits[16] = {
        B11111100, // 0
        B01100000, // 1
        B11011010, // 2
        B11110010, // 3
        B01100110, // 4
        B10110110, // 5
        B10111110, // 6
        B11100000, // 7
        B11111110, // 8
        B11110110, // 9
        B11101110, // A
        B00111110, // b
        B10011100, // C
        B01111010, // d
        B10011110, // E
        B10001110, // F
    };