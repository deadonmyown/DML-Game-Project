// Fill out your copyright notice in the Description page of Project Settings.


#include "Vendr.h"

// Sets default values
AVendr::AVendr()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComponent"));
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AVendr::OnOverlapBegin);
	BoxComponent->OnComponentEndOverlap.AddDynamic(this, &AVendr::OnOverlapEnd);
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = BoxComponent;
	Mesh->SetupAttachment(BoxComponent);
	Shop = CreateDefaultSubobject<UShopComponent>("Shop");
}

// Called when the game starts or when spawned
void AVendr::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVendr::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AVendr::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AFPCharacter* player = Cast<AFPCharacter>(OtherActor);
	if(player != nullptr)
	{
		UE_LOG(LogTemp, Display, TEXT("overlap player begin"));
		player->IsShopAvailable = true;
	}
}


void AVendr::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	AFPCharacter* player = Cast<AFPCharacter>(OtherActor);
	if(player != nullptr)
	{
		UE_LOG(LogTemp, Display, TEXT("overlap player end"));
		player->IsShopAvailable = false;
	}
}


