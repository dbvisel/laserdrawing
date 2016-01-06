This code is for an Arduino connected to two servos and a laser pointer. This code needs a lot of work!

# HARDWARE REQUIREMENTS

This is being run on an old Arduino Duemilanove with a motor shield that I found in Bangkok, but the hardware doesn't matter that much at this stage. The vertical servo is mounted on top of the horizontal servo; the laser pointer is attached to the rotor of the vertical servo.

 * The servo controlling vertical motion should be controlled by pin 9 (_servo1Pin_).
 * The servo controlling horizontal motion should be controlled by pin 10 (_servo2Pin_).
 * The laser should be connected to pin 2 (_laserpin_).

# TO DO

 * General routines for drawing lines + curves
 * Special routines for drawing letters
 * Code to process text
