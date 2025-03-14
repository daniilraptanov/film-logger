#ifndef MULTI_EXPOSURE_H
#define MULTI_EXPOSURE_H

#include <menu-component/MenuComponent.h>

class MultiExposure : protected MenuComponent {
    public:
        MultiExposure();
        void drawUI(lilka::Canvas *canvas);
};

#endif
