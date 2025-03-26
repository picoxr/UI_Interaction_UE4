// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved. 

#ifndef PXR_TYPES_H
#define PXR_TYPES_H

#include <stdbool.h>
#include <stdint.h>
#ifndef VK_VERSION_1_0
#define VK_DEFINE_HANDLE(object) typedef struct object##_T* object;
VK_DEFINE_HANDLE(VkInstance)
VK_DEFINE_HANDLE(VkPhysicalDevice)
VK_DEFINE_HANDLE(VkDevice)
#endif

#define PXR_UUID_SIZE 2
#define PXRP_SUCCESS(result) ((result) >= 0)
#define PXRP_FAILURE(result) ((result) < 0)

typedef enum
{
    PXR_RET_SUCCESS = 0,
    PXR_RET_FAIL = -1,
    PXR_RET_INVALID_LAYER_ID = -2,
    PXR_RET_INVALID_IMAGE_INDEX = -3,
    PXR_RET_INPUT_POINTER_IS_NULL = -4,
    PXR_RET_INIT_SESSION_IS_NULL = -5,
    PXR_RET_INVALID_INPUT_PARAM = -6,
    PXR_RET_NOT_BEGIN_XR = -7,
    PXR_RET_NOT_IMPLEMENTED = -8,
}PxrReturnStatus;

typedef enum
{
    PXR_LAYER_PROJECTION = 0,
    PXR_LAYER_QUAD = 1,
    PXR_LAYER_CYLINDER = 2,
    PXR_LAYER_EQUIRECT = 3,
    PXR_LAYER_EQUIRECT2 = 4,
    PXR_LAYER_CUBE = 5,
    PXR_LAYER_EAC = 6
} PxrLayerShape;

typedef enum
{
    PXR_LAYER_LAYOUT_STEREO = 0,
    PXR_LAYER_LAYOUT_DOUBLE_WIDE = 1,
    PXR_LAYER_LAYOUT_ARRAY = 2,
    PXR_LAYER_LAYOUT_MONO = 3
}PxrLayerLayout;

typedef enum
{
    PXR_LAYER_FLAG_ANDROID_SURFACE = 1 << 0,
    PXR_LAYER_FLAG_PROTECTED_CONTENT = 1 << 1,
    PXR_LAYER_FLAG_STATIC_IMAGE = 1 << 2,
    PXR_LAYER_FLAG_USE_EXTERNAL_IMAGES = 1 << 4,
    PXR_LAYER_FLAG_3D_LEFT_RIGHT_SURFACE = 1 << 5,
    PXR_LAYER_FLAG_3D_TOP_BOTTOM_SURFACE = 1 << 6,
    PXR_LAYER_FLAG_ENABLE_FRAME_EXTRAPOLATION = 1 << 7,
	PXR_LAYER_FLAG_ENABLE_SUBSAMPLED = 1 << 8,
} PxrLayerCreateFlags;

typedef enum
{
    PXR_LAYER_FLAG_NO_COMPOSITION_DEPTH_TESTING = 1 << 3,
    PXR_LAYER_FLAG_USE_EXTERNAL_HEAD_POSE = 1 << 5,
    PXR_LAYER_FLAG_LAYER_POSE_NOT_IN_TRACKING_SPACE = 1 << 6,
    PXR_LAYER_FLAG_HEAD_LOCKED = 1 << 7,
    PXR_LAYER_FLAG_USE_EXTERNAL_IMAGE_INDEX = 1 << 8,
    PXR_LAYER_FLAG_PRESENTATION_PROTECTION = 1 << 9,
    PXR_LAYER_FLAG_SOURCE_ALPHA_1_0 = 1 << 10,
    PXR_LAYER_FLAG_USE_FRAME_EXTRAPOLATION = 1 << 11,
	PXR_LAYER_FLAG_QUICK_SEETHROUGH = 1 << 12,
	PXR_LAYER_FLAG_ENABLE_NORMAL_SUPER_SAMPLING = 1 << 13,
	PXR_LAYER_FLAG_ENABLE_QUALITY_SUPER_SAMPLING = 1 << 14,
	PXR_LAYER_FLAG_ENABLE_NORMAL_SHARPENING = 1 << 15,
	PXR_LAYER_FLAG_ENABLE_QUALITY_SHARPENING = 1 << 16,
	PXR_LAYER_FLAG_ENABLE_FIXED_FOVEATED_SUPER_SAMPLING = 1<<17,
	PXR_LAYER_FLAG_ENABLE_FIXED_FOVEATED_SHARPENING = 1 << 18,
	PXR_LAYER_FLAG_ENABLE_SELF_ADAPTIVE_SHARPENING = 1 << 19,
	PXR_LAYER_FLAG_PREMULTIPLIED_ALPHA       = 1 << 20,
	PXR_LAYER_FLAG_ENABLE_SUPER_RESOLUTION = 1 << 21
} PxrLayerSubmitFlags;

typedef enum
{
    PXR_FEATURE_MULTIVIEW = 0,
    PXR_FEATURE_FOVEATION = 1,
    PXR_FEATURE_EYETRACKING = 2
} PxrFeatureType;

typedef enum
{
    PXR_UNITY = 0,
    PXR_UNREAL = 1,
    PXR_NATIVE = 2
} PxrPlatformOption;

typedef enum
{
    PXR_OPENGL_ES = 0,
    PXR_VULKAN
} PxrGraphicOption;

typedef enum
{
    PXR_EYE_LEFT = 0,
    PXR_EYE_RIGHT = 1,
    PXR_EYE_BOTH = 2,
    PXR_EYE_MAX = 2
} PxrEyeType;

typedef enum
{
    PXR_LOG_VERBOSE = 2,
    PXR_LOG_DEBUG,
    PXR_LOG_INFO,
    PXR_LOG_WARN,
    PXR_LOG_ERROR,
    PXR_LOG_FATAL,
} PxrLogPriority;

typedef enum
{
    PXR_FOVEATION_LEVEL_NONE = -1,
    PXR_FOVEATION_LEVEL_LOW = 0,
    PXR_FOVEATION_LEVEL_MID = 1,
    PXR_FOVEATION_LEVEL_HIGH = 2,
    PXR_FOVEATION_LEVEL_TOP_HIGH = 3
} PxrFoveationLevel;

typedef enum
{
    PXR_COLOR_SPACE_LINEAR = 0,
    PXR_COLOR_SPACE_SRGB = 1
} PxrColorSpace;


typedef enum
{
    PXR_RENDER_TEXTURE_WIDTH = 0,
    PXR_RENDER_TEXTURE_HEIGHT,
    PXR_SHOW_FPS,
    PXR_RUNTIME_LOG_LEVEL,
    PXR_PXRPLUGIN_LOG_LEVEL,
    PXR_UNITY_LOG_LEVEL,
    PXR_UNREAL_LOG_LEVEL,
    PXR_NATIVE_LOG_LEVEL,
    PXR_TARGET_FRAME_RATE,
    PXR_NECK_MODEL_X,
    PXR_NECK_MODEL_Y,
    PXR_NECK_MODEL_Z,
    PXR_DISPLAY_REFRESH_RATE,
    PXR_ENABLE_6DOF,
    PXR_CONTROLLER_TYPE,
    PXR_PHYSICAL_IPD,
    PXR_TO_DELTA_SENSOR_Y,
    PXR_GET_DISPLAY_RATE,
    PXR_FOVEATION_SUBSAMPLED_ENABLED,
    PXR_TRACKING_ORIGIN_HEIGHT,
    PXR_ENGINE_VERSION,
    PXR_UNREAL_OPENGL_NOERROR,
    PXR_ENABLE_CPT,
    PXR_MRC_TEXTURE_ID,
    PXR_RENDER_FPS,
    PXR_MSAA_LEVEL_RECOMMENDED,
    PXR_MRC_TEXTURE_ID_2,
    PXR_SET_SURFACE_VIEW,
    PXR_API_VERSION,
    PXR_MRC_POSITION_Y_OFFSET,
    PXR_MRC_TEXTURE_WIDTH,
    PXR_MRC_TEXTURE_HEIGHT,
    PXR_SINGLEPASS,
    PXR_FOVLEVEL,
    PXR_ANDROID_SURFACE_DIMENSIONS,
    PXR_ANDROID_SN,
    PXR_SET_DESIRED_FPS,
    PXR_GET_SEETHROUGH_STATE,
    PXR_SET_LAYER_BLEND,
    PXR_LEFT_EYE_FOV,
    PXR_RIGHT_EYE_FOV,
    PXR_BOTH_EYE_FOV,
} PxrConfigType;

