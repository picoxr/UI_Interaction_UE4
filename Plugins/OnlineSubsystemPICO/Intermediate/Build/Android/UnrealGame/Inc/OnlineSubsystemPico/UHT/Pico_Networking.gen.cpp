// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../OnlineSubsystemPico/Public/Pico_Networking.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePico_Networking() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UOnlinePicoNetworkingFunction();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UOnlinePicoNetworkingFunction_NoRegister();
	UPackage* Z_Construct_UPackage__Script_OnlineSubsystemPico();
// End Cross Module References
	DEFINE_FUNCTION(UOnlinePicoNetworkingFunction::execReadPacket)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_TARRAY_REF(uint8,Z_Param_Out_OutBinaries);
		P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_SendUserID);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UOnlinePicoNetworkingFunction::ReadPacket(Z_Param_WorldContextObject,Z_Param_Out_OutBinaries,Z_Param_Out_SendUserID);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoNetworkingFunction::execSendPacketToCurrentRoom)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_TARRAY(uint8,Z_Param_BinaryArray);
		P_GET_UBOOL(Z_Param_bReliable);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UOnlinePicoNetworkingFunction::SendPacketToCurrentRoom(Z_Param_WorldContextObject,Z_Param_BinaryArray,Z_Param_bReliable);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoNetworkingFunction::execSendPacket)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_UserId);
		P_GET_TARRAY(uint8,Z_Param_BinaryArray);
		P_GET_UBOOL(Z_Param_bReliable);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UOnlinePicoNetworkingFunction::SendPacket(Z_Param_WorldContextObject,Z_Param_UserId,Z_Param_BinaryArray,Z_Param_bReliable);
		P_NATIVE_END;
	}
	void UOnlinePicoNetworkingFunction::StaticRegisterNativesUOnlinePicoNetworkingFunction()
	{
		UClass* Class = UOnlinePicoNetworkingFunction::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ReadPacket", &UOnlinePicoNetworkingFunction::execReadPacket },
			{ "SendPacket", &UOnlinePicoNetworkingFunction::execSendPacket },
			{ "SendPacketToCurrentRoom", &UOnlinePicoNetworkingFunction::execSendPacketToCurrentRoom },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UOnlinePicoNetworkingFunction_ReadPacket_Statics
	{
		struct OnlinePicoNetworkingFunction_eventReadPacket_Parms
		{
			UObject* WorldContextObject;
			TArray<uint8> OutBinaries;
			FString SendUserID;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FBytePropertyParams NewProp_OutBinaries_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_OutBinaries;
		static const UECodeGen_Private::FStrPropertyParams NewProp_SendUserID;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoNetworkingFunction_ReadPacket_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoNetworkingFunction_eventReadPacket_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOnlinePicoNetworkingFunction_ReadPacket_Statics::NewProp_OutBinaries_Inner = { "OutBinaries", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UOnlinePicoNetworkingFunction_ReadPacket_Statics::NewProp_OutBinaries = { "OutBinaries", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoNetworkingFunction_eventReadPacket_Parms, OutBinaries), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoNetworkingFunction_ReadPacket_Statics::NewProp_SendUserID = { "SendUserID", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoNetworkingFunction_eventReadPacket_Parms, SendUserID), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UOnlinePicoNetworkingFunction_ReadPacket_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OnlinePicoNetworkingFunction_eventReadPacket_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOnlinePicoNetworkingFunction_ReadPacket_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OnlinePicoNetworkingFunction_eventReadPacket_Parms), &Z_Construct_UFunction_UOnlinePicoNetworkingFunction_ReadPacket_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoNetworkingFunction_ReadPacket_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoNetworkingFunction_ReadPacket_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoNetworkingFunction_ReadPacket_Statics::NewProp_OutBinaries_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoNetworkingFunction_ReadPacket_Statics::NewProp_OutBinaries,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoNetworkingFunction_ReadPacket_Statics::NewProp_SendUserID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoNetworkingFunction_ReadPacket_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoNetworkingFunction_ReadPacket_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|Networking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Reads the messages from other users in the room.\n/// </summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name =\"OutBinaries\">Returns an array of byte.</param>   \n/// <param name =\"OutSendId\">Returns user id which player send.</param>   \n/// <returns>\n/// * `true`: success\n/// * `false`: failure\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Networking.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nReads the messages from other users in the room.\n</summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name =\"OutBinaries\">Returns an array of byte.</param>\n<param name =\"OutSendId\">Returns user id which player send.</param>\n<returns>\n* `true`: success\n* `false`: failure\n</returns>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoNetworkingFunction_ReadPacket_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoNetworkingFunction, nullptr, "ReadPacket", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoNetworkingFunction_ReadPacket_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoNetworkingFunction_ReadPacket_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoNetworkingFunction_ReadPacket_Statics::OnlinePicoNetworkingFunction_eventReadPacket_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoNetworkingFunction_ReadPacket_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoNetworkingFunction_ReadPacket_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoNetworkingFunction_ReadPacket_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoNetworkingFunction_ReadPacket_Statics::OnlinePicoNetworkingFunction_eventReadPacket_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoNetworkingFunction_ReadPacket()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoNetworkingFunction_ReadPacket_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacket_Statics
	{
		struct OnlinePicoNetworkingFunction_eventSendPacket_Parms
		{
			UObject* WorldContextObject;
			FString UserId;
			TArray<uint8> BinaryArray;
			bool bReliable;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_UserId_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_UserId;
		static const UECodeGen_Private::FBytePropertyParams NewProp_BinaryArray_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_BinaryArray;
		static void NewProp_bReliable_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bReliable;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacket_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoNetworkingFunction_eventSendPacket_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacket_Statics::NewProp_UserId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacket_Statics::NewProp_UserId = { "UserId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoNetworkingFunction_eventSendPacket_Parms, UserId), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacket_Statics::NewProp_UserId_MetaData), Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacket_Statics::NewProp_UserId_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacket_Statics::NewProp_BinaryArray_Inner = { "BinaryArray", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacket_Statics::NewProp_BinaryArray = { "BinaryArray", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoNetworkingFunction_eventSendPacket_Parms, BinaryArray), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacket_Statics::NewProp_bReliable_SetBit(void* Obj)
	{
		((OnlinePicoNetworkingFunction_eventSendPacket_Parms*)Obj)->bReliable = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacket_Statics::NewProp_bReliable = { "bReliable", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OnlinePicoNetworkingFunction_eventSendPacket_Parms), &Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacket_Statics::NewProp_bReliable_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacket_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OnlinePicoNetworkingFunction_eventSendPacket_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacket_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OnlinePicoNetworkingFunction_eventSendPacket_Parms), &Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacket_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacket_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacket_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacket_Statics::NewProp_UserId,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacket_Statics::NewProp_BinaryArray_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacket_Statics::NewProp_BinaryArray,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacket_Statics::NewProp_bReliable,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacket_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacket_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|Networking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Sends messages to a specified user. The maximum messaging frequency is 1000/s.\n/// </summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"UserId\">The ID of the user to send messages to.</param>\n/// <param name=\"BinaryArray\">The message length (in bytes). The maximum bytes allowed is 512.</param>\n/// <param name=\"bReliable\">When `reliable` is set to `true`, messages between lost and resume will not be lost.\n/// The retention time is determined by the `reserve_period` parameter configured for the matchmaking pool, with a maximum of 1 minute.\n/// When `reliable` is set to `false`, this function works the same as the other `SendPacket` function.</param>\n/// <returns>\n/// * `true`: success\n/// * `false`: failure\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Networking.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nSends messages to a specified user. The maximum messaging frequency is 1000/s.\n</summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"UserId\">The ID of the user to send messages to.</param>\n<param name=\"BinaryArray\">The message length (in bytes). The maximum bytes allowed is 512.</param>\n<param name=\"bReliable\">When `reliable` is set to `true`, messages between lost and resume will not be lost.\nThe retention time is determined by the `reserve_period` parameter configured for the matchmaking pool, with a maximum of 1 minute.\nWhen `reliable` is set to `false`, this function works the same as the other `SendPacket` function.</param>\n<returns>\n* `true`: success\n* `false`: failure\n</returns>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacket_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoNetworkingFunction, nullptr, "SendPacket", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacket_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacket_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacket_Statics::OnlinePicoNetworkingFunction_eventSendPacket_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacket_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacket_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacket_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacket_Statics::OnlinePicoNetworkingFunction_eventSendPacket_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacket()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacket_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacketToCurrentRoom_Statics
	{
		struct OnlinePicoNetworkingFunction_eventSendPacketToCurrentRoom_Parms
		{
			UObject* WorldContextObject;
			TArray<uint8> BinaryArray;
			bool bReliable;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FBytePropertyParams NewProp_BinaryArray_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_BinaryArray;
		static void NewProp_bReliable_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bReliable;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacketToCurrentRoom_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoNetworkingFunction_eventSendPacketToCurrentRoom_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacketToCurrentRoom_Statics::NewProp_BinaryArray_Inner = { "BinaryArray", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacketToCurrentRoom_Statics::NewProp_BinaryArray = { "BinaryArray", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoNetworkingFunction_eventSendPacketToCurrentRoom_Parms, BinaryArray), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacketToCurrentRoom_Statics::NewProp_bReliable_SetBit(void* Obj)
	{
		((OnlinePicoNetworkingFunction_eventSendPacketToCurrentRoom_Parms*)Obj)->bReliable = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacketToCurrentRoom_Statics::NewProp_bReliable = { "bReliable", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OnlinePicoNetworkingFunction_eventSendPacketToCurrentRoom_Parms), &Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacketToCurrentRoom_Statics::NewProp_bReliable_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacketToCurrentRoom_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OnlinePicoNetworkingFunction_eventSendPacketToCurrentRoom_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacketToCurrentRoom_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OnlinePicoNetworkingFunction_eventSendPacketToCurrentRoom_Parms), &Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacketToCurrentRoom_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacketToCurrentRoom_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacketToCurrentRoom_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacketToCurrentRoom_Statics::NewProp_BinaryArray_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacketToCurrentRoom_Statics::NewProp_BinaryArray,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacketToCurrentRoom_Statics::NewProp_bReliable,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacketToCurrentRoom_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacketToCurrentRoom_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|Networking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Sends messages to other users in the room. The maximum messaging frequency is 1000/s.\n/// </summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"BinaryArray\">The message length (in bytes). The maximum bytes allowed is 512.</param>\n/// <param name=\"bReliable\">When `reliable` is set to `true`, messages between lost and resume will not be lost.\n/// The retention time is determined by the `reserve_period` parameter configured for the matchmaking pool, with a maximum of 1 minute.\n/// When `reliable` is set to `false`, this function works the same as the other `SendPacketToCurrentRoom` function.</param>\n/// <returns>\n/// * `true`: success\n/// * `false`: failure\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Networking.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nSends messages to other users in the room. The maximum messaging frequency is 1000/s.\n</summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"BinaryArray\">The message length (in bytes). The maximum bytes allowed is 512.</param>\n<param name=\"bReliable\">When `reliable` is set to `true`, messages between lost and resume will not be lost.\nThe retention time is determined by the `reserve_period` parameter configured for the matchmaking pool, with a maximum of 1 minute.\nWhen `reliable` is set to `false`, this function works the same as the other `SendPacketToCurrentRoom` function.</param>\n<returns>\n* `true`: success\n* `false`: failure\n</returns>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacketToCurrentRoom_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoNetworkingFunction, nullptr, "SendPacketToCurrentRoom", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacketToCurrentRoom_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacketToCurrentRoom_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacketToCurrentRoom_Statics::OnlinePicoNetworkingFunction_eventSendPacketToCurrentRoom_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacketToCurrentRoom_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacketToCurrentRoom_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacketToCurrentRoom_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacketToCurrentRoom_Statics::OnlinePicoNetworkingFunction_eventSendPacketToCurrentRoom_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacketToCurrentRoom()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacketToCurrentRoom_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOnlinePicoNetworkingFunction);
	UClass* Z_Construct_UClass_UOnlinePicoNetworkingFunction_NoRegister()
	{
		return UOnlinePicoNetworkingFunction::StaticClass();
	}
	struct Z_Construct_UClass_UOnlinePicoNetworkingFunction_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UOnlinePicoNetworkingFunction_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoNetworkingFunction_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UOnlinePicoNetworkingFunction_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UOnlinePicoNetworkingFunction_ReadPacket, "ReadPacket" }, // 645294799
		{ &Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacket, "SendPacket" }, // 807067898
		{ &Z_Construct_UFunction_UOnlinePicoNetworkingFunction_SendPacketToCurrentRoom, "SendPacketToCurrentRoom" }, // 2626880875
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoNetworkingFunction_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOnlinePicoNetworkingFunction_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @defgroup BP_Networking BP_Networking \n  *  This is the BP_Networking group\n  *  @{\n  *//// @brief OnlinePicoNetworking Blueprint Function class.\n" },
#endif
		{ "IncludePath", "Pico_Networking.h" },
		{ "ModuleRelativePath", "Public/Pico_Networking.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@defgroup BP_Networking BP_Networking\nThis is the BP_Networking group\n@{\n /// @brief OnlinePicoNetworking Blueprint Function class." },
#endif
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UOnlinePicoNetworkingFunction_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOnlinePicoNetworkingFunction>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UOnlinePicoNetworkingFunction_Statics::ClassParams = {
		&UOnlinePicoNetworkingFunction::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoNetworkingFunction_Statics::Class_MetaDataParams), Z_Construct_UClass_UOnlinePicoNetworkingFunction_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UOnlinePicoNetworkingFunction()
	{
		if (!Z_Registration_Info_UClass_UOnlinePicoNetworkingFunction.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOnlinePicoNetworkingFunction.OuterSingleton, Z_Construct_UClass_UOnlinePicoNetworkingFunction_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UOnlinePicoNetworkingFunction.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UOnlinePicoNetworkingFunction>()
	{
		return UOnlinePicoNetworkingFunction::StaticClass();
	}
	UOnlinePicoNetworkingFunction::UOnlinePicoNetworkingFunction(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOnlinePicoNetworkingFunction);
	UOnlinePicoNetworkingFunction::~UOnlinePicoNetworkingFunction() {}
	struct Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Networking_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Networking_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UOnlinePicoNetworkingFunction, UOnlinePicoNetworkingFunction::StaticClass, TEXT("UOnlinePicoNetworkingFunction"), &Z_Registration_Info_UClass_UOnlinePicoNetworkingFunction, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOnlinePicoNetworkingFunction), 3193988387U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Networking_h_2040000089(TEXT("/Script/OnlineSubsystemPico"),
		Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Networking_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Networking_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
