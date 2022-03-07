#include "autons.h"

void rightAuton(){
    /*
    1) drive forward to right mobile goal
    2)lift the lift up to get standoffs under and activated
    3) drive back
    4) turn to the right put down mobile goal
    5) turn to face middle
    6) drive to middle
    7) lift standoffs to drag back
    8) drive backwards
    */
   frontClawActivate(false);
   maxCurrent(10000);
   drivePIDTarget = 54;
   driveIsRunning = true;
   pros::delay(1250);
   driveIsRunning = false;
    frontClawActivate(true);
    pros::delay(15);
   drivePIDTarget= -40;
   driveIsRunning = true;
   pros::delay(1250);
   driveIsRunning = false;
}

void leftAuton(){
    /*
    1) drive forward to left mobile goal
    2) lift the lift up to get standoffs under and activated
    3) drive back
    4) turn to the left put down mobile goal
    5) turn to face middle
    6) drive to middle
    7) lift standoffs to drag back
    8) drive backwards
    */
   frontClawActivate(false);
   drive->setMaxVelocity(600);
   drive->moveDistance(50_in);
   pros::delay(1250);
    frontClawActivate(true);
    pros::delay(15);
   drive->moveDistance(-40_in);
   pros::delay(1750);
   /*turnLeftPIDTarget = 270;
   turnLeftPIDRunning = true;
   pros::delay(5000);
   turnLeftPIDRunning = false;*/
}

void halfWinPointRightAuton(){
    /*
    1) drive forward to right mobile goal
    2)lift the lift up to get standoffs under and activated
    3) drive back
    4) turn to the right slightly to drive not right against the alliance goal
    4) turn so back lift faces alliance goal
    5) put tilter down
    6) drive into the goal
    7) Pick up goal
    8) activate conveyor
    9) turn to the right slightly at the same time
    10) drive back at the same time
`   11) put down yellow goal
    12) turn to face middle mobile goal
    13) drive to middle mobile goal
    14) flip tilter down at the same time
    15) lift the lift up sligtly to catch standoffs
    16) drive backwards
    */
   backTilterActivate(false);
   maxCurrent(4000);
   drivePIDTarget = 20;
   driveIsRunning = true;
    pros::delay(1000);
    driveIsRunning = false;
   pros::delay(1000);
   backTilterActivate(true);
   pros::delay(500);
   bigLift.moveRelative(400, 100);
   drivePIDTarget = -20;
   driveIsRunning = true;
    pros::delay(1000);
    driveIsRunning = false;
   conveyorRunning = true;
   pros::delay(5000);
   conveyorRunning = false;
   backTilterActivate(false);
}

void halfWinPointLeftAuton(){
    backTilterActivate(false);
    drive->setMaxVelocity(200);
    drive->moveDistance(-10_in);
    pros::delay(2000);
    bigLift.moveRelative(400, 100);
    pros::delay(500);
    backTilterActivate(true);
    pros::delay(100);
    conveyorRunning = true;
    pros::delay(5000);
    conveyorRunning = false;
    drive->moveDistance(15_in);
    pros::delay(1000);
    backTilterActivate(false);

    /*
    1) drive forward to left mobile goal
    2)lift the lift up to get standoffs under and activated
    3) drive back
    4) turn to the right slightly to drive not right against the alliance goal
    4) turn so back lift faces alliance goal
    5) put tilter down
    6) drive into the goal
    7) Pick up goal
    8) activate conveyor
    9) turn to the left slightly at the same time
    10) put down yellow mobile goal
    11) turn to face middle mobile goal
    12) put tilter down
    13) drive to the middle mobile goal while putting tilter down
    14) lift the lift up to get standoffs under
    15) drive backwards
    */
}

void winPointLeft(){
backTilterActivate(false);
liftTarget = 400;
liftRunning = true;
pros::delay(1000);
liftRunning = false;
frontClawActivate(true);
turnRightPIDTarget = 30;
turnRightPIDRunning = true;
pros::delay(750);
turnRightPIDRunning = false;
drive->moveDistance(-10_in);
pros::delay(750);
turnRightPIDTarget = 135;
turnRightPIDRunning = true;
pros::delay(1000);
turnRightPIDRunning = false;
drive->moveDistance(-25_in);
pros::delay(1000);
turnRightPIDTarget = 180;
turnRightPIDRunning = true;
pros::delay(1000);
turnRightPIDRunning = false;
drive->moveDistance(-80_in);
pros::delay(3000);
leftChassis.moveVoltage(-12000);
rightChassis.moveVoltage(-12000);
pros::delay(1000);
backTilterActivate(true);
rightChassis.moveVoltage(0);
leftChassis.moveVoltage(0);
pros::delay(1000);
drive->moveDistance(20_in);
pros::delay(1000);
conveyorRunning = true;
pros::delay(2000);
conveyorRunning = false;
}

