// Copyright © 2015-2020 Pico Technology Co., Ltd. All Rights Reserved.

#include "PicoNeoControllerJni.h"
#include "PicoNeoControllerBPlib.h"

DEFINE_LOG_CATEGORY_STATIC(Jni, Log, All);

#if PLATFORM_ANDROID

extern "C"
JNIEXPORT void JNICALL
Java_com_epicgames_ue4_GameActivity_onNativeBindFail(JNIEnv *env, jobject instance)
{
	UE_LOG(Jni, Warning, TEXT("Pvr_UE Native Bind Fail"));
}

extern "C"
JNIEXPORT void JNICALL
Java_com_epicgames_ue4_GameActivity_onNativeTreadStart(JNIEnv *env, jobject instance)
{
	UPicoNeoControllerBPlib::NativeTreadStart.ExecuteIfBound();
	UE_LOG(Jni, Warning, TEXT("Pvr_UE Native Tread Start"));
}

extern "C"
JNIEXPORT void JNICALL
Java_com_epicgames_ue4_GameActivity_onNativeMainControllerConnect(JNIEnv *env, jobject instance)
{
	UPicoNeoControllerBPlib::MainControllerConnect.ExecuteIfBound();
	UE_LOG(Jni, Warning, TEXT("Pvr_UE Native MainController Connect"));
}

extern "C"
JNIEXPORT void JNICALL
Java_com_epicgames_ue4_GameActivity_onNativeMainControllerDisconnect(JNIEnv *env, jobject instance)
{
	UPicoNeoControllerBPlib::MainControllerDisconnect.ExecuteIfBound();
	UE_LOG(Jni, Warning, TEXT("Pvr_UE Native MainController Disconnect"));
}

extern "C"
JNIEXPORT void JNICALL
Java_com_epicgames_ue4_GameActivity_onNativeSubControllerConnect(JNIEnv *env, jobject instance)
{
	UPicoNeoControllerBPlib::SubControllerConnect.ExecuteIfBound();
	UE_LOG(Jni, Warning, TEXT("Pvr_UE Native SubController Connect"));
}

extern "C"
JNIEXPORT void JNICALL
Java_com_epicgames_ue4_GameActivity_onNativeSubControllerDisconnect(JNIEnv *env, jobject instance)
{
	UPicoNeoControllerBPlib::SubControllerDisconnect.ExecuteIfBound();
	UE_LOG(Jni, Warning, TEXT("Pvr_UE Native SubController Disconnect"));
}

extern "C"
JNIEXPORT void JNICALL
Java_com_epicgames_ue4_GameActivity_UpdateNeoControllerConnectState(JNIEnv *env, jobject instance)
{
	FPicoNeoControllerJni::GetInstance()->UpdateControllerConnectState();
	UE_LOG(Jni, Warning, TEXT("Pvr_UE Native UpdateNeoControllerConnectState"));
}

extern "C"
JNIEXPORT void JNICALL
Java_com_epicgames_ue4_GameActivity_StopThread(JNIEnv *env, jobject instance)
{
	FPicoNeoControllerJni::GetInstance()->SetServiceConnectState(0);
	UE_LOG(Jni, Warning, TEXT("Pvr_UE Native StopThread"));
}

extern "C"
JNIEXPORT void JNICALL
Java_com_epicgames_ue4_GameActivity_OnServiceBindSucceed(JNIEnv *env, jobject instance)
{
	FPicoNeoControllerJni::GetInstance()->SetServiceConnectState(1);
	UE_LOG(Jni, Warning, TEXT("Pvr_UE Native OnServiceBindSucceed"));
}
extern "C"
JNIEXPORT void JNICALL
Java_com_epicgames_ue4_GameActivity_OnLifeResumed(JNIEnv *env, jobject instance,jboolean isresumed)
{
	FPicoNeoControllerJni::GetInstance()->SetLifeResumed(isresumed);
	UE_LOG(Jni, Warning, TEXT("Pvr_UE Native OnLifeResumed %s"),(isresumed == JNI_TRUE)? TEXT("TRUE"):TEXT("FALSE"));

}
FPicoNeoControllerJni* FPicoNeoControllerJni::pSingleInstance = nullptr;

