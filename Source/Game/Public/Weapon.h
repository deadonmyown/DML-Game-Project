/*
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickupableItem.h"
#include "Weapon.generated.h"

/**
 * 
 #1#
UCLASS(Abstract, BlueprintType)
class GAME_API AWeapon : public APickupableItem
{
	GENERATED_BODY()
public:
	AWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int Damage;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool IsActive;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FVector Position;

	void SpawnItem(AFPCharacter* Character, AWeapon* Weapon);

	virtual void Use(AFPCharacter* Character) override;
	
	virtual void PickupItem(AFPCharacter* Character) override;
	virtual void DropItem(AFPCharacter* Character) override;

public:
	virtual void Attack();
};
*/
