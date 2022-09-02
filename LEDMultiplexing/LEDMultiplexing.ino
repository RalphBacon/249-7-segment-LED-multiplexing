/*
  Demo sketch to show multiplexing on a dual 7-segment LED display. 
  
  However, this uses a single control line
  to turn off the two digits by using a simple Si4599 dual MOSFET. When this pin is HIGH then one LED is on,
  when it is LOW then the other is ON.

  Saves a GPIO line. Although we use an additional 7 GPIO lines to drive the segments of the LED digit,
  this would normally be the case; we would use additional hardware to take care of that, such as a
  74HC595 8-bit Shift Register. Thus the 7 (or 8, if we include the Decimal Point) GPIO lines are freed up.
*/
#include <Arduino.h>
#include "charDisplay.h"

// Comment out following line for Arduino-speak C++. Otherwise uses native C++ functions which are faster and
// do things (such as setting pin values) at the same time, not sequentially.
// #define SHORTHAND

// All outputs to controll both 7-seg LEDs on PORTD (just for DEMO). Change the pin number depending
// on the 7-seg LED you're using. These pins are for the KYX-2281AS-1 dual 0.28" LED Common Cathode
// and if this link still works, this is where I got them from: https://www.aliexpress.com/item/32583382777.html
#define aSeg 7
#define bSeg 6
#define cSeg 5
#define dSeg 4
#define eSeg 3
#define fSeg 2
#define gSeg 1
#define dp 0

// Turns each complete 7-seg LED on or off in sequence. Connect to BOTH CC pins.
#define multiplex 12

// Forward declaration (of a function we're going to use)
void counter();

void setup()
{
  // All outputs are on PORTC (a group of lines controllable together)
  // Either:
#ifdef SHORTHAND
  // Data Direction Register for port D (DDRD) 1 = output, 0 = input
  DDRD = B11111110; // All OUTPUT except pin 0 (used for uploading)
#else
  pinMode(aSeg, OUTPUT);
  pinMode(bSeg, OUTPUT);
  pinMode(cSeg, OUTPUT);
  pinMode(dSeg, OUTPUT);
  pinMode(eSeg, OUTPUT);
  pinMode(fSeg, OUTPUT);
  pinMode(gSeg, OUTPUT);
#endif

  // Our LED switching (HIGH/LOW) pin (not part of PORTB)
  pinMode(multiplex, OUTPUT);
}

// If the dual MOSFET is driven HIGH then one LED goes on. And vice versa.
void ledOn(int ledNo)
{
  digitalWrite(multiplex, ledNo == 1 ? LOW : HIGH);
  delay(10);

  // To see the digits alternating really slowly (digit 1, pause, digit 2)
  // uncomment the following lines (only happens once, after a reset):
  static uint8_t myDelay = 125;
  delay(myDelay > 1 ? --myDelay : 0);  
}

// Main demo sketch
void loop()
{
  // Do this a few times so we can see what's happening
  for (auto myLoop = 100; myLoop > 0; myLoop--)
  {
    // Display segments for 7-seg LED 1
    // Either
#ifdef SHORTHAND
    // Pins on PORTD are 0 through 7 (8 bits) but we won't use bit 0 (RX) as that interferes with uploading
    // GPIO  76543210
    PORTD = B10110110; // NB bit order is 76543210 (bit 0 always 0, as DP not used)
#else
    // or (slower):
    digitalWrite(aSeg, HIGH);
    digitalWrite(bSeg, HIGH);
    digitalWrite(cSeg, HIGH);
    digitalWrite(dSeg, LOW);
    digitalWrite(eSeg, HIGH);
    digitalWrite(fSeg, HIGH);
    digitalWrite(gSeg, HIGH);
#endif

    // All segments for LED 1 written. Turn on LED.
    ledOn(1);

    // Display segments for LED 2
    // Either
#ifdef SHORTHAND
    PORTD = B11110010; // NB bit order is 786543210/abcdefgx
#else
    // or (slower):
    digitalWrite(aSeg, LOW);
    digitalWrite(bSeg, HIGH);
    digitalWrite(cSeg, HIGH);
    digitalWrite(dSeg, LOW);
    digitalWrite(eSeg, LOW);
    digitalWrite(fSeg, HIGH);
    digitalWrite(gSeg, HIGH);
#endif

    // All segments for LED 2 written. Turn on LED (will turn off other LED)
    ledOn(2);
  }

  // Simple counter function, 0 - 99 (with not-so-simple slow-down)
  counter();
}

// Simple counter 0 -99 using PORTD for speed
void counter()
{
  for (auto outer = 0; outer < 10; outer++)
  {
    // Set the GPIO pins (and hence LED segments on first LED) to the integer value in 'outer'
    PORTD = _digits[outer];

    // Turn on the first LED to show the value eg [0][X]
    ledOn(1);

    // Now the second digits, exactly as above
    for (auto inner = 0; inner < 10; inner++)
    {
      // IT'S TOO FAST! We can't see the numbers changing on LED2!
      // The only way to slow the loop and be able to see BOTH digits
      // is to continually display BOTH digits (alternatively) without
      // incrementing the counter(s)
      int slowLoop = 25;
      while (slowLoop > 0)
      {

        // Show the second digit value
        PORTD = _digits[inner];
        ledOn(2);

        // Show the first digit value
        PORTD = _digits[outer];
        ledOn(1);

        // Decrement counter
        slowLoop--;
      }
    }
  }
}