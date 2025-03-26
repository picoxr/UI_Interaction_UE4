// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Pico_Room.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
 
class UObject;
class UPico_DataStore;
class UPico_Room;
class UPico_RoomArray;
class UPico_User;
class UPico_UserArray;
enum class ERoomJoinabilit : uint8;
enum class ERoomJoinPolicy : uint8;
enum class ERoomMembershipLockStatus : uint8;
enum class ERoomType : uint8;
struct FPicoRoomOptions;
#ifdef ONLINESUBSYSTEMPICO_Pico_Room_generated_h
#error "Pico_Room.generated.h already included, missing '#pragma once' in Pico_Room.h"
#endif
#define ONLINESUBSYSTEMPICO_Pico_Room_generated_h

#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_32_DELEGATE \
ONLINESUBSYSTEMPICO_API void FRoomLaunchInvitableUserFlow_DelegateWrapper(const FScriptDelegate& RoomLaunchInvitableUserFlow, bool bIsError, int32 ErrorCode, const FString& ErrorMessage);


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_33_DELEGATE \
ONLINESUBSYSTEMPICO_API void FRoomUpdateDataStore_DelegateWrapper(const FScriptDelegate& RoomUpdateDataStore, bool bIsError, int32 ErrorCode, const FString& ErrorMessage, UPico_Room* Room);


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_34_DELEGATE \
ONLINESUBSYSTEMPICO_API void FRoomCreateAndJoinPrivate2_DelegateWrapper(const FScriptDelegate& RoomCreateAndJoinPrivate2, bool bIsError, int32 ErrorCode, const FString& ErrorMessage, UPico_Room* Room);


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_35_DELEGATE \
ONLINESUBSYSTEMPICO_API void FRoomGet_DelegateWrapper(const FScriptDelegate& RoomGet, bool bIsError, int32 ErrorCode, const FString& ErrorMessage, UPico_Room* Room);


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_36_DELEGATE \
ONLINESUBSYSTEMPICO_API void FRoomGetCurrent_DelegateWrapper(const FScriptDelegate& RoomGetCurrent, bool bIsError, int32 ErrorCode, const FString& ErrorMessage, UPico_Room* Room);


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_37_DELEGATE \
ONLINESUBSYSTEMPICO_API void FRoomGetCurrentForUser_DelegateWrapper(const FScriptDelegate& RoomGetCurrentForUser, bool bIsError, int32 ErrorCode, const FString& ErrorMessage, UPico_Room* Room);


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_38_DELEGATE \
ONLINESUBSYSTEMPICO_API void FRoomGetInvitableUsers2_DelegateWrapper(const FScriptDelegate& RoomGetInvitableUsers2, bool bIsError, int32 ErrorCode, const FString& ErrorMessage, UPico_UserArray* UserArray);


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_39_DELEGATE \
ONLINESUBSYSTEMPICO_API void FRoomGetModeratedRooms_DelegateWrapper(const FScriptDelegate& RoomGetModeratedRooms, bool bIsError, int32 ErrorCode, const FString& ErrorMessage, UPico_RoomArray* RoomArray);


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_40_DELEGATE \
ONLINESUBSYSTEMPICO_API void FRoomInviteUser_DelegateWrapper(const FScriptDelegate& RoomInviteUser, bool bIsError, int32 ErrorCode, const FString& ErrorMessage, UPico_Room* Room);


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_41_DELEGATE \
ONLINESUBSYSTEMPICO_API void FRoomJoin2_DelegateWrapper(const FScriptDelegate& RoomJoin2, bool bIsError, int32 ErrorCode, const FString& ErrorMessage, UPico_Room* Room);


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_42_DELEGATE \
ONLINESUBSYSTEMPICO_API void FRoomKickUser_DelegateWrapper(const FScriptDelegate& RoomKickUser, bool bIsError, int32 ErrorCode, const FString& ErrorMessage, UPico_Room* Room);


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_43_DELEGATE \
ONLINESUBSYSTEMPICO_API void FRoomLeave_DelegateWrapper(const FScriptDelegate& RoomLeave, bool bIsError, int32 ErrorCode, const FString& ErrorMessage, UPico_Room* Room);


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_44_DELEGATE \
ONLINESUBSYSTEMPICO_API void FRoomSetDescription_DelegateWrapper(const FScriptDelegate& RoomSetDescription, bool bIsError, int32 ErrorCode, const FString& ErrorMessage, UPico_Room* Room);


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_45_DELEGATE \
ONLINESUBSYSTEMPICO_API void FRoomUpdateMembershipLockStatus_DelegateWrapper(const FScriptDelegate& RoomUpdateMembershipLockStatus, bool bIsError, int32 ErrorCode, const FString& ErrorMessage, UPico_Room* Room);


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_46_DELEGATE \
ONLINESUBSYSTEMPICO_API void FRoomUpdateOwner_DelegateWrapper(const FScriptDelegate& RoomUpdateOwner, bool bIsError, int32 ErrorCode, const FString& ErrorMessage);


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_47_DELEGATE \
ONLINESUBSYSTEMPICO_API void FRoomUpdatePrivateRoomJoinPolicy_DelegateWrapper(const FScriptDelegate& RoomUpdatePrivateRoomJoinPolicy, bool bIsError, int32 ErrorCode, const FString& ErrorMessage, UPico_Room* Room);


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_48_DELEGATE \
ONLINESUBSYSTEMPICO_API void FRoomJoinOrCreateNamedRoom_DelegateWrapper(const FScriptDelegate& RoomJoinOrCreateNamedRoom, bool bIsError, int32 ErrorCode, const FString& ErrorMessage, UPico_Room* Room);


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_49_DELEGATE \
ONLINESUBSYSTEMPICO_API void FRoomGetNamedRooms_DelegateWrapper(const FScriptDelegate& RoomGetNamedRooms, bool bIsError, int32 ErrorCode, const FString& ErrorMessage, UPico_RoomArray* RoomArray);


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_419_SPARSE_DATA
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_419_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_419_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_419_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetJoinOrCreateNamedRoomOptions); \
	DECLARE_FUNCTION(execGetCreatePrivateRoomOptions); \
	DECLARE_FUNCTION(execJoinOrCreateNamedRoom); \
	DECLARE_FUNCTION(execGetNamedRooms); \
	DECLARE_FUNCTION(execUpdatePrivateRoomJoinPolicy); \
	DECLARE_FUNCTION(execUpdateOwner); \
	DECLARE_FUNCTION(execUpdateMembershipLockStatus); \
	DECLARE_FUNCTION(execSetDescription); \
	DECLARE_FUNCTION(execLeave); \
	DECLARE_FUNCTION(execKickUser); \
	DECLARE_FUNCTION(execJoin2); \
	DECLARE_FUNCTION(execInviteUser); \
	DECLARE_FUNCTION(execGetModeratedRooms); \
	DECLARE_FUNCTION(execGetInvitableUsers2); \
	DECLARE_FUNCTION(execGetCurrentForUser); \
	DECLARE_FUNCTION(execGetCurrent); \
	DECLARE_FUNCTION(execGet); \
	DECLARE_FUNCTION(execCreateAndJoinPrivate2); \
	DECLARE_FUNCTION(execUpdateDataStore); \
	DECLARE_FUNCTION(execLaunchInvitableUserFlow);


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_419_ACCESSORS
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_419_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUOnlinePicoRoomFunction(); \
	friend struct Z_Construct_UClass_UOnlinePicoRoomFunction_Statics; \
