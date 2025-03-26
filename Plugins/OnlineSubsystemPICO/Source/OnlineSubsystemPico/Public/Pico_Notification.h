// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 
#pragma once

#include "CoreMinimal.h"
#include "OnlineSubsystemPico.h"
#include "UObject/NoExportTypes.h"
#include "PPF_Platform.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Pico_Notification.generated.h"
//

DECLARE_LOG_CATEGORY_EXTERN(PicoNotification, Log, All);

class UPico_RoomInviteNotification;
class UPico_RoomInviteNotificationArray;


/**
 * 
*/
// DECLARE_MULTICAST_DELEGATE_FourParams(FRoomUpdateNotify, bool, /*bIsError*/ int, /*ErrorCode*/ const FString&, /*ErrorMessage*/ UPico_Room* /*Room*/);
//
// FRoom_GetNextRoomArrayPage

DECLARE_DYNAMIC_DELEGATE_FourParams(FNotificationRoomInviteNotifications, bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_RoomInviteNotificationArray*, RoomInviteNotificationArray);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FNotificationMarkAsRead, bool, bIsError, int, ErrorCode, const FString&, ErrorMessage);

/** @addtogroup Function Function
 *  This is the Function group
 *  @{
 */

/** @defgroup Notification Notification
 *  This is the Notification group
 *  @{
 */

/// @brief FPicoNotificationInterface class.
class ONLINESUBSYSTEMPICO_API FPicoNotificationInterface
{
private:
	FOnlineSubsystemPico& PicoSubsystem;

public:
	FPicoNotificationInterface(FOnlineSubsystemPico& InSubsystem);
	~FPicoNotificationInterface();

	FNotificationRoomInviteNotifications RoomInviteNotificationsDelegate;
	FNotificationMarkAsRead MarkAsReadDelegate;
	
	/// <summary>Gets a list of all pending room invites for your app. For example, notifications that may have been sent before the user launches your app.</summary>
	/// <param name="PageIdx">Defines which page of pending room invites to return. The first page index is `0`.</param>
	/// <param name="PageSize">Defines the number of pending room invites returned on each page.</param>
    /// <param name="OnRoomInviteNotificationsCallback">Will be executed when the request has been completed.    
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_RoomInviteNotificationArray *, RoomInviteNotificationArray).</param>
	/// <returns>Bool:
	/// <ul>
	/// <li>`true`: Sending request succeeded</li>
	/// <li>`false`: Sending request failed</li>
	/// </ul>
	/// </returns>  
    bool GetRoomInviteNotifications(int PageIdx, int PageSize, FNotificationRoomInviteNotifications OnRoomInviteNotificationsCallback);


	/// <summary>Marks a notification as read.</summary>
	/// <param name="NotificationID">The ID of the notificaiton to mark.</param>
    /// <param name="OnMarkAsReadCallback">Will be executed when the request has been completed.     
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage).</param>
	/// <returns>Bool:
	/// <ul>
	/// <li>`true`: Sending request succeeded</li>
	/// <li>`false`: Sending request failed</li>
	/// </ul>
	/// </returns>
    bool MarkAsRead(const FString& NotificationID, FNotificationMarkAsRead OnMarkAsReadCallback);
private:
};

/** @} */
/** @} */


/** @addtogroup BlueprintFunction BlueprintFunction
 *  This is the BlueprintFunction group
 *  @{
 */

/** @defgroup BP_Room BP_Room
 *  This is the BP_Room group
 *  @{
 */

/// @brief OnlinePicoRoom Blueprint Function class.
UCLASS()
class ONLINESUBSYSTEMPICO_API UOnlinePicoNotificationFunction : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()


