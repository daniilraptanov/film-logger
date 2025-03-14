#ifndef FL_MENU_H
#define FL_MENU_H

#include <lilka.h>

enum class FL_Menu_Enum {
    LOGGER,
    TIMER,
    MULTI_EXPOSURE,
    MAGIC_HOURS
};
  

class FL_Menu : private lilka::Menu {
    public:
        FL_Menu();
        void begin();
        void drawMenu(lilka::Canvas *canvas);
        void handleButtons();
        bool isSelected();
        bool isLogger();

    private:
        lilka::Canvas *canvas;
        bool selected;
};

#endif
