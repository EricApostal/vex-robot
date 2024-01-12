#include "main.h"
#include "../lib/tasks.hpp"
#include "../lib/maps.hpp"
#include "../lib/motors_mapped.hpp"
#include "../robot/chassis.hpp"

using namespace pros;

class Robot : public Tasks
{
public:
    /*
    0 = Driver
    1 = Auton
    */
    int mode = 0;
    bool autonStarted = false;
    int intakeState = 0; // -1 puncher, 0 = off, 1 = shooter
    bool arcadeDrive = true;
    bool bumpersOut = false;
    bool slapperState = false;

    Robot()
    {
        // motors::init();
    }

    void onTick() override
    {
        // mode 0 = driver, mode 1 = auton
        if (mode == 0)
        {
            // drive motors
            // int Left = 0;
            // int Right = 0;
            // int power = controller.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
            // int turn = controller.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);

            // Left = power + turn;
            // Right = power - turn;

            // left1.move(Left);
            // left2.move(Left);
            // left3.move(Left);

            // right1.move(Right);
            // right2.move(Right);
            // right3.move(Right);

            int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
            int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

            // move the robot
            chassis.curvature(leftY, rightX);

                if (controller.get_digital(E_CONTROLLER_DIGITAL_R1))
            {
                motors::system::move_intake(127);
            }
            else if (controller.get_digital(E_CONTROLLER_DIGITAL_R2))
            {
                motors::system::move_intake(-127);
            }
            else
            {
                motors::system::move_intake(0);
            }

            if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_UP))
            {
                slapper.move(slapperState ? 0 : 127);
                slapperState = !slapperState;
            }

            //     if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_Y))
            //     {
            //         if (intakeState == 0)
            //         {
            //             motors::system::set_flywheel_velocity(-450);
            //             intakeState = 1;
            //         }
            //         else
            //         {
            //             motors::system::set_flywheel_velocity(0);
            //             intakeState = 0;
            //         }
            //     }
            //     else if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_A))
            //     {
            //         if (intakeState == 0)
            //         {
            //             motors::system::set_flywheel_velocity(450);
            //             intakeState = -1;
            //         }
            //         else
            //         {
            //             motors::system::set_flywheel_velocity(0);
            //             intakeState = 0;
            //         }
            //     } else if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_LEFT)) {
            //         if (intakeState == 0) {
            //             motors::system::set_flywheel_velocity(-60);
            //             intakeState = 2;
            //         } else {
            //             motors::system::set_flywheel_velocity(0);
            //             intakeState = 0;
            //         }
            //     }

            if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_B))
            {
                bumpersOut = !bumpersOut;
            }

            if (bumpersOut)
            {
                motors::system::move_bumpers(true);
            }
            else
            {
                motors::system::move_bumpers(false);
            }

            // }
            // else if (mode == 1)
            // {
            //     // start auton task
            //     if (!autonStarted)
            //     {
            //         autonStarted = true;
            //     }
        }
    }
};