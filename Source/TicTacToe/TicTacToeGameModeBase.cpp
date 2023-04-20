// Copyright Epic Games, Inc. All Rights Reserved.


#include "TicTacToeGameModeBase.h"

#include "BehaviorTree/BehaviorTreeTypes.h"

void ATicTacToeGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	
	ActivePlayer = EActivePlayer::X;
	
}

EActivePlayer ATicTacToeGameModeBase::GetActivePlayer() const
{
	return ActivePlayer;
}
