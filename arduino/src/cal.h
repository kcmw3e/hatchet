// Casey Walker (2023)
// 24-671 Electromechanical Systems Design
// Carnegie Mellon University
// -------------------------------------------------------------------------- //
//
// cal.h
// For scheduling
//

#ifndef EMSD_CAL_H
#define EMSD_CAL_H

#include <Arduino.h>

#define MAX_NUM_TASKS 64

using namespace std;

typedef void task_fn();

class Task {
  private:
    task_fn* _fn;
    uint32_t _dt; // milliseconds
    uint32_t _t;
  public:
    Task(task_fn* fn, size_t dt);
    Task();
    void operator()(uint32_t);
};

class Cal {
  private:
    uint32_t _t;
    Task _tasks[MAX_NUM_TASKS];
    size_t _tasks_i = 0;
  public:
    Cal();
    bool setup();
    void tick();
    void add(task_fn* task, uint32_t dt);
};

#endif // EMSD_CAL_H
