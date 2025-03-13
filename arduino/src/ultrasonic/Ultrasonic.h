#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <Arduino.h>

class Ultrasonic {
    public:
        Ultrasonic(int trigPin, int echoPin, int measurementsCount);

        void begin();
        long getDistanceCM();
        long getFilteredDistanceCM();

    private: 
        int trigPin;
        int echoPin;
        int measurementsCount;
};

#endif
