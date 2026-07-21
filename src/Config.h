#pragma once

#include <Arduino.h>

namespace Config {

constexpr int8_t kTftCs = 5;
constexpr int8_t kTftDc = 2;
constexpr int8_t kTftReset = 10;
constexpr int8_t kTftMosi = 7;
constexpr int8_t kTftSck = 6;
constexpr uint16_t kTftWidth = 240;
constexpr uint16_t kTftHeight = 320;
constexpr uint8_t kTftRotation = 3;

constexpr char kWifiSsid[] = "WIFI";
constexpr char kWifiPassword[] = "PASSWORD";
constexpr char kRustPlusHost[] = "SERVER_IP";
constexpr uint16_t kRustPlusPort = 28082;
constexpr uint64_t kRustPlusPlayerId = 0;
constexpr int32_t kRustPlusPlayerToken = 0;
// use https://github.com/liamcottle/rustplus.js#pairing

constexpr uint32_t kInfoRefreshMs = 60UL * 1000UL;
constexpr uint32_t kTeamRefreshMs = 20UL * 1000UL;

constexpr uint8_t kSwitchButtonPins[] = {0, 0, 0};
constexpr uint64_t kSwitchEntityIds[] = {0, 0, 0};
constexpr uint8_t kVisibleTeamMembers = 4;
constexpr uint8_t kVisibleSwitches = 3;
constexpr const char* kSwitchLabels[kVisibleSwitches] = {"Turret", "Tesla", "Garage"};
}
