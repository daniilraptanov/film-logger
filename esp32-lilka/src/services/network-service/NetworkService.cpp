#include "NetworkService.h"

NetworkService::NetworkService() {}

String NetworkService::getURL(const __FlashStringHelper* suburl) {
    return (String(API_URL) + suburl).c_str();
}

String NetworkService::get(const __FlashStringHelper* suburl) {
    HTTPClient http;
    String response = "";

    if (WiFi.status() != WL_CONNECTED) {
        return response;
    }

    if (http.begin(getURL(suburl))) {
        int httpCode = http.GET();
        if (httpCode == HTTP_CODE_OK) {
            response = http.getString().c_str();
        }
        http.end();
    }
    return response;
}

String NetworkService::post(const __FlashStringHelper* suburl, const std::string& data) {
    HTTPClient http;
    String response = "";

    if (WiFi.status() != WL_CONNECTED) {
        return "";
    }

    if (http.begin(getURL(suburl))) {
        http.addHeader("Content-Type", "application/json");
        int httpCode = http.POST((uint8_t*)data.c_str(), data.length());
        if (httpCode == HTTP_CODE_OK) {
            response = http.getString().c_str();
        }
        http.end();
    }
    return response;
}

String NetworkService::patch(const __FlashStringHelper* suburl, const std::string& data) {
    HTTPClient http;
    String response = "";

    if (WiFi.status() != WL_CONNECTED) {
        return response;
    }

    if (http.begin(getURL(suburl))) {
        http.addHeader("Content-Type", "application/json");
        int httpCode = http.sendRequest("PATCH", (uint8_t*)data.c_str(), data.length());
        if (httpCode == HTTP_CODE_OK) {
            response = http.getString().c_str();
        }
        http.end();
    }
    return response;
}
