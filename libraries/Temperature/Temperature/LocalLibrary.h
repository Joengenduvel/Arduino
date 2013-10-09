//
// File			LocalLibrary.h
// Brief		Library header
//
// Project	 	Temperature
// Developed with [embedXcode](http://embedXcode.weebly.com)
// 
// Author		Robby Decosemaeker
// 				Robby Decosemaeker
// Date			9/10/13 19:35
// Version		<#version#>
// 
// Copyright	© Robby Decosemaeker, 2013
// License		<#license#>
//
// See			ReadMe.txt for references
//


// Core library - IDE-based
#if defined(MPIDE) // chipKIT specific
#include "WProgram.h"
#elif defined(DIGISPARK) // Digispark specific
#include "Arduino.h"
#elif defined(ENERGIA) // LaunchPad MSP430, Stellaris and Tiva, Experimeter Board FR5739 specific
#include "Energia.h"
#elif defined(MAPLE_IDE) // Maple specific
#include "WProgram.h"
#elif defined(CORE_TEENSY) // Teensy specific
#include "WProgram.h"
#elif defined(WIRING) // Wiring specific
#include "Wiring.h"
#elif defined(ARDUINO) && (ARDUINO >= 100) // Arduino 1.0x and 1.5x specific
#include "Arduino.h"
#elif defined(ARDUINO) && (ARDUINO < 100)  // Arduino 23 specific
#include "WProgram.h"
#endif // end IDE

#ifndef Temperature_LocalLibrary_h
#define Temperature_LocalLibrary_h

class Blinker{
public:
    Blinker();
    Blinker(uint8_t pin);
    Blinker(uint8_t pin, uint8_t times);
//
// Brief	Blink a LED
// Details	LED attached to pin is light on then light off
// Total cycle duration = ms
// Parameters:
//      pin pin to which the LED is attached
//      times number of times
//      ms cycle duration in ms
//
void blink(uint16_t ms);
    private:
    
    uint8_t _pin;
    uint8_t _times;
    
    void init(uint8_t pin, uint8_t times);
};
#endif
