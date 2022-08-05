// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PicoXRInput/Public/PXR_InputFunctionLibrary.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePXR_InputFunctionLibrary() {}
// Cross Module References
	PICOXRINPUT_API UEnum* Z_Construct_UEnum_PicoXRInput_EPxrControllerKeyMap();
	UPackage* Z_Construct_UPackage__Script_PicoXRInput();
	PICOXRINPUT_API UEnum* Z_Construct_UEnum_PicoXRInput_EPicoXRControllerDeviceType();
	PICOXRINPUT_API UEnum* Z_Construct_UEnum_PicoXRInput_EPicoXRGazeBehavior();
	PICOXRINPUT_API UEnum* Z_Construct_UEnum_PicoXRInput_EPicoXRArmModelJoint();
	PICOXRINPUT_API UEnum* Z_Construct_UEnum_PicoXRInput_EPicoXRControllerType();
	PICOXRINPUT_API UEnum* Z_Construct_UEnum_PicoXRInput_EPicoXRHandedness();
	PICOXRINPUT_API UClass* Z_Construct_UClass_UPicoXRInputFunctionLibrary_NoRegister();
	PICOXRINPUT_API UClass* Z_Construct_UClass_UPicoXRInputFunctionLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	INPUTCORE_API UEnum* Z_Construct_UEnum_InputCore_EControllerHand();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
