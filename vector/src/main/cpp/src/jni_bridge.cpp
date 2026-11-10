#include <jni.h>

#define JNI_FUNC(ret, name) JNIEXPORT ret JNICALL Java_im_vector_app_features_jumptodate_PcpNative_##name
#include <string>
#include <android/log.h>
#include "pcp/jumptodate.hpp"
#include "pcp/relation.hpp"
#include "pcp/exporter.hpp"
#include "pcp/eventcache.hpp"
#include "pcp/translate.hpp"
#include "pcp/proxy.hpp"
#include "pcp/yggdrasil.hpp"
#include "pcp/markdown.hpp"
#include "pcp/account_export.hpp"
#include "pcp/audio_engine.hpp"
#include "pcp/media_filter.hpp"
#include "pcp/content_filter.hpp"
#include "pcp/network_stats.hpp"
#include "pcp/masquerade.hpp"
#include "pcp/user_mask.hpp"
#include "pcp/chunked_upload.hpp"
#include "pcp/chat_features.hpp"
#include "pcp/invitation_hide.hpp"
#include "pcp/thread_aggregator.hpp"
#include "pcp/user_messages.hpp"
#include "pcp/room_version.hpp"
#include "pcp/chat_preview.hpp"
#include "pcp/ram_monitor.hpp"
#include "pcp/cache_manager.hpp"
#include "pcp/message_aggregator.hpp"
#include "pcp/room_info.hpp"
#include "pcp/deleted_archive.hpp"
#include "pcp/search_index.hpp"
#include "pcp/module_loader.hpp"
#include "pcp/notification.hpp"
#include "pcp/room_mirror.hpp"
#include "pcp/input_tools.hpp"
#include "pcp/llm.hpp"
#include "pcp/read_receipts.hpp"
#include "pcp/room_analytics.hpp"
#include "pcp/chat_tools.hpp"
#include "pcp/lang_detect.hpp"
#include "pcp/avatar_history.hpp"
#include "pcp/event_link.hpp"
#include "pcp/lightweight_call.hpp"
#include "pcp/scheduled_edit.hpp"
#include "pcp/svg_draw.hpp"
#include "pcp/profile_swiper.hpp"
#include "pcp/rainbow.hpp"
#include "pcp/text_formats.hpp"
#include "pcp/url_tools.hpp"
#include "pcp/notif_priority.hpp"
#include "pcp/matrix_patterns.hpp"
#include "pcp/desync_detector.hpp"
#include "pcp/latency_stats.hpp"
#include "pcp/string_utils.hpp"
#include "pcp/location_sharing.hpp"
#include "pcp/color_utils.hpp"
#include "pcp/e2ee_utils.hpp"
#include "pcp/thumbnail.hpp"
#include "pcp/waveform.hpp"
#include "pcp/session_timeout.hpp"
#include "pcp/password_validator.hpp"
#include "pcp/spellcheck.hpp"
#include "pcp/draft_manager.hpp"
#include "pcp/link_preview.hpp"
#include "pcp/hash_utils.hpp"
#include "pcp/room_stats.hpp"
#include "pcp/mention_parser.hpp"
#include "pcp/poll_utils.hpp"
#include "pcp/reaction_utils.hpp"
#include "pcp/file_validator.hpp"
#include "pcp/date_utils.hpp"
#include "pcp/message_queue.hpp"
#include "pcp/pinned_events.hpp"
#include "pcp/server_capabilities.hpp"
#include "pcp/username_validator.hpp"
#include "pcp/emoji_analyzer.hpp"
#include "pcp/identity_utils.hpp"
#include "pcp/notif_analyzer.hpp"
#include "pcp/sync_analyzer.hpp"
#include "pcp/user_rating.hpp"
#include "pcp/event_timeline.hpp"
#include "pcp/room_directory.hpp"
#include "pcp/widget_utils.hpp"
#include "pcp/sso_utils.hpp"
#include "pcp/backup_utils.hpp"
#include "pcp/device_manager.hpp"
#include "pcp/presence_utils.hpp"
#include "pcp/room_permissions.hpp"
#include "pcp/room_summary.hpp"
#include "pcp/membership_utils.hpp"
#include "pcp/event_validator.hpp"
#include "pcp/room_encryption.hpp"
#include "pcp/login_utils.hpp"
#include "pcp/connection_monitor.hpp"
#include "pcp/push_rules.hpp"
#include "pcp/space_utils.hpp"
#include "pcp/event_relations.hpp"
#include "pcp/e2ee_decoration.hpp"
#include "pcp/room_list.hpp"
#include "pcp/media_utils.hpp"
#include "pcp/notif_settings.hpp"
#include "pcp/invite_utils.hpp"
#include "pcp/session_manager.hpp"
#include "pcp/auth_utils.hpp"
#include "pcp/content_scanner.hpp"
#include "pcp/event_encryption.hpp"
#include "pcp/report_utils.hpp"
#include "pcp/webrtc_utils.hpp"
#include "pcp/message_retry.hpp"
#include "pcp/sync_utils.hpp"
#include "pcp/event_display.hpp"
#include "pcp/permalink.hpp"
#include "pcp/network_monitor.hpp"
#include "pcp/client_info.hpp"
#include "pcp/keyshare.hpp"
#include "pcp/displayname_utils.hpp"
#include "pcp/message_location.hpp"
#include "pcp/timeline_utils.hpp"
#include "pcp/cross_signing.hpp"
#include "pcp/edit_history.hpp"
#include "pcp/read_marker.hpp"
#include "pcp/slash_command.hpp"
#include "pcp/typing_monitor.hpp"
#include "pcp/url_preview.hpp"
#include "pcp/power_levels.hpp"
#include "pcp/well_known.hpp"
#include "pcp/room_sort.hpp"
#include "pcp/key_backup.hpp"
#include "pcp/content_utils.hpp"
#include "pcp/room_state.hpp"
#include "pcp/login_flow.hpp"
#include "pcp/device_naming.hpp"
#include "pcp/sync_filter.hpp"
#include "pcp/room_name.hpp"
#include "pcp/notif_format.hpp"
#include "pcp/matrix_error.hpp"
#include "pcp/agent_executor.hpp"
#include "pcp/push_condition.hpp"
#include "pcp/sender_notif_filter.hpp"
#include "pcp/string_order.hpp"
#include "pcp/event_classifier.hpp"
#include "pcp/content_guard.hpp"
#include "pcp/user_status.hpp"
#include "pcp/verification_utils.hpp"
#include "pcp/account_utils.hpp"
#include "pcp/account_data_utils.hpp"
#include "pcp/content_builder.hpp"
#include "pcp/event_utils.hpp"
#include "pcp/media_utils_extra.hpp"
#include "pcp/relation_builder.hpp"
#include <sstream>
#include <chrono>
#include <sstream>

