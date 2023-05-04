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
#include <stdint.h>

#define MAX_NUM_TASKS 32
#define MAX_NUM_SCHED_TASKS 64

using namespace std;

typedef void task_fn();

class Task {
  private:
    task_fn* _fn;
    uint32_t _dt; // milliseconds
    uint32_t _count; // number of times to execute
    uint32_t _t;
  public:
    Task();
    Task(task_fn* fn, size_t dt, size_t count = SIZE_MAX);
    void reset_time();
    void operator()(uint32_t);
    bool done();
    uint32_t get_time();
};

class Cal {
  private:
    uint32_t _t;
    Task _tasks[MAX_NUM_TASKS];
  public:
    Cal();
    bool setup();
    void tick();
    void add(task_fn* task, uint32_t dt, size_t count = SIZE_MAX);
};

#endif // EMSD_CAL_H
