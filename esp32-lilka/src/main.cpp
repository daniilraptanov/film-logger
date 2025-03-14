#include <lilka.h>
#include <fl-menu/FL_Menu.h>
#include <logger/Logger.h>
#include <timer/Timer.h>
#include <multi-exposure/MultiExposure.h>
#include <magic-hours/MagicHours.h>

FL_Menu menu;
Logger logger;
Timer timer;
MultiExposure multiExposure;
MagicHours magicHours;

void setup() {
    lilka::begin();
    menu.begin();
}


void loop() {
    lilka::Canvas canvas;
    if (!menu.isSelected()) {
        menu.drawMenu(&canvas);
    }
    else if (menu.isLogger()) {
        logger.drawUI(&canvas);
    }
    else if (menu.isTimer()) {
        timer.drawUI(&canvas);
    }
    else if (menu.isMultiExposure()) {
        multiExposure.drawUI(&canvas);
    }
    else if (menu.isMagicHours()) {
        magicHours.drawUI(&canvas);
    }
    menu.handleButtons();
}