public:

	/// <summary>Gets a list of all pending room invites for your app. For example, notifications that may have been sent before the user launches your app.</summary>
	/// <param name ="WorldContextObject">Used to get the information about the current world.</param>
	/// <param name="PageIdx">Defines which page of pending room invites to return. The first page index is `0`.</param>
	/// <param name="PageSize">Defines the number of pending room invites returned on each page.</param>
    /// <param name="OnRoomInviteNotificationsCallback">Will be executed when the request has been completed.     
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_RoomInviteNotificationArray *, RoomInviteNotificationArray).</param>
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Notification")
	static void GetRoomInviteNotifications(UObject* WorldContextObject, int PageIdx, int PageSize, FNotificationRoomInviteNotifications OnRoomInviteNotificationsCallback);


	/// <summary>Marks a notification as read.</summary>
	/// <param name ="WorldContextObject">Used to get the information about the current world.</param>
	/// <param name="NotificationID">The ID of the notificaiton to mark.</param>
    /// <param name="OnMarkAsReadCallback">Will be executed when the request has been completed.     
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage).</param>
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Notification")
	static void MarkAsRead(UObject* WorldContextObject, const FString& NotificationID, FNotificationMarkAsRead OnMarkAsReadCallback);
};

/// @brief UPico_RoomInviteNotification class.
UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_RoomInviteNotification : public UObject
{
	GENERATED_BODY()

private:
	
	ppfID ID = 0;

	ppfID RoomID = 0;

	FString SenderID = FString();

	unsigned long long SentTime;

public:
	void InitParams(ppfRoomInviteNotificationHandle InRoomInviteNotificationHandle);
	
	/** @brief Invitation ID. */
	UFUNCTION(BlueprintPure, Category = "Pico Platform|Notification|Room Invite Notification")
	FString GetID();

	/** @brief Room ID. */
	UFUNCTION(BlueprintPure, Category = "Pico Platform|Notification|Room Invite Notification")
	FString GetRoomID();
	
	/** @brief Inviter's user ID. */
	UFUNCTION(BlueprintPure, Category = "Pico Platform|Notification|Room Invite Notification")
	FString GetSenderID();
	
	/** @brief The time when the invitation is sent as string. */
	UFUNCTION(BlueprintPure, Category = "Pico Platform|Notification|Room Invite Notification")
	FString GetSentTime();

	/** @brief The time when the invitation is sent. */
	UFUNCTION(BlueprintPure, Category = "Pico Platform|Notification|Room Invite Notification")
	FDateTime GetSentDateTime();

	UFUNCTION(BlueprintPure, Category = "Pico Platform|Notification|Room Invite Notification")
	FString GetDebugString();
};

/// @brief UPico_RoomInviteNotificationArray class.
UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_RoomInviteNotificationArray : public UObject
{
	GENERATED_BODY()
private:
	UPROPERTY()
	TArray<UPico_RoomInviteNotification*> RoomInviteNotificationArray;
	int32 Size = 0;
	int32 TotalSize = 0;
	bool bHasNextPage;
public:
	void InitParams(ppfRoomInviteNotificationArrayHandle InRoomInviteNotificationArrayHandle);
	
	/** @brief Get RoomInviteNotificationArray element form Index.*/
	UFUNCTION(BlueprintPure, Category = "Pico Platform|Notification|Room Invite Notification Array")
	UPico_RoomInviteNotification* GetElement(int32 Index);
	
	
	/** @brief Get the size of RoomInviteNotificationArray .*/
	UFUNCTION(BlueprintPure, Category = "Pico Platform|Notification|Room Invite Notification Array")
	int32 GetSize();
    
	UFUNCTION(BlueprintPure, Category = "Pico Platform|Notification|Room Invite Notification Array")
	int32 GetTotalSize();
	
	/** @brief Get whether the list has the next page.*/
	UFUNCTION(BlueprintPure, Category = "Pico Platform|Notification|Room Invite Notification Array")
	bool HasNextPage();
	
	UFUNCTION(BlueprintPure, Category = "Pico Platform|Notification|Room Invite Notification Array")
	FString GetDebugString();
};
