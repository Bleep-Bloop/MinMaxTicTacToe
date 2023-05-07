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
	GENERATED_BODY()

	ATicTacToeGameModeBase();

	virtual void BeginPlay() override;

	// Current turn's player
	//UPROPERTY(EditAnywhere) // have to comment out
	USpaceState::EActivePlayer ActivePlayer;

	UPROPERTY(EditAnywhere)
	UTexture2D* XImage;
	
	UPROPERTY(EditAnywhere)
	UTexture2D* OImage;
	
public:

	USpaceState::EActivePlayer GetActivePlayer() const;

	UTexture2D* GetActivePlayerImage() const;

	void EndTurn();

	/**
	 * @brief All spots on the board organized by [row][column]
	 * @note Buttons are added from GameBoardUserWidget
	 */
	UGameButton* BoardSpaces[3][3];

	/**
	 * @brief All spots on the board and their respective states
	 */
	USpaceState::EActivePlayer BoardSpaceStates[3][3];
	
	void CheckForWinner() const;
	
	UPROPERTY()
	UOpponentAI* OpponentPlayer;

	// Checks and sets all board spaces
	// used for passing to UOpponentAI
	void UpdateBoardSpaceArray();
	
	

	//void TestFillStateArray(); // ToDo: Change name to UpdateStateArray at end of turn
	
	
};
