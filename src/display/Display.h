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

// enum Parameters {
//     ISO = 1,
//     APERTURE = 2,
//     SHUTTER = 3,
//     FILM = 4,
//     DISTANCE = 5,
//     ANGLE = 6,
//     EXPOSURE_VALUE = 7,
// };

class Display : public Adafruit_SSD1306 {
    // private:
        // Parameters selected;

    public:
        Display();

        void begin();
        void draw(int iso, float aperture, int shutter, String film, int distance, int angle, float ev);
};

#endif
