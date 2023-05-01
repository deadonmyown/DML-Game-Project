// Fill out your copyright notice in the Description page of Project Settings.


#include "FoodItem.h"
#include "FPCharacter.h"

void AFoodItem::Use(AFPCharacter* Character)
{
	if(Character)
	{
		Character->Health += Heal;

		if(OwningInventory)
		{
			OwningInventory->RemoveItem(this);
		}
	}
}


