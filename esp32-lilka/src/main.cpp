#include <lilka.h>
#include <fl-menu/FL_Menu.h>
#include <light-meter/LightMeter.h>
#include <exposure/Exposure.h>

FL_Menu menu;
LightMeter lightMeter;
Exposure exposure;

void setup() {
    lilka::begin();
    menu.begin();
}


void loop() {
    lilka::Canvas canvas;
    lilka::State state = lilka::controller.getState();

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
