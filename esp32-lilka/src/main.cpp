#include <lilka.h>
#include <Wire.h>
#include <ui/fl-menu/FL_Menu.h>
#include <ui/light-meter/LightMeter.h>
#include <ui/exposure/Exposure.h>
#include <ui/wifi-config/WiFiConfig.h>
#include <sensors/light-sensor/LightSensor.h>
#include <logger/Logger.h>

#define SDA_PIN 14
#define SCL_PIN 13
#define BUZZER_PIN 11

// UI components
FL_Menu menu;
LightMeter lightMeter;
Exposure exposure;
WiFiConfig wifiConfig;
Logger logger;

// Sensors
LightSensor lightSensor;

// Lilka modules
lilka::Controller controller;

void setup() {
    lilka::begin();
    controller.begin();
    Wire.begin(SDA_PIN, SCL_PIN);
    menu.begin();
    lightSensor.begin();
    logger.begin();

    pinMode(BUZZER_PIN, INPUT);
}

void setMenuSelected(bool state) {
    menu.setSelected(state);
}

void loop() {
    lilka::Canvas canvas;
    lilka::State state = lilka::controller.getState();
    controller.setHandler(lilka::Button::START, setMenuSelected);

    float lux = lightSensor.getLux();
    float cct = lightSensor.getCCT();
    float currentEV = lightSensor.getEV();

    int iso = exposure.getISO();
    float aperture = exposure.getAperture();
    float shutter = lightSensor.calculateShutter(currentEV, iso, aperture);

    float recommendedEvMin = lightSensor.calculateRecommendedEV(iso, aperture, 60); // TODO :: 1/500 need to be a setting
    float recommendedEvMax = lightSensor.calculateRecommendedEV(iso, aperture, 500); // TODO :: 1/60 need to be a setting

    lightSensor.printToSerial();
    logger.handleLogging(&state, iso, aperture, shutter, lux, cct, currentEV);

    if (!menu.isSelected()) {
        menu.drawMenu(&canvas);
    }
    else if (menu.isLightMeter()) {
        lightMeter.drawUI(&canvas, lux, cct);
    }
    else if (menu.isExposure()) {
        exposure.handleParameters(&state);
        exposure.drawUI(
            &canvas, 
            currentEV, 
            recommendedEvMin,
            recommendedEvMax,
            shutter
        );
    }
    else if (menu.isWiFiConfig()) {
        wifiConfig.drawUI(&canvas);
    }
}
