// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TicTacToeGameModeBase.h"
#include "TicTacToeVsAIGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TICTACTOE_API ATicTacToeVsAIGameMode : public ATicTacToeGameModeBase
{
	GENERATED_BODY()

	ATicTacToeVsAIGameMode();

private:
	
	UPROPERTY()
	UOpponentAI* OpponentPlayer;

	virtual void EndTurn() override;
	
	/**
	 * @brief Finds the AI's next move and plays
	 * @note called in EndTurn();
	 */
	void AITurn();
	
};
