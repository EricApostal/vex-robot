#pragma once

#include "main.h"
#include "../maps.hpp"
#include "../motors_mapped.hpp"
#include "lemlib/api.hpp"

/*
    Auton testing, useless otherwise. Should be added to scheduler.
*/
void doAuton()
{
    pros::MotorGroup left_side_motors({-9, -7});
    pros::MotorGroup right_side_motors({12, 13});
    pros::Imu inertial_sensor(16);

    lemlib::Drivetrain drivetrain{
        &left_side_motors,  // left drivetrain motors
        &right_side_motors, // right drivetrain motors
        10.3,               // track width
        3.25,               // wheel diameter
        360,                // wheel rpm
        100                 // chase power
    };

    lemlib::TrackingWheel left_tracking_wheel(&left_side_motors, 3.25, 5.15, 360);
    lemlib::TrackingWheel right_tracking_wheel(&right_side_motors, 3.25, 5.15, 360);

    // odometry struct
    lemlib::OdomSensors sensors{
        // &left_tracking_wheel, // vertical tracking wheel 1
        // &right_tracking_wheel, // vertical tracking wheel 2
        // &back_tracking_wheel, // horizontal tracking wheel 1
        // nullptr, // we don't have a second tracking wheel, so we set it to nullptr
        // &inertial_sensor // inertial sensor

        &left_tracking_wheel,  // vertical tracking wheel 1
        &right_tracking_wheel, // vertical tracking wheel 2
        nullptr,               // horizontal tracking wheel 1
        nullptr,               // we don't have a second tracking wheel, so we set it to nullptr
        &inertial_sensor       // inertial sensor
    };

    // forward/backward PID
    lemlib::ControllerSettings lateralController{
        8,   // kP
        30,  // kD
        1,   // smallErrorRange
        100, // smallErrorTimeout
        3,   // largeErrorRange
        500, // largeErrorTimeout
        20   // slew rate
    };

    // turning PID
    lemlib::ControllerSettings angularController{
        4,   // kP
        40,  // kD
        1,   // smallErrorRange
        100, // smallErrorTimeout
        3,   // largeErrorRange
        500, // largeErrorTimeout
        20   // slew rate
    };

    lemlib::Chassis chassis(drivetrain, lateralController, angularController, sensors);

    pros::Task screenTask([&]()
                          {
        lemlib::Pose pose(-40, -60, 0);
        while (true) {
            // print robot location to the brain screen
            pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
            pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
            pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
            // log position telemetry
            lemlib::telemetrySink()->info("Chassis pose: {}", chassis.getPose());
            // delay to save resources
            pros::delay(50);
        } });

    chassis.calibrate(); // calibrate the chassis
    chassis.setPose(-40, -60, 0);
    arm.move_relative(-400, 127);
    motors::system::move_flywheel(127);
    motors::system::move_intake(127);
    // chassis.moveTo(-36, -40, 0, 10000, true, 200, 0.8);
    chassis.moveTo(-23, -7, 0, 10000, true, 0, 0.1, 200);
    pros::delay(250);
    chassis.turnTo(47, -7, 10000);
    pros::delay(500);
    motors::system::move_intake(0);
    arm.move_absolute(0, 127);
    pros::delay(500);
    motors::system::move_flywheel(-127);
    arm.move_absolute(-1600, 127);
    pros::delay(1500);
    chassis.moveTo(-75, -65, 0, 2250, false, 0, 0, 75);
    arm.move_absolute(500, 127);
    // chassis.setPose(-55, -53, 45, 0);
    // pros::delay(1000);
    // chassis.moveTo(0, -60, 0, 10000);
    // chassis.turnTo(-70, -54, 10000, false);
    pros::delay(10000);
}