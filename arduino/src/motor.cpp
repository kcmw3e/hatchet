// Casey Walker (2023)
// 24-671 Electromechanical Systems Design
// Carnegie Mellon University
// -------------------------------------------------------------------------- //

#include "motor.h"


# if MOTOR_CONTROL_CYTRON
  Motor::Motor(): _mot(PWM_DIR, MOTOR_PIN_SPD, MOTOR_PIN_DIR)
  {
    _mot.setSpeed(0);
  }
# else
  Motor::Motor()
  {
    pinMode(MOTOR_PIN_SPD, OUTPUT);
    pinMode(MOTOR_PIN_DIR, OUTPUT);
    pinMode(MOTOR_PIN_ENA, OUTPUT);

    stop();
  }

  void Motor::_enable() {
    delayMicroseconds(MOTOR_DISABLE_DELAY); // give relay time to switch
    digitalWrite(MOTOR_PIN_ENA, MOTOR_ENABLE);
  }

  void Motor::_disable() {
    digitalWrite(MOTOR_PIN_ENA, MOTOR_DISABLE);
    delayMicroseconds(MOTOR_DISABLE_DELAY); // give relay time to switch
  }

  void Motor::_dir(uint8_t dir) {
    digitalWrite(MOTOR_PIN_DIR, dir);
  }

  void Motor::_spd(int spd) {
    // INPUT (analogWrite)    OUTPUT (V_out)
    // 255                    3.12
    // 220                    3.08
    // 200                    2.97
    // 170                    2.75
    // 140                    2.35
    // 120                    1.86
    // 100                    1.31
    //  80                    0.89
    //  60                    0.59
    //  40                    0.35
    //  20                    0.16
    //   0                    0.00

    if (spd > MOTOR_SPD_MAX) spd = MOTOR_SPD_MAX;
    analogWrite(MOTOR_PIN_SPD, spd);
  }
# endif // MOTOR_CONTROL_CYTRON

bool Motor::setup() {
  stop();

  return true;
}

void Motor::set_incr_fn(motor_incr_fn* fn) {
  _incr_fn = fn;
}

void Motor::write() {
  if (_pend_spd != _write_spd) {
#   if MOTOR_CONTROL_CYTRON
      _mot.setSpeed(_pend_spd);
#   else
      if (_pend_spd < 0) {
        // signs differ, so disable to change direction (to avoid possibility of shorting)
        if (_write_spd > 0) _disable();
        _dir(MOTOR_DIR_REV);
        _spd(-_pend_spd);
        _enable();
      } else if (_pend_spd > 0) {
        // signs differ, so disable to change direction (to avoid possibility of shorting)
        if (_write_spd < 0) _disable();
        _dir(MOTOR_DIR_FWD);
        _spd(_pend_spd);
        _enable();
      } else {
        _disable();
        _spd(0);
      }
#   endif // MOTOR_CONTROL_CYTRON
    _write_spd = _pend_spd;
  }
}

void Motor::set_spd(int spd) {
  _pend_spd = spd;
}

int Motor::get_spd() {
  return _write_spd;
}

void Motor::set_targ(int spd) {
  _targ_spd = spd;
}

void Motor::incr_spd() {
  if (_incr_fn == NULL) return;

  _pend_spd = _incr_fn(_write_spd, _targ_spd);
  if (_pend_spd == _targ_spd) _incr_fn = NULL; 
}

void Motor::stop() {
#   if MOTOR_CONTROL_CYTRON
    _mot.setSpeed(0);
#   else
    _disable();
    _spd(0);
#   endif // MOTOR_CONTROL_CYTRON
    _incr_fn = NULL;
    _pend_spd = 0;
    _write_spd = 0;
    _targ_spd = 0;
}
