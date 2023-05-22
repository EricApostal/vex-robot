// #include "main.h"
// #include "defines.hpp"

// void move_distance(int distance) {
//     front_left_motor.move(40);
//     front_right_motor.move(-40);
//     back_left_motor.move(40);
//     back_right_motor.move(-40);
//     delay(distance*16);
//     front_left_motor.move(0);
//     front_right_motor.move(0);
//     back_left_motor.move(0);
//     back_right_motor.move(0);
// }

// void move(int velocity, bool reverse=false) {
//     int rev = 1;
//     if (reverse) {
//         rev = -1;
//     }

//     front_left_motor.move(velocity*rev);
//     front_right_motor.move(-velocity*rev);
//     back_left_motor.move(velocity*rev);
//     back_right_motor.move(-velocity*rev);
// }

// void turn(int velocity, bool cc=false) { // cc for counterclockwise
//   int turn = 1;
//   if (cc) {
//     turn = -1;
//   }
//     front_left_motor.move(velocity*turn);
//     front_right_motor.move(velocity*turn);
//     back_left_motor.move(velocity*turn);
//     back_right_motor.move(velocity*turn);
// }

// void intake_motors(int velocity) {
//   intake_motor_1.move_velocity(velocity);
//   intake_motor_2.move_velocity(velocity);
// }
