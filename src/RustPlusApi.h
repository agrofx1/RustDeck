#pragma once

#include <Arduino.h>
#include <WebSocketsClient.h>
#include <queue>
#include <vector>
#include <functional>
#include <cstring>

#include "rustplus.pb.h"
#include <pb_encode.h>
#include <pb_decode.h>

struct StrArg {
    char* buf;
    size_t cap;
};

struct RepeatedCtx {
    void* array;
    size_t elem_size;
    size_t max_count;
    size_t count;
    const pb_msgdesc_t* fields;
    void (*setup)(void* elem, int idx, void* user);
    void* user;
};
static bool decodeStrCb(pb_istream_t *stream, const pb_field_t *, void **arg) {
    StrArg* s = static_cast<StrArg*>(*arg);
    size_t len = stream->bytes_left;
    if (len >= s->cap) len = s->cap - 1;
    if (!pb_read(stream, reinterpret_cast<uint8_t*>(s->buf), len)) return false;
    s->buf[len] = '\0';
    return true;
}

static bool decodeRepeatedCb(pb_istream_t *stream, const pb_field_t *, void **arg) {
    RepeatedCtx* ctx = static_cast<RepeatedCtx*>(*arg);
    if (ctx->count < ctx->max_count) {
        void* elem = (uint8_t*)ctx->array + ctx->count * ctx->elem_size;
        if (ctx->setup) ctx->setup(elem, (int)ctx->count, ctx->user);
        if (!pb_decode(stream, ctx->fields, elem)) return false;
        ctx->count++;
    } else {
        while (stream->bytes_left > 0) {
            uint8_t tmp[64];
            size_t chunk = stream->bytes_left > sizeof(tmp) ? sizeof(tmp) : stream->bytes_left;
            if (!pb_read(stream, tmp, chunk)) return false;
        }
    }
    return true;
}

static bool encodeStrCb(pb_ostream_t *stream, const pb_field_t *field, void *const *arg) {
    const char* str = static_cast<const char*>(*arg);
    if (!str) return true;
    if (!pb_encode_tag_for_field(stream, field)) return false;
    return pb_encode_string(stream, reinterpret_cast<const uint8_t*>(str), strlen(str));
}

#define BIND_STR(field, strArg) \
    do { (field).funcs.decode = decodeStrCb; (field).arg = &(strArg); } while (0)

class RustPlusSocket {
private:
    WebSocketsClient webSocket;
    std::queue<std::vector<uint8_t>> txQueue;
    bool isConnected = false;
    std::function<void(uint8_t*, size_t)> onMessageCallback;
    std::function<void(bool)> onConnectionChangeCallback;

public:
    void begin(const char* host, uint16_t port) {
        webSocket.begin(host, port, "/");
        webSocket.setReconnectInterval(5000);

        webSocket.onEvent([this](WStype_t type, uint8_t * payload, size_t length) {
            switch (type) {
                case WStype_DISCONNECTED:
                    isConnected = false;
                    if (onConnectionChangeCallback) onConnectionChangeCallback(false);
                    break;
                case WStype_CONNECTED:
                    isConnected = true;
                    if (onConnectionChangeCallback) onConnectionChangeCallback(true);
                    break;
                case WStype_BIN:
                    if (onMessageCallback) onMessageCallback(payload, length);
                    break;
                default: break;
            }
        });
    }

    void loop() {
        webSocket.loop();
        if (isConnected && !txQueue.empty()) {
            const auto& msg = txQueue.front();
            webSocket.sendBIN(msg.data(), msg.size());
            txQueue.pop();
        }
    }

    void send(const uint8_t* data, size_t len) {
        txQueue.push(std::vector<uint8_t>(data, data + len));
    }

    void setCallbacks(std::function<void(uint8_t*, size_t)> onMsg,
                      std::function<void(bool)> onConn) {
        onMessageCallback = onMsg;
        onConnectionChangeCallback = onConn;
    }

    bool connected() const { return isConnected; }
};

class RustPlusApi {
private:
    RustPlusSocket socket;
    uint64_t playerId;
    int32_t playerToken;
    uint32_t seqCounter = 1;

