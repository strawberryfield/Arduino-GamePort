// copyright (c) 2017 Roberto Ceccarelli - CasaSoft
// http://strawberryfield.altervista.org 
// 
// This file is part of CasaSoft Arduino GamePortLib
// 
// CasaSoft Arduino GamePortLib is free software: 
// you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// CasaSoft Arduino GamePortLib is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  
// See the GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with CasaSoft Arduino GamePortLib.  
// If not, see <http://www.gnu.org/licenses/>.

#include <Arduino.h>
#include "gameportlib.h"

// Constructors
GamePortLib::GamePortLib() 
{
  GamePortLib::SetPins();
}

GamePortLib::GamePortLib(int b1pin, int b2pin, int b3pin, int b4pin, int pinx1, int piny1, int pinx2, int piny2)
{
  GamePortLib::SetPins(b1pin, b2pin, b3pin, b4pin, pinx1, piny1, pinx2, piny2);
}

// Inits
void GamePortLib::SetPins() 
{
  GamePortLib::SetPins(12, 13, 3, 2, A6, A7, UNWIRED, UNWIRED);
}

void GamePortLib::SetPins(int b1pin, int b2pin, int b3pin, int b4pin, int pinx1, int piny1, int pinx2, int piny2)
{
  buttonsPin[0] = b1pin;
  buttonsPin[1] = b2pin;
  buttonsPin[2] = b3pin;
  buttonsPin[3] = b4pin;

  analogsPin[X1] = pinx1;
  analogsPin[Y1] = piny1;
  analogsPin[X2] = pinx2;
  analogsPin[Y2] = piny2;
  GamePortLib::InitPins();

  for(int j = 0; j < 4; j++)
  {
    oldReadButton[j] = 1;
    oldReadDigital[j] = DIRECTION_NONE;
	oldReadAnalog[j] = 0;
  }
}

void GamePortLib::InitDigitalPin(int pin)
{
  if(pin != -1)
  {
    pinMode(pin, INPUT);
  }
}

void GamePortLib::InitPins()
{
  for(int j = 0; j < 4; j++) 
  {
    InitDigitalPin(buttonsPin[j]);
  }
}

// Data read methods
bool GamePortLib::ReadButton(int button)
{
  return digitalRead(buttonsPin[button]); 
}

int GamePortLib::ReadAnalog(int axis)
{
  return analogRead(analogsPin[axis]);
}

int GamePortLib::ReadDigital(int axis)
{
  int r = analogRead(analogsPin[axis]);
  if(r > ANALOG_CENTER + ANALOG_DELTA)
    return 1;
  if(r < ANALOG_CENTER - ANALOG_DELTA)
    return -1;
  else
    return 0;   
}

// Test methods
void GamePortLib::TestButton(int button)
{
  bool s = ReadButton(button);
  if(oldReadButton[button] != s) 
  {
	WriteButton(button, s);
  }	
  oldReadButton[button] = s;
}

void GamePortLib::TestDigital(int axis)
{
  int s = ReadDigital(axis);
  if(oldReadDigital[axis] != s) 
  {
	WriteDigital(axis, s);
  }	
  oldReadDigital[axis] = s;
}

void GamePortLib::TestAnalog(int axis)
{
  int s = ReadAnalog(axis);
  if(oldReadAnalog[axis] != s) 
  {
	WriteAnalog(axis, s);
  }	
  oldReadAnalog[axis] = s;
}
