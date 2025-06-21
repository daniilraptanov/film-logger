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
        size_t columns = 7;

        LoggerMode mode = LoggerMode::SUSPENDED;

        String getHeader();
        String getColumnName(size_t index);
        void saveData(int &iso, float &aperture, float &shutter, float &lux, float &cct, float &ev);
};

#endif

