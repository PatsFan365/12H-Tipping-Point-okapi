#ifndef deviceDefinitions_H
#define deviceDefinitions_H

#include "main.h"
using namespace okapi;
extern int autonNumSelect;
extern bool autonRan;
extern bool driveStraight;
extern bool turnRightPIDRunning;
extern bool turnLeftPIDRunning;
extern bool turnRightEnd;
extern bool turnLeftEnd;
extern bool conveyorEnd;
extern bool conveyorRunning;
extern bool liftEnd;
extern bool liftRunning;
extern bool liftBottom;
extern bool elevateIsRunning;
extern bool elevateEnd;
extern bool driveEnd;
extern bool driveIsRunning;

extern double drivePIDTarget;
extern double turnLeftPIDTarget;
extern double turnRightPIDTarget;
extern double liftTarget;

extern MotorGroup leftChassis;
extern MotorGroup rightChassis;

//extern MotorGroup bigLiftA;

extern Motor bigLift;
extern Motor conveyor;

//extern RotationSensor rightEncoder;
//extern RotationSensor leftEncoder;



extern RotationSensor rightTrackingWheel;
extern RotationSensor leftTrackingWheel;
//extern RotationSensor sideTrackingWheel;

extern pros::ADIDigitalOut frontClaw1;
extern pros::ADIDigitalOut frontClaw2;
extern pros::ADIDigitalOut backClaw1;
extern pros::ADIDigitalOut backClaw2;

extern pros::IMU inertial;

extern Controller mainCtrl;
extern ControllerButton bigLiftUpButton;
extern ControllerButton bigLiftDownButton;
extern ControllerButton conveyorOnButton;
extern ControllerButton conveyorForwardToggle;
extern ControllerButton tilterButton;
extern ControllerButton frontClawButton;

extern void initializeSystems();
extern std::shared_ptr<OdomChassisController> drive;

//extern std::shared_ptr<AsyncPositionController<double,double>> lift;

#endif