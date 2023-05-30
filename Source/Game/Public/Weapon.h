// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ManPickup.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

UCLASS()
class GAME_API AWeapon : public AManPickup
{
	GENERATED_BODY()

public:
	AWeapon();

	UFUNCTION(BlueprintNativeEvent)
	void Attack(APlayerController* Controller);
	virtual void Attack_Implementation(APlayerController* Controller);

	UFUNCTION(BlueprintNativeEvent)
	void Equip(APlayerController* Controller);
	virtual void Equip_Implementation(APlayerController* Controller);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool CheckUnequip(APlayerController* Controller);
	virtual bool CheckUnequip_Implementation(APlayerController* Controller);
	
	virtual void Interact_Implementation(APlayerController* Controller) override;

	virtual void Use_Implementation(APlayerController* Controller) override;

	UFUNCTION(BlueprintCallable)
	bool DestroyWeapon();
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int Damage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FVector Position;
	
};
