#include "main.h"
#include "motors.hpp"
#include "tasks.hpp"
#include "okapi/api.hpp"

using namespace pros;

class Robot: public Tasks {
    public:
        /*
            0 = idle
            1 = running
            2 = completed
        */
        int status = 0;
        okapi::Controller controller;
        std::shared_ptr<ChassisController> drive;

        Robot(okapi::Controller controller) {
            controller = controller;
            Motors motors = Motors();
            drive = motors.drive;
        }

        // Robot(const Robot& other) {
        //     controller.setText(1, 1, "copy");
        // }

        std::string onTick() override {
            // controller.setText(1, 1, "robot on tick");
            drive->getModel()->arcade(controller.getAnalog(ControllerAnalog::leftY),
                              controller.getAnalog(ControllerAnalog::rightX));
            controller.setText(1, 1, "analog recieved");
            return "yep";
        }

};
