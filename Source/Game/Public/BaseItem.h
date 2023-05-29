// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemFunctionalityInterface.h"
#include "GameFramework/Actor.h"
#include "BaseItem.generated.h"

UCLASS()
class GAME_API ABaseItem : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABaseItem();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Use(APlayerController* Controller);
	virtual void Use_Implementation(APlayerController* Controller);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool Drop(APlayerController* Controller,struct FInventoryItem Item);
	virtual bool Drop_Implementation(APlayerController* Controller, FInventoryItem Item);

	ABaseItem* Spawn(APlayerController* Controller);
};
