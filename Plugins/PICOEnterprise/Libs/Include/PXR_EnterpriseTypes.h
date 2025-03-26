// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved. 

#ifndef __PXR_SDK_TYPES_H__
#define __PXR_SDK_TYPES_H__

#include <stdint.h>
#include <string>

const int CONTROLLER_STATE_STATIC = 0;
const int CONTROLLER_STATE_MOVING = 1;

enum PoseErrorType
{
    BRIGHT_LIGHT_ERROR        = (1 << 0),
    LOW_LIGHT_ERROR           = (1 << 1),
    LOW_FEATURE_COUNT_ERROR   = (1 << 2),
    CAMERA_CALIBRATION_ERROR  = (1 << 3),
    RELOCATION_IN_PROGRESS    = (1 << 4),
    INITILIZATION_IN_PROGRESS = (1 << 5),
    NO_CAMERA_ERROR           = (1 << 6),
    NO_IMU_ERROR              = (1 << 7),
    IMU_JITTER_ERROR          = (1 << 8),
    UNKNOWN_ERROR             = (1 << 9)
};

// pico slam results
typedef struct six_dof
{
    int64_t timestamp; // nanoseconds
    double x;  // position X
    double y;  // position Y
    double z;  // position Z
    double rw; // rotation W
    double rx; // rotation X
    double ry; // rotation Y
    double rz; // rotation Z
    uint8_t type;           //1:6DOF 0:3DOF 
    uint8_t confidence;     //1:good 0:bad
    PoseErrorType error;
    double  plane_height;   
    uint8_t plane_status;
    uint8_t relocation_status;
    uint8_t reserved[24];
} six_dof_t;

typedef struct 
{
   six_dof_t pose;
   six_dof_t relocation_pose;
   double vx,vy,vz; //!< 线速度
   double ax,ay,az; //!< 线加速度
   double wx,wy,wz; //!< 角速度
   double w_ax,w_ay,w_az; //!< 角加速度
   uint8_t reserved[48];
} algo_result_t;

typedef struct
{
   int id;
   float x;
   float y;
   float z;
} point_item_t;

typedef struct point_info_t
{
    int size;
    int maxSize = 2000;
    point_item_t point[2000];
} point_info_t;

enum CameraType
{
    MONO_CAMERA = 0,
    RGB_CAMERA = 1,
    TOF_CAMERA = 2,
    SECOND_MOMO_CAMERA = 3,
    THIRD_MONO_CAMERA = 4,
    FORTH_MONO_CAMERA = 5,
    FOUR_IN_ONE_MONO_CAMERA = 6,
    CAMERA_NUM,
};

typedef struct
{
    uint8_t  camera_id;
    uint32_t width;                // width
    uint32_t height;               // height
    uint32_t format;               // format
    uint32_t exposure_duration;             // exposure duration:ns
    int64_t timestamp;  // start of exposure time:ns (BOOTTIME)
    int64_t qtimer_timestamp;      // nanoseconds in qtimer
    uint64_t framenumber;          // frame number
    uint32_t datasize;             // datasize
    uint8_t *data;                 // data
} frame_item_t;

typedef struct
{
    frame_item_t frame;
    bool is_rgb;
    double rgb_tsw_matrix[16];
    bool is_anti_distortion;
    algo_result_t six_dof_pose;
    uint8_t reserved[64];
} frame_item_ext_t;

//======================hand=======================
typedef enum {
    None = -1,
    HandLeft = 0,
    HandRight = 1,
} SkeletonType;

enum HandFinger {
    Finger_Thumb = 0,
    Finger_Index = 1,
    Finger_Middle = 2,
    Finger_Ring = 3,
    Finger_Pinky = 4,
    Finger_Max = 5,
};

