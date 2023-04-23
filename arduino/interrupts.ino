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
  attachInterrupt(UI_RUP_RAISE, rup_raise, UI_RUPMODE_RAISE);
  attachInterrupt(UI_RUP_SPLIT, rup_split, UI_RUPMODE_SPLIT);

  return true;
}

void rup_raise() {
  ui.raise.toggle();
}

void rup_split() {
  ui.split.toggle();
}
