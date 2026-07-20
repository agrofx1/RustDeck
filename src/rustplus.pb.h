#ifndef PB_SRC_RUSTPLUS_PB_H_INCLUDED
#define PB_SRC_RUSTPLUS_PB_H_INCLUDED
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

typedef enum _AppEntityType {
    AppEntityType_Switch = 1,
    AppEntityType_Alarm = 2,
    AppEntityType_StorageMonitor = 3
} AppEntityType;

typedef enum _AppMarkerType {
    AppMarkerType_Undefined = 0,
    AppMarkerType_Player = 1,
    AppMarkerType_Explosion = 2,
    AppMarkerType_VendingMachine = 3,
    AppMarkerType_CH47 = 4,
    AppMarkerType_CargoShip = 5,
    AppMarkerType_Crate = 6,
    AppMarkerType_GenericRadius = 7,
    AppMarkerType_PatrolHelicopter = 8,
    AppMarkerType_TravellingVendor = 9
} AppMarkerType;

typedef enum _AppCameraRays_EntityType {
    AppCameraRays_EntityType_Tree = 1,
    AppCameraRays_EntityType_Player = 2
} AppCameraRays_EntityType;

typedef struct _Vector2 {
    bool has_x;
    float x;
    bool has_y;
    float y;
} Vector2;

typedef struct _Vector3 {
    bool has_x;
    float x;
    bool has_y;
    float y;
    bool has_z;
    float z;
} Vector3;

typedef struct _Vector4 {
    bool has_x;
    float x;
    bool has_y;
    float y;
    bool has_z;
    float z;
    bool has_w;
    float w;
} Vector4;

typedef struct _Half3 {
    bool has_x;
    float x;
    bool has_y;
    float y;
    bool has_z;
    float z;
} Half3;

typedef struct _Color {
    bool has_r;
    float r;
    bool has_g;
    float g;
    bool has_b;
    float b;
    bool has_a;
    float a;
} Color;

typedef struct _Ray {
    bool has_origin;
    Vector3 origin;
    bool has_direction;
    Vector3 direction;
} Ray;

typedef struct _ClanInfo {
    bool has_clan_id;
    int64_t clan_id;
    pb_callback_t name;
    bool has_created;
    int64_t created;
    bool has_creator;
    uint64_t creator;
    pb_callback_t motd;
    bool has_motd_timestamp;
    int64_t motd_timestamp;
    bool has_motd_author;
    uint64_t motd_author;
    pb_callback_t logo;
    bool has_color;
    int32_t color;
    pb_callback_t roles;
    pb_callback_t members;
    pb_callback_t invites;
    bool has_max_member_count;
    int32_t max_member_count;
    bool has_score;
    int64_t score;
} ClanInfo;

typedef struct _ClanActionResult {
    bool has_request_id;
    int32_t request_id;
    bool has_result;
    int32_t result;
    bool has_clan_info;
    ClanInfo clan_info;
} ClanActionResult;

typedef struct _ClanInfo_Role {
    bool has_role_id;
    int32_t role_id;
    bool has_rank;
    int32_t rank;
    pb_callback_t name;
    bool has_can_set_motd;
    bool can_set_motd;
    bool has_can_set_logo;
    bool can_set_logo;
    bool has_can_invite;
    bool can_invite;
    bool has_can_kick;
    bool can_kick;
    bool has_can_promote;
    bool can_promote;
    bool has_can_demote;
    bool can_demote;
    bool has_can_set_player_notes;
    bool can_set_player_notes;
    bool has_can_access_logs;
    bool can_access_logs;
    bool has_can_access_score_events;
    bool can_access_score_events;
} ClanInfo_Role;

typedef struct _ClanInfo_Member {
    bool has_steam_id;
    uint64_t steam_id;
    bool has_role_id;
    int32_t role_id;
    bool has_joined;
    int64_t joined;
    bool has_last_seen;
    int64_t last_seen;
    pb_callback_t notes;
    bool has_online;
    bool online;
} ClanInfo_Member;

typedef struct _ClanInfo_Invite {
    bool has_steam_id;
    uint64_t steam_id;
    bool has_recruiter;
    uint64_t recruiter;
    bool has_timestamp;
    int64_t timestamp;
} ClanInfo_Invite;

typedef struct _ClanLog {
    bool has_clan_id;
    int64_t clan_id;
    pb_callback_t log_entries;
} ClanLog;

typedef struct _ClanLog_Entry {
    bool has_timestamp;
    int64_t timestamp;
    pb_callback_t event_key;
    pb_callback_t arg1;
    pb_callback_t arg2;
    pb_callback_t arg3;
    pb_callback_t arg4;
} ClanLog_Entry;

typedef struct _ClanInvitations {
    pb_callback_t invitations;
} ClanInvitations;

typedef struct _ClanInvitations_Invitation {
    bool has_clan_id;
    int64_t clan_id;
    bool has_recruiter;
    uint64_t recruiter;
    bool has_timestamp;
    int64_t timestamp;
} ClanInvitations_Invitation;

typedef struct _AppEmpty {
    char dummy_field;
} AppEmpty;

typedef struct _AppSendMessage {
    pb_callback_t message;
} AppSendMessage;

typedef struct _AppSetEntityValue {
    bool has_value;
    bool value;
} AppSetEntityValue;

typedef struct _AppPromoteToLeader {
    bool has_steam_id;
    uint64_t steam_id;
} AppPromoteToLeader;

typedef struct _AppGetNexusAuth {
    pb_callback_t app_key;
} AppGetNexusAuth;

typedef struct _AppSuccess {
    char dummy_field;
} AppSuccess;

typedef struct _AppError {
    pb_callback_t error;
} AppError;

typedef struct _AppFlag {
    bool has_value;
    bool value;
} AppFlag;

typedef struct _AppInfo {
    pb_callback_t name;
    pb_callback_t header_image;
    pb_callback_t url;
    pb_callback_t map;
    bool has_map_size;
    uint32_t map_size;
    bool has_wipe_time;
    uint32_t wipe_time;
    bool has_players;
    uint32_t players;
    bool has_max_players;
    uint32_t max_players;
    bool has_queued_players;
    uint32_t queued_players;
    bool has_seed;
    uint32_t seed;
    bool has_salt;
    uint32_t salt;
    pb_callback_t logo_image;
    pb_callback_t nexus;
    bool has_nexus_id;
    int32_t nexus_id;
    pb_callback_t nexus_zone;
} AppInfo;

typedef struct _AppTime {
    bool has_day_length_minutes;
    float day_length_minutes;
    bool has_time_scale;
    float time_scale;
    bool has_sunrise;
    float sunrise;
    bool has_sunset;
    float sunset;
    bool has_time;
    float time;
} AppTime;

typedef struct _AppMap {
    bool has_width;
    uint32_t width;
    bool has_height;
    uint32_t height;
    pb_callback_t jpg_image;
    bool has_ocean_margin;
    int32_t ocean_margin;
    pb_callback_t monuments;
    pb_callback_t background;
} AppMap;

typedef struct _AppMap_Monument {
    pb_callback_t token;
    bool has_x;
    float x;
    bool has_y;
    float y;
} AppMap_Monument;

typedef struct _AppEntityPayload {
    bool has_value;
    bool value;
    pb_callback_t items;
    bool has_capacity;
    int32_t capacity;
    bool has_has_protection;
    bool has_protection;
    bool has_protection_expiry;
    uint32_t protection_expiry;
} AppEntityPayload;

typedef struct _AppEntityInfo {
    bool has_type;
    AppEntityType type;
    bool has_payload;
    AppEntityPayload payload;
} AppEntityInfo;

typedef struct _AppEntityPayload_Item {
    bool has_item_id;
    int32_t item_id;
    bool has_quantity;
    int32_t quantity;
    bool has_item_is_blueprint;
    bool item_is_blueprint;
} AppEntityPayload_Item;

typedef struct _AppTeamInfo {
    bool has_leader_steam_id;
    uint64_t leader_steam_id;
    pb_callback_t members;
    pb_callback_t map_notes;
    pb_callback_t leader_map_notes;
} AppTeamInfo;

typedef struct _AppTeamInfo_Member {
    bool has_steam_id;
    uint64_t steam_id;
    pb_callback_t name;
    bool has_x;
    float x;
    bool has_y;
    float y;
    bool has_is_online;
    bool is_online;
    bool has_spawn_time;
    uint32_t spawn_time;
    bool has_is_alive;
    bool is_alive;
    bool has_death_time;
    uint32_t death_time;
} AppTeamInfo_Member;

typedef struct _AppTeamInfo_Note {
    bool has_type;
    int32_t type;
    bool has_x;
    float x;
    bool has_y;
    float y;
    bool has_icon;
    int32_t icon;
    bool has_colour_index;
    int32_t colour_index;
    pb_callback_t label;
} AppTeamInfo_Note;

typedef struct _AppTeamMessage {
    bool has_steam_id;
    uint64_t steam_id;
    pb_callback_t name;
    pb_callback_t message;
    pb_callback_t color;
    bool has_time;
    uint32_t time;
} AppTeamMessage;

typedef struct _AppTeamChat {
    pb_callback_t messages;
} AppTeamChat;

typedef struct _AppMarker {
    bool has_id;
    uint64_t id;
    bool has_type;
    AppMarkerType type;
    bool has_x;
    float x;
    bool has_y;
    float y;
    bool has_steam_id;
    uint64_t steam_id;
    bool has_rotation;
    float rotation;
    bool has_radius;
    float radius;
    bool has_color1;
    Vector4 color1;
    bool has_color2;
    Vector4 color2;
    bool has_alpha;
    float alpha;
    pb_callback_t name;
    bool has_out_of_stock;
    bool out_of_stock;
    pb_callback_t sell_orders;
} AppMarker;

typedef struct _AppMarker_SellOrder {
    bool has_item_id;
    int32_t item_id;
    bool has_quantity;
    int32_t quantity;
    bool has_currency_id;
    int32_t currency_id;
    bool has_cost_per_item;
    int32_t cost_per_item;
    bool has_amount_in_stock;
    int32_t amount_in_stock;
    bool has_item_is_blueprint;
    bool item_is_blueprint;
    bool has_currency_is_blueprint;
    bool currency_is_blueprint;
    bool has_item_condition;
    float item_condition;
    bool has_item_condition_max;
    float item_condition_max;
    bool has_price_multiplier;
    float price_multiplier;
} AppMarker_SellOrder;

