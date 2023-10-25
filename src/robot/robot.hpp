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

    Robot()
    {
        arm.set_brake_mode(MOTOR_BRAKE_HOLD);
    }

    void onTick() override
    {
        // mode 0 = driver, mode 1 = auton
        if (mode == 0)
        {
            // drive motors
            int power = controller.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
            int turn = controller.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);

            int Left = power + turn;
            int Right = power - turn;

            left1.move(Left);
            left2.move(Left);
            left3.move(Left);

            right1.move(Right);
            right2.move(Right);
            right3.move(Right);

            // pnuematic pushers
            if (controller.get_digital(E_CONTROLLER_DIGITAL_R2))
            {
                right_bumper.set_value(1);
            }
            else
            {
                right_bumper.set_value(0);
            }

            if (controller.get_digital(E_CONTROLLER_DIGITAL_L2))
            {
                left_bumper.set_value(1);
            } else {
                left_bumper.set_value(0);
            }

            if (controller.get_digital(E_CONTROLLER_DIGITAL_R1))
            {
                arm.move(80);
            }
            else if (controller.get_digital(E_CONTROLLER_DIGITAL_L1))
            {
                arm.move(-40);
            }
            else
            {
                arm.move(0);
            }

            if (controller.get_digital(E_CONTROLLER_DIGITAL_R1))
            {
                left_bumper.set_value(0);
            }

            if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_Y))
            {
                if (intakeState == 0)
                {
                    intake.move(-127);
                    intakeState = 1;
                }
                else
                {
                    intake.move(0);
                    intakeState = 0;
                }
            }
            else if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_B))
            {
                if (intakeState == 0)
                {
                    intake.move(127);
                    intakeState = -1;
                }
                else
                {
                    intake.move(0);
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
