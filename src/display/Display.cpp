#include "Display.h"
#include <avr/pgmspace.h>

Display::Display() : Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET) {}

void Display::begin() {
    if (!Adafruit_SSD1306::begin(SSD1306_SWITCHCAPVCC, I2C_ADDRESS)) {
        Serial.println("Display is not initialized.");
        while (true);
    }

    Adafruit_SSD1306::clearDisplay();
    delay(2000);
    Adafruit_SSD1306::display();
}

void drawBoldText(Adafruit_SSD1306 &display, int x, int y, const char *text, int boldness) {
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    
    for (int dx = 0; dx < boldness; dx++) {
        for (int dy = 0; dy < boldness; dy++) {
            display.setCursor(x + dx, y + dy);
            display.print(text);
        }
    }
}

void Display::drawBoldText(const __FlashStringHelper* text, int x, int y, int bold) {
    Adafruit_SSD1306::setTextSize(1);
    Adafruit_SSD1306::setTextColor(SSD1306_WHITE);
    
    for (int dx = 0; dx < bold; dx++) {
        for (int dy = 0; dy < bold; dy++) {
            Adafruit_SSD1306::setCursor(x + dx, y + dy);
            Adafruit_SSD1306::print(text);
        }
    }
}

void Display::draw(FL_Parameter currentFL, int iso, float aperture, int shutter, const __FlashStringHelper* film, int distance, int angle, float ev) {
    Adafruit_SSD1306::clearDisplay();
    Adafruit_SSD1306::setCursor(0, 0);
    Adafruit_SSD1306::setTextColor(SSD1306_WHITE);
    Adafruit_SSD1306::setTextSize(1);
    

    drawBoldText(reinterpret_cast<const __FlashStringHelper*>(isoText), 0, 0, currentFL == FL_ISO ? 2 : 1);
    Adafruit_SSD1306::print(iso);

    drawBoldText(reinterpret_cast<const __FlashStringHelper*>(fText), 45, 0, currentFL == FL_APERTURE ? 2 : 1);
    Adafruit_SSD1306::print((char)47);
    Adafruit_SSD1306::print(aperture, 1);

    drawBoldText(reinterpret_cast<const __FlashStringHelper*>(oneText), 85, 0, currentFL == FL_SHUTTER ? 2 : 1);
    Adafruit_SSD1306::print((char)47);
    Adafruit_SSD1306::print(shutter);

    Adafruit_SSD1306::setCursor(0, 25);
    Adafruit_SSD1306::fillTriangle(6, 20, 2, 25, 10, 25, SSD1306_WHITE);
    Adafruit_SSD1306::setCursor(0, 30);
    Adafruit_SSD1306::fillTriangle(6, 40, 2, 35, 10, 35, SSD1306_WHITE);
    Adafruit_SSD1306::setCursor(15, 25);
    Adafruit_SSD1306::print(film);

    Adafruit_SSD1306::setCursor(0, 50);
    Adafruit_SSD1306::print(distance);
    Adafruit_SSD1306::print(reinterpret_cast<const __FlashStringHelper*>(cmText));
    Adafruit_SSD1306::print(angle);
    Adafruit_SSD1306::print((char)247);
    Adafruit_SSD1306::print(F("  "));
    Adafruit_SSD1306::print(ev, 2);
    Adafruit_SSD1306::print(reinterpret_cast<const __FlashStringHelper*>(evText));

    Adafruit_SSD1306::display();
}
