#include <fl-menu/FL_Menu.h>

FL_Menu::FL_Menu() : lilka::Menu("Вітаємо у Світогляді!") {}

void FL_Menu::begin() {
    addItem("Логер");
    addItem("Таймер");
    addItem("Мультиекспозиція");
    addItem("Магічні години");
}

void FL_Menu::drawMenu(lilka::Canvas *canvas) {
    while (!isFinished()) {
        update();
        draw(canvas);
        lilka::display.drawCanvas(canvas);
    }
    selected = true;
}

void FL_Menu::handleButtons(lilka::State *state) {
    if (state->start.justPressed) {
        selected = false;
    }
}

bool FL_Menu::isSelected() {
    return selected;
}

bool FL_Menu::isLogger() {
    int index = getCursor();
    return index == static_cast<int>(FL_Menu_Enum::LOGGER);
}

bool FL_Menu::isTimer() {
    int index = getCursor();
    return index == static_cast<int>(FL_Menu_Enum::TIMER);
}

bool FL_Menu::isMultiExposure() {
    int index = getCursor();
    return index == static_cast<int>(FL_Menu_Enum::MULTI_EXPOSURE);
}

bool FL_Menu::isMagicHours() {
    int index = getCursor();
    return index == static_cast<int>(FL_Menu_Enum::MAGIC_HOURS);
}


