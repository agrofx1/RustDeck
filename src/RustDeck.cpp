#include "RustDeck.h"

#include <cstring>

#include "Config.h"

namespace {

void copyText(char* destination, size_t capacity, const char* source) {
    if (capacity == 0) return;
    if (!source) source = "";
    strncpy(destination, source, capacity - 1);
    destination[capacity - 1] = '\0';
}

bool textChanged(const char* current, const char* next) {
    return strcmp(current, next ? next : "") != 0;
}

}

RustDeck::RustDeck(DisplayUi& displayUi, uint64_t playerId, int32_t playerToken,
                   const char* rustPlusHost, uint16_t rustPlusPort)
    : ui(displayUi), rustPlus(playerId, playerToken), switches(displayUi), host(rustPlusHost),
      port(rustPlusPort) {
    rustPlus.onConnectionChange([this](bool connected) {
        handleRustPlusConnection(connected);
    });
    rustPlus.onInfo([this](const AppInfo& info, const char* name, const char*) {
        handleServerInfo(info, name);
    });
    rustPlus.onTeamInfo([this](const AppTeamInfo& info, const AppTeamInfo_Member* members,
                               const char* const* names, int count) {
        handleTeamInfo(info, members, names, count);
    });
    rustPlus.onEntityChanged([this](const AppEntityChanged& changed) {
        handleEntityChanged(changed);
    });
}

void RustDeck::begin() {
    Serial.println("[Switch] initializing physical controls");
    switches.begin(Config::kSwitchButtonPins, Config::kSwitchEntityIds);
}

void RustDeck::update(bool isWifiConnected, uint32_t now) {
    const int8_t pressedSwitch = switches.poll(now);

    if (wifiConnected != isWifiConnected) {
        wifiConnected = isWifiConnected;
        ui.setNetworkConnected(wifiConnected);
        Serial.printf("[Switch] Wi-Fi %s\n", wifiConnected ? "connected" : "disconnected");

        if (wifiConnected) {
            rustPlus.begin(host, port);
        } else {
            handleRustPlusConnection(false);
        }
    }

    if (!wifiConnected) {
        return;
    }

    rustPlus.loop();
    if (!rustPlus.connected()) {
        return;
    }

    if (pressedSwitch >= 0) {
        Serial.printf("[Switch %d] press received while Rust+ is connected\n", pressedSwitch);
        bool value = false;
        switches.toggle(pressedSwitch, value);
        Serial.printf("[Switch %d] setEntityValue(entity=%llu, value=%s)\n", pressedSwitch,
                      static_cast<unsigned long long>(switches.entityId(pressedSwitch)),
                      value ? "true" : "false");
        rustPlus.setEntityValue(switches.entityId(pressedSwitch), value);
    }

    if (now - lastInfoRequest >= Config::kInfoRefreshMs) {
        rustPlus.getInfo();
        lastInfoRequest = now;
    }
    if (now - lastTeamRequest >= Config::kTeamRefreshMs) {
        rustPlus.getTeamInfo();
        lastTeamRequest = now;
    }
}

void RustDeck::requestInitialData(uint32_t now) {
    Serial.printf("[Switch] requesting initial data at %lu ms\n", static_cast<unsigned long>(now));
    rustPlus.getInfo();
    rustPlus.getTeamInfo();
    lastInfoRequest = now;
    lastTeamRequest = now;
}

void RustDeck::handleRustPlusConnection(bool connected) {
    if (rustPlusConnected == connected) return;

    rustPlusConnected = connected;
    ui.setRustPlusConnected(connected);
    Serial.printf("[Switch] Rust+ %s\n", connected ? "connected" : "disconnected");
    if (connected) {
        requestInitialData(millis());
    }
}

void RustDeck::handleServerInfo(const AppInfo& info, const char* name) {
    const bool serverChanged = !hasServerInfo || textChanged(serverName, name);
    if (serverChanged) {
        hasServerInfo = true;
        copyText(serverName, sizeof(serverName), name);
        ui.setServerInfo(serverName);
    }

    const bool populationChanged = players != info.players ||
                                   maxPlayers != info.max_players ||
                                   queuedPlayers != info.queued_players;
    if (populationChanged) {
        players = info.players;
        maxPlayers = info.max_players;
        queuedPlayers = info.queued_players;
        ui.setPopulation(players, maxPlayers, queuedPlayers);
    }
}

void RustDeck::handleTeamInfo(const AppTeamInfo&, const AppTeamInfo_Member* members,
                              const char* const* names, int count) {
    if (count < 0) count = 0;
    const uint8_t receivedCount = count > kMaxTeamMembers ? kMaxTeamMembers : count;
    TeamMember nextMembers[kMaxTeamMembers]{};
    bool selected[kMaxTeamMembers]{};

    for (uint8_t slot = 0; slot < receivedCount; ++slot) {
        uint8_t bestIndex = kMaxTeamMembers;
        uint8_t bestRank = 3;
        for (uint8_t candidate = 0; candidate < receivedCount; ++candidate) {
            if (selected[candidate]) continue;

            const uint8_t rank = members[candidate].is_online
                                     ? (members[candidate].is_alive ? 0 : 1)
                                     : 2;
            if (rank < bestRank) {
                bestRank = rank;
                bestIndex = candidate;
            }
        }

        if (bestIndex == kMaxTeamMembers) break;
        selected[bestIndex] = true;
        copyText(nextMembers[slot].name, sizeof(nextMembers[slot].name), names[bestIndex]);
        nextMembers[slot].online = members[bestIndex].is_online;
        nextMembers[slot].alive = members[bestIndex].is_alive;
    }

    bool teamChanged = !hasTeamInfo || teamMemberCount != receivedCount;
    for (uint8_t i = 0; !teamChanged && i < receivedCount; ++i) {
        teamChanged = textChanged(teamMembers[i].name, nextMembers[i].name) ||
                      teamMembers[i].online != nextMembers[i].online ||
                      teamMembers[i].alive != nextMembers[i].alive;
    }
    if (!teamChanged) return;

    hasTeamInfo = true;
    teamMemberCount = receivedCount;
    for (uint8_t i = 0; i < kMaxTeamMembers; ++i) teamMembers[i] = nextMembers[i];

    const uint8_t visibleCount = receivedCount > DisplayUi::kVisibleTeamMembers
                                     ? DisplayUi::kVisibleTeamMembers
                                     : receivedCount;
    const char* visibleNames[DisplayUi::kVisibleTeamMembers]{};
    bool visibleOnline[DisplayUi::kVisibleTeamMembers]{};
    bool visibleAlive[DisplayUi::kVisibleTeamMembers]{};
    for (uint8_t i = 0; i < visibleCount; ++i) {
        visibleNames[i] = teamMembers[i].name;
        visibleOnline[i] = teamMembers[i].online;
        visibleAlive[i] = teamMembers[i].alive;
    }
    ui.setTeamMembers(visibleNames, visibleOnline, visibleAlive, visibleCount);
}

void RustDeck::handleEntityChanged(const AppEntityChanged& changed) {
    if (!changed.has_entity_id) return;

    const bool value = changed.payload.has_value && changed.payload.value;
    Serial.printf("[Switch] entity-change entity=%llu value=%s%s\n",
                  static_cast<unsigned long long>(changed.entity_id),
                  value ? "true" : "false", changed.payload.has_value ? "" : " (implicit)");
    switches.setStateForEntity(changed.entity_id, value);
}
