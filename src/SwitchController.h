#pragma once

#include <Arduino.h>

#include "DisplayUi.h"

class SwitchController {
public:
    static constexpr uint8_t kSwitchCount = DisplayUi::kVisibleSwitches;

    explicit SwitchController(DisplayUi& ui);

    void begin(const uint8_t (&pins)[kSwitchCount], const uint64_t (&entityIds)[kSwitchCount]);
    int8_t poll(uint32_t now);
    void toggle(uint8_t index, bool& value);
    void setStateForEntity(uint64_t entityId, bool value);
    uint64_t entityId(uint8_t index) const;

private:
    static constexpr uint32_t kDebounceMs = 25;

    struct Switch {
        uint8_t pin = 0;
        uint64_t entityId = 0;
        bool rawPressed = false;
        bool stablePressed = false;
        bool state = false;
        uint32_t lastRawChange = 0;
    };

    DisplayUi& ui;
    Switch switches[kSwitchCount]{};

    void publish();
};
