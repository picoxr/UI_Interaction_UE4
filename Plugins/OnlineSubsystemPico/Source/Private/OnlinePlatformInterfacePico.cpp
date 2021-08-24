#include "OnlinePlatformInterfacePico.h"


FString OnlinePlatformInterfacePico::GetAppID()
{
	return "";
}

FString OnlinePlatformInterfacePico::GetOpenID()
{
	FString ret = FString("");
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetOpenID", "()Ljava/lang/String;", false);
		jstring JavaString = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method);
		if (JavaString != NULL)
		{
			const char* JavaChars = Env->GetStringUTFChars(JavaString, 0);
			ret = FString(UTF8_TO_TCHAR(JavaChars));
			Env->ReleaseStringUTFChars(JavaString, JavaChars);
			Env->DeleteLocalRef(JavaString);
		}
	}
#endif
	return ret;
}

void OnlinePlatformInterfacePico::Achievement_Init()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "Payment_Login", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

uint64 OnlinePlatformInterfacePico::Achievement_AddCount(FString AchievementId, uint64 Count)
{	
	uint64 Ret = 0;
#if PLATFORM_ANDROID
	
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring j_AchievementId = Env->NewStringUTF(TCHAR_TO_UTF8(*AchievementId));
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "Achievement_AddCount", "(Ljava/lang/String;J)J", false);
		Ret = (uint64)FJavaWrapper::CallLongMethod(Env, FJavaWrapper::GameActivityThis, Method,j_AchievementId,Count);
		Env->DeleteLocalRef(j_AchievementId);
	}
	
#endif
	return Ret;
}

uint64 OnlinePlatformInterfacePico::Achievement_AddFields(FString AchievementId, FString AchievementFields)
{
	uint64 Ret = 0;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring j_AchievementId = Env->NewStringUTF(TCHAR_TO_UTF8(*AchievementId));
		jstring j_AchievementFields = Env->NewStringUTF(TCHAR_TO_UTF8(*AchievementFields));
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "Achievement_AddFields", "(Ljava/lang/String;Ljava/lang/String;)J", false);
		Ret = (uint64)FJavaWrapper::CallLongMethod(Env, FJavaWrapper::GameActivityThis, Method,j_AchievementId,j_AchievementFields);	
		Env->DeleteLocalRef(j_AchievementId);
		Env->DeleteLocalRef(j_AchievementFields);
	}
	
#endif
	return Ret;
}

uint64 OnlinePlatformInterfacePico::Achievement_GetAllDefinitions(FString AppId)
{
	uint64 Ret = 0;
#if PLATFORM_ANDROID
	
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring j_AppId = Env->NewStringUTF(TCHAR_TO_UTF8(*AppId));
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "Achievement_GetAllDefinitions", "(Ljava/lang/String;)J", false);
		Ret = (uint64)FJavaWrapper::CallLongMethod(Env, FJavaWrapper::GameActivityThis, Method,j_AppId);
		Env->DeleteLocalRef(j_AppId);
	}

#endif
	return Ret;
}

uint64 OnlinePlatformInterfacePico::Achievement_GetAllProgress()
{
	uint64 Ret = 0;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "Achievement_GetAllProgress", "()J", false);
		Ret = (uint64)FJavaWrapper::CallLongMethod(Env, FJavaWrapper::GameActivityThis, Method);	
	}
#endif
	return Ret;
}

uint64 OnlinePlatformInterfacePico::Achievement_Unlock(FString AchievementId)
{
	uint64 Ret = 0;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring j_AchievementId = Env->NewStringUTF(TCHAR_TO_UTF8(*AchievementId));
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "Achievement_Unlock", "(Ljava/lang/String;)J", false);
		Ret = (uint64)FJavaWrapper::CallLongMethod(Env, FJavaWrapper::GameActivityThis, Method,j_AchievementId);
		Env->DeleteLocalRef(j_AchievementId);
	}
	
#endif
	return Ret;
}

