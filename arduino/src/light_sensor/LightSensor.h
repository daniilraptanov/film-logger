#ifndef LIGHT_SENSOR_H
#define LIGHT_SENSOR_H

#include <Wire.h>
#include <Arduino.h>
#include "Adafruit_TCS34725.h"

class LightSensor : protected Adafruit_TCS34725 {
    public:
        LightSensor();
        void begin();
        float getEV();
        float getCCT();
        float calculateShutter(float &ev, int &iso, float &aperture);
        void printToSerial();
};

#endif

