#include "main.h"
#include "tasks.hpp"
#include "api.h"

#include <list>

using namespace pros;

/*
    Allows for running events on tick and such.
    Basically a timing system.
*/

class Scheduler
{
public:
    // handles the state of the scheduler externally
    bool schedulerRunning;

    // if the internal loop has started
    bool schedulerTaskStarted = false;

    std::vector<Tasks*> taskArray;

    // Adds a new task to the scheduler
    void addTask(Tasks* newTask)
    {
        taskArray.push_back(newTask);
        newTask->onStart();
    }

    void startScheduler()
    {
        schedulerRunning = true;
        if (!schedulerTaskStarted)
        {
            // start the listener thread if not already started
            Task sTask{[=]
                       {
                           schedulerLoop();
                       }};
            schedulerTaskStarted = true;
        }
    }

    void pauseScheduler()
    {
        schedulerRunning = false;
    }

private:
    // TODO: Handle cleanup when a task is completed
    // TODO: Implement disabling schedular
    void schedulerLoop()
    {
        // needs to be implemented via a task
        // represents the function where the loop would be
        while (true)
        {
            for (int i = 0; i < taskArray.size(); i++)
            {
                // call the onTick method of every registered task
                taskArray[i]->onTick();
            }
            // delayed so we don't crash the program, 10ms is standard but you can change it i guess
            delay(10);
        };
    };
};