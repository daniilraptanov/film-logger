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

JsonDocument APIService::getTSC34725Settings() {
    JsonDocument result = networkService.get("/api/v1/sensors");
    JsonDocument data = networkService.getData(result);
    JsonDocument settings;
    JsonArray rows = data["rows"].as<JsonArray>();
    if (!rows.isNull() && rows.size() > 0) {
        JsonObject first = rows[0];
        settings["type"] = first["type"] | 0;
        settings["gain"] = first["gain"] | 0;
        settings["integrationTime"] = first["integrationTime"] | 0;
    }
    return settings;
}

JsonDocument APIService::getLoggingSettings() {
    JsonDocument result = networkService.get("/api/v1/logging");
    JsonDocument data = networkService.getData(result);
    return data;
}