uint64 OnlinePlatformInterfacePico::Achievement_GetDefinitionsByName(TArray<FString> AchievementIds)
{
	uint64 Ret = 0;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		//TArray<FString> ->> JObjectArray
		auto AchievementIdArray = NewScopedJavaObject(Env, (jobjectArray)Env->NewObjectArray(AchievementIds.Num(), FJavaWrapper::JavaStringClass, NULL));
		if (AchievementIdArray)
		{
			for (uint32 Param = 0; Param < AchievementIds.Num(); Param++)
			{
				auto StringValue = FJavaHelper::ToJavaString(Env, AchievementIds[Param]);
				Env->SetObjectArrayElement(*AchievementIdArray, Param, *StringValue);
			}
		}
		
		jobjectArray *  j_AchievementIds;
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "Achievement_GetDefinitionsByName", "([Ljava/lang/String;)J", false);
		Ret = (uint64)FJavaWrapper::CallLongMethod(Env, FJavaWrapper::GameActivityThis, Method,*AchievementIdArray);
	}
#endif
	return Ret;
	
}

uint64 OnlinePlatformInterfacePico::Achievements_GetAllProgressByUrl(FString NextUrl)
{	
	uint64 ret = 0;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring j_NextUrl = Env->NewStringUTF(TCHAR_TO_UTF8(*NextUrl));
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "Achievements_GetAllProgressByUrl", "(Ljava/lang/String;)J", false);
		ret = (uint64)FJavaWrapper::CallLongMethod(Env, FJavaWrapper::GameActivityThis, Method,j_NextUrl);
		Env->DeleteLocalRef(j_NextUrl);
	}
#endif
	return ret;
}

uint64 OnlinePlatformInterfacePico::Achievements_GetAllDefinitionsByUrl(FString NextUrl)
{	
	uint64 ret = 0;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring j_NextUrl = Env->NewStringUTF(TCHAR_TO_UTF8(*NextUrl));
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "Achievements_GetAllDefinitionsByUrl", "(Ljava/lang/String;)J", false);
		ret = (uint64)FJavaWrapper::CallLongMethod(Env, FJavaWrapper::GameActivityThis, Method,j_NextUrl);
		Env->DeleteLocalRef(j_NextUrl);
	}
#endif
	return ret;
}

#if PLATFORM_ANDROID
jclass OnlinePlatformInterfacePico::PopMessage()
{
	jclass ret = nullptr;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "Achievement_PopMessage", "()Lcom/picovr/achievement/bean/PvrMessage;", false);
		ret = (jclass)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
	return ret;
}

uint64 OnlinePlatformInterfacePico::GetMessageHandleType(jclass Message)
{
	uint64 ret = 0;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{		
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "Message_GetMessageHandleType", "(Lcom/picovr/achievement/bean/PvrMessage;)J", false);
		ret = (uint64)FJavaWrapper::CallLongMethod(Env, FJavaWrapper::GameActivityThis, Method,Message);
	}
	return ret;
}

bool OnlinePlatformInterfacePico::GetMessageIsError(jclass Message)
{
	bool ret = false;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "Message_GetMessageIsError", "(Lcom/picovr/achievement/bean/PvrMessage;)Z", false);
		ret = (bool)FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, Method,Message);
	}
	return ret;
}

uint64 OnlinePlatformInterfacePico::GetMessageId(jclass Message)
{
	uint64 ret = 0;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{		
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "Message_GetMessageId", "(Lcom/picovr/achievement/bean/PvrMessage;)J", false);
		ret = (uint64)FJavaWrapper::CallLongMethod(Env, FJavaWrapper::GameActivityThis, Method,Message);
	}
	return ret;
}

int32 OnlinePlatformInterfacePico::AchievementDefinitionArray_GetSize(jclass Message)
{
	int32 ret = 0;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{		
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AchievementDefinitionArray_GetSize", "(Lcom/picovr/achievement/bean/PvrMessage;)I", false);
		ret = (int32)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method,Message);
	}
	return ret;
}

