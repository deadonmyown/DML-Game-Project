// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "FoodItem.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class GAME_API AFoodItem : public AItem
{
	GENERATED_BODY()

public:
	//AFoodItem();

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
	int Heal;
	
	virtual void Use(AFPCharacter* Character) override;
};
