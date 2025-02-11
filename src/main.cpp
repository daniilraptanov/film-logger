#include <button/Button.h>
#include <display/Display.h>
#include <ui/UserInterface.h>
#include <ultrasonic/Ultrasonic.h>
#include <BH1750.h>

#include <MemoryFree.h>

UserInterface ui;
Display display;
BH1750 lightMeter(0x5c);
Ultrasonic ultrasonic(7, 8);

Button buttonUp(4);
Button buttonDown(5);
Button buttonAccept(6);

void setup() {
  Serial.begin(9600);
  Serial.println("Debug mode started...");

  lightMeter.begin();
  ultrasonic.begin();
  
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

  float lux = lightMeter.readLightLevel();
  Serial.println(lux);

  long distance = ultrasonic.getDistanceCM();
  Serial.println(distance);

  delay(500);
}