typedef enum {
    HandBone_Invalid = -1,
    HandBone_WristRoot = 0,                                    // --  root frame of the hand, where the wrist is located
    HandBone_ForearmStub = 1,                                  // --  frame for user's forearm
    HandBone_Thumb0 = 2,                                       // --  thumb trapezium bone
    HandBone_Thumb1 = 3,                                       // --  thumb metacarpal bone
    HandBone_Thumb2 = 4,                                       // --  thumb proximal phalange bone
    HandBone_Thumb3 = 5,                                       // --  thumb distal phalange bone
    HandBone_Index1 = 6,                                       // --  index proximal phalange bone
    HandBone_Index2 = 7,                                       // --  index intermediate phalange bone
    HandBone_Index3 = 8,                                       // --  index distal phalange bone
    HandBone_Middle1 = 9,                                      // --  middle proximal phalange bone
    HandBone_Middle2 = 10,                                     // --  middle intermediate phalange bone
    HandBone_Middle3 = 11,                                     // --  middle distal phalange bone
    HandBone_Ring1 = 12,                                       // --  ring proximal phalange bone
    HandBone_Ring2 = 13,                                       // --  ring intermediate phalange bone
    HandBone_Ring3 = 14,                                       // --  ring distal phalange bone
    HandBone_Pinky0 = 15,                                      // --  pinky metacarpal bone
    HandBone_Pinky1 = 16,                                      // --  pinky proximal phalange bone
    HandBone_Pinky2 = 17,                                      // --  pinky intermediate phalange bone
    HandBone_Pinky3 = 18,                                      // --  pinky distal phalange bone
    HandBone_MaxSkinnable = 19,
    HandBone_ThumbTip = HandBone_MaxSkinnable + 0,          // -- tip of the thumb
    HandBone_IndexTip = HandBone_MaxSkinnable + 1,          // -- tip of the index finger
    HandBone_MiddleTip = HandBone_MaxSkinnable + 2,         // -- tip of the middle finger
    HandBone_RingTip = HandBone_MaxSkinnable + 3,           // -- tip of the ring finger
    HandBone_PinkyTip = HandBone_MaxSkinnable + 4,          // -- tip of the pinky
    HandBone_Max = HandBone_MaxSkinnable + 5,
} HandBoneIndex;

#define Hand_MaxFingers  Finger_Max
#define Hand_MaxPinch    Finger_Max
#define Hand_MaxBones    HandBone_Max
#define Hand_MaxVertices 3000
#define Hand_MaxIndices  Hand_MaxVertices*6
#define Hand_MaxCapsules HandBone_Max

typedef enum {
    pvrConfidence_LOW,                                       // -- low
    pvrConfidence_HIGH,                                      // -- high
} TrackingConfidence;

typedef struct Quatf_ {
    float x, y, z, w;
} Quatf;

typedef struct Vectf_ {
    float x, y, z;
} Vectf;

typedef struct Posef_ {
    Quatf Orientation;                                       // -- rotation
    Vectf Position;                                          // -- position
} Posef;

typedef struct HandState_ {
    int16_t Status;                                             // --tracked or no HandTrackingStatus
    Posef RootPose;                                            // --root pose in global
    Posef BonePose[Hand_MaxBones];                             // --pose of bones
    int16_t Pinches;                                            // --finger pinched
    float PinchStrength[Hand_MaxPinch];                         // --degree of pinch
    float ClickStrength;                                        // --Strength of click
    Posef PointerPose;                                          // --interaction pose:捏合后的射线姿态
    float HandScale;                                            // --scale
    TrackingConfidence HandConfidence;                          // --confidence of hand
    TrackingConfidence FingerConfidence[Hand_MaxFingers];            // --confidence of finger
    double RequestedTimeStamp;                                  // --time stamp of requested
    double SampleTimeStamp;                                     // --time stamp of camera return
} HandState;

typedef struct HandStateParam_
{
    int64_t predictTime;
    SkeletonType type;
    int coordinateMask;
    int reserved[4];
} HandStateParam;
//======================hand=======================

