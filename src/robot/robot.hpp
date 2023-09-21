#include "main.h"
#include "motors.hpp"
#include "tasks.hpp"
#include "auton.hpp"

#include "okapi/api.hpp"

using namespace pros;

class Robot: public Tasks {
    public:
        okapi::Controller controller;
        std::shared_ptr<ChassisController> drive;
        /*
        0 = Driver
        1 = Auton
        */
        int mode = 0;
        bool autonStarted = false;

        Robot(okapi::Controller controller) {
            controller = controller;
            Motors motors = Motors();
            drive = motors.drive;
        }

        void onTick() override {
            if (mode == 0) {
                // driver
            drive->getModel()->arcade(controller.getAnalog(ControllerAnalog::leftY),
                              controller.getAnalog(ControllerAnalog::rightX));
            } else if (mode == 1) {
                // start auton task
                if (!autonStarted) {
                    doAuton(drive);
                    autonStarted = true;

                }
            }
            
        }

};
