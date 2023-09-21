#include "main.h"
#include "robot/robot.hpp"
#include "robot/scheduler.hpp"
#include "okapi/api.hpp"
#include "robot/tasks.hpp"

using namespace pros;

pros::Controller master (E_CONTROLLER_MASTER);
Scheduler scheduler;
pros::Imu inertial_sensor(5);

void initialize() {
	pros::lcd::initialize();
	// bot.taskName = "robot";
	// scheduler.addTask(&bot);
	// scheduler.startScheduler();
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
}

void opcontrol() {
    std::string asd = "false";
    if (inertial_sensor.is_calibrating()) {
        asd = "true";
    }
    // master.print(0,0, "%s", asd);
	// bot.mode = 0;
	// bot.mode = 1;
    pros::MotorGroup left_side_motors({-1, 2, -3});
    pros::MotorGroup right_side_motors({8,9,-10});
    
    lemlib::Drivetrain_t drivetrain {
        &left_side_motors, // left drivetrain motors
        &right_side_motors, // right drivetrain motors
        12, // track width
        3.25, // wheel diameter
        360 // wheel rpm
    };

    lemlib::TrackingWheel left_tracking_wheel(&left_side_motors, 3.25, 6, 360);
    lemlib::TrackingWheel right_tracking_wheel(&right_side_motors, 3.25, 6, 360);

    // odometry struct
    lemlib::OdomSensors_t sensors {

        &left_tracking_wheel, // vertical tracking wheel 1
        &right_tracking_wheel, // vertical tracking wheel 2
        nullptr, // horizontal tracking wheel 1
        nullptr, // we don't have a second tracking wheel, so we set it to nullptr
        &inertial_sensor// inertial sensor
    };

    // forward/backward PID
    lemlib::ChassisController_t lateralController {
        8, // kP
        30, // kD
        1, // smallErrorRange
        100, // smallErrorTimeout
        3, // largeErrorRange
        500, // largeErrorTimeout
        5 // slew rate
    };
    
    // turning PID
    lemlib::ChassisController_t angularController {
        4, // kP
        40, // kD
        1, // smallErrorRange
        100, // smallErrorTimeout
        3, // largeErrorRange
        500, // largeErrorTimeout
        0 // slew rate
    };

    lemlib::Chassis chassis(drivetrain, lateralController, angularController, sensors);

    chassis.calibrate(); // calibrate the chassis
    chassis.setPose(0, 0, 0); // X: 0, Y: 0, Heading: 0
    // chassis.setPose(5.2, 10.333, 87); // X: 5.2, Y: 10.333, Heading: 87

    chassis.turnTo(5,5,5000);

}
