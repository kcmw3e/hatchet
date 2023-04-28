// Casey Walker (2023)
// 24-671 Electromechanical Systems Design
// Carnegie Mellon University
// -------------------------------------------------------------------------- //

#include "motor.h"

Motor::Motor(): _mot(PWM_DIR, MOTOR_PIN_SPD, MOTOR_PIN_DIR)
{
  _mot.setSpeed(0);
}

bool Motor::setup() {

  return true;
}

void Motor::write() {
  _mot.setSpeed(_spd);
}

void Motor::set_spd(int spd) {
  _spd = spd;
}

void Motor::stop() {
  _mot.setSpeed(0);
}
