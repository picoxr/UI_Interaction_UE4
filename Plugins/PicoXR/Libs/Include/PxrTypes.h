#ifndef PXR_TYPES_H
#define PXR_TYPES_H

#include <stdbool.h>
#include <stdint.h>
#include "PxrEnums.h"
#include <jni.h>
#ifndef VK_VERSION_1_0
#define VK_DEFINE_HANDLE(object) typedef struct object##_T* object;
VK_DEFINE_HANDLE(VkInstance)
VK_DEFINE_HANDLE(VkPhysicalDevice)
VK_DEFINE_HANDLE(VkDevice)
#endif

static const int PXR_MAX_EVENT_COUNT = 20;

typedef uint64_t PxrTrackingModeFlags;
static const PxrTrackingModeFlags PXR_TRACKING_MODE_ROTATION_BIT = 0x00000001;
static const PxrTrackingModeFlags PXR_TRACKING_MODE_POSITION_BIT = 0x00000002;
static const PxrTrackingModeFlags PXR_TRACKING_MODE_EYE_BIT = 0x00000004;
static const PxrTrackingModeFlags PXR_TRACKING_MODE_FACE_BIT = 0x00000008;
static const PxrTrackingModeFlags PXR_TRACKING_MODE_PHOENIX_BIT = 0x00000010;
static const PxrTrackingModeFlags PXR_TRACKING_MODE_HAND_BIT = 0x00000020;
typedef struct PxrVulkanBinding_ {
    VkInstance instance;
    VkPhysicalDevice physicalDevice;
    VkDevice device;
    uint32_t queueFamilyIndex;
    uint32_t queueIndex;
    const void* next;
} PxrVulkanBinding;

typedef struct PxrLayerParam_ {
    int                layerId;
    PxrLayerShape      layerShape;
    PxrLayerType       layerType;
    PxrLayerLayout     layerLayout;
    uint64_t           format;
    uint32_t           width;
    uint32_t           height;
    uint32_t           sampleCount;
    uint32_t           faceCount;
    uint32_t           arraySize;
    uint32_t           mipmapCount;
    uint32_t           layerFlags;
    uint32_t           externalImageCount;
    uint64_t*          externalImages[2];
} PxrLayerParam;

typedef struct PxrQuaternionf_ {
    float    x;
    float    y;
    float    z;
    float    w;
} PxrQuaternionf;

typedef struct PxrVector3f_ {
    float    x;
    float    y;
    float    z;
} PxrVector3f;

typedef struct PxrRecti_ {
    int x;
    int y;
    int width;
    int height;
} PxrRecti;

typedef struct PxrPosef_ {
    PxrQuaternionf    orientation;
    PxrVector3f       position;
} PxrPosef;

typedef struct PxrSensorState_ {
    int status;
    PxrPosef pose;
    PxrVector3f angularVelocity;
    PxrVector3f linearVelocity;
    PxrVector3f angularAcceleration;
    PxrVector3f linearAcceleration;
    uint64_t poseTimeStampNs;
} PxrSensorState;

typedef struct PxrSensorState2_ {
    int         status;
    PxrPosef    pose;
    PxrPosef    globalPose;
    PxrVector3f angularVelocity;
    PxrVector3f linearVelocity;
    PxrVector3f angularAcceleration;
    PxrVector3f linearAcceleration;
    uint64_t    poseTimeStampNs;
} PxrSensorState2;

