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
    chassis.moveToPoint(-52, -52, 10000, false, 70);
    chassis.turnTo(46, 0, 1000);
    chassis.moveToPoint(-54, -54, 10000, false, 70);
    chassis.waitUntilDone();
    // slapper.move(127);
    pros::delay(1000);
    /// slapper.move(0);

    // go to other side of field
    chassis.turnTo(-36, -57, 10000, true, 50);
    chassis.moveToPoint(-36, -57, 10000, true, 127);
    chassis.moveToPoint(36, -57, 10000, true, 80);

    // push into right side goal
    // chassis.moveToPoint(47, -47, 10000, true, 70);
    chassis.moveToPoint(61, -34, 2000, true, 70);
    chassis.moveToPoint(66, -25, 100, true, 70);

    // return;

    // back up from right
    chassis.turnTo(47, -47, 10000, false, 50);
    chassis.moveToPoint(47, -47, 10000, false, 127);
    chassis.turnTo(9, -26, 10000, true, 50);

    // line up front push
    chassis.moveToPoint(15, -26, 10000, true, 127);
    chassis.waitUntilDone();
    // look at goal
    // chassis.turnTo(43, -5, 10000, true, 127);

    // push to front right
    motors::system::move_bumpers(true);
    chassis.moveToPoint(43, -5, 1000, true, 70);

    // go back and push a few more times
    chassis.moveToPoint(24, -3, 1000, false, 70);
    chassis.moveToPoint(43, 0, 1000, true, 70);

    return;

    // realign
    chassis.moveToPoint(15, 0, 1000, true, 70);
    chassis.turnTo(15, 24, 2000, true, 50);
    chassis.moveToPoint(15, 24, 2000, true, 50);
    chassis.moveToPoint(31, 12, 2000, true, 127);

    // push into left
    chassis.waitUntilDone();
    motors::system::move_bumpers(true);
    chassis.moveToPoint(43, 12, 2000, true, 50);
    chassis.waitUntilDone();
    pros::delay(300);
    motors::system::move_bumpers(false);

    // recenter
    chassis.moveToPoint(11, 0, 10000, false, 70);

    // go to left

    // push into center
    motors::system::move_bumpers(true);
    chassis.moveToPoint(48, 0, 10000, true, 70);
    pros::delay(300);
    motors::system::move_bumpers(false);
}