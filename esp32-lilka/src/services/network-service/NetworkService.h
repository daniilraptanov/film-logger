#ifndef NETWORK_SERVICE_H
#define NETWORK_SERVICE_H

#include <string>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <.secrets.h>

class NetworkService {
    public:
        NetworkService();

        JsonDocument get(String suburl);
        JsonDocument post(String suburl, const std::string& data);
        JsonDocument patch(String suburl, const std::string& data);
        
        String encodeURL(String str);
        String getMessage(JsonDocument& doc);
        JsonDocument getData(JsonDocument& doc);

    private:
        String getURL(String suburl);
        JsonDocument jsonify(String& response);
};

#endif
