#include <ui/wifi-config/WiFiConfig.h>

WiFiConfig::WiFiConfig() {}

void WiFiConfig::begin() {
    Serial.println("Connect to network...");
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
}

void WiFiConfig::drawUI(lilka::Canvas *canvas) {
    drawCommonUI(canvas);

    lilka::ProgressDialog progress("WiFi-мережа", "Зачекайте, йде підключення до мережі WiFi...");
    int attempts = 0;
    while ((WiFi.status() != WL_CONNECTED) && (attempts < maxAttempts)) {
        begin();

        progress.setProgress(attempts);
        progress.draw(canvas);
        lilka::display.drawCanvas(canvas);

        delay(100);
        attempts++;
    }
    if (WiFi.status() == WL_CONNECTED) {
        progress.setProgress(maxAttempts);
        progress.setMessage("Пристрій підключено!");
    } else {
        progress.setMessage("Помилка підключення :(");
    }
    progress.draw(canvas);
    lilka::display.drawCanvas(canvas);
}
