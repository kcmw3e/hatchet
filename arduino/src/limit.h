// Casey Walker (2023)
// 24-671 Electromechanical Systems Design
// Carnegie Mellon University
// -------------------------------------------------------------------------- //
//
// limit.h
// For tracking the state of limit switches
//

#ifndef EMSD_LIMIT_H
#define EMSD_LIMIT_H

#include <Arduino.h>

#include "rup.h"
#include "button.h"

#define LIMIT_PIN_TOP RUP3
#define LIMIT_PIN_BOT RUP4
#define LIMIT_PIN_DOOR RUP5

#define LIMIT_RUPMODE_TOP CHANGE
#define LIMIT_RUPMODE_BOT CHANGE
#define LIMIT_RUPMODE_DOOR CHANGE

#define LIMIT_RUP_TOP digitalPinToInterrupt(LIMIT_PIN_TOP)
#define LIMIT_RUP_BOT digitalPinToInterrupt(LIMIT_PIN_BOT)
#define LIMIT_RUP_DOOR digitalPinToInterrupt(LIMIT_PIN_DOOR)

#define LIMIT_PRESSED_STATE HIGH

class Limit {
  private:
    bool _triggered;
  public:
    Button top;
    Button bot;
    Button door;

    Limit();
    bool setup();
    void set_triggered();
    void update();
};

#endif // EMSD_LIMIT_H
