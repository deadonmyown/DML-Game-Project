// Fill out your copyright notice in the Description page of Project Settings.


#include "ShopComponent.h"
#include "InventoryController.h"
#include "InventoryGameState.h"


// Sets default values for this component's properties
UShopComponent::UShopComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UShopComponent::BeginPlay()
{
	Super::BeginPlay();

	for(auto& ID : DefaultsItemById)
	{
		AddItemToInventoryByID(ID);
	}
}

bool UShopComponent::AddItemToInventory(FInventoryItem Item)
{
	Shop.Add(Item);
	ReloadShop.Broadcast();
	return true;
}

bool UShopComponent::AddItemToInventoryByID(FName ID)
{
	FInventoryItem* ItemToAdd = FindItemByID(ID);

	if (ItemToAdd)
	{
		Shop.Add(*ItemToAdd);
		ReloadShop.Broadcast();
		return true;
	}
	return false;
}

bool UShopComponent::BuyItem(APlayerController* Controller, FInventoryItem Item)
{
	if(Controller)
	{
		AInventoryController* IController = Cast<AInventoryController>(Controller);
		if(IController && IController->Money >= Item.Value)
		{
			if(IController->AddItemToInventory(Item))
			{
				IController->Money -= Item.Value;
				RemoveItem.Broadcast(Item);
				ReloadShop.Broadcast();
				return true;
			}
		}
	}
	return false;
}

bool UShopComponent::SellItem(APlayerController* Controller, FInventoryItem Item)
{
	if(Controller)
	{
		AInventoryController* IController = Cast<AInventoryController>(Controller);
		if(IController)
		{
			if(AddItemToInventory(Item))
			{
				IController->Money += Item.Value;
				IController->RemoveItem(Item);
				ReloadShop.Broadcast();
				return true;
			}
		}
	}
	return false;
}

FInventoryItem* UShopComponent::FindItemByID(FName ID)
{
	AInventoryGameState* GameState = Cast<AInventoryGameState>(GetWorld()->GetGameState());
	UDataTable* ItemTable = GameState->GetItemDB();
	FInventoryItem* ItemToAdd = ItemTable->FindRow<FInventoryItem>(ID, "");

	return ItemToAdd;
}






