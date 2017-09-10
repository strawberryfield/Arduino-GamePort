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

  GLCD.GotoXY(10,15);
  GLCD.Puts("Joy 1");
  GLCD.GotoXY(74,15);
  GLCD.Puts("Joy 2");

  buttonPos[0] = 2;
  buttonPos[1] = 64-9-2;
  buttonPos[2] = 64+2;
  buttonPos[3] = 64+64-9-2;
  
  for(int j = 0; j < 4; j++)
    GLCD.DrawBitmap(CircleEmpty, buttonPos[j], 54);
    
  
  GLCD.DrawHLine(0, 11, GLCD.Width);
  GLCD.DrawVLine(64, 11, GLCD.Height-11);
  GLCD.DrawBitmap(CircleFilled, 27, 45);  
  GLCD.DrawBitmap(CircleFilled, 27+64, 45);  
}

void GamePortTest::WriteButton(int button, bool s)
{
  if(!s)
    GLCD.DrawBitmap(CircleFilled, buttonPos[button], 54);
  else
    GLCD.DrawBitmap(CircleEmpty, buttonPos[button], 54);
}

void GamePortTest::WriteAnalog(int axis, int s)
{
  GLCD.GotoXY(1+axis*32,27);
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

  if(axis == X2)
  {
    if(s == DIRECTION_LEFT)
    {
      GLCD.FillRect(36+64, 45, 9, 9,PIXEL_OFF);
      GLCD.DrawBitmap(ArrowLeft, 18+64, 45);
    }
    if(s == DIRECTION_RIGHT)
    {
      GLCD.FillRect(18+64, 45, 9, 9,PIXEL_OFF);
      GLCD.DrawBitmap(ArrowRight, 36+64, 45);
    }
    if(s == DIRECTION_NONE)
    {
      GLCD.FillRect(36+64, 45, 9, 9,PIXEL_OFF);
      GLCD.FillRect(18+64, 45, 9, 9,PIXEL_OFF);
    }
  }

  if(axis == Y2)
  {
    if(s == DIRECTION_UP)
    {
      GLCD.FillRect(27+64, 54, 9, 9,PIXEL_OFF);
      GLCD.DrawBitmap(ArrowUp, 27, 36);
    }
    if(s == DIRECTION_DOWN)
    {
      GLCD.FillRect(27+64, 36, 9, 9,PIXEL_OFF);
      GLCD.DrawBitmap(ArrowDown, 27, 54);
    }
    if(s == DIRECTION_NONE)
    {
      GLCD.FillRect(27+64, 36, 9, 9,PIXEL_OFF);
      GLCD.FillRect(27+64, 54, 9, 9,PIXEL_OFF);
    }
  }

}

