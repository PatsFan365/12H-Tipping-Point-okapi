#ifndef driveFunctions_H
#define driveFunctions_H

#include "main.h"

extern double signum(double x);

extern void turnRightDegreesPID();
extern void turnLeftDegreesPID();
extern void frontClawActivate(bool state);
extern void backTilterActivate(bool state);
extern void runConveyor();
extern void moveFrontLift();
extern void elevate();
extern void move();
extern void maxCurrent(double current);

#endif