typedef enum
{
    PXR_RESET_POSITION = 0,
    PXR_RESET_ORIENTATION = 1,
    PXR_RESET_ORIENTATION_Y_ONLY = 2,
    PXR_RESET_ALL
} PxrResetSensorOption;

typedef enum
{
    PXR_TYPE_UNKNOWN = 0,
    PXR_TYPE_EVENT_DATA_INSTANCE_LOSS_PENDING = 1,
    PXR_TYPE_EVENT_DATA_SESSION_STATE_CHANGED = 2,
    PXR_TYPE_EVENT_DATA_EVENTS_LOST = 3,
    PXR_TYPE_EVENT_DATA_INTERACTION_PROFILE_CHANGED = 4,
    PXR_TYPE_EVENT_DATA_PERF_SETTINGS_EXT = 5,
    PXR_TYPE_EVENT_DATA_CONTROLLER = 6,
    PXR_TYPE_EVENT_DATA_SESSION_STATE_READY = 7,
    PXR_TYPE_EVENT_DATA_SESSION_STATE_STOPPING = 8,
    PXR_TYPE_EVENT_DATA_SEETHROUGH_STATE_CHANGED = 9,
    PXR_TYPE_EVENT_HARDIPD_STATE_CHANGED = 10,
    PXR_TYPE_EVENT_FOVEATION_LEVEL_CHANGED = 11,
    PXR_TYPE_EVENT_FRUSTUM_STATE_CHANGED = 12,
    PXR_TYPE_EVENT_RENDER_TEXTURE_CHANGED = 13,
    PXR_TYPE_EVENT_TARGET_FRAME_RATE_STATE_CHANGED = 14,
    PXR_TYPE_EVENT_DATA_HMD_KEY = 15,
    PXR_TYPE_EVENT_DATA_MRC_STATUS = 16,
    PXR_TYPE_EVENT_DATA_REFRESH_RATE_CHANGED = 17,
    PXR_TYPE_EVENT_DATA_MAIN_SESSION_VISIBILITY_CHANGED_EXTX = 18,
	PXR_TYPE_EVENT_HMD_BATTERY_CHANGED = 34,

	//mr
	PXR_TYPE_EVENT_DATA_SPATIAL_TRACKING_STATE_UPDATE = 101,
	PXR_TYPE_EVENT_DATA_ANCHOR_ENTITY_PERSISTED = 118,
	PXR_TYPE_EVENT_DATA_ANCHOR_ENTITY_UNPERSISTED = 119,
	PXR_TYPE_EVENT_DATA_ANCHOR_ENTITY_CLEARED = 120,
	PXR_TYPE_ANCHOR_ENTITY_LOAD_UUID_FILTER = 122,
	PXR_TYPE_ANCHOR_ENTITY_LOAD_COMPONENT_FILTER = 123,
	PXR_TYPE_EVENT_DATA_ANCHOR_ENTITY_LOADED = 124,
	PXR_TYPE_EVENT_DATA_SPATIAL_SCENE_CAPTURED = 127,
	PXR_TYPE_ANCHOR_ENTITY_LOAD_SPATIAL_SCENE_FILTER = 128,
	PXR_TYPE_EVENT_DATA_ANCHOR_ENTITY_CREATED = 130,
} PxrStructureType;

typedef enum
{
    PXR_EVENT_LEVEL_LOW = 0,
    PXR_EVENT_LEVEL_MID,
    PXR_EVENT_LEVEL_HIGH
} PxrEventLevel;

typedef enum
{
    PXR_SESSION_STATE_UNKNOWN = 0,
    PXR_SESSION_STATE_IDLE = 1,
    PXR_SESSION_STATE_READY = 2,
    PXR_SESSION_STATE_SYNCHRONIZED = 3,
    PXR_SESSION_STATE_VISIBLE = 4,
    PXR_SESSION_STATE_FOCUSED = 5,
    PXR_SESSION_STATE_STOPPING = 6,
    PXR_SESSION_STATE_LOSS_PENDING = 7,
    PXR_SESSION_STATE_EXITING = 8,
    PXR_SESSION_STATE_MAX_ENUM = 0x7FFFFFFF
} PxrSessionState;

typedef enum
{
    PXR_PERF_SETTINGS_DOMAIN_CPU = 1,
    PXR_PERF_SETTINGS_DOMAIN_GPU = 2,
    PXR_PERF_SETTINGS_DOMAIN_MAX_ENUM = 0x7FFFFFFF
} PxrPerfSettingsDomain;

typedef enum
{
    PXR_PERF_SETTINGS_SUB_DOMAIN_COMPOSITING = 1,
    PXR_PERF_SETTINGS_SUB_DOMAIN_RENDERING = 2,
    PXR_PERF_SETTINGS_SUB_DOMAIN_THERMAL = 3,
    PXR_PERF_SETTINGS_SUB_DOMAIN_MAX_ENUM = 0x7FFFFFFF
} PxrPerfSettingsSubDomain;

typedef enum
{
    PXR_PERF_SETTINGS_NOTIF_LEVEL_LOW = 0,
    PXR_PERF_SETTINGS_NOTIF_LEVEL_MID = 25,
    PXR_PERF_SETTINGS_NOTIF_LEVEL_HIGH = 75,
    PXR_PERF_SETTINGS_NOTIFICATION_LEVEL_MAX_ENUM = 0x7FFFFFFF
} PxrPerfSettingsNotificationLevel;

typedef enum
{
    PXR_PERF_SETTINGS_CPU = 1,
    PXR_PERF_SETTINGS_GPU = 2,
    PXR_PERF_SETTINGS_MAX_ENUM = 0x7FFFFFFF
} PxrPerfSettings;

typedef enum
{
    PXR_PERF_SETTINGS_LEVEL_POWER_SAVINGS = 0,
    PXR_PERF_SETTINGS_LEVEL_SUSTAINED_LOW = 25,
    PXR_PERF_SETTINGS_LEVEL_SUSTAINED_HIGH = 50,
    PXR_PERF_SETTINGS_LEVEL_BOOST = 75,
    PXR_PERF_SETTINGS_LEVEL_MAX_ENUM = 0x7FFFFFFF
} PxrPerfSettingsLevel;
/*
 device post event type pico add new device interface
*/
typedef enum
{
    PXR_DEVICE_CONNECTCHANGED = 0,
    PXR_DEVICE_MAIN_CHANGED = 1,
    PXR_DEVICE_VERSION = 2,
    PXR_DEVICE_SN = 3,
    PXR_DEVICE_BIND_STATUS = 4,
    PXR_STATION_STATUS = 5,
    PXR_DEVICE_IOBUSY = 6,
    PXR_DEVICE_OTASTAUS = 7,
    PXR_DEVICE_ID = 8,
    PXR_DEVICE_OTASATAION_PROGRESS = 9,
    PXR_DEVICE_OTASATAION_CODE = 10,
    PXR_DEVICE_OTACONTROLLER_PROGRESS = 11,
    PXR_DEVICE_OTACONTROLLER_CODE = 12,
    PXR_DEVICE_OTA_SUCCESS = 13,
    PXR_DEVICE_BLEMAC = 14,
    PXR_DEVICE_HANDNESS_CHANGED = 15,
    PXR_DEVICE_CHANNEL = 16,
    PXR_DEVICE_LOSSRATE = 17,
    PXR_DEVICE_THREAD_STARTED = 18,
    PXR_DEVICE_MENUPRESSED_STATE = 19,
    PXR_DEVICE_HANDTRACKING_SETTING = 20,
    PXR_DEVICE_INPUTDEVICE_CHANGED = 21,
    PXR_DEVICE_SYSTEMGESTURE_STATE = 22,
	PXR_DEVICE_FITNESSBAND_STATE = 23,
	PXR_DEVICE_FITNESSBAND_BATTERY = 24,
	PXR_DEVICE_BODYTRACKING_STATE_ERROR_CODE =25
}PxrDeviceEventType;

