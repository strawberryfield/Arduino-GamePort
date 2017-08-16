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

#ifndef GAMEPORTLIB_H
#define GAMEPORTLIB_H

#define UNWIRED -1
#define X1      0
#define Y1      1
#define X2      2
#define Y2      3

#define ANALOG_CENTER   700
#define ANALOG_DELTA    100

#define DIRECTION_UP      1
#define DIRECTION_DOWN   -1
#define DIRECTION_LEFT    1
#define DIRECTION_RIGHT  -1
#define DIRECTION_NONE    0

class GamePortLib
{
private:
  int buttonsPin[4];
  int analogsPin[4];

  void InitDigitalPin(int pin);
public:
  // used to save old buttons and sticks states	
  int oldReadButton[4];
  int oldReadDigital[4];
  int oldReadAnalog[4];

  // Constructors
  GamePortLib();
  GamePortLib(int b1pin, int b2pin, int b3pin, int b4pin, int pinx1, int piny1, int pinx2, int piny2);

  // Methods
  void SetPins();
  void SetPins(int b1pin, int b2pin, int b3pin, int b4pin, int pinx1, int piny1, int pinx2, int piny2);
  bool ReadButton(int button);
  int ReadAnalog(int axis);
  int ReadDigital(int axis);

  // Diagnostic
  void TestButton(int button);
  void TestAnalog(int axis);
  void TestDigital(int axis);
  
protected:
  void InitPins();

  // Diagnostic  
  virtual void WriteButton(int button, bool s) {}
  virtual void WriteAnalog(int axis, int s) {}
  virtual void WriteDigital(int axis, int s) {}

};

#endif
