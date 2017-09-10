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

#ifndef GAMEPORTMUX_H
#define GAMEPORTMUX_H

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

class GamePortMux
{
private:
  int inputPin;
  int joySelPin;
  int anaDigSelPin;
  int unitSelPin;

public:
  // used to save old buttons and sticks states	
  int oldReadButton[4];
  int oldReadDigital[4];
  int oldReadAnalog[4];

  // Constructors
  GamePortMux();
  GamePortMux(int input, int joySel, int anaDigSel, int unitSel);

  // Init Methods
  void SetPins();
  
  // Read Methods
  void SetPins(int input, int joySel, int anaDigSel, int unitSel);
  bool ReadButton(int button);
  int ReadAnalog(int axis);
  int ReadDigital(int axis);

  // Diagnostic
  void TestButton(int button);
  void TestAnalog(int axis);
  void TestDigital(int axis);
  
protected:
  // Multiplexer management
  void SetMux(int joySel, int anaDigSel, int unitSel);
  void SetMuxButton(int button);
  void SetMuxAxis(int axis);

  // Diagnostic  
  virtual void WriteButton(int button, bool s) {}
  virtual void WriteAnalog(int axis, int s) {}
  virtual void WriteDigital(int axis, int s) {}

};

#endif
