// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TicTacToeGameModeBase.h"
#include "SpaceState.h"
#include "Components/Button.h"
#include "GameButton.generated.h"

/**
 * 
 */
UCLASS()
class TICTACTOE_API UGameButton : public UUserWidget 
{
	GENERATED_BODY()

public:
	
	virtual void NativeConstruct() override;
	
	/**
	 * @brief Changes the Sprite on each button.
	 * @Note: Bound to OnClick inside GameButton::NativeConstruct().
	 */
	UFUNCTION(BlueprintCallable)
	void ActivateWidget();
	
	USpaceState::EActivePlayer GetCurrentActivePlayer();
	
	void SetActivePlayer(USpaceState::EActivePlayer NewOwner);

private:

	UPROPERTY()
	ATicTacToeGameModeBase* CurrentGameMode;
	
	USpaceState::EActivePlayer CurrentActivePlayer;

	UPROPERTY(meta=(BindWidget))
	UButton* MainButton;
	
	void ChangeImage(UTexture2D* PlayerImage);
	
	
};