typedef struct _AppMapMarkers {
    pb_callback_t markers;
} AppMapMarkers;

typedef struct _AppClanInfo {
    bool has_clan_info;
    ClanInfo clan_info;
} AppClanInfo;

typedef struct _AppClanMessage {
    bool has_steam_id;
    uint64_t steam_id;
    pb_callback_t name;
    pb_callback_t message;
    bool has_time;
    int64_t time;
} AppClanMessage;

typedef struct _AppClanChat {
    pb_callback_t messages;
} AppClanChat;

typedef struct _AppNexusAuth {
    pb_callback_t server_id;
    bool has_player_token;
    int32_t player_token;
} AppNexusAuth;

typedef struct _AppTeamChanged {
    bool has_player_id;
    uint64_t player_id;
    bool has_team_info;
    AppTeamInfo team_info;
} AppTeamChanged;

typedef struct _AppNewTeamMessage {
    bool has_message;
    AppTeamMessage message;
} AppNewTeamMessage;

typedef struct _AppEntityChanged {
    bool has_entity_id;
    uint64_t entity_id;
    bool has_payload;
    AppEntityPayload payload;
} AppEntityChanged;

typedef struct _AppClanChanged {
    bool has_clan_info;
    ClanInfo clan_info;
} AppClanChanged;

typedef struct _AppNewClanMessage {
    bool has_clan_id;
    int64_t clan_id;
    bool has_message;
    AppClanMessage message;
} AppNewClanMessage;

typedef struct _AppCameraSubscribe {
    pb_callback_t camera_id;
} AppCameraSubscribe;

typedef struct _AppCameraInput {
    bool has_buttons;
    int32_t buttons;
    bool has_mouse_delta;
    Vector2 mouse_delta;
} AppCameraInput;

typedef struct _AppRequest {
    bool has_seq;
    uint32_t seq;
    bool has_player_id;
    uint64_t player_id;
    bool has_player_token;
    int32_t player_token;
    bool has_entity_id;
    uint64_t entity_id;
    bool has_get_info;
    AppEmpty get_info;
    bool has_get_time;
    AppEmpty get_time;
    bool has_get_map;
    AppEmpty get_map;
    bool has_get_team_info;
    AppEmpty get_team_info;
    bool has_get_team_chat;
    AppEmpty get_team_chat;
    bool has_send_team_message;
    AppSendMessage send_team_message;
    bool has_get_entity_info;
    AppEmpty get_entity_info;
    bool has_set_entity_value;
    AppSetEntityValue set_entity_value;
    bool has_check_subscription;
    AppEmpty check_subscription;
    bool has_set_subscription;
    AppFlag set_subscription;
    bool has_get_map_markers;
    AppEmpty get_map_markers;
    bool has_promote_to_leader;
    AppPromoteToLeader promote_to_leader;
    bool has_get_clan_info;
    AppEmpty get_clan_info;
    bool has_set_clan_motd;
    AppSendMessage set_clan_motd;
    bool has_get_clan_chat;
    AppEmpty get_clan_chat;
    bool has_send_clan_message;
    AppSendMessage send_clan_message;
    bool has_get_nexus_auth;
    AppGetNexusAuth get_nexus_auth;
    bool has_camera_subscribe;
    AppCameraSubscribe camera_subscribe;
    bool has_camera_unsubscribe;
    AppEmpty camera_unsubscribe;
    bool has_camera_input;
    AppCameraInput camera_input;
} AppRequest;

typedef struct _AppCameraInfo {
    bool has_width;
    int32_t width;
    bool has_height;
    int32_t height;
    bool has_near_plane;
    float near_plane;
    bool has_far_plane;
    float far_plane;
    bool has_control_flags;
    int32_t control_flags;
} AppCameraInfo;

typedef struct _AppResponse {
    bool has_seq;
    uint32_t seq;
    bool has_success;
    AppSuccess success;
    bool has_error;
    AppError error;
    bool has_info;
    AppInfo info;
    bool has_time;
    AppTime time;
    bool has_map;
    AppMap map;
    bool has_team_info;
    AppTeamInfo team_info;
    bool has_team_chat;
    AppTeamChat team_chat;
    bool has_entity_info;
    AppEntityInfo entity_info;
    bool has_flag;
    AppFlag flag;
    bool has_map_markers;
    AppMapMarkers map_markers;
    bool has_clan_info;
    AppClanInfo clan_info;
    bool has_clan_chat;
    AppClanChat clan_chat;
    bool has_nexus_auth;
    AppNexusAuth nexus_auth;
    bool has_camera_subscribe_info;
    AppCameraInfo camera_subscribe_info;
} AppResponse;

typedef struct _AppCameraRays {
    bool has_vertical_fov;
    float vertical_fov;
    bool has_sample_offset;
    int32_t sample_offset;
    pb_callback_t ray_data;
    bool has_distance;
    float distance;
    pb_callback_t entities;
    bool has_time_of_day;
    float time_of_day;
    bool has_camera_position;
    Vector3 camera_position;
    bool has_camera_rotation;
    Vector3 camera_rotation;
} AppCameraRays;

typedef struct _AppBroadcast {
    bool has_team_changed;
    AppTeamChanged team_changed;
    bool has_team_message;
    AppNewTeamMessage team_message;
    bool has_entity_changed;
    AppEntityChanged entity_changed;
    bool has_clan_changed;
    AppClanChanged clan_changed;
    bool has_clan_message;
    AppNewClanMessage clan_message;
    bool has_camera_rays;
    AppCameraRays camera_rays;
} AppBroadcast;

typedef struct _AppMessage {
    bool has_response;
    AppResponse response;
    bool has_broadcast;
    AppBroadcast broadcast;
} AppMessage;

typedef struct _AppCameraRays_Entity {
    bool has_entity_id;
    uint64_t entity_id;
    bool has_type;
    AppCameraRays_EntityType type;
    bool has_position;
    Vector3 position;
    bool has_rotation;
    Vector3 rotation;
    bool has_size;
    Vector3 size;
    pb_callback_t name;
} AppCameraRays_Entity;


