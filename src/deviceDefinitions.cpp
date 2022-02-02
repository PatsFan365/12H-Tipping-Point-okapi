#include "deviceDefinitions.h"

MotorGroup leftChassis  ({1,2,3});
MotorGroup rightChassis ({4,5,6});

QLength wheelDiameter = 3.25_in;
QLength wheelTrack = 15_in;


Motor bigLift (7, false, AbstractMotor::gearset::red, AbstractMotor::encoderUnits::degrees);
Motor conveyor (8, true, AbstractMotor::gearset::red, AbstractMotor::encoderUnits::degrees);

RotationSensor rightTrackingWheel(9, false);
RotationSensor leftTrackingWheel(10, false);
RotationSensor sideTrackingWheel(11, false);

pros::ADIDigitalOut tilter('A');
pros::ADIDigitalOut claw('B');

Controller mainCtrl(ControllerId::master);
ControllerButton bigLiftUpButton(ControllerDigital::R1);
ControllerButton bigLiftDownButton(ControllerDigital::R2);
ControllerButton conveyorUpButton(ControllerDigital::up);
ControllerButton conveyorDownButton(ControllerDigital::down);
ControllerButton tilterDownButton(ControllerDigital::R1);
ControllerButton tilterUpButton(ControllerDigital::R2);
ControllerButton clawActivateButton(ControllerDigital::A);