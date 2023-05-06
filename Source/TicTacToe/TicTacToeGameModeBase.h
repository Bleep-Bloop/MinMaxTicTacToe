// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TicTacToeGameModeBase.generated.h"

class UGameButton;


UENUM()
enum EActivePlayer
{
	None UMETA(DisplayName = "UnOwned"),
	X UMETA(DisplayName = "Player X"),
	O UMETA(DisplayName = "Player O"),
};

/**
 * 
 */
UCLASS()
class TICTACTOE_API ATicTacToeGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	virtual void BeginPlay() override;

	// Current turn's player
	UPROPERTY(EditAnywhere)
	TEnumAsByte<EActivePlayer> ActivePlayer;

	UPROPERTY(EditAnywhere)
	UTexture2D* XImage;
	
	UPROPERTY(EditAnywhere)
	UTexture2D* OImage;
	
public:

	EActivePlayer GetActivePlayer() const;

	UTexture2D* GetActivePlayerImage() const;

	void EndTurn();

	/**
	 * @brief All spots on the board organized by [row][column]
	 * @note Buttons are added from GameBoardUserWidget
	 */
	UGameButton* BoardSpaces[3][3]; 
	
	
};
