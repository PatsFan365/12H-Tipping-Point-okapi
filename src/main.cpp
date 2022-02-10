#include "deviceDefinitions.h"

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

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	initializeSystems();
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
	while(!autonRan){
		switch(autonNumSelect){
			case 0:
				autonRan = true;
				rightAuton();
				break;
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
				winPointRight();
				break;
			case 5:
				autonRan = true;
				winPointLeft();
				break;
			case 6:
				autonRan = true;
				skills();
				return;
		}
	}
	exit(0);
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
	while(true){
		drive->getModel()->tank(mainCtrl.getAnalog(ControllerAnalog::leftY), mainCtrl.getAnalog(ControllerAnalog::rightY));
		if(bigLiftUpButton.isPressed()){
			bigLiftA.moveVelocity(100);
		} else if (bigLiftDownButton.isPressed()){
			bigLiftA.moveVelocity(-100);
		} else {
			bigLiftA.moveVelocity(0);
			bigLiftA.setBrakeMode(AbstractMotor::brakeMode::hold);
		} 
		/*if(conveyorUpButton.isPressed()){
			conveyor.moveVelocity(100);
		}
		if(conveyorDownButton.isPressed()){
			conveyor.moveVelocity(-100);
		}*/
		/*if(tilterDownButton.isPressed()){
			tilter.set_value(true);
		}
		if(tilterUpButton.isPressed()){
			tilter.set_value(false);
		}*/
		pros::delay(15);
	}
}
