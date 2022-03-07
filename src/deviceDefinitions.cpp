#include "deviceDefinitions.h"

int autonNumSelect = -1;
bool autonRan = false;
bool driveStraight = false;
bool turnRightPIDRunning = false;
bool turnLeftPIDRunning = false;
bool turnRightEnd = false;
bool turnLeftEnd = false;
bool conveyorEnd = false;
bool conveyorRunning = false;
bool liftEnd = false;
bool liftRunning = false;
bool liftBottom = false;
bool elevateIsRunning = false;
bool elevateEnd = false;
bool driveEnd = false;
bool driveIsRunning = false;

double turnRightPIDTarget;
double turnLeftPIDTarget;
double drivePIDTarget;
double desiredSpeed;
double liftTarget;

std::shared_ptr<OdomChassisController> drive;
std::shared_ptr<AsyncPositionController<double, double>> lift;

Motor leftBack(-5);
Motor leftFront(-7);
Motor leftMiddle(20);
Motor rightFront(4);
Motor rightBack(13);
Motor rightMiddle(-3);

MotorGroup leftChassis  ({leftFront, leftMiddle, leftBack});
MotorGroup rightChassis ({rightFront, rightMiddle, rightBack});

//Motor bigLiftLeft(2);
//Motor bigLiftRight(-19);

Motor bigLift(11, false, AbstractMotor::gearset::red, AbstractMotor::encoderUnits::degrees);

//MotorGroup bigLiftA({bigLiftLeft, bigLiftRight});

//Motor bigLift (7, false, AbstractMotor::gearset::red, AbstractMotor::encoderUnits::degrees);
Motor conveyor (12, true, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::rotations);

//RotationSensor rightEncoder(10, true);
//RotationSensor leftEncoder(9, false);

RotationSensor rightTrackingWheel(19, true);
RotationSensor leftTrackingWheel(18, false);
//RotationSensor sideTrackingWheel(11, false);

pros::ADIDigitalOut frontClaw1('D',true);
pros::ADIDigitalOut frontClaw2('E', true);
pros::ADIDigitalOut backClaw1('G', true);
pros::ADIDigitalOut backClaw2('H', true);

pros::IMU inertial(15);

Controller mainCtrl(ControllerId::master);
ControllerButton bigLiftUpButton(ControllerDigital::R1);
ControllerButton bigLiftDownButton(ControllerDigital::R2);
ControllerButton conveyorOnButton(ControllerDigital::up);
ControllerButton conveyorForwardToggle(ControllerDigital::down);
ControllerButton tilterButton(ControllerDigital::L2);
ControllerButton frontClawButton(ControllerDigital::L1);

void initializeSystems(){
    drive = ChassisControllerBuilder()
    .withMotors(
        {-5,-7,20}, //left
        {4,13,-3} //right
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