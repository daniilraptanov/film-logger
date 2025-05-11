#include <lilka.h>
#include <ui/fl-menu/FL_Menu.h>
#include <ui/light-meter/LightMeter.h>
#include <ui/exposure/Exposure.h>
#include <sensors/light-sensor/LightSensor.h>

// UI components
FL_Menu menu;
LightMeter lightMeter;
Exposure exposure;

// Sensors
LightSensor lightSensor;

void setup() {
    lilka::begin();
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
        lightMeter.drawUI(&canvas);
    }
    else if (menu.isExposure()) {
        exposure.handleParameters(&state);
        exposure.drawUI(&canvas);
    }
    menu.handleButtons(&state);
}
