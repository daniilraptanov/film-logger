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

  display.draw(3200, 2.8, 1000, "Ilford Delta 3200P", 277, 45, 7.65);
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
  if (buttonDown.wasReleased()) {
    Serial.println("Button was released.");
  }

  delay(500);
}
