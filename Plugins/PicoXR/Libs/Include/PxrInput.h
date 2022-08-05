#ifndef PXR_INPUT_H
#define PXR_INPUT_H

#include "PxrTypes.h"
#include "PxrEnums.h"

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
    PXR_CONTROLLER_KEY_BY= 2,
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
} PxrControllerType;


typedef enum {
    PXR_NEO3_DEVICE = 1,
    PXR_PHOENIX_DEVICE = 2,
} PxrHMDType;

typedef struct PxrControllerTracking_ {
    PxrSensorState localControllerPose;
    PxrSensorState globalControllerPose;
} PxrControllerTracking;

typedef struct PxrVector2f_ {
    float    x; //0~255
    float    y; //0~255
} PxrVector2f;

typedef struct PxrControllerInputState_ {
    PxrVector2f Joystick;   // 0-255
    int homeValue;          // 0/1
    int backValue;          // 0/1
    int touchpadValue;      // 0/1
    int volumeUp;           // 0/1
    int volumeDown;         // 0/1
    float triggerValue;       // 0-255 --> 0-1
    int batteryValue;       // 0-5
    int AXValue;            // 0/1
    int BYValue;            // 0/1
    int sideValue;          // 0/1
    float gripValue;          // 0-255  --> 0-1
    int triggerclickValue;    // 0/1
    int reserved_key_1;
    int reserved_key_2;
    int reserved_key_3;
    int reserved_key_4;

    int AXTouchValue;       // 0/1
    int BYTouchValue;       // 0/1
    int rockerTouchValue;   // 0/1
    int triggerTouchValue;  // 0/1
    int thumbrestTouchValue;// 0/1
    int reserved_touch_0;
    int reserved_touch_1;
    int reserved_touch_2;
    int reserved_touch_3;
    int reserved_touch_4;

} PxrControllerInputState;

typedef struct PxrControllerInputStateDowntimeStamp_ {

    long home;          // 0/1
    long back;          // 0/1
    long touchpad;      // 0/1
    long volumeUp;           // 0/1
    long volumeDown;         // 0/1
    long AX;            // 0/1
    long BY;            // 0/1
    long side;          // 0/1
    long grip;          // 0-255
    long reserved_key_0;
    long reserved_key_1;
    long reserved_key_2;
    long reserved_key_3;
    long reserved_key_4;

    long AXTouch;       // 0/1
    long BYTouch;       // 0/1
    long rockerTouch;   // 0/1
    long triggerTouch;  // 0/1
    long thumbrestTouch;// 0/1
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
//    int int_value;
    bool up;
    bool down;
    bool shortpress;
    bool longpress;
} PxrInputEvent;

typedef struct PxrControllerInputEvent_ {
    PxrInputEvent home;          // 0/1
    PxrInputEvent back;          // 0/1
    PxrInputEvent touchpad;      // 0/1
    PxrInputEvent volumeUp;      // 0/1
    PxrInputEvent volumeDown;    // 0/1
    PxrInputEvent AX;            // 0/1
    PxrInputEvent BY;            // 0/1
    PxrInputEvent side;          // 0/1
    PxrInputEvent reserved_0_Key;// 0/1
    PxrInputEvent reserved_1_Key;// 0/1
    PxrInputEvent reserved_2_Key;// 0/1
    PxrInputEvent reserved_3_Key;// 0/1
    PxrInputEvent reserved_4_Key;// 0/1

    PxrInputEvent AXTouch;       // 0/1
    PxrInputEvent BYTouch;       // 0/1
    PxrInputEvent rockerTouch;   // 0/1
    PxrInputEvent triggerTouch;  // 0/1
    PxrInputEvent thumbrestTouch;// 0/1
    PxrInputEvent reserved_0_Touch;// 0/1
    PxrInputEvent reserved_1_Touch;// 0/1
    PxrInputEvent reserved_2_Touch;// 0/1
    PxrInputEvent reserved_3_Touch;// 0/1
    PxrInputEvent reserved_4_Touch;// 0/1

} PxrControllerInputEvent;


typedef struct PxrControllerCapability_ {
    PxrControllerType             type;
    PxrControllerDof              Dof;
    PxrControllerBond             inputBond;
    u_int64_t                 Abilities;
} PxrControllerCapability;

typedef struct PxrControllerInfo_ {
    PxrControllerType             type;
    char* mac;
    char* sn;
    char* version;
} PxrControllerInfo;

