#ifndef I2C_SCANNER_H
#define I2C_SCANNER_H

#include <Wire.h>
#include <Arduino.h>

class I2C_Scanner {
    public:
        I2C_Scanner();
        void scan();
};

#endif
