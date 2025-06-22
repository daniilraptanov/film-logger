#include <ui/wifi-config/WiFiConfig.h>

WiFiConfig::WiFiConfig() {}

void WiFiConfig::begin() {
    Serial.println("Connect to network...");
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
}

String WiFiConfig::syncData() {
    APIService apiService;
    Logger logger;

    JsonDocument records = logger.readRecords(10);

    serializeJsonPretty(records, Serial);

    return "Дані успішно синхронізовані!";
}

String WiFiConfig::checkConnection() {
    APIService apiService;
    String result = apiService.checkConnection();
    if (result.length() != 0) {
        connectionChecked = true;
        return result;
    }
    return "Сервер не відповідає";
}

void WiFiConfig::drawUI(lilka::Canvas *canvas) {
    drawCommonUI(canvas);

    lilka::ProgressDialog progress("WiFi-мережа", "Зачекайте, йде підключення до мережі WiFi...");
    int attempts = 0;
    while ((WiFi.status() != WL_CONNECTED) && (attempts < maxAttempts)) {
        connectionChecked = false;
        begin();

        progress.setProgress(attempts);
        progress.draw(canvas);
        lilka::display.drawCanvas(canvas);

        delay(100);
        attempts++;
    }
    if (WiFi.status() == WL_CONNECTED) {
        String result = "";
        if (!connectionChecked) {
            result = checkConnection();
        } else {
            result = syncData();
        }
        progress.setProgress(maxAttempts);
        progress.setMessage(result);
    } else {
        progress.setMessage("Помилка підключення :(");
    }

    progress.draw(canvas);
    lilka::display.drawCanvas(canvas);
}
