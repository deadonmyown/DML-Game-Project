// Fill out your copyright notice in the Description page of Project Settings.


#include "FoodItem.h"
#include "FPCharacter.h"

void AFoodItem::Use(AFPCharacter* Character)
{
	if(Character)
	{
		if(OwningInventory)
		{
			Character->Health += Heal;
			OwningInventory->RemoveItem(this);
		}
		else
		{
			if(GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("No OwningInventory??????????")));
		}
	}
}


