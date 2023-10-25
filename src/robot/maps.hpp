#pragma once
#include "main.h"

// Drive Motors
pros::Motor left1 = pros::Motor(-10);
pros::Motor left2 = pros::Motor(-9);
pros::Motor left3 = pros::Motor(-7);

pros::Motor right1 = pros::Motor(1);
pros::Motor right2 = pros::Motor(12);
pros::Motor right3 = pros::Motor(13);

pros::ADIDigitalOut left_bumper(1);
pros::ADIDigitalOut right_bumper(2);

pros::Motor intake(8, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor arm(2, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_DEGREES);

pros::Controller controller (pros::E_CONTROLLER_MASTER);