void middle(){
frontClawActivate(false);
drive->moveDistance(64_in);
pros::delay(2250);
frontClawActivate(true);
pros::delay(500);
drive->moveDistance(-60_in);
pros::delay(3000);
}

void skills(){
    backTilterActivate(false);
    maxCurrent(3000);
    rightTrackingWheel.reset();
    drivePIDTarget = -15;
    driveIsRunning = true;
    pros::delay(2000);
    driveIsRunning = false;
    backTilterActivate(true);
    pros::delay(100);
    turnRightPIDTarget = 20;
    turnRightPIDRunning = true;
    pros::delay(1000);
    turnRightPIDRunning = false;
    rightTrackingWheel.reset();
    drivePIDTarget = 15;
    driveIsRunning = true;
    pros::delay(2000);
    driveIsRunning = false;
    turnRightPIDTarget = 110;
    turnRightPIDRunning = true;
    pros::delay(2000);
    turnRightPIDRunning = false;
    frontClawActivate(false);
    maxCurrent(4000);
    rightTrackingWheel.reset();
    drivePIDTarget = 53;
    driveIsRunning = true;
    pros::delay(3000);
    driveIsRunning = false;
    frontClawActivate(true);
    pros::delay(500);
    turnRightPIDTarget = 120;
    turnRightPIDRunning = true;
    pros::delay(1000);
    turnRightPIDRunning = false;
    bigLift.moveRelative(550, 100);
    pros::delay(2000);
    maxCurrent(6000);
    rightTrackingWheel.reset();
    drivePIDTarget = 25;
    driveIsRunning = true;
    pros::delay(3000);
    driveIsRunning = false;
    bigLift.moveRelative(-150,100);
    pros::delay(500);

    /*turnLeftPIDTarget = 90;
    turnLeftPIDRunning = true;
    pros::delay(500);
    turnLeftPIDRunning = false;*/
    frontClawActivate(false);
    pros::delay(500);
    rightTrackingWheel.reset();
    drivePIDTarget = -30;
    driveIsRunning = true;
    pros::delay(1000);
    driveIsRunning = false;
    turnRightPIDTarget = 225;
    turnRightPIDRunning = true;
    pros::delay(1000);
    turnRightPIDRunning = false;
    conveyorRunning = true;
    bigLift.moveRelative(-425, 100);
    pros::delay(1000);
    rightTrackingWheel.reset();
    maxCurrent(2000);
    drivePIDTarget = 30;
    driveIsRunning = true;
    pros::delay(4000);
    driveIsRunning = false;
    frontClawActivate(true);
    pros::delay(500);
    turnRightPIDTarget = 45;
    turnRightPIDRunning = true;
    pros::delay(1000);
    turnRightPIDRunning = false;
    rightTrackingWheel.reset();
    drivePIDTarget = 30;
    driveIsRunning = true;
    pros::delay(1000);
    driveIsRunning = false;
    bigLift.moveRelative(450, 100);
    pros::delay(5000);
    turnRightPIDTarget = 120;
    turnRightPIDRunning = true;
    pros::delay(1000);
    turnRightPIDRunning = false;
    drivePIDTarget = 25;
    driveIsRunning = true;
    pros::delay(1000);
    driveIsRunning = false;
    bigLift.moveRelative(-200, 100);
    pros::delay(1000);
    frontClawActivate(false);
    drivePIDTarget = -10;
    driveIsRunning = true;
    pros::delay(1000);
    driveIsRunning = false;
    bigLift.moveRelative(200, 100);
    drivePIDTarget = -20;
    driveIsRunning = true;
    pros::delay(1000);
    driveIsRunning = false;
    bigLift.moveRelative(-650, 100);
    pros::delay(2000);
    turnRightPIDTarget = 300;
    turnRightPIDRunning = true;
    pros::delay(1000);
    turnRightPIDRunning = false;
    backTilterActivate(false);
    pros::delay(500);
    drivePIDTarget = 5;
    driveIsRunning = true;
    pros::delay(1000);
    driveIsRunning = false;
    turnRightPIDTarget = 120;
    turnRightPIDRunning = true;
    pros::delay(1000);
    turnRightPIDRunning = false;
    drivePIDTarget = 10;
    driveIsRunning = true;
    pros::delay(1000);
    driveIsRunning = false;
    frontClawActivate(true);
    bigLift.moveRelative(450, 100);
    drivePIDTarget = 15;
    driveIsRunning = true;
    pros::delay(1000);
    driveIsRunning = false;
    bigLift.moveRelative(-150, 100);
    drivePIDTarget = -10;
    driveIsRunning = true;
    pros::delay(1000);
    driveIsRunning = false;
    bigLift.moveRelative(400, 100);
    drivePIDTarget = -90;
    driveIsRunning = true;
    pros::delay(5000);
    driveIsRunning = false;



    /*maxCurrent(4000);
    rightTrackingWheel.reset();
    drivePIDTarget = 33;
    driveIsRunning = true;
    pros::delay(2000);
    driveIsRunning = false;
    frontClawActivate(true);
    pros::delay(500);
    bigLift.moveRelative(450, 100);
    pros::delay(1000);
    maxCurrent(6000);
    rightTrackingWheel.reset();
    drivePIDTarget = 34;
    driveIsRunning = true;
    pros::delay(2000);
    driveIsRunning = false;
    bigLift.moveRelative(-50, 100);
    frontClawActivate(false);
    pros::delay(500);
    rightTrackingWheel.reset();
    drivePIDTarget = -15;
    driveIsRunning = true;
    pros::delay(1000);
    driveIsRunning = false;
    turnRightPIDTarget = 180;
    turnRightPIDRunning = true;
    pros::delay(1000);
    turnRightPIDRunning = false;
    bigLift.moveRelative(-450, 100);
    pros::delay(1000);
    rightTrackingWheel.reset();
    drivePIDTarget = 25;
    driveIsRunning = true;
    pros::delay(2000);
    driveIsRunning = false;
    frontClawActivate(true);
    pros::delay(500);
    bigLift.moveRelative(450, 100);
    turnRightPIDTarget = 65;
    turnRightPIDRunning = true;
    pros::delay(3000);
    turnRightPIDRunning = false;
    rightTrackingWheel.reset();
    drivePIDTarget = 70;
    driveIsRunning = true;
    pros::delay(1000);
    driveIsRunning = false;
    bigLift.moveRelative(-50, 100);
    frontClawActivate(false);
    pros::delay(500);
    rightTrackingWheel.reset();
    drivePIDTarget = -30;
    driveIsRunning = true;
    pros::delay(1000);
    driveIsRunning = false;
    bigLift.moveRelative(-450, 100);
    turnRightPIDTarget = 245;
    turnRightPIDRunning = true;
    pros::delay(1000);
    turnRightPIDRunning = false;
    backTilterActivate(false);
    pros::delay(500);
    rightTrackingWheel.reset();
    drivePIDTarget = -10;
    driveIsRunning = true;
    pros::delay(1000);
    driveIsRunning = false;
    turnRightPIDTarget = 65;
    turnRightPIDRunning = true;
    pros::delay(1000);
    turnRightPIDRunning = false;
    rightTrackingWheel.reset();
    drivePIDTarget = 15;
    driveIsRunning = true;
    pros::delay(1000);
    driveIsRunning = false;
    frontClawActivate(true);
    bigLift.moveRelative(450, 100);
    rightTrackingWheel.reset();
    drivePIDTarget = 27.5;
    driveIsRunning = true;
    pros::delay(2000);
    driveIsRunning = false;
    bigLift.moveRelative(-50, 100);
    frontClawActivate(false);
    rightTrackingWheel.reset();
    drivePIDTarget = -20;
    driveIsRunning = true;
    pros::delay(1000);
    driveIsRunning = false;
    turnRightPIDTarget = 315;
    turnRightPIDRunning = true;
    pros::delay(2000);
    turnRightPIDRunning = false;
    rightTrackingWheel.reset();
    drivePIDTarget = 90;
    driveIsRunning = true;
    pros::delay(1000);
    driveIsRunning = false;
/*liftBottom = true;
backTilterActivate(false);
drive->setMaxVelocity(200);
drive->moveDistance(-10_in);
pros::delay(2000);
backTilterActivate(true);
pros::delay(100);
drive->setMaxVelocity(600);
turnRightPIDTarget = 20;
turnRightPIDRunning = true;
pros::delay(1000);
turnRightPIDRunning = false;
drive->moveDistance(15_in);
pros::delay(1000);
turnRightPIDTarget = 110;
turnRightPIDRunning = true;
pros::delay(2000);
turnRightPIDRunning = false;
drive->moveDistance(80_in);
pros::delay(4500);
turnRightPIDTarget = 180;
turnRightPIDRunning = true;
pros::delay(1000);
turnRightPIDRunning = false;
bigLift.moveRelative(400.0, 100);
pros::delay(500);
conveyorRunning = true;
drive->setMaxVelocity(100);
drive->moveDistance(60_in);
pros::delay(4000);
backTilterActivate(false);
drive->setMaxVelocity(600);
turnRightPIDTarget = 270;
turnRightPIDRunning = true;
pros::delay(1000);
turnRightPIDRunning = false;
conveyorRunning = false;
bigLift.moveRelative(-400.0, 100);
pros::delay(1000);
drive->moveDistance(55_in);
pros::delay(3000);
turnRightPIDTarget = 0;
turnRightPIDRunning = true;
pros::delay(1000);
turnRightPIDRunning = false;
drive->moveDistance(-10_in);
pros::delay(1000);
rightChassis.moveVoltage(12000);
leftChassis.moveVoltage(12000);
pros::delay(1000);
rightChassis.moveVoltage(0);
leftChassis.moveVoltage(0);
backTilterActivate(true);
pros::delay(500);
turnRightPIDTarget = 0;
turnRightPIDRunning = true;
pros::delay(1000);
turnRightPIDRunning = false;
drive->moveDistance(7.5_in);
pros::delay(1000);
turnRightPIDTarget = 90;
turnRightPIDRunning = true;
pros::delay(1000);
turnRightPIDRunning = false;
bigLift.moveRelative(400.0 ,100);
conveyorRunning = true;
drive->moveDistance(80_in);
pros::delay(4000);
conveyorRunning = false;
rightChassis.moveVoltage(12000);
leftChassis.moveVoltage(12000);
pros::delay(1000);
rightChassis.moveVoltage(0);
leftChassis.moveVoltage(0);
turnRightPIDTarget = 0;
turnRightPIDRunning = true;
pros::delay(1000);
turnRightPIDRunning = false;
backTilterActivate(false);
frontClawActivate(false);
drive->setMaxVelocity(100);
drive->moveDistance(15_in);
pros::delay(1000);
frontClawActivate(true);
pros::delay(250);
bigLift.moveRelative(400.0, 100);
pros::delay(1000);
turnRightPIDTarget = 90;
turnRightPIDRunning = true;
pros::delay(1000);
turnRightPIDRunning = false;
drive->moveDistance(-15_in);
pros::delay(1000);
turnRightPIDTarget = 180;
turnRightPIDRunning = true;
pros::delay(1000);
turnRightPIDRunning = false;
drive->moveDistance(110_in);
pros::delay(4000);
leftChassis.moveVoltage(12000);
rightChassis.moveVoltage(12000);
pros::delay(1000);
leftChassis.moveVoltage(0);
rightChassis.moveVoltage(0);
backTilterActivate(true);
pros::delay(500);
turnRightPIDTarget = 180;
turnRightPIDRunning = true;
pros::delay(1000);
turnRightPIDRunning = false;
drive->moveDistance(7.5_in);
turnRightPIDTarget = 270;
turnRightPIDRunning = true;
pros::delay(1000);
turnRightPIDRunning = false;
conveyorRunning = true;
drive->moveDistance(80_in);
pros::delay(4000);
conveyorRunning = false;
turnRightPIDTarget = 180;
turnRightPIDRunning = true;
pros::delay(2000);
turnRightPIDRunning = false;
drive->moveDistance(10_in);
pros::delay(500);
bigLift.moveRelative(-500.0, 100);
pros::delay(1000);
drive->moveDistance(15_in);
pros::delay(1000);
elevateIsRunning = true;
pros::delay(10000);
elevateIsRunning = false;*/
}