// Fill out your copyright notice in the Description page of Project Settings.


#include "Vendor.h"

// Sets default values
AVendor::AVendor()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComponent"));
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AVendor::OnOverlapBegin);
	BoxComponent->OnComponentEndOverlap.AddDynamic(this, &AVendor::OnOverlapEnd);
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

void AVendor::BuyItem(AFPCharacter* Character, AItem* Item)
{
	if(Shop && Character && Item)
	{
		Shop->BuyItem(Character, Item);
	}
}


void AVendor::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AFPCharacter* player = Cast<AFPCharacter>(OtherActor);
	if(player != nullptr)
	{
		UE_LOG(LogTemp, Display, TEXT("overlap player begin"));
		player->IsShopAvailable = true;
	}
}


void AVendor::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	AFPCharacter* player = Cast<AFPCharacter>(OtherActor);
	if(player != nullptr)
	{
		UE_LOG(LogTemp, Display, TEXT("overlap player end"));
		player->IsShopAvailable = false;
	}
}

