#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ui/UserInterface.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define I2C_ADDRESS 0x3C


const char isoText[] PROGMEM = "ISO ";
const char fText[] PROGMEM = "F";
const char shText[] PROGMEM = "1";
const char cmText[] PROGMEM = "cm  ";
const char evText[] PROGMEM = " EV";
const char cctText[] PROGMEM = " K";

class Display : protected Adafruit_SSD1306 {
    public:
        Display();

        void begin();
        void draw(FL_Parameter marked, FL_Parameter selected, int iso, float aperture, int shutter, int distance, float ev, float cct);

    private:
        void drawBoldText(const __FlashStringHelper* text, int x, int y, int bold);
        void drawUnderlinedText(const __FlashStringHelper* text, int x, int y);
};

#endif
