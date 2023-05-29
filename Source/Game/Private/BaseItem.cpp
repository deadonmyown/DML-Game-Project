// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseItem.h"
#include "FPCharacter.h"
#include "InventoryController.h"



// Sets default values
ABaseItem::ABaseItem()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ABaseItem::Use_Implementation(APlayerController* Controller)
{
	//pox
}

bool ABaseItem::Drop_Implementation(APlayerController* Controller, FInventoryItem Item)
{
	if(AInventoryController* IController = Cast<AInventoryController>(Controller))
	{
		AFPCharacter* FPCharacter = Cast<AFPCharacter>(IController->GetCharacter());
		const UWorld* World = IController->GetWorld();
		UClass* const ActorClassToSpawn = GetClass();
		if (World && ActorClassToSpawn)
		{
			FActorSpawnParameters SpawnParameters = FActorSpawnParameters();
			SpawnParameters.Template = this;
			if(auto* Spawned = IController->GetWorld()->SpawnActor<ABaseItem>(ActorClassToSpawn,  FVector::ZeroVector, FRotator::ZeroRotator, SpawnParameters))
			{
				Spawned->SetActorLocation(FPCharacter->GetActorLocation() + FPCharacter->GetActorForwardVector() * FPCharacter->DropItemMultiplier);
				IController->RemoveItem(Item);
				return true;
			}
		}
	}
	return false;
}

ABaseItem* ABaseItem::Spawn(APlayerController* Controller)
{
	if(AInventoryController* IController = Cast<AInventoryController>(Controller))
	{
		AFPCharacter* FPCharacter = Cast<AFPCharacter>(IController->GetCharacter());
		const UWorld* World = IController->GetWorld();
		UClass* const ActorClassToSpawn = GetClass();
		if (World && ActorClassToSpawn)
		{
			FActorSpawnParameters SpawnParameters = FActorSpawnParameters();
			SpawnParameters.Template = this;
			if(auto* Spawned = IController->GetWorld()->SpawnActor<ABaseItem>(ActorClassToSpawn,  FVector::ZeroVector, FRotator::ZeroRotator, SpawnParameters))
			{
				Spawned->SetActorLocation(FPCharacter->GetActorLocation() + FPCharacter->GetActorForwardVector() * FPCharacter->DropItemMultiplier);
				return Spawned;
			}
		}
	}
	return nullptr;
}

