#include "APIService.h"

APIService::APIService() {
    networkService = NetworkService();
}

String APIService::checkConnection() {
    JsonDocument result = networkService.get(
        "/api/v1/system?data=" + networkService.encodeURL("Пристрій підключено до серверу")
    );
    Serial.println(networkService.getMessage(result));
    JsonDocument data = networkService.getData(result);
    
    if (data.is<JsonObject>() && data.size() == 0) {
        return "";
    }
    return data.as<String>();
}
