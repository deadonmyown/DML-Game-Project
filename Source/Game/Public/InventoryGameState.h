// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameFramework/GameState.h"
#include "InventoryGameState.generated.h"

/**
 * 
 */
UCLASS()
class GAME_API AInventoryGameState : public AGameState
{
	GENERATED_BODY()

public:
	AInventoryGameState();

	UDataTable* GetItemDB() const;

protected:
	UPROPERTY(EditDefaultsOnly)
	class UDataTable* ItemDB;
};
