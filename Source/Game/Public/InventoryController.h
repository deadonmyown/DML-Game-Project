// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Interactable.h"
#include "InventoryItem.h"
#include "InventoryController.generated.h"

/**
 * 
 */
UCLASS()
class GAME_API AInventoryController : public APlayerController
{
	GENERATED_BODY()

public:
	AInventoryController();
	
	//Quest System
	UFUNCTION(BlueprintImplementableEvent)
	void UpdateMissionInfo();
	
	UFUNCTION(BlueprintCallable)
	bool MissionCheck(int missionChange, TEnumAsByte<enum EQuestMissionGoal> CurrMissionGoal, TEnumAsByte<ETargetType> CurrTarget);

	UFUNCTION(BlueprintCallable)
	void SetMission(class UQuestMissionInfo* MissionInfo);
	
	UFUNCTION(BlueprintCallable)
	bool FinishMission();
	
	UFUNCTION(BlueprintCallable)
	void RemoveItems(UQuestMissionInfo* MissionInfo);
	//

	//Inventory System
	UFUNCTION(BlueprintImplementableEvent)
	void ReloadInventory();

	UFUNCTION(BlueprintImplementableEvent)
	void RemoveItem(FInventoryItem Item);

	UFUNCTION(BlueprintCallable)
	void UseItem(FInventoryItem Item);

	UFUNCTION(BlueprintCallable)
	bool DropItem(FInventoryItem Item);
	
	UFUNCTION(BlueprintCallable, Category = "Utils")
	int32 GetInventoryWeight();

	UFUNCTION(BlueprintCallable, Category = "Utils")
	bool AddItemToInventoryByID(FName ID);

	UFUNCTION(BlueprintCallable, Category = "Utils")
	bool AddItemToInventory(FInventoryItem Item);
	
	FInventoryItem* FindItemByID(FName ID);
	//
	
	//Character Info
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int32 Money;
	//
	
	//Quest System
	UPROPERTY(BlueprintReadOnly)
	UQuestMissionInfo * CurrentMission = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int32 QuestsCompleted;
	//
	
	//Inventory System
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	AInteractable* CurrentInteractable;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<FInventoryItem> Inventory;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 InventorySlotLimit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 InventoryWeightLimit;
	//
	
	//Weapons
	UFUNCTION(BlueprintCallable)
	void TryAttack();

	void AttachMeleeWeapon();
	void AttachRangeWeapon();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class AAxe* MeleeWeapon = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class ABow* RangeWeapon = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class AWeapon* ActiveWeapon = nullptr;
	//

protected:
	//Inventory System
	void Interact();
	//
	
	virtual void SetupInputComponent() override;
	
};