jclass OnlinePlatformInterfacePico::AchievementDefinitionArray_GetElement(jclass Message,int32 Index)
{
	jclass ret = nullptr;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{		
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AchievementDefinitionArray_GetElement", "(Lcom/picovr/achievement/bean/PvrMessage;I)Lcom/picovr/achievement/bean/PvrMessage;", false);
		ret = (jclass)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method,Message,Index);
	}
	return ret;
}

FString OnlinePlatformInterfacePico::AchievementDefinitionArray_GetNextUrl(jclass Message)
{
	FString ret = FString("");
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AchievementDefinitionArray_GetNextUrl", "(Lcom/picovr/achievement/bean/PvrMessage;)Ljava/lang/String;", false);
		jstring JavaString = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method,Message);
		if (JavaString != NULL)
		{
			const char* JavaChars = Env->GetStringUTFChars(JavaString, 0);
			ret = FString(UTF8_TO_TCHAR(JavaChars));
			Env->ReleaseStringUTFChars(JavaString, JavaChars);
			Env->DeleteLocalRef(JavaString);
		}
	}
	return ret;
}

bool OnlinePlatformInterfacePico::AchievementDefinitionArray_HasNextPage(jclass Message)
{
	bool ret = false;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AchievementDefinitionArray_HasNextPage", "(Lcom/picovr/achievement/bean/PvrMessage;)Z", false);
		ret = (bool)FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, Method,Message);
	}
	return ret;
}

FString OnlinePlatformInterfacePico::AchievementDefinition_GetName(jclass Message)
{
	FString ret = FString("");
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AchievementDefinition_GetName", "(Lcom/picovr/achievement/bean/PvrMessage;)Ljava/lang/String;", false);
		jstring JavaString = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method,Message);
		if (JavaString != NULL)
		{
			const char* JavaChars = Env->GetStringUTFChars(JavaString, 0);
			ret = FString(UTF8_TO_TCHAR(JavaChars));
			Env->ReleaseStringUTFChars(JavaString, JavaChars);
			Env->DeleteLocalRef(JavaString);
		}
	}
	return ret;
}

int32 OnlinePlatformInterfacePico::AchievementDefinition_GetBitfieldLength(jclass Message)
{
	int32 ret = 0;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{		
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AchievementDefinition_GetBitfieldLength", "(Lcom/picovr/achievement/bean/PvrMessage;)I", false);
		ret = (int32)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method,Message);
	}
	return ret;
}

uint64 OnlinePlatformInterfacePico::AchievementDefinition_GetTarget(jclass Message)
{
	uint64 ret = 0;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{		
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AchievementDefinition_GetTarget", "(Lcom/picovr/achievement/bean/PvrMessage;)J", false);
		ret = (uint64)FJavaWrapper::CallLongMethod(Env, FJavaWrapper::GameActivityThis, Method,Message);
	}
	return ret;
}

int32 OnlinePlatformInterfacePico::AchievementDefinition_GetType(jclass Message)
{
	int32 ret = 0;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{		
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AchievementDefinition_GetType", "(Lcom/picovr/achievement/bean/PvrMessage;)I", false);
		ret = (int32)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method,Message);
	}
	return ret;
}

FString OnlinePlatformInterfacePico::AchievementDefinition_GetTitle(jclass Message)
{
	FString ret = FString("");
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AchievementDefinition_GetTitle", "(Lcom/picovr/achievement/bean/PvrMessage;)Ljava/lang/String;", false);
		jstring JavaString = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method,Message);
		if (JavaString != NULL)
		{
			const char* JavaChars = Env->GetStringUTFChars(JavaString, 0);
			ret = FString(UTF8_TO_TCHAR(JavaChars));
			Env->ReleaseStringUTFChars(JavaString, JavaChars);
			Env->DeleteLocalRef(JavaString);
		}
	}
	return ret;
}