FPicoNeoControllerJni::FPicoNeoControllerJni()
	:MainControllerConnectState(0),
	SubControllerConnectState(0)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();

	id_getNeoDeviceType = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getNeoDeviceType", "()I", false);
	id_setMainArmJoint = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "setMainArmJoint", "(I)V", false);
	id_getMainArmJoint = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getMainArmJoint", "()I", false);
	id_setMainGazeType = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "setMainGazeType", "(I)V", false);
	id_getMainGazeType = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getMainGazeType", "()I", false);
	id_setMainArmModelParm = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "setMainArmModelParm", "(FFF)V", false);
	id_getMainArmModelParm = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getMainArmModelParm", "()[F", false);
	id_setSubArmJoint = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "setSubArmJoint", "(I)V", false);
	id_getSubArmJoint = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getSubArmJoint", "()I", false);
	id_setSubGazeType = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "setSubGazeType", "(I)V", false);
	id_getSubGazeType = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getSubGazeType", "()I", false);
	id_setSubArmModelParm = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "setSubArmModelParm", "(FFF)V", false);
	id_getSubArmModelParm = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getSubArmModelParm", "()[F", false);

	id_getMainControllerConnectState = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getMainControllerConnectState", "()I", false);
	id_getSubControllerConnectState = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getSubControllerConnectState", "()I", false);
	id_getMainControllerSerialNum = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getMainControllerSerialNum", "()I", false);
	id_getSubControllerSerialNum = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getSubControllerSerialNum", "()I", false);
	id_getMainController6DofAbility = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getMainController6DofAbility", "()I", false);
	id_getSubController6DofAbility = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getSubController6DofAbility", "()I", false);
	id_getMainControllerButtonState = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getMainControllerButtonState", "(I)Z", false);
	id_getSubControllerButtonState = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getSubControllerButtonState", "(I)Z", false);
	id_getMainControllerBatteryLevel = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getMainControllerBatteryLevel", "()I", false);
	id_getSubControllerBatteryLevel = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getSubControllerBatteryLevel", "()I", false);
	id_getMainControllerOrientation = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getMainControllerOrientation", "()[F", false);
	id_getSubControllerOrientation = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getSubControllerOrientation", "()[F", false);
	id_getMainControllerPosition = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getMainControllerPosition", "()[F", false);
	id_getSubControllerPosition = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getSubControllerPosition", "()[F", false);
	id_getMainControllerAcc = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getMainControllerAcc", "()[F", false);
	id_getSubControllerAcc = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getSubControllerAcc", "()[F", false);
	id_getMainControllerAgl = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getMainControllerAgl", "()[F", false);
	id_getSubControllerAgl = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getSubControllerAgl", "()[F", false);
	id_getLeftControllerLvc = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getLeftLinearVelocity", "()[F", false);
	id_getRightControllerLvc = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getRightLinearVelocity", "()[F", false);
	id_getMainControllerTriggerNum = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getMainControllerTriggerNum", "()I", false);
	id_getSubControllerTriggerNum = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getSubControllerTriggerNum", "()I", false);
	id_getMainControllerTouchPad = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getMainControllerTouchPad", "()[I", false);
	id_getSubControllerTouchPad = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getSubControllerTouchPad", "()[I", false);
	id_shakeMainController = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "shakeMainController", "()V", false);
	id_shakeSubController = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "shakeSubController", "()V", false);
	id_shakeCV2Controller = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "shakeCV2Controller", "(FII)V", false);
	id_getMainControllerValue = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getMainControllerValue", "()I", false);
	id_StartControllerThread = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "StartControllerThread", "()V", false);
	id_GetControllerEvent = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getCVControllerButtonEvent", "()[I", false);
	id_GetControllerTouchEvent = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetControllerTouchEvent", "(I)[I", false);
	id_GetControllerGripValue = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetControllerGripValue", "(I)I", false);
	id_GetControllerRotationMode = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "NeoGetControllerRotationMode", "()I", false);
}

FPicoNeoControllerJni::~FPicoNeoControllerJni()
{
}

int32 FPicoNeoControllerJni::GetNeoDeviceType()
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	return (int32)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, id_getNeoDeviceType);
}

void FPicoNeoControllerJni::SetMainArmJoint(int32 aj)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, id_setMainArmJoint, aj);
}

int32 FPicoNeoControllerJni::GetMainArmJoint()
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	return (int32)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, id_getMainArmJoint);
}

void FPicoNeoControllerJni::SetMainGazeType(int32 gt)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, id_setMainGazeType, gt);
}

int32 FPicoNeoControllerJni::GetMainGazeType()
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	return (int32)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, id_getMainGazeType);
}

void FPicoNeoControllerJni::SetMainArmModelParm(float eh,float ed,float pta)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, id_setMainArmModelParm, eh,ed,pta);
}

