#include <string>

/*
    Task-based system for robot module controls
*/

using namespace std;

class Tasks {
    public: 
        bool isComplete = false;
        std::string taskName = "";

        Tasks(std::string task_name) {
            // taskName can be done without, perhaps useful for debug info
            taskName = task_name;
        };

        void onStart() {
            
        };

        void onComplete() {

        };

        void onTick() {

        }


};