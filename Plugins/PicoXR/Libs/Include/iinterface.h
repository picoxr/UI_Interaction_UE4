#pragma once


namespace pxr
{
    class IDPInterface
    {
    public:
        virtual ~IDPInterface() = default;

        enum class IResult
        {
            kOK,
            kFailed,
            kInvalidParam,
            kInternalNullPtrError,
            kInterfaceNotImplemented,

            //Renderer
            kInvalidRendererType = 100,
            kNoHardwareRenderDevice,
            kNativeRenderContextCreateFailed,
            kNativeRenderSourceOrTargetInvalid,
            //

            //Connector
            kAlreadyConnected = 200,
            kAlreadyHelloed,
            kNotHelloed,
            kRemoteError,
            //


            //Codec
            kSDKNotFound = 300,
            kSDKVersionNotSupported,
            kSDKInitFailed,
            //

            //Encoder
            kEncoderCreateFailed,
            kEncoderCreateInitializeParamFailed,
            kEncoderCreateBufferFailed,
            kEncoderBufferInvalid,
            kEncoderInvalid,
            kEncoderResourceInvalid,
            kEncoderEncodeFailed,
            kEncoderEncodeTimeout,
            kEncoderNoEncodedFrame,
            kEncoderAcquireAgain,
            kEncoderEncodedFrameInvalid,
            kEncoderDestroyFailed,
            //

            //Decoder
            //

            //Capture
            kCaptureNativeQueryFailed,
            kCaptureNativeInitFailed,
            kCaptureNativeStartFailed,
            kCaptureNativeStopFailed,
            kCaptureNativeInternalMemoryError,
            kCaptureNativeInternalMemoryCopyError,
            kCaptureNativeInternalAccessError,
            kCaptureAgainOnNextPeriod
            //
        };

        //
        //Connector
        //

        enum class IBoolConfigType
        {
            kBigPicture,
        };

        enum class IIntConfigType
        {
            kRenderResolutionWidth,
            kRenderResolutionHeight,

            kFrameRate,

            // Force using controller as a vendor type. 0: Pico; 1: Oculus; 2:HTC Vive
            kForceControllerType,
        };

        enum class IFloatConfigType
        {
            // The resolution scale on direct mode.
            kResolutionScale_DirectMode,
        };

        enum class IStringConfigType
        {
        };

        //


        //
        // Renderer
        //
        enum class IRenderType
        {
            kUnknown,
            kDirect3D11
        };

        enum class IRenderProc
        {
            kNone,
            kMarginDistortionCompress,
            kMarginDistortionRecover
        };
        //

        //
        // Codec
        //
        enum class IGraphicCardType
        {
            kUnknown,
            kNvidia,
            kAMD
        };

        enum class IFrameType
        {
            kNone,
            kP,
            kIDR,
            kI
        };

        enum class IFrameFormat
        {
            kUnknown,
            kRGBA,
            kNV12
        };

        enum class IFrameQuality
        {
            kUnknown,
            kPerformance,
            kStandard,
            kHigh
        };

        enum class ICodecType
        {
            kUnknown,
            kH264,
            kH265
        };
        //

        //
        //Data Tunnel
        //

        enum class IDataTunnelType
        {
            kUnknown,

            kRtpH264,
            kRtpH265,

            kRtpAudio,

            kRaw
        };

        enum class IDataTunnelMode
        {
            kRtpIn = 0x01,
            kRtpOut = 0x02,
            kRtpInAndOut = kRtpIn | kRtpOut,

            //TODO:Not implemented
            kRawIn = 0x04,
            kRawOut = 0x08,
            kRawInAndOut = kRawIn | kRawOut,

        };

        //

        //
        //Capture
        //

        enum class IAudioFormat
        {
            kUnknown,
            kPCM
        };

        //


    };

}
