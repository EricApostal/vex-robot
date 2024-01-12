#include "main.h"
#include "robot/robot.hpp"
#include "lib/scheduler.hpp"
#include "lib/tasks.hpp"
#include "robot/auton/close_side.hpp"
#include "robot/auton/skills.hpp"
#include "robot/chassis.hpp"

using namespace pros;

Scheduler scheduler;
Robot bot = Robot();

void initialize() {
	left_side_motors.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
	right_side_motors.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
	
	pros::lcd::initialize();
	pros::Task initLem([&]() {
		init_chassis();
	});
}

void disabled() {}

void competition_initialize() {}

void autonomous() {

	doAuton();
}

// Driver control start (always called when not connected to field controller)
void opcontrol() {
	pros::delay(3000);
	// doAuton();
	bot.taskName = "robot";
	scheduler.addTask(&bot);
	scheduler.startScheduler();
}