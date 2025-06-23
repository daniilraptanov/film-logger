#include <ui/wifi-config/WiFiConfig.h>

WiFiConfig::WiFiConfig() {}

void WiFiConfig::begin() {
    Serial.println("Connect to network...");
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
}

String WiFiConfig::syncData() {
    APIService apiService;
    Logger logger;
    size_t limit = 10;

    JsonDocument records = logger.readRecords(limit);
    if (records.is<JsonArray>() && !records.as<JsonArray>().isNull() && records.as<JsonArray>().size() > 0) {
        String result = apiService.exportRecords(records);
        if (result.length() != 0) {
            size_t rows = records.as<JsonArray>().size();
            bool updated = logger.markAsSynced(rows);
            size_t unsyncedRows = logger.countUnsyncedRecords();
            if (updated) {
                return String(F("Успішно збережених \nрядків: ")) + rows + String(F(", залишилось: ")) + unsyncedRows;
            }
            return F("Синхронізація не заве-\nршена.");
        }
        return F("Помилка при збереженні даних.");
    } else {
        return F("Даних для синхроні-\nзації не знайдено.");
    }
}

String WiFiConfig::checkConnection() {
    APIService apiService;
    String result = apiService.checkConnection();
    if (result.length() != 0) {
        connectionChecked = true;
        return result;
    }
    return F("Сервер не відповідає");
}

void WiFiConfig::drawUI(lilka::Canvas *canvas) {
    drawCommonUI(canvas);

    lilka::ProgressDialog progress(F("   WiFi-мережа"), F("Зачекайте, йде підклю-\nчення до мережі WiFi..."));
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
            // TODO :: переробити з прогрес баром,
            // щоб показувати скільки залишилось (замість тексту).
            // Завантаження повинно відбуватися без затримок.
            // При відкриванні цього меню спочатку показувати UI, а потім робити
            // мережні запити, бо підлагує.
            result = syncData();
        }
        progress.setProgress(maxAttempts);
        progress.setMessage(result);
    } else {
        progress.setMessage(F("Помилка підключення :("));
    }

    progress.draw(canvas);
    lilka::display.drawCanvas(canvas);

    // TODO :: використати millis,
    // тоді затримувати сповіщення, щоб користувач встигав прочитати
    delay(3000);
}
