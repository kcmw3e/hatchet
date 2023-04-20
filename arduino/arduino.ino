// Casey Walker
// 24-671 Electromechanical Systems Design
// Carnegie Mellon University
// -------------------------------------------------------------------------- //


#include <Arduino_DebugUtils.h>

void setup() {
  // Attach interrupts as needed
  // set up LED pins
  // set up Motor driver & pins
  // set up LCD & pins
  // set up IR LED/receiver & pins
}

void loop() {
  // Check on state, update LCD
  // Check on IR receiver, update state
  // Update motor driver control based on state of UI
  // Update LEDs based on state (or whatever controlls LEDs)
}

// Events:
//  Main switch (Arudino powers on)
//  E-Stop (motor controller & motor lose power), not sure how to detect
//  Buttons from UI
//  Switches from UI
//  Limit switches from cage
//  IR receiver signal change

// Events that can be interrupts:
//  Main switch (if not used to switch Arduino power)
//  E-stop (if find a way to monitor)
//  Buttons & switches from UI
//  Limit switches
