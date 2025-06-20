#ifndef NETWORK_SERVICE_H
#define NETWORK_SERVICE_H

#include <string>
#include <WiFi.h>
#include <HTTPClient.h>
#include <.secrets.h>

class NetworkService {
    public:
        NetworkService();

        String get(const __FlashStringHelper* suburl);
        String post(const __FlashStringHelper* suburl, const std::string& data);
        String patch(const __FlashStringHelper* suburl, const std::string& data);

    private:
        String getURL(const __FlashStringHelper* suburl);
};

#endif
