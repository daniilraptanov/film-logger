#ifndef WIFI_CONFIG_H
#define WIFI_CONFIG_H

#include <WiFi.h>
#include <lilka.h>
#include <.secrets.h>
#include <ui/menu-component/MenuComponent.h>
#include <services/api-service/APIService.h>
#include <logger/Logger.h>
#include <sensors/light-sensor/LightSensor.h>

class WiFiConfig : protected MenuComponent {
    public:
        WiFiConfig();
        void drawUI(lilka::Canvas *canvas, Logger &logger);
    
    private:
        int maxAttempts = 100;
        bool connectionChecked = false;
        void begin();
        String syncData();
        String initConnection(Logger &logger);
        String updateHardware(Logger &logger);
};

#endif

