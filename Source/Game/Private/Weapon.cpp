// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"
#include "FPCharacter.h"

AWeapon::AWeapon()
{
	PrimaryActorTick.bCanEverTick = false;
	PickupMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	IsActive = false;
}

void AWeapon::BeginPlay()
{
	Super::BeginPlay();
}


void AWeapon::Use(AFPCharacter* Character)
{
	//Super::Use(Character);
	if(IsActive)
	{
		PickupMesh->SetHiddenInGame(true);
		BoxComponent->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
		Character->EquippedWeapon = nullptr;
		IsActive = false;
		return;
	}
	if(GetWorld())
	{
		PickupMesh->SetHiddenInGame(false);
		BoxComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	}
	else
	{
		UWorld* const world = Character->GetWorld();
		UClass* const actorClassToSpawn = GetClass();
		if (world && actorClassToSpawn)
		{
			FActorSpawnParameters SpawnParameters = FActorSpawnParameters();
			SpawnParameters.Template = this;
			AWeapon* const spawned = GetWorld()->SpawnActor<AWeapon>(actorClassToSpawn,  FVector::ZeroVector, FRotator::ZeroRotator, SpawnParameters);
			if(spawned)
			{
				spawned->Initialize(UseText, Thumbnail, DisplayName, Description);
				spawned->AttachToActor(Character, FAttachmentTransformRules::KeepRelativeTransform);
				spawned->SetActorRelativeLocation(Position);
			}
		}
	}
	Character->EquippedWeapon = this;
	IsActive = true;
}

void AWeapon::PickupItem(AFPCharacter* Character)
{
	Super::PickupItem(Character);
	//AttachToActor(Character, FAttachmentTransformRules::KeepRelativeTransform);
	AttachToComponent(Character->Cam, FAttachmentTransformRules::KeepRelativeTransform);
	SetActorRelativeLocation(Position);
}

void AWeapon::DropItem(AFPCharacter* Character)
{
	Super::DropItem(Character);
	DetachFromActor(FDetachmentTransformRules::KeepRelativeTransform);
}

void AWeapon::Attack()
{
	TArray<AActor*> OverlappedActors;
	BoxComponent->GetOverlappingActors(OverlappedActors);
	for(auto Actor : OverlappedActors)
	{
		if(GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("OverlappedActor: %s"), *Actor->GetName()));
	}
}


