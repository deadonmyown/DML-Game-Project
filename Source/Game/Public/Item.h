// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryComponent.h"
#include "UObject/NoExportTypes.h"
#include "Item.generated.h"

/**
 * 
 */
UCLASS(Abstract, BlueprintType, Blueprintable, EditInlineNew,DefaultToInstanced)
class GAME_API UItem : public UObject
{
	GENERATED_BODY()

public:
	UItem();

	virtual UWorld* GetWorld() const {return World; };

	UPROPERTY(Transient)
	UWorld* World;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Item")
	FText UseText;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Item")
	UStaticMesh* PickupMesh;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item")
	UTexture2D* Thumbnail;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Item")
	FText DisplayName;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Item", meta = (MultiLine = true))
	FText Description;

	UPROPERTY()
	UInventoryComponent* OwningInventory;

	virtual void Use(class AFPCharacter* Character);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUse(class AFPCharacter* Character);
};
