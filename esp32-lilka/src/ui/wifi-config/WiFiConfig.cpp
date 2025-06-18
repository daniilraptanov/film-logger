#include <ui/wifi-config/WiFiConfig.h>

WiFiConfig::WiFiConfig() {}

void WiFiConfig::begin() {
    Serial.println("Connect to network...");
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
}

void WiFiConfig::drawUI(lilka::Canvas *canvas) {
    drawCommonUI(canvas);
    lilka::ProgressDialog progress("Мережа", "Зачекайте, йде підключення до WiFi мережі");
    int attempts = 0;
    while (WiFi.status() != WL_CONNECTED && attempts < maxAttempts) {
        progress.setProgress(attempts);
        progress.draw(canvas);

        begin();
        
        delay(500);
        attempts++;
    }
    if (WiFi.status() == WL_CONNECTED) {
        progress.setMessage("Пристрій підключено!");
    } else {
        progress.setMessage("Помилка підключення :(");
    }
}
