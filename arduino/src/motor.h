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

#define MOTOR_CONTROL_CYTRON 0

#if MOTOR_CONTROL_CYTRON
# include <CytronMotorDriver.h>

# define MOTOR_PIN_SPD 5 // Motor controller input 1
# define MOTOR_PIN_DIR 6 // Motor controller input 2

# define MOTOR_RAISE_SPEED 100
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

class Motor {
  private:
#   if MOTOR_CONTROL_CYTRON
      int _spd;
      CytronMD _mot;
#   else
    int _pend_spd;
    int _write_spd;

    void _enable();
    void _disable();
    void _dir(uint8_t dir);
    void _spd(int spd);
#   endif // MOTOR_CONTROL_CYTRON
  public:
    Motor();
    bool setup();
    void write();
    void set_spd(int spd);
    void stop();
};

#endif // EMSD_MOTOR_H
