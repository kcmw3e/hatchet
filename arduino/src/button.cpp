// Casey Walker (2023)
// 24-671 Electromechanical Systems Design
// Carnegie Mellon University
// -------------------------------------------------------------------------- //

#include "button.h"

Button::Button() {
  return;
}

Button::Button(uint8_t pin, int pressed_state) {
  _pin = pin;
  _pressed_state = pressed_state;
  _t = millis();
  state = BUTTON_STATE_UNPRESSED;
}

bool Button::setup() {
  pinMode(_pin, INPUT);
  return true;
}

void Button::toggle() {
  uint32_t t = millis();
  if (t - _t > BUTTON_DEBOUNCE_TIME) {
    if (digitalRead(_pin) == _pressed_state) state = BUTTON_STATE_PRESSED;
    else state = BUTTON_STATE_UNPRESSED;
    _t = t;
  }
}
