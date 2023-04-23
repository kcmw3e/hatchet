// Casey Walker (2023)
// 24-671 Electromechanical Systems Design
// Carnegie Mellon University
// -------------------------------------------------------------------------- //
//
// button.h
// For tracking the state of buttons
//

#ifndef EMSD_BUTTON_H
#define EMSD_BUTTON_H

#include <Arduino.h>

#define BUTTON_DEBOUNCE_TIME 50 // ms

#define BUTTON_STATE_PRESSED true
#define BUTTON_STATE_UNPRESSED false

typedef int button_state_t;

class Button {
  private:
    uint32_t _t;
  public:
    button_state_t state;

    Button();
    void toggle();
};

#endif // EMSD_BUTTON_H
