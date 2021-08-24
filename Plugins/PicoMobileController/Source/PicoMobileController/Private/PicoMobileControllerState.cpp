// Copyright © 2015-2020 Pico Technology Co., Ltd. All Rights Reserved.

#include "PicoMobileControllerState.h"
#include "PicoMobileControllerBFlib.h"

#if PLATFORM_ANDROID
PicoMobileControllerState::PicoMobileControllerState():
	ArmJointType(ArmJoint::Controller),
	ConnentState(0)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();

	id_getHBConnectState = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getHBConnectState", "()I", false);
	id_getHBButtonState = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getHBButtonState", "(I)Z", false);
	id_setHBGazeType = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "setHBGazeType", "(I)V", false);
	id_getHBGazeType = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getHBGazeType", "()I", false);
	id_setHBElbowHeight = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "setHBElbowHeight", "(F)V", false);
	id_setHBElbowDepth = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "setHBElbowDepth", "(F)V", false);
	id_setHBPointerTiltAngle = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "setHBPointerTiltAngle", "(F)V", false);
	id_getHBArmModelParm = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getHBArmModelParm", "()[F", false);
	id_setHBArmJoint = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "setHBArmJoint", "(I)V", false);
	id_getHBOrientation = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getHBOrientation", "()[F", false);
	id_getHBPosition = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getHBPosition", "()[F", false);
	id_getHBAcc = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getHBAcc", "()[F", false);
	id_getHBAgl = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getHBAgl", "()[F", false);
	id_getHBTouchPad = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getHBTouchPad", "()[I", false);
	id_GetControllerEvent = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetHBControllerButtonEvent", "()[I", false);
	id_GetControllerRotationMode = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "HBGetControllerRotationMode", "()I", false);
}

PicoMobileControllerState::~PicoMobileControllerState()
{
}

int32 PicoMobileControllerState::GetHBConnectState()
{
	return ConnentState;
}


void PicoMobileControllerState::UpdateConnectState()
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	ConnentState = (int32)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, id_getHBConnectState);
}

bool PicoMobileControllerState::GetHBButtonState(int32 buttonIndex)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	return FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, id_getHBButtonState, buttonIndex);
}

void PicoMobileControllerState::SetHBGazeType(int32 gazetype)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, id_setHBGazeType, gazetype);
}

int32 PicoMobileControllerState::GetHBGazeType()
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	return (int32)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, id_getHBGazeType);
}

void PicoMobileControllerState::SetHBElbowHeight(float elbowheight)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, id_setHBElbowHeight, elbowheight);
}

void PicoMobileControllerState::SetHBElbowDepth(float elbowdepth)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, id_setHBElbowDepth, elbowdepth);
}

void PicoMobileControllerState::SetHBPointerTiltAngle(float pointertiltangle)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, id_setHBPointerTiltAngle, pointertiltangle);
}

void PicoMobileControllerState::GetHBArmModelParm(FVector &parm)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jfloatArray jfArray = (jfloatArray)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, id_getHBArmModelParm);
	jfloat *jfp = Env->GetFloatArrayElements(jfArray, JNI_FALSE);
	parm.X = jfp[0];
	parm.Y = jfp[1];
	parm.Z = jfp[2];
	Env->ReleaseFloatArrayElements(jfArray, jfp, JNI_ABORT);
	Env->DeleteLocalRef(jfArray);
}

void PicoMobileControllerState::SetHBArmJoint(int32 armJoint)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, id_setHBArmJoint, armJoint);
	switch (armJoint)
	{
	case 0:
		ArmJointType = ArmJoint::Controller;
		break;
	case 1:
		ArmJointType = ArmJoint::Wrist;
		break;
	case 2:
		ArmJointType = ArmJoint::Elbow;
		break;
	case 3:
		ArmJointType = ArmJoint::Shoulder;
		break;
	}
}

PicoMobileControllerState::ArmJoint PicoMobileControllerState::GetHBArmJoint()
{
	return ArmJointType;
}

