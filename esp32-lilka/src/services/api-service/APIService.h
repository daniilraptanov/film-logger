#ifndef API_SERVICE_H
#define API_SERVICE_H

#include <services/network-service/NetworkService.h>

class APIService {
    public:
        APIService();
        String checkConnection();

    private:
        NetworkService networkService;
};

#endif
