// copyright (c) 2017 Roberto Ceccarelli - CasaSoft
// http://strawberryfield.altervista.org 
// 
// This file is part of CasaSoft Arduino GamePortLib
// 
// CasaSoft Virtual Railways Tools is free software: 
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

// Gameport declaration
#include "GamePortTest.h"
GamePortTest GP;

void setup() {
  GP.InitScreen();
  GP.SetPins();
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int j = 0; j < 4; j++)
  {
    GP.TestButton(j);
  }
  for(int j = 0; j < 2; j++)
  {
    GP.TestAnalog(j);
    GP.TestDigital(j);
  }
}