typedef enum
{
    PXR_EYE_LEVEL = 0,
    PXR_FLOOR_LEVEL,
    PXR_STAGE_LEVEL
} PxrTrackingOrigin;

typedef enum
{
    PXR_CONTROLLER_LEFT = 0,
    PXR_CONTROLLER_RIGHT,
    PXR_CONTROLLER_COUNT
} PxrControllerHandness;

typedef enum
{
    PXR_HMD_3DOF = 0,
    PXR_HMD_6DOF
} PxrHmdDof;


typedef enum
{
    PXR_OVERLAY = 0,
    PXR_UNDERLAY
} PxrLayerType;

typedef enum
{
    PXR_SET_SEETHROUGH_VISIBLE = 0,
    PXR_SET_GUARDIANSYSTEM_DISABLE,
    PXR_RESUME_GUARDIANSYSTEM_FOR_STS,
    PXR_PAUSE_GUARDIANSYSTEM_FOR_STS,
    PXR_SHUTDOWN_SDK_GUARDIANSYSTEM,
    PXR_GET_CAMERA_DATA_EXT,
    PXR_START_SDK_BOUNDARY,
    PXR_SET_CONTROLLER_POSITION,
    PXR_START_CAMERA_PREVIEW,
    PXR_GET_ROOM_MODE_STATE,
    PXR_DISABLE_BOUNDARY,
    PXR_SET_MONO_MODE,
    PXR_GET_BOUNDARY_CONFIGURED,
    PXR_GET_BOUNDARY_ENABLED,
    PXR_SET_BOUNDARY_VISIBLE,
    PXR_SET_SEETHROUGH_BACKGROUND,
    PXR_GET_BOUNDARY_VISIBLE,
    PXR_GET_DIALOG_STATE,
    PXR_SET_SENSORLOST_CUSTOM_MODE,
    PXR_SET_SENSORLOST_CM_ST,
    PXR_GET_BOUNDARY_GEOMETRY_VEX_COUNT,

    PXR_RESET_TRACKING_HARD = 1000,
    PXR_GET_TRACKING_STATE = 1001,
    PXR_SET_ORIGIN_OF_LARGE_SPACE = 1002,
} PxrFuncitonName;

typedef enum
{
    PXR_BOUNDARY_TEST_NODE_LEFT_HAND = 0,
    PXR_BOUNDARY_TEST_NODE_RIGHT_HAND = 1,
    PXR_BOUNDARY_TEST_NODE_HEAD = 2
}PxrBoundaryTestNode;

typedef enum PxrBlendFactor_ {
    PXR_BLEND_FACTOR_ZERO = 0,
    PXR_BLEND_FACTOR_ONE = 1,
    PXR_BLEND_FACTOR_SRC_ALPHA = 2,
    PXR_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA = 3,
    PXR_BLEND_FACTOR_DST_ALPHA = 4,
    PXR_BLEND_FACTOR_ONE_MINUS_DST_ALPHA = 5,
    PXR_BLEND_FACTOR_MAX_ENUM = 0xFFFFFFFF
} PxrBlendFactor;

enum PxrGazeType {
	NEVER = 0,
	DURING_MOTION = 1,
	ALWAYS = 2,
};

enum PxrArmmodelType {
	CONTROLLER = 0,
	WRIST = 1,
	ELBOW = 2,
	SHOULDER = 3,
};

enum PxrRecenterTypes
{
	RecenterNone = 0,
	RecenterOrientation = 0x1,
	RecenterPosition = 0x2,
	RecenterOrientationAndPosition = 0x3
};

/////////////////////////////////
static const int PXR_MAX_EVENT_COUNT = 20;

typedef uint64_t PxrTrackingModeFlags;
static const PxrTrackingModeFlags PXR_TRACKING_MODE_ROTATION_BIT = 0x00000001;
static const PxrTrackingModeFlags PXR_TRACKING_MODE_POSITION_BIT = 0x00000002;
static const PxrTrackingModeFlags PXR_TRACKING_MODE_EYE_BIT = 0x00000004;
static const PxrTrackingModeFlags PXR_TRACKING_MODE_FACE_BIT = 0x00000008;
static const PxrTrackingModeFlags PXR_TRACKING_MODE_FACE_LIBSYNC = 0x2000;
static const PxrTrackingModeFlags PXR_TRACKING_MODE_VCMOTOR_BIT = 0x00000010;
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

typedef struct PxrVector2f_ {
    float    x;
    float    y;
} PxrVector2f;

typedef struct PxrVector3f_ {
    float    x;
    float    y;
    float    z;
} PxrVector3f;

typedef struct PxrVector4f_ {
    float    x;
    float    y;
    float    z;
    float    w;
}PxrVector4f;

typedef struct PxrExtent2Di_ {
    int width;
    int height;
} PxrExtent2Di;

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
    int32_t    leftEyePoseStatus;        
    int32_t    rightEyePoseStatus;       
    int32_t    combinedEyePoseStatus;    

    float      leftEyeGazePoint[3];      
    float      rightEyeGazePoint[3];     
    float      combinedEyeGazePoint[3];  

    float      leftEyeGazeVector[3];     
    float      rightEyeGazeVector[3];    
    float      combinedEyeGazeVector[3]; 

    float      leftEyeOpenness;          
    float      rightEyeOpenness;         

    float      leftEyePupilDilation;     
    float      rightEyePupilDilation;    

    float      leftEyePositionGuide[3];  
    float      rightEyePositionGuide[3]; 
    float      foveatedGazeDirection[3]; 
    int32_t    foveatedGazeTrackingState;
} PxrEyeTrackingData;
typedef struct PxrEyePupilInfo {
	float leftEyePupilDiameter;
	float rightEyePupilDiameter;
	float leftEyePupilPosition[2];
	float rightEyePupilPosition[2];
}PxrEyePupilInfo;
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

typedef struct PxrLayerBlend_ {
    PxrBlendFactor srcColor;
    PxrBlendFactor dstColor;
    PxrBlendFactor srcAlpha;
    PxrBlendFactor dstAlpha;
}PxrLayerBlend;

typedef struct PxrLayerHeader2_ {
    int              layerId;
    uint32_t         layerFlags;
    float            colorScale[4];
    float            colorBias[4];
    int              compositionDepth;
    int              sensorFrameIndex;
    int              imageIndex;
    PxrPosef         headPose;
    PxrLayerShape    layerShape;
    uint32_t         useLayerBlend;
    PxrLayerBlend    layerBlend;
    uint32_t         useImageRect;
    PxrRecti         imageRect[2];
    uint64_t         reserved[4];
} PxrLayerHeader2;

typedef struct PxrLayerProjection2_ {
    PxrLayerHeader2   header;
    float             depth;
    PxrVector4f       motionVectorScale;
    PxrVector4f       motionVectorOffset;
    PxrPosef          deltaPose;
    float             minDepth;
    float             maxDepth;
    float             nearZ;
    float             farZ;
} PxrLayerProjection2;

typedef struct PxrLayerQuad2_ {
    PxrLayerHeader2   header;
    PxrPosef          pose[2];
    PxrVector2f       size[2];
} PxrLayerQuad2;

typedef struct PxrLayerCylinder2_ {
    PxrLayerHeader2   header;
    PxrPosef          pose[2];
    float             radius[2];
    float             centralAngle[2];
    float             height[2];
} PxrLayerCylinder2;

typedef struct PxrLayerEquirect2_ {
    PxrLayerHeader2   header;
    PxrPosef          pose[2];
    float             radius[2];
    float             centralHorizontalAngle[2];
    float             upperVerticalAngle[2];
    float             lowerVerticalAngle[2];
} PxrLayerEquirect2;

