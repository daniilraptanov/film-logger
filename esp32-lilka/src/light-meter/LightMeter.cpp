#include <light-meter/LightMeter.h>

LightMeter::LightMeter() : MenuComponent() {}

void LightMeter::drawUI(lilka::Canvas *canvas) {
    drawCommonUI(canvas);

    canvas->setTextColor(lilka::colors::White);
    canvas->setCursor(30, 80);
    canvas->print(String("Ця функція у розробці."));
    
    lilka::display.drawCanvas(canvas);
}
