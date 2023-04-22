// Fill out your copyright notice in the Description page of Project Settings.


#include "GameButton.h"

#include "Kismet/GameplayStatics.h"

void UGameButton::NativeConstruct()
{
	Super::NativeConstruct();

	MainButton->OnClicked.AddUniqueDynamic(this, &UGameButton::ActivateWidget);

	OwnedPlayer = EActivePlayer::None;
	
	CurrentGameMode = Cast<ATicTacToeGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
}

void UGameButton::ActivateWidget()
{

	if(CurrentGameMode->GetActivePlayer() == EActivePlayer::X)
		OwnedPlayer = EActivePlayer::X;
	else if (CurrentGameMode->GetActivePlayer() == EActivePlayer::O)
		OwnedPlayer = EActivePlayer::O;
	else
	{
		OwnedPlayer = EActivePlayer::None;
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, "ERROR - NO ACTIVE PLAYER");
	}

	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::MakeRandomColor(), FString::Printf(TEXT("Owned Player Set: %d"), OwnedPlayer.GetValue()));
	
	ChangeImage(CurrentGameMode->GetActivePlayerImage());
	MainButton->SetIsEnabled(false);
	
}

void UGameButton::ChangeImage(UTexture2D* PlayerImage)
{
	MainButton->WidgetStyle.Normal.SetResourceObject(PlayerImage);
}

