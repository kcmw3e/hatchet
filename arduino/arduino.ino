// Casey Walker (2023)
// 24-671 Electromechanical Systems Design
// Carnegie Mellon University
// -------------------------------------------------------------------------- //


#include <Arduino_DebugUtils.h>

#include "src/motor.h"
#include "src/cal.h"
#include "src/ui.h"
#include "src/limit.h"
#include "src/lock.h"

Cal cal;    // scheduler
Motor mot;  // motor
UI ui;      // ui buttons and lcd
Limit lim;  // limit switches
Lock lock;  // servo locking mechanism

#define BAUD 115200

void try_setup(bool setup_result, const char* success,  const char* failure);

void setup() {
  Serial.begin(BAUD);
  DEBUG_INFO("Setting things up...");

  try_setup(mot.setup(),       "Successfully set up motor.",          "Failed setting up motor.");
  try_setup(cal.setup(),       "Successfully set up scheduler.",      "Failed setting up scheduler.");
  try_setup(tasks_setup(),     "Successfully set up tasks.",          "Failed setting up tasks.");
  try_setup(ui.setup(),        "Successfully set up UI.",             "Failed setting up UI.");
  try_setup(interrupt_setup(), "Successfully set up interrupts.",     "Failed setting up interrupts.");
  try_setup(lim.setup(),       "Successfully set up limit switches.", "Failed setting up limit switches.");
  try_setup(callbacks_setup(), "Successfully set up callbacks.",      "Failed setting up callbacks.");
  // try_setup(lock.setup(),      "Successfully set up the lock." ,      "Failed setting up the lock.");

  DEBUG_INFO("Successfully set up all tasks.");
  DEBUG_INFO("\n");
}

void loop() {
  cal.tick();
}

void try_setup(bool setup_result, const char* success,  const char* failure) {
  if (!setup_result) {
    DEBUG_INFO("> %s", failure);
    while (true);
  } else {
    DEBUG_INFO("> %s", success);
  }
}
