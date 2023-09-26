# Meredith Program
The best vex over under program around (real)

# General Structure
Just the jist of what you need to know when working on this codebase.

## The Scheduler
The scheduler is essentially the center of this program. It provides a way to add stuff to the loop, so we can run multiple concurrent tasks.

Example usage:
```cpp
#include "robot/scheduler.hpp"
#include "robot/tasks.hpp"

class NewTask: public Tasks {
    /*
    onTick is everything you want to run persistantly.
    Much of what you run will be in onTick
    */

    // You don't have to use "override", but it ensures we're doing what we want to -- our compiler will tell us if we are trying to
    // override a method that doesn't exist
    void onTick() override {
        // do whatever you want on tick
    }

    void onStart() override {
        // do whatever you want when the task is started (maybe calibrate a sensor?)
    }
}

// Now we want to create a new instance of the object
NewTask taskExample();

// Pass the task REFERENCE (ex: &taskName) into the scheduler. This task will now run every ~10ms!
scheduler.addTask(&taskExample);
```

Keep in mind that you won't always need an onStart, or even an onTick method override, they are just available if you need them. There is onComplete, but that doesn't get called *yet* (and I may remove it, since doing so from the scheduler could be redudant).

A more complete example can be found in `robot.hpp`, where the class `Robot` extends `Tasks` (with a custom constructor)

*rest of readme coming soon:tm:*