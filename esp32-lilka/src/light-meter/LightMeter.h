#ifndef LIGHT_METER_H
#define LIGHT_METER_H

#include <menu-component/MenuComponent.h>

class LightMeter : protected MenuComponent {
    public:
        LightMeter();
        void drawUI(lilka::Canvas *canvas);
};

#endif
