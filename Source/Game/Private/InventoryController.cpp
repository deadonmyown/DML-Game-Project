#include "InventoryController.h"
#include "InventoryGameState.h"
#include "FPCharacter.h"

AInventoryController::AInventoryController() 
{
	InventorySlotLimit = 50;
	InventoryWeightLimit = 500;
}

void AInventoryController::UseItem(FInventoryItem Item)
{
	auto* BaseItem = Item.BaseItem.GetDefaultObject();
	BaseItem->Use_Implementation(this);
}

bool AInventoryController::DropItem(FInventoryItem Item)
{
	auto* BaseItem = Item.BaseItem.GetDefaultObject();
	
	AFPCharacter* FPCharacter = Cast<AFPCharacter>(GetCharacter());
	const UWorld* World = GetWorld();
	UClass* const ActorClassToSpawn = BaseItem->GetClass();
	if (World && ActorClassToSpawn)
	{
		FActorSpawnParameters SpawnParameters = FActorSpawnParameters();
		SpawnParameters.Template = BaseItem;
		if(auto* Spawned = GetWorld()->SpawnActor<ABaseItem>(ActorClassToSpawn,  FVector::ZeroVector, FRotator::ZeroRotator, SpawnParameters))
		{
			Spawned->SetActorLocation(FPCharacter->GetActorLocation() + FPCharacter->GetActorForwardVector() * FPCharacter->DropItemMultiplier);
			RemoveItem(Item);
			return true;
		}
	}
	return false;
}

int32 AInventoryController::GetInventoryWeight()
{
	int32 Weight = 0;
	for (auto& Item : Inventory)
	{
		Weight += Item.Weight;
	}

	return Weight;
}

bool AInventoryController::AddItemToInventoryByID(FName ID)
{
	FInventoryItem* ItemToAdd = FindItemByID(ID);

	if (ItemToAdd)
	{
		// If a Slot- or WeightLimit are not needed remove them in this line
		if (Inventory.Num() < InventorySlotLimit && GetInventoryWeight() + ItemToAdd->Weight <= InventoryWeightLimit)
		{
			Inventory.Add(*ItemToAdd);
			ReloadInventory();
			return true;
		}
	}
	return false;
}

bool AInventoryController::AddItemToInventory(FInventoryItem Item)
{
	if (Inventory.Num() < InventorySlotLimit && GetInventoryWeight() + Item.Weight <= InventoryWeightLimit)
	{
		Inventory.Add(Item);
		ReloadInventory();
		return true;
	}
	return false;
}

FInventoryItem* AInventoryController::FindItemByID(FName ID)
{
	AInventoryGameState* GameState = Cast<AInventoryGameState>(GetWorld()->GetGameState());
	UDataTable* ItemTable = GameState->GetItemDB();
	FInventoryItem* ItemToAdd = ItemTable->FindRow<FInventoryItem>(ID, "");

	return ItemToAdd;
}

void AInventoryController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("Interact", IE_Pressed, this, &AInventoryController::Interact);
}

void AInventoryController::Interact()
{
	if (CurrentInteractable)
	{
		CurrentInteractable->Interact(this);
	}
}

