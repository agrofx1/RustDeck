#include "DisplayUi.h"

#include <SPI.h>
#include <cstring>

#include "Config.h"

namespace {

constexpr uint16_t kBackground = 0x0861;
constexpr uint16_t kPanel = 0x18C3;
constexpr uint16_t kPanelBorder = 0x528A;
constexpr uint16_t kTileText = 0xFFDF;
constexpr uint16_t kMuted = 0xA514;
constexpr uint16_t kActive = 0x7E66;
constexpr uint16_t kInactive = 0x4208;
constexpr uint16_t kOrange = 0xFBC0;
constexpr uint16_t kSwitchOn = 0x45E8;
constexpr uint16_t kSwitchOff = 0xF986;

constexpr int16_t kMargin = 8;

void copyText(char* destination, size_t capacity, const char* source) {
    if (capacity == 0) return;
    if (!source) source = "";
    strncpy(destination, source, capacity - 1);
    destination[capacity - 1] = '\0';
}

void printClipped(Adafruit_ST7789& display, const char* text, size_t maxChars) {
    for (size_t i = 0; text && text[i] && i < maxChars; ++i) display.print(text[i]);
}

void drawWifiIcon(Adafruit_ST7789& display, int16_t x, int16_t y, uint16_t color) {
    display.fillRect(x, y + 1, 10, 2, color);
    display.fillRect(x + 2, y + 3, 6, 2, color);
    display.fillRect(x + 3, y + 5, 4, 2, color);
    display.fillRect(x + 4, y + 7, 2, 2, color);
}

void drawRustPlusIcon(Adafruit_ST7789& display, int16_t x, int16_t y, uint16_t color) {
    display.fillRect(x + 4, y, 2, 10, color);
    display.fillRect(x, y + 4, 10, 2, color);
}

void drawPanel(Adafruit_ST7789& display, int16_t x, int16_t y,
               int16_t width, int16_t height) {
    display.fillRect(x, y, width, height, kPanel);
    display.drawRect(x, y, width, height, kPanelBorder);
}

void drawTeamStatusIcon(Adafruit_ST7789& display, int16_t x, int16_t y,
                        bool online, bool alive) {
    if (!online) {
        display.drawCircle(x + 4, y + 4, 4, kInactive);
        return;
    }
    if (alive) {
        display.fillCircle(x + 4, y + 4, 4, kActive);
        return;
    }

    display.drawLine(x, y, x + 8, y + 8, kOrange);
    display.drawLine(x + 8, y, x, y + 8, kOrange);
}

}

DisplayUi::DisplayUi()
    : display(Config::kTftCs, Config::kTftDc, Config::kTftReset) {}

void DisplayUi::begin() {
    SPI.begin(Config::kTftSck, -1, Config::kTftMosi, Config::kTftCs);
    display.init(Config::kTftWidth, Config::kTftHeight);
    display.setRotation(Config::kTftRotation);
    display.setTextWrap(false);
    drawStaticLayout();
    dirtyRegions = kAllRegions;
}

void DisplayUi::setNetworkConnected(bool connected) {
    if (networkConnected == connected) return;
    networkConnected = connected;
    dirtyRegions |= kConnectionStatus;
}

void DisplayUi::setRustPlusConnected(bool connected) {
    if (rustPlusConnected == connected) return;
    rustPlusConnected = connected;
    dirtyRegions |= kConnectionStatus;
}

void DisplayUi::setServerInfo(const char* name) {
    if (hasServerInfo && strcmp(serverName, name ? name : "") == 0) return;
    copyText(serverName, sizeof(serverName), name);
    hasServerInfo = true;
    dirtyRegions |= kServerName;
}

void DisplayUi::setPopulation(uint32_t newPlayers, uint32_t newMaxPlayers, uint32_t newQueuedPlayers) {
    if (players != newPlayers || maxPlayers != newMaxPlayers) dirtyRegions |= kPopulation;
    if (queuedPlayers != newQueuedPlayers) dirtyRegions |= kQueue;
    players = newPlayers;
    maxPlayers = newMaxPlayers;
    queuedPlayers = newQueuedPlayers;
}

void DisplayUi::setTeamMembers(const char* const* names, const bool* online, const bool* alive,
                               uint8_t count) {
    const uint8_t newCount = count > kVisibleTeamMembers ? kVisibleTeamMembers : count;
    bool teamChanged = !hasTeamInfo || teamMemberCount != newCount;
    for (uint8_t i = 0; !teamChanged && i < newCount; ++i) {
        teamChanged = strcmp(teamMemberNames[i], names[i] ? names[i] : "") != 0 ||
                      teamMemberOnline[i] != online[i] || teamMemberAlive[i] != alive[i];
    }
    if (!teamChanged) return;

    hasTeamInfo = true;
    teamMemberCount = newCount;
    for (uint8_t i = 0; i < kVisibleTeamMembers; ++i) {
        if (i < newCount) {
            copyText(teamMemberNames[i], sizeof(teamMemberNames[i]), names[i]);
            teamMemberOnline[i] = online[i];
            teamMemberAlive[i] = alive[i];
        } else {
            teamMemberNames[i][0] = '\0';
            teamMemberOnline[i] = false;
            teamMemberAlive[i] = false;
        }
    }
    dirtyRegions |= kTeam;
}

