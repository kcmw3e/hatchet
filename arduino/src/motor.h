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

#include <CytronMotorDriver.h>

#define MOTOR_PIN_SPD 3 // Motor controller input 1
#define MOTOR_PIN_DIR 4 // Motor controller input 2

#define MOTOR_FWD HIGH
#define MOTOR_REV LOW

class Motor {
  private:
    int _spd;
    CytronMD _mot;
  public:
    Motor();
    bool setup();
    void write();
    void set_spd(int spd);
};

#endif // EMSD_MOTOR_H
