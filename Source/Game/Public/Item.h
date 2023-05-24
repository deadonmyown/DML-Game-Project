/*
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryComponent.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

/**
 * 
 #1#
UCLASS(Abstract, BlueprintType, Blueprintable, DefaultToInstanced)
class GAME_API AItem : public AActor
{
	GENERATED_BODY()

public:
	AItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Item")
	FText UseText;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Item")
	UStaticMeshComponent* PickupMesh;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item", meta = (ExposeOnSpawn="true"))
	UTexture2D* Thumbnail;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Item")
	FText DisplayName;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Item", meta = (MultiLine = true))
	FText Description;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Item")
	int Cost;
	
	IInteractableUIInterface* OwningInventory;

	virtual void Use(class AFPCharacter* Character);

	virtual void Setup(AFPCharacter* Character);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUse(class AFPCharacter* Character);
};
*/
