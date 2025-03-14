#ifndef TIMER_H
#define TIMER_H

#include <menu-component/MenuComponent.h>

class Timer : protected MenuComponent {
    public:
        Timer();
        void drawUI(lilka::Canvas *canvas);
};

#endif
