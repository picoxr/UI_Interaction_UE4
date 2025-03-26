// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved.


#include "PXR_PICOXRPawn.h"
#include "PXR_HMDRuntimeSettings.h"


// Sets default values
APXR_PICOXRPawn::APXR_PICOXRPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APXR_PICOXRPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APXR_PICOXRPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}




// Called to bind functionality to input
void APXR_PICOXRPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UPICOXRSettings* Settings = GetMutableDefault<UPICOXRSettings>();
	if(Settings->IsValidLowLevel()&&Settings->bEnableAutoKeyMapping)
	{
		// This component belongs to the possessing Player Controller
		InputComponent->BindAction("ButtonA", IE_Pressed, this, &APXR_PICOXRPawn::ClickButtonAPressed);
		InputComponent->BindAction("ButtonA", IE_Released, this, &APXR_PICOXRPawn::ClickButtonAReleased);

		InputComponent->BindAction("ButtonB", IE_Pressed, this, &APXR_PICOXRPawn::ClickButtonBPressed);
		InputComponent->BindAction("ButtonB", IE_Released, this, &APXR_PICOXRPawn::ClickButtonBReleased);

		InputComponent->BindAction("ButtonX", IE_Pressed, this, &APXR_PICOXRPawn::ClickButtonXPressed);
		InputComponent->BindAction("ButtonX", IE_Released, this, &APXR_PICOXRPawn::ClickButtonXReleased);

		InputComponent->BindAction("ButtonY", IE_Pressed, this, &APXR_PICOXRPawn::ClickButtonYPressed);
		InputComponent->BindAction("ButtonY", IE_Released, this, &APXR_PICOXRPawn::ClickButtonYReleased);

		InputComponent->BindAction("ButtonLeftGrip", IE_Pressed, this, &APXR_PICOXRPawn::ClickButtonLeftGripPressed);
		InputComponent->BindAction("ButtonLeftGrip", IE_Released, this, &APXR_PICOXRPawn::ClickButtonLeftGripReleased);

		InputComponent->BindAction("ButtonLeftTrigger", IE_Pressed, this, &APXR_PICOXRPawn::ClickButtonLeftTriggerPressed);
		InputComponent->BindAction("ButtonLeftTrigger", IE_Released, this, &APXR_PICOXRPawn::ClickButtonLeftTriggerReleased);

		// This component belongs to the possessing Player Controller
		InputComponent->BindAction("ButtonATouched", IE_Pressed, this, &APXR_PICOXRPawn::ClickButtonATouchedPressed);
		InputComponent->BindAction("ButtonATouched", IE_Released, this, &APXR_PICOXRPawn::ClickButtonATouchedReleased);

		InputComponent->BindAction("ButtonBTouched", IE_Pressed, this, &APXR_PICOXRPawn::ClickButtonBTouchedPressed);
		InputComponent->BindAction("ButtonBTouched", IE_Released, this, &APXR_PICOXRPawn::ClickButtonBTouchedReleased);

		InputComponent->BindAction("ButtonXTouched", IE_Pressed, this, &APXR_PICOXRPawn::ClickButtonXTouchedPressed);
		InputComponent->BindAction("ButtonXTouched", IE_Released, this, &APXR_PICOXRPawn::ClickButtonXTouchedReleased);

		InputComponent->BindAction("ButtonYTouched", IE_Pressed, this, &APXR_PICOXRPawn::ClickButtonYTouchedPressed);
		InputComponent->BindAction("ButtonYTouched", IE_Released, this, &APXR_PICOXRPawn::ClickButtonYTouchedReleased);

		InputComponent->BindAction("ButtonLeftTriggerTouched", IE_Pressed, this, &APXR_PICOXRPawn::ClickButtonLeftTriggerTouchedPressed);
		InputComponent->BindAction("ButtonLeftTriggerTouched", IE_Released, this, &APXR_PICOXRPawn::ClickButtonLeftTriggerTouchedReleased);
		
		InputComponent->BindAction("ButtonRightTrigger", IE_Pressed, this, &APXR_PICOXRPawn::ClickButtonRightTriggerPressed);
		InputComponent->BindAction("ButtonRightTrigger", IE_Released, this, &APXR_PICOXRPawn::ClickButtonRightTriggerReleased);
		
		InputComponent->BindAction("ButtonRightTriggerTouched", IE_Pressed, this, &APXR_PICOXRPawn::ClickButtonRightTriggerTouchedPressed);
		InputComponent->BindAction("ButtonRightTriggerTouched", IE_Released, this, &APXR_PICOXRPawn::ClickButtonRightTriggerTouchedReleased);

		InputComponent->BindAction("ButtonLeftHome", IE_Pressed, this, &APXR_PICOXRPawn::ClickButtonLeftHomePressed);
		InputComponent->BindAction("ButtonLeftHome", IE_Released, this, &APXR_PICOXRPawn::ClickButtonLeftHomeReleased);

		InputComponent->BindAction("ButtonLeftMenu", IE_Pressed, this, &APXR_PICOXRPawn::ClickButtonLeftMenuPressed);
		InputComponent->BindAction("ButtonLeftMenu", IE_Released, this, &APXR_PICOXRPawn::ClickButtonLeftMenuReleased);
		
		InputComponent->BindAction("ButtonRightGrip", IE_Pressed, this, &APXR_PICOXRPawn::ClickButtonRightGripPressed);
		InputComponent->BindAction("ButtonRightGrip", IE_Released, this, &APXR_PICOXRPawn::ClickButtonRightGripReleased);
		
		InputComponent->BindAction("ButtonRightHome", IE_Pressed, this, &APXR_PICOXRPawn::ClickButtonRightHomePressed);
		InputComponent->BindAction("ButtonRightHome", IE_Released, this, &APXR_PICOXRPawn::ClickButtonRightHomeReleased);

		InputComponent->BindAction("ButtonRightSystem", IE_Pressed, this, &APXR_PICOXRPawn::ClickButtonRightSystemPressed);
		InputComponent->BindAction("ButtonRightSystem", IE_Released, this, &APXR_PICOXRPawn::ClickButtonRightSystemReleased);

		InputComponent->BindAction("LeftJoyStickTouched", IE_Pressed, this, &APXR_PICOXRPawn::ClickButtonLeftJoyStickTouchedPressed);
		InputComponent->BindAction("LeftJoyStickTouched", IE_Released, this, &APXR_PICOXRPawn::ClickButtonLeftJoyStickTouchedReleased);

		InputComponent->BindAction("RightJoyStickTouched", IE_Pressed, this, &APXR_PICOXRPawn::ClickButtonRightJoyStickTouchedPressed);
		InputComponent->BindAction("RightJoyStickTouched", IE_Released, this, &APXR_PICOXRPawn::ClickButtonRightJoyStickTouchedReleased);
		
		InputComponent->BindAxis("LeftTriggerAxis", this, &APXR_PICOXRPawn::LeftTriggerAxisVal);
		InputComponent->BindAxis("LeftGripAxis", this, &APXR_PICOXRPawn::LeftGripAxisVal);

		InputComponent->BindAxis("RightTriggerAxis", this, &APXR_PICOXRPawn::RightTriggerAxisVal);
		InputComponent->BindAxis("RightGripAxis", this, &APXR_PICOXRPawn::RightGripAxisVal);

		InputComponent->BindAxis("LeftJoyStickXAxis", this, &APXR_PICOXRPawn::LeftJoyStickXVal);
		InputComponent->BindAxis("LeftJoyStickYAxis", this, &APXR_PICOXRPawn::LeftJoyStickYVal);
		
		InputComponent->BindAxis("RightJoyStickXAxis", this, &APXR_PICOXRPawn::RightJoyStickXVal);
		InputComponent->BindAxis("RightJoyStickYAxis", this, &APXR_PICOXRPawn::RightJoyStickYVal);



	}
}

