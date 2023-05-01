// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"
#include "FPCharacter.h"
#include "PickupableItem.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	//PrimaryComponentTick.bCanEverTick = true;

	Capacity = 20;
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	for(auto& Item : DefaultsItem)
	{
		AddItem(Item.GetDefaultObject());
	}
	
}

bool UInventoryComponent::AddItem(AItem* Item)
{
	if(Items.Num() >= Capacity || !Item)
	{
		return false;
	}

	Item->OwningInventory = this;
	Items.Add(Item);

	//Update UI
	OnInventoryUpdated.Broadcast();
	return true;
}

bool UInventoryComponent::RemoveItem(AItem* Item)
{
	if(Item)
	{
		Item->OwningInventory = nullptr;
		Items.RemoveSingle(Item);
		OnInventoryUpdated.Broadcast();
		return true;
	}

	return false;
}

bool UInventoryComponent::SpawnItem(AFPCharacter* Character, APickupableItem* Item)
{
	if(Item->GetWorld())
	{
		Item->DropItem(Character);
		return true;
	}
	UWorld* const world = GetWorld();
	UClass* const actorClassToSpawn = Item->GetClass();
	if (world && actorClassToSpawn)
	{
		FActorSpawnParameters SpawnParameters = FActorSpawnParameters();
		SpawnParameters.Template = Item;
		APickupableItem* const spawned = GetWorld()->SpawnActor<APickupableItem>(actorClassToSpawn,  Character->GetActorLocation() +
			Character->GetActorForwardVector() * Character->DropItemMultiplier, FRotator::ZeroRotator, SpawnParameters);
		if(spawned)
		{
			spawned->Initialize(Item->UseText, Item->Thumbnail, Item->DisplayName, Item->Description);
			return true;
		}
	}
	return false;
}