#ifdef __cplusplus
extern "C" {
#endif

#define _AppEntityType_MIN AppEntityType_Switch
#define _AppEntityType_MAX AppEntityType_StorageMonitor
#define _AppEntityType_ARRAYSIZE ((AppEntityType)(AppEntityType_StorageMonitor+1))

#define _AppMarkerType_MIN AppMarkerType_Undefined
#define _AppMarkerType_MAX AppMarkerType_TravellingVendor
#define _AppMarkerType_ARRAYSIZE ((AppMarkerType)(AppMarkerType_TravellingVendor+1))

#define _AppCameraRays_EntityType_MIN AppCameraRays_EntityType_Tree
#define _AppCameraRays_EntityType_MAX AppCameraRays_EntityType_Player
#define _AppCameraRays_EntityType_ARRAYSIZE ((AppCameraRays_EntityType)(AppCameraRays_EntityType_Player+1))

#define AppEntityInfo_type_ENUMTYPE AppEntityType
#define AppMarker_type_ENUMTYPE AppMarkerType
#define AppCameraRays_Entity_type_ENUMTYPE AppCameraRays_EntityType

#define Vector2_init_default                     {false, 0, false, 0}
#define Vector3_init_default                     {false, 0, false, 0, false, 0}
#define Vector4_init_default                     {false, 0, false, 0, false, 0, false, 0}
#define Half3_init_default                       {false, 0, false, 0, false, 0}
#define Color_init_default                       {false, 0, false, 0, false, 0, false, 0}
#define Ray_init_default                         {false, Vector3_init_default, false, Vector3_init_default}
#define ClanActionResult_init_default            {false, 0, false, 0, false, ClanInfo_init_default}
#define ClanInfo_init_default                    {false, 0, {{NULL}, NULL}, false, 0, false, 0, {{NULL}, NULL}, false, 0, false, 0, {{NULL}, NULL}, false, 0, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, false, 0, false, 0}
#define ClanInfo_Role_init_default               {false, 0, false, 0, {{NULL}, NULL}, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0}
#define ClanInfo_Member_init_default             {false, 0, false, 0, false, 0, false, 0, {{NULL}, NULL}, false, 0}
#define ClanInfo_Invite_init_default             {false, 0, false, 0, false, 0}
#define ClanLog_init_default                     {false, 0, {{NULL}, NULL}}
#define ClanLog_Entry_init_default               {false, 0, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}}
#define ClanInvitations_init_default             {{{NULL}, NULL}}
#define ClanInvitations_Invitation_init_default  {false, 0, false, 0, false, 0}
#define AppRequest_init_default                  {false, 0, false, 0, false, 0, false, 0, false, AppEmpty_init_default, false, AppEmpty_init_default, false, AppEmpty_init_default, false, AppEmpty_init_default, false, AppEmpty_init_default, false, AppSendMessage_init_default, false, AppEmpty_init_default, false, AppSetEntityValue_init_default, false, AppEmpty_init_default, false, AppFlag_init_default, false, AppEmpty_init_default, false, AppPromoteToLeader_init_default, false, AppEmpty_init_default, false, AppSendMessage_init_default, false, AppEmpty_init_default, false, AppSendMessage_init_default, false, AppGetNexusAuth_init_default, false, AppCameraSubscribe_init_default, false, AppEmpty_init_default, false, AppCameraInput_init_default}
#define AppMessage_init_default                  {false, AppResponse_init_default, false, AppBroadcast_init_default}
#define AppResponse_init_default                 {false, 0, false, AppSuccess_init_default, false, AppError_init_default, false, AppInfo_init_default, false, AppTime_init_default, false, AppMap_init_default, false, AppTeamInfo_init_default, false, AppTeamChat_init_default, false, AppEntityInfo_init_default, false, AppFlag_init_default, false, AppMapMarkers_init_default, false, AppClanInfo_init_default, false, AppClanChat_init_default, false, AppNexusAuth_init_default, false, AppCameraInfo_init_default}
#define AppBroadcast_init_default                {false, AppTeamChanged_init_default, false, AppNewTeamMessage_init_default, false, AppEntityChanged_init_default, false, AppClanChanged_init_default, false, AppNewClanMessage_init_default, false, AppCameraRays_init_default}
#define AppEmpty_init_default                    {0}
#define AppSendMessage_init_default              {{{NULL}, NULL}}
#define AppSetEntityValue_init_default           {false, 0}
#define AppPromoteToLeader_init_default          {false, 0}
#define AppGetNexusAuth_init_default             {{{NULL}, NULL}}
#define AppSuccess_init_default                  {0}
#define AppError_init_default                    {{{NULL}, NULL}}
#define AppFlag_init_default                     {false, 0}
#define AppInfo_init_default                     {{{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, {{NULL}, NULL}, {{NULL}, NULL}, false, 0, {{NULL}, NULL}}
#define AppTime_init_default                     {false, 0, false, 0, false, 0, false, 0, false, 0}
#define AppMap_init_default                      {false, 0, false, 0, {{NULL}, NULL}, false, 0, {{NULL}, NULL}, {{NULL}, NULL}}
#define AppMap_Monument_init_default             {{{NULL}, NULL}, false, 0, false, 0}
#define AppEntityInfo_init_default               {false, _AppEntityType_MIN, false, AppEntityPayload_init_default}
#define AppEntityPayload_init_default            {false, 0, {{NULL}, NULL}, false, 0, false, 0, false, 0}
#define AppEntityPayload_Item_init_default       {false, 0, false, 0, false, 0}
#define AppTeamInfo_init_default                 {false, 0, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}}
#define AppTeamInfo_Member_init_default          {false, 0, {{NULL}, NULL}, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0}
#define AppTeamInfo_Note_init_default            {false, 0, false, 0, false, 0, false, 0, false, 0, {{NULL}, NULL}}
#define AppTeamMessage_init_default              {false, 0, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, false, 0}
#define AppTeamChat_init_default                 {{{NULL}, NULL}}
#define AppMarker_init_default                   {false, 0, false, _AppMarkerType_MIN, false, 0, false, 0, false, 0, false, 0, false, 0, false, Vector4_init_default, false, Vector4_init_default, false, 0, {{NULL}, NULL}, false, 0, {{NULL}, NULL}}
#define AppMarker_SellOrder_init_default         {false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0}
#define AppMapMarkers_init_default               {{{NULL}, NULL}}
#define AppClanInfo_init_default                 {false, ClanInfo_init_default}
#define AppClanMessage_init_default              {false, 0, {{NULL}, NULL}, {{NULL}, NULL}, false, 0}
#define AppClanChat_init_default                 {{{NULL}, NULL}}
#define AppNexusAuth_init_default                {{{NULL}, NULL}, false, 0}
#define AppTeamChanged_init_default              {false, 0, false, AppTeamInfo_init_default}
#define AppNewTeamMessage_init_default           {false, AppTeamMessage_init_default}
#define AppEntityChanged_init_default            {false, 0, false, AppEntityPayload_init_default}
#define AppClanChanged_init_default              {false, ClanInfo_init_default}
#define AppNewClanMessage_init_default           {false, 0, false, AppClanMessage_init_default}
#define AppCameraSubscribe_init_default          {{{NULL}, NULL}}
#define AppCameraInput_init_default              {false, 0, false, Vector2_init_default}
#define AppCameraInfo_init_default               {false, 0, false, 0, false, 0, false, 0, false, 0}
#define AppCameraRays_init_default               {false, 0, false, 0, {{NULL}, NULL}, false, 0, {{NULL}, NULL}, false, 0, false, Vector3_init_default, false, Vector3_init_default}
#define AppCameraRays_Entity_init_default        {false, 0, false, _AppCameraRays_EntityType_MIN, false, Vector3_init_default, false, Vector3_init_default, false, Vector3_init_default, {{NULL}, NULL}}
#define Vector2_init_zero                        {false, 0, false, 0}
#define Vector3_init_zero                        {false, 0, false, 0, false, 0}
#define Vector4_init_zero                        {false, 0, false, 0, false, 0, false, 0}
#define Half3_init_zero                          {false, 0, false, 0, false, 0}
#define Color_init_zero                          {false, 0, false, 0, false, 0, false, 0}
#define Ray_init_zero                            {false, Vector3_init_zero, false, Vector3_init_zero}
#define ClanActionResult_init_zero               {false, 0, false, 0, false, ClanInfo_init_zero}
#define ClanInfo_init_zero                       {false, 0, {{NULL}, NULL}, false, 0, false, 0, {{NULL}, NULL}, false, 0, false, 0, {{NULL}, NULL}, false, 0, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, false, 0, false, 0}
#define ClanInfo_Role_init_zero                  {false, 0, false, 0, {{NULL}, NULL}, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0}
#define ClanInfo_Member_init_zero                {false, 0, false, 0, false, 0, false, 0, {{NULL}, NULL}, false, 0}
#define ClanInfo_Invite_init_zero                {false, 0, false, 0, false, 0}
#define ClanLog_init_zero                        {false, 0, {{NULL}, NULL}}
#define ClanLog_Entry_init_zero                  {false, 0, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}}
#define ClanInvitations_init_zero                {{{NULL}, NULL}}
#define ClanInvitations_Invitation_init_zero     {false, 0, false, 0, false, 0}
#define AppRequest_init_zero                     {false, 0, false, 0, false, 0, false, 0, false, AppEmpty_init_zero, false, AppEmpty_init_zero, false, AppEmpty_init_zero, false, AppEmpty_init_zero, false, AppEmpty_init_zero, false, AppSendMessage_init_zero, false, AppEmpty_init_zero, false, AppSetEntityValue_init_zero, false, AppEmpty_init_zero, false, AppFlag_init_zero, false, AppEmpty_init_zero, false, AppPromoteToLeader_init_zero, false, AppEmpty_init_zero, false, AppSendMessage_init_zero, false, AppEmpty_init_zero, false, AppSendMessage_init_zero, false, AppGetNexusAuth_init_zero, false, AppCameraSubscribe_init_zero, false, AppEmpty_init_zero, false, AppCameraInput_init_zero}
#define AppMessage_init_zero                     {false, AppResponse_init_zero, false, AppBroadcast_init_zero}
#define AppResponse_init_zero                    {false, 0, false, AppSuccess_init_zero, false, AppError_init_zero, false, AppInfo_init_zero, false, AppTime_init_zero, false, AppMap_init_zero, false, AppTeamInfo_init_zero, false, AppTeamChat_init_zero, false, AppEntityInfo_init_zero, false, AppFlag_init_zero, false, AppMapMarkers_init_zero, false, AppClanInfo_init_zero, false, AppClanChat_init_zero, false, AppNexusAuth_init_zero, false, AppCameraInfo_init_zero}
#define AppBroadcast_init_zero                   {false, AppTeamChanged_init_zero, false, AppNewTeamMessage_init_zero, false, AppEntityChanged_init_zero, false, AppClanChanged_init_zero, false, AppNewClanMessage_init_zero, false, AppCameraRays_init_zero}
#define AppEmpty_init_zero                       {0}
#define AppSendMessage_init_zero                 {{{NULL}, NULL}}
#define AppSetEntityValue_init_zero              {false, 0}
#define AppPromoteToLeader_init_zero             {false, 0}
#define AppGetNexusAuth_init_zero                {{{NULL}, NULL}}
#define AppSuccess_init_zero                     {0}
#define AppError_init_zero                       {{{NULL}, NULL}}
#define AppFlag_init_zero                        {false, 0}
#define AppInfo_init_zero                        {{{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, {{NULL}, NULL}, {{NULL}, NULL}, false, 0, {{NULL}, NULL}}
#define AppTime_init_zero                        {false, 0, false, 0, false, 0, false, 0, false, 0}
#define AppMap_init_zero                         {false, 0, false, 0, {{NULL}, NULL}, false, 0, {{NULL}, NULL}, {{NULL}, NULL}}
#define AppMap_Monument_init_zero                {{{NULL}, NULL}, false, 0, false, 0}
#define AppEntityInfo_init_zero                  {false, _AppEntityType_MIN, false, AppEntityPayload_init_zero}
#define AppEntityPayload_init_zero               {false, 0, {{NULL}, NULL}, false, 0, false, 0, false, 0}
#define AppEntityPayload_Item_init_zero          {false, 0, false, 0, false, 0}
#define AppTeamInfo_init_zero                    {false, 0, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}}
#define AppTeamInfo_Member_init_zero             {false, 0, {{NULL}, NULL}, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0}
#define AppTeamInfo_Note_init_zero               {false, 0, false, 0, false, 0, false, 0, false, 0, {{NULL}, NULL}}
#define AppTeamMessage_init_zero                 {false, 0, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, false, 0}
#define AppTeamChat_init_zero                    {{{NULL}, NULL}}
#define AppMarker_init_zero                      {false, 0, false, _AppMarkerType_MIN, false, 0, false, 0, false, 0, false, 0, false, 0, false, Vector4_init_zero, false, Vector4_init_zero, false, 0, {{NULL}, NULL}, false, 0, {{NULL}, NULL}}
#define AppMarker_SellOrder_init_zero            {false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0}
#define AppMapMarkers_init_zero                  {{{NULL}, NULL}}
#define AppClanInfo_init_zero                    {false, ClanInfo_init_zero}
#define AppClanMessage_init_zero                 {false, 0, {{NULL}, NULL}, {{NULL}, NULL}, false, 0}
#define AppClanChat_init_zero                    {{{NULL}, NULL}}
#define AppNexusAuth_init_zero                   {{{NULL}, NULL}, false, 0}
#define AppTeamChanged_init_zero                 {false, 0, false, AppTeamInfo_init_zero}
#define AppNewTeamMessage_init_zero              {false, AppTeamMessage_init_zero}
#define AppEntityChanged_init_zero               {false, 0, false, AppEntityPayload_init_zero}
#define AppClanChanged_init_zero                 {false, ClanInfo_init_zero}
#define AppNewClanMessage_init_zero              {false, 0, false, AppClanMessage_init_zero}
#define AppCameraSubscribe_init_zero             {{{NULL}, NULL}}
#define AppCameraInput_init_zero                 {false, 0, false, Vector2_init_zero}
#define AppCameraInfo_init_zero                  {false, 0, false, 0, false, 0, false, 0, false, 0}
#define AppCameraRays_init_zero                  {false, 0, false, 0, {{NULL}, NULL}, false, 0, {{NULL}, NULL}, false, 0, false, Vector3_init_zero, false, Vector3_init_zero}
#define AppCameraRays_Entity_init_zero           {false, 0, false, _AppCameraRays_EntityType_MIN, false, Vector3_init_zero, false, Vector3_init_zero, false, Vector3_init_zero, {{NULL}, NULL}}

#define Vector2_x_tag                            1
#define Vector2_y_tag                            2
#define Vector3_x_tag                            1
#define Vector3_y_tag                            2
#define Vector3_z_tag                            3
#define Vector4_x_tag                            1
#define Vector4_y_tag                            2
#define Vector4_z_tag                            3
#define Vector4_w_tag                            4
#define Half3_x_tag                              1
#define Half3_y_tag                              2
#define Half3_z_tag                              3
#define Color_r_tag                              1
#define Color_g_tag                              2
#define Color_b_tag                              3
#define Color_a_tag                              4
#define Ray_origin_tag                           1
#define Ray_direction_tag                        2
#define ClanInfo_clan_id_tag                     1
#define ClanInfo_name_tag                        2
#define ClanInfo_created_tag                     3
#define ClanInfo_creator_tag                     4
#define ClanInfo_motd_tag                        5
#define ClanInfo_motd_timestamp_tag              6
#define ClanInfo_motd_author_tag                 7
#define ClanInfo_logo_tag                        8
#define ClanInfo_color_tag                       9
#define ClanInfo_roles_tag                       10
#define ClanInfo_members_tag                     11
#define ClanInfo_invites_tag                     12
#define ClanInfo_max_member_count_tag            13
#define ClanInfo_score_tag                       14
#define ClanActionResult_request_id_tag          1
#define ClanActionResult_result_tag              2
#define ClanActionResult_has_clan_info_tag       3
#define ClanActionResult_clan_info_tag           4
#define ClanInfo_Role_role_id_tag                1
#define ClanInfo_Role_rank_tag                   2
#define ClanInfo_Role_name_tag                   3
#define ClanInfo_Role_can_set_motd_tag           4
#define ClanInfo_Role_can_set_logo_tag           5
#define ClanInfo_Role_can_invite_tag             6
#define ClanInfo_Role_can_kick_tag               7
#define ClanInfo_Role_can_promote_tag            8
#define ClanInfo_Role_can_demote_tag             9
#define ClanInfo_Role_can_set_player_notes_tag   10
#define ClanInfo_Role_can_access_logs_tag        11
#define ClanInfo_Role_can_access_score_events_tag 12
#define ClanInfo_Member_steam_id_tag             1
#define ClanInfo_Member_role_id_tag              2
#define ClanInfo_Member_joined_tag               3
#define ClanInfo_Member_last_seen_tag            4
#define ClanInfo_Member_notes_tag                5
#define ClanInfo_Member_online_tag               6
#define ClanInfo_Invite_steam_id_tag             1
#define ClanInfo_Invite_recruiter_tag            2
#define ClanInfo_Invite_timestamp_tag            3
#define ClanLog_clan_id_tag                      1
#define ClanLog_log_entries_tag                  2
#define ClanLog_Entry_timestamp_tag              1
#define ClanLog_Entry_event_key_tag              2
#define ClanLog_Entry_arg1_tag                   3
#define ClanLog_Entry_arg2_tag                   4
#define ClanLog_Entry_arg3_tag                   5
#define ClanLog_Entry_arg4_tag                   6
#define ClanInvitations_invitations_tag          1
#define ClanInvitations_Invitation_clan_id_tag   1
#define ClanInvitations_Invitation_recruiter_tag 2
#define ClanInvitations_Invitation_timestamp_tag 3
#define AppSendMessage_message_tag               1
#define AppSetEntityValue_value_tag              1
#define AppPromoteToLeader_steam_id_tag          1
#define AppGetNexusAuth_app_key_tag              1
#define AppError_error_tag                       1
#define AppFlag_value_tag                        1
#define AppInfo_name_tag                         1
#define AppInfo_header_image_tag                 2
#define AppInfo_url_tag                          3
#define AppInfo_map_tag                          4
#define AppInfo_map_size_tag                     5
#define AppInfo_wipe_time_tag                    6
#define AppInfo_players_tag                      7
#define AppInfo_max_players_tag                  8
#define AppInfo_queued_players_tag               9
#define AppInfo_seed_tag                         10
#define AppInfo_salt_tag                         11
#define AppInfo_logo_image_tag                   12
#define AppInfo_nexus_tag                        13
#define AppInfo_nexus_id_tag                     14
#define AppInfo_nexus_zone_tag                   15
#define AppTime_day_length_minutes_tag           1
#define AppTime_time_scale_tag                   2
#define AppTime_sunrise_tag                      3
#define AppTime_sunset_tag                       4
#define AppTime_time_tag                         5
#define AppMap_width_tag                         1
#define AppMap_height_tag                        2
#define AppMap_jpg_image_tag                     3
#define AppMap_ocean_margin_tag                  4
#define AppMap_monuments_tag                     5
#define AppMap_background_tag                    6
#define AppMap_Monument_token_tag                1
#define AppMap_Monument_x_tag                    2
#define AppMap_Monument_y_tag                    3
#define AppEntityPayload_value_tag               1
#define AppEntityPayload_items_tag               2
#define AppEntityPayload_capacity_tag            3
#define AppEntityPayload_has_protection_tag      4
#define AppEntityPayload_protection_expiry_tag   5
#define AppEntityInfo_type_tag                   1
#define AppEntityInfo_payload_tag                3
#define AppEntityPayload_Item_item_id_tag        1
#define AppEntityPayload_Item_quantity_tag       2
#define AppEntityPayload_Item_item_is_blueprint_tag 3
#define AppTeamInfo_leader_steam_id_tag          1
#define AppTeamInfo_members_tag                  2
#define AppTeamInfo_map_notes_tag                3
#define AppTeamInfo_leader_map_notes_tag         4
#define AppTeamInfo_Member_steam_id_tag          1
#define AppTeamInfo_Member_name_tag              2
#define AppTeamInfo_Member_x_tag                 3
#define AppTeamInfo_Member_y_tag                 4
#define AppTeamInfo_Member_is_online_tag         5
#define AppTeamInfo_Member_spawn_time_tag        6
#define AppTeamInfo_Member_is_alive_tag          7
#define AppTeamInfo_Member_death_time_tag        8
#define AppTeamInfo_Note_type_tag                2
#define AppTeamInfo_Note_x_tag                   3
#define AppTeamInfo_Note_y_tag                   4
#define AppTeamInfo_Note_icon_tag                5
#define AppTeamInfo_Note_colour_index_tag        6
#define AppTeamInfo_Note_label_tag               7
#define AppTeamMessage_steam_id_tag              1
#define AppTeamMessage_name_tag                  2
#define AppTeamMessage_message_tag               3
#define AppTeamMessage_color_tag                 4
#define AppTeamMessage_time_tag                  5
#define AppTeamChat_messages_tag                 1
#define AppMarker_id_tag                         1
#define AppMarker_type_tag                       2
#define AppMarker_x_tag                          3
#define AppMarker_y_tag                          4
#define AppMarker_steam_id_tag                   5
#define AppMarker_rotation_tag                   6
#define AppMarker_radius_tag                     7
#define AppMarker_color1_tag                     8
#define AppMarker_color2_tag                     9
#define AppMarker_alpha_tag                      10
#define AppMarker_name_tag                       11
#define AppMarker_out_of_stock_tag               12
#define AppMarker_sell_orders_tag                13
#define AppMarker_SellOrder_item_id_tag          1
#define AppMarker_SellOrder_quantity_tag         2
#define AppMarker_SellOrder_currency_id_tag      3
#define AppMarker_SellOrder_cost_per_item_tag    4
#define AppMarker_SellOrder_amount_in_stock_tag  5
#define AppMarker_SellOrder_item_is_blueprint_tag 6
#define AppMarker_SellOrder_currency_is_blueprint_tag 7
#define AppMarker_SellOrder_item_condition_tag   8
#define AppMarker_SellOrder_item_condition_max_tag 9
#define AppMarker_SellOrder_price_multiplier_tag 10
#define AppMapMarkers_markers_tag                1
#define AppClanInfo_clan_info_tag                1
#define AppClanMessage_steam_id_tag              1
#define AppClanMessage_name_tag                  2
#define AppClanMessage_message_tag               3
#define AppClanMessage_time_tag                  4
#define AppClanChat_messages_tag                 1
#define AppNexusAuth_server_id_tag               1
#define AppNexusAuth_player_token_tag            2
#define AppTeamChanged_player_id_tag             1
#define AppTeamChanged_team_info_tag             2
#define AppNewTeamMessage_message_tag            1
#define AppEntityChanged_entity_id_tag           1
#define AppEntityChanged_payload_tag             2
#define AppClanChanged_clan_info_tag             1
#define AppNewClanMessage_clan_id_tag            1
#define AppNewClanMessage_message_tag            2
#define AppCameraSubscribe_camera_id_tag         1
#define AppCameraInput_buttons_tag               1
#define AppCameraInput_mouse_delta_tag           2
#define AppRequest_seq_tag                       1
#define AppRequest_player_id_tag                 2
#define AppRequest_player_token_tag              3
#define AppRequest_entity_id_tag                 4
#define AppRequest_get_info_tag                  8
#define AppRequest_get_time_tag                  9
#define AppRequest_get_map_tag                   10
#define AppRequest_get_team_info_tag             11
#define AppRequest_get_team_chat_tag             12
#define AppRequest_send_team_message_tag         13
#define AppRequest_get_entity_info_tag           14
#define AppRequest_set_entity_value_tag          15
#define AppRequest_check_subscription_tag        16
#define AppRequest_set_subscription_tag          17
#define AppRequest_get_map_markers_tag           18
#define AppRequest_promote_to_leader_tag         20
#define AppRequest_get_clan_info_tag             21
#define AppRequest_set_clan_motd_tag             22
#define AppRequest_get_clan_chat_tag             23
#define AppRequest_send_clan_message_tag         24
#define AppRequest_get_nexus_auth_tag            25
#define AppRequest_camera_subscribe_tag          30
#define AppRequest_camera_unsubscribe_tag        31
#define AppRequest_camera_input_tag              32
#define AppCameraInfo_width_tag                  1
#define AppCameraInfo_height_tag                 2
#define AppCameraInfo_near_plane_tag             3
#define AppCameraInfo_far_plane_tag              4
#define AppCameraInfo_control_flags_tag          5
#define AppResponse_seq_tag                      1
#define AppResponse_success_tag                  4
#define AppResponse_error_tag                    5
#define AppResponse_info_tag                     6
#define AppResponse_time_tag                     7
#define AppResponse_map_tag                      8
#define AppResponse_team_info_tag                9
#define AppResponse_team_chat_tag                10
#define AppResponse_entity_info_tag              11
#define AppResponse_flag_tag                     12
#define AppResponse_map_markers_tag              13
#define AppResponse_clan_info_tag                15
#define AppResponse_clan_chat_tag                16
#define AppResponse_nexus_auth_tag               17
#define AppResponse_camera_subscribe_info_tag    20
#define AppCameraRays_vertical_fov_tag           1
#define AppCameraRays_sample_offset_tag          2
#define AppCameraRays_ray_data_tag               3
#define AppCameraRays_distance_tag               4
#define AppCameraRays_entities_tag               5
#define AppCameraRays_time_of_day_tag            6
#define AppCameraRays_camera_position_tag        7
#define AppCameraRays_camera_rotation_tag        8
#define AppBroadcast_team_changed_tag            4
#define AppBroadcast_team_message_tag            5
#define AppBroadcast_entity_changed_tag          6
#define AppBroadcast_clan_changed_tag            7
#define AppBroadcast_clan_message_tag            8
#define AppBroadcast_camera_rays_tag             10
#define AppMessage_response_tag                  1
#define AppMessage_broadcast_tag                 2
#define AppCameraRays_Entity_entity_id_tag       1
#define AppCameraRays_Entity_type_tag            2
#define AppCameraRays_Entity_position_tag        3
#define AppCameraRays_Entity_rotation_tag        4
#define AppCameraRays_Entity_size_tag            5
#define AppCameraRays_Entity_name_tag            6

#define Vector2_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, FLOAT,    x,                 1) \
X(a, STATIC,   OPTIONAL, FLOAT,    y,                 2)
#define Vector2_CALLBACK NULL
#define Vector2_DEFAULT NULL

#define Vector3_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, FLOAT,    x,                 1) \
X(a, STATIC,   OPTIONAL, FLOAT,    y,                 2) \
X(a, STATIC,   OPTIONAL, FLOAT,    z,                 3)
#define Vector3_CALLBACK NULL
#define Vector3_DEFAULT NULL

#define Vector4_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, FLOAT,    x,                 1) \
X(a, STATIC,   OPTIONAL, FLOAT,    y,                 2) \
X(a, STATIC,   OPTIONAL, FLOAT,    z,                 3) \
X(a, STATIC,   OPTIONAL, FLOAT,    w,                 4)
#define Vector4_CALLBACK NULL
#define Vector4_DEFAULT NULL

#define Half3_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, FLOAT,    x,                 1) \
X(a, STATIC,   OPTIONAL, FLOAT,    y,                 2) \
X(a, STATIC,   OPTIONAL, FLOAT,    z,                 3)
#define Half3_CALLBACK NULL
#define Half3_DEFAULT NULL

#define Color_FIELDLIST(X, a_) \
X(a_, STATIC,   OPTIONAL, FLOAT,    r,                 1) \
X(a_, STATIC,   OPTIONAL, FLOAT,    g,                 2) \
X(a_, STATIC,   OPTIONAL, FLOAT,    b,                 3) \
X(a_, STATIC,   OPTIONAL, FLOAT,    a,                 4)
#define Color_CALLBACK NULL
#define Color_DEFAULT NULL

#define Ray_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, MESSAGE,  origin,            1) \
X(a, STATIC,   OPTIONAL, MESSAGE,  direction,         2)
#define Ray_CALLBACK NULL
#define Ray_DEFAULT NULL
#define Ray_origin_MSGTYPE Vector3
#define Ray_direction_MSGTYPE Vector3

#define ClanActionResult_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, INT32,    request_id,        1) \
X(a, STATIC,   OPTIONAL, INT32,    result,            2) \
X(a, STATIC,   OPTIONAL, MESSAGE,  clan_info,         4)
#define ClanActionResult_CALLBACK NULL
#define ClanActionResult_DEFAULT NULL
#define ClanActionResult_clan_info_MSGTYPE ClanInfo

#define ClanInfo_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, INT64,    clan_id,           1) \
X(a, CALLBACK, OPTIONAL, STRING,   name,              2) \
X(a, STATIC,   OPTIONAL, INT64,    created,           3) \
X(a, STATIC,   OPTIONAL, UINT64,   creator,           4) \
X(a, CALLBACK, OPTIONAL, STRING,   motd,              5) \
X(a, STATIC,   OPTIONAL, INT64,    motd_timestamp,    6) \
X(a, STATIC,   OPTIONAL, UINT64,   motd_author,       7) \
X(a, CALLBACK, OPTIONAL, BYTES,    logo,              8) \
X(a, STATIC,   OPTIONAL, SINT32,   color,             9) \
X(a, CALLBACK, REPEATED, MESSAGE,  roles,            10) \
X(a, CALLBACK, REPEATED, MESSAGE,  members,          11) \
X(a, CALLBACK, REPEATED, MESSAGE,  invites,          12) \
X(a, STATIC,   OPTIONAL, INT32,    max_member_count,  13) \
X(a, STATIC,   OPTIONAL, INT64,    score,            14)
#define ClanInfo_CALLBACK pb_default_field_callback
#define ClanInfo_DEFAULT NULL
#define ClanInfo_roles_MSGTYPE ClanInfo_Role
#define ClanInfo_members_MSGTYPE ClanInfo_Member
#define ClanInfo_invites_MSGTYPE ClanInfo_Invite

#define ClanInfo_Role_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, INT32,    role_id,           1) \
X(a, STATIC,   OPTIONAL, INT32,    rank,              2) \
X(a, CALLBACK, OPTIONAL, STRING,   name,              3) \
X(a, STATIC,   OPTIONAL, BOOL,     can_set_motd,      4) \
X(a, STATIC,   OPTIONAL, BOOL,     can_set_logo,      5) \
X(a, STATIC,   OPTIONAL, BOOL,     can_invite,        6) \
X(a, STATIC,   OPTIONAL, BOOL,     can_kick,          7) \
X(a, STATIC,   OPTIONAL, BOOL,     can_promote,       8) \
X(a, STATIC,   OPTIONAL, BOOL,     can_demote,        9) \
X(a, STATIC,   OPTIONAL, BOOL,     can_set_player_notes,  10) \
X(a, STATIC,   OPTIONAL, BOOL,     can_access_logs,  11) \
X(a, STATIC,   OPTIONAL, BOOL,     can_access_score_events,  12)
#define ClanInfo_Role_CALLBACK pb_default_field_callback
#define ClanInfo_Role_DEFAULT NULL

#define ClanInfo_Member_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, UINT64,   steam_id,          1) \
X(a, STATIC,   OPTIONAL, INT32,    role_id,           2) \
X(a, STATIC,   OPTIONAL, INT64,    joined,            3) \
X(a, STATIC,   OPTIONAL, INT64,    last_seen,         4) \
X(a, CALLBACK, OPTIONAL, STRING,   notes,             5) \
X(a, STATIC,   OPTIONAL, BOOL,     online,            6)
#define ClanInfo_Member_CALLBACK pb_default_field_callback
#define ClanInfo_Member_DEFAULT NULL

#define ClanInfo_Invite_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, UINT64,   steam_id,          1) \
X(a, STATIC,   OPTIONAL, UINT64,   recruiter,         2) \
X(a, STATIC,   OPTIONAL, INT64,    timestamp,         3)
#define ClanInfo_Invite_CALLBACK NULL
#define ClanInfo_Invite_DEFAULT NULL

#define ClanLog_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, INT64,    clan_id,           1) \
X(a, CALLBACK, REPEATED, MESSAGE,  log_entries,       2)
#define ClanLog_CALLBACK pb_default_field_callback
#define ClanLog_DEFAULT NULL
#define ClanLog_log_entries_MSGTYPE ClanLog_Entry

#define ClanLog_Entry_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, INT64,    timestamp,         1) \
X(a, CALLBACK, OPTIONAL, STRING,   event_key,         2) \
X(a, CALLBACK, OPTIONAL, STRING,   arg1,              3) \
X(a, CALLBACK, OPTIONAL, STRING,   arg2,              4) \
X(a, CALLBACK, OPTIONAL, STRING,   arg3,              5) \
X(a, CALLBACK, OPTIONAL, STRING,   arg4,              6)
#define ClanLog_Entry_CALLBACK pb_default_field_callback
#define ClanLog_Entry_DEFAULT NULL

#define ClanInvitations_FIELDLIST(X, a) \
X(a, CALLBACK, REPEATED, MESSAGE,  invitations,       1)
#define ClanInvitations_CALLBACK pb_default_field_callback
#define ClanInvitations_DEFAULT NULL
#define ClanInvitations_invitations_MSGTYPE ClanInvitations_Invitation

#define ClanInvitations_Invitation_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, INT64,    clan_id,           1) \
X(a, STATIC,   OPTIONAL, UINT64,   recruiter,         2) \
X(a, STATIC,   OPTIONAL, INT64,    timestamp,         3)
#define ClanInvitations_Invitation_CALLBACK NULL
#define ClanInvitations_Invitation_DEFAULT NULL

#define AppRequest_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, UINT32,   seq,               1) \
X(a, STATIC,   OPTIONAL, UINT64,   player_id,         2) \
X(a, STATIC,   OPTIONAL, INT32,    player_token,      3) \
X(a, STATIC,   OPTIONAL, UINT64,   entity_id,         4) \
X(a, STATIC,   OPTIONAL, MESSAGE,  get_info,          8) \
X(a, STATIC,   OPTIONAL, MESSAGE,  get_time,          9) \
X(a, STATIC,   OPTIONAL, MESSAGE,  get_map,          10) \
X(a, STATIC,   OPTIONAL, MESSAGE,  get_team_info,    11) \
X(a, STATIC,   OPTIONAL, MESSAGE,  get_team_chat,    12) \
X(a, STATIC,   OPTIONAL, MESSAGE,  send_team_message,  13) \
X(a, STATIC,   OPTIONAL, MESSAGE,  get_entity_info,  14) \
X(a, STATIC,   OPTIONAL, MESSAGE,  set_entity_value,  15) \
X(a, STATIC,   OPTIONAL, MESSAGE,  check_subscription,  16) \
X(a, STATIC,   OPTIONAL, MESSAGE,  set_subscription,  17) \
X(a, STATIC,   OPTIONAL, MESSAGE,  get_map_markers,  18) \
X(a, STATIC,   OPTIONAL, MESSAGE,  promote_to_leader,  20) \
X(a, STATIC,   OPTIONAL, MESSAGE,  get_clan_info,    21) \
X(a, STATIC,   OPTIONAL, MESSAGE,  set_clan_motd,    22) \
X(a, STATIC,   OPTIONAL, MESSAGE,  get_clan_chat,    23) \
X(a, STATIC,   OPTIONAL, MESSAGE,  send_clan_message,  24) \
X(a, STATIC,   OPTIONAL, MESSAGE,  get_nexus_auth,   25) \
X(a, STATIC,   OPTIONAL, MESSAGE,  camera_subscribe,  30) \
X(a, STATIC,   OPTIONAL, MESSAGE,  camera_unsubscribe,  31) \
X(a, STATIC,   OPTIONAL, MESSAGE,  camera_input,     32)
#define AppRequest_CALLBACK NULL
#define AppRequest_DEFAULT NULL
#define AppRequest_get_info_MSGTYPE AppEmpty
#define AppRequest_get_time_MSGTYPE AppEmpty
#define AppRequest_get_map_MSGTYPE AppEmpty
#define AppRequest_get_team_info_MSGTYPE AppEmpty
#define AppRequest_get_team_chat_MSGTYPE AppEmpty
#define AppRequest_send_team_message_MSGTYPE AppSendMessage
#define AppRequest_get_entity_info_MSGTYPE AppEmpty
#define AppRequest_set_entity_value_MSGTYPE AppSetEntityValue
#define AppRequest_check_subscription_MSGTYPE AppEmpty
#define AppRequest_set_subscription_MSGTYPE AppFlag
#define AppRequest_get_map_markers_MSGTYPE AppEmpty
#define AppRequest_promote_to_leader_MSGTYPE AppPromoteToLeader
#define AppRequest_get_clan_info_MSGTYPE AppEmpty
#define AppRequest_set_clan_motd_MSGTYPE AppSendMessage
#define AppRequest_get_clan_chat_MSGTYPE AppEmpty
#define AppRequest_send_clan_message_MSGTYPE AppSendMessage
#define AppRequest_get_nexus_auth_MSGTYPE AppGetNexusAuth
#define AppRequest_camera_subscribe_MSGTYPE AppCameraSubscribe
#define AppRequest_camera_unsubscribe_MSGTYPE AppEmpty
#define AppRequest_camera_input_MSGTYPE AppCameraInput

#define AppMessage_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, MESSAGE,  response,          1) \
X(a, STATIC,   OPTIONAL, MESSAGE,  broadcast,         2)
#define AppMessage_CALLBACK NULL
#define AppMessage_DEFAULT NULL
#define AppMessage_response_MSGTYPE AppResponse
#define AppMessage_broadcast_MSGTYPE AppBroadcast

#define AppResponse_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, UINT32,   seq,               1) \
X(a, STATIC,   OPTIONAL, MESSAGE,  success,           4) \
X(a, STATIC,   OPTIONAL, MESSAGE,  error,             5) \
X(a, STATIC,   OPTIONAL, MESSAGE,  info,              6) \
X(a, STATIC,   OPTIONAL, MESSAGE,  time,              7) \
X(a, STATIC,   OPTIONAL, MESSAGE,  map,               8) \
X(a, STATIC,   OPTIONAL, MESSAGE,  team_info,         9) \
X(a, STATIC,   OPTIONAL, MESSAGE,  team_chat,        10) \
X(a, STATIC,   OPTIONAL, MESSAGE,  entity_info,      11) \
X(a, STATIC,   OPTIONAL, MESSAGE,  flag,             12) \
X(a, STATIC,   OPTIONAL, MESSAGE,  map_markers,      13) \
X(a, STATIC,   OPTIONAL, MESSAGE,  clan_info,        15) \
X(a, STATIC,   OPTIONAL, MESSAGE,  clan_chat,        16) \
X(a, STATIC,   OPTIONAL, MESSAGE,  nexus_auth,       17) \
X(a, STATIC,   OPTIONAL, MESSAGE,  camera_subscribe_info,  20)
#define AppResponse_CALLBACK NULL
#define AppResponse_DEFAULT NULL
#define AppResponse_success_MSGTYPE AppSuccess
#define AppResponse_error_MSGTYPE AppError
#define AppResponse_info_MSGTYPE AppInfo
#define AppResponse_time_MSGTYPE AppTime
#define AppResponse_map_MSGTYPE AppMap
#define AppResponse_team_info_MSGTYPE AppTeamInfo
#define AppResponse_team_chat_MSGTYPE AppTeamChat
#define AppResponse_entity_info_MSGTYPE AppEntityInfo
#define AppResponse_flag_MSGTYPE AppFlag
#define AppResponse_map_markers_MSGTYPE AppMapMarkers
#define AppResponse_clan_info_MSGTYPE AppClanInfo
#define AppResponse_clan_chat_MSGTYPE AppClanChat
#define AppResponse_nexus_auth_MSGTYPE AppNexusAuth
#define AppResponse_camera_subscribe_info_MSGTYPE AppCameraInfo

#define AppBroadcast_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, MESSAGE,  team_changed,      4) \
X(a, STATIC,   OPTIONAL, MESSAGE,  team_message,      5) \
X(a, STATIC,   OPTIONAL, MESSAGE,  entity_changed,    6) \
X(a, STATIC,   OPTIONAL, MESSAGE,  clan_changed,      7) \
X(a, STATIC,   OPTIONAL, MESSAGE,  clan_message,      8) \
X(a, STATIC,   OPTIONAL, MESSAGE,  camera_rays,      10)
#define AppBroadcast_CALLBACK NULL
#define AppBroadcast_DEFAULT NULL
#define AppBroadcast_team_changed_MSGTYPE AppTeamChanged
#define AppBroadcast_team_message_MSGTYPE AppNewTeamMessage
#define AppBroadcast_entity_changed_MSGTYPE AppEntityChanged
#define AppBroadcast_clan_changed_MSGTYPE AppClanChanged
#define AppBroadcast_clan_message_MSGTYPE AppNewClanMessage
#define AppBroadcast_camera_rays_MSGTYPE AppCameraRays

#define AppEmpty_FIELDLIST(X, a) \

#define AppEmpty_CALLBACK NULL
#define AppEmpty_DEFAULT NULL

#define AppSendMessage_FIELDLIST(X, a) \
X(a, CALLBACK, OPTIONAL, STRING,   message,           1)
#define AppSendMessage_CALLBACK pb_default_field_callback
#define AppSendMessage_DEFAULT NULL

#define AppSetEntityValue_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, BOOL,     value,             1)
#define AppSetEntityValue_CALLBACK NULL
#define AppSetEntityValue_DEFAULT NULL

#define AppPromoteToLeader_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, UINT64,   steam_id,          1)
#define AppPromoteToLeader_CALLBACK NULL
#define AppPromoteToLeader_DEFAULT NULL

#define AppGetNexusAuth_FIELDLIST(X, a) \
X(a, CALLBACK, OPTIONAL, STRING,   app_key,           1)
#define AppGetNexusAuth_CALLBACK pb_default_field_callback
#define AppGetNexusAuth_DEFAULT NULL

#define AppSuccess_FIELDLIST(X, a) \

#define AppSuccess_CALLBACK NULL
#define AppSuccess_DEFAULT NULL

#define AppError_FIELDLIST(X, a) \
X(a, CALLBACK, OPTIONAL, STRING,   error,             1)
#define AppError_CALLBACK pb_default_field_callback
#define AppError_DEFAULT NULL

#define AppFlag_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, BOOL,     value,             1)
#define AppFlag_CALLBACK NULL
#define AppFlag_DEFAULT NULL

#define AppInfo_FIELDLIST(X, a) \
X(a, CALLBACK, OPTIONAL, STRING,   name,              1) \
X(a, CALLBACK, OPTIONAL, STRING,   header_image,      2) \
X(a, CALLBACK, OPTIONAL, STRING,   url,               3) \
X(a, CALLBACK, OPTIONAL, STRING,   map,               4) \
X(a, STATIC,   OPTIONAL, UINT32,   map_size,          5) \
X(a, STATIC,   OPTIONAL, UINT32,   wipe_time,         6) \
X(a, STATIC,   OPTIONAL, UINT32,   players,           7) \
X(a, STATIC,   OPTIONAL, UINT32,   max_players,       8) \
X(a, STATIC,   OPTIONAL, UINT32,   queued_players,    9) \
X(a, STATIC,   OPTIONAL, UINT32,   seed,             10) \
X(a, STATIC,   OPTIONAL, UINT32,   salt,             11) \
X(a, CALLBACK, OPTIONAL, STRING,   logo_image,       12) \
X(a, CALLBACK, OPTIONAL, STRING,   nexus,            13) \
X(a, STATIC,   OPTIONAL, INT32,    nexus_id,         14) \
X(a, CALLBACK, OPTIONAL, STRING,   nexus_zone,       15)
#define AppInfo_CALLBACK pb_default_field_callback
#define AppInfo_DEFAULT NULL

#define AppTime_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, FLOAT,    day_length_minutes,   1) \
X(a, STATIC,   OPTIONAL, FLOAT,    time_scale,        2) \
X(a, STATIC,   OPTIONAL, FLOAT,    sunrise,           3) \
X(a, STATIC,   OPTIONAL, FLOAT,    sunset,            4) \
X(a, STATIC,   OPTIONAL, FLOAT,    time,              5)
#define AppTime_CALLBACK NULL
#define AppTime_DEFAULT NULL

#define AppMap_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, UINT32,   width,             1) \
X(a, STATIC,   OPTIONAL, UINT32,   height,            2) \
X(a, CALLBACK, OPTIONAL, BYTES,    jpg_image,         3) \
X(a, STATIC,   OPTIONAL, INT32,    ocean_margin,      4) \
X(a, CALLBACK, REPEATED, MESSAGE,  monuments,         5) \
X(a, CALLBACK, OPTIONAL, STRING,   background,        6)
#define AppMap_CALLBACK pb_default_field_callback
#define AppMap_DEFAULT NULL
#define AppMap_monuments_MSGTYPE AppMap_Monument

#define AppMap_Monument_FIELDLIST(X, a) \
X(a, CALLBACK, OPTIONAL, STRING,   token,             1) \
X(a, STATIC,   OPTIONAL, FLOAT,    x,                 2) \
X(a, STATIC,   OPTIONAL, FLOAT,    y,                 3)
#define AppMap_Monument_CALLBACK pb_default_field_callback
#define AppMap_Monument_DEFAULT NULL

#define AppEntityInfo_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, UENUM,    type,              1) \
X(a, STATIC,   OPTIONAL, MESSAGE,  payload,           3)
#define AppEntityInfo_CALLBACK NULL
#define AppEntityInfo_DEFAULT (const pb_byte_t*)"\x08\x01\x00"
#define AppEntityInfo_payload_MSGTYPE AppEntityPayload

#define AppEntityPayload_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, BOOL,     value,             1) \
X(a, CALLBACK, REPEATED, MESSAGE,  items,             2) \
X(a, STATIC,   OPTIONAL, INT32,    capacity,          3) \
X(a, STATIC,   OPTIONAL, BOOL,     has_protection,    4) \
X(a, STATIC,   OPTIONAL, UINT32,   protection_expiry,   5)
#define AppEntityPayload_CALLBACK pb_default_field_callback
#define AppEntityPayload_DEFAULT NULL
#define AppEntityPayload_items_MSGTYPE AppEntityPayload_Item

#define AppEntityPayload_Item_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, INT32,    item_id,           1) \
X(a, STATIC,   OPTIONAL, INT32,    quantity,          2) \
X(a, STATIC,   OPTIONAL, BOOL,     item_is_blueprint,   3)
#define AppEntityPayload_Item_CALLBACK NULL
#define AppEntityPayload_Item_DEFAULT NULL

#define AppTeamInfo_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, UINT64,   leader_steam_id,   1) \
X(a, CALLBACK, REPEATED, MESSAGE,  members,           2) \
X(a, CALLBACK, REPEATED, MESSAGE,  map_notes,         3) \
X(a, CALLBACK, REPEATED, MESSAGE,  leader_map_notes,   4)
#define AppTeamInfo_CALLBACK pb_default_field_callback
#define AppTeamInfo_DEFAULT NULL
#define AppTeamInfo_members_MSGTYPE AppTeamInfo_Member
#define AppTeamInfo_map_notes_MSGTYPE AppTeamInfo_Note
#define AppTeamInfo_leader_map_notes_MSGTYPE AppTeamInfo_Note

#define AppTeamInfo_Member_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, UINT64,   steam_id,          1) \
X(a, CALLBACK, OPTIONAL, STRING,   name,              2) \
X(a, STATIC,   OPTIONAL, FLOAT,    x,                 3) \
X(a, STATIC,   OPTIONAL, FLOAT,    y,                 4) \
X(a, STATIC,   OPTIONAL, BOOL,     is_online,         5) \
X(a, STATIC,   OPTIONAL, UINT32,   spawn_time,        6) \
X(a, STATIC,   OPTIONAL, BOOL,     is_alive,          7) \
X(a, STATIC,   OPTIONAL, UINT32,   death_time,        8)
#define AppTeamInfo_Member_CALLBACK pb_default_field_callback
#define AppTeamInfo_Member_DEFAULT NULL

#define AppTeamInfo_Note_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, INT32,    type,              2) \
X(a, STATIC,   OPTIONAL, FLOAT,    x,                 3) \
X(a, STATIC,   OPTIONAL, FLOAT,    y,                 4) \
X(a, STATIC,   OPTIONAL, INT32,    icon,              5) \
X(a, STATIC,   OPTIONAL, INT32,    colour_index,      6) \
X(a, CALLBACK, OPTIONAL, STRING,   label,             7)
#define AppTeamInfo_Note_CALLBACK pb_default_field_callback
#define AppTeamInfo_Note_DEFAULT NULL

#define AppTeamMessage_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, UINT64,   steam_id,          1) \
X(a, CALLBACK, OPTIONAL, STRING,   name,              2) \
X(a, CALLBACK, OPTIONAL, STRING,   message,           3) \
X(a, CALLBACK, OPTIONAL, STRING,   color,             4) \
X(a, STATIC,   OPTIONAL, UINT32,   time,              5)
#define AppTeamMessage_CALLBACK pb_default_field_callback
#define AppTeamMessage_DEFAULT NULL

#define AppTeamChat_FIELDLIST(X, a) \
X(a, CALLBACK, REPEATED, MESSAGE,  messages,          1)
#define AppTeamChat_CALLBACK pb_default_field_callback
#define AppTeamChat_DEFAULT NULL
#define AppTeamChat_messages_MSGTYPE AppTeamMessage

#define AppMarker_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, UINT64,   id,                1) \
X(a, STATIC,   OPTIONAL, UENUM,    type,              2) \
X(a, STATIC,   OPTIONAL, FLOAT,    x,                 3) \
X(a, STATIC,   OPTIONAL, FLOAT,    y,                 4) \
X(a, STATIC,   OPTIONAL, UINT64,   steam_id,          5) \
X(a, STATIC,   OPTIONAL, FLOAT,    rotation,          6) \
X(a, STATIC,   OPTIONAL, FLOAT,    radius,            7) \
X(a, STATIC,   OPTIONAL, MESSAGE,  color1,            8) \
X(a, STATIC,   OPTIONAL, MESSAGE,  color2,            9) \
X(a, STATIC,   OPTIONAL, FLOAT,    alpha,            10) \
X(a, CALLBACK, OPTIONAL, STRING,   name,             11) \
X(a, STATIC,   OPTIONAL, BOOL,     out_of_stock,     12) \
X(a, CALLBACK, REPEATED, MESSAGE,  sell_orders,      13)
#define AppMarker_CALLBACK pb_default_field_callback
#define AppMarker_DEFAULT NULL
#define AppMarker_color1_MSGTYPE Vector4
#define AppMarker_color2_MSGTYPE Vector4
#define AppMarker_sell_orders_MSGTYPE AppMarker_SellOrder

#define AppMarker_SellOrder_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, INT32,    item_id,           1) \
X(a, STATIC,   OPTIONAL, INT32,    quantity,          2) \
X(a, STATIC,   OPTIONAL, INT32,    currency_id,       3) \
X(a, STATIC,   OPTIONAL, INT32,    cost_per_item,     4) \
X(a, STATIC,   OPTIONAL, INT32,    amount_in_stock,   5) \
X(a, STATIC,   OPTIONAL, BOOL,     item_is_blueprint,   6) \
X(a, STATIC,   OPTIONAL, BOOL,     currency_is_blueprint,   7) \
X(a, STATIC,   OPTIONAL, FLOAT,    item_condition,    8) \
X(a, STATIC,   OPTIONAL, FLOAT,    item_condition_max,   9) \
X(a, STATIC,   OPTIONAL, FLOAT,    price_multiplier,  10)
#define AppMarker_SellOrder_CALLBACK NULL
#define AppMarker_SellOrder_DEFAULT NULL

#define AppMapMarkers_FIELDLIST(X, a) \
X(a, CALLBACK, REPEATED, MESSAGE,  markers,           1)
#define AppMapMarkers_CALLBACK pb_default_field_callback
#define AppMapMarkers_DEFAULT NULL
#define AppMapMarkers_markers_MSGTYPE AppMarker

#define AppClanInfo_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, MESSAGE,  clan_info,         1)
#define AppClanInfo_CALLBACK NULL
#define AppClanInfo_DEFAULT NULL
#define AppClanInfo_clan_info_MSGTYPE ClanInfo

#define AppClanMessage_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, UINT64,   steam_id,          1) \
X(a, CALLBACK, OPTIONAL, STRING,   name,              2) \
X(a, CALLBACK, OPTIONAL, STRING,   message,           3) \
X(a, STATIC,   OPTIONAL, INT64,    time,              4)
#define AppClanMessage_CALLBACK pb_default_field_callback
#define AppClanMessage_DEFAULT NULL

#define AppClanChat_FIELDLIST(X, a) \
X(a, CALLBACK, REPEATED, MESSAGE,  messages,          1)
#define AppClanChat_CALLBACK pb_default_field_callback
#define AppClanChat_DEFAULT NULL
#define AppClanChat_messages_MSGTYPE AppClanMessage

#define AppNexusAuth_FIELDLIST(X, a) \
X(a, CALLBACK, OPTIONAL, STRING,   server_id,         1) \
X(a, STATIC,   OPTIONAL, INT32,    player_token,      2)
#define AppNexusAuth_CALLBACK pb_default_field_callback
#define AppNexusAuth_DEFAULT NULL

#define AppTeamChanged_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, UINT64,   player_id,         1) \
X(a, STATIC,   OPTIONAL, MESSAGE,  team_info,         2)
#define AppTeamChanged_CALLBACK NULL
#define AppTeamChanged_DEFAULT NULL
#define AppTeamChanged_team_info_MSGTYPE AppTeamInfo

#define AppNewTeamMessage_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, MESSAGE,  message,           1)
#define AppNewTeamMessage_CALLBACK NULL
#define AppNewTeamMessage_DEFAULT NULL
#define AppNewTeamMessage_message_MSGTYPE AppTeamMessage

#define AppEntityChanged_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, UINT64,   entity_id,         1) \
X(a, STATIC,   OPTIONAL, MESSAGE,  payload,           2)
#define AppEntityChanged_CALLBACK NULL
#define AppEntityChanged_DEFAULT NULL
#define AppEntityChanged_payload_MSGTYPE AppEntityPayload

#define AppClanChanged_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, MESSAGE,  clan_info,         1)
#define AppClanChanged_CALLBACK NULL
#define AppClanChanged_DEFAULT NULL
#define AppClanChanged_clan_info_MSGTYPE ClanInfo

#define AppNewClanMessage_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, INT64,    clan_id,           1) \
X(a, STATIC,   OPTIONAL, MESSAGE,  message,           2)
#define AppNewClanMessage_CALLBACK NULL
#define AppNewClanMessage_DEFAULT NULL
#define AppNewClanMessage_message_MSGTYPE AppClanMessage

#define AppCameraSubscribe_FIELDLIST(X, a) \
X(a, CALLBACK, OPTIONAL, STRING,   camera_id,         1)
#define AppCameraSubscribe_CALLBACK pb_default_field_callback
#define AppCameraSubscribe_DEFAULT NULL

#define AppCameraInput_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, INT32,    buttons,           1) \
X(a, STATIC,   OPTIONAL, MESSAGE,  mouse_delta,       2)
#define AppCameraInput_CALLBACK NULL
#define AppCameraInput_DEFAULT NULL
#define AppCameraInput_mouse_delta_MSGTYPE Vector2

#define AppCameraInfo_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, INT32,    width,             1) \
X(a, STATIC,   OPTIONAL, INT32,    height,            2) \
X(a, STATIC,   OPTIONAL, FLOAT,    near_plane,        3) \
X(a, STATIC,   OPTIONAL, FLOAT,    far_plane,         4) \
X(a, STATIC,   OPTIONAL, INT32,    control_flags,     5)
#define AppCameraInfo_CALLBACK NULL
#define AppCameraInfo_DEFAULT NULL

#define AppCameraRays_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, FLOAT,    vertical_fov,      1) \
X(a, STATIC,   OPTIONAL, INT32,    sample_offset,     2) \
X(a, CALLBACK, OPTIONAL, BYTES,    ray_data,          3) \
X(a, STATIC,   OPTIONAL, FLOAT,    distance,          4) \
X(a, CALLBACK, REPEATED, MESSAGE,  entities,          5) \
X(a, STATIC,   OPTIONAL, FLOAT,    time_of_day,       6) \
X(a, STATIC,   OPTIONAL, MESSAGE,  camera_position,   7) \
X(a, STATIC,   OPTIONAL, MESSAGE,  camera_rotation,   8)
#define AppCameraRays_CALLBACK pb_default_field_callback
#define AppCameraRays_DEFAULT NULL
#define AppCameraRays_entities_MSGTYPE AppCameraRays_Entity
#define AppCameraRays_camera_position_MSGTYPE Vector3
#define AppCameraRays_camera_rotation_MSGTYPE Vector3

#define AppCameraRays_Entity_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, UINT64,   entity_id,         1) \
X(a, STATIC,   OPTIONAL, UENUM,    type,              2) \
X(a, STATIC,   OPTIONAL, MESSAGE,  position,          3) \
X(a, STATIC,   OPTIONAL, MESSAGE,  rotation,          4) \
X(a, STATIC,   OPTIONAL, MESSAGE,  size,              5) \
X(a, CALLBACK, OPTIONAL, STRING,   name,              6)
#define AppCameraRays_Entity_CALLBACK pb_default_field_callback
#define AppCameraRays_Entity_DEFAULT (const pb_byte_t*)"\x10\x01\x00"
#define AppCameraRays_Entity_position_MSGTYPE Vector3
#define AppCameraRays_Entity_rotation_MSGTYPE Vector3
#define AppCameraRays_Entity_size_MSGTYPE Vector3

extern const pb_msgdesc_t Vector2_msg;
extern const pb_msgdesc_t Vector3_msg;
extern const pb_msgdesc_t Vector4_msg;
extern const pb_msgdesc_t Half3_msg;
extern const pb_msgdesc_t Color_msg;
extern const pb_msgdesc_t Ray_msg;
extern const pb_msgdesc_t ClanActionResult_msg;
extern const pb_msgdesc_t ClanInfo_msg;
extern const pb_msgdesc_t ClanInfo_Role_msg;
extern const pb_msgdesc_t ClanInfo_Member_msg;
extern const pb_msgdesc_t ClanInfo_Invite_msg;
extern const pb_msgdesc_t ClanLog_msg;
extern const pb_msgdesc_t ClanLog_Entry_msg;
extern const pb_msgdesc_t ClanInvitations_msg;
extern const pb_msgdesc_t ClanInvitations_Invitation_msg;
extern const pb_msgdesc_t AppRequest_msg;
extern const pb_msgdesc_t AppMessage_msg;
extern const pb_msgdesc_t AppResponse_msg;
extern const pb_msgdesc_t AppBroadcast_msg;
extern const pb_msgdesc_t AppEmpty_msg;
extern const pb_msgdesc_t AppSendMessage_msg;
extern const pb_msgdesc_t AppSetEntityValue_msg;
extern const pb_msgdesc_t AppPromoteToLeader_msg;
extern const pb_msgdesc_t AppGetNexusAuth_msg;
extern const pb_msgdesc_t AppSuccess_msg;
extern const pb_msgdesc_t AppError_msg;
extern const pb_msgdesc_t AppFlag_msg;
extern const pb_msgdesc_t AppInfo_msg;
extern const pb_msgdesc_t AppTime_msg;
extern const pb_msgdesc_t AppMap_msg;
extern const pb_msgdesc_t AppMap_Monument_msg;
extern const pb_msgdesc_t AppEntityInfo_msg;
extern const pb_msgdesc_t AppEntityPayload_msg;
extern const pb_msgdesc_t AppEntityPayload_Item_msg;
extern const pb_msgdesc_t AppTeamInfo_msg;
extern const pb_msgdesc_t AppTeamInfo_Member_msg;
extern const pb_msgdesc_t AppTeamInfo_Note_msg;
extern const pb_msgdesc_t AppTeamMessage_msg;
extern const pb_msgdesc_t AppTeamChat_msg;
extern const pb_msgdesc_t AppMarker_msg;
extern const pb_msgdesc_t AppMarker_SellOrder_msg;
extern const pb_msgdesc_t AppMapMarkers_msg;
extern const pb_msgdesc_t AppClanInfo_msg;
extern const pb_msgdesc_t AppClanMessage_msg;
extern const pb_msgdesc_t AppClanChat_msg;
extern const pb_msgdesc_t AppNexusAuth_msg;
extern const pb_msgdesc_t AppTeamChanged_msg;
extern const pb_msgdesc_t AppNewTeamMessage_msg;
extern const pb_msgdesc_t AppEntityChanged_msg;
extern const pb_msgdesc_t AppClanChanged_msg;
extern const pb_msgdesc_t AppNewClanMessage_msg;
extern const pb_msgdesc_t AppCameraSubscribe_msg;
extern const pb_msgdesc_t AppCameraInput_msg;
extern const pb_msgdesc_t AppCameraInfo_msg;
extern const pb_msgdesc_t AppCameraRays_msg;
extern const pb_msgdesc_t AppCameraRays_Entity_msg;

#define Vector2_fields &Vector2_msg
#define Vector3_fields &Vector3_msg
#define Vector4_fields &Vector4_msg
#define Half3_fields &Half3_msg
#define Color_fields &Color_msg
#define Ray_fields &Ray_msg
#define ClanActionResult_fields &ClanActionResult_msg
#define ClanInfo_fields &ClanInfo_msg
#define ClanInfo_Role_fields &ClanInfo_Role_msg
#define ClanInfo_Member_fields &ClanInfo_Member_msg
#define ClanInfo_Invite_fields &ClanInfo_Invite_msg
#define ClanLog_fields &ClanLog_msg
#define ClanLog_Entry_fields &ClanLog_Entry_msg
#define ClanInvitations_fields &ClanInvitations_msg
#define ClanInvitations_Invitation_fields &ClanInvitations_Invitation_msg
#define AppRequest_fields &AppRequest_msg
#define AppMessage_fields &AppMessage_msg
#define AppResponse_fields &AppResponse_msg
#define AppBroadcast_fields &AppBroadcast_msg
#define AppEmpty_fields &AppEmpty_msg
#define AppSendMessage_fields &AppSendMessage_msg
#define AppSetEntityValue_fields &AppSetEntityValue_msg
#define AppPromoteToLeader_fields &AppPromoteToLeader_msg
#define AppGetNexusAuth_fields &AppGetNexusAuth_msg
#define AppSuccess_fields &AppSuccess_msg
#define AppError_fields &AppError_msg
#define AppFlag_fields &AppFlag_msg
#define AppInfo_fields &AppInfo_msg
#define AppTime_fields &AppTime_msg
#define AppMap_fields &AppMap_msg
#define AppMap_Monument_fields &AppMap_Monument_msg
#define AppEntityInfo_fields &AppEntityInfo_msg
#define AppEntityPayload_fields &AppEntityPayload_msg
#define AppEntityPayload_Item_fields &AppEntityPayload_Item_msg
#define AppTeamInfo_fields &AppTeamInfo_msg
#define AppTeamInfo_Member_fields &AppTeamInfo_Member_msg
#define AppTeamInfo_Note_fields &AppTeamInfo_Note_msg
#define AppTeamMessage_fields &AppTeamMessage_msg
#define AppTeamChat_fields &AppTeamChat_msg
#define AppMarker_fields &AppMarker_msg
#define AppMarker_SellOrder_fields &AppMarker_SellOrder_msg
#define AppMapMarkers_fields &AppMapMarkers_msg
#define AppClanInfo_fields &AppClanInfo_msg
#define AppClanMessage_fields &AppClanMessage_msg
#define AppClanChat_fields &AppClanChat_msg
#define AppNexusAuth_fields &AppNexusAuth_msg
#define AppTeamChanged_fields &AppTeamChanged_msg
#define AppNewTeamMessage_fields &AppNewTeamMessage_msg
#define AppEntityChanged_fields &AppEntityChanged_msg
#define AppClanChanged_fields &AppClanChanged_msg
#define AppNewClanMessage_fields &AppNewClanMessage_msg
#define AppCameraSubscribe_fields &AppCameraSubscribe_msg
#define AppCameraInput_fields &AppCameraInput_msg
#define AppCameraInfo_fields &AppCameraInfo_msg
#define AppCameraRays_fields &AppCameraRays_msg
#define AppCameraRays_Entity_fields &AppCameraRays_Entity_msg

#define AppCameraInfo_size                       43
#define AppCameraInput_size                      23
#define AppEmpty_size                            0
#define AppEntityPayload_Item_size               24
#define AppFlag_size                             2
#define AppMarker_SellOrder_size                 74
#define AppPromoteToLeader_size                  11
#define AppSetEntityValue_size                   2
#define AppSuccess_size                          0
#define AppTime_size                             25
#define ClanInfo_Invite_size                     33
#define ClanInvitations_Invitation_size          33
#define Color_size                               20
#define Half3_size                               15
#define Ray_size                                 34
#define SRC_RUSTPLUS_PB_H_MAX_SIZE               AppMarker_SellOrder_size
#define Vector2_size                             10
#define Vector3_size                             15
#define Vector4_size                             20

#ifdef __cplusplus
}
#endif

#endif
