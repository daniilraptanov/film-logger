#include <button/Button.h>
#include <display/Display.h>
#include <ui/UserInterface.h>
#include <ultrasonic/Ultrasonic.h>
#include <light_sensor/LightSensor.h>

// #include <MemoryFree.h>

UserInterface ui;
Display display;
LightSensor lightSensor;
// Ultrasonic ultrasonic(7, 8, 10);
Button buttonDown(6);
Button buttonAccept(5);
Button buttonUp(4);

void setup() {
  Serial.begin(9600);
  Serial.println(F("Debug mode started..."));

  display.begin();
  lightSensor.begin();
  // ultrasonic.begin();
  buttonUp.begin();
  buttonDown.begin();
  buttonAccept.begin();

//   // Serial.print("Free memory after initialization: ");
//   // Serial.println(freeMemory());
}

void loop() {
  ui.handleUI(buttonUp.wasPressed(), buttonDown.wasPressed(), buttonAccept.wasPressed());

  float ev = lightSensor.getEV();
  int iso = ui.getISO();
  float aperture = ui.getAperture();
  float shutter = lightSensor.calculateShutter(ev, iso, aperture);

  display.draw(
    ui.getMarked(), 
    ui.getSelected(), 
    iso, 
    aperture,
    shutter, 
    F("Kodak Vision3 500T"),
    42, // ultrasonic.getFilteredDistanceCM(), 
    42, 
    ev
  );

  delay(500);
}
