#ifndef LOGGER_H
#define LOGGER_H

#include <lilka.h>
#include <SD.h>
#include <ArduinoJson.h>

enum class LoggerMode {
    SUSPENDED,
    SINGLE,
    STREAM,
};

class Logger {
    public:
        Logger();
        void begin();
        void handleLogging(lilka::State *state, int &iso, float &aperture, float &shutter, float &lux, float &cct, float &ev);
        JsonDocument readRecords(size_t limit);

    private:
        String fileName = "/fl_logs.csv";
        String dataSeparator = F(",");

        const char* columnNames[8] = {"id", "iso", "aperture", "shutter", "lux", "cct", "ev", "synced"};
        size_t columns = sizeof(columnNames) / sizeof(columnNames[0]);

        LoggerMode mode = LoggerMode::SUSPENDED;

        String getHeader();
        String getColumnName(size_t index);
        String generateUUIDv4();
        void saveData(int &iso, float &aperture, float &shutter, float &lux, float &cct, float &ev);
};

#endif

