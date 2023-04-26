// Casey Walker (2023)
// 24-671 Electromechanical Systems Design
// Carnegie Mellon University
// -------------------------------------------------------------------------- //

#include <Arduino_DebugUtils.h>

#include "ui.h"

UI::UI() {
  LiquidCrystal_PCF8574 _lcd(UI_LCD_ADDR);
  
  Button raise(UI_PIN_RAISE, UI_PRESSED_STATE);
  Button split(UI_PIN_SPLIT, UI_PRESSED_STATE);
}

bool UI::setup() {
  // verify I2C comm connection
  // Wire.begin();
  // Wire.beginTransmission(0x27);
  // uint8_t result = Wire.endTransmission();
  // if (result != 0) return false;
  
  // _lcd.begin(UI_LCD_COLS, UI_LCD_ROWS);

  // _lcd.createChar(1, dotOff);
  // _lcd.createChar(2, dotOn);

  raise.setup();
  split.setup();

  return true;
}

void UI::set_button_triggered() {
  _button_triggered = true;
}

void UI::update() {
  if (_button_triggered) {
    raise.toggle();
    split.toggle();

    _button_triggered = false;
  }
}

/*
void loop() {
  if (show == 0) {
    lcd.setBacklight(255);
    lcd.home();
    lcd.clear();
    lcd.print("Hello LCD");
    delay(1000);

    lcd.setBacklight(0);
    delay(400);
    lcd.setBacklight(255);

  } else if (show == 1) {
    lcd.clear();
    lcd.print("Cursor On");
    lcd.cursor();

  } else if (show == 2) {
    lcd.clear();
    lcd.print("Cursor Blink");
    lcd.blink();

  } else if (show == 3) {
    lcd.clear();
    lcd.print("Cursor OFF");
    lcd.noBlink();
    lcd.noCursor();

  } else if (show == 4) {
    lcd.clear();
    lcd.print("Display Off");
    lcd.noDisplay();

  } else if (show == 5) {
    lcd.clear();
    lcd.print("Display On");
    lcd.display();

  } else if (show == 7) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("*** first line.");
    lcd.setCursor(0, 1);
    lcd.print("*** second line.");

  } else if (show == 8) {
    lcd.scrollDisplayLeft();
  } else if (show == 9) {
    lcd.scrollDisplayLeft();
  } else if (show == 10) {
    lcd.scrollDisplayLeft();
  } else if (show == 11) {
    lcd.scrollDisplayRight();

  } else if (show == 12) {
    lcd.clear();
    lcd.print("write-");

  } else if (show == 13) {
    lcd.clear();
    lcd.print("custom 1:<\01>");
    lcd.setCursor(0, 1);
    lcd.print("custom 2:<\02>");

  } else {
    lcd.print(show - 13);
  }  // if

  delay(1400);
  show = (show + 1) % 16;
}  // loop()
*/
