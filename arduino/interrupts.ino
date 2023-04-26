// Casey Walker (2023)
// 24-671 Electromechanical Systems Design
// Carnegie Mellon University
// -------------------------------------------------------------------------- //
//
// interrupts.ino
// interrupt tasks to run
//

// Arduino Mega interrupt pins: 2, 3, 18, 19, 20, 21

bool interrupt_setup() {
  attachInterrupt(UI_RUP_RAISE, rup_ui_button_triggered, UI_RUPMODE_RAISE);
  attachInterrupt(UI_RUP_SPLIT, rup_ui_button_triggered, UI_RUPMODE_SPLIT);
  
  attachInterrupt(LIMIT_PIN_BOT, rup_limit_triggered, LIMIT_RUPMODE_BOT);
  attachInterrupt(LIMIT_PIN_TOP, rup_limit_triggered, LIMIT_RUPMODE_TOP);
  attachInterrupt(LIMIT_PIN_DOOR, rup_limit_triggered, LIMIT_RUPMODE_DOOR);

  return true;
}

void rup_ui_button_triggered() {
  ui.set_button_triggered();
}

void rup_limit_triggered() {
  lim.set_triggered();
}
