#pragma once
#include "main.h"

pros::ADIDigitalOut left_bumper(1);
pros::ADIDigitalOut right_bumper(2);

pros::Motor intake(8, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor arm(2, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_DEGREES);