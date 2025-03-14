#ifndef MAGIC_HOURS_H
#define MAGIC_HOURS_H

#include <menu-component/MenuComponent.h>

class MagicHours : protected MenuComponent {
    public:
        MagicHours();
        void drawUI(lilka::Canvas *canvas);
};

#endif
