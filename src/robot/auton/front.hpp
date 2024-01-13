#pragma once
#include "main.h"
#include "../../lib/tasks.hpp"
#include "../../lib/motors_mapped.hpp"
#include "lemlib/api.hpp"
#include "../chassis.hpp"

/*
    Auton testing, useless otherwise. Should be added to scheduler.
*/

// https://path.jerryio.com/

void front_auton()
{  
    left_side_motors.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
	right_side_motors.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
    chassis.setPose(31, -59, 90);
    chassis.moveToPoint(56, -50, 1000, true, 70);
    chassis.waitUntilDone();
    motors::system::move_bumpers(true);
    pros::delay(500);
    // 60, -25
    motors::system::move_bumpers(false);
    chassis.moveToPoint(70, -22, 1000, true, 85);
    pros::delay(500);
    chassis.moveToPoint(47, -47, 1000, false, 50);
    pros::delay(500);
    motors::system::move_intake(127);
    chassis.moveToPoint(20, -18, 2000, 50);
    pros:delay(500);
    chassis.moveToPoint(4, 0, 1000);
    pros::delay(500);
    motors::system::move_bumpers(true);
    chassis.turnTo(40, 10, 1000);
    chassis.moveToPoint(60, 20, 1000, 60);
    pros::delay(500);
    motors::system::move_bumpers(false);
    motors::system::move_intake(-127);
    pros::delay(500);
    motors::system::move_intake(0);
    chassis.waitUntilDone();
}