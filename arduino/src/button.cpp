// Casey Walker (2023)
// 24-671 Electromechanical Systems Design
// Carnegie Mellon University
// -------------------------------------------------------------------------- //

#include "button.h"

Button::Button() {
  _t = millis();
  state = BUTTON_STATE_UNPRESSED;
}

void Button::toggle() {
  uint32_t t = millis();
  if (t - _t > BUTTON_DEBOUNCE_TIME) {
    state = !state;
    _t = t;
  }
}
