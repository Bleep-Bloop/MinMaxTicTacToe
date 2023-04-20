// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TicTacToeGameModeBase.generated.h"


UENUM()
enum EActivePlayer
{
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
	
	UPROPERTY(EditAnywhere)
	TEnumAsByte<EActivePlayer> ActivePlayer;
	
	UPROPERTY(EditAnywhere)
	UTexture2D* XImage;
	
	UPROPERTY(EditAnywhere)
	UTexture2D* OImage;
	
};
