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

typedef void button_callback_fn();

class Button {
  private:
    uint8_t _pin;
    uint32_t _t;
    int _pin_val;
    int _pressed_val;
    button_callback_fn* _fn;
  public:
    Button();
    Button(uint8_t pin, int pressed_val);
    bool setup();
    void set_callback(button_callback_fn* fn);
    void update();
    bool is_pressed();
    bool is_unpressed();
};

#endif // EMSD_BUTTON_H
