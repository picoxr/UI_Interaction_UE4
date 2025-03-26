// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PXR_PICOXRPawn.generated.h"

UCLASS()
class APXR_PICOXRPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APXR_PICOXRPawn();
	
	UPROPERTY(BlueprintReadOnly, Category = "PICOPawn")
	float RightTriggerAxis;
	UPROPERTY(BlueprintReadOnly, Category = "PICOPawn")
	float RightGripAxis;
	UPROPERTY(BlueprintReadOnly, Category = "PICOPawn")
	float RightJoyStickXAxis;
	UPROPERTY(BlueprintReadOnly, Category = "PICOPawn")
	float RightJoyStickYAxis;
	UPROPERTY(BlueprintReadOnly, Category = "PICOPawn")
	float LeftTriggerAxis;
	UPROPERTY(BlueprintReadOnly, Category = "PICOPawn")
	float LeftGripAxis;
	UPROPERTY(BlueprintReadOnly, Category = "PICOPawn")
	float LeftJoyStickXAxis;
	UPROPERTY(BlueprintReadOnly, Category = "PICOPawn")
	float LeftJoyStickYAxis;
	
	UPROPERTY(BlueprintReadOnly, Category = "PICOPawn")
	bool AButtonPressed;
	UPROPERTY(BlueprintReadOnly, Category = "PICOPawn")
	bool BButtonPressed;
	UPROPERTY(BlueprintReadOnly, Category = "PICOPawn")
	bool XButtonPressed;
	UPROPERTY(BlueprintReadOnly, Category = "PICOPawn")
	bool YButtonPressed;

	UPROPERTY(BlueprintReadOnly, Category = "PICOPawn")
	bool AButtonTouched;
	UPROPERTY(BlueprintReadOnly, Category = "PICOPawn")
	bool BButtonTouched;
	UPROPERTY(BlueprintReadOnly, Category = "PICOPawn")
	bool XButtonTouched;
	UPROPERTY(BlueprintReadOnly, Category = "PICOPawn")
	bool YButtonTouched;
	
	UPROPERTY(BlueprintReadOnly, Category = "PICOPawn")
	bool RightHomePressed;
	UPROPERTY(BlueprintReadOnly, Category = "PICOPawn")
	bool RightSystemPressed;
	UPROPERTY(BlueprintReadOnly, Category = "PICOPawn")
	bool LeftHomePressed;
	UPROPERTY(BlueprintReadOnly, Category = "PICOPawn")
	bool LeftMenuPressed;
	
	UPROPERTY(BlueprintReadOnly, Category = "PICOPawn")
	bool RightTriggerPressed;
	UPROPERTY(BlueprintReadOnly, Category = "PICOPawn")
	bool RightGripPressed;
	UPROPERTY(BlueprintReadOnly, Category = "PICOPawn")
	bool LeftTriggerPressed;
	UPROPERTY(BlueprintReadOnly, Category = "PICOPawn")
	bool LeftGripPressed;

	UPROPERTY(BlueprintReadOnly, Category = "PICOPawn")
	bool RightTriggerTouched;
	UPROPERTY(BlueprintReadOnly, Category = "PICOPawn")
	bool RightGripTouched;
	UPROPERTY(BlueprintReadOnly, Category = "PICOPawn")
	bool LeftTriggerTouched;
	UPROPERTY(BlueprintReadOnly, Category = "PICOPawn")
	bool LeftGripTouched;

	UPROPERTY(BlueprintReadOnly, Category = "PICOPawn")
	bool LeftJoyStickTouched;
	UPROPERTY(BlueprintReadOnly, Category = "PICOPawn")
	bool RightJoyStickTouched;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
private:
	void ClickButtonAPressed();
	void ClickButtonAReleased();
	void ClickButtonBPressed();
	void ClickButtonBReleased();
	
	void ClickButtonXPressed();
	void ClickButtonXReleased();
	void ClickButtonYPressed();
	void ClickButtonYReleased();

	void ClickButtonATouchedPressed();
	void ClickButtonATouchedReleased();
	void ClickButtonBTouchedPressed();
	void ClickButtonBTouchedReleased();
	
	void ClickButtonXTouchedPressed();
	void ClickButtonXTouchedReleased();
	void ClickButtonYTouchedPressed();
	void ClickButtonYTouchedReleased();
	
	void ClickButtonLeftHomePressed();
	void ClickButtonLeftHomeReleased();
	void ClickButtonLeftMenuPressed();
	void ClickButtonLeftMenuReleased();
	
	void ClickButtonRightHomePressed();
	void ClickButtonRightHomeReleased();
	void ClickButtonRightSystemPressed();
	void ClickButtonRightSystemReleased();
	
	void ClickButtonLeftTriggerPressed();
	void ClickButtonLeftTriggerReleased();
	void ClickButtonLeftGripPressed();
	void ClickButtonLeftGripReleased();
	
	void ClickButtonRightTriggerPressed();
	void ClickButtonRightTriggerReleased();
	void ClickButtonRightGripPressed();
	void ClickButtonRightGripReleased();

	void ClickButtonLeftTriggerTouchedPressed();
	void ClickButtonLeftTriggerTouchedReleased();
	void ClickButtonLeftGripTouchedPressed();
	void ClickButtonLeftGripTouchedReleased();
	
	void ClickButtonRightTriggerTouchedPressed();
	void ClickButtonRightTriggerTouchedReleased();
	void ClickButtonRightGripTouchedPressed();
	void ClickButtonRightGripTouchedReleased();
	
	void ClickButtonRightJoyStickTouchedPressed();
	void ClickButtonRightJoyStickTouchedReleased();
	void ClickButtonLeftJoyStickTouchedPressed();
	void ClickButtonLeftJoyStickTouchedReleased();
	
	void LeftTriggerAxisVal(float Val);
	void LeftGripAxisVal(float Val);
	void LeftJoyStickXVal(float Val);
	void LeftJoyStickYVal(float Val);
	
	void RightTriggerAxisVal(float Val);
	void RightGripAxisVal(float Val);
	void RightJoyStickXVal(float Val);
	void RightJoyStickYVal(float Val);


};
