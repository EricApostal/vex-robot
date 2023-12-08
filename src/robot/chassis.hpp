#pragma once
#include "main.h"
#include "lemlib/api.hpp"
#include "../lib/motors_mapped.hpp"

lemlib::Drivetrain drivetrain{
    &left_side_motors,  // left drivetrain motors
    &right_side_motors, // right drivetrain motors
    10.3,               // track width
    3.25,               // wheel diameter
    360,                // wheel rpm
    100                 // chase power
};

// odometry struct
lemlib::OdomSensors sensors{
    // &left_tracking_wheel, // vertical tracking wheel 1
    // &right_tracking_wheel, // vertical tracking wheel 2
    // &back_tracking_wheel, // horizontal tracking wheel 1
    // nullptr, // we don't have a second tracking wheel, so we set it to nullptr
    // &inertial_sensor // inertial sensor

    nullptr,         // vertical tracking wheel 1
    nullptr,         // vertical tracking wheel 2
    nullptr,         // horizontal tracking wheel 1
    nullptr,         // we don't have a second tracking wheel, so we set it to nullptr
    &inertial_sensor // inertial sensor
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

void init_chassis()
{
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
    chassis.calibrate();
}