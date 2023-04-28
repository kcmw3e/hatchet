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
  attachInterrupt(LIMIT_PIN_TOP, rup_mot_limit_triggered, LIMIT_RUPMODE_TOP);
  attachInterrupt(LIMIT_PIN_BOT, rup_mot_limit_triggered, LIMIT_RUPMODE_BOT);
  attachInterrupt(LIMIT_PIN_DOOR, rup_door_limit_triggered, LIMIT_RUPMODE_DOOR);

  return true;
}

void rup_mot_limit_triggered() {
  if (digitalRead(LIMIT_PIN_TOP) == BUTTON_STATE_PRESSED || digitalRead(LIMIT_PIN_BOT) == BUTTON_STATE_PRESSED)
    mot.set_spd(0);
}

void rup_door_limit_triggered() {
  if (digitalRead(LIMIT_PIN_DOOR) == BUTTON_STATE_UNPRESSED)
    mot.set_spd(0);
}
