#pragma once
#include "main.h"
#include "../../lib/tasks.hpp"
#include "../../lib/motors_mapped.hpp"
#include "../../lib/maps.hpp"
#include "lemlib/api.hpp"
#include "../chassis.hpp"

// https://path.jerryio.com/

void skills_auton()
{  
    left_side_motors.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
	right_side_motors.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
    chassis.setPose(-40, -53, 90);
    chassis.moveToPoint(-52, -52, 10000, false, 70);
    chassis.turnTo(46, 0, 1000);
    chassis.moveToPoint(-54, -54, 10000, false, 70);
    chassis.waitUntilDone();
    slapper.move(127);
    pros::delay(1000);
    slapper.move(0);

    // to to other side of field
    chassis.turnTo(-36, -57, 10000, true, 50);
    // chassis.moveToPoint(-36, -57, 10000, true, 70);
    // chassis.waitUntilDone();
    // chassis.moveToPoint(36, -57, 10000, true, 70);
    // chassis.waitUntilDone();


    // // push into right side goal
    // chassis.moveToPoint(54, -29, 10000, true, 70);
    // chassis.moveToPoint(42, -42, 10000, true, 70);

    // // start moving to front
    // chassis.moveToPoint(9, -26, 10000, true, 70);

    // // push to front right
    // motors::system::move_bumpers(true);
    // chassis.moveToPoint(43, -10, 10000, true, 70);
    // pros::delay(300);
    // motors::system::move_bumpers(true);

    // // recenter
    // chassis.moveToPoint(11, 0, 10000, true, 70);

    // // push into center
    // motors::system::move_bumpers(true);
    // chassis.moveToPoint(48, 0, 10000, true, 70);
    // pros::delay(300);
    // motors::system::move_bumpers(false);
}