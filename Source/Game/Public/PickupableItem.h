/*
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Components/BoxComponent.h"
#include "PickupableItem.generated.h"


UCLASS(Abstract, BlueprintType)
class GAME_API APickupableItem : public AItem
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	APickupableItem();

protected:
	virtual void Use(AFPCharacter* Character) override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBoxComponent* BoxComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool IsOnLevel = false;

	virtual void PickupItem(AFPCharacter* Character);
	virtual void DropItem(AFPCharacter* Character);
	
private:
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, 
					  AActor* OtherActor, 
					  UPrimitiveComponent* OtherComp, 
					  int32 OtherBodyIndex, 
					  bool bFromSweep, 
					  const FHitResult &SweepResult );

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
*/
