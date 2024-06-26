#pragma once
#include "main.h"

pros::Motor left1(11, pros::E_MOTOR_GEARSET_06, true);
pros::Motor left2(12, pros::E_MOTOR_GEARSET_06, true);
pros::Motor left3(13, pros::E_MOTOR_GEARSET_06, true);

pros::Motor right1(18, pros::E_MOTOR_GEARSET_06, false);
pros::Motor right2(19, pros::E_MOTOR_GEARSET_06, false);
pros::Motor right3(20, pros::E_MOTOR_GEARSET_06, false);

pros::MotorGroup left_side_motors({left1, left2, left3});
pros::MotorGroup right_side_motors({right1, right2, right3});

pros::ADIDigitalOut left_bumper(1);
pros::ADIDigitalOut right_bumper(2);

pros::ADIDigitalOut eric_dooley_last_minute_hang(3);

pros::Motor slapper (14, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor intake(10, pros::E_MOTOR_GEARSET_INVALID, true, pros::E_MOTOR_ENCODER_DEGREES);

pros::Imu inertial_sensor(16);

pros::Rotation horizontal_tracking(1, true);
pros::Rotation vertical_tracking(2, true);

pros::Controller controller (pros::E_CONTROLLER_MASTER);