// Fill out your copyright notice in the Description page of Project Settings.


#include "TicTacToeVsAIGameMode.h"

#include "GameButton.h"

ATicTacToeVsAIGameMode::ATicTacToeVsAIGameMode()
{
	OpponentPlayer = CreateDefaultSubobject<UOpponentAI>("Enemy Player AI");
}

void ATicTacToeVsAIGameMode::EndTurn()
{
	Super::EndTurn();

	// Call Ai's turn
	AITurn();
	
}

void ATicTacToeVsAIGameMode::AITurn()
{
	UpdateBoardSpaceArray();
	
	if(ActivePlayer == USpaceState::EActivePlayer::O)
	{
		FMove NextMove = OpponentPlayer->FindBestMove(BoardSpaceStates);
		if(BoardSpaces[NextMove.Row][NextMove.Column])
			BoardSpaces[NextMove.Row][NextMove.Column]->ActivateWidget();
	}
}
