#pragma once

#include <vector>

#include "../types.h"
#include "../iinterface.h"

namespace pxr
{
    namespace capture
    {

        struct CaptureParam
        {
            IDPInterface::IAudioFormat format = IDPInterface::IAudioFormat::kUnknown;
            p_uint32 num_of_channels = 0;
            p_uint32 bits_per_sample = 0;
            p_uint32 samples_per_sec = 0;
        };

        class CaptureInterface
            :public IDPInterface
        {
        public:

            virtual IResult Startup(const CaptureParam& param) = 0;

            virtual IResult Capture(std::vector<p_uint8>& out_data) = 0;

            virtual IResult Flush() = 0;

            /**
             * \brief Get the period between audio packets.
             *        Could use this as the sleep interval when Capture() returns kCaptureAgainOnNextPeriod.
             *
             * \return Period time in ms.
             */
            virtual p_uint32 GetPeriod() = 0;

            virtual IResult Shutdown() = 0;

            virtual bool IsValid() = 0;

        };
    }
}
