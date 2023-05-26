// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
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

	/** Function to collect every AutoPickup in range. */
	void CollectAutoPickups();

	/** Function to check for the closest Interactable in sight and in range. */
	void CheckForInteractables();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(BlueprintReadOnly)
	bool IsQuestAvailable;

	UPROPERTY(BlueprintReadOnly)
	bool IsShopAvailable;

	UPROPERTY(BlueprintReadOnly)
	UQuestMissionInfo * CurrentMission = nullptr;

	UPROPERTY(BlueprintReadOnly)
	class UQuestInfo* CurrentQuest = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int Health;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int DropItemMultiplier;

	void QuestTest();
	UFUNCTION(BlueprintCallable)
	void SetQuest(UQuestInfo* Quest);

	UPROPERTY(EditAnywhere, Category = "Camera")
	UCameraComponent* Cam;

	/** Collection sphere */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USphereComponent* CollectionSphere;
	
private:
	void HorizontalMovement(float input);
	void VerticalMovement(float input);

	void HorizontalRotation(float input);
	void VerticalRotation(float input);

	TSubclassOf<class AAutoPickup> AutoPickup; 
};
