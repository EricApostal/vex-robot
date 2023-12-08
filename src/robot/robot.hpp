#include "main.h"
#include "../lib/tasks.hpp"
#include "../lib/maps.hpp"
#include "../lib/motors_mapped.hpp"

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
    bool hangState = false;

    Robot()
    {
        motors::init();
    }

    void onTick() override
    {
        // mode 0 = driver, mode 1 = auton
        if (mode == 0)
        {
            // drive motors
            int Left = 0;
            int Right = 0;
            if (arcadeDrive) {
                int power = controller.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
                int turn = controller.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);

                Left = power + turn;
                Right = power - turn;
            } else {
                Left = controller.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
                Right = controller.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y);
            }

            motors::drivetrain::move_left(Left);
            motors::drivetrain::move_right(Right);


            if (controller.get_digital(E_CONTROLLER_DIGITAL_R1))
            {
                if (!hangState) {
                    motors::system::move_arm(-127);
                }
            }
            else if (controller.get_digital(E_CONTROLLER_DIGITAL_R2))
            {
                motors::system::move_arm(127);
            }
            else
            {
                motors::system::move_arm(0);
            }

            if (controller.get_digital(E_CONTROLLER_DIGITAL_L1)) {
                motors::system::move_intake(127);
            } else if (controller.get_digital(E_CONTROLLER_DIGITAL_L2)) {
                motors::system::move_intake(-127);
            } else {
                motors::system::move_intake(0);
            }

            if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_UP)) {
                hangState = !hangState;
                motors::system::set_hang_lock(hangState);
            }

            if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_Y))
            {
                if (intakeState == 0)
                {
                    motors::system::move_flywheel(-127);
                    intakeState = 1;
                }
                else
                {
                    motors::system::move_flywheel(0);
                    intakeState = 0;
                }
            }
            else if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_A))
            {
                if (intakeState == 0)
                {
                    motors::system::move_flywheel(127);
                    intakeState = -1;
                }
                else
                {
                    motors::system::move_flywheel(0);
                    intakeState = 0;
                }
            } else if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_LEFT)) {
                if (intakeState == 0) {
                    motors::system::move_flywheel(-60);
                    intakeState = 2;
                } else {
                    motors::system::move_flywheel(0);
                    intakeState = 0;
                }
            }
            if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_X)) {
                arcadeDrive = !arcadeDrive;
            }
            if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_B)) {
                bumpersOut = !bumpersOut;
            }

            // todo: make less verbose
            if (bumpersOut) {
                motors::system::move_bumpers(true);
            } else {
                motors::system::move_bumpers(false);
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