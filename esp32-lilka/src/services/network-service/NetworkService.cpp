#include "NetworkService.h"

NetworkService::NetworkService() {}

String NetworkService::getURL(String suburl) {
    return (String(API_URL) + suburl).c_str();
}

String NetworkService::encodeURL(String str) {
    String encoded = "";
    char c;
    char code0;
    char code1;
    char code2;
    for (int i = 0; i < str.length(); i++) {
        c = str.charAt(i);
        if (isalnum(c)) {
            encoded += c;
        } else {
            encoded += '%';
            code1 = (c >> 4) & 0xF;
            code2 = c & 0xF;
            code1 += code1 > 9 ? 'A' - 10 : '0';
            code2 += code2 > 9 ? 'A' - 10 : '0';
            encoded += code1;
            encoded += code2;
        }
    }
  return encoded;
}

JsonDocument NetworkService::jsonify(String& response) {
    JsonDocument doc;
    DeserializationError error = deserializeJson(doc, response);
    if (error || (response.length() == 0)) {
        JsonDocument fallback;
        fallback["message"] = "network error";
        fallback.createNestedObject("data");
        return fallback;
    }
    return doc;
}

String NetworkService::getMessage(JsonDocument& doc) {
    return doc["message"];
}

JsonDocument NetworkService::getData(JsonDocument& doc) {
    return doc["data"];
}

JsonDocument NetworkService::get(String suburl) {
    HTTPClient http;
    String response = "";

    if (WiFi.status() != WL_CONNECTED) {
        return jsonify(response);
    }

    if (http.begin(getURL(suburl))) {
        int httpCode = http.GET();
        if (httpCode == HTTP_CODE_OK) {
            response = http.getString().c_str();
        }
        http.end();
    }
    return jsonify(response);
}

JsonDocument NetworkService::post(String suburl, JsonDocument &data) {
    HTTPClient http;
    String response = "";

    if (WiFi.status() != WL_CONNECTED) {
        return jsonify(response);
    }

    if (http.begin(getURL(suburl))) {
        String payload;
        serializeJson(data, payload);
        http.addHeader("Content-Type", "application/json");
        int httpCode = http.POST(payload);
        if (httpCode == HTTP_CODE_CREATED) {
            response = http.getString().c_str();
        }
        http.end();
    }
    return jsonify(response);
}

JsonDocument NetworkService::patch(String suburl, JsonDocument &data) {
    HTTPClient http;
    String response = "";

    if (WiFi.status() != WL_CONNECTED) {
        return jsonify(response);
    }

    if (http.begin(getURL(suburl))) {
        String payload;
        serializeJson(data, payload);
        http.addHeader("Content-Type", "application/json");
        int httpCode = http.POST(payload);
        if (httpCode == HTTP_CODE_CREATED) {
            response = http.getString().c_str();
        }
        http.end();
    }
    return jsonify(response);
}
