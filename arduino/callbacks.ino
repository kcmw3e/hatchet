// Casey Walker (2023)
// 24-671 Electromechanical Systems Design
// Carnegie Mellon University
// -------------------------------------------------------------------------- //
//
// callbacks.ino
// callbacks for buttons
//

bool callbacks_setup() {
  ui.raise.set_callback(ui_raise_callback);
  ui.split.set_callback(ui_split_callback);

  lim.top.set_callback(limit_top_callback);
  lim.bot.set_callback(limit_bot_callback);
  lim.door.set_callback(limit_door_callback);
  return true;
}

void ui_raise_callback() {
  if (ui.raise.state() == BUTTON_STATE_PRESSED) mot.set_spd(MOTOR_RAISE_SPEED);
  DEBUG_INFO("Raise is %s.", ui.raise.state() == BUTTON_STATE_PRESSED ? "pressed" : "unpressed");
}

void ui_split_callback() {
  if (ui.split.state() == BUTTON_STATE_PRESSED) mot.set_spd(MOTOR_SPLIT_SPEED);
  DEBUG_INFO("Split is %s.", ui.split.state() == BUTTON_STATE_PRESSED ? "pressed" : "unpressed");
}

void limit_top_callback() {
  if (lim.top.state() == BUTTON_STATE_PRESSED) mot.stop();
  DEBUG_INFO("Top limit switch %s.", lim.top.state() == BUTTON_STATE_PRESSED ? "triggered" : "released");
}

void limit_bot_callback() {
  if (lim.bot.state() == BUTTON_STATE_PRESSED) mot.stop();
  DEBUG_INFO("Bottom limit switch %s.", lim.bot.state() == BUTTON_STATE_PRESSED ? "triggered" : "released");
}

void limit_door_callback() {
  ui.lights(lim.door.state() == BUTTON_STATE_PRESSED);
  DEBUG_INFO("Door limit switch %s.", lim.door.state() == BUTTON_STATE_PRESSED ? "triggered" : "released");
}
