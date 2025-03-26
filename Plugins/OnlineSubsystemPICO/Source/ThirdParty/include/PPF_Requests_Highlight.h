// This file is generated automatically. Please don't edit it.


#ifndef PPF_REQUESTS_HIGHLIGHT_H
#define PPF_REQUESTS_HIGHLIGHT_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"


/// A message with type ::ppfMessageType_Highlight_CaptureScreen will be generated in response.
/// First call ::ppf_Message_IsError() to check if an error occurred.
/// Extract the payload from the message handle with ::ppf_Message_GetCaptureInfo().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Highlight_CaptureScreen();

/// A message with type ::ppfMessageType_Highlight_ListMedia will be generated in response.
/// First call ::ppf_Message_IsError() to check if an error occurred.
/// Extract the payload from the message handle with ::ppf_Message_GetSessionMedia().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Highlight_ListMedia(const char* sessionId);

/// A message with type ::ppfMessageType_Highlight_SaveMedia will be generated in response.
/// First call ::ppf_Message_IsError() to check if an error occurred.
/// This response has no payload. If no error occurred, the request was successful.
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Highlight_SaveMedia(const char* jobId,const char* sessionId);

/// A message with type ::ppfMessageType_Highlight_ShareMedia will be generated in response.
/// First call ::ppf_Message_IsError() to check if an error occurred.
/// This response has no payload. If no error occurred, the request was successful.
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Highlight_ShareMedia(const char* jobId,const char* sessionId);

/// A message with type ::ppfMessageType_Highlight_StartRecord will be generated in response.
/// First call ::ppf_Message_IsError() to check if an error occurred.
/// This response has no payload. If no error occurred, the request was successful.
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Highlight_StartRecord();

/// 返回SessionId 若没有权限返回错误信息
/// A message with type ::ppfMessageType_Highlight_StartSession will be generated in response.
/// Call ::ppf_Message_IsError() to check if an error occurred.
/// If no error occurred, the message will contain a payload of type const char*.
/// Extract the payload from the message handle with ::ppf_Message_GetString()
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Highlight_StartSession();

// 主动调用停止录屏
/// A message with type ::ppfMessageType_Highlight_StopRecord will be generated in response.
/// First call ::ppf_Message_IsError() to check if an error occurred.
/// Extract the payload from the message handle with ::ppf_Message_GetRecordInfo().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Highlight_StopRecord();
#endif

