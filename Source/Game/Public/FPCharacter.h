// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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

	UPROPERTY()
	UQuestMissionInfo * CurrentMission = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int Silversmith;

	void QuestTest();

private:
	void HorizontalMovement(float input);
	void VerticalMovement(float input);

	void HorizontalRotation(float input);
	void VerticalRotation(float input);

	UPROPERTY(EditAnywhere, Category = "Camera")
	UCameraComponent* Cam;
};
