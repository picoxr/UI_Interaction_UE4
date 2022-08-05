#pragma once
//Auth: Alan Duan
//Date: 2021-11-11
//Desp: Log output function.

#include <stdint.h>
#include <sstream>
#include <memory>

#include "streamer_api.h"
namespace pxr
{
    enum LogLevel
    {
        kLogLevelInvalid = -1,
        kLogLevelDebug = 0,
        kLogLevelInfo = 1,
        kLogLevelWarn = 2,
        kLogLevelError = 3
    };
    //
    //brief: Log message wrapper. Should not be used directly.
    //
    class PXR_STREAMER_API LogMessage
    {
    public:
        static std::shared_ptr<LogMessage> Create(const std::string& file,
            long line,
            LogLevel type,
            const std::string& func = "");
        virtual std::stringstream& stream() = 0;
        virtual LogLevel level() const = 0;
        static std::string PointerToString(void* p);
    protected:
        virtual ~LogMessage() {};
    };

    class PXR_STREAMER_API LogWriter
    {
    public:
        //
        //brief: Set the log file path. 
        //       Must be called before writing the first log message.
        //argv : [in] name: The log file path.
        //
        static void SetLogFilePrefix(const std::string& name);
        //
        //brief: Set the log min output level. 
        //       e.g. If setting kLogLevelInfo, debug message cannot be output.
        //       Should be set before writing the first log message.
        //argv : [in] level: The log min output level. 
        //       The default value is kLogLevelInfo.
        //
        static void SetOuputLogLevel(LogLevel level);
        //
        //brief: Should not be called directly!!!
        //       Use the macro instead.
        //argv : [in] log_msg: The message need to be output.
        //
        static void Log(LogMessage& log_msg);
    };
}
//
//brief: Convert pointer to hexadecimal, just like 0xefdffa70.
//
#define PXR_LOG_PTR(ptr) pxr::LogMessage::PointerToString((void*)ptr)
//
//brief: Should not be used. Tool Macro to output this pointer.
//
#define PXR_THIS_PTR PXR_LOG_PTR(this)
//
//brief: Should not be used. Tool Macro.
//
#define PXR_LOG(msg, type) \
do{auto m = pxr::LogMessage::Create(__FILE__, __LINE__,\
pxr::LogLevel::##type, __FUNCTION__);\
m->stream() << msg;pxr::LogWriter::Log(*m);}while (false);
#define PXR_LOG_THIS(msg, type) PXR_LOG(msg << ", this = " << PXR_THIS_PTR, type);
//
//brief: Output log with different level.
//       E.x. PXR_DEBUG("my value= " << value << ", second value= " << value2);
//       Only support base type.
//
#define PXR_DEBUG(msg) PXR_LOG(msg, kLogLevelDebug)
#define PXR_INFO(msg) PXR_LOG(msg, kLogLevelInfo)
#define PXR_WARN(msg) PXR_LOG(msg, kLogLevelWarn)
#define PXR_ERROR(msg) PXR_LOG(msg, kLogLevelError)

//
//brief: Output log with this pointer. Should be used in class member function,
//       not static function.
//
#define PXR_DEBUG_THIS(msg) PXR_LOG_THIS(msg, kLogLevelDebug)
#define PXR_INFO_THIS(msg) PXR_LOG_THIS(msg, kLogLevelInfo)
#define PXR_WARN_THIS(msg) PXR_LOG_THIS(msg, kLogLevelWarn)
#define PXR_ERROR_THIS(msg) PXR_LOG_THIS(msg, kLogLevelError)

//
//brief: Check the condition and output error log.
//       E.x. PXR_CHECK(p == nullptr, "invalid pointer");
//
//NOTE(by Alan Duan): Lack of operator checking, use carefully.
#define PXR_CHECK(C,S) {if(C) {PXR_ERROR_THIS(#S << ", cond = " << #C);}}
//
//brief: Check the condition, output error log and return value.
//       E.x. PXR_CHECK_RET(p == nullptr, "invalid pointer", false);
//
#define PXR_CHECK_RET(C,S,V)\
{if(C){PXR_ERROR_THIS(#S << ", " << #C);return V;}}
//
//brief: Check the pxr::IInterface::IResult and output error log.
//       E.x. 
//       pxr::IInterface::IResult res = pxr::IInterface::IResult::kFailed;
//       PXR_CHECK_RES(res, "invalid result");
//
//NOTE(by Alan Duan): Lack of operator checking, use carefully.
#define PXR_CHECK_RES(R,S)\
{if (R != pxr::IInterface::IResult::kOK) {\
PXR_ERROR_THIS(#S", res = " << (int) R);}}
//
//brief: Check the pxr::IInterface::IResult and output error log.
//       E.x. 
//       pxr::IInterface::IResult res = pxr::IInterface::IResult::kFailed;
//       PXR_CHECK_RES_RET(res, "invalid result", false);
//
#define PXR_CHECK_RES_RET(R,S,V) \
{if (R != pxr::IInterface::IResult::kOK) {\
PXR_ERROR_THIS(#S", res = " << (int) R);return V;}}