#ifndef deviceDefinitions_H
#define deviceDefinitions_H

#include "main.h"
using namespace okapi;
extern int autonNumSelect;
extern bool autonRan;

extern MotorGroup leftChassis;
extern MotorGroup rightChassis;

extern MotorGroup bigLiftA;

//extern Motor bigLift;
extern Motor conveyor;

extern RotationSensor rightEncoder;
extern RotationSensor leftEncoder;



//extern RotationSensor rightTrackingWheel;
//extern RotationSensor leftTrackingWheel;
//extern RotationSensor sideTrackingWheel;

//extern pros::ADIDigitalOut tilter;

extern Controller mainCtrl;
extern ControllerButton bigLiftUpButton;
extern ControllerButton bigLiftDownButton;
//extern ControllerButton conveyorUpButton;
//extern ControllerButton conveyorDownButton;
//extern ControllerButton tilterDownButton;
//extern ControllerButton tilterUpButton;

extern void initializeSystems();
extern std::shared_ptr<OdomChassisController> drive;
//extern std::shared_ptr<AsyncPositionController<double,double>> lift;

#endif