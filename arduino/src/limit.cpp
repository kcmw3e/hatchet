// Casey Walker (2023)
// 24-671 Electromechanical Systems Design
// Carnegie Mellon University
// -------------------------------------------------------------------------- //

#include <Arduino_DebugUtils.h>

#include "limit.h"

Limit::Limit(){
  top = Button(LIMIT_PIN_TOP);
  bot = Button(LIMIT_PIN_BOT);
  door = Button(LIMIT_PIN_DOOR);
}

bool Limit::setup() {
  top.setup();
  bot.setup();
  door.setup();
  
  return true;
}

void Limit::update() {
  top.update();
  bot.update();
  door.update();
}
