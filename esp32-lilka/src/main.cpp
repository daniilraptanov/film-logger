#include <lilka.h>
#include <fl-menu/FL_Menu.h>
#include <logger/Logger.h>

FL_Menu menu;
Logger logger;

void setup() {
    lilka::begin();
    menu.begin();
}


void loop() {
    lilka::Canvas canvas;
    if (!menu.isSelected()) {
        menu.drawMenu(&canvas);
    }
    if (menu.isLogger()) {
        logger.drawUI(&canvas);
    }
    menu.handleButtons();
}
