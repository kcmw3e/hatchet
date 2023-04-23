// Casey Walker (2023)
// 24-671 Electromechanical Systems Design
// Carnegie Mellon University
// -------------------------------------------------------------------------- //


#include <Arduino_DebugUtils.h>

#include "src/motor.h"
#include "src/cal.h"
#include "src/ui.h"

Cal cal;
Motor mot;
UI ui;

#define BAUD 115200

void setup() {
  Serial.begin(BAUD);
  DEBUG_INFO("Setting things up...");

  if (!mot.setup()) {
    DEBUG_INFO("failed motor setup");
    while (true);
  };
  DEBUG_INFO("success motor setup");

  if (!cal.setup()) {
    DEBUG_INFO("failed scheduler setup");
    while (true);
  }
  DEBUG_INFO("success scheduler setup");

  if (!tasks_setup()) {
    DEBUG_INFO("failed setting up tasks");
    while (true);
  }   
  DEBUG_INFO("success setting up tasks");

  if (!ui.setup()) {
    DEBUG_INFO("failed setting up ui");
    while (true);
  }
  DEBUG_INFO("success setting up ui");

  if (!interrupt_setup()) {
    DEBUG_INFO("failed setting up interrupts");
    while (true);
  }
  DEBUG_INFO("success setting up interrupts");

  // Attach interrupts as needed
  // set up LED pins
  // set up Motor driver & pins
  // set up LCD & pins
  // set up IR LED/receiver & pins
}

void loop() {
  cal.tick();
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
