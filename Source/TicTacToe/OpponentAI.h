// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SpaceState.h"
#include "Components/ActorComponent.h"
#include "OpponentAI.generated.h"

struct FMove
{
	int Row;
	int Column;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TICTACTOE_API UOpponentAI : public UActorComponent
{
	GENERATED_BODY()

public:
	
	// ToDo: CurrentPlayer to handle AI vs AI
	FMove FindBestMove(USpaceState::EActivePlayer Spaces[3][3]);

private:

	bool HasMovesLeft(USpaceState::EActivePlayer Spaces[3][3]);

	int EvaluateBoard(USpaceState::EActivePlayer Spaces[3][3]);

	int MiniMax(USpaceState::EActivePlayer Spaces[3][3], int Depth, bool bIsMax);
	
};

