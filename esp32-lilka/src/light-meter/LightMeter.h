#ifndef LIGHT_METER_H
#define LIGHT_METER_H

#include <menu-component/MenuComponent.h>

class LightMeter : protected MenuComponent {
    public:
        LightMeter();
        void drawUI(lilka::Canvas *canvas);

    private:
        void drawGradientLuxBar(lilka::Canvas *canvas);
        void drawGradientKelvinBar(lilka::Canvas *canvas);
        void drawCrosshair(lilka::Canvas *canvas, int luxY, int kelX);

        float mapLuxToY(float lux);
        float mapKelvinToX(float kelvin);
};

#endif