    char errorMsg[256];
    char infoName[128];
    char infoHeaderImage[256];
    char infoUrl[256];
    char infoMap[64];
    StrArg argError     {errorMsg,         sizeof(errorMsg)};
    StrArg argInfoName  {infoName,         sizeof(infoName)};
    StrArg argInfoHdrImg{infoHeaderImage,  sizeof(infoHeaderImage)};
    StrArg argInfoUrl   {infoUrl,          sizeof(infoUrl)};
    StrArg argInfoMap   {infoMap,          sizeof(infoMap)};

    static const int MAX_TEAM_MEMBERS = 8;
    AppTeamInfo_Member teamMembers[MAX_TEAM_MEMBERS];
    char teamMemberNames[MAX_TEAM_MEMBERS][64];
    const char* teamMemberNamePointers[MAX_TEAM_MEMBERS];
    StrArg teamMemberNameArgs[MAX_TEAM_MEMBERS];
    RepeatedCtx teamMembersCtx{};

    static const int MAX_TEAM_MESSAGES = 16;
    AppTeamMessage teamMessages[MAX_TEAM_MESSAGES];
    char teamMsgNames[MAX_TEAM_MESSAGES][64];
    char teamMsgTexts[MAX_TEAM_MESSAGES][128];
    char teamMsgColors[MAX_TEAM_MESSAGES][16];
    StrArg teamMsgNameArgs[MAX_TEAM_MESSAGES];
    StrArg teamMsgTextArgs[MAX_TEAM_MESSAGES];
    StrArg teamMsgColorArgs[MAX_TEAM_MESSAGES];
    RepeatedCtx teamMessagesCtx{};

    std::function<void(uint32_t, const char*)>                              onErrorCb;
    std::function<void(const AppTeamInfo&, const AppTeamInfo_Member*, const char* const*, int)> onTeamInfoCb;
    std::function<void(const AppEntityInfo&)>                                onEntityInfoCb;
    std::function<void(const AppInfo&, const char*, const char*)>           onInfoCb;
    std::function<void(const AppTime&)>                                      onTimeCb;
    std::function<void(const AppMap&)>                                       onMapCb;
    std::function<void(const AppMapMarkers&)>                                onMapMarkersCb;
    std::function<void(const AppTeamChat&, const AppTeamMessage*, int)>     onTeamChatCb;
    std::function<void(const AppFlag&)>                                      onFlagCb;
    std::function<void(const AppClanInfo&)>                                  onClanInfoCb;
    std::function<void(const AppClanChat&)>                                  onClanChatCb;
    std::function<void(const AppNexusAuth&)>                                 onNexusAuthCb;
    std::function<void(const AppCameraInfo&)>                                onCameraSubscribeInfoCb;

    std::function<void(const AppTeamChanged&)>     onTeamChangedCb;
    std::function<void(const AppNewTeamMessage&)>  onNewTeamMessageCb;
    std::function<void(const AppEntityChanged&)>   onEntityChangedCb;
    std::function<void(const AppClanChanged&)>     onClanChangedCb;
    std::function<void(const AppNewClanMessage&)>  onNewClanMessageCb;
    std::function<void(const AppCameraRays&)>      onCameraRaysCb;

    static void setupTeamMember(void* elem, int idx, void* user) {
        auto* self = static_cast<RustPlusApi*>(user);
        auto* m = static_cast<AppTeamInfo_Member*>(elem);
        *m = AppTeamInfo_Member_init_zero;
        BIND_STR(m->name, self->teamMemberNameArgs[idx]);
    }

    static void setupTeamMessage(void* elem, int idx, void* user) {
        auto* self = static_cast<RustPlusApi*>(user);
        auto* m = static_cast<AppTeamMessage*>(elem);
        *m = AppTeamMessage_init_zero;
        BIND_STR(m->name,    self->teamMsgNameArgs[idx]);
        BIND_STR(m->message, self->teamMsgTextArgs[idx]);
        BIND_STR(m->color,   self->teamMsgColorArgs[idx]);
    }

