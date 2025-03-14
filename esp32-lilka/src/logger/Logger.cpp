#include <logger/Logger.h>

Logger::Logger() : MenuComponent() {}

void Logger::drawUI(lilka::Canvas *canvas) {
    drawCommonUI(canvas);

    // ISO, F-stop, Shutter
    // canvas->drawRect(10, 10, 80, 30, lilka::colors::White);
    canvas->setCursor(20, 30);
    canvas->setTextColor(lilka::colors::White);
    canvas->print(String("6400"));

    // canvas->drawRect(100, 10, 80, 30, lilka::colors::White);
    canvas->setCursor(110, 30);
    canvas->print(String("F/2.7"));

    // canvas->drawRect(190, 10, 80, 30, lilka::colors::White);
    canvas->setCursor(200, 30);
    canvas->print(String("1/1000"));

    // Film title
    // canvas->drawRect(10, 60, 260, 30, lilka::colors::White);
    canvas->setCursor(20, 80);
    canvas->print(String("<"));
    canvas->setCursor(40, 80);
    canvas->print(String("Kodak Vision3 500T"));
    canvas->setCursor(250, 80);
    canvas->print(String(">"));

    // Frame, Distance, Angle
    // canvas->drawRect(10, 110, 80, 30, lilka::colors::White);
    canvas->setCursor(20, 130);
    canvas->print(String("frame: 2"));

    // canvas->drawRect(100, 110, 80, 30, lilka::colors::White);
    canvas->setCursor(110, 130);
    canvas->print(String("42cm"));

    // canvas->drawRect(190, 110, 80, 30, lilka::colors::White);
    canvas->setCursor(200, 130);
    canvas->print(String("45 deg"));

    // EV, CCT
    // canvas->drawRect(10, 160, 130, 30, lilka::colors::White);
    canvas->setCursor(20, 180);
    canvas->print(String("EV: 7.45"));

    // canvas->drawRect(150, 160, 130, 30, lilka::colors::White);
    canvas->setCursor(160, 180);
    canvas->print(String("CCT: 5200K"));

    lilka::display.drawCanvas(canvas);
}