void PicoMobileControllerState::GetHBOrientation(FQuat &outOri)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jfloatArray jfArray = (jfloatArray)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, id_getHBOrientation);
	jfloat *jfp = Env->GetFloatArrayElements(jfArray, JNI_FALSE);
	outOri.X = jfp[2];
	outOri.Y = jfp[0];
	outOri.Z = jfp[1];
	outOri.W = jfp[3];
	Env->ReleaseFloatArrayElements(jfArray, jfp, JNI_ABORT);
	Env->DeleteLocalRef(jfArray);
}

void PicoMobileControllerState::GetHBPosition(FVector &outPos)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jfloatArray jfArray = (jfloatArray)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, id_getHBPosition);
	jfloat *jfp = Env->GetFloatArrayElements(jfArray, JNI_FALSE);
	outPos.X = jfp[0];
	outPos.Y = jfp[1];
	outPos.Z = jfp[2];
	Env->ReleaseFloatArrayElements(jfArray, jfp, JNI_ABORT);
	Env->DeleteLocalRef(jfArray);
}

void PicoMobileControllerState::GetHBAcc(FVector& outAcc)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jfloatArray jfArray = (jfloatArray)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, id_getHBAcc);
	jfloat *jfp = Env->GetFloatArrayElements(jfArray, JNI_FALSE);
	outAcc.X = jfp[0];
	outAcc.Y = jfp[1];
	outAcc.Z = jfp[2];
	Env->ReleaseFloatArrayElements(jfArray, jfp, JNI_ABORT);
	Env->DeleteLocalRef(jfArray);
}

void PicoMobileControllerState::GetHBAgl(FVector &outAgl)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jfloatArray jfArray = (jfloatArray)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, id_getHBAgl);
	jfloat *jfp = Env->GetFloatArrayElements(jfArray, JNI_FALSE);
	outAgl.X = jfp[0];
	outAgl.Y = jfp[1];
	outAgl.Z = jfp[2];
	Env->ReleaseFloatArrayElements(jfArray, jfp, JNI_ABORT);
	Env->DeleteLocalRef(jfArray);
}

void PicoMobileControllerState::GetHBTouchPad(FVector2D &outTou)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jintArray jiArray = (jintArray)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, id_getHBTouchPad);
	jint *jip = Env->GetIntArrayElements(jiArray, JNI_FALSE);

	if (0 == jip[0] && 0 == jip[1])
	{
		outTou.Y = 0;
		outTou.X = 0;
	}
	else
	{
		outTou.Y = (((float)jip[0]) / 255 - 0.5f) * 2;
		outTou.X = (((float)jip[1]) / 255 - 0.5f) * 2;
	}

	Env->ReleaseIntArrayElements(jiArray, jip, JNI_ABORT);
	Env->DeleteLocalRef(jiArray);
}

void PicoMobileControllerState::GetControllerButtonEvent(int *OutButton)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jintArray jiArray = (jintArray)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, id_GetControllerEvent);
	jint *jip = Env->GetIntArrayElements(jiArray, JNI_FALSE);
	for (int i = 0; i < 47; i++)
	{
		OutButton[i] = jip[i];
	}
	Env->ReleaseIntArrayElements(jiArray, jip, JNI_ABORT);
	Env->DeleteLocalRef(jiArray);
}

int32 PicoMobileControllerState::GetControllerRotationMode()
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	return (int32)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, id_GetControllerRotationMode);
}

PicoMobileControllerState* PicoMobileControllerState::pControllerState = nullptr;


extern "C" JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_nativePicoCtrlerConnected(JNIEnv * jni, jclass clazz)
{
	UPicoMobileControllerBFlib::PicoControllerConnected.ExecuteIfBound();
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_nativePicoCtrlerDisconnected(JNIEnv * jni, jclass clazz)
{
	UPicoMobileControllerBFlib::PicoControllerDisconnected.ExecuteIfBound();
}
extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_nativePicoRecenter(JNIEnv * jni, jclass clazz)
{
}
extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_UpdateMobileControllerConnectState(JNIEnv * jni, jclass clazz)
{
	PicoMobileControllerState::GetInstance()->UpdateConnectState();
}
#endif