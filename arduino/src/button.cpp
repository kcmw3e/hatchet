// Casey Walker (2023)
// 24-671 Electromechanical Systems Design
// Carnegie Mellon University
// -------------------------------------------------------------------------- //

#include "button.h"

Button::Button() {
  return;
}

Button::Button(uint8_t pin) {
  _pin = pin;
  _t = millis();
  pinMode(_pin, INPUT);
  _state = digitalRead(_pin);
}

bool Button::setup() {
  return true;
}

void Button::set_callback(button_callback_fn *fn) {
  _fn = fn;
}

void Button::update() {
  uint32_t t = millis();
  button_state_t new_state = digitalRead(_pin);
  if (new_state != _state && t - _t > BUTTON_DEBOUNCE_TIME) {
    _state = new_state;
    _t = t;
    if (_fn != NULL) _fn();
  }
}

button_state_t Button::state() {
  return _state;
}

bool Button::is_pressed() {
  return _state == BUTTON_STATE_PRESSED;
}

bool Button::is_unpressed() {
  return _state == BUTTON_STATE_UNPRESSED;
}
