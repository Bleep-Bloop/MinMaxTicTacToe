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

UTexture2D* ATicTacToeGameModeBase::GetActivePlayerImage() const
{
	if(ActivePlayer == EActivePlayer::X)
		return XImage;
	else
		return OImage;
	
}

void ATicTacToeGameModeBase::EndTurn()
{
	
	bool bIsPlayerX = ActivePlayer == EActivePlayer::X;
	ActivePlayer = (bIsPlayerX? ActivePlayer = EActivePlayer::O : ActivePlayer = EActivePlayer::X);

	// ToDo: Check for win

}
