// Casey Walker (2023)
// 24-671 Electromechanical Systems Design
// Carnegie Mellon University
// -------------------------------------------------------------------------- //
//
// ui.h
// for displaying to LCD and handling UI buttons
//

#ifndef EMSD_UI_H
#define EMSD_UI_H

#include <Arduino.h>

#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>

#include "rup.h"
#include "button.h"

#define UI_LCD_ADDR 0x27
#define UI_LCD_ROWS 2
#define UI_LCD_COLS 16

#define UI_PIN_RAISE RUP1
#define UI_PIN_SPLIT RUP2

#define UI_RUPMODE_RAISE CHANGE
#define UI_RUPMODE_SPLIT CHANGE

#define UI_RUP_RAISE digitalPinToInterrupt(UI_PIN_RAISE)
#define UI_RUP_SPLIT digitalPinToInterrupt(UI_PIN_SPLIT)

#define UI_PRESSED_STATE HIGH

// // Custom characters
// byte dotOff[] = { 0b00000, 0b01110, 0b10001, 0b10001,
//                   0b10001, 0b01110, 0b00000, 0b00000 };
// byte dotOn[] = { 0b00000, 0b01110, 0b11111, 0b11111,
//                  0b11111, 0b01110, 0b00000, 0b00000 };

class UI {
  private:
    LiquidCrystal_PCF8574 _lcd;
    bool _button_triggered;
  public:
    Button raise;
    Button split;

    UI();
    bool setup();
    void set_button_triggered();
    void update();
};

#endif // EMSD_UI_H
