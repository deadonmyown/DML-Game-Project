// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ItemFunctionalityInterface.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UItemFunctionalityInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GAME_API IItemFunctionalityInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Use(APlayerController* Controller);
	virtual void Use_Implementation(APlayerController* Controller) = 0;

	UFUNCTION(BlueprintNativeEvent)
	bool Drop(APlayerController* Controller,struct FInventoryItem Item);
	virtual bool Drop_Implementation(APlayerController* Controller, FInventoryItem Item) = 0;
};
