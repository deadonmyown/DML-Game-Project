// Fill out your copyright notice in the Description page of Project Settings.


#include "Vendor.h"

// Sets default values
AVendor::AVendor()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComponent"));
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = BoxComponent;
	Mesh->SetupAttachment(BoxComponent);
	Shop = CreateDefaultSubobject<UShopComponent>("Shop");
}

// Called when the game starts or when spawned
void AVendor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVendor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AVendor::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AVendor::BuyItem(APlayerController* PlayerController, FInventoryItem Item)
{
	if(Controller)
	{
		Shop->BuyItem(PlayerController, Item);
	}
}

void AVendor::SellItem(APlayerController* PlayerController, FInventoryItem Item)
{
	if(Controller)
	{
		Shop->SellItem(PlayerController, Item);
	}
}