typedef struct PxrEyeTrackingData_ {
    int32_t    leftEyePoseStatus;          //!< Bit field (pvrEyePoseStatus) indicating left eye pose status
    int32_t    rightEyePoseStatus;         //!< Bit field (pvrEyePoseStatus) indicating right eye pose status
    int32_t    combinedEyePoseStatus;      //!< Bit field (pvrEyePoseStatus) indicating combined eye pose status

    float      leftEyeGazePoint[3];        //!< Left Eye Gaze Point
    float      rightEyeGazePoint[3];       //!< Right Eye Gaze Point
    float      combinedEyeGazePoint[3];    //!< Combined Eye Gaze Point (HMD center-eye point)

    float      leftEyeGazeVector[3];       //!< Left Eye Gaze Point
    float      rightEyeGazeVector[3];      //!< Right Eye Gaze Point
    float      combinedEyeGazeVector[3];   //!< Comnbined Eye Gaze Vector (HMD center-eye point)

    float      leftEyeOpenness;            //!< Left eye value between 0.0 and 1.0 where 1.0 means fully open and 0.0 closed.
    float      rightEyeOpenness;           //!< Right eye value between 0.0 and 1.0 where 1.0 means fully open and 0.0 closed.

    float      leftEyePupilDilation;       //!< Left eye value in millimeters indicating the pupil dilation
    float      rightEyePupilDilation;      //!< Right eye value in millimeters indicating the pupil dilation

    float      leftEyePositionGuide[3];    //!< Position of the inner corner of the left eye in meters from the HMD center-eye coordinate system's origin.
    float      rightEyePositionGuide[3];   //!< Position of the inner corner of the right eye in meters from the HMD center-eye coordinate system's origin.
    float      foveatedGazeDirection[3];   //!< Position of the gaze direction in meters from the HMD center-eye coordinate system's origin.
    int32_t    foveatedGazeTrackingState;  //!< The current state of the foveatedGazeDirection signal.
} PxrEyeTrackingData;
enum BlendShapeIndex {
    EyeLookDown_L = 0,
    NoseSneer_L = 1,
    EyeLookIn_L = 2,
    BrowInnerUp = 3,
    BrowDown_L = 25,
    MouthClose = 5,
    MouthLowerDown_R = 6,
    JawOpen = 7,
    MouthLowerDown_L = 9,
    MouthFunnel = 10,
    EyeLookIn_R = 11,
    EyeLookDown_R = 12,
    NoseSneer_R = 13,
    MouthRollUpper = 14,
    JawRight = 15,
    MouthDimple_L = 16,
    MouthRollLower = 17,
    MouthSmile_L = 18,
    MouthPress_L = 19,
    MouthSmile_R = 20,
    MouthPress_R = 21,
    MouthDimple_R = 22,
    MouthLeft = 23,
    EyeSquint_R = 41,
    EyeSquint_L = 4,
    MouthFrown_L = 26,
    EyeBlink_L = 27,
    CheekSquint_L = 28,
    BrowOuterUp_L = 29,
    EyeLookUp_L = 30,
    JawLeft = 31,
    MouthStretch_L = 32,
    MouthStretch_R = 33,
    MouthPucker = 34,
    EyeLookUp_R = 35,
    BrowOuterUp_R = 36,
    CheekSquint_R = 37,
    EyeBlink_R = 38,
    MouthUpperUp_L = 39,
    MouthFrown_R = 40,
    BrowDown_R = 24,
    JawForward = 42,
    MouthUpperUp_R = 43,
    CheekPuff = 44,
    EyeLookOut_L = 45,
    EyeLookOut_R = 46,
    EyeWide_R = 47,
    EyeWide_L = 49,
    MouthRight = 48,
    MouthShrugLower = 8,
    MouthShrugUpper = 50,
    TongueOut = 51,
};

#define BLEND_SHAPE_NUMS 52

typedef struct PXrFaceTrackingData{
    int64_t timestamp;                         // us​
    float blendShapeWeight[BLEND_SHAPE_NUMS];   //52（51+1）表情分量权重系​
    float reserved[16];
} PxrFaceTrackingData;
typedef struct PxrLayerHeader_ {
    int              layerId;
    uint32_t         layerFlags;
    float            colorScale[4];
    float            colorBias[4];
    int              compositionDepth;
    int              sensorFrameIndex;
    int              imageIndex;
    PxrPosef         headPose;
} PxrLayerHeader;

typedef struct PxrLayerProjection_ {
    PxrLayerHeader    header;
    float             depth;
} PxrLayerProjection;

typedef struct PxrLayerQuad_ {
    PxrLayerHeader    header;
    PxrPosef          pose;
    float             size[2];
} PxrLayerQuad;

typedef struct PxrLayerCylinder_ {
    PxrLayerHeader    header;
    PxrPosef          pose;
    float             radius;
    float             centralAngle;
    float             height;
} PxrLayerCylinder;

typedef struct PxrLayerEquirect_ {
    PxrLayerHeader    header;
    PxrPosef          pose;
    float             radius;
    float             centralHorizontalAngle;
    float             upperVerticalAngle;
    float             lowerVerticalAngle;
} PxrLayerEquirect;

typedef struct PxrEventDataBaseHeader_ {
    PxrStructureType             type;
    PxrEventLevel                eventLevel;
} PxrEventDataBaseHeader;

typedef struct PxrEventDataBuffer_ {
    PxrStructureType             type;
    PxrEventLevel                eventLevel;
    uint8_t                     varying[500];
} PxrEventDataBuffer;

typedef struct PxrEventDataEventsLost_ {
    PxrStructureType             type;
    PxrEventLevel                eventLevel;
    uint32_t                    lostEventCount;
} PxrEventDataEventsLost;

typedef struct PxrEventDataInstanceLossPending_ {
    PxrStructureType             type;
    PxrEventLevel                eventLevel;
    int64_t                      lossTime;
} PxrEventDataInstanceLossPending;

typedef struct PxrEventDataSessionReady_ {
    PxrStructureType             type;
    PxrEventLevel                eventLevel;
} PxrEventDataSessionReady;

typedef struct PxrEventDataSessionStopping_ {
    PxrStructureType             type;
    PxrEventLevel                eventLevel;
} PxrEventDataSessionStopping;


typedef struct PxrEventDataSessionStateChanged_ {
    PxrStructureType             type;
    PxrEventLevel                eventLevel;
    PxrSessionState              state;
    int64_t                      time;
} PxrEventDataSessionStateChanged;

