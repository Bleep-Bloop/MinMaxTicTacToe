// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "OpponentAI.h"
#include "SpaceState.h"
#include "GameFramework/GameModeBase.h"
#include "TicTacToeGameModeBase.generated.h"

class UGameButton;

/**
 * 
 */
UCLASS()
class TICTACTOE_API ATicTacToeGameModeBase : public AGameModeBase
{
protected:
	GENERATED_BODY()

	ATicTacToeGameModeBase();
	
	virtual void BeginPlay() override;

	// Current turn's player
	USpaceState::EActivePlayer ActivePlayer;

	UPROPERTY(EditAnywhere)
	UTexture2D* XImage;
	
	UPROPERTY(EditAnywhere)
	UTexture2D* OImage;
	
	void CheckForWinner() const;
	
	// Checks and sets all board spaces
	// used for passing to UOpponentAI
	void UpdateBoardSpaceArray();

public:

	USpaceState::EActivePlayer GetActivePlayer() const;

	UTexture2D* GetActivePlayerImage() const;

	virtual void EndTurn();

	/**
	 * @brief All spots on the board organized by [row][column]
	 * @note Buttons are added from GameBoardUserWidget
	 */
	UGameButton* BoardSpaces[3][3];

	/**
	 * @brief All spots on the board and their respective states
	 * @note used by OpponentAI
	 */
	USpaceState::EActivePlayer BoardSpaceStates[3][3];
	

	
};
