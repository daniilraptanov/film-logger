#ifndef NETWORK_SERVICE_H
#define NETWORK_SERVICE_H

#include <string>

class NetworkService {
public:
    NetworkService();

    std::string get(const std::string& url);
    std::string post(const std::string& url, const std::string& data);
    std::string patch(const std::string& url, const std::string& data);
};

#endif