typedef struct PxrLayerCube2_ {
    PxrLayerHeader2    header;
    PxrPosef           pose[2];
} PxrLayerCube2;

typedef struct PxrLayerEAC2_ {
    PxrLayerHeader2    header;
    PxrPosef           pose[2];
    PxrVector3f        offset[2];
    PxrQuaternionf     offsetRot[2];
    uint32_t           modelType;
    float              overlapFactor;
} PxrLayerEAC2;

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
    PxrLayerHeader2   header;
    PxrPosef          pose[2];
    float             radius[2];
    float             scaleX[2];
    float             scaleY[2];
    float             biasX[2];
    float             biasY[2];
} PxrLayerEquirect;

typedef enum PxrLayerImageTypes_ {
    PXR_IMAGE_TYPE_DEFAULT,
    PXR_LAYER_IMAGE_TYPE_MOTION_VECTOR,
    PXR_LAYER_IMAGE_TYPE_DEPTH,
} PxrLayerImageTypes;

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

typedef struct PxrEventHmdBatteryChanged_ {
	PxrStructureType             type;
	PxrEventLevel                eventLevel;
	int                         value;
} PxrEventHmdBatteryChanged;

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

typedef struct
{
    uint32_t slot;
    uint32_t reversal;
    float amp;
}PxrVibrate_info;

typedef struct
{
	uint64_t frameseq;
	uint16_t play;
	uint16_t frequency;
	uint16_t loop;
	float gain;
} PxrPhf_params_t;

#define PHF_LENGTH 50
typedef struct
{
	PxrPhf_params_t params[PHF_LENGTH];
} PxrPhf_params;

typedef struct
{
    int slot;
    uint64_t buffersize;
    int sampleRate;
    int channelCounts;
    int bitrate;
    int reversal;
    int isCache;
} PxrVibrate_config;
typedef enum XrTrackingMode
{
    XR_TRACKING_MODE_ROTATION = 0x1,
    XR_TRACKING_MODE_POSITION = 0x2,
    XR_TRACKING_MODE_EYE = 0x4,
    XR_TRACKING_MODE_FACE = 0x8
}XrTrackingMode;
#define BLEND_SHAPE_NUMS 72
typedef struct {
    int64_t timestamp;
    float blendShapeWeight[BLEND_SHAPE_NUMS];
    float videoInputValid[10];
    float laughingProb;
    float emotionProb[10];
    float reserved[128];
} PxrFTInfo;
enum GetDataType {
    PXR_GET_FACE_DATA_DEFAULT = 0,
    PXR_GET_FACE_DATA = 3,   
    PXR_GET_LIP_DATA = 4,    
    PXR_GET_FACELIP_DATA = 5,
};
////////////////////////////////////////////////

typedef enum
{
	PXR_CONTROLLER_3DOF = 0,
	PXR_CONTROLLER_6DOF
} PxrControllerDof;

typedef enum
{
	PXR_CONTROLLER_BOND = 0,
	PXR_CONTROLLER_UNBOND
} PxrControllerBond;

typedef enum
{
	PXR_CONTROLLER_KEY_HOME = 0,
	PXR_CONTROLLER_KEY_AX = 1,
	PXR_CONTROLLER_KEY_BY = 2,
	PXR_CONTROLLER_KEY_BACK = 3,
	PXR_CONTROLLER_KEY_TRIGGER = 4,
	PXR_CONTROLLER_KEY_VOL_UP = 5,
	PXR_CONTROLLER_KEY_VOL_DOWN = 6,
	PXR_CONTROLLER_KEY_ROCKER = 7,
	PXR_CONTROLLER_KEY_GRIP = 8,
	PXR_CONTROLLER_KEY_TOUCHPAD = 9,
	PXR_CONTROLLER_KEY_LASTONE = 127,

	PXR_CONTROLLER_TOUCH_AX = 128,
	PXR_CONTROLLER_TOUCH_BY = 129,
	PXR_CONTROLLER_TOUCH_ROCKER = 130,
	PXR_CONTROLLER_TOUCH_TRIGGER = 131,
	PXR_CONTROLLER_TOUCH_THUMB = 132,
	PXR_CONTROLLER_TOUCH_LASTONE = 255
} PxrControllerKeyMap;

typedef enum
{
	PXR_CONTROLLER_HAVE_TOUCH = 0x00000001,
	PXR_CONTROLLER_HAVE_GRIP = 0x00000002,
	PXR_CONTROLLER_HAVE_ROCKER = 0x00000004,
	PXR_CONTROLLER_HAVE_TOUCHPAD = 0x00000008,
	PXR_CONTROLLER_HAVE_ALL = 0xFFFFFFFF

} PxrControllerAbilities;


typedef enum {
	PXR_NO_DEVICE = 0,
	PXR_HB_Controller = 1,
	PXR_CV_Controller = 2,
	PXR_HB2_Controller = 3,
	PXR_CV2_Controller = 4,
	PXR_CV3_Optics_Controller = 5,
	PXR_CV3_Phoenix_Controller = 6,
    PXR_G3_Controller = 7,
} PxrControllerType;


typedef enum {
	PXR_NEO3_DEVICE = 1,
	PXR_PHOENIX_DEVICE = 2,
} PxrHMDType;

typedef struct PxrControllerTracking_ {
	PxrSensorState localControllerPose;
	PxrSensorState globalControllerPose;
} PxrControllerTracking;


typedef struct PxrControllerInputState_ {
	PxrVector2f Joystick;   
	int homeValue;          
	int backValue;          
	int touchpadValue;      
	int volumeUp;           
	int volumeDown;         
	float triggerValue;     
	int batteryValue;       
	int AXValue;            
	int BYValue;            
	int sideValue;          
	float gripValue;        
	int triggerclickValue;  
	int reserved_key_1;
	int reserved_key_2;
	int reserved_key_3;
	int reserved_key_4;

	int AXTouchValue;       
	int BYTouchValue;       
	int rockerTouchValue;   
	int triggerTouchValue;  
	int thumbrestTouchValue;
	int reserved_touch_0;
	int reserved_touch_1;
	int reserved_touch_2;
	int reserved_touch_3;
	int reserved_touch_4;

} PxrControllerInputState;

typedef struct PxrControllerInputStateDowntimeStamp_ {

	long home;          
	long back;          
	long touchpad;      
	long volumeUp;      
	long volumeDown;    
	long AX;            
	long BY;            
	long side;          
	long grip;          
	long reserved_key_0;
	long reserved_key_1;
	long reserved_key_2;
	long reserved_key_3;
	long reserved_key_4;

	long AXTouch;       
	long BYTouch;       
	long rockerTouch;   
	long triggerTouch;  
	long thumbrestTouch;
	long reserved_touch_0;
	long reserved_touch_1;
	long reserved_touch_2;
	long reserved_touch_3;
	long reserved_touch_4;

} PxrControllerInputStateDowntimeStamp;


typedef struct PxrInputEvent_ {
	union
	{
		int int_value;
		float  float_value;
	};
	bool up;
	bool down;
	bool shortpress;
	bool longpress;
} PxrInputEvent;

typedef struct PxrControllerInputEvent_ {
	PxrInputEvent home;          
	PxrInputEvent back;          
	PxrInputEvent touchpad;      
	PxrInputEvent volumeUp;      
	PxrInputEvent volumeDown;    
	PxrInputEvent AX;            
	PxrInputEvent BY;            
	PxrInputEvent side;          
	PxrInputEvent reserved_0_Key;
	PxrInputEvent reserved_1_Key;
	PxrInputEvent reserved_2_Key;
	PxrInputEvent reserved_3_Key;
	PxrInputEvent reserved_4_Key;

	PxrInputEvent AXTouch;       
	PxrInputEvent BYTouch;       
	PxrInputEvent rockerTouch;   
	PxrInputEvent triggerTouch;  
	PxrInputEvent thumbrestTouch;
	PxrInputEvent reserved_0_Touch;
	PxrInputEvent reserved_1_Touch;
	PxrInputEvent reserved_2_Touch;
	PxrInputEvent reserved_3_Touch;
	PxrInputEvent reserved_4_Touch;

} PxrControllerInputEvent;