// End Cross Module References
	static UEnum* EPxrControllerKeyMap_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_PicoXRInput_EPxrControllerKeyMap, Z_Construct_UPackage__Script_PicoXRInput(), TEXT("EPxrControllerKeyMap"));
		}
		return Singleton;
	}
	template<> PICOXRINPUT_API UEnum* StaticEnum<EPxrControllerKeyMap>()
	{
		return EPxrControllerKeyMap_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EPxrControllerKeyMap(EPxrControllerKeyMap_StaticEnum, TEXT("/Script/PicoXRInput"), TEXT("EPxrControllerKeyMap"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_PicoXRInput_EPxrControllerKeyMap_Hash() { return 2604842985U; }
	UEnum* Z_Construct_UEnum_PicoXRInput_EPxrControllerKeyMap()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_PicoXRInput();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EPxrControllerKeyMap"), 0, Get_Z_Construct_UEnum_PicoXRInput_EPxrControllerKeyMap_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EPxrControllerKeyMap::PXR_CONTROLLER_KEY_HOME", (int64)EPxrControllerKeyMap::PXR_CONTROLLER_KEY_HOME },
				{ "EPxrControllerKeyMap::PXR_CONTROLLER_KEY_AX", (int64)EPxrControllerKeyMap::PXR_CONTROLLER_KEY_AX },
				{ "EPxrControllerKeyMap::PXR_CONTROLLER_KEY_BY", (int64)EPxrControllerKeyMap::PXR_CONTROLLER_KEY_BY },
				{ "EPxrControllerKeyMap::PXR_CONTROLLER_KEY_BACK", (int64)EPxrControllerKeyMap::PXR_CONTROLLER_KEY_BACK },
				{ "EPxrControllerKeyMap::PXR_CONTROLLER_KEY_TRIGGER", (int64)EPxrControllerKeyMap::PXR_CONTROLLER_KEY_TRIGGER },
				{ "EPxrControllerKeyMap::PXR_CONTROLLER_KEY_VOL_UP", (int64)EPxrControllerKeyMap::PXR_CONTROLLER_KEY_VOL_UP },
				{ "EPxrControllerKeyMap::PXR_CONTROLLER_KEY_VOL_DOWN", (int64)EPxrControllerKeyMap::PXR_CONTROLLER_KEY_VOL_DOWN },
				{ "EPxrControllerKeyMap::PXR_CONTROLLER_KEY_ROCKER", (int64)EPxrControllerKeyMap::PXR_CONTROLLER_KEY_ROCKER },
				{ "EPxrControllerKeyMap::PXR_CONTROLLER_KEY_GRIP", (int64)EPxrControllerKeyMap::PXR_CONTROLLER_KEY_GRIP },
				{ "EPxrControllerKeyMap::PXR_CONTROLLER_KEY_TOUCHPAD", (int64)EPxrControllerKeyMap::PXR_CONTROLLER_KEY_TOUCHPAD },
				{ "EPxrControllerKeyMap::PXR_CONTROLLER_KEY_LASTONE", (int64)EPxrControllerKeyMap::PXR_CONTROLLER_KEY_LASTONE },
				{ "EPxrControllerKeyMap::PXR_CONTROLLER_TOUCH_AX", (int64)EPxrControllerKeyMap::PXR_CONTROLLER_TOUCH_AX },
				{ "EPxrControllerKeyMap::PXR_CONTROLLER_TOUCH_BY", (int64)EPxrControllerKeyMap::PXR_CONTROLLER_TOUCH_BY },
				{ "EPxrControllerKeyMap::PXR_CONTROLLER_TOUCH_ROCKER", (int64)EPxrControllerKeyMap::PXR_CONTROLLER_TOUCH_ROCKER },
				{ "EPxrControllerKeyMap::PXR_CONTROLLER_TOUCH_TRIGGER", (int64)EPxrControllerKeyMap::PXR_CONTROLLER_TOUCH_TRIGGER },
				{ "EPxrControllerKeyMap::PXR_CONTROLLER_TOUCH_THUMB", (int64)EPxrControllerKeyMap::PXR_CONTROLLER_TOUCH_THUMB },
				{ "EPxrControllerKeyMap::PXR_CONTROLLER_TOUCH_LASTONE", (int64)EPxrControllerKeyMap::PXR_CONTROLLER_TOUCH_LASTONE },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
				{ "PXR_CONTROLLER_KEY_AX.Name", "EPxrControllerKeyMap::PXR_CONTROLLER_KEY_AX" },
				{ "PXR_CONTROLLER_KEY_BACK.Name", "EPxrControllerKeyMap::PXR_CONTROLLER_KEY_BACK" },
				{ "PXR_CONTROLLER_KEY_BY.Name", "EPxrControllerKeyMap::PXR_CONTROLLER_KEY_BY" },
				{ "PXR_CONTROLLER_KEY_GRIP.Name", "EPxrControllerKeyMap::PXR_CONTROLLER_KEY_GRIP" },
				{ "PXR_CONTROLLER_KEY_HOME.Name", "EPxrControllerKeyMap::PXR_CONTROLLER_KEY_HOME" },
				{ "PXR_CONTROLLER_KEY_LASTONE.Name", "EPxrControllerKeyMap::PXR_CONTROLLER_KEY_LASTONE" },
				{ "PXR_CONTROLLER_KEY_ROCKER.Name", "EPxrControllerKeyMap::PXR_CONTROLLER_KEY_ROCKER" },
				{ "PXR_CONTROLLER_KEY_TOUCHPAD.Name", "EPxrControllerKeyMap::PXR_CONTROLLER_KEY_TOUCHPAD" },
				{ "PXR_CONTROLLER_KEY_TRIGGER.Name", "EPxrControllerKeyMap::PXR_CONTROLLER_KEY_TRIGGER" },
				{ "PXR_CONTROLLER_KEY_VOL_DOWN.Name", "EPxrControllerKeyMap::PXR_CONTROLLER_KEY_VOL_DOWN" },
				{ "PXR_CONTROLLER_KEY_VOL_UP.Name", "EPxrControllerKeyMap::PXR_CONTROLLER_KEY_VOL_UP" },
				{ "PXR_CONTROLLER_TOUCH_AX.Name", "EPxrControllerKeyMap::PXR_CONTROLLER_TOUCH_AX" },
				{ "PXR_CONTROLLER_TOUCH_BY.Name", "EPxrControllerKeyMap::PXR_CONTROLLER_TOUCH_BY" },
				{ "PXR_CONTROLLER_TOUCH_LASTONE.Name", "EPxrControllerKeyMap::PXR_CONTROLLER_TOUCH_LASTONE" },
				{ "PXR_CONTROLLER_TOUCH_ROCKER.Name", "EPxrControllerKeyMap::PXR_CONTROLLER_TOUCH_ROCKER" },
				{ "PXR_CONTROLLER_TOUCH_THUMB.Name", "EPxrControllerKeyMap::PXR_CONTROLLER_TOUCH_THUMB" },
				{ "PXR_CONTROLLER_TOUCH_TRIGGER.Name", "EPxrControllerKeyMap::PXR_CONTROLLER_TOUCH_TRIGGER" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_PicoXRInput,
				nullptr,
				"EPxrControllerKeyMap",
				"EPxrControllerKeyMap",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* EPicoXRControllerDeviceType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_PicoXRInput_EPicoXRControllerDeviceType, Z_Construct_UPackage__Script_PicoXRInput(), TEXT("EPicoXRControllerDeviceType"));
		}
		return Singleton;
	}
	template<> PICOXRINPUT_API UEnum* StaticEnum<EPicoXRControllerDeviceType>()
	{
		return EPicoXRControllerDeviceType_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EPicoXRControllerDeviceType(EPicoXRControllerDeviceType_StaticEnum, TEXT("/Script/PicoXRInput"), TEXT("EPicoXRControllerDeviceType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_PicoXRInput_EPicoXRControllerDeviceType_Hash() { return 1573657309U; }
	UEnum* Z_Construct_UEnum_PicoXRInput_EPicoXRControllerDeviceType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_PicoXRInput();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EPicoXRControllerDeviceType"), 0, Get_Z_Construct_UEnum_PicoXRInput_EPicoXRControllerDeviceType_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EPicoXRControllerDeviceType::UnKnown", (int64)EPicoXRControllerDeviceType::UnKnown },
				{ "EPicoXRControllerDeviceType::G2", (int64)EPicoXRControllerDeviceType::G2 },
				{ "EPicoXRControllerDeviceType::Neo2", (int64)EPicoXRControllerDeviceType::Neo2 },
				{ "EPicoXRControllerDeviceType::Neo3", (int64)EPicoXRControllerDeviceType::Neo3 },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "G2.DisplayName", "Pico G2" },
				{ "G2.Name", "EPicoXRControllerDeviceType::G2" },
				{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
				{ "Neo2.DisplayName", "Pico Neo2" },
				{ "Neo2.Name", "EPicoXRControllerDeviceType::Neo2" },
				{ "Neo3.DisplayName", "Pico Neo3" },
				{ "Neo3.Name", "EPicoXRControllerDeviceType::Neo3" },
				{ "UnKnown.DisplayName", "UnKnown Controller" },
				{ "UnKnown.Name", "EPicoXRControllerDeviceType::UnKnown" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_PicoXRInput,
				nullptr,
				"EPicoXRControllerDeviceType",
				"EPicoXRControllerDeviceType",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* EPicoXRGazeBehavior_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_PicoXRInput_EPicoXRGazeBehavior, Z_Construct_UPackage__Script_PicoXRInput(), TEXT("EPicoXRGazeBehavior"));
		}
		return Singleton;
	}
	template<> PICOXRINPUT_API UEnum* StaticEnum<EPicoXRGazeBehavior>()
	{
		return EPicoXRGazeBehavior_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EPicoXRGazeBehavior(EPicoXRGazeBehavior_StaticEnum, TEXT("/Script/PicoXRInput"), TEXT("EPicoXRGazeBehavior"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_PicoXRInput_EPicoXRGazeBehavior_Hash() { return 3594333153U; }
	UEnum* Z_Construct_UEnum_PicoXRInput_EPicoXRGazeBehavior()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_PicoXRInput();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EPicoXRGazeBehavior"), 0, Get_Z_Construct_UEnum_PicoXRInput_EPicoXRGazeBehavior_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EPicoXRGazeBehavior::Never", (int64)EPicoXRGazeBehavior::Never },
				{ "EPicoXRGazeBehavior::DuringMotion", (int64)EPicoXRGazeBehavior::DuringMotion },
				{ "EPicoXRGazeBehavior::Always", (int64)EPicoXRGazeBehavior::Always },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "Always.Name", "EPicoXRGazeBehavior::Always" },
				{ "BlueprintType", "true" },
				{ "DuringMotion.Name", "EPicoXRGazeBehavior::DuringMotion" },
				{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
				{ "Never.Name", "EPicoXRGazeBehavior::Never" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_PicoXRInput,
				nullptr,
				"EPicoXRGazeBehavior",
				"EPicoXRGazeBehavior",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* EPicoXRArmModelJoint_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_PicoXRInput_EPicoXRArmModelJoint, Z_Construct_UPackage__Script_PicoXRInput(), TEXT("EPicoXRArmModelJoint"));
		}
		return Singleton;
	}
	template<> PICOXRINPUT_API UEnum* StaticEnum<EPicoXRArmModelJoint>()
	{
		return EPicoXRArmModelJoint_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EPicoXRArmModelJoint(EPicoXRArmModelJoint_StaticEnum, TEXT("/Script/PicoXRInput"), TEXT("EPicoXRArmModelJoint"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_PicoXRInput_EPicoXRArmModelJoint_Hash() { return 39512613U; }
	UEnum* Z_Construct_UEnum_PicoXRInput_EPicoXRArmModelJoint()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_PicoXRInput();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EPicoXRArmModelJoint"), 0, Get_Z_Construct_UEnum_PicoXRInput_EPicoXRArmModelJoint_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EPicoXRArmModelJoint::Controller", (int64)EPicoXRArmModelJoint::Controller },
				{ "EPicoXRArmModelJoint::Wrist", (int64)EPicoXRArmModelJoint::Wrist },
				{ "EPicoXRArmModelJoint::Elbow", (int64)EPicoXRArmModelJoint::Elbow },
				{ "EPicoXRArmModelJoint::Shoulder", (int64)EPicoXRArmModelJoint::Shoulder },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Controller.Name", "EPicoXRArmModelJoint::Controller" },
				{ "Elbow.Name", "EPicoXRArmModelJoint::Elbow" },
				{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
				{ "Shoulder.Name", "EPicoXRArmModelJoint::Shoulder" },
				{ "Wrist.Name", "EPicoXRArmModelJoint::Wrist" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_PicoXRInput,
				nullptr,
				"EPicoXRArmModelJoint",
				"EPicoXRArmModelJoint",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* EPicoXRControllerType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_PicoXRInput_EPicoXRControllerType, Z_Construct_UPackage__Script_PicoXRInput(), TEXT("EPicoXRControllerType"));
		}
		return Singleton;
	}
	template<> PICOXRINPUT_API UEnum* StaticEnum<EPicoXRControllerType>()
	{
		return EPicoXRControllerType_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EPicoXRControllerType(EPicoXRControllerType_StaticEnum, TEXT("/Script/PicoXRInput"), TEXT("EPicoXRControllerType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_PicoXRInput_EPicoXRControllerType_Hash() { return 4243800933U; }
	UEnum* Z_Construct_UEnum_PicoXRInput_EPicoXRControllerType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_PicoXRInput();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EPicoXRControllerType"), 0, Get_Z_Construct_UEnum_PicoXRInput_EPicoXRControllerType_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EPicoXRControllerType::LeftHand", (int64)EPicoXRControllerType::LeftHand },
				{ "EPicoXRControllerType::RightHand", (int64)EPicoXRControllerType::RightHand },
				{ "EPicoXRControllerType::G2Hand", (int64)EPicoXRControllerType::G2Hand },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "G2Hand.DisplayName", "Pico G2 Hand" },
				{ "G2Hand.Name", "EPicoXRControllerType::G2Hand" },
				{ "LeftHand.DisplayName", "Pico Neo LeftHand" },
				{ "LeftHand.Name", "EPicoXRControllerType::LeftHand" },
				{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
				{ "RightHand.DisplayName", "Pico Neo RightHand" },
				{ "RightHand.Name", "EPicoXRControllerType::RightHand" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_PicoXRInput,
				nullptr,
				"EPicoXRControllerType",
				"EPicoXRControllerType",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* EPicoXRHandedness_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_PicoXRInput_EPicoXRHandedness, Z_Construct_UPackage__Script_PicoXRInput(), TEXT("EPicoXRHandedness"));
		}
		return Singleton;
	}
	template<> PICOXRINPUT_API UEnum* StaticEnum<EPicoXRHandedness>()
	{
		return EPicoXRHandedness_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EPicoXRHandedness(EPicoXRHandedness_StaticEnum, TEXT("/Script/PicoXRInput"), TEXT("EPicoXRHandedness"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_PicoXRInput_EPicoXRHandedness_Hash() { return 3256712269U; }
	UEnum* Z_Construct_UEnum_PicoXRInput_EPicoXRHandedness()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_PicoXRInput();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EPicoXRHandedness"), 0, Get_Z_Construct_UEnum_PicoXRInput_EPicoXRHandedness_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EPicoXRHandedness::LeftHand", (int64)EPicoXRHandedness::LeftHand },
				{ "EPicoXRHandedness::RightHand", (int64)EPicoXRHandedness::RightHand },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "LeftHand.Name", "EPicoXRHandedness::LeftHand" },
				{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
				{ "RightHand.Name", "EPicoXRHandedness::RightHand" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_PicoXRInput,
				nullptr,
				"EPicoXRHandedness",
				"EPicoXRHandedness",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	DEFINE_FUNCTION(UPicoXRInputFunctionLibrary::execPXR_SetControllerEnableKey)
	{
		P_GET_UBOOL(Z_Param_isEnable);
		P_GET_ENUM(EPxrControllerKeyMap,Z_Param_Key);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=UPicoXRInputFunctionLibrary::PXR_SetControllerEnableKey(Z_Param_isEnable,EPxrControllerKeyMap(Z_Param_Key));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRInputFunctionLibrary::execPXR_GetControllerPredictedLocationAndRotation)
	{
		P_GET_ENUM(EControllerHand,Z_Param_DeviceHand);
		P_GET_PROPERTY(FFloatProperty,Z_Param_PredictedTime);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_OutLocation);
		P_GET_STRUCT_REF(FRotator,Z_Param_Out_OutRotation);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPicoXRInputFunctionLibrary::PXR_GetControllerPredictedLocationAndRotation(EControllerHand(Z_Param_DeviceHand),Z_Param_PredictedTime,Z_Param_Out_OutLocation,Z_Param_Out_OutRotation);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRInputFunctionLibrary::execPXR_SetControllerOriginOffset)
	{
		P_GET_ENUM(EPicoXRControllerType,Z_Param_Controller);
		P_GET_STRUCT(FVector,Z_Param_Offset);
		P_FINISH;
		P_NATIVE_BEGIN;
		UPicoXRInputFunctionLibrary::PXR_SetControllerOriginOffset(EPicoXRControllerType(Z_Param_Controller),Z_Param_Offset);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRInputFunctionLibrary::execPXR_GetControllerEnableHomekey)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPicoXRInputFunctionLibrary::PXR_GetControllerEnableHomekey();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRInputFunctionLibrary::execPXR_GetHandedness)
	{
		P_GET_ENUM_REF(EPicoXRHandedness,Z_Param_Out_Handedness);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPicoXRInputFunctionLibrary::PXR_GetHandedness((EPicoXRHandedness&)(Z_Param_Out_Handedness));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRInputFunctionLibrary::execPXR_GetControllerArmModelParam)
	{
		P_GET_ENUM(EPicoXRControllerType,Z_Param_Controller);
		P_GET_ENUM_REF(EPicoXRHandedness,Z_Param_Out_Handness);
		P_GET_ENUM_REF(EPicoXRArmModelJoint,Z_Param_Out_ArmJoint);
		P_GET_ENUM_REF(EPicoXRGazeBehavior,Z_Param_Out_GazeType);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_ElbowHeight);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_ElbowDepth);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_PointerTiltAngle);
		P_FINISH;
		P_NATIVE_BEGIN;
		UPicoXRInputFunctionLibrary::PXR_GetControllerArmModelParam(EPicoXRControllerType(Z_Param_Controller),(EPicoXRHandedness&)(Z_Param_Out_Handness),(EPicoXRArmModelJoint&)(Z_Param_Out_ArmJoint),(EPicoXRGazeBehavior&)(Z_Param_Out_GazeType),Z_Param_Out_ElbowHeight,Z_Param_Out_ElbowDepth,Z_Param_Out_PointerTiltAngle);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRInputFunctionLibrary::execPXR_SetControllerArmModelParam)
	{
		P_GET_ENUM(EPicoXRControllerType,Z_Param_Controller);
		P_GET_ENUM(EPicoXRHandedness,Z_Param_Handness);
		P_GET_ENUM(EPicoXRArmModelJoint,Z_Param_ArmJoint);
		P_GET_ENUM(EPicoXRGazeBehavior,Z_Param_GazeType);
		P_GET_PROPERTY(FFloatProperty,Z_Param_ElbowHeight);
		P_GET_PROPERTY(FFloatProperty,Z_Param_ElbowDepth);
		P_GET_PROPERTY(FFloatProperty,Z_Param_PointerTiltAngle);
		P_FINISH;
		P_NATIVE_BEGIN;
		UPicoXRInputFunctionLibrary::PXR_SetControllerArmModelParam(EPicoXRControllerType(Z_Param_Controller),EPicoXRHandedness(Z_Param_Handness),EPicoXRArmModelJoint(Z_Param_ArmJoint),EPicoXRGazeBehavior(Z_Param_GazeType),Z_Param_ElbowHeight,Z_Param_ElbowDepth,Z_Param_PointerTiltAngle);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRInputFunctionLibrary::execPXR_GetControllerDeviceType)
	{
		P_GET_ENUM_REF(EPicoXRControllerDeviceType,Z_Param_Out_ControllerType);
		P_FINISH;
		P_NATIVE_BEGIN;
		UPicoXRInputFunctionLibrary::PXR_GetControllerDeviceType((EPicoXRControllerDeviceType&)(Z_Param_Out_ControllerType));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRInputFunctionLibrary::execPXR_VibrateController)
	{
		P_GET_ENUM(EPicoXRControllerType,Z_Param_ControllerType);
		P_GET_PROPERTY(FFloatProperty,Z_Param_Strength);
		P_GET_PROPERTY(FIntProperty,Z_Param_Time);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPicoXRInputFunctionLibrary::PXR_VibrateController(EPicoXRControllerType(Z_Param_ControllerType),Z_Param_Strength,Z_Param_Time);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRInputFunctionLibrary::execPXR_GetControllerLinearVelocity)
	{
		P_GET_ENUM(EPicoXRControllerType,Z_Param_ControllerType);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_LinearVelocity);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPicoXRInputFunctionLibrary::PXR_GetControllerLinearVelocity(EPicoXRControllerType(Z_Param_ControllerType),Z_Param_Out_LinearVelocity);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRInputFunctionLibrary::execPXR_GetControllerAcceleration)
	{
		P_GET_ENUM(EPicoXRControllerType,Z_Param_ControllerType);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Acceleration);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPicoXRInputFunctionLibrary::PXR_GetControllerAcceleration(EPicoXRControllerType(Z_Param_ControllerType),Z_Param_Out_Acceleration);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRInputFunctionLibrary::execPXR_GetControllerAngularVelocity)
	{
		P_GET_ENUM(EPicoXRControllerType,Z_Param_ControllerType);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_AngularVelocity);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPicoXRInputFunctionLibrary::PXR_GetControllerAngularVelocity(EPicoXRControllerType(Z_Param_ControllerType),Z_Param_Out_AngularVelocity);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRInputFunctionLibrary::execPXR_SetMainControllerHandle)
	{
		P_GET_ENUM(EPicoXRHandedness,Z_Param_Handedness);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPicoXRInputFunctionLibrary::PXR_SetMainControllerHandle(EPicoXRHandedness(Z_Param_Handedness));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRInputFunctionLibrary::execPXR_GetMainControllerHandle)
	{
		P_GET_ENUM_REF(EPicoXRHandedness,Z_Param_Out_Handedness);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPicoXRInputFunctionLibrary::PXR_GetMainControllerHandle((EPicoXRHandedness&)(Z_Param_Out_Handedness));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRInputFunctionLibrary::execPXR_GetControllerConnectionState)
	{
		P_GET_ENUM(EPicoXRControllerType,Z_Param_ControllerType);
		P_GET_UBOOL_REF(Z_Param_Out_Status);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPicoXRInputFunctionLibrary::PXR_GetControllerConnectionState(EPicoXRControllerType(Z_Param_ControllerType),Z_Param_Out_Status);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRInputFunctionLibrary::execPXR_GetControllerPower)
	{
		P_GET_ENUM(EPicoXRControllerType,Z_Param_ControllerType);
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_Power);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPicoXRInputFunctionLibrary::PXR_GetControllerPower(EPicoXRControllerType(Z_Param_ControllerType),Z_Param_Out_Power);
		P_NATIVE_END;
	}
	void UPicoXRInputFunctionLibrary::StaticRegisterNativesUPicoXRInputFunctionLibrary()
	{
		UClass* Class = UPicoXRInputFunctionLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "PXR_GetControllerAcceleration", &UPicoXRInputFunctionLibrary::execPXR_GetControllerAcceleration },
			{ "PXR_GetControllerAngularVelocity", &UPicoXRInputFunctionLibrary::execPXR_GetControllerAngularVelocity },
			{ "PXR_GetControllerArmModelParam", &UPicoXRInputFunctionLibrary::execPXR_GetControllerArmModelParam },
			{ "PXR_GetControllerConnectionState", &UPicoXRInputFunctionLibrary::execPXR_GetControllerConnectionState },
			{ "PXR_GetControllerDeviceType", &UPicoXRInputFunctionLibrary::execPXR_GetControllerDeviceType },
			{ "PXR_GetControllerEnableHomekey", &UPicoXRInputFunctionLibrary::execPXR_GetControllerEnableHomekey },
			{ "PXR_GetControllerLinearVelocity", &UPicoXRInputFunctionLibrary::execPXR_GetControllerLinearVelocity },
			{ "PXR_GetControllerPower", &UPicoXRInputFunctionLibrary::execPXR_GetControllerPower },
			{ "PXR_GetControllerPredictedLocationAndRotation", &UPicoXRInputFunctionLibrary::execPXR_GetControllerPredictedLocationAndRotation },
			{ "PXR_GetHandedness", &UPicoXRInputFunctionLibrary::execPXR_GetHandedness },
			{ "PXR_GetMainControllerHandle", &UPicoXRInputFunctionLibrary::execPXR_GetMainControllerHandle },
			{ "PXR_SetControllerArmModelParam", &UPicoXRInputFunctionLibrary::execPXR_SetControllerArmModelParam },
			{ "PXR_SetControllerEnableKey", &UPicoXRInputFunctionLibrary::execPXR_SetControllerEnableKey },
			{ "PXR_SetControllerOriginOffset", &UPicoXRInputFunctionLibrary::execPXR_SetControllerOriginOffset },
			{ "PXR_SetMainControllerHandle", &UPicoXRInputFunctionLibrary::execPXR_SetMainControllerHandle },
			{ "PXR_VibrateController", &UPicoXRInputFunctionLibrary::execPXR_VibrateController },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerAcceleration_Statics
	{
		struct PicoXRInputFunctionLibrary_eventPXR_GetControllerAcceleration_Parms
		{
			EPicoXRControllerType ControllerType;
			FVector Acceleration;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ControllerType_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_ControllerType;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Acceleration;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerAcceleration_Statics::NewProp_ControllerType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerAcceleration_Statics::NewProp_ControllerType = { "ControllerType", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRInputFunctionLibrary_eventPXR_GetControllerAcceleration_Parms, ControllerType), Z_Construct_UEnum_PicoXRInput_EPicoXRControllerType, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerAcceleration_Statics::NewProp_Acceleration = { "Acceleration", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRInputFunctionLibrary_eventPXR_GetControllerAcceleration_Parms, Acceleration), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerAcceleration_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PicoXRInputFunctionLibrary_eventPXR_GetControllerAcceleration_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerAcceleration_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PicoXRInputFunctionLibrary_eventPXR_GetControllerAcceleration_Parms), &Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerAcceleration_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerAcceleration_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerAcceleration_Statics::NewProp_ControllerType_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerAcceleration_Statics::NewProp_ControllerType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerAcceleration_Statics::NewProp_Acceleration,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerAcceleration_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerAcceleration_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
		{ "Comment", "/**\n\x09* Get controller acceleration.\n\x09* @param ControllerType    (In) The controller type(G2 controller/Neo LeftController/Neo RightController).\n\x09* @param Acceleration     (Out) Controller acceleration.\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
		{ "ToolTip", "Get controller acceleration.\n@param ControllerType    (In) The controller type(G2 controller/Neo LeftController/Neo RightController).\n@param Acceleration     (Out) Controller acceleration." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerAcceleration_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRInputFunctionLibrary, nullptr, "PXR_GetControllerAcceleration", nullptr, nullptr, sizeof(PicoXRInputFunctionLibrary_eventPXR_GetControllerAcceleration_Parms), Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerAcceleration_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerAcceleration_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerAcceleration_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerAcceleration_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerAcceleration()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerAcceleration_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerAngularVelocity_Statics
	{
		struct PicoXRInputFunctionLibrary_eventPXR_GetControllerAngularVelocity_Parms
		{
			EPicoXRControllerType ControllerType;
			FVector AngularVelocity;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ControllerType_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_ControllerType;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_AngularVelocity;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerAngularVelocity_Statics::NewProp_ControllerType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerAngularVelocity_Statics::NewProp_ControllerType = { "ControllerType", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRInputFunctionLibrary_eventPXR_GetControllerAngularVelocity_Parms, ControllerType), Z_Construct_UEnum_PicoXRInput_EPicoXRControllerType, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerAngularVelocity_Statics::NewProp_AngularVelocity = { "AngularVelocity", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRInputFunctionLibrary_eventPXR_GetControllerAngularVelocity_Parms, AngularVelocity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerAngularVelocity_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PicoXRInputFunctionLibrary_eventPXR_GetControllerAngularVelocity_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerAngularVelocity_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PicoXRInputFunctionLibrary_eventPXR_GetControllerAngularVelocity_Parms), &Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerAngularVelocity_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerAngularVelocity_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerAngularVelocity_Statics::NewProp_ControllerType_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerAngularVelocity_Statics::NewProp_ControllerType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerAngularVelocity_Statics::NewProp_AngularVelocity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerAngularVelocity_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerAngularVelocity_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
		{ "Comment", "/**\n\x09* Get controller angular velocity.\n\x09* @param ControllerType     (In) The controller type(G2 controller/Neo LeftController/Neo RightController).\n\x09* @param AngularVelocity   (Out) Controller angular velocity.\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
		{ "ToolTip", "Get controller angular velocity.\n@param ControllerType     (In) The controller type(G2 controller/Neo LeftController/Neo RightController).\n@param AngularVelocity   (Out) Controller angular velocity." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerAngularVelocity_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRInputFunctionLibrary, nullptr, "PXR_GetControllerAngularVelocity", nullptr, nullptr, sizeof(PicoXRInputFunctionLibrary_eventPXR_GetControllerAngularVelocity_Parms), Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerAngularVelocity_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerAngularVelocity_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerAngularVelocity_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerAngularVelocity_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerAngularVelocity()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerAngularVelocity_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerArmModelParam_Statics
	{
		struct PicoXRInputFunctionLibrary_eventPXR_GetControllerArmModelParam_Parms
		{
			EPicoXRControllerType Controller;
			EPicoXRHandedness Handness;
			EPicoXRArmModelJoint ArmJoint;
			EPicoXRGazeBehavior GazeType;
			float ElbowHeight;
			float ElbowDepth;
			float PointerTiltAngle;
		};
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Controller_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Controller;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Handness_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Handness;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ArmJoint_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_ArmJoint;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_GazeType_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_GazeType;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ElbowHeight;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ElbowDepth;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_PointerTiltAngle;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerArmModelParam_Statics::NewProp_Controller_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerArmModelParam_Statics::NewProp_Controller = { "Controller", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRInputFunctionLibrary_eventPXR_GetControllerArmModelParam_Parms, Controller), Z_Construct_UEnum_PicoXRInput_EPicoXRControllerType, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerArmModelParam_Statics::NewProp_Handness_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerArmModelParam_Statics::NewProp_Handness = { "Handness", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRInputFunctionLibrary_eventPXR_GetControllerArmModelParam_Parms, Handness), Z_Construct_UEnum_PicoXRInput_EPicoXRHandedness, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerArmModelParam_Statics::NewProp_ArmJoint_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerArmModelParam_Statics::NewProp_ArmJoint = { "ArmJoint", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRInputFunctionLibrary_eventPXR_GetControllerArmModelParam_Parms, ArmJoint), Z_Construct_UEnum_PicoXRInput_EPicoXRArmModelJoint, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerArmModelParam_Statics::NewProp_GazeType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerArmModelParam_Statics::NewProp_GazeType = { "GazeType", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRInputFunctionLibrary_eventPXR_GetControllerArmModelParam_Parms, GazeType), Z_Construct_UEnum_PicoXRInput_EPicoXRGazeBehavior, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerArmModelParam_Statics::NewProp_ElbowHeight = { "ElbowHeight", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRInputFunctionLibrary_eventPXR_GetControllerArmModelParam_Parms, ElbowHeight), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerArmModelParam_Statics::NewProp_ElbowDepth = { "ElbowDepth", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRInputFunctionLibrary_eventPXR_GetControllerArmModelParam_Parms, ElbowDepth), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerArmModelParam_Statics::NewProp_PointerTiltAngle = { "PointerTiltAngle", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRInputFunctionLibrary_eventPXR_GetControllerArmModelParam_Parms, PointerTiltAngle), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerArmModelParam_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerArmModelParam_Statics::NewProp_Controller_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerArmModelParam_Statics::NewProp_Controller,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerArmModelParam_Statics::NewProp_Handness_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerArmModelParam_Statics::NewProp_Handness,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerArmModelParam_Statics::NewProp_ArmJoint_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerArmModelParam_Statics::NewProp_ArmJoint,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerArmModelParam_Statics::NewProp_GazeType_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerArmModelParam_Statics::NewProp_GazeType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerArmModelParam_Statics::NewProp_ElbowHeight,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerArmModelParam_Statics::NewProp_ElbowDepth,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerArmModelParam_Statics::NewProp_PointerTiltAngle,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerArmModelParam_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
		{ "Comment", "/**\n\x09* Set controller arm model parameter.\n\x09* @param Controller         (In) The controller type(G2 controller/Neo LeftController/Neo RightController).\n\x09* @param Handness          (Out) Determines if the controller is in the left hand or right hand.\n\x09* @param ArmJoint          (Out) The arm joint(Controller/Wrist/Elbow/Shoulder).\n\x09* @param GazeType          (Out) The gaze type(Never/DuringMotion/Always).\n\x09* @param ElbowHeight       (Out) The Height of the elbow..\n\x09* @param ElbowDepth        (Out) The Depth of the elbow.\n\x09* @param PointerTiltAngle  (Out) The Downward tilt or pitch of the laser pointer relative to the controller (degrees).\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
		{ "ToolTip", "Set controller arm model parameter.\n@param Controller         (In) The controller type(G2 controller/Neo LeftController/Neo RightController).\n@param Handness          (Out) Determines if the controller is in the left hand or right hand.\n@param ArmJoint          (Out) The arm joint(Controller/Wrist/Elbow/Shoulder).\n@param GazeType          (Out) The gaze type(Never/DuringMotion/Always).\n@param ElbowHeight       (Out) The Height of the elbow..\n@param ElbowDepth        (Out) The Depth of the elbow.\n@param PointerTiltAngle  (Out) The Downward tilt or pitch of the laser pointer relative to the controller (degrees)." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerArmModelParam_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRInputFunctionLibrary, nullptr, "PXR_GetControllerArmModelParam", nullptr, nullptr, sizeof(PicoXRInputFunctionLibrary_eventPXR_GetControllerArmModelParam_Parms), Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerArmModelParam_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerArmModelParam_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerArmModelParam_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerArmModelParam_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerArmModelParam()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerArmModelParam_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerConnectionState_Statics
	{
		struct PicoXRInputFunctionLibrary_eventPXR_GetControllerConnectionState_Parms
		{
			EPicoXRControllerType ControllerType;
			bool Status;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ControllerType_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_ControllerType;
		static void NewProp_Status_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_Status;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerConnectionState_Statics::NewProp_ControllerType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerConnectionState_Statics::NewProp_ControllerType = { "ControllerType", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRInputFunctionLibrary_eventPXR_GetControllerConnectionState_Parms, ControllerType), Z_Construct_UEnum_PicoXRInput_EPicoXRControllerType, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerConnectionState_Statics::NewProp_Status_SetBit(void* Obj)
	{
		((PicoXRInputFunctionLibrary_eventPXR_GetControllerConnectionState_Parms*)Obj)->Status = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerConnectionState_Statics::NewProp_Status = { "Status", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PicoXRInputFunctionLibrary_eventPXR_GetControllerConnectionState_Parms), &Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerConnectionState_Statics::NewProp_Status_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerConnectionState_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PicoXRInputFunctionLibrary_eventPXR_GetControllerConnectionState_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerConnectionState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PicoXRInputFunctionLibrary_eventPXR_GetControllerConnectionState_Parms), &Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerConnectionState_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerConnectionState_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerConnectionState_Statics::NewProp_ControllerType_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerConnectionState_Statics::NewProp_ControllerType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerConnectionState_Statics::NewProp_Status,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerConnectionState_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerConnectionState_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
		{ "Comment", "/**\n\x09* Get controller connect state.\n\x09* @param ControllerType   (In) The controller type(G2 controller/Neo LeftController/Neo RightController).\n\x09* @param Status          (Out) Connect state,true:Connected,false:DisConnected.\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
		{ "ToolTip", "Get controller connect state.\n@param ControllerType   (In) The controller type(G2 controller/Neo LeftController/Neo RightController).\n@param Status          (Out) Connect state,true:Connected,false:DisConnected." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerConnectionState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRInputFunctionLibrary, nullptr, "PXR_GetControllerConnectionState", nullptr, nullptr, sizeof(PicoXRInputFunctionLibrary_eventPXR_GetControllerConnectionState_Parms), Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerConnectionState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerConnectionState_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerConnectionState_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerConnectionState_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerConnectionState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerConnectionState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerDeviceType_Statics
	{
		struct PicoXRInputFunctionLibrary_eventPXR_GetControllerDeviceType_Parms
		{
			EPicoXRControllerDeviceType ControllerType;
		};
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ControllerType_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_ControllerType;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerDeviceType_Statics::NewProp_ControllerType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerDeviceType_Statics::NewProp_ControllerType = { "ControllerType", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRInputFunctionLibrary_eventPXR_GetControllerDeviceType_Parms, ControllerType), Z_Construct_UEnum_PicoXRInput_EPicoXRControllerDeviceType, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerDeviceType_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerDeviceType_Statics::NewProp_ControllerType_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerDeviceType_Statics::NewProp_ControllerType,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerDeviceType_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
		{ "Comment", "/**\n\x09* Get the controller type.\n\x09* @param ControllerType    (Out) The controller type(G2 /Neo).\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
		{ "ToolTip", "Get the controller type.\n@param ControllerType    (Out) The controller type(G2 /Neo)." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerDeviceType_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRInputFunctionLibrary, nullptr, "PXR_GetControllerDeviceType", nullptr, nullptr, sizeof(PicoXRInputFunctionLibrary_eventPXR_GetControllerDeviceType_Parms), Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerDeviceType_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerDeviceType_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerDeviceType_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerDeviceType_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerDeviceType()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerDeviceType_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerEnableHomekey_Statics
	{
		struct PicoXRInputFunctionLibrary_eventPXR_GetControllerEnableHomekey_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerEnableHomekey_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PicoXRInputFunctionLibrary_eventPXR_GetControllerEnableHomekey_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerEnableHomekey_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PicoXRInputFunctionLibrary_eventPXR_GetControllerEnableHomekey_Parms), &Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerEnableHomekey_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerEnableHomekey_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerEnableHomekey_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerEnableHomekey_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
		{ "Comment", "/**\n\x09* Get controller enable homeKey.\n\x09* @return True if home key enable.\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
		{ "ToolTip", "Get controller enable homeKey.\n@return True if home key enable." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerEnableHomekey_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRInputFunctionLibrary, nullptr, "PXR_GetControllerEnableHomekey", nullptr, nullptr, sizeof(PicoXRInputFunctionLibrary_eventPXR_GetControllerEnableHomekey_Parms), Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerEnableHomekey_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerEnableHomekey_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerEnableHomekey_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerEnableHomekey_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerEnableHomekey()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerEnableHomekey_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerLinearVelocity_Statics
	{
		struct PicoXRInputFunctionLibrary_eventPXR_GetControllerLinearVelocity_Parms
		{
			EPicoXRControllerType ControllerType;
			FVector LinearVelocity;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ControllerType_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_ControllerType;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_LinearVelocity;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerLinearVelocity_Statics::NewProp_ControllerType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerLinearVelocity_Statics::NewProp_ControllerType = { "ControllerType", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRInputFunctionLibrary_eventPXR_GetControllerLinearVelocity_Parms, ControllerType), Z_Construct_UEnum_PicoXRInput_EPicoXRControllerType, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerLinearVelocity_Statics::NewProp_LinearVelocity = { "LinearVelocity", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRInputFunctionLibrary_eventPXR_GetControllerLinearVelocity_Parms, LinearVelocity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerLinearVelocity_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PicoXRInputFunctionLibrary_eventPXR_GetControllerLinearVelocity_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerLinearVelocity_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PicoXRInputFunctionLibrary_eventPXR_GetControllerLinearVelocity_Parms), &Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerLinearVelocity_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerLinearVelocity_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerLinearVelocity_Statics::NewProp_ControllerType_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerLinearVelocity_Statics::NewProp_ControllerType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerLinearVelocity_Statics::NewProp_LinearVelocity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerLinearVelocity_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerLinearVelocity_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
		{ "Comment", "/**\n\x09* Get controller linear velocity.\n\x09* @param ControllerType     (In) The controller type(G2 controller/Neo LeftController/Neo RightController).\n\x09* @param LinearVelocity    (Out) Controller linear velocity.\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
		{ "ToolTip", "Get controller linear velocity.\n@param ControllerType     (In) The controller type(G2 controller/Neo LeftController/Neo RightController).\n@param LinearVelocity    (Out) Controller linear velocity." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerLinearVelocity_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRInputFunctionLibrary, nullptr, "PXR_GetControllerLinearVelocity", nullptr, nullptr, sizeof(PicoXRInputFunctionLibrary_eventPXR_GetControllerLinearVelocity_Parms), Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerLinearVelocity_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerLinearVelocity_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerLinearVelocity_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerLinearVelocity_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerLinearVelocity()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerLinearVelocity_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerPower_Statics
	{
		struct PicoXRInputFunctionLibrary_eventPXR_GetControllerPower_Parms
		{
			EPicoXRControllerType ControllerType;
			int32 Power;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ControllerType_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_ControllerType;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Power;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerPower_Statics::NewProp_ControllerType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerPower_Statics::NewProp_ControllerType = { "ControllerType", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRInputFunctionLibrary_eventPXR_GetControllerPower_Parms, ControllerType), Z_Construct_UEnum_PicoXRInput_EPicoXRControllerType, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerPower_Statics::NewProp_Power = { "Power", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRInputFunctionLibrary_eventPXR_GetControllerPower_Parms, Power), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerPower_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PicoXRInputFunctionLibrary_eventPXR_GetControllerPower_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerPower_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PicoXRInputFunctionLibrary_eventPXR_GetControllerPower_Parms), &Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerPower_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerPower_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerPower_Statics::NewProp_ControllerType_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerPower_Statics::NewProp_ControllerType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerPower_Statics::NewProp_Power,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerPower_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerPower_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
		{ "Comment", "/**\n\x09* Get controller power.\n\x09* @param ControllerType   (In) The controller type(G2 controller/Neo LeftController/Neo RightController).\n\x09* @param Power           (Out) The power of controller.\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
		{ "ToolTip", "Get controller power.\n@param ControllerType   (In) The controller type(G2 controller/Neo LeftController/Neo RightController).\n@param Power           (Out) The power of controller." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerPower_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRInputFunctionLibrary, nullptr, "PXR_GetControllerPower", nullptr, nullptr, sizeof(PicoXRInputFunctionLibrary_eventPXR_GetControllerPower_Parms), Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerPower_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerPower_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerPower_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerPower_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerPower()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerPower_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics
	{
		struct PicoXRInputFunctionLibrary_eventPXR_GetControllerPredictedLocationAndRotation_Parms
		{
			EControllerHand DeviceHand;
			float PredictedTime;
			FVector OutLocation;
			FRotator OutRotation;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_DeviceHand_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_DeviceHand;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_PredictedTime;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_OutLocation;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_OutRotation;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics::NewProp_DeviceHand_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics::NewProp_DeviceHand = { "DeviceHand", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRInputFunctionLibrary_eventPXR_GetControllerPredictedLocationAndRotation_Parms, DeviceHand), Z_Construct_UEnum_InputCore_EControllerHand, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics::NewProp_PredictedTime = { "PredictedTime", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRInputFunctionLibrary_eventPXR_GetControllerPredictedLocationAndRotation_Parms, PredictedTime), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics::NewProp_OutLocation = { "OutLocation", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRInputFunctionLibrary_eventPXR_GetControllerPredictedLocationAndRotation_Parms, OutLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics::NewProp_OutRotation = { "OutRotation", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRInputFunctionLibrary_eventPXR_GetControllerPredictedLocationAndRotation_Parms, OutRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PicoXRInputFunctionLibrary_eventPXR_GetControllerPredictedLocationAndRotation_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PicoXRInputFunctionLibrary_eventPXR_GetControllerPredictedLocationAndRotation_Parms), &Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics::NewProp_DeviceHand_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics::NewProp_DeviceHand,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics::NewProp_PredictedTime,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics::NewProp_OutLocation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics::NewProp_OutRotation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
		{ "Comment", "/**\n\x09 * Get controller location and rotation with predicted time.\n\x09 * @param DeviceHand      (In) Select the left or right handle.\n\x09 * @param PredictedTime   (In) Prediction time (ms).\n\x09 * @param OutLocation    (Out) Location with predicted time.\n\x09 * @param OutRotation    (Out) Rotation with predicted time.\n\x09 */" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
		{ "ToolTip", "Get controller location and rotation with predicted time.\n@param DeviceHand      (In) Select the left or right handle.\n@param PredictedTime   (In) Prediction time (ms).\n@param OutLocation    (Out) Location with predicted time.\n@param OutRotation    (Out) Rotation with predicted time." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRInputFunctionLibrary, nullptr, "PXR_GetControllerPredictedLocationAndRotation", nullptr, nullptr, sizeof(PicoXRInputFunctionLibrary_eventPXR_GetControllerPredictedLocationAndRotation_Parms), Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetHandedness_Statics
	{
		struct PicoXRInputFunctionLibrary_eventPXR_GetHandedness_Parms
		{
			EPicoXRHandedness Handedness;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Handedness_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Handedness;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetHandedness_Statics::NewProp_Handedness_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetHandedness_Statics::NewProp_Handedness = { "Handedness", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRInputFunctionLibrary_eventPXR_GetHandedness_Parms, Handedness), Z_Construct_UEnum_PicoXRInput_EPicoXRHandedness, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetHandedness_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PicoXRInputFunctionLibrary_eventPXR_GetHandedness_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetHandedness_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PicoXRInputFunctionLibrary_eventPXR_GetHandedness_Parms), &Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetHandedness_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetHandedness_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetHandedness_Statics::NewProp_Handedness_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetHandedness_Statics::NewProp_Handedness,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetHandedness_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetHandedness_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
		{ "Comment", "/**\n\x09* Get handedness.\n\x09* @param  Handedness        (Out) Handedness.\n\x09* @return True if get succeed.\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
		{ "ToolTip", "Get handedness.\n@param  Handedness        (Out) Handedness.\n@return True if get succeed." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetHandedness_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRInputFunctionLibrary, nullptr, "PXR_GetHandedness", nullptr, nullptr, sizeof(PicoXRInputFunctionLibrary_eventPXR_GetHandedness_Parms), Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetHandedness_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetHandedness_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetHandedness_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetHandedness_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetHandedness()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetHandedness_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetMainControllerHandle_Statics
	{
		struct PicoXRInputFunctionLibrary_eventPXR_GetMainControllerHandle_Parms
		{
			EPicoXRHandedness Handedness;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Handedness_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Handedness;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetMainControllerHandle_Statics::NewProp_Handedness_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetMainControllerHandle_Statics::NewProp_Handedness = { "Handedness", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRInputFunctionLibrary_eventPXR_GetMainControllerHandle_Parms, Handedness), Z_Construct_UEnum_PicoXRInput_EPicoXRHandedness, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetMainControllerHandle_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PicoXRInputFunctionLibrary_eventPXR_GetMainControllerHandle_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetMainControllerHandle_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PicoXRInputFunctionLibrary_eventPXR_GetMainControllerHandle_Parms), &Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetMainControllerHandle_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetMainControllerHandle_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetMainControllerHandle_Statics::NewProp_Handedness_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetMainControllerHandle_Statics::NewProp_Handedness,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetMainControllerHandle_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetMainControllerHandle_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
		{ "Comment", "/**\n\x09* Get the main controller.\n\x09* @param Handedness     (Out) Main handedness(Neo LeftController/Neo RightController).\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
		{ "ToolTip", "Get the main controller.\n@param Handedness     (Out) Main handedness(Neo LeftController/Neo RightController)." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetMainControllerHandle_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRInputFunctionLibrary, nullptr, "PXR_GetMainControllerHandle", nullptr, nullptr, sizeof(PicoXRInputFunctionLibrary_eventPXR_GetMainControllerHandle_Parms), Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetMainControllerHandle_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetMainControllerHandle_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetMainControllerHandle_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetMainControllerHandle_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetMainControllerHandle()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetMainControllerHandle_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerArmModelParam_Statics
	{
		struct PicoXRInputFunctionLibrary_eventPXR_SetControllerArmModelParam_Parms
		{
			EPicoXRControllerType Controller;
			EPicoXRHandedness Handness;
			EPicoXRArmModelJoint ArmJoint;
			EPicoXRGazeBehavior GazeType;
			float ElbowHeight;
			float ElbowDepth;
			float PointerTiltAngle;
		};
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Controller_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Controller;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Handness_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Handness;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ArmJoint_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_ArmJoint;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_GazeType_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_GazeType;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ElbowHeight;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ElbowDepth;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_PointerTiltAngle;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerArmModelParam_Statics::NewProp_Controller_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerArmModelParam_Statics::NewProp_Controller = { "Controller", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRInputFunctionLibrary_eventPXR_SetControllerArmModelParam_Parms, Controller), Z_Construct_UEnum_PicoXRInput_EPicoXRControllerType, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerArmModelParam_Statics::NewProp_Handness_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerArmModelParam_Statics::NewProp_Handness = { "Handness", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRInputFunctionLibrary_eventPXR_SetControllerArmModelParam_Parms, Handness), Z_Construct_UEnum_PicoXRInput_EPicoXRHandedness, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerArmModelParam_Statics::NewProp_ArmJoint_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerArmModelParam_Statics::NewProp_ArmJoint = { "ArmJoint", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRInputFunctionLibrary_eventPXR_SetControllerArmModelParam_Parms, ArmJoint), Z_Construct_UEnum_PicoXRInput_EPicoXRArmModelJoint, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerArmModelParam_Statics::NewProp_GazeType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerArmModelParam_Statics::NewProp_GazeType = { "GazeType", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRInputFunctionLibrary_eventPXR_SetControllerArmModelParam_Parms, GazeType), Z_Construct_UEnum_PicoXRInput_EPicoXRGazeBehavior, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerArmModelParam_Statics::NewProp_ElbowHeight = { "ElbowHeight", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRInputFunctionLibrary_eventPXR_SetControllerArmModelParam_Parms, ElbowHeight), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerArmModelParam_Statics::NewProp_ElbowDepth = { "ElbowDepth", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRInputFunctionLibrary_eventPXR_SetControllerArmModelParam_Parms, ElbowDepth), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerArmModelParam_Statics::NewProp_PointerTiltAngle = { "PointerTiltAngle", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRInputFunctionLibrary_eventPXR_SetControllerArmModelParam_Parms, PointerTiltAngle), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerArmModelParam_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerArmModelParam_Statics::NewProp_Controller_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerArmModelParam_Statics::NewProp_Controller,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerArmModelParam_Statics::NewProp_Handness_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerArmModelParam_Statics::NewProp_Handness,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerArmModelParam_Statics::NewProp_ArmJoint_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerArmModelParam_Statics::NewProp_ArmJoint,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerArmModelParam_Statics::NewProp_GazeType_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerArmModelParam_Statics::NewProp_GazeType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerArmModelParam_Statics::NewProp_ElbowHeight,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerArmModelParam_Statics::NewProp_ElbowDepth,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerArmModelParam_Statics::NewProp_PointerTiltAngle,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerArmModelParam_Statics::Function_MetaDataParams[] = {
		{ "ArmJoint", "Controller" },
		{ "Category", "PXR|PXRInput" },
		{ "Comment", "/**\n\x09* Set controller arm model parameter.\n\x09* @param Controller        (In) The controller type(G2 controller/Neo LeftController/Neo RightController).\n\x09* @param Handness          (In) Determines if the controller is in the left hand or right hand.\n\x09* @param ArmJoint          (In) The arm joint(Controller/Wrist/Elbow/Shoulder).\n\x09* @param GazeType          (In) The gaze type(Never/DuringMotion/Always).\n\x09* @param ElbowHeight       (In) The Height of the elbow..\n\x09* @param ElbowDepth        (In) The Depth of the elbow.\n\x09* @param PointerTiltAngle  (In) The Downward tilt or pitch of the laser pointer relative to the controller (degrees).\n\x09*/" },
		{ "ElbowDepth", "0.0" },
		{ "ElbowHeight", "0.0" },
		{ "GazeType", "DuringMotion" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
		{ "PointerTiltAngle", "15.0" },
		{ "ToolTip", "Set controller arm model parameter.\n@param Controller        (In) The controller type(G2 controller/Neo LeftController/Neo RightController).\n@param Handness          (In) Determines if the controller is in the left hand or right hand.\n@param ArmJoint          (In) The arm joint(Controller/Wrist/Elbow/Shoulder).\n@param GazeType          (In) The gaze type(Never/DuringMotion/Always).\n@param ElbowHeight       (In) The Height of the elbow..\n@param ElbowDepth        (In) The Depth of the elbow.\n@param PointerTiltAngle  (In) The Downward tilt or pitch of the laser pointer relative to the controller (degrees)." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerArmModelParam_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRInputFunctionLibrary, nullptr, "PXR_SetControllerArmModelParam", nullptr, nullptr, sizeof(PicoXRInputFunctionLibrary_eventPXR_SetControllerArmModelParam_Parms), Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerArmModelParam_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerArmModelParam_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerArmModelParam_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerArmModelParam_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerArmModelParam()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerArmModelParam_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerEnableKey_Statics
	{
		struct PicoXRInputFunctionLibrary_eventPXR_SetControllerEnableKey_Parms
		{
			bool isEnable;
			EPxrControllerKeyMap Key;
			int32 ReturnValue;
		};
		static void NewProp_isEnable_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_isEnable;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Key_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Key;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerEnableKey_Statics::NewProp_isEnable_SetBit(void* Obj)
	{
		((PicoXRInputFunctionLibrary_eventPXR_SetControllerEnableKey_Parms*)Obj)->isEnable = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerEnableKey_Statics::NewProp_isEnable = { "isEnable", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PicoXRInputFunctionLibrary_eventPXR_SetControllerEnableKey_Parms), &Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerEnableKey_Statics::NewProp_isEnable_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerEnableKey_Statics::NewProp_Key_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerEnableKey_Statics::NewProp_Key = { "Key", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRInputFunctionLibrary_eventPXR_SetControllerEnableKey_Parms, Key), Z_Construct_UEnum_PicoXRInput_EPxrControllerKeyMap, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerEnableKey_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRInputFunctionLibrary_eventPXR_SetControllerEnableKey_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerEnableKey_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerEnableKey_Statics::NewProp_isEnable,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerEnableKey_Statics::NewProp_Key_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerEnableKey_Statics::NewProp_Key,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerEnableKey_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerEnableKey_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerEnableKey_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRInputFunctionLibrary, nullptr, "PXR_SetControllerEnableKey", nullptr, nullptr, sizeof(PicoXRInputFunctionLibrary_eventPXR_SetControllerEnableKey_Parms), Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerEnableKey_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerEnableKey_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerEnableKey_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerEnableKey_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerEnableKey()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerEnableKey_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerOriginOffset_Statics
	{
		struct PicoXRInputFunctionLibrary_eventPXR_SetControllerOriginOffset_Parms
		{
			EPicoXRControllerType Controller;
			FVector Offset;
		};
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Controller_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Controller;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Offset;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerOriginOffset_Statics::NewProp_Controller_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerOriginOffset_Statics::NewProp_Controller = { "Controller", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRInputFunctionLibrary_eventPXR_SetControllerOriginOffset_Parms, Controller), Z_Construct_UEnum_PicoXRInput_EPicoXRControllerType, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerOriginOffset_Statics::NewProp_Offset = { "Offset", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRInputFunctionLibrary_eventPXR_SetControllerOriginOffset_Parms, Offset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerOriginOffset_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerOriginOffset_Statics::NewProp_Controller_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerOriginOffset_Statics::NewProp_Controller,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerOriginOffset_Statics::NewProp_Offset,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerOriginOffset_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
		{ "Comment", "/**\n\x09* Set controller origin offset.\n\x09* @param Controller      (In) Controller type.\n\x09* @param Offset          (In) Origin offset.   \n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
		{ "ToolTip", "Set controller origin offset.\n@param Controller      (In) Controller type.\n@param Offset          (In) Origin offset." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerOriginOffset_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRInputFunctionLibrary, nullptr, "PXR_SetControllerOriginOffset", nullptr, nullptr, sizeof(PicoXRInputFunctionLibrary_eventPXR_SetControllerOriginOffset_Parms), Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerOriginOffset_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerOriginOffset_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerOriginOffset_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerOriginOffset_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerOriginOffset()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerOriginOffset_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetMainControllerHandle_Statics
	{
		struct PicoXRInputFunctionLibrary_eventPXR_SetMainControllerHandle_Parms
		{
			EPicoXRHandedness Handedness;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Handedness_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Handedness;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetMainControllerHandle_Statics::NewProp_Handedness_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetMainControllerHandle_Statics::NewProp_Handedness = { "Handedness", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRInputFunctionLibrary_eventPXR_SetMainControllerHandle_Parms, Handedness), Z_Construct_UEnum_PicoXRInput_EPicoXRHandedness, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetMainControllerHandle_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PicoXRInputFunctionLibrary_eventPXR_SetMainControllerHandle_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetMainControllerHandle_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PicoXRInputFunctionLibrary_eventPXR_SetMainControllerHandle_Parms), &Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetMainControllerHandle_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetMainControllerHandle_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetMainControllerHandle_Statics::NewProp_Handedness_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetMainControllerHandle_Statics::NewProp_Handedness,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetMainControllerHandle_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetMainControllerHandle_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
		{ "Comment", "/**\n\x09* Set the main controller.\n\x09* @param Handedness     (In) Main handedness(Neo LeftController/Neo RightController).\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
		{ "ToolTip", "Set the main controller.\n@param Handedness     (In) Main handedness(Neo LeftController/Neo RightController)." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetMainControllerHandle_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRInputFunctionLibrary, nullptr, "PXR_SetMainControllerHandle", nullptr, nullptr, sizeof(PicoXRInputFunctionLibrary_eventPXR_SetMainControllerHandle_Parms), Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetMainControllerHandle_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetMainControllerHandle_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetMainControllerHandle_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetMainControllerHandle_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetMainControllerHandle()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetMainControllerHandle_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_VibrateController_Statics
	{
		struct PicoXRInputFunctionLibrary_eventPXR_VibrateController_Parms
		{
			EPicoXRControllerType ControllerType;
			float Strength;
			int32 Time;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ControllerType_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_ControllerType;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Strength;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_Time;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_VibrateController_Statics::NewProp_ControllerType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_VibrateController_Statics::NewProp_ControllerType = { "ControllerType", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRInputFunctionLibrary_eventPXR_VibrateController_Parms, ControllerType), Z_Construct_UEnum_PicoXRInput_EPicoXRControllerType, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_VibrateController_Statics::NewProp_Strength = { "Strength", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRInputFunctionLibrary_eventPXR_VibrateController_Parms, Strength), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_VibrateController_Statics::NewProp_Time = { "Time", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRInputFunctionLibrary_eventPXR_VibrateController_Parms, Time), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_VibrateController_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PicoXRInputFunctionLibrary_eventPXR_VibrateController_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_VibrateController_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PicoXRInputFunctionLibrary_eventPXR_VibrateController_Parms), &Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_VibrateController_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_VibrateController_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_VibrateController_Statics::NewProp_ControllerType_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_VibrateController_Statics::NewProp_ControllerType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_VibrateController_Statics::NewProp_Strength,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_VibrateController_Statics::NewProp_Time,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_VibrateController_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_VibrateController_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
		{ "Comment", "/**\n\x09* Vibration the controller.\n\x09* @param ControllerType    (In) The controller type(G2 controller/Neo LeftController/Neo RightController).\n\x09* @param Strength          (In) Vibration strength.\n\x09* @param Time              (In) Vibration time.\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
		{ "ToolTip", "Vibration the controller.\n@param ControllerType    (In) The controller type(G2 controller/Neo LeftController/Neo RightController).\n@param Strength          (In) Vibration strength.\n@param Time              (In) Vibration time." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_VibrateController_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRInputFunctionLibrary, nullptr, "PXR_VibrateController", nullptr, nullptr, sizeof(PicoXRInputFunctionLibrary_eventPXR_VibrateController_Parms), Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_VibrateController_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_VibrateController_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_VibrateController_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_VibrateController_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_VibrateController()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_VibrateController_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UPicoXRInputFunctionLibrary_NoRegister()
	{
		return UPicoXRInputFunctionLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UPicoXRInputFunctionLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPicoXRInputFunctionLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_PicoXRInput,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UPicoXRInputFunctionLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerAcceleration, "PXR_GetControllerAcceleration" }, // 40456988
		{ &Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerAngularVelocity, "PXR_GetControllerAngularVelocity" }, // 1258801585
		{ &Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerArmModelParam, "PXR_GetControllerArmModelParam" }, // 2815581694
		{ &Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerConnectionState, "PXR_GetControllerConnectionState" }, // 4208280405
		{ &Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerDeviceType, "PXR_GetControllerDeviceType" }, // 2641465440
		{ &Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerEnableHomekey, "PXR_GetControllerEnableHomekey" }, // 3953340093
		{ &Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerLinearVelocity, "PXR_GetControllerLinearVelocity" }, // 1691300952
		{ &Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerPower, "PXR_GetControllerPower" }, // 1472243610
		{ &Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation, "PXR_GetControllerPredictedLocationAndRotation" }, // 1494872169
		{ &Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetHandedness, "PXR_GetHandedness" }, // 724239787
		{ &Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_GetMainControllerHandle, "PXR_GetMainControllerHandle" }, // 3810522379
		{ &Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerArmModelParam, "PXR_SetControllerArmModelParam" }, // 204073731
		{ &Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerEnableKey, "PXR_SetControllerEnableKey" }, // 366707046
		{ &Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetControllerOriginOffset, "PXR_SetControllerOriginOffset" }, // 3725514023
		{ &Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_SetMainControllerHandle, "PXR_SetMainControllerHandle" }, // 1673850455
		{ &Z_Construct_UFunction_UPicoXRInputFunctionLibrary_PXR_VibrateController, "PXR_VibrateController" }, // 660348844
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPicoXRInputFunctionLibrary_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "PXR_InputFunctionLibrary.h" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPicoXRInputFunctionLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPicoXRInputFunctionLibrary>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UPicoXRInputFunctionLibrary_Statics::ClassParams = {
		&UPicoXRInputFunctionLibrary::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UPicoXRInputFunctionLibrary_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UPicoXRInputFunctionLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPicoXRInputFunctionLibrary()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UPicoXRInputFunctionLibrary_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UPicoXRInputFunctionLibrary, 3791102811);
	template<> PICOXRINPUT_API UClass* StaticClass<UPicoXRInputFunctionLibrary>()
	{
		return UPicoXRInputFunctionLibrary::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UPicoXRInputFunctionLibrary(Z_Construct_UClass_UPicoXRInputFunctionLibrary, &UPicoXRInputFunctionLibrary::StaticClass, TEXT("/Script/PicoXRInput"), TEXT("UPicoXRInputFunctionLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPicoXRInputFunctionLibrary);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
