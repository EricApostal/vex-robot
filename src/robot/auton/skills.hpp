#pragma once
#include "main.h"
#include "../../lib/tasks.hpp"
#include "../../lib/motors_mapped.hpp"
#include "../../lib/maps.hpp"
#include "lemlib/api.hpp"
#include "../chassis.hpp"

// https://path.jerryio.com/

int baseSpeed = 80;

void skills_auton()
{  
    left_side_motors.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
	right_side_motors.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
    chassis.moveToPoint(-51, -53, 2000, false, 40, false);
    chassis.turnTo(55, 0, 1000, true);

    chassis.waitUntilDone();

    slapper.move(127);
    pros::delay(1000); // 30000
    slapper.move(0);

    chassis.waitUntilDone();

    // go to other side of field
    chassis.turnTo(-22, -58, 500, true, baseSpeed);
    chassis.moveToPoint(-22, -55, 300, true, baseSpeed);
    chassis.turnTo(38, -55, 300, true, baseSpeed);
    chassis.moveToPoint(38, -55, 10000, true, baseSpeed);

    // start right push
    chassis.turnTo(58, -36, 500, true, baseSpeed);
    chassis.moveToPoint(58, -36, 1000, true, baseSpeed);
    // chassis.moveToPoint(10, -43, 1000, false, baseSpeed);

    // // start mid right
    // motors::system::move_bumpers(true);
    // chassis.turnTo(44, -15, 500, true, baseSpeed);
    // chassis.moveToPoint(44, -15, 1000, true, baseSpeed);
    // chassis.moveToPoint(34, -15, 1000, false, baseSpeed);
    // chassis.moveToPoint(44, -15, 1000, true, baseSpeed);
    // motors::system::move_bumpers(false);
    // chassis.moveToPoint(13, -15, 500, false, baseSpeed);

    // // mid 
    // chassis.turnTo(40, 0, 500, true, baseSpeed);
    // motors::system::move_bumpers(true);
    // chassis.moveToPoint(40, 0, 500, true, baseSpeed);
    // chassis.moveToPoint(30, 0, 500, false, baseSpeed);
    // chassis.moveToPoint(40, 0, 1000, true, baseSpeed);
    // motors::system::move_bumpers(true);
    // chassis.moveToPoint(30, 0, 500, false, baseSpeed);

    // // mid left 
    // motors::system::move_bumpers(true);
    // chassis.turnTo(45, 10, 500, true, baseSpeed);
    // chassis.moveToPoint(45, 10, 1000, true, baseSpeed);
    // chassis.moveToPoint(35, 10, 1000, false, baseSpeed);
    // motors::system::move_bumpers(true);
    // chassis.moveToPoint(45, 10, 500, true, baseSpeed);

}