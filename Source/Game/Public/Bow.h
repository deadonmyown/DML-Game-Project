// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "GameFramework/Actor.h"
#include "Bow.generated.h"

UCLASS()
class GAME_API ABow : public AWeapon
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABow();

	virtual void Attack_Implementation(APlayerController* Controller) override;

	virtual void Equip_Implementation(APlayerController* Controller) override;

	virtual bool CheckUnequip_Implementation(APlayerController* Controller) override;
	
	virtual void Interact_Implementation(APlayerController* Controller) override;

	virtual void Use_Implementation(APlayerController* Controller) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<class AArrow> Arrow;
};
