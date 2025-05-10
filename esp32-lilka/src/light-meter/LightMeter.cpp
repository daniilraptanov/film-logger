#include <light-meter/LightMeter.h>

// Lux bar
static constexpr int LX_X = 25;
static constexpr int LX_Y = 25;
static constexpr int LX_W = 20;
static constexpr int LX_H = 150;

// Kelvin bar
static constexpr int KX = 45;
static constexpr int KY = 175;
static constexpr int KW = 150;
static constexpr int KH = 20;


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

    int maxLux = 100000;
    int luxValue = 2400;
    int cctValue = 5200;

    int luxY = mapLuxToY(luxValue);
    int kelX = mapKelvinToX(cctValue);

    drawCrosshair(canvas, luxY, kelX, luxValue, cctValue);
    
    lilka::display.drawCanvas(canvas);
}

void LightMeter::drawGradientLuxBar(lilka::Canvas *canvas) {
    for (int i = 0; i < LX_H; ++i) {
        uint8_t gray = map(i, 0, LX_H - 1, 255, 0);
        uint16_t c   = canvas->color565(gray, gray, gray);
        canvas->fillRect(LX_X, LX_Y + i, LX_W, 1, c);
    }
}

void LightMeter::drawGradientKelvinBar(lilka::Canvas *canvas) {
    // градієнтна шкала CCT: 1800K (тепло-червоний) → 3000K (жовтий) → 5000K (білий) → 6600K (холодно-блакитний)
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

void LightMeter::drawCrosshair(lilka::Canvas *canvas, int luxY, int kelX, int lux, int kelvin) {
    // горизонтальна лінія від правої межі шкали lux до точки перетину
    canvas->drawLine(LX_X + LX_W, luxY, kelX, luxY, lilka::colors::Green);
    // вертикальна лінія від верхньої межі шкали Kelvin до точки перетину
    canvas->drawLine(kelX, KY, kelX, luxY, lilka::colors::Green);
    // зелена точка у місці перетину
    canvas->fillCircle(kelX, luxY, 3, lilka::colors::Green);

    // малюємо значення lux над точкою
    canvas->setFont(FONT_6x12);
    canvas->setTextSize(2);
    canvas->setTextColor(lilka::colors::White);
    // вирівнювання по центру за X
    String luxStr = String(lux);
    int16_t x1, y1;
    uint16_t w, h;
    canvas->getTextBounds(luxStr, 0, 0, &x1, &y1, &w, &h);
    int16_t tw = w;
    canvas->setCursor(kelX - tw/2, luxY - 10);
    canvas->print(luxStr);

    // малюємо значення Kelvin праворуч від точки
    String kelStr = String(kelvin);
    canvas->setCursor(kelX + 6, luxY + (KH/2) - 2);
    canvas->print(kelStr);
}

int LightMeter::mapLuxToY(float lux) {
    // масив опорних значень люксів
    static constexpr int LUX_STOPS[] = {
        1,10,50,100,300,500,700,1000,3000,5000,7000,
        10000,15000,20000,25000,30000,40000,50000,70000,100000
    };

    static constexpr int LUX_N = sizeof(LUX_STOPS) / sizeof(LUX_STOPS[0]);

    // знайти індекс попереднього стопа
    int i = 0;
    while (i < LUX_N-1 && lux > LUX_STOPS[i+1]) ++i;
        // дробова позиція між stops[i] і stops[i+1]
        float t = 0;
        if (i < LUX_N-1) {
            t = float(lux - LUX_STOPS[i]) / float(LUX_STOPS[i+1] - LUX_STOPS[i]);
        }
        // нормована позиція по всій шкалі (0 внизу … 1 вгорі)
        float norm = (i + t) / float(LUX_N - 1);
        return LX_Y + int((1.0f - norm) * LX_H);
    
};

int LightMeter::mapKelvinToX(float kelvin) {
    return KX + map(kelvin, 1800, 6600, 0, KW - 1);
};
