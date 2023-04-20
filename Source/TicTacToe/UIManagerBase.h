// Created by Spring2022_Capstone team

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UIManagerBase.generated.h"

class UUserWidget;

UCLASS()
class TICTACTOE_API AUIManagerBase : public AActor
{
	GENERATED_BODY()
	
public:	
	AUIManagerBase();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Widget")
	TSubclassOf<UUserWidget> RootWidget;

	UFUNCTION()
	void DisplayWidget();
	UFUNCTION()
	void DismissWidget();

private:
	
	UPROPERTY()
	UUserWidget *_RootWidget;
	
};