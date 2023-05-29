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
	void Attack();
	virtual void Attack_Implementation();
	
	virtual void Interact_Implementation(APlayerController* Controller) override;

	virtual void Use_Implementation(APlayerController* Controller) override;

	UFUNCTION(BlueprintCallable)
	bool DestroyWeapon();
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int Damage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FVector Position;
	
};
