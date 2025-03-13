#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class Button {
    private:
        uint8_t pin;
        bool state;
        unsigned long debounceDelay;
        unsigned long lastDebounceDelay;

    public:
        Button(uint8_t pin, unsigned long debounceDelay = 10);

        void begin();
        bool isPressed();
        bool wasPressed();
        bool wasReleased();
};

#endif
