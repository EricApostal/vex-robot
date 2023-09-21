#pragma once
#include <string>
#include "motors.hpp"

/*
    Task-based system for robot module controls
*/

using namespace std;


class Tasks {
    public: 
        bool isComplete = false;
        std::string taskName = "default";

        Tasks() {
            
        };

        virtual void onStart() {
            
        };

        virtual void onComplete() {

        };

        virtual void onTick() {
            
        };


};
