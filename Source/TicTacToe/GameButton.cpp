// Fill out your copyright notice in the Description page of Project Settings.


#include "GameButton.h"

void UGameButton::NativeConstruct()
{
	Super::NativeConstruct();

	MainButton->OnClicked.AddUniqueDynamic(this, &UGameButton::ActivateWidget);
}

void UGameButton::ActivateWidget()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::MakeRandomColor(), "UGameButton::ActivateWidget()");

	// Cast<CustomGameMode>(GetWorld()->GetGameMode()).bXIsActivePlayer;
	// if bXIsActivePlayer
	// Sprite X elseSprite O

}
