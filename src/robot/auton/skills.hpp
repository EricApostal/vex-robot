#pragma once
#include "main.h"
#include "../../lib/tasks.hpp"
#include "../../lib/motors_mapped.hpp"
#include "lemlib/api.hpp"
#include "../chassis.hpp"

/*
    Auton testing, useless otherwise. Should be added to scheduler.
*/

void doSkills()
{
    chassis.setPose(-41, -62, 0);
    arm.move_relative(-850, 127);
    chassis.moveToPose(-46.5, -46.5, 0, 10000, false, 0, 0, 50, false);
    pros::delay(1000);
    // chassis.turnTo(47, 0, 10000, true, 50, false);
    chassis.moveToPose(-65, -65, 0, 10000, true, 0, 0.6, 50, false);
    pros::delay(10000);
}