//Handtracking data
typedef enum {
    pxrNoneActive               = 0,
    pxrControllerActive         = 1,
    pxrHandTrackingActive       = 2,
}PxrActiveInputDeviceType;
typedef enum{
    PxrNone = -1,
    PxrHandLeft = 0,
    PxrHandRight = 1,
}PxrHandType;
typedef enum{
    PxrSkeletonTypeNone = -1,
    PxrSkeletonTypeHandLeft = 0,
    PxrSkeletonTypeHandRight = 1,
} PxrSkeletonType;
typedef enum {
    PxrMeshTypeNone = -1,
    PxrMeshTypeHandLeft = 0,
    PxrMeshTypeHandRight = 1,
} PxrMeshType;
typedef enum PxrHandTrackingStatus_{
    PxrHandTracked = (1 << 0),
    PxrInputStateValid = (1 << 1),
    PxrSystemGestureInProgress = (1 << 6),
    PxrDominantHand = (1 << 7),
    PxrMenuPressed = (1 << 8)
}PxrHandTrackingStatus;
typedef struct PxrVector4f_ {
    float x, y, z, w;
}PxrVector4f;
typedef struct PxrVector4s_ {
    int16_t x, y, z, w;
}PxrVector4s;
typedef enum PxrHandBoneIndex_{
    PxrHandBone_Invalid = -1,
    PxrHandBone_WristRoot = 0, // root frame of the hand, where the wrist is located
    PxrHandBone_ForearmStub = 1, // frame for user's forearm
    PxrHandBone_Thumb0 = 2, // thumb trapezium bone
    PxrHandBone_Thumb1 = 3, // thumb metacarpal bone
    PxrHandBone_Thumb2 = 4, // thumb proximal phalange bone
    PxrHandBone_Thumb3 = 5, // thumb distal phalange bone
    PxrHandBone_Index1 = 6, // index proximal phalange bone
    PxrHandBone_Index2 = 7, // index intermediate phalange bone
    PxrHandBone_Index3 = 8, // index distal phalange bone
    PxrHandBone_Middle1 = 9, // middle proximal phalange bone
    PxrHandBone_Middle2 = 10, // middle intermediate phalange bone
    PxrHandBone_Middle3 = 11, // middle distal phalange bone
    PxrHandBone_Ring1 = 12, // ring proximal phalange bone
    PxrHandBone_Ring2 = 13, // ring intermediate phalange bone
    PxrHandBone_Ring3 = 14, // ring distal phalange bone
    PxrHandBone_Pinky0 = 15, // pinky metacarpal bone
    PxrHandBone_Pinky1 = 16, // pinky proximal phalange bone
    PxrHandBone_Pinky2 = 17, // pinky intermediate phalange bone
    PxrHandBone_Pinky3 = 18, // pinky distal phalange bone
    PxrHandBone_MaxSkinnable = 19,
    // Bone tips are position only. They are not used for skinning but useful for hit-testing.
    // NOTE: HandBone_ThumbTip == HandBone_MaxSkinnable since the extended tips need to be
    // contiguous

    PxrHandBone_ThumbTip = PxrHandBone_MaxSkinnable + 0, // tip of the thumb
    PxrHandBone_IndexTip = PxrHandBone_MaxSkinnable + 1, // tip of the index finger
    PxrHandBone_MiddleTip = PxrHandBone_MaxSkinnable + 2, // tip of the middle finger
    PxrHandBone_RingTip = PxrHandBone_MaxSkinnable + 3, // tip of the ring finger
    PxrHandBone_PinkyTip = PxrHandBone_MaxSkinnable + 4, // tip of the pinky
    PxrHandBone_Max = PxrHandBone_MaxSkinnable + 5,
} PxrHandBoneIndex;
#define PxrHandBoneIndex_max 24

typedef enum {
    PxrHandPinch_Thumb  = 1 << 0,
    PxrHandPinch_Index  = 1 << 1,
    PxrHandPinch_Middle = 1 << 2,
    PxrHandPinch_Ring   = 1 << 3,
    PxrHandPinch_Pinky  = 1 << 4,
} PxrHandFingerPinch;
#define PxrHandFingerPinch_max 5

typedef enum {
    PxrTrackingConfidence_LOW,
    PxrTrackingConfidence_HIGH,
} PxrTrackingConfidence;
#define PxrHandFinger_Max 5

