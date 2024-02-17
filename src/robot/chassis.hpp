#pragma once
#include "main.h"
#include "lemlib/api.hpp"
#include "../lib/motors_mapped.hpp"

lemlib::Drivetrain drivetrain{
    &left_side_motors,  // left drivetrain motors
    &right_side_motors, // right drivetrain motors
    10.1,               // track width
    lemlib::Omniwheel::NEW_325,               // wheel diameter
    450,                // wheel rpm
    2               // chase power
};

lemlib::TrackingWheel horizontal_tracking_wheel(&horizontal_tracking, 2, 6);
lemlib::TrackingWheel vertical_tracking_wheel(&vertical_tracking, 2, 0);

// odometry struct
lemlib::OdomSensors sensors{
    &vertical_tracking_wheel,   // vertical tracking wheel 1
    nullptr,                    // vertical tracking wheel 2
    &horizontal_tracking_wheel, // horizontal tracking wheel 1
    nullptr,                    // we don't have a second tracking wheel, so we set it to nullptr
    &inertial_sensor            // inertial sensor
};

// forward/backward PID
lemlib::ControllerSettings linearController(
    10, // proportional gain (kP)
    0,
    30, // derivative gain (kD)
    0,
    1, // small error range, in inches
    100, // small error range timeout, in milliseconds
    3, // large error range, in inches
    500, // large error range timeout, in milliseconds
    20 // maximum acceleration (slew)
);

// turning PID
lemlib::ControllerSettings angularController(
    2, // proportional gain (kP)
    0,
    10, // derivative gain (kD)
    0,
    1, // small error range, in degrees
    100, // small error range timeout, in milliseconds
    3, // large error range, in degrees
    500, // large error range timeout, in milliseconds
    0 // maximum acceleration (slew). 0 means no limit
);

lemlib::Chassis chassis(drivetrain, linearController, angularController, sensors);

void init_chassis()
{
    chassis.calibrate();
    chassis.setPose(-40, -53, 90);

    pros::Task screenTask([&]()
                          {
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
}