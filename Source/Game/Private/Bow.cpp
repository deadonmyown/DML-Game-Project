
#include "Bow.h"

#include "FPCharacter.h"
#include "InventoryController.h"
#include "Arrow.h"


ABow::ABow()
{
	Name = "Bow";
}

void ABow::Attack_Implementation(APlayerController* Controller)
{
	if(Arrow)
	{
		auto* NewArrow = Arrow.GetDefaultObject();
		NewArrow->Shoot(Controller, this);
	}
}

void ABow::Equip_Implementation(APlayerController* Controller)
{
	//Super::Equip_Implementation(Controller);
	if(AInventoryController* IController = Cast<AInventoryController>(Controller))
	{
		if(IController->ActiveWeapon)
		{
			IController->ActiveWeapon->Destroy();
			IController->ActiveWeapon = nullptr;
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
			}
		}
	}
}

bool ABow::CheckUnequip_Implementation(APlayerController* Controller)
{
	if(AInventoryController* IController = Cast<AInventoryController>(Controller))
	{
		if(ABow* Bow = Cast<ABow>(IController->ActiveWeapon))
		{
			IController->ActiveWeapon->Destroy();
			IController->ActiveWeapon = nullptr;
			return true;
		}
	}
	return false;
}

void ABow::Interact_Implementation(APlayerController* Controller)
{
	Super::Interact_Implementation(Controller);
}

void ABow::Use_Implementation(APlayerController* Controller)
{
	if(AInventoryController* IController = Cast<AInventoryController>(Controller))
	{
		FInventoryItem Item = IController->FindItemByIDBP(ItemID);
		IController->SetWeaponWidget(Item);
	}
}

