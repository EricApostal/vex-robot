
#include "main.h"
#include "tasks.hpp"
#include <vector>

using namespace pros;

/*
    Allows for running events on tick and such.
    Basically a timing system.
*/

std::vector< Tasks > taskArray;

// handles the state of the scheduler externally
bool schedulerRunning;

// if the internal loop has started
bool schedulerTaskStarted;

// Adds a new task to the schedular
void addTask(Tasks newTask) {
    taskArray.push_back(newTask);
}

void startScheduler() {
    schedulerRunning = true;
    if (!schedulerTaskStarted) {
        // start the listener thread if not already started
        Task sTask(schedulerLoop);
    }
}

void pauseScheduler() {
    schedulerRunning = false;
}

// TODO: Handle cleanup when a task is completed
void schedulerLoop() {
    // needs to be implemented via a task
    // represents the function where the loop would be
    while (true) {
        for (int i = 0; i < taskArray.size(); i++) {
            // call the onTick method of every registered task
            taskArray[i].onTick();
        }
        // delayed so we don't crash the program, 10 ms is a magic number
        delay(10);
    }
}

