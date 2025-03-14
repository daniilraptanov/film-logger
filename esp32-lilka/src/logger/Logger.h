#ifndef LOGGER_H
#define LOGGER_H

#include <menu-component/MenuComponent.h>

class Logger : protected MenuComponent {
    public:
        Logger();
        void drawUI(lilka::Canvas *canvas);
};

#endif