public: \
	DECLARE_CLASS(UOnlinePicoRoomFunction, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OnlineSubsystemPico"), NO_API) \
	DECLARE_SERIALIZER(UOnlinePicoRoomFunction)


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_419_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UOnlinePicoRoomFunction(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UOnlinePicoRoomFunction(UOnlinePicoRoomFunction&&); \
	NO_API UOnlinePicoRoomFunction(const UOnlinePicoRoomFunction&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOnlinePicoRoomFunction); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOnlinePicoRoomFunction); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOnlinePicoRoomFunction) \
	NO_API virtual ~UOnlinePicoRoomFunction();


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_416_PROLOG
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_419_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_419_SPARSE_DATA \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_419_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_419_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_419_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_419_ACCESSORS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_419_INCLASS_NO_PURE_DECLS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_419_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<class UOnlinePicoRoomFunction>();

#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_640_SPARSE_DATA
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_640_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_640_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_640_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetDebugString); \
	DECLARE_FUNCTION(execGetRoomType); \
	DECLARE_FUNCTION(execGetPlayerNumber); \
	DECLARE_FUNCTION(execGetMaxUsers); \
	DECLARE_FUNCTION(execGetJoinability); \
	DECLARE_FUNCTION(execGetJoinPolicy); \
	DECLARE_FUNCTION(execGetIsMembershipLocked); \
	DECLARE_FUNCTION(execGetRoomID); \
	DECLARE_FUNCTION(execGetName); \
	DECLARE_FUNCTION(execGetDescription); \
	DECLARE_FUNCTION(execGetUsers); \
	DECLARE_FUNCTION(execGetOwner); \
	DECLARE_FUNCTION(execGetDataStore);


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_640_ACCESSORS
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_640_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPico_Room(); \
	friend struct Z_Construct_UClass_UPico_Room_Statics; \
public: \
	DECLARE_CLASS(UPico_Room, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OnlineSubsystemPico"), NO_API) \
	DECLARE_SERIALIZER(UPico_Room)


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_640_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPico_Room(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPico_Room(UPico_Room&&); \
	NO_API UPico_Room(const UPico_Room&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPico_Room); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPico_Room); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPico_Room) \
	NO_API virtual ~UPico_Room();


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_637_PROLOG
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_640_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_640_SPARSE_DATA \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_640_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_640_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_640_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_640_ACCESSORS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_640_INCLASS_NO_PURE_DECLS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_640_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<class UPico_Room>();

#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_734_SPARSE_DATA
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_734_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_734_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_734_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetDebugString); \
	DECLARE_FUNCTION(execGetPageSize); \
	DECLARE_FUNCTION(execGetPageIndex); \
	DECLARE_FUNCTION(execHasNextPage); \
	DECLARE_FUNCTION(execGetTotalSize); \
	DECLARE_FUNCTION(execGetSize); \
	DECLARE_FUNCTION(execGetElement);


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_734_ACCESSORS
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_734_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPico_RoomArray(); \
	friend struct Z_Construct_UClass_UPico_RoomArray_Statics; \
public: \
	DECLARE_CLASS(UPico_RoomArray, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OnlineSubsystemPico"), NO_API) \
	DECLARE_SERIALIZER(UPico_RoomArray)


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_734_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPico_RoomArray(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPico_RoomArray(UPico_RoomArray&&); \
	NO_API UPico_RoomArray(const UPico_RoomArray&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPico_RoomArray); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPico_RoomArray); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPico_RoomArray) \
	NO_API virtual ~UPico_RoomArray();


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_731_PROLOG
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_734_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_734_SPARSE_DATA \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_734_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_734_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_734_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_734_ACCESSORS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_734_INCLASS_NO_PURE_DECLS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h_734_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<class UPico_RoomArray>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Room_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
