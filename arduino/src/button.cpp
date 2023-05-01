// Casey Walker (2023)
// 24-671 Electromechanical Systems Design
// Carnegie Mellon University
// -------------------------------------------------------------------------- //

#include "button.h"

Button::Button() {
  return;
}

Button::Button(uint8_t pin, int pressed_val) {
  _pin = pin;
  _t = millis();
  pinMode(_pin, INPUT);
  _pin_val = digitalRead(_pin);
  _pressed_val = pressed_val;
}

bool Button::setup() {
  return true;
}

void Button::set_callback(button_callback_fn *fn) {
  _fn = fn;
}

void Button::update() {
  uint32_t t = millis();
  int val = digitalRead(_pin);
  if (val != _pin_val && t - _t > BUTTON_DEBOUNCE_TIME) {
    _pin_val = val;
    _t = t;
    if (_fn != NULL) _fn();
  }
}

bool Button::is_pressed() {
  return _pin_val == _pressed_val;
}

bool Button::is_unpressed() {
  return _pin_val != _pressed_val;;
}
