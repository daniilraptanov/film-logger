#ifndef API_SERVICE_H
#define API_SERVICE_H

#include <services/network-service/NetworkService.h>

class APIService {
    public:
        APIService();
        String checkConnection();
        String exportRecords(JsonDocument &records);
        JsonDocument getTSC34725Settings();
        JsonDocument getLoggingSettings();

    private:
        NetworkService networkService;
        String handleStringApiResponse(JsonDocument &response);
};

#endif
