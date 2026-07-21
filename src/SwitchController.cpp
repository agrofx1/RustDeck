#include "SwitchController.h"

SwitchController::SwitchController(DisplayUi& displayUi) : ui(displayUi) {}

void SwitchController::begin(const uint8_t (&pins)[Config::kVisibleSwitches],
                             const uint64_t (&entityIds)[Config::kVisibleSwitches]) {
    for (uint8_t i = 0; i < Config::kVisibleSwitches; ++i) {
        switches[i].pin = pins[i];
        switches[i].entityId = entityIds[i];
        pinMode(switches[i].pin, INPUT_PULLDOWN);
        switches[i].rawPressed = digitalRead(switches[i].pin) == HIGH;
        switches[i].stablePressed = switches[i].rawPressed;
        switches[i].lastRawChange = millis();
        Serial.printf("[Switch %u] pin=%u entity=%llu configured=%s initial_input=%s\n", i,
                      switches[i].pin, static_cast<unsigned long long>(switches[i].entityId),
                      switches[i].entityId ? "yes" : "no",
                      switches[i].stablePressed ? "HIGH" : "LOW");
    }
    publish();
}

int8_t SwitchController::poll(uint32_t now) {
    for (uint8_t i = 0; i < Config::kVisibleSwitches; ++i) {
        Switch& current = switches[i];
        const bool pressed = digitalRead(current.pin) == HIGH;
        if (pressed != current.rawPressed) {
            current.rawPressed = pressed;
            current.lastRawChange = now;
            Serial.printf("[Switch %u] raw_input=%s at %lu ms\n", i,
                          pressed ? "HIGH" : "LOW", static_cast<unsigned long>(now));
        }
        if (current.stablePressed == current.rawPressed ||
            now - current.lastRawChange < kDebounceMs) {
            continue;
        }
        current.stablePressed = current.rawPressed;
        Serial.printf("[Switch %u] debounced=%s after %lu ms\n", i,
                      current.stablePressed ? "PRESSED" : "RELEASED",
                      static_cast<unsigned long>(now - current.lastRawChange));
        if (current.stablePressed) return i;
    }
    return -1;
}

void SwitchController::toggle(uint8_t index, bool& value) {
    Switch& current = switches[index];
    const bool previous = current.state;
    current.state = !current.state;
    value = current.state;
    Serial.printf("[Switch %u] local %s -> %s; entity=%llu\n", index,
                  previous ? "ON" : "OFF", value ? "ON" : "OFF",
                  static_cast<unsigned long long>(current.entityId));
    publish();
}

void SwitchController::setStateForEntity(uint64_t entityId, bool value) {
    for (uint8_t i = 0; i < Config::kVisibleSwitches; ++i) {
        if (switches[i].entityId == entityId) {
            Serial.printf("[Switch %u] entity-change matched entity=%llu\n", i,
                          static_cast<unsigned long long>(entityId));
            switches[i].state = value;
            publish();
            return;
        }
    }
    Serial.printf("[Switch] entity-change ignored: entity=%llu is not configured\n",
                  static_cast<unsigned long long>(entityId));
}

uint64_t SwitchController::entityId(uint8_t index) const {
    return index < Config::kVisibleSwitches ? switches[index].entityId : 0;
}

void SwitchController::publish() {
    bool active[Config::kVisibleSwitches]{};
    for (uint8_t i = 0; i < Config::kVisibleSwitches; ++i) {
        active[i] = switches[i].state;
    }
    Serial.printf("[Switch] publish UI (%u switches)\n", static_cast<unsigned>(Config::kVisibleSwitches));
    ui.setSwitches(active);
}
