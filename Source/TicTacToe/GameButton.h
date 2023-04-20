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
	/**
	 * @brief Changes the Sprite on each button
	 * @IMPORTANT Remember to bind this to OnClick inside GameBoardUserWidget BP
	 */
	UFUNCTION(BlueprintCallable)
	void ActivateWidget();

	void Whydoesthiswork();

	UFUNCTION()
	void OnSelected(AActor* ClickedActor, FKey ButtonPressed);

	UPROPERTY(meta=(BindWidget))
	UButton* MainButton;

	virtual void NativeConstruct() override;

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