typedef struct PxrControllerCapability_ {
	PxrControllerType             type;
	PxrControllerDof              Dof;
	PxrControllerBond             inputBond;
	uint64_t                 Abilities;
} PxrControllerCapability;

typedef struct PxrControllerInfo_ {
	PxrControllerType             type;
	char* mac;
	char* sn;
	char* version;
} PxrControllerInfo;

//Handtracking data
typedef enum {
	pxrHeadActive = 0,
	pxrControllerActive = 1,
	pxrHandTrackingActive = 2,
}PxrActiveInputDeviceType;
typedef enum {
	PxrNone = -1,
	PxrHandLeft = 0,
	PxrHandRight = 1,
}PxrHandType;
typedef enum {
	PxrSkeletonTypeNone = -1,
	PxrSkeletonTypeHandLeft = 0,
	PxrSkeletonTypeHandRight = 1,
} PxrSkeletonType;
typedef enum {
	PxrMeshTypeNone = -1,
	PxrMeshTypeHandLeft = 0,
	PxrMeshTypeHandRight = 1,
} PxrMeshType;
typedef enum PxrHandTrackingStatus_ {
	PxrHandTracked = (1 << 0),
	PxrInputStateValid = (1 << 1),
	PxrSystemGestureInProgress = (1 << 6),
	PxrDominantHand = (1 << 7),
	PxrMenuPressed = (1 << 8)
}PxrHandTrackingStatus;
typedef struct PxrVector4s_ {
	int16_t x, y, z, w;
}PxrVector4s;
typedef enum PxrHandBoneIndex_ {
	PxrHandBone_Invalid = -1,
	PxrHandBone_WristRoot = 0,
	PxrHandBone_ForearmStub = 1,
	PxrHandBone_Thumb0 = 2,
	PxrHandBone_Thumb1 = 3,
	PxrHandBone_Thumb2 = 4,
	PxrHandBone_Thumb3 = 5,
	PxrHandBone_Index1 = 6,
	PxrHandBone_Index2 = 7,
	PxrHandBone_Index3 = 8,
	PxrHandBone_Middle1 = 9,
	PxrHandBone_Middle2 = 10,
	PxrHandBone_Middle3 = 11,
	PxrHandBone_Ring1 = 12,
	PxrHandBone_Ring2 = 13,
	PxrHandBone_Ring3 = 14,
	PxrHandBone_Pinky0 = 15,
	PxrHandBone_Pinky1 = 16,
	PxrHandBone_Pinky2 = 17,
	PxrHandBone_Pinky3 = 18,
	PxrHandBone_MaxSkinnable = 19,

	PxrHandBone_ThumbTip = PxrHandBone_MaxSkinnable + 0,
	PxrHandBone_IndexTip = PxrHandBone_MaxSkinnable + 1,
	PxrHandBone_MiddleTip = PxrHandBone_MaxSkinnable + 2,
	PxrHandBone_RingTip = PxrHandBone_MaxSkinnable + 3,
	PxrHandBone_PinkyTip = PxrHandBone_MaxSkinnable + 4,
	PxrHandBone_Max = PxrHandBone_MaxSkinnable + 5,
} PxrHandBoneIndex;
#define PxrHandBoneIndex_max 24

typedef enum {
	PxrHandPinch_Thumb = 1 << 0,
	PxrHandPinch_Index = 1 << 1,
	PxrHandPinch_Middle = 1 << 2,
	PxrHandPinch_Ring = 1 << 3,
	PxrHandPinch_Pinky = 1 << 4,
} PxrHandFingerPinch;
#define PxrHandFingerPinch_max 5

typedef enum {
	PxrTrackingConfidence_LOW,
	PxrTrackingConfidence_HIGH,
} PxrTrackingConfidence;
#define PxrHandFinger_Max 5

//new handtracking
#define PxrHandJointCount 26
typedef struct
{
	uint64_t    	locationFlags;
	PxrPosef        pose;
	float           radius;
} PxrHandJointsLocation;
typedef struct
{
	uint32_t                   isActive;
	uint32_t                   jointCount;
	float    		  	       HandScale;
	PxrHandJointsLocation      jointLocations[PxrHandJointCount];
}PxrHandJointsLocations;

typedef struct handaimstate_ {
	uint64_t  			Status;
	PxrPosef      	    aimPose;
	float             	pinchStrengthIndex;
	float            	pinchStrengthMiddle;
	float             	pinchStrengthRing;
	float             	pinchStrengthLittle;
	float             	ClickStrength;
}PxrHandAimState;

typedef struct Pxrhandstate_ {
	int16_t  Status;
	PxrPosef   RootPose;
	PxrPosef   BonePose[PxrHandBoneIndex_max];
	int16_t Pinches;
	float    PinchStrength[PxrHandFingerPinch_max];
	float ClickStrength;
	PxrPosef   PointerPose;
	float    HandScale;
	PxrTrackingConfidence  HandConfidence;
	PxrTrackingConfidence  FingerConfidence[PxrHandFinger_Max];
	double   RequestedTimeStamp;
	double   SampleTimeStamp;
}PxrHandState;

typedef struct PxrBoneCapsule_ {
	PxrHandBoneIndex BoneIndex;
	PxrVector3f StartPoint;
	PxrVector3f EndPoint;
	float Radius;
} PxrBoneCapsule;

typedef struct Bone_ {
	PxrPosef  Bones;
	PxrHandBoneIndex BoneIndices;
	PxrHandBoneIndex ParentBoneIndices;
}PxrBone;
#define PxrBoneCapsule_max 19
typedef struct PxrSkeleton_ {
	PxrSkeletonType Type;
	int NumBones;
	int NumBoneCapsules;
	PxrBone     Bones[PxrHandBoneIndex_max];
	PxrBoneCapsule   Capsules[PxrBoneCapsule_max];
}PxrSkeleton;

typedef int16_t PxrVertexIndex;
#define PxrHand_MaxVertices 3000
#define PxrHand_MaxIndices  PxrHand_MaxVertices*6
typedef struct {
	int  NumVertices;
	int  NumIndices;
	PxrVector3f   VertexPositions[PxrHand_MaxVertices];
	PxrVertexIndex   Indices[PxrHand_MaxIndices];
	PxrVector3f    VertexNormals[PxrHand_MaxVertices];
	PxrVector2f    VertexUV0[PxrHand_MaxVertices];
	PxrVector4s    BlendIndices[PxrHand_MaxVertices];
	PxrVector4f    BlendWeights[PxrHand_MaxVertices];
}PxrHandMesh;

//Handtracking data

typedef enum PxrETResult {
	PXR_ET_RESULT_SUCCESS,
	PXR_ET_RESULT_SWITCH_NOT_ENABLE = -1,
	PXR_ET_RESULT_PERMISION_NOT_ENABLE = -2,
} PxrETResult;

/*************************************** Motion Tracking ***************************************/
typedef enum {
	PXR_MT_SUCCESS               =  0,
	PXR_MT_FAILURE               = -1,
	PXR_MT_MODE_NONE             = -2,
	PXR_MT_DEVICE_NOT_SUPPORT    = -3,
	PXR_MT_SERVICE_NEED_START    = -4,
	PXR_MT_ET_PERMISSION_DENIED  = -5,
	PXR_MT_FT_PERMISSION_DENIED  = -6,
	PXR_MT_MIC_PERMISSION_DENIED = -7,
	PXR_MT_SYSTEM_DENIED         = -8,
	PXR_MT_UNKNOW_ERROR          = -9
} PxrTrackingStateCode;

/*************************************** Face Tracking ***************************************/
#define PXR_FACE_TRACKING_API_VERSION 1
#ifdef PXR_FACE_TRACKING_API_VERSION 

typedef enum {
	PXR_FTM_NONE          =-1,
	PXR_FTM_FACE          = 0,
	PXR_FTM_LIPS          = 1,
	PXR_FTM_FACE_LIPS_VIS = 2,
	PXR_FTM_FACE_LIPS_BS  = 3,
	PXR_FTM_COUNT         = 4
} PxrFaceTrackingMode;

