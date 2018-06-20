// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "GladiatorArenaGameMode.h"
#include "GladiatorArenaPlayerController.h"
#include "GladiatorArenaCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGladiatorArenaGameMode::AGladiatorArenaGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AGladiatorArenaPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}