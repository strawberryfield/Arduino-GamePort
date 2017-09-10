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
#include "gameportmux.h"

// Constructors
GamePortMux::GamePortMux() 
{
  GamePortMux::SetPins();
}

GamePortMux::GamePortMux(int input, int joySel, int anaDigSel, int unitSel)
{
  GamePortMux::SetPins(input, joySel, anaDigSel, unitSel);
}

// Inits
void GamePortMux::SetPins() 
{
  GamePortMux::SetPins(A6, 13, 12, 3);
}

void GamePortMux::SetPins(int input, int joySel, int anaDigSel, int unitSel)
{
  inputPin		= input;
  joySelPin		= joySel;
  anaDigSelPin	= anaDigSel;
  unitSelPin	= unitSel;

  pinMode(joySelPin, OUTPUT);		
  pinMode(anaDigSelPin, OUTPUT);	
  pinMode(unitSelPin, OUTPUT);	
  
  for(int j = 0; j < 4; j++)
  {
    oldReadButton[j] = 1;
    oldReadDigital[j] = DIRECTION_NONE;
	oldReadAnalog[j] = 0;
  }
}

// Multiplexer management
void GamePortMux::SetMux(int joySel, int anaDigSel, int unitSel)
{
  digitalWrite(joySelPin, joySel);
  digitalWrite(anaDigSelPin, anaDigSel);
  digitalWrite(unitSelPin, unitSel);
}

void GamePortMux::SetMuxButton(int button)
{
	SetMux(bitRead(button, 1), 0, button & 1);
}

void GamePortMux::SetMuxAxis(int axis)
{
	SetMux(bitRead(axis, 1), 1, axis & 1);
}

// Data read methods
bool GamePortMux::ReadButton(int button)
{
  SetMuxButton(button);	
  return analogRead(inputPin) > ANALOG_CENTER; 
}

int GamePortMux::ReadAnalog(int axis)
{
  SetMuxAxis(axis);	
  return analogRead(inputPin);
}

int GamePortMux::ReadDigital(int axis)
{
  SetMuxAxis(axis);	
  int r = analogRead(inputPin);
  if(r > ANALOG_CENTER + ANALOG_DELTA)
    return 1;
  if(r < ANALOG_CENTER - ANALOG_DELTA)
    return -1;
  else
    return 0;   
}

// Test methods
void GamePortMux::TestButton(int button)
{
  bool s = ReadButton(button);
  if(oldReadButton[button] != s) 
  {
	WriteButton(button, s);
  }	
  oldReadButton[button] = s;
}

void GamePortMux::TestDigital(int axis)
{
  int s = ReadDigital(axis);
  if(oldReadDigital[axis] != s) 
  {
	WriteDigital(axis, s);
  }	
  oldReadDigital[axis] = s;
}

void GamePortMux::TestAnalog(int axis)
{
  int s = ReadAnalog(axis);
  if(oldReadAnalog[axis] != s) 
  {
	WriteAnalog(axis, s);
  }	
  oldReadAnalog[axis] = s;
}