typedef int64_t PxrFaceTrackingDataGetFlags;
static const PxrFaceTrackingDataGetFlags PXR_FACE_DEFAULT = 0;

typedef struct PxrFaceTrackingStartInfo_ {
	int                         apiVersion;
	PxrFaceTrackingMode         mode;
} PxrFaceTrackingStartInfo;

typedef struct PxrFaceTrackingStopInfo_ {
	int                         apiVersion;
	bool                        pause;
} PxrFaceTrackingStopInfo;

typedef struct PxrFaceTrackignState_ {
	int                         apiVersion;
	PxrFaceTrackingMode         currentTrackingMode;
	PxrTrackingStateCode        code;
} PxrFaceTrackingState;

typedef struct PxrFaceTrackingDataGetInfo_ {
	int                         apiVersion;
	int64_t                     displayTime;
    PxrFaceTrackingDataGetFlags flags;
} PxrFaceTrackingDataGetInfo;

typedef struct PxrFaceTrackingData_ {
	int                         apiVersion;
	float*                      blendShapeWeight;
	int64_t                     timestamp;
	float                       laughingProb;
	bool                        eyeValid;
	bool                        faceValid;
} PxrFaceTrackingData;

#endif // PXR_FACE_TRACKING_API_VERSION

/*************************************** Eye Tracking ***************************************/
#define PXR_EYE_TRACKING_API_VERSION 1
#ifdef PXR_EYE_TRACKING_API_VERSION

typedef enum {
	PXR_ETM_NONE  =-1,
	PXR_ETM_BOTH  = 0,
	PXR_ETM_COUNT = 1
} PxrEyeTrackingMode;

typedef enum {
	leftEye =  0,
	rightEye = 1,
	combined = 2,
	eyeCount = 3
} PxrPerEyeUsage;

typedef int64_t PxrEyeTrackingDataGetFlags;
static const PxrEyeTrackingDataGetFlags PXR_EYE_DEFAULT     = 0;
static const PxrEyeTrackingDataGetFlags PXR_EYE_POSITION    = 1 << 0;
static const PxrEyeTrackingDataGetFlags PXR_EYE_ORIENTATION = 1 << 1;

typedef struct PxrEyeTrackingStartInfo_ {
	int                        apiVersion;
	bool                       needCalibration;
	PxrEyeTrackingMode         mode;
} PxrEyeTrackingStartInfo;

typedef struct PxrEyeTrackingStopInfo_ {
	int                        apiVersion;
} PxrEyeTrackingStopInfo;

typedef struct PxrEyeTrackingState_ {
	int                        apiVersion;
	PxrEyeTrackingMode         currentTrackingMode;
	PxrTrackingStateCode       code;
} PxrEyeTrackingState;

typedef struct PxrEyeTrackingDataGetInfo_ {
	int                        apiVersion;
	int64_t                    displayTime;
	PxrEyeTrackingDataGetFlags flags;
} PxrEyeTrackingDataGetInfo;

typedef struct PxrPerEyeData_ {
	int                        apiVersion;
	PxrPosef                   pose;
  //float                      confidence;
	bool                       isPoseValid;
	float                      openness;
	bool                       isOpennessValid;
} PxrPerEyeData;

typedef struct PxrEyeTrackingData1_ {
	int                        apiVersion;
	PxrPerEyeData              eyeDatas[eyeCount];
  //double                     timestamp;
} PxrEyeTrackingData1;

#endif // PXR_EYE_TRACKING_API_VERSION

/*************************************** Body Tracking ***************************************/
#define PXR_BODY_TRACKING_API_VERSION 1

#ifdef PXR_BODY_TRACKING_API_VERSION
//Bodytracking data
typedef enum BodyTrackerRole
{
    PxrPelvis         = 0,
    Pxr_LEFT_HIP       = 1,
    Pxr_RIGHT_HIP      = 2,
    Pxr_SPINE1         = 3,
    Pxr_LEFT_KNEE      = 4,
    Pxr_RIGHT_KNEE     = 5,
    Pxr_SPINE2         = 6,
    Pxr_LEFT_ANKLE     = 7,
    Pxr_RIGHT_ANKLE    = 8,
    Pxr_SPINE3         = 9,
    Pxr_LEFT_FOOT      = 10,
    Pxr_RIGHT_FOOT     = 11,
    Pxr_NECK           = 12,
    Pxr_LEFT_COLLAR    = 13,
    Pxr_RIGHT_COLLAR   = 14,
    Pxr_HEAD           = 15,
    Pxr_LEFT_SHOULDER  = 16,
    Pxr_RIGHT_SHOULDER = 17,
    Pxr_LEFT_ELBOW     = 18,
    Pxr_RIGHT_ELBOW    = 19,
    Pxr_LEFT_WRIST     = 20,
    Pxr_RIGHT_WRIST    = 21,
    Pxr_LEFT_HAND      = 22,
    Pxr_RIGHT_HAND     = 23,
    Pxr_NONE_ROLE      = 24,
    Pxr_MIN_ROLE       = 0,
    Pxr_MAX_ROLE       = 23,
    Pxr_ROLE_NUM       = 24,
} PxrBodyTrackerRole;

// imu data
typedef struct PxrBodyTrackingImu
{
    int64_t TimeStamp;                // time stamp of imu
    double    temperature;              // temperature of imu
    double    GyroData[3];              // gyroscope data, x,y,z
    double    AccData[3];               // Accelerometer data, x,y,z
    double    MagData[3];               // magnetometer data, x,y,z
} PxrBodyTrackingImu;

typedef struct PxrBodyTrackingPose
{
    int64_t TimeStamp;                // time stamp of imu
    double    PosX;                     // position of x
    double    PosY;                     // position of y
    double    PosZ;                     // position of z
    double    RotQx;                    // x components of Quaternion
    double    RotQy;                    // y components of Quaternion
    double    RotQz;                    // z components of Quaternion
    double    RotQw;                    // w components of Quaternion
} PxrBodyTrackingPose;

typedef enum {
    PXR_BTM_DISABLE             =0,
    PXR_BTM_WITH_SWIFT          =1,
    PXR_BTM_WITHOUT_SWIFT       =2,
    PXR_BTM_MAX_ENUM            = 0x7FFFFFFF
}PxrBodyTrackingMode;
typedef enum {
    Pxr_HUMAN_HEIGHT = 0,
    Pxr_SWIFT_MODE = 1,
    Pxr_BONE_PARAM = 2
} PxrBodyTrackingAlgParamType;
typedef struct PxrBodyTrackingBoneLength
{
    float HeadLen;
    float NeckLen;
    float TorsoLen;
    float HipLen;
    float UpperLegLen;
    float LowerLegLen;
    float FootLen;
    float ShoulderLen;
    float UpperArmLen;
    float LowerArmLen;
    float HandLen;
} PxrBodyTrackingBoneLength;
typedef struct PxrBodyTrackingAlgParam
{
    int32_t  BodyJointSet;
    PxrBodyTrackingBoneLength BoneLength;
}PxrBodyTrackingAlgParam;
typedef struct PxrBodyTrackingStartInfo_ {
    int                         apiVersion;
    PxrBodyTrackingMode         mode;
    int32_t  BodyJointSet;
    PxrBodyTrackingBoneLength BoneLength;
}PxrBodyTrackingStartInfo;

typedef struct PxrBodyTrackingStopInfo_ {
    int                         apiVersion;
}PxrBodyTrackingStopInfo;

typedef enum {
    Pxr_BODYTRACKING_INVALID = 0,
    Pxr_BODYTRACKING_VALID = 1,
    Pxr_BODYTRACKING_LIMITED = 2
} PxrBodyTrackingStatusCode;

