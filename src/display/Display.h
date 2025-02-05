#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define I2C_ADDRESS 0x3C


const char isoText[] PROGMEM = "ISO:";
const char fText[] PROGMEM = " F";
const char oneText[] PROGMEM = " 1";
const char cmText[] PROGMEM = "cm  ";
const char evText[] PROGMEM = " EV";

class Display : public Adafruit_SSD1306 {
    // private:
        // Parameters selected;

    public:
        Display();

        void begin();
        void draw(int iso, float aperture, int shutter, const char* film, int distance, int angle, float ev);
};

#endif
