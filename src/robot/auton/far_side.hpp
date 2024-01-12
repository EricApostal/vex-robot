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
    left_side_motors.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
	right_side_motors.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
    chassis.setPose(0, -60, 0);
    // chassis.moveToPose(0, 0, 0, 10000);
    // chassis.moveToPoint(0, 0, 20000);
    chassis.turnTo(60,0, 10000, true, 50);
}