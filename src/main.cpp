#include <button/Button.h>
#include <display/Display.h>
#include <ui/UserInterface.h>
#include <ultrasonic/Ultrasonic.h>
#include <BH1750.h>

#include <MemoryFree.h>

UserInterface ui;
Display display;
// BH1750 lightMeter(0x5c);
Ultrasonic ultrasonic(7, 8);

Button buttonDown(6);
Button buttonAccept(5);
Button buttonUp(4);

void setup() {
  Serial.begin(9600);
  Serial.println(F("Debug mode started..."));

  // lightMeter.begin();
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
  
  // float lux = lightMeter.readLightLevel();
  // Serial.println(lux);
  
  long distance = ultrasonic.getDistanceCM();

  display.draw(ui.getMarked(), ui.getISO(), ui.getAperture(), ui.getShutter(), F("Kodak Vision3 500T"), distance, 42, 7.65);

  delay(500);
}

