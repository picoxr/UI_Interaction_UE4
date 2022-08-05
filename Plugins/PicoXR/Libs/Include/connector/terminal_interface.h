#pragma once


#include <vector>

#include "../iinterface.h"
#include "../types.h"

#include "terminal_accessory.hpp"
#include "terminal_info.hpp"
#include "terminal_message.hpp"


namespace pxr
{
    namespace connector
    {
        class TerminalInterface
            :public IDPInterface
        {
        public:


            virtual IResult ConnectToHost(const p_string& host, const p_string& port) = 0;
            virtual void DisconnectFromHost() = 0;

            virtual IResult Hello(const TerminalInfo& my_info) = 0;
            virtual IResult Bye() = 0;
            virtual p_uint32 GetId() = 0;
            virtual IResult Active(p_bool active) = 0;

            virtual IResult QueryRemoteConfig(IBoolConfigType type, PXR_OUT_VALUE p_bool& out) = 0;
            virtual IResult QueryRemoteConfig(IIntConfigType type, PXR_OUT_VALUE p_int32& out) = 0;
            virtual IResult QueryRemoteConfig(IFloatConfigType type, PXR_OUT_VALUE p_float& out) = 0;
            virtual IResult QueryRemoteConfig(IStringConfigType type, PXR_OUT_VALUE p_string& out) = 0;

            virtual IResult QueryRemoteTerminal(p_uint32 terminal_id, PXR_OUT_VALUE TerminalInfo& out) = 0;
            virtual IResult QueryRemoteTerminals(PXR_OUT_VALUE std::vector<TerminalInfo>& out) = 0;
            virtual IResult QueryRemoteTerminalId(const TerminalInfo::Type& type, uint32_t& id) = 0;

            virtual IResult SubmitTerminalAccessory(const TerminalAccessory& in) = 0;
            virtual IResult QueryRemoteTerminalAccessory(p_uint32 terminal_id,
                PXR_OUT_VALUE TerminalAccessory& out) = 0;

            virtual IResult SubmitHmdAccessory(const HmdAccessory& in) = 0;
            virtual IResult QueryRemoteHmdAccessory(p_uint32 terminal_id,
                PXR_OUT_VALUE HmdAccessory& out) = 0;

            virtual IResult SubmitControllerAccessory(const ControllerAccessory& in) = 0;
            virtual IResult QueryRemoteControllerAccessory(p_uint32 terminal_id,
                ControllerAccessory::Type type, PXR_OUT_VALUE ControllerAccessory& out) = 0;

            virtual IResult PushMessage(const TerminalMessage& msg) = 0;
            virtual IResult PullMessage(PXR_OUT_VALUE std::vector<TerminalMessage>& out) = 0;

        };
    }
}
