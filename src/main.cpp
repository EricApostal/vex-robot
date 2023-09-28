#include "main.h"
#include "robot/robot.hpp"
#include "robot/scheduler.hpp"
#include "okapi/api.hpp"
#include "robot/tasks.hpp"

using namespace pros;

okapi::Controller controller;
Scheduler scheduler;
Robot bot(controller);

void initialize() {
	pros::lcd::initialize();
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
}

// When we start using the controller (always called when not connected to field controller)
void opcontrol() {
	bot.taskName = "robot";
	scheduler.addTask(&bot);
	scheduler.startScheduler();
}