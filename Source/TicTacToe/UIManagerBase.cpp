// Created by Spring2022_Capstone team

#include "UIManagerBase.h"
#include "Blueprint/UserWidget.h"

AUIManagerBase::AUIManagerBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AUIManagerBase::BeginPlay()
{
	Super::BeginPlay();
	DisplayWidget();
}

void AUIManagerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AUIManagerBase::DisplayWidget()
{
	if (RootWidget) {
		_RootWidget = CreateWidget(GetWorld(), RootWidget);
		_RootWidget->AddToViewport(1);
	} else {
		UE_LOG(LogTemp, Error, TEXT("Type not specified for Root Widget"));
	}
}

void AUIManagerBase::DismissWidget()
{
	_RootWidget->RemoveFromParent();
}