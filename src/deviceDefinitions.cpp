#include "deviceDefinitions.h"

int autonNumSelect = -1;
bool autonRan = false;
bool driveStraight = false;
bool turnRightPIDRunning = false;
bool turnLeftPIDRunning = false;
bool drivePIDRunning = false;

double turnRightPIDTarget;
double turnLeftPIDTarget;
double drivePIDTarget;
double desiredSpeed;

std::shared_ptr<OdomChassisController> drive;
std::shared_ptr<AsyncPositionController<double, double>> lift;

Motor leftBack(5);
Motor leftFront(7);
Motor leftMiddle(-20);
Motor rightFront(-4);
Motor rightBack(-2);
Motor rightMiddle(3);

MotorGroup leftChassis  ({leftFront, leftMiddle, leftBack});
MotorGroup rightChassis ({rightFront, rightMiddle, rightBack});

//Motor bigLiftLeft(2);
//Motor bigLiftRight(-19);

Motor bigLift(1);

//MotorGroup bigLiftA({bigLiftLeft, bigLiftRight});

//Motor bigLift (7, false, AbstractMotor::gearset::red, AbstractMotor::encoderUnits::degrees);
//Motor conveyor (8, true, AbstractMotor::gearset::red, AbstractMotor::encoderUnits::degrees);

//RotationSensor rightEncoder(10, true);
//RotationSensor leftEncoder(9, false);

RotationSensor rightTrackingWheel(19, true);
RotationSensor leftTrackingWheel(18, false);
//RotationSensor sideTrackingWheel(11, false);

pros::ADIDigitalOut frontClaw('A');
pros::ADIDigitalOut backClaw('A');

pros::IMU inertial(14);

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
        {-5,-7,20}, //left
        {4,2,-3} //right
    )
    /*.withMotors(
      {12, 15},
      {-13, -14}
    )*/
    .withSensors(
        rightTrackingWheel,
        leftTrackingWheel
    )
    /*.withSensors(
        rightEncoder,
        leftEncoder
    )*/
    .withGains(
        {0.0016, 0.0, 0.0}, //drive
        {0.0005,0,0}, //turn
        {0.0,0,0} //straight
    )
    /*.withGains(
        {.003, 0.0, 0.0002}, //drive
        {0.0001, 0.0001, 0.000}, //turn 
        {0, 0.0, 0.0} //angle
    )*/
    // wheel size is 4.1797_in times 3/7 gear ratio
    //.withDimensions(AbstractMotor::gearset::green, {{4.0_in, 14.0_in}, imev5GreenTPR})
    .withDimensions({AbstractMotor::gearset::blue, (36.0/84.0)}, {{4.0_in, 14_in}, imev5BlueTPR})
    .withOdometry({{2.75_in, 5_in}, 360})
    //.withOdometry()
    .buildOdometry();
    //.build();
    
    /*lift = AsyncPosControllerBuilder()
    .withMotor({2, -19})
    .withGains(
        {.001, .01, .001}
    )
    .withGearset({AbstractMotor::gearset::green, 12/84})
    .build();*/
}