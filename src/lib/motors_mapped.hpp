#pragma once

#include "main.h"
#include "tasks.hpp"
#include "maps.hpp"

using namespace pros;

namespace motors
{
    void init() {}
    
    namespace drivetrain {
        void move_left(int power) {
            left_side_motors.move(power);
            right_side_motors.move(-power);
        }

        void move_right(int power) {
            left_side_motors.move(-power);
            right_side_motors.move(power);
        }
    }

    namespace system {
        void move_intake(int power) {
            intake.move(power);
        }

        void move_bumpers(bool state) {
            left_bumper.set_value(state);
            right_bumper.set_value(state);
        }
    }

} // namespace motors