using namespace pcp;

// --- Singleton keyword filter ---
static pcp::KeywordFilter g_keywordFilter;

// --- Singleton network stats collector ---
static pcp::NetworkStatsCollector g_netStats;

// --- Singleton user mask registry ---
static pcp::UserMaskRegistry g_userMasks;

// --- Singleton chunked uploader ---
static pcp::ChunkedUploader g_uploader;

// --- Singleton invitation hide list ---
static pcp::InvitationHideList g_inviteHide;

// --- Singleton thread aggregator ---
static pcp::ThreadAggregator g_threadAgg;

// --- Singleton cache manager ---
static pcp::CacheManager g_cacheMgr;

// --- Singleton message aggregator ---
static pcp::MessageAggregator g_msgAgg;

// --- Singleton deleted archive ---
static pcp::DeletedMessageArchive g_deletedArchive;

// --- Singleton search index ---
static pcp::SearchIndex g_searchIndex;

// --- Singleton module loader ---
static pcp::ModuleLoader g_moduleLoader;

// --- Singleton notification keywords ---
static pcp::NotificationKeywords g_notifKeywords;

// --- Singleton room mirror manager ---
static pcp::RoomMirrorManager g_mirrorMgr;

// --- Singleton symbol bar ---
static pcp::SymbolBar g_symbolBar;

// --- Singleton replacement engine ---
static pcp::ReplacementEngine g_replacementEngine;

// --- Singleton user MXID visibility ---
static pcp::UserMxidVisibility g_mxidVisibility;

// --- Singleton user hide manager ---
static pcp::UserHideManager g_userHide;

// --- Singleton message queue ---
static pcp::MessageQueue g_msgQueue;

// --- Singleton language hide manager ---
static pcp::LanguageHideManager g_langHide;

// --- Singleton chat push down ---
static pcp::ChatPushDownManager g_chatPushDown;

// --- Singleton emoji blacklist ---
static pcp::EmojiBlacklist g_emojiBlacklist;

// --- Singleton avatar history ---
static pcp::AvatarHistory g_avatarHistory;

// --- Singleton lightweight call manager ---
static pcp::LightweightCallManager g_lightCall;

// --- Singleton scheduled edit queue ---
static pcp::ScheduledEditQueue g_schedEdits;

// --- Singleton drawing canvas ---
static pcp::DrawingCanvas g_drawCanvas;

// --- Singleton profile swiper ---
static pcp::ProfileSwiper g_profileSwiper;

// --- Singleton connection monitor ---
static pcp::ConnectionMonitor g_connectionMonitor;

// --- Singleton desync detector ---
static pcp::DesyncDetector g_desyncDetector;

// --- Singleton latency tracker ---
static pcp::LatencyTracker g_latencyTracker;

// --- Singleton location sharing manager ---
static pcp::LocationSharingManager g_locationSharing;

#define LOG_TAG "PcpNative"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

