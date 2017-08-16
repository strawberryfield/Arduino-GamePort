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

#include "GamePortTest.h"

void GamePortTest::InitScreen()
{
  // Initialize the GLCD
  GLCD.Init();
  GLCD.ClearScreen();  
  GLCD.DrawBitmap(CATlogo, 0, 0);
  delay(2000);
  GLCD.ClearScreen();
  
  GLCD.SelectFont(System5x7);
  GLCD.Puts("GAMEPORT Test");

  GLCD.GotoXY(0,15);
  GLCD.Puts("Analogs");
  GLCD.GotoXY(64,15);
  for(int j = 0; j < 4; j++)
    GLCD.DrawBitmap(CircleEmpty, 84, 27+j*9);
    
  GLCD.Puts("Digitals");
  GLCD.DrawHLine(0, 11, GLCD.Width);
  GLCD.DrawBitmap(CircleFilled, 27, 45);  
}

void GamePortTest::WriteButton(int button, bool s)
{
  if(!s)
    GLCD.DrawBitmap(CircleFilled, 84, 27+button*9);
  else
    GLCD.DrawBitmap(CircleEmpty, 84, 27+button*9);
}

void GamePortTest::WriteAnalog(int axis, int s)
{
  GLCD.GotoXY(0+axis*32,27);
  GLCD.Printf("%4d", s);
}

void GamePortTest::WriteDigital(int axis, int s)
{
  if(axis == X1)
  {
    if(s == DIRECTION_LEFT)
    {
      GLCD.FillRect(36, 45, 9, 9,PIXEL_OFF);
      GLCD.DrawBitmap(ArrowLeft, 18, 45);
    }
    if(s == DIRECTION_RIGHT)
    {
      GLCD.FillRect(18, 45, 9, 9,PIXEL_OFF);
      GLCD.DrawBitmap(ArrowRight, 36, 45);
    }
    if(s == DIRECTION_NONE)
    {
      GLCD.FillRect(36, 45, 9, 9,PIXEL_OFF);
      GLCD.FillRect(18, 45, 9, 9,PIXEL_OFF);
    }
  }

  if(axis == Y1)
  {
    if(s == DIRECTION_UP)
    {
      GLCD.FillRect(27, 54, 9, 9,PIXEL_OFF);
      GLCD.DrawBitmap(ArrowUp, 27, 36);
    }
    if(s == DIRECTION_DOWN)
    {
      GLCD.FillRect(27, 36, 9, 9,PIXEL_OFF);
      GLCD.DrawBitmap(ArrowDown, 27, 54);
    }
    if(s == DIRECTION_NONE)
    {
      GLCD.FillRect(27, 36, 9, 9,PIXEL_OFF);
      GLCD.FillRect(27, 54, 9, 9,PIXEL_OFF);
    }
  }
}

