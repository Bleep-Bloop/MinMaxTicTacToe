// Copyright Epic Games, Inc. All Rights Reserved.


#include "TicTacToeGameModeBase.h"

#include "GameButton.h"
#include "BehaviorTree/BehaviorTreeTypes.h"

void ATicTacToeGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	
	// Start game with PlayerX
	ActivePlayer = EActivePlayer::X;

	// Setting Cursor -> ToDo: Shorten
	if(GetWorld()->GetFirstPlayerController())
	{
		GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
	}
	
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

	// ToDo:
	bool bIsPlayerX = (ActivePlayer == EActivePlayer::X);
	ActivePlayer = (bIsPlayerX? ActivePlayer = EActivePlayer::O : ActivePlayer = EActivePlayer::X);
	
	CheckForWinner();

}


void ATicTacToeGameModeBase::CheckForWinner() const
{

	// Check Horizontal
	for(int i = 0; i < 3; i++)
	{
		if(BoardSpaces[i][0]->GetOwnedPlayer() == BoardSpaces[i][1]->GetOwnedPlayer() && BoardSpaces[i][1]->GetOwnedPlayer() == BoardSpaces[i][2]->GetOwnedPlayer())
		{
			if(BoardSpaces[i][1]->GetOwnedPlayer() == EActivePlayer::X)
			{
				GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green,"X Horizontal");
			}
			else if(BoardSpaces[i][1]->GetOwnedPlayer() == EActivePlayer::O)
			{
				GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green,"O Horizontal");
			}
		}
	}

	// Check Vertical
	for(int i = 0; i < 3; i++)
	{
		if(BoardSpaces[0][i]->GetOwnedPlayer() == BoardSpaces[1][i]->GetOwnedPlayer() && BoardSpaces[1][i]->GetOwnedPlayer() == BoardSpaces[2][i]->GetOwnedPlayer())
		{
			if(BoardSpaces[1][i]->GetOwnedPlayer() == EActivePlayer::X)
			{
				GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green,"X WINS Vertical");
			}
			else if(BoardSpaces[1][i]->GetOwnedPlayer() == EActivePlayer::O)
			{
				GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green,"O WINS Vertical");
			}
		}
	}
	
	// Check Diagonal Top Left -> Bottom Right
	if(BoardSpaces[0][0]->GetOwnedPlayer() == BoardSpaces[1][1]->GetOwnedPlayer() && BoardSpaces[1][1]->GetOwnedPlayer() == BoardSpaces[2][2]->GetOwnedPlayer())
	{
		if(BoardSpaces[0][0]->GetOwnedPlayer() == EActivePlayer::X)
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green,"X WINS Diagonal Top Left -> Bottom Right");
		}
		else if(BoardSpaces[0][0]->GetOwnedPlayer() == EActivePlayer::O)
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green,"O WINS Diagonal Top Left -> Bottom Right");
		}
	}

	// Check Diagonal Bottom Left -> Top Right
	if(BoardSpaces[2][0]->GetOwnedPlayer() == BoardSpaces[1][1]->GetOwnedPlayer() && BoardSpaces[1][1]->GetOwnedPlayer() == BoardSpaces[0][2]->GetOwnedPlayer())
	{
		if(BoardSpaces[2][0]->GetOwnedPlayer() == EActivePlayer::X)
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green,"X WINS Diagonal Bottom Left -> Top Right");
		}
		else if(BoardSpaces[2][0]->GetOwnedPlayer() == EActivePlayer::O)
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green,"O WINS Diagonal Bottom Left -> Top Right");
		}
	}

}