FString OnlinePlatformInterfacePico::AchievementDefinition_GetDescription(jclass Message)
{
	FString ret = FString("");
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AchievementDefinition_GetDescription", "(Lcom/picovr/achievement/bean/PvrMessage;)Ljava/lang/String;", false);
		jstring JavaString = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method,Message);
		if (JavaString != NULL)
		{
			const char* JavaChars = Env->GetStringUTFChars(JavaString, 0);
			ret = FString(UTF8_TO_TCHAR(JavaChars));
			Env->ReleaseStringUTFChars(JavaString, JavaChars);
			Env->DeleteLocalRef(JavaString);
		}
	}
	return ret;
}
	
bool OnlinePlatformInterfacePico::AchievementDefinition_GetIsSecret(jclass Message)
{
	bool ret = false;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AchievementDefinition_GetIsSecret", "(Lcom/picovr/achievement/bean/PvrMessage;)Z", false);
		ret = (bool)FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, Method,Message);
	}
	return ret;
}

FString OnlinePlatformInterfacePico::AchievementDefinition_GetUnlockedDescription(jclass Message)
{
	FString ret = FString("");
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AchievementDefinition_GetUnlockedDescription", "(Lcom/picovr/achievement/bean/PvrMessage;)Ljava/lang/String;", false);
		jstring JavaString = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method,Message);
		if (JavaString != NULL)
		{
			const char* JavaChars = Env->GetStringUTFChars(JavaString, 0);
			ret = FString(UTF8_TO_TCHAR(JavaChars));
			Env->ReleaseStringUTFChars(JavaString, JavaChars);
			Env->DeleteLocalRef(JavaString);
		}
	}
	return ret;
}

FString OnlinePlatformInterfacePico::AchievementDefinition_GetUnlockedImage(jclass Message)
{
	FString ret = FString("");
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AchievementDefinition_GetUnlockedImage", "(Lcom/picovr/achievement/bean/PvrMessage;)Ljava/lang/String;", false);
		jstring JavaString = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method,Message);
		if (JavaString != NULL)
		{
			const char* JavaChars = Env->GetStringUTFChars(JavaString, 0);
			ret = FString(UTF8_TO_TCHAR(JavaChars));
			Env->ReleaseStringUTFChars(JavaString, JavaChars);
			Env->DeleteLocalRef(JavaString);
		}
	}
	return ret;
}

FString OnlinePlatformInterfacePico::AchievementDefinition_GetLockedImage(jclass Message)
{
	FString ret = FString("");
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AchievementDefinition_GetLockedImage", "(Lcom/picovr/achievement/bean/PvrMessage;)Ljava/lang/String;", false);
		jstring JavaString = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method,Message);
		if (JavaString != NULL)
		{
			const char* JavaChars = Env->GetStringUTFChars(JavaString, 0);
			ret = FString(UTF8_TO_TCHAR(JavaChars));
			Env->ReleaseStringUTFChars(JavaString, JavaChars);
			Env->DeleteLocalRef(JavaString);
		}
	}
	return ret;
}

int32 OnlinePlatformInterfacePico::AchievementProgressArray_GetSize(jclass Message)
{
	int32 ret = 0;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{		
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AchievementProgressArray_GetSize", "(Lcom/picovr/achievement/bean/PvrMessage;)I", false);
		ret = (int32)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method,Message);
	}
	return ret;
}

jclass OnlinePlatformInterfacePico::AchievementProgressArray_GetElement(jclass Message,int32 Index)
{
	jclass ret = nullptr;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{		
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AchievementProgressArray_GetElement", "(Lcom/picovr/achievement/bean/PvrMessage;I)Lcom/picovr/achievement/bean/PvrMessage;", false);
		ret = (jclass)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method,Message,Index);
	}
	return ret;
}

FString OnlinePlatformInterfacePico::AchievementProgressArray_GetNextUrl(jclass Message)
{
	FString ret = FString("");
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AchievementProgressArray_GetNextUrl", "(Lcom/picovr/achievement/bean/PvrMessage;)Ljava/lang/String;", false);
		jstring JavaString = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method,Message);
		if (JavaString != NULL)
		{
			const char* JavaChars = Env->GetStringUTFChars(JavaString, 0);
			ret = FString(UTF8_TO_TCHAR(JavaChars));
			Env->ReleaseStringUTFChars(JavaString, JavaChars);
			Env->DeleteLocalRef(JavaString);
		}
	}
	return ret;
}