void APXR_PICOXRPawn::ClickButtonAPressed()
{
	this->AButtonPressed=true;
}

void APXR_PICOXRPawn::ClickButtonAReleased()
{
	this->AButtonPressed=false;
}

void APXR_PICOXRPawn::ClickButtonBPressed()
{
	this->BButtonPressed=true;
}

void APXR_PICOXRPawn::ClickButtonBReleased()
{
	this->BButtonPressed=false;
}

void APXR_PICOXRPawn::ClickButtonXPressed()
{
	this->XButtonPressed=true;
}

void APXR_PICOXRPawn::ClickButtonXReleased()
{
	this->XButtonPressed=false;
}

void APXR_PICOXRPawn::ClickButtonYPressed()
{
	this->YButtonPressed=true;
}

void APXR_PICOXRPawn::ClickButtonYReleased()
{
	this->YButtonPressed=false;
}

void APXR_PICOXRPawn::ClickButtonATouchedPressed()
{
	this->AButtonTouched=true;
}

void APXR_PICOXRPawn::ClickButtonATouchedReleased()
{
	this->AButtonTouched=false;
}

void APXR_PICOXRPawn::ClickButtonBTouchedPressed()
{
	this->BButtonTouched=true;
}

void APXR_PICOXRPawn::ClickButtonBTouchedReleased()
{
	this->BButtonTouched=false;
}

void APXR_PICOXRPawn::ClickButtonXTouchedPressed()
{
	this->XButtonTouched=true;
}

void APXR_PICOXRPawn::ClickButtonXTouchedReleased()
{
	this->XButtonTouched=false;
}

void APXR_PICOXRPawn::ClickButtonYTouchedPressed()
{
	this->YButtonTouched=true;
}

