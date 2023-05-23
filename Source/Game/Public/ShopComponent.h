// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FPCharacter.h"
#include "Components/ActorComponent.h"
#include "InteractableUIInterface.h"
#include "ShopComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnShopUpdated);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAME_API UShopComponent : public UActorComponent, public IInteractableUIInterface
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UShopComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual bool AddItem(class AItem* Item) override;
	virtual bool RemoveItem(AItem* Item) override;

	bool BuyItem(AFPCharacter* Character, AItem* Item);
	bool SellItem(AFPCharacter* Character, AItem* Item);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float Percent;
	
	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<AItem>> DefaultsItem;

	UPROPERTY(BlueprintAssignable, Category = "Inventory")
	FOnShopUpdated OnShopUpdated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Items")
	TArray<AItem*> Items;
};
