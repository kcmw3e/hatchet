// Casey Walker (2023)
// 24-671 Electromechanical Systems Design
// Carnegie Mellon University
// -------------------------------------------------------------------------- //

#include "motor.h"

Motor::Motor():
  _mot(PWM_DIR, MOTOR_PIN_SPD, MOTOR_PIN_DIR)
{
  
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