void FPicoNeoControllerJni::GetMainArmModelParm(FVector& AMParm)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jfloatArray jfArray = (jfloatArray)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, id_getMainArmModelParm);
	jfloat *jfp = Env->GetFloatArrayElements(jfArray, JNI_FALSE);
	AMParm.X = jfp[0];
	AMParm.Y = jfp[1];
	AMParm.Z = jfp[2];
	Env->ReleaseFloatArrayElements(jfArray, jfp, JNI_ABORT);
	Env->DeleteLocalRef(jfArray);
}

void FPicoNeoControllerJni::SetSubArmJoint(int32 aj)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, id_setSubArmJoint, aj);
}

int32 FPicoNeoControllerJni::GetSubArmJoint()
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	return (int32)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, id_getSubArmJoint);
}

void FPicoNeoControllerJni::SetSubGazeType(int32 gt)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, id_setSubGazeType, gt);
}

int32 FPicoNeoControllerJni::GetSubGazeType()
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	return (int32)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, id_getSubGazeType);
}

void FPicoNeoControllerJni::SetSubArmModelParm(float eh, float ed, float pta)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, id_setSubArmModelParm, eh,ed,pta);
}

void FPicoNeoControllerJni::GetSubArmModelParm(FVector& AMParm)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jfloatArray jfArray = (jfloatArray)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, id_getSubArmModelParm);
	jfloat *jfp = Env->GetFloatArrayElements(jfArray, JNI_FALSE);
	AMParm.X = jfp[0];
	AMParm.Y = jfp[1];
	AMParm.Z = jfp[2];
	Env->ReleaseFloatArrayElements(jfArray, jfp, JNI_ABORT);
	Env->DeleteLocalRef(jfArray);
}

int32 FPicoNeoControllerJni::GetMainControllerConnectState()
{
	/*JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	return (int32)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, id_getMainControllerConnectState);*/
	return MainControllerConnectState;
}

int32 FPicoNeoControllerJni::GetSubControllerConnectState()
{
	/*JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	return (int32)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, id_getSubControllerConnectState);*/
	return SubControllerConnectState;
}


void FPicoNeoControllerJni::UpdateControllerConnectState()
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	int32 MainState =  (int32)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, id_getMainControllerConnectState);
	int32 SubState  =  (int32)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, id_getSubControllerConnectState);
	SetControllerConnectState(0, MainState);
	SetControllerConnectState(1, SubState);
}

int32 FPicoNeoControllerJni::GetServiceConnectState()
{
	return ServiceConnectState;
}

void FPicoNeoControllerJni::SetServiceConnectState(int32 newState)
{
	 ServiceConnectState = newState;
}

void FPicoNeoControllerJni::SetControllerConnectState(int32 handness, int32 newstate)
{
	if (handness == 0)
	{
		MainControllerConnectState = newstate;
	}
	else
	{
		SubControllerConnectState = newstate;
	}
}

int32 FPicoNeoControllerJni::GetMainControllerSerialNum()
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	return (int32)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, id_getMainControllerSerialNum);
}

int32 FPicoNeoControllerJni::GetSubControllerSerialNum()
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	return (int32)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, id_getSubControllerSerialNum);
}

int32 FPicoNeoControllerJni::GetMainController6DofAbility()
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	return (int32)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, id_getMainController6DofAbility);
}

int32 FPicoNeoControllerJni::GetSubController6DofAbility()
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	return (int32)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, id_getSubController6DofAbility);
}

bool FPicoNeoControllerJni::GetMainControllerButtonState(int32 buttonIndex)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	return FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, id_getMainControllerButtonState, buttonIndex);
}

bool FPicoNeoControllerJni::GetSubControllerButtonState(int32 buttonIndex)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	return FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, id_getSubControllerButtonState, buttonIndex);
}

int32 FPicoNeoControllerJni::GetMainControllerBatteryLevel()
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	return (int32)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, id_getMainControllerBatteryLevel);
}

int32 FPicoNeoControllerJni::GetSubControllerBatteryLevel()
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	return (int32)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, id_getSubControllerBatteryLevel);
}

void FPicoNeoControllerJni::GetMainControllerOrientation(FQuat &outOri)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jfloatArray jfArray = (jfloatArray)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, id_getMainControllerOrientation);
	jfloat *jfp = Env->GetFloatArrayElements(jfArray, JNI_FALSE);
	outOri.X = jfp[2];
	outOri.Y = jfp[0];
	outOri.Z = jfp[1];
	outOri.W = jfp[3];
	Env->ReleaseFloatArrayElements(jfArray, jfp, JNI_ABORT);
	Env->DeleteLocalRef(jfArray);
}

