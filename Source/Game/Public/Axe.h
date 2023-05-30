// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "Axe.generated.h"

UCLASS()
class GAME_API AAxe : public AWeapon
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAxe();

	virtual void Attack_Implementation(APlayerController* Controller) override;

	virtual void Equip_Implementation(APlayerController* Controller) override;

	virtual bool CheckUnequip_Implementation(APlayerController* Controller) override;
	
	virtual void Interact_Implementation(APlayerController* Controller) override;

	virtual void Use_Implementation(APlayerController* Controller) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	USphereComponent* AttackSphere;
};