extern "C" {

/*
 * Class: im.vector.app.features.jumptodate.PcpNative
 * Method: nativeValidateAndBuild
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Z)Ljava/lang/String;
 *
 * Returns JSON string: {"url": "...", ...} or {"error": "..."}
 */
JNIEXPORT jstring JNICALL
Java_im_vector_app_features_jumptodate_PcpNative_nativeValidateAndBuild(
    JNIEnv* env,
    jclass /* this */,
    jstring jRoomId,
    jstring jDateString,
    jstring jServerUrl,
    jstring jAccessToken,
    jboolean jIsEnabled
) {
    // Feature flag check — C++ gates the feature
    if (!jIsEnabled) {
        const char* err = R"({"error":"/jumptodate is disabled. Enable it in Settings → Labs."})";
        return env->NewStringUTF(err);
    }
    if (!jRoomId || !jDateString || !jServerUrl || !jAccessToken) {
        jclass exClass = env->FindClass("java/lang/IllegalArgumentException");
        env->ThrowNew(exClass, "All parameters must be non-null");
        return nullptr;
    }

    // Convert Java strings to C++ strings
    const char* roomIdCh     = env->GetStringUTFChars(jRoomId, nullptr);
    const char* dateCh       = env->GetStringUTFChars(jDateString, nullptr);
    const char* serverUrlCh  = env->GetStringUTFChars(jServerUrl, nullptr);
    const char* accessTokenCh = env->GetStringUTFChars(jAccessToken, nullptr);

    pcp::JumpToDateRequest request;
    request.roomId        = std::string(roomIdCh);
    request.dateString    = std::string(dateCh);
    request.serverBaseUrl = std::string(serverUrlCh);
    request.accessToken   = std::string(accessTokenCh);

    // Release Java strings
    env->ReleaseStringUTFChars(jRoomId, roomIdCh);
    env->ReleaseStringUTFChars(jDateString, dateCh);
    env->ReleaseStringUTFChars(jServerUrl, serverUrlCh);
    env->ReleaseStringUTFChars(jAccessToken, accessTokenCh);

    LOGD("nativeJumpToDate called: roomId=%s date=%s", request.roomId.c_str(), request.dateString.c_str());

    // Validate date and compute timestamp
    if (!pcp::validateAndComputeTimestamp(request)) {
        std::string errorJson = R"({"error":")" + request.errorMessage + R"("})";
        return env->NewStringUTF(errorJson.c_str());
    }

    // Build the MSC3030 URL
    std::string url = pcp::buildMsc3030Url(request);
    LOGD("MSC3030 URL: %s", url.c_str());

    // Return the URL and timestamp to Kotlin — HTTP call happens in Kotlin layer
    std::string resultJson =
        R"({"url":")" + url +
        R"(","accessToken":")" + request.accessToken +
        R"(","timestamp":)" + std::to_string(request.originServerTs) +
        R"(})";
    return env->NewStringUTF(resultJson.c_str());
}

/*
 * Class: im.vector.app.features.jumptodate.PcpNative
 * Method: nativeParseResponse
 * Signature: (Ljava/lang/String;I)Ljava/lang/String;
 *
 * Parses the HTTP response body and returns JSON with eventId or error.
 */
JNIEXPORT jstring JNICALL
Java_im_vector_app_features_jumptodate_PcpNative_nativeParseResponse(
    JNIEnv* env,
    jclass /* this */,
    jstring jResponseBody,
    jint httpStatus
) {
    if (!jResponseBody) {
        jclass exClass = env->FindClass("java/lang/IllegalArgumentException");
        env->ThrowNew(exClass, "Response body must be non-null");
        return nullptr;
    }

    const char* bodyCh = env->GetStringUTFChars(jResponseBody, nullptr);
    std::string body(bodyCh);
    env->ReleaseStringUTFChars(jResponseBody, bodyCh);

    LOGD("nativeParseResponse: status=%d body_len=%zu", httpStatus, body.size());

    auto result = pcp::parseTimestampToEventResponse(body, httpStatus);

    if (result.success) {
        std::string json = R"({"eventId":")" + result.eventId + R"("})";
        return env->NewStringUTF(json.c_str());
    } else {
        std::string json =
            R"({"error":")" + result.errorMessage +
            R"(","statusCode":)" + std::to_string(result.statusCode) + R"(})";
        return env->NewStringUTF(json.c_str());
    }
}

/*
 * Class: im.vector.app.features.jumptodate.PcpNative
 * Method: nativeParseRelation
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 *
 * Parses event JSON to find the source event this event relates to.
 * @param eventJson  Full JSON of the Matrix event
 * @param allowedTypes  Comma-separated list of allowed relation types (e.g. "m.annotation,m.reference")
 *                      or empty string for all types.
 *
 * Returns JSON: {"sourceEventId": "$xyz", "relationType": "m.annotation"} or {"isRelation": false}
 */
JNIEXPORT jstring JNICALL
Java_im_vector_app_features_jumptodate_PcpNative_nativeParseRelation(
    JNIEnv* env,
    jclass /* this */,
    jstring jEventJson,
    jstring jAllowedTypes
) {
    if (!jEventJson) {
        jclass exClass = env->FindClass("java/lang/IllegalArgumentException");
        env->ThrowNew(exClass, "Event JSON must be non-null");
        return nullptr;
    }

    const char* jsonCh = env->GetStringUTFChars(jEventJson, nullptr);
    std::string json(jsonCh);
    env->ReleaseStringUTFChars(jEventJson, jsonCh);

    LOGD("nativeParseRelation: eventJson_len=%zu", json.size());

    auto relation = pcp::parseRelation(json);

    if (!relation.isRelation) {
        return env->NewStringUTF(R"({"isRelation": false})");
    }

    // Check if this relation type is allowed
    bool allowed = true;
    if (jAllowedTypes) {
        const char* allowedCh = env->GetStringUTFChars(jAllowedTypes, nullptr);
        std::string allowedStr(allowedCh);
        env->ReleaseStringUTFChars(jAllowedTypes, allowedCh);

        if (!allowedStr.empty()) {
            allowed = pcp::isJumpableRelationType(relation.relationType) &&
                      allowedStr.find(relation.relationType) != std::string::npos;
        }
    } else {
        allowed = pcp::isJumpableRelationType(relation.relationType);
    }

    if (!allowed) {
        return env->NewStringUTF(R"({"isRelation": false})");
    }

    std::string resultJson =
        R"({"isRelation": true, "sourceEventId": ")" + relation.sourceEventId +
        R"(", "relationType": ")" + relation.relationType + R"("})";
    return env->NewStringUTF(resultJson.c_str());
}

