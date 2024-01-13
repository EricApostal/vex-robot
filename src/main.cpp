#include "main.h"
#include "robot/robot.hpp"
#include "lib/scheduler.hpp"
#include "lib/tasks.hpp"
#include "robot/auton/front.hpp"
#include "robot/auton/skills.hpp"
#include "robot/chassis.hpp"
// #include "autoSelect/selection.h"

using namespace pros;

Scheduler scheduler;
Robot bot = Robot();

void initialize() {
	left_side_motors.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
	right_side_motors.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
	// selector::init();

	pros::Task initLem([&]() {
		init_chassis();
	});
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
	// auto current_selector = selector::auton;
	// if (current_selector == 1 | current_selector == 2) {
	// 	skills_auton();
	// }
	skills_auton();
}

// Driver control start (always called when not connected to field controller)
void opcontrol() {
	bot.taskName = "robot";
	scheduler.addTask(&bot);
	scheduler.startScheduler();
}