#include "APIService.h"

APIService::APIService() {
    networkService = NetworkService();
}

String APIService::checkConnection() {
    return networkService.get(
        "/api/v1/system?data=" + networkService.encodeURL("Пристрій підключено до серверу")
    );
}
