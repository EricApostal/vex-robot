#include "main.h"
#include "tasks.hpp"
#include "maps.hpp"

using namespace pros;

namespace motors
{
    void init() {
        arm.set_brake_mode(MOTOR_BRAKE_HOLD);
        left1.set_brake_mode(MOTOR_BRAKE_HOLD);
        left2.set_brake_mode(MOTOR_BRAKE_HOLD);
        right1.set_brake_mode(MOTOR_BRAKE_HOLD);
        right2.set_brake_mode(MOTOR_BRAKE_HOLD);
    }
    
    namespace drivetrain {
        void move_left(int power) {
            left1.move(power);
            left2.move(power);
        }

        void move_right(int power) {
            right1.move(power);
            right2.move(power);
        }
    }

    namespace system {
        void move_intake(int power) {
            intake_1.move(power);
            intake_2.move(power);
        }

        void move_flywheel(int power) {
            flywheel_1.move(power);
            flywheel_2.move(power);
        }

        void move_arm(int power) {
            arm.move(power);
        }

        void move_bumpers(bool state) {
            left_bumper.set_value(state);
            right_bumper.set_value(state);
        }
    }

} // namespace motors
