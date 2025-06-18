#include <ui/fl-menu/FL_Menu.h>

FL_Menu::FL_Menu() : lilka::Menu("Світогляд System") {}

void FL_Menu::begin() {
    addItem("Світлометрія");
    addItem("Експозиція");
    addItem("Мережа");
}

void FL_Menu::drawMenu(lilka::Canvas *canvas) {
    while (!isFinished()) {
        update();
        draw(canvas);
        lilka::display.drawCanvas(canvas);
    }
    selected = true;
}

void FL_Menu::setSelected(bool state) {
    selected = state;
}

bool FL_Menu::isSelected() {
    return selected;
}

bool FL_Menu::isLightMeter() {
    int index = getCursor();
    return index == static_cast<int>(FL_Menu_Enum::LIGHT_METER);
}

bool FL_Menu::isExposure() {
    int index = getCursor();
    return index == static_cast<int>(FL_Menu_Enum::EXPOSURE);
}

bool FL_Menu::isWiFiConfig() {
    int index = getCursor();
    return index == static_cast<int>(FL_Menu_Enum::WIFI_CONFIG);
}
