#include "driveFunctions.h"

/*double currentOrientation =  0.0;

double currentR;
double lastR = 0.0;
double deltaR;

double currentL;
double lastL = 0.0;
double deltaL;

const double sR = 2.5;
const double sL = 2.5;

const double rWheel = M_PI * 2.75;
const double lWheel = M_PI * 2.75;*/

const int LOOP_DELAY = 15;

/*void calculateOrientation(){
    currentR = rightTrackingWheel.get();
    currentL = leftTrackingWheel.get();
    deltaR = ((currentR - lastR)/360) * rWheel;
    deltaL = ((currentL - lastL)/360) * lWheel;
    currentOrientation += (deltaR - deltaL) / (sR + sL);
    lastR = currentR;
    lastL = currentL;
}*/

double bindToMagnitude(double value, double MAX_MAGNITUDE)
{
  if(value > MAX_MAGNITUDE)
  {
    value = MAX_MAGNITUDE;
  }
  else if(value < -MAX_MAGNITUDE)
  {
    value = -MAX_MAGNITUDE;
  }
  return value;
}

void turnRightDegreesPID(){
  //calculateOrientation();
  double INTEGRATOR_MAX_MAGNITUDE = 100;
  double DELTA_T = LOOP_DELAY / 1000.0;
  double endingDegrees = turnRightPIDTarget;
  double currentDegrees = inertial.get_heading();

  double kP = .001;
  double kI = 0.0;
  double kD = 0.0;

  double porportionalAmount = 0;
  double integralAmount = 0;
  double derivativeAmount = 0;
  double accumulatedDegrees = 0;

  double lastDegrees = 0;
  double runTime = 0;
  while(turnRightPIDRunning)
  {
    currentDegrees = inertial.get_heading();

    porportionalAmount = fabs(endingDegrees - currentDegrees); //error

    accumulatedDegrees += porportionalAmount;
    accumulatedDegrees = bindToMagnitude(accumulatedDegrees, INTEGRATOR_MAX_MAGNITUDE);

    derivativeAmount = (porportionalAmount - lastDegrees) / DELTA_T;
    lastDegrees = porportionalAmount;

    integralAmount = accumulatedDegrees * DELTA_T;

    double total = porportionalAmount * kP + integralAmount * kI + derivativeAmount * kD;

    rightChassis.moveVelocity(-total);
    leftChassis.moveVelocity(total);
    printf("%.1lf\n", inertial.get_heading());

    runTime += LOOP_DELAY;
    pros::delay(LOOP_DELAY);
  }
  rightChassis.moveVelocity(0);
  leftChassis.moveVelocity(0);
}