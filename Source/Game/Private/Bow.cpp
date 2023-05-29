
#include "Bow.h"

#include "FPCharacter.h"
#include "InventoryController.h"


ABow::ABow()
{
	Name = "Bow";
}

void ABow::Attack_Implementation()
{
	Super::Attack_Implementation();
}

void ABow::Interact_Implementation(APlayerController* Controller)
{
	Super::Interact_Implementation(Controller);
}

void ABow::Use_Implementation(APlayerController* Controller)
{
	if(AInventoryController* IController = Cast<AInventoryController>(Controller))
	{
		if(IController->ActiveWeapon)
		{
			IController->ActiveWeapon->DestroyWeapon();
			IController->RangeWeapon = nullptr;
		}

		AFPCharacter* FPCharacter = Cast<AFPCharacter>(IController->GetCharacter());
		const UWorld* World = IController->GetWorld();
		UClass* const ActorClassToSpawn = GetClass();
		if (World && ActorClassToSpawn)
		{
			FActorSpawnParameters SpawnParameters = FActorSpawnParameters();
			SpawnParameters.Template = this;
			if(auto* Spawned = IController->GetWorld()->SpawnActor<ABow>(ActorClassToSpawn,  FVector::ZeroVector, FRotator::ZeroRotator, SpawnParameters))
			{
				Spawned->AttachToActor(FPCharacter, FAttachmentTransformRules::KeepRelativeTransform);
				Spawned->AttachToComponent(FPCharacter->Cam, FAttachmentTransformRules::KeepRelativeTransform);
				Spawned->SetActorRelativeLocation(Position);
				IController->ActiveWeapon = Spawned;
				IController->RangeWeapon = Spawned;
			}
		}
	}
}