typedef enum {
    Pxr_BT_ERROR_INNER_EXCEPTION = 0,
    Pxr_BT_ERROR_TRACKER_NOT_CALIBRATED = 1,
    Pxr_BT_ERROR_TRACKER_NUM_NOT_ENOUGH = 2,
    Pxr_BT_ERROR_TRACKER_STATE_NOT_SATISFIED = 3,
    Pxr_BT_ERROR_TRACKER_PERSISTENT_INVISIBILITY = 4,
    Pxr_BT_ERROR_TRACKER_DATA_ERROR = 5,
    Pxr_BT_ERROR_USER_CHANGE = 6,
    Pxr_BT_ERROR_TRACKING_POSE_ERROR = 7,
} PxrBodyTrackingErrorCode;


typedef struct PxrBodyTrackingState_ {
    int                         apiVersion;
    PxrBodyTrackingMode         currentTrackingMode;
    PxrTrackingStateCode        code;
    PxrBodyTrackingStatusCode   StateCode;
    PxrBodyTrackingErrorCode    ErrorCode;
    uint8_t                     connectedBandCount;//swift计数?
    uint8_t                     fitnessBand[12];//绑定id  12个数字
} PxrBodyTrackingState;

typedef enum {
    PXR_BODY_NONE               = 0,
    PXR_BODY_POSE               = 1 << 0,
    PXR_BODY_ACTION             = 1 << 1,
    PXR_BODY_VELO_ACC           = 1 << 2,
    PXR_BODY_MAX_ENUM           = 0x7FFFFFFF
} PxrBodyTrackingGetDataFlags;

typedef struct PxrBodyTrackingGetDataInfo_ {
    int                         apiVersion;
    int64_t                     displayTime;
    PxrBodyTrackingGetDataFlags flags; //use in future
} PxrBodyTrackingGetDataInfo;
// action set
typedef enum BodyActionList_
{
	PxrNoneAction  = 0x00000000,
	PxrTouchGround = 0x00000001,
	PxrKeepStatic  = 0x00000002,
	PxrTouchGroundToe =0x00000004
  } PxrBodyActionList;

typedef struct PxrBodyTrackingRoleData_ {
	int                         apiVersion;
	PxrBodyTrackerRole          role;
	PxrBodyActionList           bodyAction;
	PxrBodyTrackingPose         localPose;
	PxrBodyTrackingPose         globalPose;
	double                      velo[3];
	double                      acce[3];
	double                      wvelo[3];
	double                      wacce[3];
} PxrBodyTrackingRoleData;

typedef struct PxrBodyTrackingData_ {
	int                           apiVersion;
	PxrBodyTrackingRoleData       roleData[24];
} PxrBodyTrackingData;

typedef struct PxrBodyTrackingTransform
{
  PxrBodyTrackerRole bone;                // bone name. if bone == NONE_ROLE, this bone is not calculated
  PxrBodyTrackingPose localpose;
  PxrBodyTrackingPose globalpose;
  double velo[3];                     // velocity of x,y,z
  double acce[3];                     // acceleration of x,y,z
  double wvelo[3];                    // angular velocity of x,y,z
  double wacce[3];                    // angular acceleration of x,y,z
  uint32_t   bodyAction;              // multiple actions can be supported at the same time by means of OR BodyActionList
} PxrBodyTrackingTransform;


typedef struct PxrBodyTrackingResult
{
    PxrBodyTrackingTransform trackingdata[Pxr_ROLE_NUM];
} PxrBodyTrackingResult;

typedef struct PxrFitnessBandConnectState
{
	uint8_t num;
	uint8_t trackerID[12];
} PxrFitnessBandConnectState;

typedef struct
{
	int trackerSum;
	char trackersSN[6][24];
}PxrMotionConnectState;

typedef enum
{
	PxrUnknown = 0,
	PxrSwift_1 = 1,
	PxrSwift_2
}PxrMotionTrackerType;

typedef enum
{
	PxrBodyTracking = 0,
	PxrMotionTracking
} PxrMotionTrackerMode;

typedef struct
{
	PxrPosef      pose;
	float angularVelocity[3];
	float linearVelocity[3];
	float angularAcceleration[3];
	float linearAcceleration[3];
}PxrMotionTrackerPoseLocation;

typedef struct
{
	char trackerSN[24];
	PxrMotionTrackerPoseLocation      localPose;  
	PxrMotionTrackerPoseLocation        globalPose;

}PxrMotionTrackerLocations;

#endif

/*************************************** MR ***************************************/
typedef enum PxrResult {
    PXR_SUCCESS = 0,
    PXR_TIMEOUT_EXPIRED = 1,
    PXR_ERROR_VALIDATION_FAILURE = -1,
    PXR_ERROR_RUNTIME_FAILURE = -2,
    PXR_ERROR_OUT_OF_MEMORY = -3,
    PXR_ERROR_API_VERSION_UNSUPPORTED = -4,
    PXR_ERROR_INITIALIZATION_FAILED = -6,
    PXR_ERROR_FUNCTION_UNSUPPORTED = -7,
    PXR_ERROR_FEATURE_UNSUPPORTED = -8,
    PXR_ERROR_LIMIT_REACHED = -10,
    PXR_ERROR_SIZE_INSUFFICIENT = -11,
    PXR_ERROR_HANDLE_INVALID = -12,

    PXR_ERROR_SPATIAL_LOCALIZATION_RUNNING_BD = -1000,
    PXR_ERROR_SPATIAL_LOCALIZATION_NOT_RUNNING_BD = -1001,
    PXR_ERROR_SPATIAL_MAP_CREATED_BD = -1002,
    PXR_ERROR_SPATIAL_MAP_NOT_CREATED_BD = -1003,
    PXR_ERROR_COMPONENT_NOT_SUPPORTED_BD = -501,
    PXR_ERROR_COMPONENT_CONFLICT = -502,
    PXR_ERROR_COMPONENT_NOT_ADDED_BD = -503,
    PXR_ERROR_COMPONENT_ADDED_BD = -504,
    PXR_ERROR_ANCHOR_ENTITY_NOT_FOUND_BD = -505

} PxrResult;

typedef enum PxrSceneLabel {
	PXR_SCENE_LABEL_UNKNOWN_ = 0,
	PXR_SCENE_LABEL_FLOOR_ = 1,
	PXR_SCENE_LABEL_CEILING_ = 2,
	PXR_SCENE_LABEL_WALL_ = 3,
	PXR_SCENE_LABEL_DOOR_ = 4,
	PXR_SCENE_LABEL_WINDOW_ = 5,
	PXR_SCENE_LABEL_OPENING_ = 6,
	PXR_SCENE_LABEL_TABLE_ = 7,
	PXR_SCENE_LABEL_SOFA_ = 8,
	PXR_SCENE_LABEL_MAX_ENUM_ = 0x7FFFFFFF
} PxrSceneLabel;

typedef enum PxrPersistLocation {
	PXR_PERSIST_LOCATION_LOCAL = 1,
	PXR_PERSIST_LOCATION_REMOTE = 2,
	PXR_PERSIST_LOCATION_MAX_ENUM_ = 0x7FFFFFFF
} PxrPersistLocation;

typedef enum PxrSpatialTrackingState {
	PXR_SPATIAL_TRACKING_STATE_INVALID_ = 0,
	PXR_SPATIAL_TRACKING_STATE_VALID_ = 1,
	PXR_SPATIAL_TRACKING_STATE_LIMITED_ = 2,
} PxrSpatialTrackingState;

typedef enum PxrSpatialTrackingStateMessage {
	PXR_SPATIAL_TRACKING_STATE_MESSAGE_UNKNOWN = 0,
	PXR_SPATIAL_TRACKING_STATE_MESSAGE_INTERNAL_ERROR = 1,
} PxrSpatialTrackingStateMessage;

typedef enum PxrSpatialSceneCaptureStatus {
	PXR_SPATIAL_SCENE_CAPTURE_STATUS_NOT_DEFINED = 0,
	PXR_SPATIAL_SCENE_CAPTURE_STATUS_MAX_ENUM = 0x7FFFFFFF
} PxrSpatialSceneCaptureStatus;

typedef struct PxrAnchorEntityCreateInfo {
	PxrTrackingOrigin pxrTrackingOrigin;
	PxrPosef pose;
	double timeMs;
} PxrAnchorEntityCreateInfo;

