#pragma once
#include "main.h"
#include "../../lib/tasks.hpp"
#include "../../lib/motors_mapped.hpp"
#include "lemlib/api.hpp"

ASSET(path1_txt);

class AutonController
{

public:
    lemlib::Drivetrain drivetrain;
    lemlib::OdomSensors sensors;  
    lemlib::ControllerSettings lateralController;
    lemlib::ControllerSettings angularController;
    lemlib::Chassis chassis;
    
    void startAuton() {
        chassis.setPose(-23, 0, 0);
        // chassis.turnTo(0, 0, 10000);
        chassis.moveToPoint(-22, 0, 10000, false, 127, false);
        // chassis.follow(path1_txt, 15, 10000, true);
        // chassis.waitUntilDone();
        pros::delay(10000);
    }

    AutonController() :
    drivetrain(
        &left_side_motors,  // left drivetrain motors
        &right_side_motors, // right drivetrain motors
        10.3,               // track width
        3.25,               // wheel diameter
        360,                // wheel rpm
        8
    ),
    sensors{
        nullptr,         // vertical tracking wheel 1
        nullptr,         // vertical tracking wheel 2
        nullptr,         // horizontal tracking wheel 1
        nullptr,         // second tracking wheel
        &inertial_sensor
    },
    lateralController(
        8,   // kP
        30,  // kD
        1,   // smallErrorRange
        100, // smallErrorTimeout
        3,   // largeErrorRange
        500, // largeErrorTimeout
        5    // slew rate
    ),
    angularController(
        4,   // kP
        40,  // kD
        1,   // smallErrorRange
        100, // smallErrorTimeout
        3,   // largeErrorRange
        500, // largeErrorTimeout
        0    // slew rate
    ),
    chassis(drivetrain, lateralController, angularController, sensors) // Initialize chassis here
    {

        pros::Task screenTask([&]() {
            chassis.calibrate();
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
            }
        });
    }
};
