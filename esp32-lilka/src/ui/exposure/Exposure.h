#ifndef EXPOSURE_H
#define EXPOSURE_H

#include <menu-component/MenuComponent.h>

enum class FL_Parameter {
    NONE,
    ISO,
    APERTURE,
};

class Exposure : protected MenuComponent {
    public:
        Exposure();
        void drawUI(lilka::Canvas *canvas);
        void handleParameters(lilka::State *state);
        int getISO();
        float getAperture();

    private:
        int ISO_VALUES[16] = {0, 15, 50, 100, 200, 250, 400, 500, 600, 800, 1000, 1200, 1600, 1800, 3200, 6400};
        float APERTURE_VALUES[12] = {0, 1.4, 2, 2.8, 3.5, 4, 5.6, 8, 11, 16, 22, 64};
        
        int ISO_SIZEOF = 16;
        int APERTURE_SIZEOF = 12;

        FL_Parameter selected;

        int isoIndex;
        int apertureIndex;

        int getNextIndex(int index, int maxIndex, bool buttonUp, bool buttonDown);
};

#endif
