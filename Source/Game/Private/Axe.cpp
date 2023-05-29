﻿
#include "Axe.h"

#include "FPCharacter.h"
#include "InventoryController.h"


AAxe::AAxe()
{
	AttackSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollectionSphere"));
	AttackSphere->SetupAttachment(RootComponent);
	AttackSphere->SetSphereRadius(85.f);

	Name = "Axe";
}

void AAxe::Attack_Implementation()
{
	TArray<AActor*> OverlappedActors;
	AttackSphere->GetOverlappingActors(OverlappedActors);
	for(auto Actor : OverlappedActors)
	{
		if(GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("OverlappedActor: %s"), *Actor->GetName()));
	}
}

void AAxe::Interact_Implementation(APlayerController* Controller)
{
	Super::Interact_Implementation(Controller);
}

void AAxe::Use_Implementation(APlayerController* Controller)
{
	if(AInventoryController* IController = Cast<AInventoryController>(Controller))
	{
		if(IController->ActiveWeapon)
		{
			IController->ActiveWeapon->DestroyWeapon();
			IController->MeleeWeapon = nullptr;
		}

		AFPCharacter* FPCharacter = Cast<AFPCharacter>(IController->GetCharacter());
		const UWorld* World = IController->GetWorld();
		UClass* const ActorClassToSpawn = GetClass();
		if (World && ActorClassToSpawn)
		{
			FActorSpawnParameters SpawnParameters = FActorSpawnParameters();
			SpawnParameters.Template = this;
			if(auto* Spawned = IController->GetWorld()->SpawnActor<AAxe>(ActorClassToSpawn,  FVector::ZeroVector, FRotator::ZeroRotator, SpawnParameters))
			{
				Spawned->AttachToActor(FPCharacter, FAttachmentTransformRules::KeepRelativeTransform);
				Spawned->AttachToComponent(FPCharacter->Cam, FAttachmentTransformRules::KeepRelativeTransform);
				Spawned->SetActorRelativeLocation(Position);
				IController->ActiveWeapon = Spawned;
				IController->MeleeWeapon = Spawned;
			}
		}
	}
}

