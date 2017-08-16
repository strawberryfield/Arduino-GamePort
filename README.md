# Arduino-GamePort

## Library to interface Analog PC Joysticks to Arduino-GamePort

The enclosed example uses a 128x64 LCD display driven with OpenGLCD library 
(https://bitbucket.org/bperrybap/openglcd/wiki/Home)

Due to the high number of pins used by the LCD the input in the example is made via A6 and A7 analog inputs
that aren't available on all arduino boards. If you have other free input you can use those.

Library is released under GNU GPL v.3 (see the enclose LICENSE.txt)