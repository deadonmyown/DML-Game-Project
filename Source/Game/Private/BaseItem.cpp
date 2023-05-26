// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseItem.h"
#include "FPCharacter.h"
#include "ManPickup.h"


// Sets default values
ABaseItem::ABaseItem()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ABaseItem::Use_Implementation(APlayerController* Controller)
{
	//pox
}

bool ABaseItem::Drop_Implementation(APlayerController* Controller)
{
	AFPCharacter* Character = Cast<AFPCharacter>(UGameplayStatics::GetPlayerPawn(Controller->GetWorld(), 0));
	const UWorld* World = Controller->GetWorld();
	UClass* const ActorClassToSpawn = GetClass();
	if (World && ActorClassToSpawn)
	{
		FActorSpawnParameters SpawnParameters = FActorSpawnParameters();
		SpawnParameters.Template = this;
		if(auto* Spawned = Controller->GetWorld()->SpawnActor<ABaseItem>(ActorClassToSpawn,  FVector::ZeroVector, FRotator::ZeroRotator, SpawnParameters))
		{
			Spawned->SetActorLocation(Character->GetActorLocation() + Character->GetActorForwardVector() * Character->DropItemMultiplier);
			return true;
		}
	}
	return false;
}

