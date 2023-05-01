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
  attachInterrupt(LIMIT_RUP_TOP, rup_mot_limit_triggered, LIMIT_RUPMODE_TOP);
  attachInterrupt(LIMIT_RUP_BOT, rup_mot_limit_triggered, LIMIT_RUPMODE_BOT);
  attachInterrupt(LIMIT_RUP_DOOR, rup_door_limit_triggered, LIMIT_RUPMODE_DOOR);

  return true;
}

void rup_mot_limit_triggered() {
  // if (digitalRead(LIMIT_PIN_TOP) == LIMIT_PRESSED_VAL || digitalRead(LIMIT_PIN_BOT) == LIMIT_PRESSED_VAL)
  //   mot.stop();
  return;
}

void rup_door_limit_triggered() {
  if (digitalRead(LIMIT_PIN_DOOR) != LIMIT_PRESSED_VAL) // when door open (i.e. not pressed), stop motor
    mot.stop();
}
