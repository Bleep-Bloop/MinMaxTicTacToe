// Fill out your copyright notice in the Description page of Project Settings.


#include "GameButton.h"

void UGameButton::ActivateWidget(bool bIsPlayerX)
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::MakeRandomColor(), "Button Pressed");
	// ToDo:
	/*	if (bIsX)
	 *		this->Turn sprite to attached sprite
	 */
}
