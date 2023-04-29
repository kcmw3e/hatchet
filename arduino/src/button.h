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
#include <Arduino_DebugUtils.h>

#define BUTTON_DEBOUNCE_TIME 50 // ms

#define BUTTON_STATE_PRESSED HIGH
#define BUTTON_STATE_UNPRESSED LOW

typedef int button_state_t;
typedef void button_callback_fn();

class Button {
  private:
    uint8_t _pin;
    uint32_t _t;
    button_state_t _state;
    button_callback_fn* _fn;
  public:
    Button();
    Button(uint8_t pin);
    bool setup();
    void set_callback(button_callback_fn* fn);
    void update();
    button_state_t state();
    bool is_pressed();
    bool is_unpressed();
};

#endif // EMSD_BUTTON_H