    void sendRequest(AppRequest& req) {
        req.has_seq          = true;  req.seq          = seqCounter++;
        req.has_player_id    = true;  req.player_id    = playerId;
        req.has_player_token = true;  req.player_token = playerToken;

        uint8_t buffer[1024];
        pb_ostream_t stream = pb_ostream_from_buffer(buffer, sizeof(buffer));

        if (pb_encode(&stream, AppRequest_fields, &req)) {
            socket.send(buffer, stream.bytes_written);
        } else {
            Serial.printf("[RustPlusApi] Encode failed: %s\n", PB_GET_ERROR(&stream));
        }
    }

    void handleIncomingMessage(uint8_t* payload, size_t length) {
        AppMessage msg = AppMessage_init_zero;

        teamMembersCtx.count  = 0;
        teamMessagesCtx.count = 0;

        BIND_STR(msg.response.error.error,           argError);
        BIND_STR(msg.response.info.name,             argInfoName);
        BIND_STR(msg.response.info.header_image,     argInfoHdrImg);
        BIND_STR(msg.response.info.url,              argInfoUrl);
        BIND_STR(msg.response.info.map,              argInfoMap);

        msg.response.team_info.members.funcs.decode    = decodeRepeatedCb;
        msg.response.team_info.members.arg             = &teamMembersCtx;
        msg.response.team_chat.messages.funcs.decode   = decodeRepeatedCb;
        msg.response.team_chat.messages.arg            = &teamMessagesCtx;

        pb_istream_t stream = pb_istream_from_buffer(payload, length);

        if (!pb_decode(&stream, AppMessage_fields, &msg)) {
            Serial.printf("[RustPlusApi] Decode failed: %s\n", PB_GET_ERROR(&stream));
            return;
        }

        if (msg.has_response) {
            AppResponse& r = msg.response;
            if      (r.has_error                 && onErrorCb)              onErrorCb(r.seq, errorMsg);
            else if (r.has_team_info             && onTeamInfoCb)           onTeamInfoCb(r.team_info, teamMembers, teamMemberNamePointers, (int)teamMembersCtx.count);
            else if (r.has_entity_info           && onEntityInfoCb)         onEntityInfoCb(r.entity_info);
            else if (r.has_info                  && onInfoCb)               onInfoCb(r.info, infoName, infoMap);
            else if (r.has_time                  && onTimeCb)               onTimeCb(r.time);
            else if (r.has_map                   && onMapCb)                onMapCb(r.map);
            else if (r.has_map_markers           && onMapMarkersCb)         onMapMarkersCb(r.map_markers);
            else if (r.has_team_chat             && onTeamChatCb)           onTeamChatCb(r.team_chat, teamMessages, (int)teamMessagesCtx.count);
            else if (r.has_flag                  && onFlagCb)               onFlagCb(r.flag);
            else if (r.has_clan_info             && onClanInfoCb)           onClanInfoCb(r.clan_info);
            else if (r.has_clan_chat             && onClanChatCb)           onClanChatCb(r.clan_chat);
            else if (r.has_nexus_auth            && onNexusAuthCb)          onNexusAuthCb(r.nexus_auth);
            else if (r.has_camera_subscribe_info && onCameraSubscribeInfoCb) onCameraSubscribeInfoCb(r.camera_subscribe_info);
        }

        if (msg.has_broadcast) {
            AppBroadcast& bc = msg.broadcast;
            if (bc.has_team_changed    && onTeamChangedCb)    onTeamChangedCb(bc.team_changed);
            if (bc.has_team_message    && onNewTeamMessageCb) onNewTeamMessageCb(bc.team_message);
            if (bc.has_entity_changed  && onEntityChangedCb)  onEntityChangedCb(bc.entity_changed);
            if (bc.has_clan_changed    && onClanChangedCb)    onClanChangedCb(bc.clan_changed);
            if (bc.has_clan_message    && onNewClanMessageCb) onNewClanMessageCb(bc.clan_message);
            if (bc.has_camera_rays     && onCameraRaysCb)     onCameraRaysCb(bc.camera_rays);
        }
    }

public:
    RustPlusApi(uint64_t pid, int32_t token) : playerId(pid), playerToken(token) {
        for (int i = 0; i < MAX_TEAM_MEMBERS; i++) {
            teamMemberNameArgs[i] = {teamMemberNames[i], sizeof(teamMemberNames[i])};
            teamMemberNamePointers[i] = teamMemberNames[i];
        }

        for (int i = 0; i < MAX_TEAM_MESSAGES; i++) {
            teamMsgNameArgs[i]  = {teamMsgNames[i],  sizeof(teamMsgNames[i])};
            teamMsgTextArgs[i]  = {teamMsgTexts[i],  sizeof(teamMsgTexts[i])};
            teamMsgColorArgs[i] = {teamMsgColors[i], sizeof(teamMsgColors[i])};
        }

        teamMembersCtx = {
            teamMembers, sizeof(AppTeamInfo_Member), MAX_TEAM_MEMBERS, 0,
            AppTeamInfo_Member_fields, setupTeamMember, this
        };
        teamMessagesCtx = {
            teamMessages, sizeof(AppTeamMessage), MAX_TEAM_MESSAGES, 0,
            AppTeamMessage_fields, setupTeamMessage, this
        };

        socket.setCallbacks(
            [this](uint8_t* p, size_t l) { handleIncomingMessage(p, l); },
            [](bool) {}
        );
    }

