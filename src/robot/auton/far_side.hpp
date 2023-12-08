#pragma once
#include "main.h"
#include "../../lib/tasks.hpp"
#include "../../lib/motors_mapped.hpp"
#include "lemlib/api.hpp"
#include "../chassis.hpp"

/*
    Auton testing, useless otherwise. Should be added to scheduler.
*/

void doAuton()
{
    chassis.setPose(-45, -63, 0);
    arm.move_relative(-1650, 127);
    pros::delay(500);
    // motors::system::move_intake(127);
    // arm.move_absolute(-600, 70);
    chassis.moveToPose(-60, -25, 0, 2000, true, 0, 0.1, 100, false);
    motors::system::move_intake(-127);
    pros::delay(500);
    motors::system::move_intake(0);
    chassis.moveToPose(-60, -50, 0, 2000, false, 0, 0.1, 100, false);
    chassis.turnTo(-5, 0, 10000, true, 100, false);
    arm.move_absolute(0, 127);
    pros::delay(500);
    chassis.moveToPose(-64, -26, 0, 2000, false, 0, 0.1, 100, false);
    pros::delay(10000);
}