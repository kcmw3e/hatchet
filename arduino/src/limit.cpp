// Casey Walker (2023)
// 24-671 Electromechanical Systems Design
// Carnegie Mellon University
// -------------------------------------------------------------------------- //

#include <Arduino_DebugUtils.h>

#include "limit.h"

Limit::Limit(){
  Button top(LIMIT_PIN_TOP, LIMIT_PRESSED_STATE);
  Button bot(LIMIT_PIN_BOT, LIMIT_PRESSED_STATE);
  Button doot(LIMIT_PIN_DOOR, LIMIT_PRESSED_STATE);
}

bool Limit::setup() {
  top.setup();
  bot.setup();
  door.setup();
  
  return true;
}

void Limit::set_triggered() {
  _triggered = true;
}

void Limit::update() {
  if (_triggered) {
    top.toggle();
    bot.toggle();
    door.toggle();

    _triggered = false;
  }
}
