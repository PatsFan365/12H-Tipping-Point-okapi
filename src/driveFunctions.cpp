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

double signum(double x){
  if(x>0){
    return 1;
  }
  else if(x<0){
    return -1;
  }
  else{
    return 0;
  }
}
void maxCurrent(double current){
  rightChassis.setCurrentLimit(current);
  leftChassis.setCurrentLimit(current);
}
void move(){
  double INTEGRATOR_MAX_MAGNITUDE = 100;
  double DELTA_T = LOOP_DELAY / 1000.0;
  double trackingWheelCircumference = (2.75 * M_PI);
  double endingDegrees = (drivePIDTarget/trackingWheelCircumference) * 360;
  double currentDegrees = rightTrackingWheel.get();

  double kP = 0.5;
  double kI = 0.0;//.5
  double kD = 0.01;//.1

  double porportionalAmount = 0;
  double integralAmount = 0;
  double derivativeAmount = 0;
  double accumulatedDegrees = 0;

  double lastDegrees = 0;
  double runTime = 0;
  bool setZero = true;
  while(true){
    if(driveEnd){
      return;
    }
    if(driveIsRunning){
      endingDegrees = (drivePIDTarget/trackingWheelCircumference) * 360;
      currentDegrees = rightTrackingWheel.get();
      porportionalAmount = endingDegrees - currentDegrees;

    accumulatedDegrees += porportionalAmount;
    accumulatedDegrees = bindToMagnitude(accumulatedDegrees, INTEGRATOR_MAX_MAGNITUDE);

    derivativeAmount = (porportionalAmount - lastDegrees) / DELTA_T;
    lastDegrees = porportionalAmount;

    integralAmount = accumulatedDegrees * DELTA_T;
    printf("%.1lf", porportionalAmount);
    double total = porportionalAmount * kP + integralAmount * kI + derivativeAmount * kD;

    rightChassis.moveVelocity(total);
    leftChassis.moveVelocity(total);
    pros::delay(LOOP_DELAY);
    setZero = true;
  }else{
    if(setZero){
      rightChassis.moveVelocity(0);
      leftChassis.moveVelocity(0);
      setZero = false;
    }
  porportionalAmount = 0;
  integralAmount = 0;
  derivativeAmount = 0;
  accumulatedDegrees = 0;
  lastDegrees = 0;
  runTime = 0;
  pros::delay(20);
  }
  }
}
void turnRightDegreesPID(){
  //calculateOrientation();
  double INTEGRATOR_MAX_MAGNITUDE = 100;
  double DELTA_T = LOOP_DELAY / 1000.0;
  double endingDegrees = turnRightPIDTarget;
  double currentDegrees = inertial.get_heading();

  double kP = 3.4;
  double kI = 0.5;//.5
  double kD = 0.1;//.1

  double porportionalAmount = 0;
  double integralAmount = 0;
  double derivativeAmount = 0;
  double accumulatedDegrees = 0;
  double difference = 0.0;

  double lastDegrees = 0;
  double runTime = 0;
  bool setZero = true;
  while(true){
    if(turnRightEnd){
      return;
    }
  if(turnRightPIDRunning)
  {
    endingDegrees = turnRightPIDTarget;
    currentDegrees = inertial.get_heading();
    difference = endingDegrees - currentDegrees;
    if(signum(difference) == -1){
      porportionalAmount = 360 - fabs(endingDegrees - currentDegrees);
    } else{
      porportionalAmount = fabs(endingDegrees - currentDegrees);
    }

    accumulatedDegrees += porportionalAmount;
    accumulatedDegrees = bindToMagnitude(accumulatedDegrees, INTEGRATOR_MAX_MAGNITUDE);

    derivativeAmount = (porportionalAmount - lastDegrees) / DELTA_T;
    lastDegrees = porportionalAmount;

    integralAmount = accumulatedDegrees * DELTA_T;

    double total = porportionalAmount * kP + integralAmount * kI + derivativeAmount * kD;

    rightChassis.moveVelocity(-total);
    leftChassis.moveVelocity(total);
    printf("%.1lf\n", inertial.get_heading());

    //runTime += LOOP_DELAY;
    printf("%.1lf",endingDegrees);
    printf("%.1lf",currentDegrees);
    pros::delay(LOOP_DELAY);
    setZero = true;
  }else{
    if(setZero){
      rightChassis.moveVelocity(0);
      leftChassis.moveVelocity(0);
      setZero = false;
    }
  porportionalAmount = 0;
  integralAmount = 0;
  derivativeAmount = 0;
  accumulatedDegrees = 0;
  difference = 0.0;
  lastDegrees = 0;
  runTime = 0;
  pros::delay(20);
  }
}
}
void turnLeftDegreesPID(){
  //calculateOrientation();
  double INTEGRATOR_MAX_MAGNITUDE = 100;
  double DELTA_T = LOOP_DELAY / 1000.0;
  double endingDegrees = turnLeftPIDTarget;
  double currentDegrees = inertial.get_heading();

  double kP = .6;
  double kI = 0.0;
  double kD = 0.01; //=.05

  double porportionalAmount = 0;
  double integralAmount = 0;
  double derivativeAmount = 0;
  double accumulatedDegrees = 0;
  double difference = 0.0;

  double lastDegrees = 0;
  double runTime = 0;
  bool setZeroL = true;
  while(true){
    if(turnLeftEnd){
      return;
    }
  if(turnLeftPIDRunning)
  {
    endingDegrees = turnLeftPIDTarget;
    currentDegrees = inertial.get_heading();
    difference = endingDegrees - currentDegrees;
    if(signum(difference) == -1){
      porportionalAmount = 360 - fabs(endingDegrees - currentDegrees);
    } else{
      porportionalAmount = fabs(endingDegrees - currentDegrees);
    }

    accumulatedDegrees += porportionalAmount;
    accumulatedDegrees = bindToMagnitude(accumulatedDegrees, INTEGRATOR_MAX_MAGNITUDE);

    derivativeAmount = (porportionalAmount - lastDegrees) / DELTA_T;
    lastDegrees = porportionalAmount;

    integralAmount = accumulatedDegrees * DELTA_T;

    double total = porportionalAmount * kP + integralAmount * kI + derivativeAmount * kD;

    rightChassis.moveVelocity(total);
    leftChassis.moveVelocity(-total);
    printf("%.1lf\n", inertial.get_heading());

    //runTime += LOOP_DELAY;
    pros::delay(LOOP_DELAY);
    setZeroL = true;
  }else{
    if(setZeroL){
      rightChassis.moveVelocity(0);
      leftChassis.moveVelocity(0);
      setZeroL = false;
    }
  porportionalAmount = 0;
  integralAmount = 0;
  derivativeAmount = 0;
  accumulatedDegrees = 0;
  difference = 0.0;
  lastDegrees = 0;
  runTime = 0;
  pros::delay(20);
  if(porportionalAmount < .02){
    turnLeftPIDRunning = false;
  }
  }
}
}
void frontClawActivate(bool state){
  frontClaw1.set_value(state);
  frontClaw2.set_value(state);
}
void backTilterActivate(bool state){
  backClaw1.set_value(state);
  backClaw2.set_value(state);
}
void runConveyor(){
  while(true){
    if(conveyorEnd){
      return;
    }
    if(conveyorRunning){
      conveyor.moveVelocity(450);
    } else {
      conveyor.moveVelocity(0);
    }
    pros::delay(20);
  }
}
void moveFrontLift(){
  bool setZeroLift = true;
  double porportionalAmount;
  double endingRotations;
  double currentRotations;
  double kP;
  while(true){
    if(liftEnd){
      return;
    }
    if(liftRunning){
      endingRotations = liftTarget;
      currentRotations = bigLift.getPosition();
      kP = 75.0;

      porportionalAmount = endingRotations - currentRotations;
      double total = porportionalAmount * kP;
      bigLift.moveVoltage(-total);
      setZeroLift = true;
      printf("%lf\n", endingRotations);
      printf("%.1lf\n", currentRotations);
      pros::delay(15);
    } else{
      if(setZeroLift && !liftBottom){
        bigLift.moveVoltage(0);
        setZeroLift = false;
      } else if (setZeroLift){
        bigLift.moveVelocity(-10);
        setZeroLift = false;
      }
      porportionalAmount = 0;
      pros::delay(20);
    }
  }
}
void elevate(){
  double kP = 1.0;
  double proportionalAmount;
  bool setZeroElevate = false;
  while(true){
    if(elevateEnd){
      return;
    }
    if(elevateIsRunning){
      proportionalAmount = inertial.get_pitch();
      double total = kP * proportionalAmount;
      leftChassis.moveVoltage(-total);
      rightChassis.moveVoltage(-total);
      setZeroElevate = true;
    }
    else{
      if(setZeroElevate){
        leftChassis.moveVoltage(0);
        rightChassis.moveVoltage(0);
        setZeroElevate = false;
      }
    }
  }
}