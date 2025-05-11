#ifndef LIGHT_METER_H
#define LIGHT_METER_H

#include <ui/menu-component/MenuComponent.h>

class LightMeter : protected MenuComponent {
    public:
        LightMeter();
        void drawUI(lilka::Canvas *canvas, float lux, float cct);

    private:
        void drawGradientLuxBar(lilka::Canvas *canvas);
        void drawGradientKelvinBar(lilka::Canvas *canvas);
        void drawCrosshair(lilka::Canvas *canvas, int luxY, int kelX, int lux, int kelvin);

        int mapLuxToY(float lux);
        int mapKelvinToX(float kelvin);
};

#endif
