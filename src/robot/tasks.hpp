#include <string>
#include "motors.hpp"

/*
    Task-based system for robot module controls
*/

using namespace std;

#ifndef TASKS_HPP
#define TASKS_HPP

class Tasks {
    public: 
        bool isComplete = false;
        std::string taskName = "default";

        Tasks() {
            
        };

        void onStart() {
            
        };

        void onComplete() {

        };

        virtual std::string onTick() {
            return "nope";
        };


};

#endif