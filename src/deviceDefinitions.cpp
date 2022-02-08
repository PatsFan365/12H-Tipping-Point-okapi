#include "deviceDefinitions.h"

int autonNumSelect = -1;

std::shared_ptr<OdomChassisController> drive;
std::shared_ptr<AsyncPositionController<double, double>> lift;

MotorGroup leftChassis  ({1,2,3});
MotorGroup rightChassis ({4,5,6});

Motor bigLift (7, false, AbstractMotor::gearset::red, AbstractMotor::encoderUnits::degrees);
Motor conveyor (8, true, AbstractMotor::gearset::red, AbstractMotor::encoderUnits::degrees);

RotationSensor rightTrackingWheel(9, false);
RotationSensor leftTrackingWheel(10, false);
//RotationSensor sideTrackingWheel(11, false);

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

void initializeSystems(){
    drive = ChassisControllerBuilder()
    .withMotors(
      leftChassis,
      rightChassis
    )
    .withSensors(
        rightTrackingWheel,
        leftTrackingWheel
    )
    // wheel size is 4.1797_in times 3/7 gear ratio
    .withDimensions({AbstractMotor::gearset::green, (3.0 / 7.0)}, {{4.1797_in, 10.6016_in}, imev5GreenTPR})
    // .withDimensions(AbstractMotor::gearset::blue, {{1.7913_in, 10.6016_in}, imev5BlueTPR})
    .withOdometry({{2.5_in, 2.75_in}, 3600})
    .buildOdometry();
    
    lift = AsyncPosControllerBuilder()
    .withMotor(7)
    .withGains(
        {.001, .01, .001}
    )
    .withGearset({AbstractMotor::gearset::red, 2/3})
    .build();
}