/*
 * Class: im.vector.app.features.jumptodate.PcpNative
 * Method: nativeFormatEventHtml
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Z)Ljava/lang/String;
 *
 * Formats a single event as HTML.
 * @param senderName  Display name of the sender
 * @param timestamp   ISO 8601 timestamp string
 * @param body        Plain text body
 * @param msgType     Message type (m.text, m.image, etc.)
 * @param fileName    Attachment filename if applicable
 * @param mediaSize   Attachment size in bytes as string (empty if none)
 * @param relationType Relation type string (m.annotation, m.reference, etc.)
 * @param isContinuation Whether this event is from the same sender as previous
 */
JNIEXPORT jstring JNICALL
Java_im_vector_app_features_jumptodate_PcpNative_nativeFormatEventHtml(
    JNIEnv* env,
    jclass /* this */,
    jstring jSenderName,
    jstring jTimestamp,
    jstring jBody,
    jstring jMsgType,
    jstring jFileName,
    jstring jMediaSize,
    jstring jRelationType,
    jboolean jIsContinuation
) {
    ExportEvent event;
    event.senderName   = jSenderName ? std::string(env->GetStringUTFChars(jSenderName, nullptr)) : "";
    event.timestamp    = jTimestamp ? std::string(env->GetStringUTFChars(jTimestamp, nullptr)) : "";
    event.body         = jBody ? std::string(env->GetStringUTFChars(jBody, nullptr)) : "";
    event.msgType      = jMsgType ? std::string(env->GetStringUTFChars(jMsgType, nullptr)) : "";
    event.fileName     = jFileName ? std::string(env->GetStringUTFChars(jFileName, nullptr)) : "";
    event.relationType = jRelationType ? std::string(env->GetStringUTFChars(jRelationType, nullptr)) : "";

    if (jMediaSize) {
        auto sizeStr = std::string(env->GetStringUTFChars(jMediaSize, nullptr));
        if (!sizeStr.empty()) event.mediaSize = std::stoll(sizeStr);
        env->ReleaseStringUTFChars(jMediaSize, sizeStr.c_str());
    }

    // Release all strings
    if (jSenderName)   env->ReleaseStringUTFChars(jSenderName, event.senderName.c_str());
    if (jTimestamp)    env->ReleaseStringUTFChars(jTimestamp, event.timestamp.c_str());
    if (jBody)         env->ReleaseStringUTFChars(jBody, event.body.c_str());
    if (jMsgType)      env->ReleaseStringUTFChars(jMsgType, event.msgType.c_str());
    if (jFileName)     env->ReleaseStringUTFChars(jFileName, event.fileName.c_str());
    if (jRelationType) env->ReleaseStringUTFChars(jRelationType, event.relationType.c_str());

    auto html = pcp::formatEventHtml(event, jIsContinuation);
    return env->NewStringUTF(html.c_str());
}

/*
 * Class: im.vector.app.features.jumptodate.PcpNative
 * Method: nativeFormatEventPlainText
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 *
 * Formats a single event as plain text line.
 */
JNIEXPORT jstring JNICALL
Java_im_vector_app_features_jumptodate_PcpNative_nativeFormatEventPlainText(
    JNIEnv* env,
    jclass /* this */,
    jstring jSenderName,
    jstring jTimestamp,
    jstring jBody,
    jstring jMsgType,
    jstring jFileName,
    jstring jRelationType
) {
    ExportEvent event;
    event.senderName   = jSenderName ? std::string(env->GetStringUTFChars(jSenderName, nullptr)) : "";
    event.timestamp    = jTimestamp ? std::string(env->GetStringUTFChars(jTimestamp, nullptr)) : "";
    event.body         = jBody ? std::string(env->GetStringUTFChars(jBody, nullptr)) : "";
    event.msgType      = jMsgType ? std::string(env->GetStringUTFChars(jMsgType, nullptr)) : "";
    event.fileName     = jFileName ? std::string(env->GetStringUTFChars(jFileName, nullptr)) : "";
    event.relationType = jRelationType ? std::string(env->GetStringUTFChars(jRelationType, nullptr)) : "";

    if (jSenderName)   env->ReleaseStringUTFChars(jSenderName, event.senderName.c_str());
    if (jTimestamp)    env->ReleaseStringUTFChars(jTimestamp, event.timestamp.c_str());
    if (jBody)         env->ReleaseStringUTFChars(jBody, event.body.c_str());
    if (jMsgType)      env->ReleaseStringUTFChars(jMsgType, event.msgType.c_str());
    if (jFileName)     env->ReleaseStringUTFChars(jFileName, event.fileName.c_str());
    if (jRelationType) env->ReleaseStringUTFChars(jRelationType, event.relationType.c_str());

    auto text = pcp::formatEventPlainText(event);
    return env->NewStringUTF(text.c_str());
}

/*
 * Class: im.vector.app.features.jumptodate.PcpNative
 * Method: nativeBuildHtmlExport
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;[Ljava/lang/String;)Ljava/lang/String;
 *
 * Builds a complete HTML export document from event HTML strings.
 * @param roomName    Room display name
 * @param roomTopic   Room topic
 * @param exportDate  ISO date of export
 * @param eventHtmls  Array of pre-rendered event HTML strings
 */
