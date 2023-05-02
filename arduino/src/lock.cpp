// Casey Walker (2023)
// 24-671 Electromechanical Systems Design
// Carnegie Mellon University
// -------------------------------------------------------------------------- //

#include "lock.h"

Lock::Lock() {
  pinMode(LOCK_SERVO_PIN, OUTPUT);
}

bool Lock::setup() {
  _servo.attach(LOCK_SERVO_PIN);
  lock();
  return true;
}

void Lock::lock() {
  _servo.write(LOCK_SERVO_LOCK_POS);
}

void Lock::unlock() {
  _servo.write(LOCK_SERVO_UNLOCK_POS);
}
