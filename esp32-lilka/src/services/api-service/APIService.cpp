#include "APIService.h"

APIService::APIService() {
    networkService = NetworkService();
}

String APIService::handleStringApiResponse(JsonDocument &response) {
    Serial.println(networkService.getMessage(response));
    JsonDocument data = networkService.getData(response);
    
    if (data.is<JsonObject>() && data.size() == 0) {
        return "";
    }
    return data.as<String>();
}

String APIService::checkConnection() {
    JsonDocument result = networkService.get(
        "/api/v1/system?data=" + networkService.encodeURL("Пристрій підключено до серверу")
    );
    return handleStringApiResponse(result);
}

String APIService::exportRecords(JsonDocument &records) {
    JsonDocument payload;
    payload["data"] = records;
    JsonDocument result = networkService.post("/api/v1/light-records/import", payload);
    return handleStringApiResponse(result);
}

