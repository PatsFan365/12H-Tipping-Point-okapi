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
   drive->setMaxVelocity(400);
   drive->moveDistance(12_in);
   pros::delay(2000);
   drive->moveDistance(-20_in);
   pros::delay(5000);
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
   turnRightPIDTarget = 45;
   turnRightDegreesPID();
   pros::delay(10000);
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
}

void halfWinPointLeftAuton(){
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

}

void winPointRight(){

}

void skills(){

}