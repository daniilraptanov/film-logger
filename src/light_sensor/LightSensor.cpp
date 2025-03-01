#include <light_sensor/LightSensor.h>

LightSensor::LightSensor() : Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_154MS, TCS34725_GAIN_4X) {}

void LightSensor::begin() {
    if (!Adafruit_TCS34725::begin()) {
        Serial.println("TCS34725 is not initialized.");
        while (true);
    }
    Serial.println("TCS34725 found!");
}

//   uint16_t r, g, b, c;
//   tcs.getRawData(&r, &g, &b, &c);
//   Serial.print("R: "); Serial.print(r);
//   Serial.print(" G: "); Serial.print(g);
//   Serial.print(" B: "); Serial.print(b);
//   Serial.print(" C: "); Serial.println(c);

