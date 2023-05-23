// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "GameFramework/Character.h"
#include "QuestMissionInfo.h"
#include "Weapon.h"
#include "Camera/CameraComponent.h"
#include "FPCharacter.generated.h"

UCLASS()
class GAME_API AFPCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(BlueprintReadOnly)
	bool IsQuestAvailable;

	UPROPERTY(BlueprintReadOnly)
	bool IsOverlapItem;

	UPROPERTY(BlueprintReadOnly)
	bool IsShopAvailable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UInventoryComponent* Inventory;

	UPROPERTY(BlueprintReadOnly)
	UQuestMissionInfo * CurrentMission = nullptr;

	UPROPERTY(BlueprintReadOnly)
	class UQuestInfo* CurrentQuest = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int Silversmith;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int Health;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int DropItemMultiplier;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AWeapon* EquippedWeapon;

	void QuestTest();
	UFUNCTION(BlueprintCallable)
	void SetQuest(UQuestInfo* Quest);
	
	UFUNCTION(BlueprintCallable, Category = "Items")
	void UseItem(AItem* Item);

	UPROPERTY(EditAnywhere, Category = "Camera")
	UCameraComponent* Cam;
	
private:
	void HorizontalMovement(float input);
	void VerticalMovement(float input);

	void HorizontalRotation(float input);
	void VerticalRotation(float input);

	void Interact();

	void CheckAttack();

};
