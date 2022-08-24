// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProjectRadiateGameMode.h"
#include "ProjectRadiateHUD.h"
#include "ProjectRadiateCharacter.h"
#include "UObject/ConstructorHelpers.h"

AProjectRadiateGameMode::AProjectRadiateGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AProjectRadiateHUD::StaticClass();
}
