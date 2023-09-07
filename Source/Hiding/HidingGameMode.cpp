// Copyright Epic Games, Inc. All Rights Reserved.

#include "HidingGameMode.h"
#include "HidingCharacter.h"
#include "UObject/ConstructorHelpers.h"

AHidingGameMode::AHidingGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
