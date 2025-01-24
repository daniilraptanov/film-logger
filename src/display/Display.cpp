#include "Display.h"

Display::Display() {
    Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
};

void Display::begin() {
    if (!oled.begin(SSD1306_SWITCHCAPVCC, I2C_ADDRESS)) {
        Serial.println("Display is not initialized.");
        while (true);
    }
    oled.clearDisplay();
    delay(2000);
    oled.display();
}

void Display::draw(int iso, float aperture, int shutter, String film, int distance, int angle, float ev) {
    oled.clearDisplay();
    oled.setTextSize(1);
    oled.setTextColor(SSD1306_WHITE);

    oled.setCursor(0, 0);
    oled.print("ISO:");
    oled.print(iso);
    oled.print(" F/");
    oled.print(aperture, 1);
    oled.print(" 1/");
    oled.print(shutter);

    oled.setCursor(0, 25);
    oled.fillTriangle(6, 20, 2, 25, 10, 25, SSD1306_WHITE);
    oled.setCursor(0, 30);
    oled.fillTriangle(6, 40, 2, 35, 10, 35, SSD1306_WHITE);
    oled.setCursor(20, 25);
    oled.print(film);

    oled.setCursor(0, 50);
    oled.print(distance);
    oled.print("cm  ");
    oled.print(angle);
    oled.print((char)247);
    oled.print("  ");
    oled.print(ev, 2);
    oled.print("EV");

    oled.display();
}

