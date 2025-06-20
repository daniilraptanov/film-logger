#ifndef NETWORK_SERVICE_H
#define NETWORK_SERVICE_H

#include <string>
#include <WiFi.h>
#include <HTTPClient.h>
#include <.secrets.h>

class NetworkService {
    public:
        NetworkService();

        String get(String suburl);
        String post(String suburl, const std::string& data);
        String patch(String suburl, const std::string& data);
        String encodeURL(String str);

    private:
        String getURL(String suburl);
};

#endif
