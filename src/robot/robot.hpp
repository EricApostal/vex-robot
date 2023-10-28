#include "main.h"
#include "tasks.hpp"
#include "maps.hpp"

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


    Robot()
    {
        arm1.set_brake_mode(MOTOR_BRAKE_HOLD);
    }

    void onTick() override
    {
        // mode 0 = driver, mode 1 = auton
        if (mode == 0)
        {
            // drive motors
            int Left;
            int Right;
            if (arcadeDrive) {
                int power = controller.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
                int turn = controller.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);

                int Left = power + turn;
                int Right = power - turn;
            } else {
                Left = controller.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
                Right = controller.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y);
            }

            left1.move(Left);
            left2.move(Left);
            left3.move(Left);

            right1.move(Right);
            right2.move(Right);
            right3.move(Right);

            // pnuematic pushers
            // if (controller.get_digital(E_CONTROLLER_DIGITAL_R2))
            // {
            //     right_bumper.set_value(1);
            // }
            // else
            // {
            //     right_bumper.set_value(0);
            // }

            // if (controller.get_digital(E_CONTROLLER_DIGITAL_L2))
            // {
            //     left_bumper.set_value(1);
            // } else {
            //     left_bumper.set_value(0);
            // }


            if (controller.get_digital(E_CONTROLLER_DIGITAL_R1))
            {
                arm1.move(-127);
            }
            else if (controller.get_digital(E_CONTROLLER_DIGITAL_R2))
            {
                arm1.move(127);
            }
            else
            {
                arm1.move(0);
            }

            if (controller.get_digital(E_CONTROLLER_DIGITAL_L1)) {
                intake_1.move(-127);
                intake_2.move(127);
            } else if (controller.get_digital(E_CONTROLLER_DIGITAL_L2)) {
                intake_1.move(127);
                intake_2.move(-127);
            } else {
                intake_1.move(0);
                intake_2.move(0);
            }


            if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_Y))
            {
                if (intakeState == 0)
                {
                    flywheel.move(-127);
                    intakeState = 1;
                }
                else
                {
                    flywheel.move(0);
                    intakeState = 0;
                }
            }
            else if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_B))
            {
                if (intakeState == 0)
                {
                    flywheel.move(127);
                    intakeState = -1;
                }
                else
                {
                    flywheel.move(0);
                    intakeState = 0;
                }
            } else if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_DOWN)) {
                if (intakeState == 0) {
                flywheel.move(-60);
                intakeState = 2;
                } else {
                    flywheel.move(0);
                    intakeState = 0;
                }
            }
        }
        else if (mode == 1)
        {
            // start auton task
            if (!autonStarted)
            {
                autonStarted = true;
            }
        }
    }
};
