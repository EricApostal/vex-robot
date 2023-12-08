#include "main.h"
#include "robot/robot.hpp"
#include "lib/scheduler.hpp"
#include "lib/tasks.hpp"

using namespace pros;

Scheduler scheduler;
Robot bot = Robot();

void initialize() {
	bot.taskName = "robot";
	scheduler.addTask(&bot);
	scheduler.startScheduler();

	pros::lcd::initialize();
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
	pros::delay(1000);
	bot.runAuton();
}

// Driver control start (always called when not connected to field controller)
void opcontrol() {

}