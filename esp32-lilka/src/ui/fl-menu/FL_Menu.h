#ifndef FL_MENU_H
#define FL_MENU_H

#include <lilka.h>

enum class FL_Menu_Enum {
    LIGHT_METER,
    EXPOSURE,
    WIFI_CONFIG,
};
  

class FL_Menu : private lilka::Menu {
    public:
        FL_Menu();
        void begin();
        void drawMenu(lilka::Canvas *canvas);
        void setSelected(bool state);
        bool isSelected();

        bool isLightMeter();
        bool isExposure();
        bool isWiFiConfig();

    private:
        lilka::Canvas *canvas;
        bool selected;
};

#endif