JNIEXPORT jstring JNICALL
Java_im_vector_app_features_jumptodate_PcpNative_nativeBuildHtmlExport(
    JNIEnv* env,
    jclass /* this */,
    jstring jRoomName,
    jstring jRoomTopic,
    jstring jExportDate,
    jobjectArray jEventHtmls
) {
    auto roomName   = jRoomName ? std::string(env->GetStringUTFChars(jRoomName, nullptr)) : "";
    auto roomTopic  = jRoomTopic ? std::string(env->GetStringUTFChars(jRoomTopic, nullptr)) : "";
    auto exportDate = jExportDate ? std::string(env->GetStringUTFChars(jExportDate, nullptr)) : "";

    if (jRoomName)  env->ReleaseStringUTFChars(jRoomName, roomName.c_str());
    if (jRoomTopic) env->ReleaseStringUTFChars(jRoomTopic, roomTopic.c_str());
    if (jExportDate) env->ReleaseStringUTFChars(jExportDate, exportDate.c_str());

    // Build HTML document — events are already formatted, wrap them
    std::ostringstream html;
    html << "<!DOCTYPE html>\n<html lang=\"en\">\n<head>\n";
    html << "<meta charset=\"UTF-8\">\n";
    html << "<title>" << escapeHtml(roomName) << " — Chat Export</title>\n";
    html << R"(<style>
body { font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, sans-serif; margin: 0; padding: 16px; background: #f5f5f5; }
.mx_ExportHeader { background: #fff; border-radius: 8px; padding: 16px; margin-bottom: 16px; box-shadow: 0 1px 3px rgba(0,0,0,0.1); }
.mx_ExportHeader h1 { margin: 0 0 8px; font-size: 1.5em; }
.mx_ExportHeader p { margin: 4px 0; color: #666; font-size: 0.9em; }
.mx_EventTile { background: #fff; border-radius: 8px; padding: 12px 16px; margin-bottom: 8px; box-shadow: 0 1px 2px rgba(0,0,0,0.05); }
.mx_EventTile_continuation { margin-top: -4px; border-radius: 0 0 8px 8px; }
.mx_EventTile_info { margin-bottom: 6px; }
.mx_EventTile_sender { font-weight: 600; color: #333; margin-right: 8px; }
.mx_MessageTimestamp { color: #999; font-size: 0.85em; }
.mx_EventTile_body { color: #222; line-height: 1.5; }
.mx_EventTile_attachment { background: #f0f0f0; border-radius: 4px; padding: 8px; margin-bottom: 8px; }
.mx_Attachment_name { font-weight: 500; }
.mx_Attachment_size { color: #999; margin-left: 8px; }
.mx_EventTile_reaction { font-style: italic; color: #666; }
.mx_EventTile_content { white-space: pre-wrap; word-wrap: break-word; }
hr { border: none; border-top: 1px solid #e0e0e0; margin: 16px 0; }
</style>)" << "\n";
    html << "</head>\n<body>\n";
    html << "<div class=\"mx_ExportHeader\">\n";
    html << "  <h1>" << escapeHtml(roomName) << "</h1>\n";
    if (!roomTopic.empty()) html << "  <p>" << escapeHtml(roomTopic) << "</p>\n";
    html << "  <p>Exported: " << exportDate << "</p>\n";

    jsize count = env->GetArrayLength(jEventHtmls);
    html << "  <p>Total messages: " << count << "</p>\n";
    html << "</div>\n";

    for (jsize i = 0; i < count; ++i) {
        auto jHtml = (jstring)env->GetObjectArrayElement(jEventHtmls, i);
        if (jHtml) {
            auto htmlStr = std::string(env->GetStringUTFChars(jHtml, nullptr));
            html << htmlStr;
            env->ReleaseStringUTFChars(jHtml, htmlStr.c_str());
        }
    }

    html << "<hr>\n<p style=\"color:#999;text-align:center;\">Exported with PCP</p>\n";
    html << "</body>\n</html>";

    return env->NewStringUTF(html.str().c_str());
}

// --- Event Cache (global singleton for Stage 2 acceleration) ---
static pcp::EventCache g_eventCache;

/*
 * Class: im.vector.app.features.jumptodate.PcpNative
 * Method: nativeCachePut
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Z)V
 */
JNIEXPORT void JNICALL
Java_im_vector_app_features_jumptodate_PcpNative_nativeCachePut(
    JNIEnv* env,
    jclass /* this */,
    jstring jEventId,
    jstring jSenderId,
    jstring jSenderName,
    jstring jTimestamp,
    jstring jBody,
    jstring jMsgType,
    jstring jEventType,
    jstring jRelationType,
    jstring jSourceEventId,
    jboolean jSentByMe
) {
    CachedEvent event;
    event.eventId     = jEventId ? std::string(env->GetStringUTFChars(jEventId, nullptr)) : "";
    event.senderId    = jSenderId ? std::string(env->GetStringUTFChars(jSenderId, nullptr)) : "";
    event.senderName  = jSenderName ? std::string(env->GetStringUTFChars(jSenderName, nullptr)) : "";
    event.timestamp   = jTimestamp ? std::string(env->GetStringUTFChars(jTimestamp, nullptr)) : "";
    event.body        = jBody ? std::string(env->GetStringUTFChars(jBody, nullptr)) : "";
    event.msgType     = jMsgType ? std::string(env->GetStringUTFChars(jMsgType, nullptr)) : "";
    event.eventType   = jEventType ? std::string(env->GetStringUTFChars(jEventType, nullptr)) : "";
    event.relationType = jRelationType ? std::string(env->GetStringUTFChars(jRelationType, nullptr)) : "";
    event.sourceEventId = jSourceEventId ? std::string(env->GetStringUTFChars(jSourceEventId, nullptr)) : "";
    event.sentByMe    = jSentByMe;

    // Release strings
    if (jEventId)     env->ReleaseStringUTFChars(jEventId, event.eventId.c_str());
    if (jSenderId)    env->ReleaseStringUTFChars(jSenderId, event.senderId.c_str());
    if (jSenderName)  env->ReleaseStringUTFChars(jSenderName, event.senderName.c_str());
    if (jTimestamp)   env->ReleaseStringUTFChars(jTimestamp, event.timestamp.c_str());
    if (jBody)        env->ReleaseStringUTFChars(jBody, event.body.c_str());
    if (jMsgType)     env->ReleaseStringUTFChars(jMsgType, event.msgType.c_str());
    if (jEventType)   env->ReleaseStringUTFChars(jEventType, event.eventType.c_str());
    if (jRelationType) env->ReleaseStringUTFChars(jRelationType, event.relationType.c_str());
    if (jSourceEventId) env->ReleaseStringUTFChars(jSourceEventId, event.sourceEventId.c_str());

    g_eventCache.put(event);
}

/*
 * Class: im.vector.app.features.jumptodate.PcpNative
 * Method: nativeCacheGetContext
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL
Java_im_vector_app_features_jumptodate_PcpNative_nativeCacheGetContext(
    JNIEnv* env,
    jclass /* this */,
    jstring jEventId
) {
    if (!jEventId) {
        return env->NewStringUTF(R"({"cached": false})");
    }

    auto eventId = std::string(env->GetStringUTFChars(jEventId, nullptr));
    env->ReleaseStringUTFChars(jEventId, eventId.c_str());

    auto json = g_eventCache.getContextData(eventId);
    return env->NewStringUTF(json.c_str());
}

/*
 * Class: im.vector.app.features.jumptodate.PcpNative
 * Method: nativeCacheSize
 * Signature: ()I
 */
JNIEXPORT jint JNICALL
Java_im_vector_app_features_jumptodate_PcpNative_nativeCacheSize(
    JNIEnv* /* env */,
    jclass /* this */
) {
    return static_cast<jint>(g_eventCache.size());
}

// --- Translation ---

/*
 * Class: im.vector.app.features.jumptodate.PcpNative
 * Method: nativeBuildTranslateRequest
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL
Java_im_vector_app_features_jumptodate_PcpNative_nativeBuildTranslateRequest(
    JNIEnv* env, jclass,
    jstring jText, jstring jSourceLang, jstring jTargetLang,
    jstring jApiEndpoint, jstring jApiToken, jstring jModel
) {
    TranslateRequest req;
    req.text           = jText ? std::string(env->GetStringUTFChars(jText, nullptr)) : "";
    req.sourceLanguage = jSourceLang ? std::string(env->GetStringUTFChars(jSourceLang, nullptr)) : "";
    req.targetLanguage = jTargetLang ? std::string(env->GetStringUTFChars(jTargetLang, nullptr)) : "";
    req.apiEndpoint    = jApiEndpoint ? std::string(env->GetStringUTFChars(jApiEndpoint, nullptr)) : "";
    req.apiToken       = jApiToken ? std::string(env->GetStringUTFChars(jApiToken, nullptr)) : "";
    req.model          = jModel ? std::string(env->GetStringUTFChars(jModel, nullptr)) : "gpt-4o-mini";

    if (jText)        env->ReleaseStringUTFChars(jText, req.text.c_str());
    if (jSourceLang)  env->ReleaseStringUTFChars(jSourceLang, req.sourceLanguage.c_str());
    if (jTargetLang)  env->ReleaseStringUTFChars(jTargetLang, req.targetLanguage.c_str());
    if (jApiEndpoint) env->ReleaseStringUTFChars(jApiEndpoint, req.apiEndpoint.c_str());
    if (jApiToken)    env->ReleaseStringUTFChars(jApiToken, req.apiToken.c_str());
    if (jModel)       env->ReleaseStringUTFChars(jModel, req.model.c_str());

    auto body = pcp::buildTranslateRequestBody(req);
    return env->NewStringUTF(body.c_str());
}

/*
 * Class: im.vector.app.features.jumptodate.PcpNative
 * Method: nativeParseTranslateResponse
 * Signature: (Ljava/lang/String;I)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL
Java_im_vector_app_features_jumptodate_PcpNative_nativeParseTranslateResponse(
    JNIEnv* env, jclass,
    jstring jResponseBody, jint jHttpStatus
) {
    if (!jResponseBody) {
        return env->NewStringUTF(R"({"success": false, "error": "Empty response"})");
    }
    auto body = std::string(env->GetStringUTFChars(jResponseBody, nullptr));
    env->ReleaseStringUTFChars(jResponseBody, body.c_str());

    auto result = pcp::parseTranslateResponse(body, jHttpStatus);

    if (result.success) {
        std::string json = R"({"success": true, "translatedText": ")" + result.translatedText + R"("})";
        return env->NewStringUTF(json.c_str());
    } else {
        std::string json = R"({"success": false, "error": ")" + result.errorMessage + R"(", "statusCode": )"
            + std::to_string(result.statusCode) + "}";
        return env->NewStringUTF(json.c_str());
    }
}

// --- Proxy Configuration ---

/*
 * Class: im.vector.app.features.jumptodate.PcpNative
 * Method: nativeComputeProxyConfig
 * Signature: (IILjava/lang/String;ILjava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL
Java_im_vector_app_features_jumptodate_PcpNative_nativeComputeProxyConfig(
    JNIEnv* env, jclass,
    jint jConnType, jint jProxyType,
    jstring jHost, jint jPort,
    jstring jUsername, jstring jPassword
) {
    auto connType = static_cast<ConnectionType>(jConnType);
    auto proxyType = static_cast<ProxyType>(jProxyType);

    auto host     = jHost ? std::string(env->GetStringUTFChars(jHost, nullptr)) : "";
    auto username = jUsername ? std::string(env->GetStringUTFChars(jUsername, nullptr)) : "";
    auto password = jPassword ? std::string(env->GetStringUTFChars(jPassword, nullptr)) : "";

    if (jHost)     env->ReleaseStringUTFChars(jHost, host.c_str());
    if (jUsername) env->ReleaseStringUTFChars(jUsername, username.c_str());
    if (jPassword) env->ReleaseStringUTFChars(jPassword, password.c_str());

    auto config = pcp::computeProxyConfig(
        connType, proxyType, host, jPort, username, password
    );

    auto json = config.toJson();
    return env->NewStringUTF(json.c_str());
}

// --- Yggdrasil ---

JNIEXPORT jboolean JNICALL
Java_im_vector_app_features_jumptodate_PcpNative_nativeIsYggdrasilAddress(
    JNIEnv* env, jclass, jstring jAddr
) {
    if (!jAddr) return JNI_FALSE;
    auto addr = std::string(env->GetStringUTFChars(jAddr, nullptr));
    env->ReleaseStringUTFChars(jAddr, addr.c_str());
    return pcp::isYggdrasilAddress(addr) ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT jboolean JNICALL
Java_im_vector_app_features_jumptodate_PcpNative_nativeIsYggdrasilDomain(
    JNIEnv* env, jclass, jstring jHost
) {
    if (!jHost) return JNI_FALSE;
    auto host = std::string(env->GetStringUTFChars(jHost, nullptr));
    env->ReleaseStringUTFChars(jHost, host.c_str());
    return pcp::isYggdrasilDomain(host) ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT jstring JNICALL
Java_im_vector_app_features_jumptodate_PcpNative_nativeBuildYggHomeserverUrl(
    JNIEnv* env, jclass, jstring jAddr, jint jPort, jboolean jTls
) {
    if (!jAddr) return env->NewStringUTF("");
    auto addr = std::string(env->GetStringUTFChars(jAddr, nullptr));
    env->ReleaseStringUTFChars(jAddr, addr.c_str());
    auto url = pcp::buildYggHomeserverUrl(addr, jPort, jTls);
    return env->NewStringUTF(url.c_str());
}

JNIEXPORT jstring JNICALL
Java_im_vector_app_features_jumptodate_PcpNative_nativeRewriteHomeserverUrl(
    JNIEnv* env, jclass, jstring jOriginalUrl, jstring jYggAddr
) {
    if (!jOriginalUrl || !jYggAddr) return env->NewStringUTF("");
    auto original = std::string(env->GetStringUTFChars(jOriginalUrl, nullptr));
    auto ygg = std::string(env->GetStringUTFChars(jYggAddr, nullptr));
    env->ReleaseStringUTFChars(jOriginalUrl, original.c_str());
    env->ReleaseStringUTFChars(jYggAddr, ygg.c_str());
    auto result = pcp::rewriteHomeserverUrl(original, ygg);
    return env->NewStringUTF(result.c_str());
}

// --- Read Marker Time Label ---

JNIEXPORT jstring JNICALL
Java_im_vector_app_features_jumptodate_PcpNative_nativeFormatJumpToUnreadLabel(
    JNIEnv* env, jclass, jstring jReadMarkerJson, jlong jNowMs
) {
    auto json = jReadMarkerJson ? std::string(env->GetStringUTFChars(jReadMarkerJson, nullptr)) : "{}";
    if (jReadMarkerJson) env->ReleaseStringUTFChars(jReadMarkerJson, json.c_str());

    pcp::ReadMarkerState state;
    // Quick parse from JSON
    if (json.find("\"hasUnread\": true") != std::string::npos ||
        json.find("\"hasUnread\":true") != std::string::npos) state.hasUnread = true;
    // Extract timestamp
    auto tsPos = json.find("\"firstUnreadTimestampMs\"");
    if (tsPos != std::string::npos) {
        auto colon = json.find(':', tsPos);
        if (colon != std::string::npos) {
            colon++;
            while (colon < json.size() && (json[colon] == ' ' || json[colon] == '\t')) colon++;
            while (colon < json.size() && json[colon] >= '0' && json[colon] <= '9') {
                state.firstUnreadTimestampMs = state.firstUnreadTimestampMs * 10 + (json[colon] - '0');
                colon++;
            }
        }
    }

    auto label = pcp::formatJumpToUnreadLabel(state, jNowMs);
    return env->NewStringUTF(label.c_str());
}

// ==== PCP v0.2 JNI Bridges ====
// NOTE: v0.2 bridges require jStr helper and parseJsonStringArray which
// are not yet implemented. This section is temporarily disabled.
#if 0

// --- Event Summary ---
JNI_FUNC(jstring, nativeFormatEventSummary)(JNIEnv* env, jclass,
    jstring jType, jstring jMsgType, jstring jSender, jstring jBody,
    jstring jMembership, jstring jDisplayName, jboolean jRedacted, jboolean jEncrypted)
{
    auto result = pcp::formatEventSummary(
        jStr(env, jType), jStr(env, jMsgType), jStr(env, jSender), jStr(env, jBody),
        jStr(env, jMembership), jStr(env, jDisplayName), jRedacted, jEncrypted);
    return env->NewStringUTF(result.c_str());
}

// --- Typing Indicator ---
JNI_FUNC(jstring, nativeFormatTypingIndicator)(JNIEnv* env, jclass, jstring jNamesJson, jint jMax) {
    auto names = pcp::parseJsonStringArray(jStr(env, jNamesJson));
    auto result = pcp::formatTypingIndicator(names, jMax);
    return env->NewStringUTF(result.c_str());
}

// --- Calculate Capabilities ---
JNI_FUNC(jstring, nativeCalculateCapabilities)(JNIEnv* env, jclass, jint u, jint e, jint s,
    jint i, jint k, jint b, jint r, jint n)
{
    auto caps = pcp::calculateCapabilities(u, e, s, i, k, b, r, n);
    std::ostringstream os;
    os << R"({"isOwner":)" << caps.isOwner
       << R"(,"isModerator":)" << caps.isModerator
       << R"(,"canSendMessages":)" << caps.canSendMessages
       << R"(,"canInvite":)" << caps.canInvite
       << R"(,"canKick":)" << caps.canKick
       << R"(,"canBan":)" << caps.canBan
       << R"(,"canRedact":)" << caps.canRedact << "}";
    return env->NewStringUTF(os.str().c_str());
}

// --- Content Builder ---
JNI_FUNC(jstring, nativeBuildTextContent)(JNIEnv* env, jclass, jstring jType, jstring jBody, jstring jFb) {
    auto result = pcp::buildTextContent(jStr(env, jType), jStr(env, jBody), jStr(env, jFb));
    return env->NewStringUTF(result.c_str());
}
JNI_FUNC(jstring, nativeBuildImageContent)(JNIEnv* env, jclass, jstring jBody, jstring jUrl,
    jint jW, jint jH, jlong jSz, jstring jMime) {
    auto result = pcp::buildImageContent(jStr(env, jBody), jStr(env, jUrl), jW, jH, jSz, jStr(env, jMime));
    return env->NewStringUTF(result.c_str());
}
JNI_FUNC(jstring, nativeBuildFileContent)(JNIEnv* env, jclass, jstring jBody, jstring jUrl,
    jstring jFn, jlong jSz, jstring jMime) {
    auto result = pcp::buildFileContent(jStr(env, jBody), jStr(env, jUrl), jStr(env, jFn), jSz, jStr(env, jMime));
    return env->NewStringUTF(result.c_str());
}

// --- Media ---
JNI_FUNC(jstring, nativeFormatFileSize)(JNIEnv* env, jclass, jlong jBytes) {
    return env->NewStringUTF(pcp::formatFileSize(jBytes).c_str());
}
JNI_FUNC(jstring, nativeFormatDuration)(JNIEnv* env, jclass, jlong jMs) {
    return env->NewStringUTF(pcp::formatDuration(jMs).c_str());
}
JNI_FUNC(jstring, nativeSanitizeFilename)(JNIEnv* env, jclass, jstring jName, jint jLen) {
    return env->NewStringUTF(pcp::sanitizeFilename(jStr(env, jName), jLen).c_str());
}

// --- Account Data ---
JNI_FUNC(jstring, nativeParseDirectMessages)(JNIEnv* env, jclass, jstring jJson) {
    auto dm = pcp::parseDirectMessageMap(jStr(env, jJson));
    return env->NewStringUTF(pcp::buildDirectMessageMapJson(dm).c_str());
}
JNI_FUNC(jstring, nativeParseIgnoredUsers)(JNIEnv* env, jclass, jstring jJson) {
    auto list = pcp::parseIgnoredUsers(jStr(env, jJson));
    std::ostringstream os; os << "["; for (size_t i = 0; i < list.size(); i++) {
        if (i>0) os<<","; os<<"\""<<list[i]<<"\""; } os<<"]";
    return env->NewStringUTF(os.str().c_str());
}
JNI_FUNC(jstring, nativeAddBreadcrumb)(JNIEnv* env, jclass, jstring jJson, jstring jRoom) {
    auto result = pcp::addBreadcrumb(jStr(env, jJson), jStr(env, jRoom));
    return env->NewStringUTF(result.c_str());
}
JNI_FUNC(jboolean, nativeIsValidUserId)(JNIEnv*, jclass, jstring jId) {
    return pcp::isValidUserId(jStr(nullptr, jId));
}
JNI_FUNC(jstring, nativeServerNameFromMxid)(JNIEnv* env, jclass, jstring jMxid) {
    return env->NewStringUTF(pcp::serverNameFromMxid(jStr(env, jMxid)).c_str());
}

// --- Relation Builder ---
JNI_FUNC(jstring, nativeBuildReplyRelation)(JNIEnv* env, jclass, jstring jId) {
    return env->NewStringUTF(pcp::buildReplyRelation(jStr(env, jId)).c_str());
}
JNI_FUNC(jstring, nativeBuildThreadRelation)(JNIEnv* env, jclass, jstring jR, jstring jL, jboolean jFb) {
    return env->NewStringUTF(pcp::buildThreadRelation(jStr(env, jR), jStr(env, jL), jFb).c_str());
}
JNI_FUNC(jstring, nativeBuildEditRelation)(JNIEnv* env, jclass, jstring jId) {
    return env->NewStringUTF(pcp::buildReplaceRelation(jStr(env, jId)).c_str());
}
JNI_FUNC(jstring, nativeBuildReactionRelation)(JNIEnv* env, jclass, jstring jId, jstring jKey) {
    return env->NewStringUTF(pcp::buildReactionRelation(jStr(env, jId), jStr(env, jKey)).c_str());
}
JNI_FUNC(jstring, nativeWrapWithRelation)(JNIEnv* env, jclass, jstring jContent, jstring jRel) {
    return env->NewStringUTF(pcp::wrapWithRelation(jStr(env, jContent), jStr(env, jRel)).c_str());
}

#endif // v0.2 JNI Bridges

} // extern "C"
