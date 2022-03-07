#include "main.h"

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}
/*bool intakeToggle = false;
void toggleIntakeFn() {
    while(pros::Task::notify_take(true, TIMEOUT_MAX)) {
        intakeToggle =!intakeToggle;
        pros::delay(20);
    }
}*/

/*void odomTask(){
	while(1){
		printf("hi");
		positionTracking();
	}
}*/
/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	Logger::setDefaultLogger(
    std::make_shared<Logger>(
        TimeUtilFactory::createDefault().getTimer(), // It needs a Timer
        "/ser/sout", // Output to the PROS terminal
        Logger::LogLevel::info // Show errors and warnings
    )
);
	initializeSystems();
	leftTrackingWheel.reset();
	rightTrackingWheel.reset();
	drive->setState({0_in, 0_in, 0_deg});
	inertial.reset();
	bigLift.tarePosition();
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
	autonSelectScreen();
}


/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	//pros::Task odom(odomTask);
	pros::Task pidTurnRight(turnRightDegreesPID);
	pros::Task pidTurnLeft(turnLeftDegreesPID);
	pros::Task conveyorMove(runConveyor);
	pros::Task liftMove(moveFrontLift);
	pros::Task elevating(elevate);
	pros::Task moving(move);
	bigLift.setBrakeMode(AbstractMotor::brakeMode::hold);
	if(!autonRan){
		switch(autonNumSelect){
			case 0:
			{
				autonRan = true;
				rightAuton();
				break;
			}
			case 1:
				autonRan = true;
				leftAuton();
				break;
			case 2:
				autonRan = true;
				halfWinPointRightAuton();
				break;
			case 3:
				autonRan = true;
				halfWinPointLeftAuton();
				break;
			case 4: 
				autonRan = true;
				middle();
				break;
			case 5:
				autonRan = true;
				winPointLeft();
				break;
			case 6:
				autonRan = true;
				skills();
				break;
		}
	}
		/*printf("start\n");
        printf("%.4lf\n", currentOrientation);
        printf("%.4lf\n", deltaPosition);
        printf("%4lf\n", position[0]);
        printf("%4lf\n", position[1]);*/
		//rightAuton();
	printf("auton end\n");
	printf("%d\n", autonRan);
	//odom.remove();
	return;
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	//drive->setState({0_in, 0_in, 0_deg});
	bool conveyorOnState = false;
	bool conveyorIsOn = false;
	int conveyorIsForward = 1;
	bool tilterActive = true;
	bool tilterState = false;
	bool frontClawActive = true;
	bool frontClawState = false;
	turnRightEnd = true;
	turnLeftEnd = true;
	conveyorEnd = true;
	liftEnd = true;
	elevateEnd = true;
	driveEnd = true;
	//pros::Task intakeTask(toggleIntakeFn);
	while(true){
		drive->getModel()->tank(mainCtrl.getAnalog(ControllerAnalog::leftY), mainCtrl.getAnalog(ControllerAnalog::rightY));
		if(bigLiftUpButton.isPressed()){
			bigLift.moveVelocity(100);
		} else if (bigLiftDownButton.isPressed()){
			bigLift.moveVelocity(-100);
		} else {
			bigLift.moveVelocity(0);
			
			bigLift.setBrakeMode(AbstractMotor::brakeMode::hold);
		} 
		if(conveyorOnButton.isPressed() && !conveyorOnState){
			conveyorIsOn = !conveyorIsOn;
		}
		if(conveyorForwardToggle.isPressed()){
			conveyor.moveVelocity(-450);
		} else if (conveyorIsOn){
			conveyor.moveVelocity(450);
		} else {
			conveyor.moveVelocity(0);
		}
		/*if(conveyorOnButton.isPressed()) {
			intakeTask.notify();
		}
			if(conveyorForwardToggle.isPressed()){
				conveyor.moveVelocity(-600);
			} else if(intakeToggle && !conveyorOnState) {
				conveyor.moveVelocity(600);
			} else {
				conveyor.moveVelocity(0);
			}*/
		/*if(conveyorOnButton.isPressed() && !conveyorOnState){
			if(conveyorIsOn){
				conveyor.moveVelocity(0);
				conveyorIsOn = false;
			} else{
				conveyor.moveVelocity(600);
				conveyorIsOn = true;
			}
		}
		else if (conveyorForwardToggle.isPressed()){
			conveyor.moveVelocity(600);
		} else if (conveyorIsOn == false){
			conveyor.moveVelocity(0);
		}*/
		if(tilterButton.isPressed() && !tilterState){
			backClaw1.set_value(!tilterActive);
			backClaw2.set_value(!tilterActive);
			tilterActive = !tilterActive;
		}
		if(frontClawButton.isPressed() && !frontClawState){
			frontClaw1.set_value(!frontClawActive);
			frontClaw2.set_value(!frontClawActive);
			frontClawActive = !frontClawActive;
		}
		conveyorOnState = conveyorOnButton.isPressed();
		tilterState = tilterButton.isPressed();
		frontClawState = frontClawButton.isPressed();
		pros::delay(20);
	}
}