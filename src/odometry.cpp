#include "odometry.h"

/*double x = 0;
double y = 0;
double theta;

double distance;
double lastR = 0;
double lastL = 0;
double currentR;
double currentL;
double deltaR;
double deltaL;

void positionTracking(){
    currentR = (rightTrackingWheel.get() / 360) * (M_PI * 2.75);
    currentL = (leftTrackingWheel.get() / 360) * (M_PI * 2.75);
    deltaR = lastR - currentR;
    deltaL = lastL - currentL;
    distance = (deltaR + deltaL)/2;
    theta = inertial.get_heading();
    x += distance * cos(theta);
    y += distance * sin(theta);
    pros::delay(20);
}*/
std::vector<double>position = {0,0};
std::vector<double>polar;
std::vector<double> displacement;
double deltaPosition;

double lastOrientation = 0;
double currentOrientation = 0;
double averageOrientation = 0;
double deltaOrientation;
const double sR = 2.5;
const double sL = 2.5;
//const double sS = 5.5;

const double rWheel = M_PI * 2.75;
const double lWheel = M_PI * 2.75;
//const double sWheel = M_PI * 3.25;

double currentR;
double lastR = 0.0;
double deltaR;

double currentL;
double lastL = 0.0;
double deltaL;

void calculateOrientation(){
    currentR = rightTrackingWheel.get();
    currentL = leftTrackingWheel.get();
    deltaR = ((currentR - lastR)/360) * rWheel;
    deltaL = ((currentL - lastL)/360) * lWheel;
    currentOrientation += (deltaR - deltaL) / (sR + sL);
    lastR = currentR;
    lastL = currentL;
    printf("hola");
}

void positionTracking(){
        printf("test");
        deltaOrientation = lastOrientation - currentOrientation;
        if(lastOrientation == currentOrientation){
            deltaPosition = deltaR;
            printf("test2\n");
        }
        else{
            deltaPosition = 2 * sin(currentOrientation/2) * ((deltaR/deltaOrientation)+ sR);
        }
        averageOrientation = lastOrientation + (deltaOrientation / 2);
        polar[0] = deltaPosition;
        polar[1] = currentOrientation - averageOrientation;
        displacement[0] = polar[0] * cos(polar[1]);
        displacement[1] = polar[0] * sin(polar[1]);
        position[0] += displacement[0];
        position[1] += displacement[1];
        lastOrientation = currentOrientation;
        printf("hello");
}