void FPicoNeoControllerJni::GetSubControllerOrientation(FQuat &outOri)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jfloatArray jfArray = (jfloatArray)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, id_getSubControllerOrientation);
	jfloat *jfp = Env->GetFloatArrayElements(jfArray, JNI_FALSE);
	outOri.X = jfp[2];
	outOri.Y = jfp[0];
	outOri.Z = jfp[1];
	outOri.W = jfp[3];
	Env->ReleaseFloatArrayElements(jfArray, jfp, JNI_ABORT);
	Env->DeleteLocalRef(jfArray);
}

void FPicoNeoControllerJni::GetMainControllerPosition(FVector &outPos)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jfloatArray jfArray = (jfloatArray)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, id_getMainControllerPosition);
	jfloat *jfp = Env->GetFloatArrayElements(jfArray, JNI_FALSE);
	outPos.X = jfp[0];
	outPos.Y = jfp[1];
	outPos.Z = jfp[2];
	Env->ReleaseFloatArrayElements(jfArray, jfp, JNI_ABORT);
	Env->DeleteLocalRef(jfArray);
}

void FPicoNeoControllerJni::GetSubControllerPosition(FVector &outPos)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jfloatArray jfArray = (jfloatArray)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, id_getSubControllerPosition);
	jfloat *jfp = Env->GetFloatArrayElements(jfArray, JNI_FALSE);
	outPos.X = jfp[0];
	outPos.Y = jfp[1];
	outPos.Z = jfp[2];
	Env->ReleaseFloatArrayElements(jfArray, jfp, JNI_ABORT);
	Env->DeleteLocalRef(jfArray);
}

void FPicoNeoControllerJni::GetMainControllerAcc(FVector &outAcc)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jfloatArray jfArray = (jfloatArray)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, id_getMainControllerAcc);
	jfloat *jfp = Env->GetFloatArrayElements(jfArray, JNI_FALSE);
	outAcc.X = jfp[0];
	outAcc.Y = jfp[1];
	outAcc.Z = jfp[2];
	Env->ReleaseFloatArrayElements(jfArray, jfp, JNI_ABORT);
	Env->DeleteLocalRef(jfArray);
}

void FPicoNeoControllerJni::GetSubControllerAcc(FVector &outAcc)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jfloatArray jfArray = (jfloatArray)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, id_getSubControllerAcc);
	jfloat *jfp = Env->GetFloatArrayElements(jfArray, JNI_FALSE);
	outAcc.X = jfp[0];
	outAcc.Y = jfp[1];
	outAcc.Z = jfp[2];
	Env->ReleaseFloatArrayElements(jfArray, jfp, JNI_ABORT);
	Env->DeleteLocalRef(jfArray);
}

void FPicoNeoControllerJni::GetMainControllerAgl(FVector &outAgl)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jfloatArray jfArray = (jfloatArray)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, id_getMainControllerAgl);
	jfloat *jfp = Env->GetFloatArrayElements(jfArray, JNI_FALSE);
	outAgl.X = jfp[0];
	outAgl.Y = jfp[1];
	outAgl.Z = jfp[2];
	Env->ReleaseFloatArrayElements(jfArray, jfp, JNI_ABORT);
	Env->DeleteLocalRef(jfArray);
}

void FPicoNeoControllerJni::GetSubControllerAgl(FVector &outAgl)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jfloatArray jfArray = (jfloatArray)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, id_getSubControllerAgl);
	jfloat *jfp = Env->GetFloatArrayElements(jfArray, JNI_FALSE);
	outAgl.X = jfp[0];
	outAgl.Y = jfp[1];
	outAgl.Z = jfp[2];
	Env->ReleaseFloatArrayElements(jfArray, jfp, JNI_ABORT);
	Env->DeleteLocalRef(jfArray);
}

void FPicoNeoControllerJni::GetLeftControllerLvc(FVector &outLvc)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jfloatArray jfArray = (jfloatArray)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, id_getLeftControllerLvc);
	jfloat *jfp = Env->GetFloatArrayElements(jfArray, JNI_FALSE);
	outLvc.X = jfp[0];
	outLvc.Y = jfp[1];
	outLvc.Z = jfp[2];
	Env->ReleaseFloatArrayElements(jfArray, jfp, JNI_ABORT);
	Env->DeleteLocalRef(jfArray);
}

