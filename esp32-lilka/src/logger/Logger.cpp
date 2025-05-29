#include <logger/Logger.h>

Logger::Logger() {}

void Logger::begin() {
    if (!SD.begin(4)) {
        Serial.println(F("SD card is not initialized."));
        while (true);
    }
    Serial.println(F("Device is ready to log."));

    File file = SD.open(fileName, FILE_APPEND);
    if (!file) {
        Serial.println(F("Failed to open file..."));
    };
    file.println("iso" + dataSeparator + "aperture" + dataSeparator + "shutter" + dataSeparator + "lux" + dataSeparator + "cct" + dataSeparator + "ev");
    file.close();
}

void Logger::handleLogging(lilka::State *state, int &iso, float &aperture, float &shutter, float &lux, float &cct, float &ev) {
    if (state->c.justPressed && mode == LoggerMode::STREAM) {
        mode = LoggerMode::SUSPENDED;
        return;
    }
    if (state->d.justPressed && mode == LoggerMode::SINGLE) {
        mode = LoggerMode::SUSPENDED;
        return;
    }
    
    if (state->c.justPressed || mode == LoggerMode::STREAM) {
        mode = LoggerMode::STREAM;
        saveData(iso, aperture, shutter, lux, cct, ev);

        Serial.println("saved in a stream mode");

    } else if (state->d.justPressed && mode == LoggerMode::SUSPENDED) {
        mode = LoggerMode::SINGLE;
        saveData(iso, aperture, shutter, lux, cct, ev);

        Serial.println("saved in a single mode");
    }
}

void Logger::saveData(int &iso, float &aperture, float &shutter, float &lux, float &cct, float &ev) {
    File file = SD.open(fileName, FILE_APPEND);
    if (!file) {
        Serial.println(F("Failed to log data..."));
    };
    file.println(iso + dataSeparator + aperture + dataSeparator + shutter + dataSeparator + lux + dataSeparator + cct + dataSeparator + ev);
    file.close();
}
