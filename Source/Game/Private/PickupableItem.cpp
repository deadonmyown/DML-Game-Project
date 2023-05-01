// Fill out your copyright notice in the Description page of Project Settings.


#include "PickupableItem.h"
#include "FPCharacter.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APickupableItem::APickupableItem()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComponent"));
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &APickupableItem::OnOverlapBegin);
	BoxComponent->OnComponentEndOverlap.AddDynamic(this, &APickupableItem::OnOverlapEnd);
	RootComponent = BoxComponent;
	PickupMesh->SetupAttachment(BoxComponent);
}

void APickupableItem::Use(AFPCharacter* Character)
{
	//TODO: Drop item ☺ just for testing instantiate of the actor. Spawn actor before removing
	Character->Inventory->SpawnItem(Character, this);
	Character->Inventory->RemoveItem(this);
}

void APickupableItem::Initialize(FText useText, UTexture2D* thumbnail, FText displayName, FText description)
{
	UseText = useText;
	Thumbnail = thumbnail;
	DisplayName = displayName;
	Description = description;
}


void APickupableItem::PickupItem(AFPCharacter* Character)
{
	if(GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("PickupableItem added")));
	Character->Inventory->AddItem(this);
	PickupMesh->SetHiddenInGame(true);
	PickupMesh->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	BoxComponent->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
}

void APickupableItem::DropItem(AFPCharacter* Character)
{
	if(GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, FString::Printf(TEXT("PickupableItem dropped")));
	PickupMesh->SetHiddenInGame(false);
	PickupMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	BoxComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SetActorLocation(Character->GetActorLocation() + Character->GetActorForwardVector() * Character->DropItemMultiplier);
}


void APickupableItem::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
                                     bool bFromSweep, const FHitResult& SweepResult)
{
	AFPCharacter* player = Cast<AFPCharacter>(OtherActor);
	if(player)
	{
		player->IsOverlapItem = true;
	}
}

void APickupableItem::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	AFPCharacter* player = Cast<AFPCharacter>(OtherActor);
	if(player)
	{
		player->IsOverlapItem = false;
	}
}

