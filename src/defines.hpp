#include "main.h"

using namespace pros;

#ifndef DEFINES_HPP
#define DEFINES_HPP

// your variable definitions go here
// drivetrain
Motor left_1(10, E_MOTOR_GEARSET_06, 0, E_MOTOR_ENCODER_DEGREES);
Motor left_2(9, E_MOTOR_GEARSET_06, 0, E_MOTOR_ENCODER_DEGREES);
Motor left_3(8, E_MOTOR_GEARSET_06, 0, E_MOTOR_ENCODER_DEGREES);

Motor right_1(7, E_MOTOR_GEARSET_06, 0, E_MOTOR_ENCODER_DEGREES);
Motor right_2(6, E_MOTOR_GEARSET_06, 0, E_MOTOR_ENCODER_DEGREES);
Motor right_3(5, E_MOTOR_GEARSET_06, 0, E_MOTOR_ENCODER_DEGREES);

Controller controller (E_CONTROLLER_MASTER);

// pros::ADIDigitalOut piston_index(1); // Replace 1 with the port number of your piston
// pros::ADIDigitalOut string_piston(2);
// pros::ADIDigitalOut string_piston2(3);

#endif // DEFINES_HPP

