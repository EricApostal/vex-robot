#include "main.h"
#include "robot/robot.hpp"
#include "auton.hpp"
#include "robot/scheduler.hpp"
#include "okapi/api.hpp"
#include "robot/tasks.hpp"

using namespace pros;

okapi::Controller controller;
Scheduler scheduler;
Robot bot(controller);	

void initialize() {
	// pros::lcd::initialize();
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
}

void driver_control() {
	bot.taskName = "robot";
	scheduler.addTask(&bot);
	scheduler.startScheduler();
}

void opcontrol() {
	screen::print(TEXT_SMALL, 3,"asdasdas");
	driver_control();
}
