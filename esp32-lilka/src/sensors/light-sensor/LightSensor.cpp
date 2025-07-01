#include <sensors/light-sensor/LightSensor.h>

LightSensor::LightSensor() : Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_101MS, TCS34725_GAIN_1X) {}

void LightSensor::begin() {
    if (!Adafruit_TCS34725::begin()) {
        Serial.println(F("TCS34725 is not initialized."));
        while (true);
    }
    Serial.println(F("TCS34725 found!"));
}

float LightSensor::getLux() {
    uint16_t r, g, b, c;
    getRawData(&r, &g, &b, &c);
    return calculateLux(r, g, b);
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

float LightSensor::calculateShutter(float ev, int iso, float aperture) {
    return (pow(2, ev) * (iso / 100)) / pow(aperture, 2);
}

float LightSensor::calculateRecommendedEV(int iso, float aperture, float shutter) {
    float numerator = shutter * pow(aperture, 2);
    float denominator = iso / 100;
    return log2(numerator / denominator);
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

bool LightSensor::applySettings(JsonDocument settings) {
    int type = settings["type"];
    if (type != SensorType::TCS34725) {
        return false;
    }
    
    int gain = settings["gain"].as<int>();
    int integrationTime = settings["gain"].as<int>();

    switch (gain) {
        case 1:
            setGain(TCS34725_GAIN_1X);
            break;
        case 4:
            setGain(TCS34725_GAIN_4X);
            break;
        case 16:
            setGain(TCS34725_GAIN_16X);
            break;
        case 60:
            setGain(TCS34725_GAIN_60X);
            break;
        default:
            setGain(TCS34725_GAIN_1X);
            break;
    }

    switch (integrationTime) {
        case 2:
            setIntegrationTime(TCS34725_INTEGRATIONTIME_2_4MS);
            break;
        case 24:
            setIntegrationTime(TCS34725_INTEGRATIONTIME_24MS);
            break;
        case 50:
            setIntegrationTime(TCS34725_INTEGRATIONTIME_50MS);
            break;
        case 60:
            setIntegrationTime(TCS34725_INTEGRATIONTIME_60MS);
            break;
        case 101:
            setIntegrationTime(TCS34725_INTEGRATIONTIME_101MS);
            break;
        case 120:
            setIntegrationTime(TCS34725_INTEGRATIONTIME_120MS);
            break;
        case 154:
            setIntegrationTime(TCS34725_INTEGRATIONTIME_154MS);
            break;
        case 180:
            setIntegrationTime(TCS34725_INTEGRATIONTIME_180MS);
            break;
        case 199:
            setIntegrationTime(TCS34725_INTEGRATIONTIME_199MS);
            break;
        case 240:
            setIntegrationTime(TCS34725_INTEGRATIONTIME_240MS);
            break;
        case 300:
            setIntegrationTime(TCS34725_INTEGRATIONTIME_300MS);
            break;
        case 360:
            setIntegrationTime(TCS34725_INTEGRATIONTIME_360MS);
            break;
        case 401:
            setIntegrationTime(TCS34725_INTEGRATIONTIME_401MS);
            break;
        case 420:
            setIntegrationTime(TCS34725_INTEGRATIONTIME_420MS);
            break;
        case 480:
            setIntegrationTime(TCS34725_INTEGRATIONTIME_480MS);
            break;
        case 499:
            setIntegrationTime(TCS34725_INTEGRATIONTIME_499MS);
            break;
        case 540:
            setIntegrationTime(TCS34725_INTEGRATIONTIME_540MS);
            break;
        case 600:
            setIntegrationTime(TCS34725_INTEGRATIONTIME_600MS);
            break;
        case 614:
            setIntegrationTime(TCS34725_INTEGRATIONTIME_614MS);
            break;
        default:
            setIntegrationTime(TCS34725_INTEGRATIONTIME_101MS);
            break;
    }
    
    return true;
}
