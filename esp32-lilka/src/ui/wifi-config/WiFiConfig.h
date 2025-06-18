#ifndef WIFI_CONFIG_H
#define WIFI_CONFIG_H

#include <WiFi.h>
#include <lilka.h>
#include <.secrets.h>
#include <ui/menu-component/MenuComponent.h>

class WiFiConfig : protected MenuComponent {
    public:
        WiFiConfig();
        void drawUI(lilka::Canvas *canvas);
    
    private:
        void begin();
        int maxAttempts = 100;
};

#endif