typedef struct PXrEventDataMainSessionVisibilityChangedEXTX_ {
	PxrStructureType             type;
	PxrEventLevel                eventLevel;
	bool                         visible;
	char    				 	 packageName[128];
} PXrEventDataMainSessionVisibilityChangedEXTX;

typedef struct PxrEventDataInteractionProfileChanged_ {
    PxrStructureType             type;
    PxrEventLevel                eventLevel;
} PxrEventDataInteractionProfileChanged;

typedef struct PxrEventDataPerfSettings_ {
    PxrStructureType             type;
    PxrEventLevel                eventLevel;
    PxrPerfSettingsDomain               domain;
    PxrPerfSettingsSubDomain            subDomain;
    PxrPerfSettingsNotificationLevel    fromLevel;
    PxrPerfSettingsNotificationLevel    toLevel;
} PxrEventDataPerfSettings;

typedef struct PxrEventDataControllerChanged_ {
    PxrStructureType             type;
    PxrEventLevel                eventLevel;
    PxrDeviceEventType           eventtype;
    uint8_t                         controller;
    uint8_t                         status;
    uint8_t                     varying[400];
    uint16_t                         length;
} PxrEventDataControllerChanged;

typedef struct PxrEventDataSeethroughStateChanged_ {
    PxrStructureType             type;
    PxrEventLevel                eventLevel;
    int                          state;
} PxrEventDataSeethroughStateChanged;

typedef struct PxrEventDataHardIPDStateChanged_ {
    PxrStructureType             type;
    PxrEventLevel                eventLevel;
    float                       ipd;
}PxrEventDataHardIPDStateChanged;

typedef struct PxrEventDataFoveationLevelChanged_ {
    PxrStructureType             type;
    PxrEventLevel                eventLevel;
    int                        level;
} PxrEventDataFoveationLevelChanged;

typedef struct PxrEventDataFrustumChanged_ {
    PxrStructureType             type;
    PxrEventLevel                eventLevel;
} PxrEventDataFrustumChanged;

typedef struct PxrEventDataRenderTextureChanged_ {
    PxrStructureType             type;
    PxrEventLevel                eventLevel;
    int                         width;
    int                         height;
} PxrEventDataRenderTextureChanged;

typedef struct PxrXrEventDataTargetFrameRateChanged_ {
    PxrStructureType             type;
    PxrEventLevel                eventLevel;
    int                         frameRate;
} PxrEventDataTargetFrameRateChanged;

typedef struct PxrXrEventDataMrcStatusChanged_ {
    PxrStructureType             type;
    PxrEventLevel                eventLevel;
    int                         mrc_status;
} PxrEventDataMrcStatusChanged;

typedef struct PxrXrEventDataRefreshRateChanged_ {
    PxrStructureType             type;
    PxrEventLevel                eventLevel;
    float                        refrashRate;
} PxrEventDataRefreshRateChanged;


typedef struct PxrEventDataHmdKey_ {
    PxrStructureType             type;
    PxrEventLevel                eventLevel;
    int                         code;
    int                         action;
    int                         repeat;
} PxrEventDataHmdKey;


typedef struct PxrEndFrameInfo_ {
    PxrPosef     headPose;
    float        depth;
} PxrEndFrameInfo;

typedef struct PxrInitParamData_ {
    void* activity;
    void* vm;
    int   controllerdof;
    int   headdof;
} PxrInitParamData;

typedef struct PxrFoveationParams_ {
    float foveationGainX;
    float foveationGainY;
    float foveationArea;
    float foveationMinimum;
}PxrFoveationParams;

typedef struct PxrBoundaryTriggerInfo_ {
	bool                  isTriggering;
    float                 closestDistance;
	PxrVector3f           closestPoint;
	PxrVector3f           closestPointNormal;
	bool                  valid;
}PxrBoundaryTriggerInfo;

typedef struct PxrSeeThoughData_ {
	uint64_t              leftEyeTextureId;
    uint64_t              rightEyeTextureId;
    uint32_t              width;
    uint32_t              height;
    uint32_t              exposure;
    int64_t               startTimeOfExposure;
    bool                  valid;
}PxrSeeThoughData;
typedef struct AudioClipData_{
    uint32_t delaytag;
    uint32_t slot;
    uint32_t buffersize;
    uint32_t sampleRate;
    uint32_t channelMask;
    uint32_t bitrate;
    uint32_t slotConfig;
    uint32_t datatype;
    uint32_t isCache;
    uint32_t clicpId;
} AudioClipData;

typedef enum XrTrackingMode
{
    XR_TRACKING_MODE_ROTATION = 0x1,
    XR_TRACKING_MODE_POSITION = 0x2,
    XR_TRACKING_MODE_EYE = 0x4,
    XR_TRACKING_MODE_FACE = 0x8
}XrTrackingMode;
#endif  // PXR_TYPES_H
