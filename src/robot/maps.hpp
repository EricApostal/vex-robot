#pragma once
#include "main.h"

// Drive Motors
pros::Motor left1 = pros::Motor(-9);
pros::Motor left2 = pros::Motor(-7);

pros::Motor right1 = pros::Motor(16);
pros::Motor right2 = pros::Motor(17);

pros::ADIDigitalOut left_bumper(7);
pros::ADIDigitalOut right_bumper(8);

pros::ADIDigitalOut hang_lock(6);

pros::Motor flywheel_1(8, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor flywheel_2(-20, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);

pros::Motor arm(2, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_DEGREES);

pros::Motor intake_1(18, pros::E_MOTOR_GEARSET_INVALID, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor intake_2(-5, pros::E_MOTOR_GEARSET_INVALID, false, pros::E_MOTOR_ENCODER_DEGREES);

pros::Controller controller (pros::E_CONTROLLER_MASTER);