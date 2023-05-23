// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractableUIInterface.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UInteractableUIInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GAME_API IInteractableUIInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual bool AddItem(class AItem* Item) = 0;
	virtual bool RemoveItem(AItem* Item) = 0;
	
};