void FPicoNeoControllerJni::GetRightControllerLvc(FVector &outLvc)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jfloatArray jfArray = (jfloatArray)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, id_getRightControllerLvc);
	jfloat *jfp = Env->GetFloatArrayElements(jfArray, JNI_FALSE);
	outLvc.X = jfp[0];
	outLvc.Y = jfp[1];
	outLvc.Z = jfp[2];
	Env->ReleaseFloatArrayElements(jfArray, jfp, JNI_ABORT);
	Env->DeleteLocalRef(jfArray);
}

float FPicoNeoControllerJni::GetMainControllerTriggerNum()
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	return ((float)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, id_getMainControllerTriggerNum)) / 255;
}

float FPicoNeoControllerJni::GetSubControllerTriggerNum()
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	return ((float)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, id_getSubControllerTriggerNum)) / 255;
}

void FPicoNeoControllerJni::GetMainControllerTouchPad(FVector2D &outTou)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jintArray jiArray = (jintArray)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, id_getMainControllerTouchPad);
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

void FPicoNeoControllerJni::GetLeftControllerRocker(FVector2D &outRoc)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jintArray jiArray = (jintArray)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, id_getMainControllerTouchPad);
	jint *jip = Env->GetIntArrayElements(jiArray, JNI_FALSE);

	outRoc.Y = (((float)jip[0]) / 255 - 0.5f) * 2;
	outRoc.X = (((float)jip[1]) / 255 - 0.5f) * 2;

	Env->ReleaseIntArrayElements(jiArray, jip, JNI_ABORT);
	Env->DeleteLocalRef(jiArray);
}

void FPicoNeoControllerJni::GetSubControllerTouchPad(FVector2D &outTou)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jintArray jiArray = (jintArray)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, id_getSubControllerTouchPad);
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

void FPicoNeoControllerJni::GetRightControllerRocker(FVector2D &outRoc)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jintArray jiArray = (jintArray)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, id_getSubControllerTouchPad);
	jint *jip = Env->GetIntArrayElements(jiArray, JNI_FALSE);

	outRoc.Y = (((float)jip[0]) / 255 - 0.5f) * 2;
	outRoc.X = (((float)jip[1]) / 255 - 0.5f) * 2;

	Env->ReleaseIntArrayElements(jiArray, jip, JNI_ABORT);
	Env->DeleteLocalRef(jiArray);
}

void FPicoNeoControllerJni::ShakeMainController()
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, id_shakeMainController);
}

void FPicoNeoControllerJni::ShakeSubController()
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, id_shakeSubController);
}

void FPicoNeoControllerJni::ShakeCV2Controller(float strength, int32 time, int32 hand)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, id_shakeCV2Controller,strength,time,hand);
}

int32 FPicoNeoControllerJni::GetMainControllerValue()
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	return (int32)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, id_getMainControllerValue);
}

void FPicoNeoControllerJni::StartControllerThread()
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, id_StartControllerThread);
}

void FPicoNeoControllerJni::GetControllerButtonEvent(int* OutButtonleft, int* OutButtonRight)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jintArray jiArray = (jintArray)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, id_GetControllerEvent);
	jint *jip = Env->GetIntArrayElements(jiArray, JNI_FALSE);
	for (int i = 0; i < 67; i++)
	{
		OutButtonleft[i] = jip[i];
	}
	for (int i = 67; i < 134; i++)
	{
		OutButtonRight[i-67] = jip[i];
	}
	Env->ReleaseIntArrayElements(jiArray, jip, JNI_ABORT);
	Env->DeleteLocalRef(jiArray);
}

bool FPicoNeoControllerJni::GetLifeResumed()
{
	return IsResumed;
}
void FPicoNeoControllerJni::SetLifeResumed(bool isResumed)
{
	IsResumed = isResumed;
}

void FPicoNeoControllerJni::GetControllerTouchEvent(int32 Controller,int* TouchState)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jintArray jiArray = (jintArray)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, id_GetControllerTouchEvent,Controller);
	jint *jip = Env->GetIntArrayElements(jiArray, JNI_FALSE);
	for (int i = 0; i < 15; i++)
	{
		TouchState[i] = jip[i];
	}
	Env->ReleaseIntArrayElements(jiArray, jip, JNI_ABORT);
	Env->DeleteLocalRef(jiArray);
}

float FPicoNeoControllerJni::GetControllerGripValue(int32 Controller)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	int32 GripValue = (int32)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, id_GetControllerGripValue, Controller);
	if(GripValue == 0)
	{
		return 0;
	}
	return(((float)GripValue) / 255 - 0.5f) * 2;
}

int32 FPicoNeoControllerJni::GetControllerRotationMode()
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	return (int32)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, id_GetControllerRotationMode);
}
#endif
