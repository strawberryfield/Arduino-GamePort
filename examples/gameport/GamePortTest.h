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

#ifndef GAMEPORTTEST_H
#define GAMEPORTTEST_H

#include <gameportlib.h>

// include the library header
#include <openGLCD.h>

// fonts and images
#include <fonts/System5x7.h>
#include <bitmaps/CATlogo.h>
#include <bitmaps/CircleEmpty.h>
#include <bitmaps/CircleFilled.h>
#include <bitmaps/ArrowLeft.h>
#include <bitmaps/ArrowRight.h>
#include <bitmaps/ArrowUp.h>
#include <bitmaps/ArrowDown.h>

class GamePortTest : public GamePortLib 
{
public:
  using GamePortLib::GamePortLib;
  void InitScreen();
  
protected:
  virtual void WriteButton(int button, bool s);
  virtual void WriteAnalog(int axis, int s);
  virtual void WriteDigital(int axis, int s);

};
#endif

