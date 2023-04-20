// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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
	
	UPROPERTY(meta=(BindWidget))
	UButton* MainButton;

private:

	// ToDo: Store in Game Manager
	UPROPERTY(EditAnywhere)
	UTexture2D* XImage;

	// ToDo: Store in Game Manager
	UPROPERTY(EditAnywhere)
	UTexture2D* OImage;

	UPROPERTY(EditAnywhere)
	UTexture2D* CurrentBackgroundImage;
	
};
