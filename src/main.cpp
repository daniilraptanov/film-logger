#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void displayInterface(int iso, float aperture, int shutter, String film, int distance, int angle, float ev) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(0, 0);
  display.print("ISO:");
  display.print(iso);
  display.print(" F/");
  display.print(aperture, 1);
  display.print(" 1/");
  display.print(shutter);

  display.setCursor(0, 25);
  display.fillTriangle(6, 20, 2, 25, 10, 25, SSD1306_WHITE);
  display.setCursor(0, 30);
  display.fillTriangle(6, 40, 2, 35, 10, 35, SSD1306_WHITE);
  display.setCursor(20, 25);
  display.print(film);

  display.setCursor(0, 50);
  display.print(distance);
  display.print("cm  ");
  display.print(angle);
  display.print((char)247);
  display.print("  ");
  display.print(ev, 2);
  display.print("EV");

  display.display();
}

void setup() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    for (;;);
  }
  display.display();
  delay(2000);
  display.clearDisplay();

  displayInterface(3200, 2.8, 1000, "Ilford Delta 3200P", 277, 45, 7.65);
}

void loop() {
}
