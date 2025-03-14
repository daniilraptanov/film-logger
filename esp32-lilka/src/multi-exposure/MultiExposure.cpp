#include <multi-exposure/MultiExposure.h>

MultiExposure::MultiExposure() : MenuComponent() {}

void MultiExposure::drawUI(lilka::Canvas *canvas) {
    drawCommonUI(canvas);

    canvas->setTextColor(lilka::colors::White);
    canvas->setCursor(30, 80);
    canvas->print(String("Ця функція у розробці."));
    
    lilka::display.drawCanvas(canvas);
}
