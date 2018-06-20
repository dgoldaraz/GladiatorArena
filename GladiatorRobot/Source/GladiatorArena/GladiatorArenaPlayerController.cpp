// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "GladiatorArenaPlayerController.h"
#include "AI/Navigation/NavigationSystem.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "GladiatorArenaCharacter.h"

AGladiatorArenaPlayerController::AGladiatorArenaPlayerController()
{
	//bShowMouseCursor = true;
	//DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void AGladiatorArenaPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

//	// keep updating the destination every tick while desired
//	if (bMoveToMouseCursor)
//	{
//		MoveToMouseCursor();
//	}
}

void AGladiatorArenaPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	//InputComponent->BindAction("SetDestination", IE_Pressed, this, &AGladiatorArenaPlayerController::OnSetDestinationPressed);
	//InputComponent->BindAction("SetDestination", IE_Released, this, &AGladiatorArenaPlayerController::OnSetDestinationReleased);

	//// support touch devices 
	//InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &AGladiatorArenaPlayerController::MoveToTouchLocation);
	//InputComponent->BindTouch(EInputEvent::IE_Repeat, this, &AGladiatorArenaPlayerController::MoveToTouchLocation);

	//InputComponent->BindAction("ResetVR", IE_Pressed, this, &AGladiatorArenaPlayerController::OnResetVR);

	//Add Keyboard controllers
	InputComponent->BindAxis("MoveForward", this, &AGladiatorArenaPlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AGladiatorArenaPlayerController::MoveRight);
}

//void AGladiatorArenaPlayerController::OnResetVR()
//{
//	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
//}
//
//void AGladiatorArenaPlayerController::MoveToMouseCursor()
//{
//	if (UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled())
//	{
//		if (AGladiatorArenaCharacter* MyPawn = Cast<AGladiatorArenaCharacter>(GetPawn()))
//		{
//			if (MyPawn->GetCursorToWorld())
//			{
//				UNavigationSystem::SimpleMoveToLocation(this, MyPawn->GetCursorToWorld()->GetComponentLocation());
//			}
//		}
//	}
//	else
//	{
//		// Trace to see what is under the mouse cursor
//		FHitResult Hit;
//		GetHitResultUnderCursor(ECC_Visibility, false, Hit);
//
//		if (Hit.bBlockingHit)
//		{
//			// We hit something, move there
//			SetNewMoveDestination(Hit.ImpactPoint);
//		}
//	}
//}
//
//void AGladiatorArenaPlayerController::MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location)
//{
//	FVector2D ScreenSpaceLocation(Location);
//
//	// Trace to see what is under the touch location
//	FHitResult HitResult;
//	GetHitResultAtScreenPosition(ScreenSpaceLocation, CurrentClickTraceChannel, true, HitResult);
//	if (HitResult.bBlockingHit)
//	{
//		// We hit something, move there
//		SetNewMoveDestination(HitResult.ImpactPoint);
//	}
//}
//
//void AGladiatorArenaPlayerController::SetNewMoveDestination(const FVector DestLocation)
//{
//	APawn* const MyPawn = GetPawn();
//	if (MyPawn)
//	{
//		UNavigationSystem* const NavSys = GetWorld()->GetNavigationSystem();
//		float const Distance = FVector::Dist(DestLocation, MyPawn->GetActorLocation());
//
//		// We need to issue move command only if far enough in order for walk animation to play correctly
//		if (NavSys && (Distance > 120.0f))
//		{
//			NavSys->SimpleMoveToLocation(this, DestLocation);
//		}
//	}
//}
//
//void AGladiatorArenaPlayerController::OnSetDestinationPressed()
//{
//	// set flag to keep updating destination until released
//	bMoveToMouseCursor = true;
//}
//
//void AGladiatorArenaPlayerController::OnSetDestinationReleased()
//{
//	// clear flag to indicate we should stop updating the destination
//	bMoveToMouseCursor = false;
//}

void AGladiatorArenaPlayerController::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		GetPawn()->AddMovementInput(GetActorForwardVector(), Value);
	}
}


void AGladiatorArenaPlayerController::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		GetPawn()->AddMovementInput(GetActorRightVector(), Value);
	}
}
