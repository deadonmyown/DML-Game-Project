/*
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
	
	if(AWeapon* Weapon = Cast<AWeapon>(Item))
	{
		if(Weapon->GetWorld())
		{
			Weapon->OwningInventory = this;
			Weapon->IsOnLevel = true;
			Items.Add(Weapon);
			OnInventoryUpdated.Broadcast();
			return true;
		}
		AFPCharacter* Character = Cast<AFPCharacter>(GetOwner());
		const UWorld* World = GetWorld();
		UClass* const ActorClassToSpawn = Weapon->GetClass();
		if (World && ActorClassToSpawn)
		{
			FActorSpawnParameters SpawnParameters = FActorSpawnParameters();
			SpawnParameters.Template = Weapon;
			if(AWeapon* const Spawned = GetWorld()->SpawnActor<AWeapon>(ActorClassToSpawn,  Character->GetActorLocation() +
				Character->GetActorForwardVector() * Character->DropItemMultiplier, FRotator::ZeroRotator, SpawnParameters))
			{
				Spawned->SetActorLocation(Character->GetActorLocation() + Character->GetActorForwardVector() * Character->DropItemMultiplier);
				Spawned->IsOnLevel = true;
				Spawned->OwningInventory = this;
				Items.Add(Spawned);
				OnInventoryUpdated.Broadcast();
				return true;
			}
		}
		return false;
	}
	auto* NewItem = NewObject<AItem>(GetOwner(), Item->GetClass(), Item->GetFName(), RF_NoFlags, Item);
	
	NewItem->OwningInventory = this;
	Items.Add(NewItem);
	
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

bool UInventoryComponent::SpawnItem(const AFPCharacter* Character, APickupableItem* Item) const
{
	const UWorld* World = GetWorld();
	UClass* const ActorClassToSpawn = Item->GetClass();
	if (World && ActorClassToSpawn)
	{
		FActorSpawnParameters SpawnParameters = FActorSpawnParameters();
		SpawnParameters.Template = Item;
		if(APickupableItem* const Spawned = GetWorld()->SpawnActor<APickupableItem>(ActorClassToSpawn,  Character->GetActorLocation() +
			Character->GetActorForwardVector() * Character->DropItemMultiplier, FRotator::ZeroRotator, SpawnParameters))
		{
			Spawned->SetActorLocation(Character->GetActorLocation() + Character->GetActorForwardVector() * Character->DropItemMultiplier);
			Spawned->IsOnLevel = true;
			return true;
		}
	}
	return false;
}
*/

