#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <Adafruit_SSD1306.h>


// enum Parameters {
//     ISO = 1,
//     APERTURE = 2,
//     SHUTTER = 3,
//     FILM = 4,
//     DISTANCE = 5,
//     ANGLE = 6,
//     EXPOSURE_VALUE = 7,
// };

class Display {
    private:
        // Parameters selected;
        Adafruit_SSD1306 display;

    public:
        Display();

        void begin();
        void draw(int iso, float aperture, int shutter, String film, int distance, int angle, float ev);
};

#endif
