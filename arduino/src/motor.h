// Casey Walker (2023)
// 24-671 Electromechanical Systems Design
// Carnegie Mellon University
// -------------------------------------------------------------------------- //
//
// motor.h
// for controlling the impact driver motor
//

#ifndef EMSD_MOTOR_H
#define EMSD_MOTOR_H

#include <Arduino.h>
#include <Arduino_DebugUtils.h>

#define MOTOR_CONTROL_CYTRON 1

#if MOTOR_CONTROL_CYTRON
# include <CytronMotorDriver.h>

# define MOTOR_PIN_SPD 5 // Motor controller input 1
# define MOTOR_PIN_DIR 6 // Motor controller input 2

# define MOTOR_RAISE_SPEED -50
# define MOTOR_SPLIT_SPEED 100
#else
# define MOTOR_PIN_SPD 4 // pin to control 980Hz PWM motor speed control
# define MOTOR_PIN_DIR 6 // pin to switch the H-bridge
# define MOTOR_PIN_ENA 5 // pin to enable motor to move

# define MOTOR_DIR_FWD LOW
# define MOTOR_DIR_REV HIGH

# define MOTOR_ENABLE LOW
# define MOTOR_DISABLE HIGH

# define MOTOR_RAISE_SPEED 150
# define MOTOR_SPLIT_SPEED -200

# define MOTOR_SPD_MAX 200

# define MOTOR_DISABLE_DELAY 50 // microseconds
#endif // MOTOR_CONTROL_CYTRON

typedef int motor_incr_fn(int cur, int targ);

class Motor {
  private:
    int _targ_spd;  // target speed for ramping
    int _pend_spd;  // pending speed for next write
    int _write_spd; // speed currently being written
    motor_incr_fn* _incr_fn;
#   if MOTOR_CONTROL_CYTRON
      CytronMD _mot;
#   else
    void _enable();
    void _disable();
    void _dir(uint8_t dir);
    void _spd(int spd);
#   endif // MOTOR_CONTROL_CYTRON
  public:
    Motor();
    bool setup();
    void set_incr_fn(motor_incr_fn* fn);
    void write();
    void set_spd(int spd);
    int get_spd();
    void set_targ(int spd);
    void incr_spd();
    void stop();
};

#endif // EMSD_MOTOR_H
