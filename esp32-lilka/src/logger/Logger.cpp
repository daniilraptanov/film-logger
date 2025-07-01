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
    if (file.size() == 0) {
        file.println(getHeader());
    }
    file.close();
}

bool Logger::synced(String &columnName, String &value) {
    return columnName == "synced" && value == "1";
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

String Logger::generateUUIDv4() {
    uint8_t uuid[16];

    // Fill with random bytes
    for (int i = 0; i < 16; i++) {
        uuid[i] = (uint8_t)esp_random();
    }

    // Set version: UUID (4) — bits 12-15 from 7th byte
    uuid[6] = (uuid[6] & 0x0F) | 0x40;

    // Set variant UUID — bits 6-7 from 9th byte
    uuid[8] = (uuid[8] & 0x3F) | 0x80;

    // Format to UUID string
    char uuid_str[37];
    sprintf(uuid_str,
        "%02x%02x%02x%02x-"
        "%02x%02x-"
        "%02x%02x-"
        "%02x%02x-"
        "%02x%02x%02x%02x%02x%02x",
        uuid[0], uuid[1], uuid[2], uuid[3],
        uuid[4], uuid[5],
        uuid[6], uuid[7],
        uuid[8], uuid[9],
        uuid[10], uuid[11], uuid[12], uuid[13], uuid[14], uuid[15]
    );

    return String(uuid_str);
}

void Logger::pauseStream() {
    if (mode == LoggerMode::STREAM) {
        // TODO :: use millis instead delay
        delay(streamIntervalSec * 1000);
    }
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

    pauseStream();
}

void Logger::saveData(int &iso, float &aperture, float &shutter, float &lux, float &cct, float &ev) {
    File file = SD.open(fileName, FILE_APPEND);
    if (!file) {
        Serial.println(F("Failed to log data..."));
    };
    file.println(
        generateUUIDv4() + dataSeparator +
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

        int lastIndex = 0;
        int sepIndex = 0;
        bool skipRow = false;
        String values[columns];

        for (int i = 0; i < columns; ++i) {
            sepIndex = line.indexOf(dataSeparator, lastIndex);
            if (sepIndex == -1) {
                values[i] = line.substring(lastIndex);
            } else {
                values[i] = line.substring(lastIndex, sepIndex);
                lastIndex = sepIndex + dataSeparator.length();
            }
        }

        for (int i = 0; i < columns; ++i) {
            String columnName = getColumnName(i);
            if (synced(columnName, values[i])) {
                skipRow = true;
                break;
            }
        }
        if (skipRow) continue;

        JsonObject row = array.createNestedObject();
        for (int i = 0; i < columns; ++i) {
            row[getColumnName(i)] = values[i];
        }
        count++;
    }

    file.close();
    return doc;
}

bool Logger::markAsSynced(size_t limit) {
    File file = SD.open(fileName, FILE_READ);
    if (!file) {
        Serial.println(F("Failed to open file for reading..."));
        return false;
    }

    String tempFileName = String(fileName) + ".tmp";
    File tempFile = SD.open(tempFileName.c_str(), FILE_WRITE);
    if (!tempFile) {
        Serial.println(F("Failed to open temp file for writing..."));
        file.close();
        return false;
    }

    tempFile.println(getHeader());

    size_t count = 0;
    String line;
    while (file.available()) {
        line = file.readStringUntil('\n');
        line.trim();

        if ((line.length() == 0) || (line == getHeader())) {
            continue;
        }

        int lastSep = line.lastIndexOf(dataSeparator);
        if (lastSep == -1) {
            tempFile.println(line);
        } else {
            String syncedValue = line.substring(lastSep + 1);
            if (syncedValue != "1" && (limit == 0 || count < limit)) {
                line = line.substring(0, lastSep + 1) + "1";
                count++;
            }
            tempFile.println(line);
        }
    }

    file.close();
    tempFile.close();

    SD.remove(fileName);
    SD.rename(tempFileName.c_str(), fileName);

    return (limit == 0) || (count == limit);
}

size_t Logger::countUnsyncedRecords() {
    File file = SD.open(fileName, FILE_READ);
    if (!file) {
        Serial.println(F("Failed to open file for reading..."));
        return 0;
    }

    size_t count = 0;
    String line;
    while (file.available()) {
        line = file.readStringUntil('\n');
        line.trim();

        if ((line.length() == 0) || (line == getHeader())) continue;

        int lastSep = line.lastIndexOf(dataSeparator);
        if (lastSep == -1) continue;

        String syncedValue = line.substring(lastSep + 1);
        if (syncedValue != "1") {
            count++;
        }
    }

    file.close();
    return count;
}

bool Logger::applySettings(JsonDocument settings) {
    streamIntervalSec = settings["streamIntervalSec"] | 0;
    return true;
}