void APXR_PICOXRPawn::ClickButtonYTouchedReleased()
{
	this->YButtonTouched=false;
}

void APXR_PICOXRPawn::ClickButtonLeftHomePressed()
{
	this->LeftHomePressed=true;
}

void APXR_PICOXRPawn::ClickButtonLeftHomeReleased()
{
	this->LeftHomePressed=false;
}

void APXR_PICOXRPawn::ClickButtonLeftMenuPressed()
{
	this->LeftMenuPressed=true;
}

void APXR_PICOXRPawn::ClickButtonLeftMenuReleased()
{
	this->LeftMenuPressed=false;
}

void APXR_PICOXRPawn::ClickButtonRightHomePressed()
{
	this->RightHomePressed=true;
}

void APXR_PICOXRPawn::ClickButtonRightHomeReleased()
{
	this->RightHomePressed=false;
}

void APXR_PICOXRPawn::ClickButtonRightSystemPressed()
{
	this->RightSystemPressed=true;
}

void APXR_PICOXRPawn::ClickButtonRightSystemReleased()
{
	this->RightSystemPressed=false;
}

void APXR_PICOXRPawn::ClickButtonLeftTriggerPressed()
{
	this->LeftTriggerPressed=true;
}

void APXR_PICOXRPawn::ClickButtonLeftTriggerReleased()
{
	this->LeftTriggerPressed=false;
}

void APXR_PICOXRPawn::ClickButtonLeftGripPressed()
{
	this->LeftGripPressed=true;
}

void APXR_PICOXRPawn::ClickButtonLeftGripReleased()
{
	this->LeftGripPressed=false;
}

void APXR_PICOXRPawn::ClickButtonRightTriggerPressed()
{
	this->RightTriggerPressed=true;
}

void APXR_PICOXRPawn::ClickButtonRightTriggerReleased()
{
	this->RightTriggerPressed=false;
}

void APXR_PICOXRPawn::ClickButtonRightGripPressed()
{
	this->RightGripPressed=true;
}

void APXR_PICOXRPawn::ClickButtonRightGripReleased()
{
	this->RightGripPressed=false;
}

void APXR_PICOXRPawn::ClickButtonLeftTriggerTouchedPressed()
{
	this->LeftTriggerTouched =true;
}

void APXR_PICOXRPawn::ClickButtonLeftTriggerTouchedReleased()
{
	this->LeftTriggerTouched =false;
}

void APXR_PICOXRPawn::ClickButtonLeftGripTouchedPressed()
{
	this->LeftGripTouched =true;
}

void APXR_PICOXRPawn::ClickButtonLeftGripTouchedReleased()
{
	this->LeftGripTouched =false;
}

void APXR_PICOXRPawn::ClickButtonRightTriggerTouchedPressed()
{
	this->RightTriggerTouched=true;
}

void APXR_PICOXRPawn::ClickButtonRightTriggerTouchedReleased()
{
	this->RightTriggerTouched=false;
}

void APXR_PICOXRPawn::ClickButtonRightGripTouchedPressed()
{
	this->RightGripTouched =true;
}

void APXR_PICOXRPawn::ClickButtonRightGripTouchedReleased()
{
	this->RightGripTouched =false;
}

void APXR_PICOXRPawn::ClickButtonRightJoyStickTouchedPressed()
{
	this->RightJoyStickTouched =true;
}

void APXR_PICOXRPawn::ClickButtonRightJoyStickTouchedReleased()
{
	this->RightJoyStickTouched =false;
}

void APXR_PICOXRPawn::ClickButtonLeftJoyStickTouchedPressed()
{
	this->LeftJoyStickTouched =true;
}

void APXR_PICOXRPawn::ClickButtonLeftJoyStickTouchedReleased()
{
	this->LeftJoyStickTouched =false;
}

void APXR_PICOXRPawn::LeftTriggerAxisVal(float Val)
{
	this->LeftTriggerAxis=Val;
}

void APXR_PICOXRPawn::LeftGripAxisVal(float Val)
{
	this->LeftGripAxis=Val;		
}

void APXR_PICOXRPawn::LeftJoyStickXVal(float Val)
{
	this->LeftJoyStickXAxis=Val;
}

void APXR_PICOXRPawn::LeftJoyStickYVal(float Val)
{
	this->LeftJoyStickYAxis=Val;
}

void APXR_PICOXRPawn::RightTriggerAxisVal(float Val)
{
	this->RightTriggerAxis=Val;
}

void APXR_PICOXRPawn::RightGripAxisVal(float Val)
{
	this->RightGripAxis=Val;
}

void APXR_PICOXRPawn::RightJoyStickXVal(float Val)
{
	this->RightJoyStickXAxis=Val;
}

void APXR_PICOXRPawn::RightJoyStickYVal(float Val)
{
	this->RightJoyStickYAxis=Val;
}


