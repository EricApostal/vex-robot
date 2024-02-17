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

    // lemlib::Pose oldPose = chassis.getPose();

    slapper.move(127);
    pros::delay(1000); // 30000
    slapper.move(0);

    // I think the slapper messes with the inertial sensor, so we want to ignore anything while it's moving
    // pros::delay(3000);
    // chassis.setPose(oldPose);
    chassis.waitUntilDone();

    // go to other side of field
    chassis.turnTo(-36, -57, 500, true, baseSpeed);
    chassis.moveToPoint(-36, -57, 10000, true, baseSpeed);

}