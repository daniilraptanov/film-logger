#include <lilka.h>
#include <Wire.h>
#include <ui/fl-menu/FL_Menu.h>
#include <ui/light-meter/LightMeter.h>
#include <ui/exposure/Exposure.h>
#include <sensors/light-sensor/LightSensor.h>

#define SDA_PIN 14
#define SCL_PIN 13

// UI components
FL_Menu menu;
LightMeter lightMeter;
Exposure exposure;

// Sensors
LightSensor lightSensor;

void setup() {
    lilka::begin();
    Wire.begin(SDA_PIN, SCL_PIN);
    menu.begin();
    lightSensor.begin();
}


void loop() {
    lilka::Canvas canvas;
    lilka::State state = lilka::controller.getState();

    lightSensor.printToSerial();

    if (!menu.isSelected()) {
        menu.drawMenu(&canvas);
    }
    else if (menu.isLightMeter()) {
        lightMeter.drawUI(&canvas, lightSensor.getLux(), lightSensor.getCCT());
    }
    else if (menu.isExposure()) {
        exposure.handleParameters(&state);
        exposure.drawUI(&canvas);
    }
    menu.handleButtons(&state);
}
