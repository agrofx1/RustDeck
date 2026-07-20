#include <Arduino.h>
#include <WiFi.h>
#include <cstring>

#include "Config.h"
#include "DisplayUi.h"
#include "RustDeck.h"

namespace {

DisplayUi ui;
RustDeck rustDeck(ui, Config::kRustPlusPlayerId, Config::kRustPlusPlayerToken,
                  Config::kRustPlusHost, Config::kRustPlusPort);

bool credentialsConfigured() {
    return Config::kWifiSsid[0] != '\0' &&
           strcmp(Config::kWifiSsid, "YOUR_WIFI_SSID") != 0 &&
           Config::kRustPlusPlayerId != 0 &&
           Config::kRustPlusPlayerToken != 0;
}

}

void setup() {
    Serial.begin(115200);
    ui.begin();
    rustDeck.begin();

    if (!credentialsConfigured()) {
        Serial.println("Set Config.h credentials");
        return;
    }

    WiFi.mode(WIFI_STA);
    WiFi.begin(Config::kWifiSsid, Config::kWifiPassword);
}

void loop() {
    if (!credentialsConfigured()) {
        delay(100);
        return;
    }

    rustDeck.update(WiFi.status() == WL_CONNECTED, millis());
    ui.draw();
}
