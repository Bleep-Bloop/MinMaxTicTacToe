// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"
#include "SpaceState.generated.h"


/**
 * 
 */
UCLASS()
class TICTACTOE_API USpaceState : public UUserDefinedEnum
{
	GENERATED_BODY()

public:
	
	enum class EActivePlayer
	{
		None UMETA(DisplayName = "UnOwned"),
		X UMETA(DisplayName = "Player X"),
		O UMETA(DisplayName = "Player O"),
	};
	
};

