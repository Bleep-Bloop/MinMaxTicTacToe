// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameButton.h"
#include "Blueprint/UserWidget.h"
#include "GameBoardUserWidget.generated.h"

class UImage;

/**
 * 
 */
UCLASS()
class TICTACTOE_API UGameBoardUserWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

private:

	UPROPERTY()
	ATicTacToeGameModeBase* CurrentGameMode;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UPanelWidget* RootWidget;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UImage* BackgroundImage; // Just a color

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UImage* GameBoardImage;

	// BoardSpaces // Row_Column 
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UGameButton* GameButton0_0;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UGameButton* GameButton0_1;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UGameButton* GameButton0_2;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UGameButton* GameButton1_0;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UGameButton* GameButton1_1;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UGameButton* GameButton1_2;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UGameButton* GameButton2_0;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UGameButton* GameButton2_1;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UGameButton* GameButton2_2;

	void InitButtons();
	
	
};
