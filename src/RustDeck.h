#pragma once

#include <Arduino.h>

#include "DisplayUi.h"
#include "RustPlusApi.h"
#include "SwitchController.h"

class RustDeck {
public:
    RustDeck(DisplayUi& ui, uint64_t playerId, int32_t playerToken,
             const char* host, uint16_t port);

    void begin();
    void update(bool wifiConnected, uint32_t now);

private:
    static constexpr uint8_t kMaxTeamMembers = 8;

    struct TeamMember {
        char name[32]{};
        bool online = false;
        bool alive = false;
    };

    DisplayUi& ui;
    RustPlusApi rustPlus;
    SwitchController switches;
    const char* host;
    uint16_t port;
    bool wifiConnected = false;
    bool rustPlusConnected = false;
    bool hasServerInfo = false;
    bool hasTeamInfo = false;
    uint32_t lastInfoRequest = 0;
    uint32_t lastTeamRequest = 0;
    char serverName[48]{};
    uint32_t players = 0;
    uint32_t maxPlayers = 0;
    uint32_t queuedPlayers = 0;
    uint8_t teamMemberCount = 0;
    TeamMember teamMembers[kMaxTeamMembers]{};

    void requestInitialData(uint32_t now);
    void handleRustPlusConnection(bool connected);
    void handleServerInfo(const AppInfo& info, const char* name);
    void handleTeamInfo(const AppTeamInfo& info, const AppTeamInfo_Member* members,
                        const char* const* names, int count);
    void handleEntityChanged(const AppEntityChanged& changed);
};
