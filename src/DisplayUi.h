#pragma once

#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <Config.h>

class DisplayUi {
public:
    DisplayUi();

    void begin();
    void setNetworkConnected(bool connected);
    void setRustPlusConnected(bool connected);
    void setServerInfo(const char* name);
    void setPopulation(uint32_t players, uint32_t maxPlayers, uint32_t queuedPlayers);
    void setTeamMembers(const char* const* names, const bool* online, const bool* alive,
                        uint8_t count);
    void setSwitches(const bool* active);
    void draw();

private:
    enum DirtyRegion : uint8_t {
        kConnectionStatus = 1 << 0,
        kServerName = 1 << 1,
        kPopulation = 1 << 2,
        kQueue = 1 << 3,
        kTeam = 1 << 4,
        kSwitches = 1 << 5,
        kAllRegions = kConnectionStatus | kServerName | kPopulation | kQueue | kTeam | kSwitches,
    };

    Adafruit_ST7789 display;
    bool networkConnected = false;
    bool rustPlusConnected = false;
    bool hasServerInfo = false;
    bool hasTeamInfo = false;
    uint8_t dirtyRegions = kAllRegions;
    uint32_t players = 0;
    uint32_t maxPlayers = 0;
    uint32_t queuedPlayers = 0;
    uint8_t teamMemberCount = 0;
    bool teamMemberOnline[Config::kVisibleTeamMembers]{};
    bool teamMemberAlive[Config::kVisibleTeamMembers]{};
    bool switchActive[Config::kVisibleSwitches]{};
    char serverName[48]{};
    char teamMemberNames[Config::kVisibleTeamMembers][16]{};

    void drawStaticLayout();
    void drawConnectionStatus();
    void drawServerName();
    void drawPopulation();
    void drawQueue();
    void drawTeam();
    void drawSwitches();
};
