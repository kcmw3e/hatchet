// Casey Walker (2023)
// 24-671 Electromechanical Systems Design
// Carnegie Mellon University
// -------------------------------------------------------------------------- //
//
// tasks.ino
// periodic tasks to run
//

// all intervals in ms
#define MOTOR_WRITE_INTERVAL 10
#define UI_UPDATE_INTERVAL 0
#define LIMIT_UPDATE_INTERVAL 0

bool tasks_setup() {
  cal.add(task_motor_write, MOTOR_WRITE_INTERVAL);
  cal.add(task_ui_update, UI_UPDATE_INTERVAL);
  cal.add(task_limit_update, LIMIT_UPDATE_INTERVAL);

  return true;
}

void task_motor_write() {
  mot.write();
}

void task_ui_update() {
  ui.update();
}

void task_limit_update() {
  lim.update();
}
