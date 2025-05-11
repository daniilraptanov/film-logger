#include <ui/exposure/Exposure.h>

Exposure::Exposure() : MenuComponent() {
    selected = FL_Parameter::NONE;
}

void Exposure::drawUI(lilka::Canvas *canvas) {
    drawCommonUI(canvas);
    
    // ISO, F-stop, Shutter
    // canvas->drawRect(10, 10, 80, 30, lilka::colors::White);
    canvas->setTextColor(selected == FL_Parameter::ISO ? lilka::colors::Yellow : lilka::colors::White);
    canvas->setCursor(20, 30);
    canvas->print(getISO());

    // canvas->drawRect(100, 10, 80, 30, lilka::colors::White);
    canvas->setTextColor(selected == FL_Parameter::APERTURE ? lilka::colors::Yellow : lilka::colors::White);
    canvas->setCursor(110, 30);
    canvas->print(String("F/") + String(getAperture()));

    // canvas->drawRect(190, 10, 80, 30, lilka::colors::White);
    canvas->setTextColor(lilka::colors::White);
    canvas->setCursor(200, 30);
    canvas->print(String("1/1000"));

    // Film title
    // canvas->drawRect(10, 60, 260, 30, lilka::colors::White);
    canvas->setTextColor(lilka::colors::White);
    canvas->setCursor(20, 80);
    canvas->print(String("<"));
    canvas->setCursor(40, 80);
    canvas->print(String("Kodak Vision3 500T"));
    canvas->setCursor(250, 80);
    canvas->print(String(">"));

    // Frame, Distance, Angle
    // canvas->drawRect(10, 110, 80, 30, lilka::colors::White);
    canvas->setTextColor(lilka::colors::White);
    canvas->setCursor(20, 130);
    canvas->print(String("frame: 2"));

    // canvas->drawRect(100, 110, 80, 30, lilka::colors::White);
    canvas->setTextColor(lilka::colors::White);
    canvas->setCursor(110, 130);
    canvas->print(String("42cm"));

    // canvas->drawRect(190, 110, 80, 30, lilka::colors::White);
    canvas->setTextColor(lilka::colors::White);
    canvas->setCursor(200, 130);
    canvas->print(String("45 deg"));

    // EV, CCT
    // canvas->drawRect(10, 160, 130, 30, lilka::colors::White);
    canvas->setTextColor(lilka::colors::White);
    canvas->setCursor(20, 180);
    canvas->print(String("EV: 7.45"));

    // canvas->drawRect(150, 160, 130, 30, lilka::colors::White);
    canvas->setTextColor(lilka::colors::White);
    canvas->setCursor(160, 180);
    canvas->print(String("CCT: 5200K"));

    lilka::display.drawCanvas(canvas);
}

void Exposure::handleParameters(lilka::State *state) {
    if (state->up.justPressed) {
        selected =
            selected == FL_Parameter::NONE ? FL_Parameter::ISO :
            selected == FL_Parameter::ISO ? FL_Parameter::APERTURE :
            FL_Parameter::NONE; 
    } else if (state->down.justPressed) {
        selected =
            selected == FL_Parameter::APERTURE ? FL_Parameter::ISO :
            selected == FL_Parameter::ISO ? FL_Parameter::NONE :
            FL_Parameter::APERTURE;
    }

    if (selected == FL_Parameter::ISO) {
        isoIndex = getNextIndex(isoIndex, ISO_SIZEOF, state->right.justPressed, state->left.justPressed);
    }
    if (selected == FL_Parameter::APERTURE) {
        apertureIndex = getNextIndex(apertureIndex, APERTURE_SIZEOF, state->right.justPressed, state->left.justPressed);
    }
}

int Exposure::getNextIndex(int index, int maxIndex, bool buttonUp, bool buttonDown) {
    if (buttonUp) {
        if (index == maxIndex) {
            return 0;
        } else {
            return index + 1;
        }
        return index;
    }
    if (buttonDown) {
        if (index == 0) {
            return maxIndex; 
        } else {
            return index - 1;
        }
        return index;
    }
    return index;
}

int Exposure::getISO() {
    return ISO_VALUES[isoIndex];
}

float Exposure::getAperture() {
    return APERTURE_VALUES[apertureIndex];
}
