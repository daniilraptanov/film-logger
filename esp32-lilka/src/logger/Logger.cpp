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
    if (file && file.size() == 0) {
        file.println(getHeader());
    }
    file.close();
}

String Logger::getHeader() {
    String header;
    for (size_t i = 0; i < columns; ++i) {
        header += columnNames[i];
        if (i < columns - 1) {
            header += dataSeparator;
        }
    }
    return header;
}

String Logger::getColumnName(size_t index) {
    if (index < columns) {
        return columnNames[index];
    }
    return "";
}

void Logger::handleLogging(lilka::State *state, int &iso, float &aperture, float &shutter, float &lux, float &cct, float &ev) {
    if (state->c.justPressed && mode == LoggerMode::STREAM) {
        mode = LoggerMode::SUSPENDED;
        lilka::buzzer.play(lilka::NOTE_A4, 100);
        return;
    }
    if (state->c.justPressed && mode == LoggerMode::SUSPENDED) {
        mode = LoggerMode::STREAM;
        lilka::buzzer.play(lilka::NOTE_A7, 300);
    }
    
    if (mode == LoggerMode::STREAM) {
        saveData(iso, aperture, shutter, lux, cct, ev);

        Serial.println("saved in a stream mode");

    } else if (state->d.justPressed && mode == LoggerMode::SUSPENDED) {
        mode = LoggerMode::SINGLE;
        saveData(iso, aperture, shutter, lux, cct, ev);
        lilka::buzzer.play(lilka::NOTE_A4, 100);

        Serial.println("saved in a single mode");
        mode = LoggerMode::SUSPENDED;
    }
}

void Logger::saveData(int &iso, float &aperture, float &shutter, float &lux, float &cct, float &ev) {
    File file = SD.open(fileName, FILE_APPEND);
    if (!file) {
        Serial.println(F("Failed to log data..."));
    };
    file.println(
        iso + dataSeparator + 
        aperture + dataSeparator + 
        shutter + dataSeparator + 
        lux + dataSeparator + 
        cct + dataSeparator + 
        ev + dataSeparator +
        0
    );
    file.close();
}

JsonDocument Logger::readRecords(size_t limit) {
    File file = SD.open(fileName, FILE_READ);
    JsonDocument doc;
    JsonArray array = doc.to<JsonArray>();

    if (!file) {
        Serial.println(F("Failed to read data..."));
        return doc;
    };


    size_t count = 0;
    String line;
    while (file.available() && (limit == 0 || count < limit)) {
        line = file.readStringUntil('\n');
        line.trim();

        if ((line.length() == 0) || (line == getHeader())) continue;

        JsonObject row;
        int lastIndex = 0;
        int sepIndex = 0;
        for (int i = 0; i < columns; ++i) {
            sepIndex = line.indexOf(dataSeparator, lastIndex);
            String value;
            if (sepIndex == -1) {
            value = line.substring(lastIndex);
            } else {
            value = line.substring(lastIndex, sepIndex);
            lastIndex = sepIndex + dataSeparator.length();
            }
            row[getColumnName(i)] = value;
            array.add(row);
        }
        count++;
    }

    file.close();
    return doc;
}

