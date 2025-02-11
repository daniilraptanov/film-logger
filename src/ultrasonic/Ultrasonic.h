#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <Arduino.h>

class Ultrasonic {
    public:
        Ultrasonic(int trigPin, int echoPin);

        void begin();
        long getDistanceCM();

    private: 
        int trigPin;
        int echoPin;
};

#endif
