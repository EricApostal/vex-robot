#include "main.h"

using namespace pros;

// so this file doesn't get called multiple times upon including
#ifndef DEFINES_HPP
#define DEFINES_HPP

// drivetrain
Motor left_1(1, E_MOTOR_GEARSET_06, 0, E_MOTOR_ENCODER_DEGREES);
Motor left_2(2, E_MOTOR_GEARSET_06, 0, E_MOTOR_ENCODER_DEGREES);

Motor right_1(10, E_MOTOR_GEARSET_06, 0, E_MOTOR_ENCODER_DEGREES);
Motor right_2(9, E_MOTOR_GEARSET_06, 0, E_MOTOR_ENCODER_DEGREES);

// pistons
pros::ADIDigitalOut climb_hinge(1);
pros::ADIDigitalOut pto(2);
pros::ADIDigitalOut leveler(3);

// mechs
Motor intake_left(14, E_MOTOR_GEARSET_INVALID, 0, E_MOTOR_ENCODER_DEGREES);
Motor intake_right(15, E_MOTOR_GEARSET_INVALID, 0, E_MOTOR_ENCODER_DEGREES);

Controller controller (E_CONTROLLER_MASTER);

#endif

