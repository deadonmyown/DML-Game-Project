/*
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractableUIInterface.h"
#include "InventoryComponent.generated.h"

//Blueprints will bind to it to update the UI
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInventoryUpdated);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAME_API UInventoryComponent : public UActorComponent, public IInteractableUIInterface
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual bool AddItem(class AItem* Item) override;
	virtual bool RemoveItem(AItem* Item) override;

	bool SpawnItem(const class AFPCharacter* Character, class APickupableItem* Item) const;

	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<AItem>> DefaultsItem;

	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	int32 Capacity;

	UPROPERTY(BlueprintAssignable, Category = "Inventory")
	FOnInventoryUpdated OnInventoryUpdated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Items")
	TArray<AItem*> Items;
	

		
};
*/
