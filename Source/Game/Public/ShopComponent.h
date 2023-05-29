// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryItem.h"
#include "Components/ActorComponent.h"
#include "ShopComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRemoveItem, FInventoryItem, Item);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnShopReload);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GAME_API UShopComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UShopComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable)
	bool BuyItem(APlayerController* Controller, struct FInventoryItem Item);

	UFUNCTION(BlueprintCallable)
	bool SellItem(APlayerController* Controller, FInventoryItem Item);

	UFUNCTION(BlueprintCallable, Category = "Utils")
	bool AddItemToInventoryByID(FName ID);

	UFUNCTION(BlueprintCallable, Category = "Utils")
	bool AddItemToInventory(FInventoryItem Item);

	FInventoryItem* FindItemByID(FName ID);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<FInventoryItem> Shop;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float Percent;

	UPROPERTY(EditAnywhere)
	TArray<FName> DefaultsItemById;

	UPROPERTY(BlueprintAssignable, Category = "Utils")
	FRemoveItem RemoveItem;

	UPROPERTY(BlueprintAssignable, Category = "Utils")
	FOnShopReload ReloadShop;
};
