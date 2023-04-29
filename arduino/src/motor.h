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

#include <CytronMotorDriver.h>

#define MOTOR_PIN_SPD 5 // Motor controller input 1
#define MOTOR_PIN_DIR 6 // Motor controller input 2

#define MOTOR_RAISE_SPEED 100
#define MOTOR_SPLIT_SPEED 100

class Motor {
  private:
    int _spd;
    CytronMD _mot;
  public:
    Motor();
    bool setup();
    void write();
    void set_spd(int spd);
    void stop();
};

#endif // EMSD_MOTOR_H
