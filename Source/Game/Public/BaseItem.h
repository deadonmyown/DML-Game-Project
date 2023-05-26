// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemFunctionalityInterface.h"
#include "GameFramework/Actor.h"
#include "BaseItem.generated.h"

UCLASS()
class GAME_API ABaseItem : public AActor, public IItemFunctionalityInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABaseItem();

	virtual void Use_Implementation(APlayerController* Controller) override;
	virtual bool Drop_Implementation(APlayerController* Controller) override;
};
