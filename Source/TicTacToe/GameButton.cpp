// Fill out your copyright notice in the Description page of Project Settings.


#include "GameButton.h"

#include "Kismet/GameplayStatics.h"

void UGameButton::NativeConstruct()
{
	Super::NativeConstruct();

	MainButton->OnClicked.AddUniqueDynamic(this, &UGameButton::ActivateWidget);

	CurrentActivePlayer = USpaceState::EActivePlayer::None;
	
	CurrentGameMode = Cast<ATicTacToeGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));

}

void UGameButton::ActivateWidget()
{

	if(CurrentGameMode->GetActivePlayer() == USpaceState::EActivePlayer::X)
		CurrentActivePlayer = USpaceState::EActivePlayer::X;
	else if (CurrentGameMode->GetActivePlayer() == USpaceState::EActivePlayer::O)
		CurrentActivePlayer = USpaceState::EActivePlayer::O;
	else
	{
		CurrentActivePlayer = USpaceState::EActivePlayer::None;
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, "ERROR - NO ACTIVE PLAYER");
	}
	
	ChangeImage(CurrentGameMode->GetActivePlayerImage());
	MainButton->SetIsEnabled(false);

	CurrentGameMode->EndTurn();
	
}

USpaceState::EActivePlayer UGameButton::GetCurrentActivePlayer()
{
	return CurrentActivePlayer;
}

// ToDo: Use this when setting everything else
void UGameButton::SetActivePlayer(USpaceState::EActivePlayer NewOwner)
{
	CurrentActivePlayer = NewOwner;
}


void UGameButton::ChangeImage(UTexture2D* PlayerImage)
{
	MainButton->WidgetStyle.Normal.SetResourceObject(PlayerImage);
}


