#pragma once

#include "capture/capture_interface.h"
#include "codec/encoder_interface.h"
#include "connector/host_interface.h"
#include "connector/terminal_interface.h"
#include "renderer/renderer_interface.h"
#include "tunnel/data_tunnel_interface.h"

#include "types.h"

#if defined(WIN32) || defined(_WINDOWS) || defined(_WINDLL)

#   ifdef PXR_STREAMER_EXPORTS

#       define PXR_STREAMER_API __declspec(dllexport)

#   else

#       define PXR_STREAMER_API __declspec(dllimport)

#   endif

#else

#   if __GNUC__ >= 4

#       define PXR_STREAMER_API      __attribute__ ((visibility("default")))

#   else

#       define PXR_STREAMER_API

#   endif

#endif

#ifdef __cplusplus
#define PXR_EXTERN_C extern "C" 
#endif


namespace pxr
{
    namespace connector
    {
        PXR_EXTERN_C PXR_STREAMER_API HostInterface* RegisterAsHost();
        PXR_EXTERN_C PXR_STREAMER_API void UnregisterHost(HostInterface** host);

        PXR_EXTERN_C PXR_STREAMER_API TerminalInterface* RegisterAsTerminal();
        PXR_EXTERN_C PXR_STREAMER_API void UnregisterTerminal(TerminalInterface** terminal);
    }

    namespace capture
    {
        PXR_EXTERN_C PXR_STREAMER_API CaptureInterface* BuildCapture();
        PXR_EXTERN_C PXR_STREAMER_API void DestroyCapture(CaptureInterface** capture);
    }

    namespace renderer
    {
        PXR_EXTERN_C PXR_STREAMER_API RendererInterface* BuildRenderer();
        PXR_EXTERN_C PXR_STREAMER_API void DestroyRenderer(RendererInterface** renderer);
    }

    namespace codec
    {
        PXR_EXTERN_C PXR_STREAMER_API EncoderInterface* BuildEncoder();
        PXR_EXTERN_C PXR_STREAMER_API void DestroyEncoder(EncoderInterface** encoder);
    }

    namespace tunnel
    {
        PXR_EXTERN_C PXR_STREAMER_API DataTunnelInterface* BuildDataTunnel();
        PXR_EXTERN_C PXR_STREAMER_API void DestroyDataTunnel(DataTunnelInterface** tunnel);
    }

    namespace error
    {
        PXR_EXTERN_C PXR_STREAMER_API const char* GetLastErrorMessage();
    }

    namespace version
    {
        PXR_EXTERN_C PXR_STREAMER_API const char* GetStreamerVersion();
    }

}

