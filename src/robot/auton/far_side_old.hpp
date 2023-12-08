#pragma once
#include "main.h"
#include "../../lib/tasks.hpp"
#include "../../lib/motors_mapped.hpp"
#include "lemlib/api.hpp"
#include "../chassis.hpp"

/*
    Auton testing, useless otherwise. Should be added to scheduler.
*/

void calibrate() {}

void doAuton()
{
    chassis.setPose(-45, -63, 0);
    arm.move_relative(-400, 70);
    motors::system::move_flywheel(127);
    motors::system::move_intake(127);
    chassis.moveToPose(-28, -5, 0, 10000, true, 0, 0.1, 100);
    pros::delay(250);
    chassis.turnTo(50, 10, 10000);
    pros::delay(500);
    motors::system::move_intake(0);
    arm.move_absolute(0, 706);
    pros::delay(1000);
    motors::system::move_flywheel(-127);
    arm.move_absolute(-1650, 700);
    pros::delay(1000);
    motors::system::move_intake(0);
    motors::system::move_flywheel(0);
    chassis.moveToPose(-52, -45, 0, 2250, false, 0, 0, 75);
    pros::delay(1000);
    chassis.turnTo(60, -60, 500);
    pros::delay(300);
    chassis.turnTo(24, 24, 500);
    pros::delay(300);
    chassis.turnTo(60, -60, 500);
    pros::delay(300);
    chassis.turnTo(24, 24, 500);
    pros::delay(300);
    arm.move_absolute(-950, 200);
    pros::delay(500);
    chassis.turnTo(-60, -60, 10000);
    pros::delay(500);
    chassis.moveToPose(5, -62, 270, 10000, false, 0, 0.1, 75);
    pros::delay(1000);
    // chassis.turnTo(-60, -40, 10000);
    // pros::delay(1000);
    // chassis.moveTo(-1, -60, 0, 10000, false, 0, 0.1, 75);
    pros::delay(10000);

    // arm.move_absolute(-500, 70);
    // chassis.setPose(-55, -53, 45, 0);
    // pros::delay(1000);
    // motors::system::move_flywheel(0);
    // chassis.moveTo(7, -62, 90, 10000);

//Just stopping the thing cuz I don't like loud noise + battery drain.
//     pros::delay(500);
//     motors::system::move_intake(0);
//     motors::system::move_flywheel(0);
//     pros::delay(10000);
}