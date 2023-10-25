#pragma once
#include <string>

/*
    Task-based system for robot module controls
*/

// waddya want from me?
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
