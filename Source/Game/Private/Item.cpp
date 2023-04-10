// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"

UItem::UItem()
{
	Description = FText::FromString("Description");
	DisplayName = FText::FromString("Item");
	UseText = FText::FromString("Use");
}

void UItem::Use(AFPCharacter* Character)
{
}

