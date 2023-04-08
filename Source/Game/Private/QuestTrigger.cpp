// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestTrigger.h"
#include "FPCharacter.h"
#include "QuestMissionInfo.h"

// Sets default values
AQuestTrigger::AQuestTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComponent"));
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AQuestTrigger::OnOverlapBegin);
	BoxComponent->OnComponentEndOverlap.AddDynamic(this, &AQuestTrigger::OnOverlapEnd);
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = BoxComponent;
	Mesh->SetupAttachment(BoxComponent);
}

// Called when the game starts or when spawned
void AQuestTrigger::BeginPlay()
{
	Super::BeginPlay();
	// SphereComponent = CreateDefaultSubobject<USphereComponent>(FName(TEXT("CollisionComponent")));
	// SphereComponent->SetRelativeLocation(FVector::ZeroVector);
	// SphereComponent->SetSphereRadius(20.0f);
}

// Called every frame
void AQuestTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AQuestTrigger::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, 
					  AActor* OtherActor, 
					  UPrimitiveComponent* OtherComp, 
					  int32 OtherBodyIndex, 
					  bool bFromSweep, 
					  const FHitResult &SweepResult )
{
	AFPCharacter* player = Cast<AFPCharacter>(OtherActor);
	if(player != nullptr)
	{
		UE_LOG(LogTemp, Display, TEXT("overlap player begin"));
		player->IsQuestAvailable = true;
		UQuestMissionInfo* Mission = NewObject<UQuestMissionInfo>();
		Mission->Description = "aaaaaa " + FString::FromInt(Missions.Num());
		Mission->Reward = 10;
		Mission->MissionCurrentProgress = 0;
		Mission->MissionMaxProgress = 1;
		Missions.Add(Mission);
		player->CurrentMission = Mission;
		UE_LOG(LogTemp, Display, TEXT("Mission info: c.p: %i \t m.p: %i \t reward: %i"), player->CurrentMission->MissionCurrentProgress, player->CurrentMission->MissionMaxProgress, player->CurrentMission->Reward);
	}
}

void AQuestTrigger::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	AFPCharacter* player = Cast<AFPCharacter>(OtherActor);
	if(player != nullptr)
	{
		UE_LOG(LogTemp, Display, TEXT("overlap player end"));
		player->IsQuestAvailable = false;
		UE_LOG(LogTemp, Display, TEXT("%s succeed"), *Missions.Last()->Description);
		player->QuestTest();
	}
}