bool OnlinePlatformInterfacePico::AchievementProgressArray_HasNextPage(jclass Message)
{
	bool ret = false;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AchievementProgressArray_HasNextPage", "(Lcom/picovr/achievement/bean/PvrMessage;)Z", false);
		ret = (bool)FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, Method,Message);
	}
	return ret;
}

FString OnlinePlatformInterfacePico::AchievementProgress_GetBitfield(jclass Message)
{
	FString ret = FString("");
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AchievementProgress_GetBitfield", "(Lcom/picovr/achievement/bean/PvrMessage;)Ljava/lang/String;", false);
		jstring JavaString = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method,Message);
		if (JavaString != NULL)
		{
			const char* JavaChars = Env->GetStringUTFChars(JavaString, 0);
			ret = FString(UTF8_TO_TCHAR(JavaChars));
			Env->ReleaseStringUTFChars(JavaString, JavaChars);
			Env->DeleteLocalRef(JavaString);
		}
	}
	return ret;
}
	
uint64 OnlinePlatformInterfacePico::AchievementProgress_GetCount(jclass Message)
{
	uint64 ret = 0;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{		
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AchievementProgress_GetCount", "(Lcom/picovr/achievement/bean/PvrMessage;)J", false);
		ret = (uint64)FJavaWrapper::CallLongMethod(Env, FJavaWrapper::GameActivityThis, Method,Message);
	}
	return ret;
}

bool OnlinePlatformInterfacePico::AchievementProgress_GetIsUnlocked(jclass Message)
{
	bool ret = false;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AchievementProgress_GetIsUnlocked", "(Lcom/picovr/achievement/bean/PvrMessage;)Z", false);
		ret = (bool)FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, Method,Message);
	}
	return ret;
}

FString OnlinePlatformInterfacePico::AchievementProgress_GetName(jclass Message)
{
	FString ret = FString("");
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AchievementProgress_GetName", "(Lcom/picovr/achievement/bean/PvrMessage;)Ljava/lang/String;", false);
		jstring JavaString = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method,Message);
		if (JavaString != NULL)
		{
			const char* JavaChars = Env->GetStringUTFChars(JavaString, 0);
			ret = FString(UTF8_TO_TCHAR(JavaChars));
			Env->ReleaseStringUTFChars(JavaString, JavaChars);
			Env->DeleteLocalRef(JavaString);
		}
	}
	return ret;
}

bool OnlinePlatformInterfacePico::AchievementUpdate_GetJustUnlocked(jclass Message)
{
	bool ret = false;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AchievementUpdate_GetJustUnlocked", "(Lcom/picovr/achievement/bean/PvrMessage;)Z", false);
		ret = (bool)FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, Method,Message);
	}
	return ret;
}

uint64 OnlinePlatformInterfacePico::AchievementProgress_GetUnlockTime(jclass Message)
{
	uint64 ret = 0;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{		
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AchievementProgress_GetUnlockTime", "(Lcom/picovr/achievement/bean/PvrMessage;)J", false);
		ret = (uint64)FJavaWrapper::CallLongMethod(Env, FJavaWrapper::GameActivityThis, Method,Message);
	}
	return ret;
}

FString OnlinePlatformInterfacePico::AchievementUpdate_GetName(jclass Message)
{
	FString ret = FString("");
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AchievementUpdate_GetName", "(Lcom/picovr/achievement/bean/PvrMessage;)Ljava/lang/String;", false);
		jstring JavaString = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method,Message);
		if (JavaString != NULL)
		{
			const char* JavaChars = Env->GetStringUTFChars(JavaString, 0);
			ret = FString(UTF8_TO_TCHAR(JavaChars));
			Env->ReleaseStringUTFChars(JavaString, JavaChars);
			Env->DeleteLocalRef(JavaString);
		}
	}
	return ret;
}
#endif
