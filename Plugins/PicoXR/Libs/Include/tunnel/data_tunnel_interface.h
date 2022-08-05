#pragma once


#include "data_tunnel_packet.h"

#include "../iinterface.h"
#include "../types.h"

#include <functional>


namespace pxr
{
    namespace tunnel
    {

        struct DataTunnelAddress
        {
            p_uint8 ip[4] = { 0 };
            p_uint32 port = 0;
        };

        struct DataTunnelParam
        {
            IDPInterface::IDataTunnelType type;
            IDPInterface::IDataTunnelMode mode;
            DataTunnelAddress dst_addr;
            p_uint16 local_port;
            p_uint32 mtu; //Maximum Transmission Unit, If type = kRtp, then packet contains [ Rtp header + [payload] ] 

            p_uint32 rate; //Audio: Samples per packet; Video: Frames per second.


            //Callbacks are not used currently
            std::function<void(const DataTunnelAddress&/*connected_addr*/)> on_connected = nullptr;
            std::function<void(const DataTunnelAddress&/*disconnected_addr*/)> on_disconnected = nullptr;
            std::function<void(const DataTunnelAddress&/*src_addr*/, const DataTunnelPacket& /*received packet*/)> on_new_packet = nullptr;
            std::function<void(const DataTunnelAddress& /*timeout_addr*/)> on_timeout = nullptr;
            std::function<void(p_uint32 /*error_num*/)> on_error;
            //
        };

        class DataTunnelInterface
            :public IDPInterface
        {
        public:
            virtual IResult Startup(const DataTunnelParam& param) = 0;
            virtual IResult Shutdown() = 0;
            virtual IResult SendData(const DataTunnelPacket& packet) = 0;

            virtual IDataTunnelType GetType_() = 0;

        };
    }
}