    void begin(const char* host, uint16_t port) { socket.begin(host, port); }
    void loop()                                  { socket.loop(); }
    bool connected() const                       { return socket.connected(); }
    void onConnectionChange(std::function<void(bool)> cb) {
        socket.setCallbacks(
            [this](uint8_t* p, size_t l) { handleIncomingMessage(p, l); },
            cb
        );
    }

    void getInfo()       { AppRequest r = AppRequest_init_zero; r.has_get_info       = true; sendRequest(r); }
    void getTime()       { AppRequest r = AppRequest_init_zero; r.has_get_time       = true; sendRequest(r); }
    void getMap()        { AppRequest r = AppRequest_init_zero; r.has_get_map        = true; sendRequest(r); }
    void getMapMarkers() { AppRequest r = AppRequest_init_zero; r.has_get_map_markers = true; sendRequest(r); }

    void getTeamInfo()   { AppRequest r = AppRequest_init_zero; r.has_get_team_info  = true; sendRequest(r); }
    void getTeamChat()   { AppRequest r = AppRequest_init_zero; r.has_get_team_chat  = true; sendRequest(r); }
    void sendTeamMessage(const char* msg) {
        AppRequest r = AppRequest_init_zero;
        r.has_send_team_message = true;
        r.send_team_message.message.funcs.encode = encodeStrCb;
        r.send_team_message.message.arg = const_cast<char*>(msg);
        sendRequest(r);
    }
    void promoteToLeader(uint64_t steamId) {
        AppRequest r = AppRequest_init_zero;
        r.has_promote_to_leader = true;
        r.promote_to_leader.has_steam_id = true;
        r.promote_to_leader.steam_id = steamId;
        sendRequest(r);
    }

    void getEntityInfo(uint64_t entityId) {
        AppRequest r = AppRequest_init_zero;
        r.has_entity_id = true; r.entity_id = entityId;
        r.has_get_entity_info = true;
        sendRequest(r);
    }
    void setEntityValue(uint64_t entityId, bool value) {
        AppRequest r = AppRequest_init_zero;
        r.has_entity_id = true; r.entity_id = entityId;
        r.has_set_entity_value = true;
        r.set_entity_value.has_value = true;
        r.set_entity_value.value = value;
        sendRequest(r);
    }

    void checkSubscription() { AppRequest r = AppRequest_init_zero; r.has_check_subscription = true; sendRequest(r); }
    void setSubscription(bool value) {
        AppRequest r = AppRequest_init_zero;
        r.has_set_subscription = true;
        r.set_subscription.has_value = true;
        r.set_subscription.value = value;
        sendRequest(r);
    }

