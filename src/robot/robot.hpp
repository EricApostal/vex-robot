#include "main.h"
#include "motors.hpp"
#include "tasks.hpp"
#include "maps.hpp"

#include "okapi/api.hpp"

using namespace pros;

class Robot : public Tasks
{
public:
    okapi::Controller controller;
    std::shared_ptr<ChassisController> drive;
    /*
    0 = Driver
    1 = Auton
    */
    int mode = 0;
    bool autonStarted = false;

    Robot(okapi::Controller controller)
    {
        controller = controller;
        Motors motors = Motors();
        drive = motors.drive;
    }

    void onTick() override
    {
        // mode 0 = driver, mode 1 = auton
        if (mode == 0)
        {
            
            // drive motors
            drive->getModel()->arcade(controller.getAnalog(ControllerAnalog::leftY),
                                      controller.getAnalog(ControllerAnalog::rightX));
            
            // pnuematic pushers
            if (controller.getDigital(ControllerDigital::L1))
            {
                // arm.move(-127);
                // left_bumper.set_value(1);
            } else {
                arm.move(0);
                left_bumper.set_value(0);
            }

            if (controller.getDigital(ControllerDigital::R1))
            {
                intake.move(-127);
                // arm.move(-127);
                // right_bumper.set_value(1);
            } else {
                intake.move(0);
                right_bumper.set_value(0);
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
