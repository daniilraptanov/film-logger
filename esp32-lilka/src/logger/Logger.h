#ifndef LOGGER_H
#define LOGGER_H

#include <lilka.h>
#include <SD.h>

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

    private:
        String fileName = "/fl_logs.csv";
        String dataSeparator = F(",");

        LoggerMode mode = LoggerMode::SUSPENDED;
        void saveData(int &iso, float &aperture, float &shutter, float &lux, float &cct, float &ev);
};

#endif

