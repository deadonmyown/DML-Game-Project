// Fill out your copyright notice in the Description page of Project Settings.


#include "Arrow.h"

#include "FPCharacter.h"
#include "InventoryController.h"


// Sets default values
AArrow::AArrow()
{
	PrimaryActorTick.bCanEverTick = true;
	
	AttackSphere = CreateDefaultSubobject<USphereComponent>(TEXT("AttackSphere"));
	AttackSphere->SetupAttachment(RootComponent);
	AttackSphere->SetSphereRadius(50.f);

	Name = "Arrow";
}

void AArrow::Shoot(APlayerController* Controller, ABow* Bow)
{
	if(AInventoryController* IController = Cast<AInventoryController>(Controller))
	{
		AFPCharacter* FPCharacter = Cast<AFPCharacter>(IController->GetCharacter());
		const UWorld* World = IController->GetWorld();
		UClass* const ActorClassToSpawn = GetClass();
		if (World && ActorClassToSpawn)
		{
			FActorSpawnParameters SpawnParameters = FActorSpawnParameters();
			SpawnParameters.Template = this;
			if(auto* Spawned = IController->GetWorld()->SpawnActor<AArrow>(ActorClassToSpawn,  FVector::ZeroVector, FRotator::ZeroRotator, SpawnParameters))
			{
				Spawned->SetActorLocation(FPCharacter->GetActorLocation() + FPCharacter->GetActorForwardVector() * 20);
			}
		}
	}
}

void AArrow::BeginPlay()
{
	Super::BeginPlay();
	
}

void AArrow::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

