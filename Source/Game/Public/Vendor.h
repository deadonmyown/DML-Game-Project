// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ShopComponent.h"
#include "InventoryItem.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Pawn.h"
#include "Vendor.generated.h"

UCLASS()
class GAME_API AVendor : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AVendor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBoxComponent* BoxComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UShopComponent* Shop;

	UFUNCTION(BlueprintCallable)
	void BuyItem(APlayerController* PlayerController, FInventoryItem Item);

	UFUNCTION(BlueprintCallable)
	void SellItem(APlayerController* PlayerController, FInventoryItem Item);

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
