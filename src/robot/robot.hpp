#include "main.h"
#include "motors.hpp"
#include "tasks.hpp"

using namespace pros;

class Robot {
    public:
        /*
            0 = idle
            1 = running
            2 = completed
        */
        int status = 0;
        Tasks task = Tasks("main");
};
