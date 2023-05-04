// Casey Walker (2023)
// 24-671 Electromechanical Systems Design
// Carnegie Mellon University
// -------------------------------------------------------------------------- //
//
// callbacks.ino
// callbacks for buttons
//

#define MOTOR_MODE_RAMP 1

#define RAMP_TIME 100 // milliseconds
#define RAMP_CALL_COUNT 5
#define RAMP_INTERVAL RAMP_TIME/RAMP_CALL_COUNT
#define SPLIT_ATTEMPT_TIME 3000 // milliseconds

static int RAMP_DIFF = 0;

bool callbacks_setup() {
  ui.raise.set_callback(ui_raise_callback);
  ui.split.set_callback(ui_split_callback);

  lim.top.set_callback(limit_top_callback);
  lim.bot.set_callback(limit_bot_callback);
  lim.door.set_callback(limit_door_callback);
  return true;
}

void ui_raise_callback() {
  if (ui.raise.is_pressed()) {
    // lock.lock();
    if (lim.top.is_pressed()) {
      ui.set_lcd_msg("ERR: Already", "raised.");
      DEBUG_INFO("Raise attempted while crusher is at the top.");
    } else if (lim.door.is_unpressed()) {
      ui.set_lcd_msg("ERR: Cannot run", "while door open.");
      DEBUG_INFO("Raise attempted while door is open.");
    } else {
      motor_raise();
    }
  }
}

void ui_split_callback() {
  if (ui.split.is_pressed()) {
    if (lim.bot.is_pressed()) {
      ui.set_lcd_msg("ERR: Already", "split.");
      DEBUG_INFO("Split attempted while crusher is at the bottom.");
    } else if (lim.door.is_unpressed()) {
      ui.set_lcd_msg("ERR: Cannot run", "while door open.");
      DEBUG_INFO("Split attempted while door is open.");
    } else {
      cal.add(motor_raise, SPLIT_ATTEMPT_TIME, 1);
      motor_split();
    }
  }
}

void limit_top_callback() {
  if (lim.top.is_pressed()) {
    // lock.lock();
    mot.stop();
    ui.set_lcd_msg("Done raising.");
    DEBUG_INFO("Top limit switched triggered, making sure motor is stopped.");
  }
}

void limit_bot_callback() {
  if (lim.bot.is_pressed()) {
    mot.stop();
    ui.set_lcd_msg("Done splitting.", "Check wood!");
    DEBUG_INFO("Bottom limit switch triggerd, making sure motor is stopped.");
  }
}

void limit_door_callback() {
  bool door_open = lim.door.is_unpressed();
  ui.lights(door_open);

  if (door_open) {
    mot.stop(); // just in case door opened while running
    ui.set_lcd_msg("Door is open,", "cannot run.");
  } else {
    ui.set_lcd_msg("Door is closed,", "ready to run.");
  }
}

void motor_raise() {
  if (lim.door.is_unpressed() || lim.top.is_pressed()) return;
#     if MOTOR_MODE_RAMP
      mot.set_targ(MOTOR_RAISE_SPEED);
      mot.set_incr_fn(motor_ramp);
      RAMP_DIFF = MOTOR_RAISE_SPEED - mot.get_spd();
      cal.add(motor_incr_spd, RAMP_INTERVAL, RAMP_CALL_COUNT);
#     else
      mot.set_spd(MOTOR_RAISE_SPEED);
#     endif // MOTOR_MODE_RAMP
    ui.set_lcd_msg("Raising...");
    DEBUG_INFO("Raising crusher.");
}

void motor_split() {
  if (lim.door.is_unpressed() || lim.bot.is_pressed()) return;
    // lock.unlock();
#     if MOTOR_MODE_RAMP
      mot.set_targ(MOTOR_SPLIT_SPEED);
      mot.set_incr_fn(motor_ramp);
      RAMP_DIFF = MOTOR_SPLIT_SPEED - mot.get_spd();
      cal.add(motor_incr_spd, RAMP_INTERVAL, RAMP_CALL_COUNT);
#     else
      mot.set_spd(MOTOR_SPLIT_SPEED);
#     endif // MOTOR_MODE_RAMP
    ui.set_lcd_msg("Splitting,", "watch out!");
    DEBUG_INFO("Sending crusher down.");
}

void motor_incr_spd() {
  mot.incr_spd();
}

int motor_ramp(int cur, int targ) {
  if ((targ < 0 && cur < targ) || (targ > 0 && cur > targ))      return targ;
  return cur + RAMP_DIFF/RAMP_CALL_COUNT;
}

void ui_lcd_raise_progress() {
  static size_t n = 0;

  const char* dots;
  switch (n) {
    case 0:
      dots = "";
      break;
    case 1:
      dots = ".";
      break;
    case 2:
      dots = "..";
      break;
    case 3:
      dots = "...";
      break;
    default:
      dots = "";
      n = 0;
      break;
  }
  n++;

  char msg[15];
  sprintf(msg, "%s%s", "Raising", dots);  
  ui.set_lcd_msg(msg);
}
