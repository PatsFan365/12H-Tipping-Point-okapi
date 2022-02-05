#ifndef deviceDefinitions_H
#define deviceDefinitions_H

#include "main.h"
using namespace okapi;
extern int autonNumSelect;

extern MotorGroup leftChassis;
extern MotorGroup rightChassis;

extern QLength wheelDiameter;
extern QLength wheelTrack;

extern Motor bigLift;
extern Motor conveyor;

extern RotationSensor rightTrackingWheel;
extern RotationSensor leftTrackingWheel;
extern RotationSensor sideTrackingWheel;

extern pros::ADIDigitalOut tilter;
extern pros::ADIDigitalOut claw;

extern Controller mainCtrl;
extern ControllerButton bigLiftUpButton;
extern ControllerButton bigLiftDownButton;
extern ControllerButton conveyorUpButton;
extern ControllerButton conveyorDownButton;
extern ControllerButton tilterDownButton;
extern ControllerButton tilterUpButton;
extern ControllerButton clawActivateButton;

#endif