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

void Display::drawUnderlinedText(const __FlashStringHelper* text, int x, int y) {
    Adafruit_SSD1306::setTextSize(1);
    Adafruit_SSD1306::setTextColor(SSD1306_WHITE);
    Adafruit_SSD1306::setCursor(x, y);
    Adafruit_SSD1306::print(text);

    int textWidth = strlen_P((PGM_P)text) * 4;
    int lineY = y + 8;

    Adafruit_SSD1306::drawLine(x, lineY, x + textWidth, lineY, SSD1306_WHITE);    
}

void Display::draw(FL_Parameter marked, FL_Parameter selected, int iso, float aperture, int shutter, const __FlashStringHelper* film, int distance, int angle, float ev) {
    Adafruit_SSD1306::clearDisplay();
    Adafruit_SSD1306::setCursor(0, 0);
    Adafruit_SSD1306::setTextColor(SSD1306_WHITE);
    Adafruit_SSD1306::setTextSize(2);
    

    if (selected == FL_ISO) {
        drawUnderlinedText(reinterpret_cast<const __FlashStringHelper*>(isoText), 0, 0);
    } else {
        drawBoldText(reinterpret_cast<const __FlashStringHelper*>(isoText), 0, 0, marked == FL_ISO ? 2 : 1);
    }
    Adafruit_SSD1306::print(iso);


    if (selected == FL_APERTURE) {
        drawUnderlinedText(reinterpret_cast<const __FlashStringHelper*>(fText), 80, 0);
    } else {
        drawBoldText(reinterpret_cast<const __FlashStringHelper*>(fText), 80, 0, marked == FL_APERTURE ? 2 : 1);
    }
    Adafruit_SSD1306::print((char)47);
    Adafruit_SSD1306::print(aperture, 1);


    if (selected == FL_SHUTTER) {
        drawUnderlinedText(reinterpret_cast<const __FlashStringHelper*>(shText), 0, 20);
    } else {
        drawBoldText(reinterpret_cast<const __FlashStringHelper*>(shText), 0, 20, marked == FL_SHUTTER ? 2 : 1);
    }
    Adafruit_SSD1306::print((char)47);
    Adafruit_SSD1306::print(shutter);

    // Adafruit_SSD1306::setCursor(0, 25);
    // Adafruit_SSD1306::fillTriangle(6, 20, 2, 25, 10, 25, SSD1306_WHITE);
    // Adafruit_SSD1306::setCursor(0, 30);
    // Adafruit_SSD1306::fillTriangle(6, 40, 2, 35, 10, 35, SSD1306_WHITE);
    // Adafruit_SSD1306::setCursor(15, 25);
    // Adafruit_SSD1306::print(film);

    Adafruit_SSD1306::setCursor(80, 20);
    Adafruit_SSD1306::print(distance);
    Adafruit_SSD1306::print(reinterpret_cast<const __FlashStringHelper*>(cmText));
    
    // Adafruit_SSD1306::print(angle);
    // Adafruit_SSD1306::print((char)247);
    
    Adafruit_SSD1306::setCursor(0, 40);
    Adafruit_SSD1306::print(ev, 2);
    Adafruit_SSD1306::print(reinterpret_cast<const __FlashStringHelper*>(evText));

    Adafruit_SSD1306::display();
}