//======================body=======================
// imu wear position
typedef enum BodyTrackerRole
{
    Pelvis         = 0,
    LEFT_HIP       = 1,
    RIGHT_HIP      = 2,
    SPINE1         = 3,
    LEFT_KNEE      = 4,
    RIGHT_KNEE     = 5,
    SPINE2         = 6,
    LEFT_ANKLE     = 7,
    RIGHT_ANKLE    = 8,
    SPINE3         = 9,
    LEFT_FOOT      = 10,
    RIGHT_FOOT     = 11,
    NECK           = 12,
    LEFT_COLLAR    = 13,
    RIGHT_COLLAR   = 14,
    HEAD           = 15,
    LEFT_SHOULDER  = 16,
    RIGHT_SHOULDER = 17,
    LEFT_ELBOW     = 18,
    RIGHT_ELBOW    = 19,
    LEFT_WRIST     = 20,
    RIGHT_WRIST    = 21,
    LEFT_HAND      = 22,
    RIGHT_HAND     = 23,
    NONE_ROLE      = 24,                // unvalid
    MIN_ROLE       = 0,                 // min value
    MAX_ROLE       = 23,                // max value
    ROLE_NUM       = 24,
} BodyTrackerRole;

typedef struct BodyTrackerPose
{
    int64_t TimeStamp;                // time stamp of imu
    double    PosX;                     // position of x
    double    PosY;                     // position of y
    double    PosZ;                     // position of z
    double    RotQx;                    // x components of Quaternion
    double    RotQy;                    // y components of Quaternion
    double    RotQz;                    // z components of Quaternion
    double    RotQw;                    // w components of Quaternion
} BodyTrackerPose;

typedef struct BodyTrackingTransform
{
    BodyTrackerRole bone;                // bone name. if bone == NONE_ROLE, this bone is not calculated
    BodyTrackerPose   l_transform;         // the position and pose of bone in local world frame
    BodyTrackerPose   g_transform;         // the position and pose of bone in global world frame
    double         velo[3];             // (temporarily deprecated)velocity of x,y,z
    double         acce[3];             // (temporarily deprecated)acceleration of x,y,z
    double         wvelo[3];            // (temporarily deprecated)angular velocity of x,y,z
    double         wacce[3];            // (temporarily deprecated)angular acceleration of x,y,z
    uint32_t       action;              // multiple actions can be supported at the same time by means of OR
    uint8_t        reserved[8];
} BodyTrackingTransform;

typedef struct BodyTrackingData
{
    BodyTrackingTransform trackingdata[ROLE_NUM];
} BodyTrackingData;

enum SwiftCalibState
{
    CALIB_OFF = 0,                        // off
    STATIC_CALIB_STATE_FIRST_STEP = 1,    // first step static calib
    STATIC_CALIB_STATE_SECOND_STEP = 2,   // second step static calib
    DYNAMIC_CALIB = 3,                    // dynamic calib
    RESET_CALIB = 4,                    // reset calib
};
//======================body=======================
//======================Accessary==================
typedef struct SwiftConnectState
{
    uint8_t num; // 实际个数
    uint8_t trackerID[12]; // 已连接的trackerId
} SwiftConnectState;
//======================Accessary==================

//======================MRManager$VST==================
typedef struct CameraCallBackContext
{
    uint8_t camera_id;
    int32_t width;
    int32_t height;
    int32_t format;
    int64_t timestamp;     // start_exposure_time
    int64_t exposuretime;  // exposure_duration_time
    uint64_t framenumber_6dof;
} CameraCallBackContext;

typedef struct CameraMeta
{
    CameraCallBackContext ctx;
    double rgb_tsw[16];
} CameraMeta;

typedef struct see_pose
{
  float x;  // position X
  float y;  // position Y
  float z;  // position Z
  float rw; // rotation W
  float rx; // rotation X
  float ry; // rotation Y
  float rz; // rotation Z
} see_pose_t;

typedef struct frame_item_undistorted
{
    uint8_t  camera_id;
    uint32_t width;                // width
    uint32_t height;               // height
    uint32_t format;               // format
    uint32_t exposure_duration;             // exposure time:ns
    int64_t timestamp;  // start of exposure time:ns (BOOTTIME)
    int64_t qtimer_timestamp;      // nanoseconds in qtimer
    uint64_t framenumber;          // frame number
    uint32_t datasize;             // datasize
    float frate;
    algo_result_t pose;
} frame_item_undistorted_t;

typedef struct rgb_camera_params
{
    //内参
    float fx;
    float fy;
    float cx;
    float cy;
    //外参
    double x;
    double y;
    double z;
    double rw;
    double rx;
    double ry;
    double rz;
} rgb_camera_params;
//======================MRManager$VST==================
#endif