typedef struct Pxrhandstate_{
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

typedef struct Bone_{
    PxrPosef  Bones;
    PxrHandBoneIndex BoneIndices;
    PxrHandBoneIndex ParentBoneIndices;
}PxrBone;
#define PxrBoneCapsule_max 19
typedef struct PxrSkeleton_{
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
extern "C" {

/*******************************************************************************************************************************************************************
*
*                                                 Main Controller Feature Function
*
*********************************************************************************************************************************************************************/

/*
 * get input connecte state，type,input dof,touch and mac addr.
 */
int Pxr_GetControllerCapabilities(uint32_t deviceID, PxrControllerCapability *capability);

/*
 * get input connecte state.
 */
int Pxr_GetControllerConnectStatus(uint32_t deviceID);

//get input sensor data
//attention: predictTime can be set 0 if user do not need predict. headSensorData can be set NULL too.
int Pxr_GetControllerTrackingState(uint32_t deviceID, double predictTime, float headSensorData[],
                                   PxrControllerTracking *tracking);

//get input key state,please refer to PxrControllerInputState struct
int Pxr_GetControllerInputState(uint32_t deviceID, PxrControllerInputState *state);

//get input key Event,please refer to PxrControllerInputEvent struct
int Pxr_GetControllerInputEvent(uint32_t deviceID, PxrControllerInputEvent *event);

/******************************************************
 * set input vibration
 ******************************************************/
int Pxr_SetControllerVibration(uint32_t deviceID, float strength, int time);
int Pxr_SetControllerVibrationEvent(uint32_t deviceID,int frequency, float strength, int time);

/*******************************************************************************************************************************************************************
*
*                                          Controller Manager Feature Function
*
*********************************************************************************************************************************************************************/
//set Virtual Key by developer
int Pxr_SetVirtualKey(int keytype,int keyvalue,int controller);
//set app can get key value
int Pxr_SetControllerEnableKey(bool isEnable,PxrControllerKeyMap Key);

//set main input device
int Pxr_SetControllerMainInputHandle(uint32_t deviceID);

//get main input device
int Pxr_GetControllerMainInputHandle(uint32_t *deviceID);

//get main input device
int Pxr_SetControllerUnbind(uint32_t deviceID);

//get main input device
int Pxr_SetControllerEnterPairing(uint32_t deviceID);

//get main input device
int Pxr_SetControllerStopPairing(uint32_t deviceID);

//get main input device
int Pxr_SetControllerUpgrade(uint32_t deviceID,int rule,char* station_path_by_char,char* controller_path_by_char);

/*
 * get input device type/mac/sn addr.
 */
int Pxr_GetControllerinfo(uint32_t deviceID, PxrControllerInfo *info);

/*
 * vibrate the controller
 */

int Pxr_StopControllerVCMotor(int clientId);
int Pxr_StartControllerVCMotor(char* file,int slot,int slotconfig);
int Pxr_SetControllerAmp(float mode);
int Pxr_SetControllerDelay(int delay);
char*  Pxr_GetVibrateDelayTime(int* length);
int Pxr_StartVibrateBySharemF(float* data,AudioClipData* parameter);
int Pxr_StartVibrateBySharemU(uint8_t * data,AudioClipData* parameter);
int Pxr_StartVibrateByCache(int clicpid);
int Pxr_ClearVibrateByCache(int clicpid);
//handtracking function
int Pxr_SetAppHandTrackingEnabled(bool  bHandTrackingEnabled);
int Pxr_GetActiveInputDeviceType(PxrActiveInputDeviceType * ActiveInputType);
int Pxr_GetHandTrackingEnabled(bool * bHandTrackingEnabled);
int Pxr_GetHandTrackingHandState(PxrHandType  HandID,int16_t coordinateflag,PxrHandState * HandtrackHandState);
int Pxr_GetHandTrackingSkeleton(PxrSkeletonType Handtrackskeletontype,PxrSkeleton * HandtrackSkeleton);
int Pxr_GetHandTrackingMesh(PxrMeshType HandtrackMeshType,PxrHandMesh * HandtrackHandMesh);
//handtracking function

/*******************************************************************************************************************************************************************
*
*                                                 Main Hand Feature Function
*
*********************************************************************************************************************************************************************/

/*
 * there is some function about hand,so put hand function here.
 */





/*******************************************************************************************************************************************************************
*
*                                          legacy Function  don't use!
*
*********************************************************************************************************************************************************************/

int *Pxr_GetControllerKeyEventExt(int controllerSerialNum, int devicetype);
int Pxr_GetControllerTouchEvent(int controllerSerialNum, int length, int *value);
int Pxr_SetInputEventCallback(bool enable_Input_callback);
//reset input pose
int Pxr_RecenterInputPose(uint32_t deviceID);
//get head raw sensor data
int Pxr_GetHeadSensorData(float *data);

}
#endif //PXR_INPUT_H
