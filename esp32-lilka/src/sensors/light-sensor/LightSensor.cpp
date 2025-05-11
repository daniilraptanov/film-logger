#include <sensors/light-sensor/LightSensor.h>

LightSensor::LightSensor() : Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_101MS, TCS34725_GAIN_1X) {}

void LightSensor::begin() {
    if (!Adafruit_TCS34725::begin()) {
        Serial.println(F("TCS34725 is not initialized."));
        while (true);
    }
    Serial.println(F("TCS34725 found!"));
}

float LightSensor::getEV() {
    uint16_t r, g, b, c;
    getRawData(&r, &g, &b, &c);
    return log((calculateLux(r, g, b)) / (2.5)) / log(2);
}

float LightSensor::getCCT() {
    uint16_t r, g, b, c;
    getRawData(&r, &g, &b, &c);
    return calculateColorTemperature(r, g, b);
}

float LightSensor::calculateShutter(float &ev, int &iso, float &aperture) {
    return (pow(2, ev) * (iso / 100)) / pow(aperture, 2);
}


/*
    Use this method only in testing mode!
*/
void LightSensor::printToSerial() {
    uint16_t r, g, b, c;
    getRawData(&r, &g, &b, &c);
    
    Serial.print(F("Clear: "));
    Serial.print(c);

    Serial.print(F(";   Red: "));
    Serial.print(r);

    Serial.print(F(";   Green: "));
    Serial.print(g);

    Serial.print(F(";   Blue: "));
    Serial.print(b);

    Serial.print(F(";   Lux: "));
    Serial.print(calculateLux(r, g, b));
    
    Serial.println();
}
