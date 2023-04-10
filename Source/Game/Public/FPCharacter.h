// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "GameFramework/Character.h"
#include "QuestMissionInfo.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UInventoryComponent* Inventory;

	UPROPERTY()
	UQuestMissionInfo * CurrentMission = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int Silversmith;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int Health;

	void QuestTest();
	UFUNCTION(BlueprintCallable, Category = "Items")
	void UseItem(UItem* Item);

private:
	void HorizontalMovement(float input);
	void VerticalMovement(float input);

	void HorizontalRotation(float input);
	void VerticalRotation(float input);

	UPROPERTY(EditAnywhere, Category = "Camera")
	UCameraComponent* Cam;
};
