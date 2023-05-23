// Fill out your copyright notice in the Description page of Project Settings.


#include "ShopComponent.h"
#include "Item.h"

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

	for(auto& Item : DefaultsItem)
	{
		AddItem(Item.GetDefaultObject());
	}
}

bool UShopComponent::AddItem(AItem* Item)
{
	if(!Item)
	{
		return false;
	}

	auto* NewItem = NewObject<AItem>(GetOwner(), Item->GetClass(), Item->GetFName(), RF_NoFlags, Item);

	/*if(NewItem->GetWorld())
	{
		if(APickupableItem* PickupableItem = Cast<APickupableItem>(NewItem))
		{
			if(Item->GetWorld())
			{
				PickupableItem->IsOnLevel = true;
			}
			PickupableItem->OwningInventory = this;
			Items.Add(PickupableItem);
			OnShopUpdated.Broadcast();
			return true;
		}
	}*/
	
	NewItem->OwningInventory = this;
	Items.Add(NewItem);
	
	//Update UI
	OnShopUpdated.Broadcast();
	
	return true;
}

bool UShopComponent::RemoveItem(AItem* Item)
{
	if(Item)
	{
		Item->OwningInventory = nullptr;
		Items.RemoveSingle(Item);

		OnShopUpdated.Broadcast();
		
		return true;
	}

	return false;
}

bool UShopComponent::BuyItem(AFPCharacter* Character, AItem* Item)
{
	if(Character && Item && Character->Silversmith >= Item->Cost)
	{
		RemoveItem(Item);
		if(Character->Inventory->AddItem(Item))
		{
			Character->Silversmith -= Item->Cost;
			return true;
		}
		AddItem(Item);
	}
	return false;
}

bool UShopComponent::SellItem(AFPCharacter* Character, AItem* Item)
{
	if(Character || Item)
	{
		Character->Inventory->RemoveItem(Item);
		AddItem(Item);
		Character->Silversmith += FGenericPlatformMath::CeilToInt(Item->Cost * Percent);
		return true;
	}
	return false;
}



