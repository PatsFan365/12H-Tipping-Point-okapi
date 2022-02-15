#ifndef odometry_H
#define odometry_H

#include "main.h"

extern std::vector<double> position;
extern double deltaPosition;

extern double currentOrientation;

//extern void calculateOrientation();
extern void positionTracking();

#endif