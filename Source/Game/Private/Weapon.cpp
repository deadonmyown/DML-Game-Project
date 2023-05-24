/*// Fill out your copyright notice in the Description page of Project Settings.


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
	if(IsOnLevel && GetWorld())
	{
		PickupMesh->SetHiddenInGame(false);
		BoxComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		Character->EquippedWeapon = this;
		IsActive = true;
	}
	else
	{
		SpawnItem(Character, this);
	}
}

void AWeapon::SpawnItem(AFPCharacter* Character, AWeapon* Weapon)
{
	UWorld* const World = Character->GetWorld();
	UClass* const ActorClassToSpawn = Weapon->GetClass();
	if (World && ActorClassToSpawn)
	{
		FActorSpawnParameters SpawnParameters = FActorSpawnParameters();
		SpawnParameters.Template = Weapon;
		if(AWeapon* const Spawned = GetWorld()->SpawnActor<AWeapon>(ActorClassToSpawn, FVector::ZeroVector, FRotator::ZeroRotator, SpawnParameters))
		{
			Spawned->AttachToActor(Character, FAttachmentTransformRules::KeepRelativeTransform);
			Spawned->AttachToComponent(Character->Cam, FAttachmentTransformRules::KeepRelativeTransform);
			Spawned->SetActorRelativeLocation(Position);
			Character->EquippedWeapon = Spawned;
			Spawned->IsActive = true;
			Spawned->IsOnLevel = true;
		}
	}
}

void AWeapon::PickupItem(AFPCharacter* Character)
{
	if(OwningInventory == nullptr)
	{
		if(GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("PickupableItem added")));
		Character->Inventory->AddItem(this);
		PickupMesh->SetHiddenInGame(true);
		PickupMesh->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
		BoxComponent->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
		AttachToActor(Character, FAttachmentTransformRules::KeepRelativeTransform);
		AttachToComponent(Character->Cam, FAttachmentTransformRules::KeepRelativeTransform);
		SetActorRelativeLocation(Position);
	}
	
}

void AWeapon::DropItem(AFPCharacter* Character)
{
	if(GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, FString::Printf(TEXT("PickupableItem dropped")));
	PickupMesh->SetHiddenInGame(false);
	PickupMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	BoxComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SetActorLocation(Character->GetActorLocation() + Character->GetActorForwardVector() * Character->DropItemMultiplier);
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
}*/