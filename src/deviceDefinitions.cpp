#include "deviceDefinitions.h"

int autonNumSelect = -1;
bool autonRan = false;

std::shared_ptr<OdomChassisController> drive;
std::shared_ptr<AsyncPositionController<double, double>> lift;

Motor leftBack(12);
Motor leftFront(15);
Motor rightFront(-13);
Motor rightBack(-14);

MotorGroup leftChassis  ({leftFront, leftBack});
MotorGroup rightChassis ({rightFront, rightBack});

Motor bigLiftLeft(2);
Motor bigLiftRight(-19);

MotorGroup bigLiftA({bigLiftLeft, bigLiftRight});

//Motor bigLift (7, false, AbstractMotor::gearset::red, AbstractMotor::encoderUnits::degrees);
//Motor conveyor (8, true, AbstractMotor::gearset::red, AbstractMotor::encoderUnits::degrees);

RotationSensor rightEncoder(10, false);
RotationSensor leftEncoder(9, false);

//RotationSensor rightTrackingWheel(9, false);
//RotationSensor leftTrackingWheel(10, false);
//RotationSensor sideTrackingWheel(11, false);

//pros::ADIDigitalOut tilter('A');

Controller mainCtrl(ControllerId::master);
ControllerButton bigLiftUpButton(ControllerDigital::R1);
ControllerButton bigLiftDownButton(ControllerDigital::R2);
//ControllerButton conveyorUpButton(ControllerDigital::up);
//ControllerButton conveyorDownButton(ControllerDigital::down);
//ControllerButton tilterDownButton(ControllerDigital::R1);
//ControllerButton tilterUpButton(ControllerDigital::R2);

void initializeSystems(){
    drive = ChassisControllerBuilder()
    .withMotors(
      {12, 15},
      {13, 14}
    )
    .withSensors(
        rightEncoder,
        leftEncoder
    )
    .withGains(
        {.5, 0.0, 0.0}, //drive
        {.001, 0.0, 0.0}, //turn 
        {.001, 0.0, 0.0} //angle
    )
    // wheel size is 4.1797_in times 3/7 gear ratio
    .withDimensions(AbstractMotor::gearset::green, {{4.0_in, 14.0_in}, imev5GreenTPR})
    // .withDimensions(AbstractMotor::gearset::blue, {{1.7913_in, 10.6016_in}, imev5BlueTPR})
    //.withOdometry({{2.5_in, 2.75_in}, 3600})
    .withOdometry()
    .buildOdometry();
    
    /*lift = AsyncPosControllerBuilder()
    .withMotor({2, -19})
    .withGains(
        {.001, .01, .001}
    )
    .withGearset({AbstractMotor::gearset::green, 12/84})
    .build();*/
}