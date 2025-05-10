#include <light-meter/LightMeter.h>

LightMeter::LightMeter() : MenuComponent() {}


void LightMeter::drawUI(lilka::Canvas *canvas) {
    drawCommonUI(canvas);

    drawGradientLuxBar(canvas);
    canvas->setFont(FONT_6x12);
    canvas->setTextColor(lilka::colors::White);
    canvas->setCursor(25, 20);
    canvas->setTextSize(2);
    canvas->print(F("lux"));

    drawGradientKelvinBar(canvas);
    canvas->setCursor(205, 190);
    canvas->setTextSize(2);
    canvas->print(F("K."));
    
    lilka::display.drawCanvas(canvas);
}

void LightMeter::drawGradientLuxBar(lilka::Canvas *canvas) {
    const int LX_X = 25;
    const int LX_Y = 25;
    const int LX_W = 20;
    const int LX_H = 150;
    for (int i = 0; i < LX_H; ++i) {
        uint8_t gray = map(i, 0, LX_H - 1, 255, 0);
        uint16_t c   = canvas->color565(gray, gray, gray);
        canvas->fillRect(LX_X, LX_Y + i, LX_W, 1, c);
    }
}

void LightMeter::drawGradientKelvinBar(lilka::Canvas *canvas) {
    // Градієнтна шкала CCT: 1800K (тепло-червоний) → 3000K (жовтий) → 5000K (білий) → 6600K (холодно-блакитний)
    const int KX = 45;
    const int KY = 175;
    const int KW = 150;
    const int KH = 20;

    struct CCTStop { int temp; uint8_t r, g, b; };
    constexpr CCTStop stops[] = {
        { 1800, 255,  56,   0 },  // свічка
        { 3000, 255, 180,  71 },  // теплий білий
        { 5000, 255, 255, 255 },  // нейтральний / денне світло
        { 6600,  64, 156, 255 }   // холодний. білий / хмарне небо
    };

    for (int x = 0; x < KW; ++x) {
        // обчислюємо відповідну температуру для цієї колонки
        float tNorm = float(x) / float(KW - 1);
        float temp  = 1800 + tNorm * (6600 - 1800);

        // знаходимо два сусідні стопи
        const CCTStop* a = &stops[0];
        const CCTStop* b = &stops[1];
        for (int i = 0; i < int(sizeof(stops)/sizeof(stops[0])) - 1; ++i) {
            if (temp >= stops[i].temp && temp <= stops[i+1].temp) {
                a = &stops[i];
                b = &stops[i+1];
                break;
            }
        }

        // локальна інтерполяція між a.temp і b.temp
        float f = (temp - a->temp) / float(b->temp - a->temp);
        uint8_t r = uint8_t(a->r + f * (b->r - a->r));
        uint8_t g = uint8_t(a->g + f * (b->g - a->g));
        uint8_t bl= uint8_t(a->b + f * (b->b - a->b));

        uint16_t col = canvas->color565(r, g, bl);
        canvas->fillRect(KX + x, KY, 1, KH, col);
    }
}
