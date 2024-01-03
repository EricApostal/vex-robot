#include "main.h"
#include "robot/robot.hpp"
#include "lib/scheduler.hpp"
#include "lib/tasks.hpp"
#include "robot/auton/far_side.hpp"
#include "robot/auton/skills.hpp"
#include "robot/chassis.hpp"

using namespace pros;

Scheduler scheduler;
Robot bot = Robot();

void initialize() {
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
	// pros::delay(2500);
	// doSkills();
	bot.taskName = "robot";
	scheduler.addTask(&bot);
	scheduler.startScheduler();
}