//
// LocalLibrary.cpp 
// Library C++ code
// ----------------------------------
// Developed with embedXcode 
// http://embedXcode.weebly.com
//
// Project 		Temperature
//
// Created by 	Robby Decosemaeker, 9/10/13 19:35
// 				Robby Decosemaeker
//	
// Copyright 	© Robby Decosemaeker, 2013
// License 		<#license#>
//
// See 			LocalLibrary.cpp.h and ReadMe.txt for references
//


#include "LocalLibrary.h"

Blinker::Blinker(){}

Blinker::Blinker(uint8_t pin) {
    init(pin, 1);
}

Blinker::Blinker(uint8_t pin, uint8_t times){
    init(pin, times);
}

void Blinker::init(uint8_t pin, uint8_t times){
    _pin = pin;
    _times = times;
    pinMode(_pin, OUTPUT);
}

void Blinker::blink(uint16_t ms) {
  for (uint8_t i=0; i<_times; i++) {
    digitalWrite(_pin, HIGH);
    delay(ms >> 1);               
    digitalWrite(_pin, LOW);
    delay(ms >> 1);              
  }
}

