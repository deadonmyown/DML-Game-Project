#include "InventoryController.h"
#include "InventoryGameState.h"
#include "FPCharacter.h"
#include "QuestMissionGoal.h"
#include "QuestMissionInfo.h"
#include "TargetType.h"
#include "Weapon.h"
#include "Bow.h"
#include "Axe.h"

AInventoryController::AInventoryController() 
{
	InventorySlotLimit = 50;
	InventoryWeightLimit = 500;
}

void AInventoryController::UseItem(FInventoryItem Item)
{
	auto* BaseItem = Item.BaseItem.GetDefaultObject();
	BaseItem->Use(this);
}

bool AInventoryController::DropItem(FInventoryItem Item)
{
	auto* BaseItem = Item.BaseItem.GetDefaultObject();

	return BaseItem->Drop(this, Item);
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
			MissionCheck(1, ItemToAdd->MissionGoal, ItemToAdd->Target);
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
		MissionCheck(1, Item.MissionGoal, Item.Target);
		return true;
	}
	return false;
}

FInventoryItem AInventoryController::FindItemByIDBP(FName ID)
{
	AInventoryGameState* GameState = Cast<AInventoryGameState>(GetWorld()->GetGameState());
	UDataTable* ItemTable = GameState->GetItemDB();
	FInventoryItem* ItemToAdd = ItemTable->FindRow<FInventoryItem>(ID, "");

	return *ItemToAdd;
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
	InputComponent->BindAction("MeleeWeapon", IE_Pressed, this, &AInventoryController::AttachMeleeWeapon);
	InputComponent->BindAction("RangeWeapon", IE_Pressed, this, &AInventoryController::AttachRangeWeapon);
	InputComponent->BindAction("LMBAction", IE_Pressed, this, &AInventoryController::TryAttack);
}

void AInventoryController::TryAttack()
{
	if(ActiveWeapon)
	{
		ActiveWeapon->Attack(this);
	}
}

void AInventoryController::AttachMeleeWeapon()
{
	if(MeleeWeapon)
	{
		auto* DefaultMeleeWeapon = MeleeWeapon.GetDefaultObject();
		if(DefaultMeleeWeapon->CheckUnequip(this))
			return;
		DefaultMeleeWeapon->Equip(this);
	}
}

void AInventoryController::AttachRangeWeapon()
{
	if(RangeWeapon)
	{
		auto* DefaultRangeWeapon = RangeWeapon.GetDefaultObject();
		if(DefaultRangeWeapon->CheckUnequip(this))
			return;
		DefaultRangeWeapon->Equip(this);
	}
}

void AInventoryController::Interact()
{
	if (CurrentInteractable)
	{
		CurrentInteractable->Interact(this);
	}
}

bool AInventoryController::MissionCheck(int missionChange, TEnumAsByte<EQuestMissionGoal> CurrMissionGoal,
	TEnumAsByte<ETargetType> CurrTarget)
{
	if(IsValid(CurrentMission))
	{
		if(missionChange >= 0)
		{
			if(CurrentMission->MissionGoal == CurrMissionGoal && CurrentMission->Target == CurrTarget && !CurrentMission->IsComplete)
			{
				CurrentMission->MissionProgress(missionChange, this);
				return true;
			}
		}
		if(CurrentMission->MissionGoal == CurrMissionGoal && CurrentMission->Target == CurrTarget && !CurrentMission->IsGetReward)
		{
			CurrentMission->MissionRegress(missionChange, this);
			return true;
		}
	}
	return false;
}

void AInventoryController::SetMission(UQuestMissionInfo* MissionInfo)
{
	CurrentMission = MissionInfo;
	for(auto Item : Inventory)
	{
		MissionCheck(1, Item.MissionGoal, Item.Target);
	}
}

bool AInventoryController::FinishMission()
{
	if(CurrentMission && CurrentMission->IsComplete && !CurrentMission->IsGetReward)
	{
		CurrentMission->GetReward(this);
		RemoveItems(CurrentMission);
		CurrentMission = nullptr;
		UpdateMissionInfo();
		return true;
	}
	return false;
}

void AInventoryController::RemoveItems(UQuestMissionInfo* MissionInfo)
{
	if(MissionInfo->IsGetReward)
	{
		int counter(0);
		for(auto Item: Inventory)
		{
			if(counter >= MissionInfo->MissionMaxProgress)
			{
				break;
			}
			if(CurrentMission->MissionGoal == Item.MissionGoal && CurrentMission->Target == Item.Target)
			{
				counter++;
				RemoveItem(Item);
			}
		}
	}
}

