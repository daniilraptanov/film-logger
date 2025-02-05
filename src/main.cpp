#include <button/Button.h>
#include <display/Display.h>
#include <ui/UserInterface.h>

#include <MemoryFree.h>

const int potPin1 = A0;
const int potPin2 = A1;
const int potPin3 = A2;

UserInterface ui;
Display display;

Button buttonUp(4);
Button buttonDown(5);
Button buttonAccept(6);

void setup() {
  Serial.begin(9600);
  Serial.println("Debug mode started...");

  display.begin();
  buttonUp.begin();
  buttonDown.begin();
  buttonAccept.begin();

  // Serial.print("Free memory after initialization: ");
  // Serial.println(freeMemory());
}

void loop() {
  ui.handleUI(buttonUp.wasPressed(), buttonDown.wasPressed(), buttonAccept.wasPressed());
  display.draw(ui.getISO(), ui.getAperture(), ui.getShutter(), "Kodak Vision3 500T", 451, 42, 7.65);
  
  Serial.println("Current FL Parameter: ");
  Serial.print(ui.getMarked());

  delay(500);
}