    void getClanInfo()    { AppRequest r = AppRequest_init_zero; r.has_get_clan_info    = true; sendRequest(r); }
    void setClanMotd(const char* motd) {
        AppRequest r = AppRequest_init_zero;
        r.has_set_clan_motd = true;
        r.set_clan_motd.message.funcs.encode = encodeStrCb;
        r.set_clan_motd.message.arg = const_cast<char*>(motd);
        sendRequest(r);
    }
    void getClanChat()    { AppRequest r = AppRequest_init_zero; r.has_get_clan_chat    = true; sendRequest(r); }
    void sendClanMessage(const char* msg) {
        AppRequest r = AppRequest_init_zero;
        r.has_send_clan_message = true;
        r.send_clan_message.message.funcs.encode = encodeStrCb;
        r.send_clan_message.message.arg = const_cast<char*>(msg);
        sendRequest(r);
    }

    void getNexusAuth(const char* appKey) {
        AppRequest r = AppRequest_init_zero;
        r.has_get_nexus_auth = true;
        r.get_nexus_auth.app_key.funcs.encode = encodeStrCb;
        r.get_nexus_auth.app_key.arg = const_cast<char*>(appKey);
        sendRequest(r);
    }

    void cameraSubscribe(const char* cameraId) {
        AppRequest r = AppRequest_init_zero;
        r.has_camera_subscribe = true;
        r.camera_subscribe.camera_id.funcs.encode = encodeStrCb;
        r.camera_subscribe.camera_id.arg = const_cast<char*>(cameraId);
        sendRequest(r);
    }
    void cameraUnsubscribe() { AppRequest r = AppRequest_init_zero; r.has_camera_unsubscribe = true; sendRequest(r); }
    void cameraInput(int32_t buttons, float deltaX, float deltaY) {
        AppRequest r = AppRequest_init_zero;
        r.has_camera_input = true;
        r.camera_input.has_buttons = true;
        r.camera_input.buttons = buttons;
        r.camera_input.has_mouse_delta = true;
        r.camera_input.mouse_delta.has_x = true;
        r.camera_input.mouse_delta.x = deltaX;
        r.camera_input.mouse_delta.has_y = true;
        r.camera_input.mouse_delta.y = deltaY;
        sendRequest(r);
    }

    void onError(std::function<void(uint32_t, const char*)> cb)                              { onErrorCb = cb; }
    void onTeamInfo(std::function<void(const AppTeamInfo&, const AppTeamInfo_Member*, const char* const*, int)> cb) { onTeamInfoCb = cb; }
    void onEntityInfo(std::function<void(const AppEntityInfo&)> cb)                          { onEntityInfoCb = cb; }
    void onInfo(std::function<void(const AppInfo&, const char*, const char*)> cb)            { onInfoCb = cb; }
    void onTime(std::function<void(const AppTime&)> cb)                                       { onTimeCb = cb; }
    void onMap(std::function<void(const AppMap&)> cb)                                          { onMapCb = cb; }
    void onMapMarkers(std::function<void(const AppMapMarkers&)> cb)                           { onMapMarkersCb = cb; }
    void onTeamChat(std::function<void(const AppTeamChat&, const AppTeamMessage*, int)> cb)  { onTeamChatCb = cb; }
    void onFlag(std::function<void(const AppFlag&)> cb)                                       { onFlagCb = cb; }
    void onClanInfo(std::function<void(const AppClanInfo&)> cb)                               { onClanInfoCb = cb; }
    void onClanChat(std::function<void(const AppClanChat&)> cb)                               { onClanChatCb = cb; }
    void onNexusAuth(std::function<void(const AppNexusAuth&)> cb)                             { onNexusAuthCb = cb; }
    void onCameraSubscribeInfo(std::function<void(const AppCameraInfo&)> cb)                  { onCameraSubscribeInfoCb = cb; }

    void onTeamChanged(std::function<void(const AppTeamChanged&)> cb)         { onTeamChangedCb = cb; }
    void onNewTeamMessage(std::function<void(const AppNewTeamMessage&)> cb)   { onNewTeamMessageCb = cb; }
    void onEntityChanged(std::function<void(const AppEntityChanged&)> cb)     { onEntityChangedCb = cb; }
    void onClanChanged(std::function<void(const AppClanChanged&)> cb)         { onClanChangedCb = cb; }
    void onNewClanMessage(std::function<void(const AppNewClanMessage&)> cb)   { onNewClanMessageCb = cb; }
    void onCameraRays(std::function<void(const AppCameraRays&)> cb)           { onCameraRaysCb = cb; }
};
