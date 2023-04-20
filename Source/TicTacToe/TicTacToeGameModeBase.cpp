// Copyright Epic Games, Inc. All Rights Reserved.


#include "TicTacToeGameModeBase.h"

void ATicTacToeGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, "ATicTacToeGameModeBase::BeginPlay()");
	ActivePlayer = EActivePlayer::X;

	
	
}
