#include "main.h"
#include "defines.hpp"

using namespace pros;

void drivetrain_left(int32_t voltage) {
    left_1.move(voltage);
    left_2.move(voltage*-1);
    left_3.move(voltage);
}

void drivetrain_right(int32_t voltage) {
    right_1.move(voltage*-1);
    right_2.move(voltage);
    right_3.move(voltage);
}

void controller_tick() {
    // front_left_motor.move(controller.get_analog(ANALOG_LEFT_Y) + controller.get_analog(ANALOG_RIGHT_X));
    // back_left_motor.move(controller.get_analog(ANALOG_LEFT_Y) + controller.get_analog(ANALOG_RIGHT_X));
    drivetrain_left(controller.get_analog(ANALOG_LEFT_Y) + controller.get_analog(ANALOG_RIGHT_X));
    drivetrain_right(controller.get_analog(ANALOG_LEFT_Y)*-1 + controller.get_analog(ANALOG_RIGHT_X));
}

void tick() {
    // movement
    controller_tick();
} 

