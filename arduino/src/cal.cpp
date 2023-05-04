// Casey Walker (2023)
// 24-671 Electromechanical Systems Design
// Carnegie Mellon University
// -------------------------------------------------------------------------- //

#include <Arduino_DebugUtils.h>

#include "cal.h"


Task::Task(task_fn* fn, size_t dt, size_t count) {
  _fn = fn;
  _dt = dt;
  _count = count;
  _t = millis();
}

Task::Task() {
  _fn = NULL;
  _dt = 0;
  _t = millis();
}

void Task::reset_time() {
  _t = millis();
}

void Task::operator()(uint32_t t) {
  if (_count == 0) return;
  if (t - _t > _dt) {
    _t = t;
    _fn();
    if (_count != SIZE_MAX) _count--;
  }
}

bool Task::done() {
  return _count == 0;
}

uint32_t Task::get_time() {
  return _t;
}

Cal::Cal() {
  _t = millis();
}

bool Cal::setup() {
  return true;
}

void Cal::tick() {
  _t = millis();
  for (size_t i = 0; i < MAX_NUM_TASKS; i++) {
    Task& task = _tasks[i];
    task(_t);
  }
}

void Cal::add(task_fn* fn, uint32_t dt, size_t count) {
  for (size_t i = 0; i < MAX_NUM_TASKS; i++) {
    if (!_tasks[i].done()) continue;
    _tasks[i] = Task(fn, dt, count);
    Task& task = _tasks[i];
    task.reset_time();
    break;
  }
}
