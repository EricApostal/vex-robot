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
    pros::delay(30000); // 30000
    slapper.move(0);

    chassis.waitUntilDone();

    // go to other side of field
    chassis.turnTo(-22, -58, 500, true, baseSpeed);
    chassis.moveToPoint(-22, -55, 300, true, baseSpeed);
    chassis.turnTo(40, -55, 300, true, baseSpeed);
    chassis.moveToPoint(40, -55, 10000, true, baseSpeed);

    // align right push
    chassis.turnTo(65, -36, 500, true, baseSpeed);
    chassis.moveToPoint(65, -36, 1000, true, baseSpeed);

    // commence right push
    // chassis.turnTo(58, -17, 500, true, baseSpeed);
    // chassis.moveToPoint(58, -17, 500, true, baseSpeed);

    // back up
    chassis.turnTo(61, -45, 500, false, baseSpeed);
    chassis.moveToPoint(61, -45, 500, false, baseSpeed);

    // begin align front push
    chassis.turnTo(9, -33, 1000, false, baseSpeed);
    chassis.moveToPoint(9, -33, 1000, false, baseSpeed);
    chassis.waitUntilDone();

    motors::system::move_bumpers(true);
    chassis.turnTo(49, 0, 1000, true, baseSpeed);
    chassis.moveToPoint(49, 0, 1000, true, baseSpeed);

    // go back, push again
    chassis.waitUntilDone();
    motors::system::move_bumpers(false);

    chassis.turnTo(7, 12, 1000, false, baseSpeed);
    chassis.moveToPoint(7, 12, 1000, false, baseSpeed);

    chassis.waitUntilDone();
    motors::system::move_bumpers(true);
    chassis.moveToPoint(55, 8, 1000, true, baseSpeed);

    chassis.waitUntilDone();
    motors::system::move_bumpers(false);
    chassis.turnTo(8, -39, 1000, false, baseSpeed);
    chassis.moveToPoint(8, -39, 1000, false, baseSpeed);

    chassis.turnTo(47, 47, 10000, false, baseSpeed);
    chassis.moveToPoint(47, 47, 3000, false, baseSpeed);

}