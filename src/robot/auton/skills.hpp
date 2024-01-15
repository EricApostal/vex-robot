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
    chassis.moveToPoint(-52, -52, 10000, false, baseSpeed);
    chassis.turnTo(46, 0, 1000);
    chassis.moveToPoint(-54, -54, 10000, false, baseSpeed);
    chassis.waitUntilDone();

    lemlib::Pose oldPose = chassis.getPose();

    slapper.move(127);
    pros::delay(1000); // 30000

    slapper.move(0);

    // I think the slapper messes with the inertial sensor, so we want to ignore anything while it's moving
    pros::delay(3000);
    chassis.setPose(oldPose);
    chassis.waitUntilDone();

    // go to other side of field
    chassis.turnTo(-36, -57, 10000, true, 50);
    chassis.moveToPoint(-36, -57, 10000, true, 127);
    chassis.moveToPoint(36, -57, 10000, true, 80);

    // push into right side goal
    // chassis.moveToPoint(47, -47, 10000, true, 70);
    chassis.moveToPoint(66, -34, 500, true, baseSpeed);
    chassis.moveToPoint(66, -15, 500, true, 100);

    // push again
    chassis.moveToPoint(66, -34, 2000, false, baseSpeed);
    chassis.waitUntilDone();
    pros::delay(500);
    chassis.moveToPoint(66, -15, 200, true, 100);

    // back up from right
    chassis.turnTo(47, -47, 1000, false, 50);
    chassis.moveToPoint(47, -47, 10000, false, baseSpeed);
    chassis.turnTo(35, -34, 1000, true, baseSpeed);
    chassis.moveToPoint(35, -34, 10000, true, baseSpeed);
    chassis.turnTo(15, -26, 1000, true, 50);
    chassis.moveToPoint(15, -26, 10000, true, baseSpeed);

    // line up front push   
    chassis.moveToPoint(15, -26, 10000, true, baseSpeed);
    chassis.waitUntilDone();

    // push to front right
    motors::system::move_bumpers(true);
    chassis.moveToPoint(49, -2, 1500, true, baseSpeed);

    // go back and push a few more times
    chassis.moveToPoint(24, -2, 3000, false, baseSpeed);
    chassis.moveToPoint(49, -2, 1000, true, baseSpeed);

    chassis.waitUntilDone();
    motors::system::move_bumpers(false);

    // realign
    chassis.moveToPoint(4, -2, 10000, false, baseSpeed);

    chassis.turnTo(4, 20, 3000, true, 50);
    chassis.moveToPoint(4, 20, 3000, true, baseSpeed);

    // push into left
    chassis.waitUntilDone();
    motors::system::move_bumpers(true);
    chassis.moveToPoint(43, 15, 2000, true, baseSpeed);
    chassis.moveToPoint(24, 15, 3000, false, baseSpeed);
    chassis.moveToPoint(43, 15, 2000, true, baseSpeed);
    chassis.waitUntilDone();
    pros::delay(100);
    motors::system::move_bumpers(false);

    // go back to prepare for far left push
    chassis.moveToPoint(10, 34, 10000, false, baseSpeed);

    // // push into center
    // chassis.waitUntilDone();
    // motors::system::move_bumpers(true);
    // chassis.moveToPoint(48, 12, 10000, true, baseSpeed);
    // pros::delay(300);
    // chassis.waitUntilDone();
    // motors::system::move_bumpers(false);
    
    // return;
    // go to far left
    chassis.moveToPoint(46, 58, 2000, false, baseSpeed);
    chassis.turnTo(65, 35, 10000, true, baseSpeed);
    chassis.moveToPoint(65, 35, 10000, true, baseSpeed);
    chassis.turnTo(65, 24, 10000, true, baseSpeed);
    chassis.moveToPoint(65, 24, 10000, true, baseSpeed);
    // chassis.turnTo(68, 30, 10000, true, baseSpeed);
    // chassis.moveToPoint(68, 30, 10000, true, baseSpeed);

    // // push in
    // chassis.moveToPoint(58, 23, 1000, true, baseSpeed);
    // chassis.moveToPoint(61, 27, 1000, true, baseSpeed);

}