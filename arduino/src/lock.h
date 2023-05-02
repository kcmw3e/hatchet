// Casey Walker (2023)
// 24-671 Electromechanical Systems Design
// Carnegie Mellon University
// -------------------------------------------------------------------------- //
//
// lock.h
// For controlling the servo that triggers the plate lock
//

#ifndef EMSD_LOCK_H
#define EMSD_LOCK_H

#include <Arduino.h>

#include <Servo.h>

#define LOCK_SERVO_PIN 12

#define LOCK_SERVO_LOCK_POS 40
#define LOCK_SERVO_UNLOCK_POS 150

class Lock {
  private:
    Servo _servo;
  public:
    Lock();
    bool setup();
    void lock();
    void unlock();
};

#endif // EMSD_LOCK_H
