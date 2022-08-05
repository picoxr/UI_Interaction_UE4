#pragma once

#include "../iinterface.h"

#include "../types.h"

namespace pxr
{
    namespace connector
    {
        class HostInterface
            :public IDPInterface
        {
        public:
            /**
             * \brief Start the host
             * \param host address and port to be listened on, and will use the 'port' and 'port + 1' for receiving data.
             * \return
             */
            virtual IResult Startup(const p_string& host, const p_string& port) = 0;

            /**
             * \brief
             */
            virtual void Shutdown() = 0;


            /**
             * \brief
             * \return
             */
            virtual bool IsRunning() = 0;
        };
    }
}

