// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InventoryFunctionalityInterface.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UInventoryFunctionalityInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GAME_API IInventoryFunctionalityInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, Category = "Utils")
	virtual bool AddItemToInventoryByID(FName ID) = 0;

	UFUNCTION(BlueprintCallable, Category = "Utils")
	virtual bool AddItemToInventory(struct FInventoryItem Item) = 0;

	virtual FInventoryItem* FindItemByID(FName ID) = 0;
	
};
