// Casey Walker (2023)
// 24-671 Electromechanical Systems Design
// Carnegie Mellon University
// -------------------------------------------------------------------------- //
//
// tasks.ino
// periodic tasks to run
//

#define MOTOR_WRITE_INTERVAL 10 // ms
#define UI_UPDATE_INTERVAL 0 // ms

bool tasks_setup() {
  cal.add(task_motor_write, MOTOR_WRITE_INTERVAL);
  cal.add(task_ui_update, UI_UPDATE_INTERVAL);

  return true;
}

void task_motor_write() {
  mot.write();
}

void task_ui_update() {
  ui.update();
}