void DisplayUi::setSwitches(const bool* active) {
    for (uint8_t i = 0; i < kVisibleSwitches; ++i) {
        if (switchActive[i] != active[i]) {
            for (uint8_t j = 0; j < kVisibleSwitches; ++j) {
                switchActive[j] = active[j];
            }
            dirtyRegions |= kSwitches;
            return;
        }
    }
}

void DisplayUi::draw() {
    const uint8_t regions = dirtyRegions;
    if (regions & kConnectionStatus) drawConnectionStatus();
    if (regions & kServerName) drawServerName();
    if (regions & kPopulation) drawPopulation();
    if (regions & kQueue) drawQueue();
    if (regions & kTeam) drawTeam();
    if (regions & kSwitches) drawSwitches();
    dirtyRegions &= ~regions;
}

void DisplayUi::drawStaticLayout() {
    display.fillScreen(kBackground);
    drawPanel(display, kMargin, kMargin, 304, 52);
    display.fillRect(kMargin, kMargin, 4, 52, kOrange);
    display.setTextColor(kMuted);
    display.setTextSize(1);
    display.setCursor(18, 16);
    display.print("SERVER");

    drawPanel(display, kMargin, 68, 184, 112);
    display.setCursor(20, 80);
    display.print("POPULATION");
    display.setCursor(116, 98);
    display.print("QUEUE");

    drawPanel(display, 200, 68, 112, 112);
    display.setCursor(212, 80);
    display.print("TEAM");
}

void DisplayUi::drawConnectionStatus() {
    display.fillRect(268, 12, 18, 18, kPanel);
    drawWifiIcon(display, 272, 16, networkConnected ? kActive : kInactive);
    display.fillRect(290, 12, 18, 18, kPanel);
    drawRustPlusIcon(display, 294, 16, rustPlusConnected ? kActive : kInactive);
}

void DisplayUi::drawServerName() {
    display.fillRect(18, 30, 240, 16, kPanel);

    if (!hasServerInfo) {
        display.setTextColor(kMuted);
        display.setTextSize(2);
        display.setCursor(18, 30);
        display.print("AWAITING SERVER");
        return;
    }

    display.setTextColor(kTileText);
    display.setTextSize(2);
    display.setCursor(18, 30);
    printClipped(display, serverName, 23);
}

void DisplayUi::drawPopulation() {
    display.fillRect(20, 96, 88, 54, kPanel);
    display.setTextColor(kTileText);
    display.setTextSize(4);
    display.setCursor(20, 96);
    display.print(players);
    display.setTextSize(2);
    display.setTextColor(kMuted);
    display.setCursor(20, 132);
    display.print("/ ");
    display.print(maxPlayers);
}

void DisplayUi::drawQueue() {
    display.fillRect(116, 110, 64, 24, kPanel);
    display.setTextColor(queuedPlayers ? kOrange : kTileText);
    display.setTextSize(2);
    display.setCursor(116, 112);
    display.print(queuedPlayers);
}

void DisplayUi::drawTeam() {
    display.fillRect(208, 96, 96, 72, kPanel);
    display.setTextSize(1);
    if (!hasTeamInfo) {
        display.setTextColor(kMuted);
        display.setCursor(212, 104);
        display.print("AWAITING TEAM");
        return;
    }
    if (teamMemberCount == 0) {
        display.setTextColor(kMuted);
        display.setCursor(212, 104);
        display.print("NO TEAM");
        return;
    }

    for (uint8_t i = 0; i < teamMemberCount; ++i) {
        const int16_t y = 98 + i * 17;
        display.setTextColor(kTileText);
        display.setTextSize(2);
        display.setCursor(212, y);
        printClipped(display, teamMemberNames[i], 6);
        drawTeamStatusIcon(display, 292, y + 3, teamMemberOnline[i], teamMemberAlive[i]);
    }
}

void DisplayUi::drawSwitches() {
    constexpr int16_t kSwitchY = 188;
    constexpr int16_t kSwitchWidth = 96;
    constexpr int16_t kSwitchHeight = 36;
    constexpr int16_t kSwitchX[kVisibleSwitches] = {8, 110, 212};
    constexpr const char* kSwitchLabels[kVisibleSwitches] = {"Turret", "Tesla", "Garage"};

    for (uint8_t i = 0; i < kVisibleSwitches; ++i) {
        const int16_t x = kSwitchX[i];
        display.fillRect(x, kSwitchY, kSwitchWidth, kSwitchHeight, kBackground);
        display.fillRoundRect(x, kSwitchY, kSwitchWidth, kSwitchHeight, 7, kPanel);

        const uint16_t outline = switchActive[i] ? kSwitchOn : kSwitchOff;
        for (int16_t inset = 0; inset < 3; ++inset) {
            display.drawRoundRect(x + inset, kSwitchY + inset,
                                  kSwitchWidth - inset * 2, kSwitchHeight - inset * 2,
                                  7 - inset, outline);
        }
        display.setTextColor(kTileText);
        display.setTextSize(2);
        const int16_t labelWidth = strlen(kSwitchLabels[i]) * 12;
        display.setCursor(x + (kSwitchWidth - labelWidth) / 2, kSwitchY + 10);
        display.print(kSwitchLabels[i]);
    }
}
