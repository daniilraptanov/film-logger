#include "APIService.h"

APIService::APIService() {
    networkService = NetworkService();
}

String APIService::checkConnection() {
    JsonDocument result = networkService.get(
        "/api/v1/system?data=" + networkService.encodeURL("Пристрій підключено до серверу")
    );
    Serial.println(networkService.getMessage(result));
    return networkService.getData(result).as<String>();
}
