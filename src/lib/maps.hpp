#pragma once
#include "main.h"

pros::MotorGroup left_side_motors({11, 12, 13});
pros::MotorGroup right_side_motors({18, 19, 20});

pros::Motor left1(11, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor left2(12, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor left3(13, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES);

pros::Motor right1(18, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor right2(19, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor right3(20, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);

pros::ADIDigitalOut left_bumper(1);
pros::ADIDigitalOut right_bumper(2);

pros::Motor slapper (5, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_DEGREES);

pros::Motor intake(10, pros::E_MOTOR_GEARSET_INVALID, false, pros::E_MOTOR_ENCODER_DEGREES);

pros::Imu inertial_sensor(19);

pros::Controller controller (pros::E_CONTROLLER_MASTER);