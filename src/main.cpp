#include <button/Button.h>
#include <display/Display.h>
#include <film-settings/FilmSettings.h>

const int potPin1 = A0;
const int potPin2 = A1;
const int potPin3 = A2;

Display display;
FilmSettings filmSettings;

Button buttonUp(3);
Button buttonDown(4);
Button buttonAccept(5);

void setup() {
  Serial.begin(9600);
  Serial.println("Debug mode started...");

  display.begin();
  buttonUp.begin();
  buttonDown.begin();
  buttonAccept.begin();
}

void loop() {
  int potValue1 = analogRead(potPin1);
  int potValue2 = analogRead(potPin2);
  int potValue3 = analogRead(potPin3);

  int iso = filmSettings.mapISO(potValue1);
  int aperture = filmSettings.mapAperture(potValue2);
  int shutter = filmSettings.mapShutter(potValue3);

  if (buttonUp.wasPressed()) {
    Serial.println("Button was pressed.");
  }

  display.draw(iso, aperture, shutter, "Kodak Vision 3 500T", 451, 42, 7.65);

  delay(500);
}
