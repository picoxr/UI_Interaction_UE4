#pragma once

#include <vector>

#include "../types.h"
#include "../iinterface.h"

namespace pxr
{
    namespace codec
    {

        struct EncoderParam
        {
            void* device = nullptr;

            //This is nullable, on D3D, you could get immediate context from device
            void* context = nullptr;
            //

            p_int32 width = 0;
            p_int32 height = 0;
            p_int32 bitrate = 0;
            p_int32 fps = 0;
            p_int32 gop = 0xFFFFFFFF;
            IDPInterface::IFrameFormat format = IDPInterface::IFrameFormat::kUnknown;
            IDPInterface::IFrameQuality quality = IDPInterface::IFrameQuality::kUnknown;
            IDPInterface::ICodecType codecs = IDPInterface::ICodecType::kUnknown;
            p_int32 leftORright = 0;//left=1, right=2;
        };

        struct FrameParam
        {
            p_uint32 width = 0;
            p_uint32 height = 0;
            IDPInterface::IFrameFormat format = IDPInterface::IFrameFormat::kUnknown;
            IDPInterface::IFrameType force_type = IDPInterface::IFrameType::kNone;
        };

        typedef void (*EncoderOutputCallback)(void* obj, p_uint8* encoded_data, p_int32 data_length);

        class EncoderInterface
            :public IDPInterface
        {
        public:


            /**
             * \brief 
             * \param param 
             * \param callback Callback is not used currently.
             * \return 
             */
            virtual IResult Startup(const EncoderParam& param, EncoderOutputCallback callback) = 0;

            virtual IResult Submit(p_resource_handle* texture, const FrameParam* param, void* frame_tag = nullptr) = 0;

            /**
             * \brief Get the latest encoder output, aka H264 or H265 stream data.
             *			The output is EXCLUDE the unnecessary AUD data.
             *			If no available output, it will return error on AMD GPU and block on NVidia GPU
             * \param out_data The stream output
             * \param out_frame_tag
             * \return
             */
            virtual IResult Acquire(std::vector<p_uint8>& out_data, void** out_frame_tag = nullptr) = 0;

            virtual IResult Flush() = 0;

            virtual IResult Shutdown() = 0;

            virtual IGraphicCardType GetGPUType() = 0;

            virtual bool IsValid() = 0;

        };
    }
}
