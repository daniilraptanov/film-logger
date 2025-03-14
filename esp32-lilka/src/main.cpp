#include <lilka.h>

void setup() {
  lilka::begin();
}

enum class FL_Menu {
  LOGGER,
  TIMER,
  MULTI_EXPOSURE,
  MAGIC_HOURS
};

void loop() {
    lilka::Canvas canvas;

    lilka::Menu FL_Menu("Вітаємо у Світогляді!");
    FL_Menu.addItem("Логер");
    FL_Menu.addItem("Таймер");
    FL_Menu.addItem("Мультиекспозиція");
    FL_Menu.addItem("Магічні години");
    while (!FL_Menu.isFinished()) {
        FL_Menu.update();
        FL_Menu.draw(&canvas);
        lilka::display.drawCanvas(&canvas);
    }
    int index = FL_Menu.getCursor();
    lilka::MenuItem item;
    FL_Menu.getItem(index, &item);
    Serial.println(String("Ви обрали пункт ") + item.title);
}