typedef struct PxrAnchorEntityDestroyInfo {
	uint64_t anchor;
} PxrAnchorEntityDestroyInfo;

typedef struct PxrUUid
{
	uint64_t value[PXR_UUID_SIZE];
} PxrUuid;

typedef uint64_t PxrAnchorComponentTypeFlags;
static const PxrAnchorComponentTypeFlags PXR_ANCHOR_COMPONENT_TYPE_POSE_BIT_ = 0x00000001;
static const PxrAnchorComponentTypeFlags PXR_ANCHOR_COMPONENT_TYPE_PERSISTENCE_BIT_ = 0x00000002;
static const PxrAnchorComponentTypeFlags PXR_ANCHOR_COMPONENT_TYPE_SCENE_LABEL_BIT_ = 0x00000004;
static const PxrAnchorComponentTypeFlags PXR_ANCHOR_COMPONENT_TYPE_PLANE_BIT_ = 0x00000008;
static const PxrAnchorComponentTypeFlags PXR_ANCHOR_COMPONENT_TYPE_BOX_BIT_ = 0x00000010;

typedef struct PxrExtent2Df {
	float    width;
	float    height;
} PxrExtent2Df;

typedef struct PxrAnchorPlaneBoundaryInfo {
	PxrVector3f         center;
	PxrExtent2Df        extent;
} PxrAnchorPlaneBoundaryInfo;

typedef struct PxrAnchorPlanePolygonInfo {
	uint32_t           polygonSizeCapacityInput;
	uint32_t           polygonSizeCountOutput;
	PxrVector3f* polygonVertices;
} PxrAnchorPlanePolygonInfo;

typedef struct PxrAnchorBoxInfo {
	PxrVector3f         center;
	PxrVector3f         extent;
} PxrAnchorBoxInfo;

typedef struct PxrAnchorEntityList {
	uint32_t            count;
	uint64_t* anchors;
} PxrAnchorEntityList;

typedef struct PxrAnchorEntityPersistInfo {
	PxrAnchorEntityList    anchorList;
	PxrPersistLocation     location;
} PxrAnchorEntityPersistInfo;

typedef struct PxrAnchorEntityUnpersistInfo {
	PxrAnchorEntityList    anchorList;
	PxrPersistLocation     location;
} PxrAnchorEntityUnpersistInfo;

typedef struct PxrAnchorEntityClearInfo {
	PxrPersistLocation location;
} PxrAnchorEntityClearInfo;

typedef struct PxrAnchorEntityLoadFilterBaseHeader {
	PxrStructureType    type;
	uint8_t            varying[128];
} PxrAnchorEntityLoadFilterBaseHeader;

typedef struct PxrAnchorEntityLoadInfo {
	uint32_t                                    maxResult;
	int64_t                                  timeout;
	PxrPersistLocation                         location;
	const PxrAnchorEntityLoadFilterBaseHeader* include;
	const PxrAnchorEntityLoadFilterBaseHeader* exclude;
} PxrAnchorEntityLoadInfo;

typedef struct PxrAnchorEntityLoadUuidFilter {
	PxrStructureType    type;
	uint32_t           uuidCount;
	PxrUuid* uuidList;
} PxrAnchorEntityLoadUuidFilter;

typedef uint64_t PxrFlags64;
typedef PxrFlags64 PxrSpatialSceneDataTypeFlags;
// Flag bits for XrComponentTypeFlagsBD
static const PxrSpatialSceneDataTypeFlags PXR_SPATIAL_SCENE_DATA_TYPE_UNKNOWN_BIT_ = 0x00000001;
static const PxrSpatialSceneDataTypeFlags PXR_SPATIAL_SCENE_DATA_TYPE_FLOOR_BIT_ = 0x00000002;
static const PxrSpatialSceneDataTypeFlags PXR_SPATIAL_SCENE_DATA_TYPE_CEILING_BIT_ = 0x00000004;
static const PxrSpatialSceneDataTypeFlags PXR_SPATIAL_SCENE_DATA_TYPE_WALL_BIT_ = 0x00000008;
static const PxrSpatialSceneDataTypeFlags PXR_SPATIAL_SCENE_DATA_TYPE_DOOR_BIT_ = 0x00000010;
static const PxrSpatialSceneDataTypeFlags PXR_SPATIAL_SCENE_DATA_TYPE_WINDOW_BIT_ = 0x00000020;
static const PxrSpatialSceneDataTypeFlags PXR_SPATIAL_SCENE_DATA_TYPE_OPENING_BIT_ = 0x00000040;
static const PxrSpatialSceneDataTypeFlags PXR_SPATIAL_SCENE_DATA_TYPE_OBJECT_BIT_ = 0x00000080;

typedef struct PxrAnchorEntityLoadSpatialSceneFilter {
	PxrStructureType               type;
	PxrSpatialSceneDataTypeFlags typeFlags;
} PxrAnchorEntityLoadSpatialSceneFilter;

typedef struct PxrAnchorEntityLoadResult {
	uint64_t    anchor;
	PxrUuid           uuid;
} PxrAnchorEntityLoadResult;

typedef struct PxrAnchorEntityLoadResults {
	uint32_t                    resultCapacityInput;
	uint32_t                    resultCountOutput;
	PxrAnchorEntityLoadResult* results;
} PxrAnchorEntityLoadResults;

typedef struct PxrSpatialTrackingStateInfo {
	PxrSpatialTrackingState state;
	PxrSpatialTrackingStateMessage message;
} PxrSpatialTrackingStateInfo;

typedef struct PxrEventDataSpatialTrackingStateUpdate {
	PxrStructureType type;
	PxrEventLevel eventLevel;
	PxrSpatialTrackingStateInfo stateInfo;
} PxrEventDataSpatialTrackingStateUpdate;

typedef struct PxrEventDataAnchorEntityCreated {
	PxrStructureType     type;
	uint64_t       taskId;
	PxrResult            result;
	uint64_t            anchorHandle;
	PxrUuid  uuid;
} PxrEventDataAnchorEntityCreated;

typedef struct PxrEventDataAnchorEntityPersisted {
	PxrStructureType     type;
	uint64_t       taskId;
	PxrResult           result;
	PxrPersistLocation location;
} PxrEventDataAnchorEntityPersisted;

typedef struct PxrEventDataAnchorEntityUnpersisted {
	PxrStructureType     type;
	uint64_t       taskId;
	PxrResult            result;
	PxrPersistLocation location;
} PxrEventDataAnchorEntityUnpersisted;

typedef struct PxrEventDataAnchorEntityCleared {
	PxrStructureType     type;
	uint64_t       taskId;
	PxrResult            result;
	PxrPersistLocation location;
} PxrEventDataAnchorEntityCleared;

typedef struct PxrEventDataAnchorEntityLoaded {
	PxrStructureType     type;
	uint64_t     taskId;
	PxrResult            result;
	uint32_t            count;
	PxrPersistLocation location;
} PxrEventDataAnchorEntityLoaded;

typedef struct PxrEventDataSpatialSceneCaptured {
	PxrStructureType                type;
	uint64_t                        taskId;
	PxrResult                       result;
	PxrSpatialSceneCaptureStatus    status;
} PxrEventDataSpatialSceneCaptured;

/*************************************** MR ***************************************/

typedef enum {
	PXR_FOVEATION_Success = 0,
	PXR_FOVEATION_Success_OneEye = 1,

	PXR_FOVEATION_Failure = -1000,
	PXR_FOVEATION_InvalidData = -1001,
	PXR_FOVEATION_InvalidParams = -1002,
	PXR_FOVEATION_NotInitialized = -1003,
} PxrFoveationStateCode;

/*************************************** Adaptive Resolution ***************************************/
typedef enum PxrAdaptiveResolutionPowerSetting {
    PXR_ADAPTIVE_RESOLUTION_HIGH_QUALITY,
    PXR_ADAPTIVE_RESOLUTION_BALANCED,
    PXR_ADAPTIVE_RESOLUTION_BATTERY_SAVING
} PxrAdaptiveResolutionPowerSetting;


#endif  // PXR_TYPES_H
