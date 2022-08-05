#pragma once


#include "../types.h"


#define PXR_TUNNEL_PACKET_MAX_EXTENSION_LENGTH 1024

namespace pxr
{
    namespace tunnel
    {
        class DataTunnelPacket
        {

            PXR_NO_COPY(DataTunnelPacket);

        public:

            void SetPayload(p_uint8* p) { payload_ = p; };
            p_uint8* GetPayload() const { return payload_; };

            void SetPayloadLength(p_size l) { payload_length_ = l; };
            p_size GetPayloadLength() const { return payload_length_; };



            /**
            * \brief Not necessary when use as send packet.
            *		But when receive a rtp packet, use GetPacket() to get the whole data,
            *		if get a raw packet, payload == packet
            */
            void SetPacket(p_uint8* p) { packet_ = p; };
            p_uint8* GetPacket() const { return packet_; };

            void SetPacketLength(p_size l) { packet_length_ = l; };
            p_size GetPacketLength() const { return packet_length_; };


            //
            //Enabled with type = kRtp
            //
            void SetPayloadType(p_uint8 t) { payload_type_ = t; };
            p_uint8 GetPayloadType() const { return payload_type_; };

            void SetExtensionID(p_uint16 id) { ext_id_ = id; };
            p_uint16 GetExtensionID() const { return ext_id_; };

            void SetExtension(p_uint8* e) { extension_ = e; };
            PXR_NULLABLE p_uint8* GetExtension() const { return extension_; };

            /**
             * \brief The extension length must less than MTU and max extension length.
             */
            void SetExtensionLength(p_size l) { extension_length_ = l; };
            p_size GetExtensionLength() const { return extension_length_; };


            static p_size GetMaxExtensionLength() { return PXR_TUNNEL_PACKET_MAX_EXTENSION_LENGTH; };

            //Sequence number is ignored when used as sending packet.
            //Internal default sequence number will be used.
            void SetSequenceNumber(p_uint32 n) { seq_num_ = n; };
            p_uint32 GetSequenceNumber() const { return seq_num_; };
            //

            //

            DataTunnelPacket()
                : packet_(p_nullptr)
                , packet_length_(0)
                , seq_num_(0)
                , payload_type_(0)
                , payload_(p_nullptr)
                , payload_length_(0)
                , ext_id_(0)
                , extension_(p_nullptr)
                , extension_length_(0)
            {
            }
            ~DataTunnelPacket() = default;

        private:
            p_uint8* packet_;
            p_size packet_length_;
            p_uint32 seq_num_;
            p_uint8 payload_type_;
            p_uint8* payload_;
            p_size payload_length_;
            p_uint16 ext_id_;
            p_uint8* extension_;
            p_size extension_length_;
        };
    }
}


