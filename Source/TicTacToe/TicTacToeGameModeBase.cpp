// Copyright Epic Games, Inc. All Rights Reserved.


#include "TicTacToeGameModeBase.h"

#include "GameButton.h"
#include "BehaviorTree/BehaviorTreeTypes.h"

ATicTacToeGameModeBase::ATicTacToeGameModeBase()
{
	OpponentPlayer = CreateDefaultSubobject<UOpponentAI>("Enemy Player AI");
}

void ATicTacToeGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	
	// Start game with PlayerX
	ActivePlayer = USpaceState::EActivePlayer::X;
	
	// Setting Cursor -> ToDo: Shorten
	if(GetWorld()->GetFirstPlayerController())
	{
		GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
	}
	
}

USpaceState::EActivePlayer ATicTacToeGameModeBase::GetActivePlayer() const
{
	return ActivePlayer;
}

UTexture2D* ATicTacToeGameModeBase::GetActivePlayerImage() const
{
	if(ActivePlayer == USpaceState::EActivePlayer::X)
		return XImage;
	else
		return OImage;
	
}

// Called when a GameButton ActivateWidget() called
void ATicTacToeGameModeBase::EndTurn()
{

	// Update Array holding BoardSpaces (used by OpponentAI)
	UpdateBoardSpaceArray();
	
	CheckForWinner();

	// ToDo: Re-Write
	bool bIsPlayerX = (ActivePlayer == USpaceState::EActivePlayer::X); 
	ActivePlayer = (bIsPlayerX? ActivePlayer = USpaceState::EActivePlayer::O : ActivePlayer = USpaceState::EActivePlayer::X);
	

	// Find AI's move
	if(ActivePlayer == USpaceState::EActivePlayer::O)
	{
		FMove NextMove = OpponentPlayer->FindBestMove(BoardSpaceStates);
		if(BoardSpaces[NextMove.Row][NextMove.Column])
			BoardSpaces[NextMove.Row][NextMove.Column]->ActivateWidget();
	}
	
}


void ATicTacToeGameModeBase::CheckForWinner() const
{

	// Check Horizontal
	for(int i = 0; i < 3; i++)
	{
		if(BoardSpaces[i][0]->GetCurrentActivePlayer() == BoardSpaces[i][1]->GetCurrentActivePlayer() && BoardSpaces[i][1]->GetCurrentActivePlayer() == BoardSpaces[i][2]->GetCurrentActivePlayer())
		{
			if(BoardSpaces[i][1]->GetCurrentActivePlayer() == USpaceState::EActivePlayer::X)
			{
				GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green,"X Horizontal");
			}
			else if(BoardSpaces[i][1]->GetCurrentActivePlayer() == USpaceState::EActivePlayer::O)
			{
				GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green,"O Horizontal");
			}
		}
	}

	// Check Vertical
	for(int i = 0; i < 3; i++)
	{
		if(BoardSpaces[0][i]->GetCurrentActivePlayer() == BoardSpaces[1][i]->GetCurrentActivePlayer() && BoardSpaces[1][i]->GetCurrentActivePlayer() == BoardSpaces[2][i]->GetCurrentActivePlayer())
		{
			if(BoardSpaces[1][i]->GetCurrentActivePlayer() == USpaceState::EActivePlayer::X)
			{
				GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green,"X WINS Vertical");
			}
			else if(BoardSpaces[1][i]->GetCurrentActivePlayer() == USpaceState::EActivePlayer::O)
			{
				GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green,"O WINS Vertical");
			}
		}
	}
	
	// Check Diagonal Top Left -> Bottom Right
	if(BoardSpaces[0][0]->GetCurrentActivePlayer() == BoardSpaces[1][1]->GetCurrentActivePlayer() && BoardSpaces[1][1]->GetCurrentActivePlayer() == BoardSpaces[2][2]->GetCurrentActivePlayer())
	{
		if(BoardSpaces[0][0]->GetCurrentActivePlayer() == USpaceState::EActivePlayer::X)
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green,"X WINS Diagonal Top Left -> Bottom Right");
		}
		else if(BoardSpaces[0][0]->GetCurrentActivePlayer() == USpaceState::EActivePlayer::O)
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green,"O WINS Diagonal Top Left -> Bottom Right");
		}
	}

	// Check Diagonal Bottom Left -> Top Right
	if(BoardSpaces[2][0]->GetCurrentActivePlayer() == BoardSpaces[1][1]->GetCurrentActivePlayer() && BoardSpaces[1][1]->GetCurrentActivePlayer() == BoardSpaces[0][2]->GetCurrentActivePlayer())
	{
		if(BoardSpaces[2][0]->GetCurrentActivePlayer() == USpaceState::EActivePlayer::X)
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green,"X WINS Diagonal Bottom Left -> Top Right");
		}
		else if(BoardSpaces[2][0]->GetCurrentActivePlayer() == USpaceState::EActivePlayer::O)
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green,"O WINS Diagonal Bottom Left -> Top Right");
		}
	}

}

void ATicTacToeGameModeBase::UpdateBoardSpaceArray()
{
	BoardSpaceStates[0][0] = BoardSpaces[0][0]->GetCurrentActivePlayer();
	BoardSpaceStates[0][1] = BoardSpaces[0][1]->GetCurrentActivePlayer();
	BoardSpaceStates[0][2] = BoardSpaces[0][2]->GetCurrentActivePlayer();
	BoardSpaceStates[1][0] = BoardSpaces[1][0]->GetCurrentActivePlayer();
	BoardSpaceStates[1][1] = BoardSpaces[1][1]->GetCurrentActivePlayer();
	BoardSpaceStates[1][2] = BoardSpaces[1][2]->GetCurrentActivePlayer();
	BoardSpaceStates[2][0] = BoardSpaces[2][0]->GetCurrentActivePlayer();
	BoardSpaceStates[2][1] = BoardSpaces[2][1]->GetCurrentActivePlayer();
	BoardSpaceStates[2][2] = BoardSpaces[2][2]->GetCurrentActivePlayer();
}

