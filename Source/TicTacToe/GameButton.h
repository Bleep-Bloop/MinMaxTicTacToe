// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "GameButton.generated.h"

/**
 * 
 */
UCLASS()
class TICTACTOE_API UGameButton : public UButton 
{
	GENERATED_BODY()

public:
	void ActivateWidget(bool bIsPlayerX);

private:

	// ToDo: Store in Game Manager
	UPROPERTY(EditAnywhere, meta=(BindWidget))
	UTexture2D* XImage;

	// ToDo: Store in Game Manager
	UPROPERTY(EditAnywhere, meta=(BindWidget))
	UTexture2D* OImage;
	
};
