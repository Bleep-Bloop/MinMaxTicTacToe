// Copyright Epic Games, Inc. All Rights Reserved.


#include "TicTacToeGameModeBase.h"
#include "GameButton.h"
#include "Kismet/GameplayStatics.h"

ATicTacToeGameModeBase::ATicTacToeGameModeBase()
{
}

void ATicTacToeGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	
	// Start game with PlayerX
	ActivePlayer = USpaceState::EActivePlayer::X;
	
	// Setting Cursor -> ToDo: Shorten
	if(GetWorld()->GetFirstPlayerController())
		GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
	
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
	
	// ToDo: Re-Write
	bool bIsPlayerX = (ActivePlayer == USpaceState::EActivePlayer::X); 
	ActivePlayer = (bIsPlayerX? ActivePlayer = USpaceState::EActivePlayer::O : ActivePlayer = USpaceState::EActivePlayer::X);

	CheckForWinner();
	UpdateBoardSpaceArray();
	
}


bool ATicTacToeGameModeBase::CheckForWinner() const
{
	//USpaceState::EActivePlayer Winner = USpaceState::EActivePlayer::None;

	// Check Diagonal Top Left -> Bottom Right
	if(BoardSpaces[0][0]->GetCurrentActivePlayer() == BoardSpaces[1][1]->GetCurrentActivePlayer() && BoardSpaces[1][1]->GetCurrentActivePlayer() == BoardSpaces[2][2]->GetCurrentActivePlayer())
	{
		if(BoardSpaces[0][0]->GetCurrentActivePlayer() == USpaceState::EActivePlayer::X)
			UGameplayStatics::OpenLevel(GetWorld(), "Map_XWin");
		else if(BoardSpaces[0][0]->GetCurrentActivePlayer() == USpaceState::EActivePlayer::O)
			UGameplayStatics::OpenLevel(GetWorld(), "Map_OWin");
	}

	// Check Diagonal Bottom Left -> Top Right
	if(BoardSpaces[2][0]->GetCurrentActivePlayer() == BoardSpaces[1][1]->GetCurrentActivePlayer() && BoardSpaces[1][1]->GetCurrentActivePlayer() == BoardSpaces[0][2]->GetCurrentActivePlayer())
	{
		if(BoardSpaces[2][0]->GetCurrentActivePlayer() == USpaceState::EActivePlayer::X)
			UGameplayStatics::OpenLevel(GetWorld(), "Map_XWin");
		else if(BoardSpaces[2][0]->GetCurrentActivePlayer() == USpaceState::EActivePlayer::O)
			UGameplayStatics::OpenLevel(GetWorld(), "Map_OWin");
	}
	
	// Check Horizontal
	for(int i = 0; i < 3; i++)
	{
		if(BoardSpaces[i][0]->GetCurrentActivePlayer() == BoardSpaces[i][1]->GetCurrentActivePlayer() && BoardSpaces[i][1]->GetCurrentActivePlayer() == BoardSpaces[i][2]->GetCurrentActivePlayer())
		{
			if(BoardSpaces[i][0]->GetCurrentActivePlayer() == USpaceState::EActivePlayer::X)
				UGameplayStatics::OpenLevel(GetWorld(), "Map_XWin");
			else if(BoardSpaces[i][0]->GetCurrentActivePlayer() == USpaceState::EActivePlayer::O)
				UGameplayStatics::OpenLevel(GetWorld(), "Map_OWin");
		}
	}

	// Check Vertical
	for(int i = 0; i < 3; i++)
	{
		if(BoardSpaces[0][i]->GetCurrentActivePlayer() == BoardSpaces[1][i]->GetCurrentActivePlayer() && BoardSpaces[1][i]->GetCurrentActivePlayer() == BoardSpaces[2][i]->GetCurrentActivePlayer())
		{
			if(BoardSpaces[0][i]->GetCurrentActivePlayer() == USpaceState::EActivePlayer::X)
			{
				UGameplayStatics::OpenLevel(GetWorld(), "Map_XWin");
				return true;
			}
			else if(BoardSpaces[0][i]->GetCurrentActivePlayer() == USpaceState::EActivePlayer::O)
				UGameplayStatics::OpenLevel(GetWorld(), "Map_OWin");
		}
	}
	
	int ActiveSpaces = 0;
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(BoardSpaces[i][j]->GetCurrentActivePlayer() != USpaceState::EActivePlayer::None)
				ActiveSpaces++;
		}
	}
	if(ActiveSpaces == 9)
		UGameplayStatics::OpenLevel(GetWorld(), "Map_Tie");

	return false;
	
}

void ATicTacToeGameModeBase::UpdateBoardSpaceArray()
{

	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			BoardSpaceStates[i][j] = BoardSpaces[i][j]->GetCurrentActivePlayer();
		}
	}

}

