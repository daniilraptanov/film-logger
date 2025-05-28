#include <ui/exposure/Exposure.h>

Exposure::Exposure() : MenuComponent() {
    selected = FL_Parameter::NONE;
}

void Exposure::drawUI(lilka::Canvas *canvas, float currentEV, float recommendedEvMin, float recommendedEvMax, float shutter) {
    drawCommonUI(canvas);
    
    // ISO, F-stop, Shutter
    canvas->setTextColor(selected == FL_Parameter::ISO ? lilka::colors::Yellow : lilka::colors::White);
    canvas->setCursor(20, 30);
    canvas->print(String("ISO [") + String(getISO()) + String("]"));

    canvas->setTextColor(selected == FL_Parameter::APERTURE ? lilka::colors::Yellow : lilka::colors::White);
    canvas->setCursor(20, 70);
    canvas->print(String("F/  [") + String(getAperture()) + String("]"));

    canvas->setTextColor(lilka::colors::White);
    canvas->setCursor(20, 110);
    canvas->setTextColor(
        evDifferenceOK(currentEV, recommendedEvMin, recommendedEvMax) ? lilka::colors::Green :
        evDifferenceWARN(currentEV, recommendedEvMin, recommendedEvMax) ? lilka::colors::Orange :
        evDifferenceCRIT(currentEV, recommendedEvMin, recommendedEvMax) ? lilka::colors::Red :
        lilka::colors::Gray_green
    );
    canvas->print(String("1/  ") + String(shutter));


    // шкала EV
    const int EV_X = 10;
    const int EV_Y = 170;
    const int EV_W = 220;
    const int EV_MAX = 20;

    canvas->fillRect(EV_X, EV_Y - 1, EV_W, 3, lilka::colors::White);

    const int tickStep = 5;
    const int tickH = 8;
    const int tickTh = 2;
    canvas->setFont(FONT_6x12);
    canvas->setTextSize(1);
    canvas->setTextColor(lilka::colors::White);

    for (int ev = 0; ev <= EV_MAX; ev += tickStep) {
        int x = EV_X + int((float(ev) / EV_MAX) * EV_W);

        canvas->fillRect(x - tickTh/2,
            EV_Y - tickH,
            tickTh,
            tickH * 2,
            lilka::colors::White
        );

        String evStr = String(ev);
        int16_t bx, by; uint16_t bw, bh;
        canvas->getTextBounds(evStr, 0, 0, &bx, &by, &bw, &bh);
        int tx = x - bw/2;
        int ty = EV_Y - tickH - bh - 2;
        canvas->setCursor(tx, ty);
        canvas->print(evStr);
    }

    // позиції поточного та рекомендованого EV
    int curX = EV_X + int((currentEV / float(EV_MAX)) * EV_W);
    int recMinX = EV_X + int((recommendedEvMin / float(EV_MAX)) * EV_W);
    int recMaxX = EV_X + int((recommendedEvMax / float(EV_MAX)) * EV_W);


    canvas->fillRect(curX - tickTh,
        EV_Y - (tickH/2),
        tickTh * 2,
        tickH,
        lilka::colors::Red
    );

    canvas->fillRect(recMinX - tickTh,
        EV_Y - tickH,
        tickTh * 2,
        tickH * 2,
        lilka::colors::Green
    );
    canvas->fillRect(recMaxX - tickTh,
        EV_Y - tickH,
        tickTh * 2,
        tickH * 2,
        lilka::colors::Green
    );

    canvas->setTextColor(lilka::colors::White);
    // поточний над червоною рискою
    {
        String curStr = String(currentEV, 1);
        int16_t bx, by; uint16_t bw, bh;
        canvas->getTextBounds(curStr, 0, 0, &bx, &by, &bw, &bh);
        canvas->setCursor(curX - bw/2, EV_Y - bh/2);
        canvas->print(curStr);
    }
    // рекомендований мінімальний від зеленої риски
    {
        String recStr = String(recommendedEvMin, 1);
        int16_t bx, by; uint16_t bw, bh;
        canvas->getTextBounds(recStr, 0, 0, &bx, &by, &bw, &bh);
        canvas->setCursor(recMinX + 4, EV_Y - bh/2);
        canvas->print(recStr);
    }
    // рекомендований максимальний від зеленої риски
    {
        String recStr = String(recommendedEvMax, 1);
        int16_t bx, by; uint16_t bw, bh;
        canvas->getTextBounds(recStr, 0, 0, &bx, &by, &bw, &bh);
        canvas->setCursor(recMaxX + 4, EV_Y - bh/2);
        canvas->print(recStr);
    }
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

bool Exposure::evDifferenceOK(float current, float min, float max) {
    return (current > min) && (current < max);
};
bool Exposure::evDifferenceWARN(float current, float min, float max) {
    return (current >= min) && (current <= max);
};
bool Exposure::evDifferenceCRIT(float current, float min, float max) {
    return (current < min) || (current > max);
};
