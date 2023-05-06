// Fill out your copyright notice in the Description page of Project Settings.


#include "GameBoardUserWidget.h"

#include "Kismet/GameplayStatics.h"

void UGameBoardUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	CurrentGameMode = Cast<ATicTacToeGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));

	InitButtons();
	
}

void UGameBoardUserWidget::InitButtons()
{
	// Set References in GameMode
	CurrentGameMode->BoardSpaces[0][0] = GameButton0_0;
	CurrentGameMode->BoardSpaces[0][1] = GameButton0_1;
	CurrentGameMode->BoardSpaces[0][2] = GameButton0_2;

	CurrentGameMode->BoardSpaces[1][0] = GameButton1_0;
	CurrentGameMode->BoardSpaces[1][1] = GameButton1_1;
	CurrentGameMode->BoardSpaces[1][2] = GameButton1_2;

	CurrentGameMode->BoardSpaces[2][0] = GameButton2_0;
	CurrentGameMode->BoardSpaces[2][1] = GameButton2_1;
	CurrentGameMode->BoardSpaces[2][2] = GameButton2_2;

}
