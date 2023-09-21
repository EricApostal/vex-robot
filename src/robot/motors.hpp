#pragma once

#include "main.h"
#include "okapi/api.hpp"

using namespace okapi;


class Motors
{
public:
    okapi::MotorGroup leftMotors = okapi::MotorGroup({-1, 2, -3});
    okapi::MotorGroup rightMotors = okapi::MotorGroup({8, 9, -10});
    std::shared_ptr<ChassisController> drive;

    Motors() {
        leftMotors.setBrakeMode( okapi::AbstractMotor::brakeMode::hold );
        rightMotors.setBrakeMode( okapi::AbstractMotor::brakeMode::hold );

        drive = ChassisControllerBuilder()

        // .withMotors({-1, -2, 3}, {8, -9, -10})
        .withMotors(leftMotors, rightMotors)
        // Green gearset, 4 in wheel diam, 11.5 in wheel track
        .withDimensions(AbstractMotor::gearset::blue, {{3.25_in, 12_in}, 400})
        .build();
    }
};
