#include "main.h"
#include "robot/robot.hpp"
#include "auton.hpp"

using namespace pros;

void onStart() {

	};

void initialize() {
	pros::lcd::initialize();
	Robot bot = Robot();

	// claw_hinge.set_brake_mode(MOTOR_BRAKE_HOLD);
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
}

void driver_control() {
	while (true) {
		// tick();
		delay(10);
	}
}

void opcontrol() {
	driver_control();
}
