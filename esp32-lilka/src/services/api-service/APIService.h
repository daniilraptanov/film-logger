#ifndef API_SERVICE_H
#define API_SERVICE_H

#include <services/network-service/NetworkService.h>

class APIService {
    public:
        APIService();
        String checkConnection();
        String exportRecords(JsonDocument &records);

    private:
        NetworkService networkService;
        String handleStringApiResponse(JsonDocument &response);
};

#endif
