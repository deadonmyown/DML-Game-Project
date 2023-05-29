
#include "Weapon.h"

#include "FPCharacter.h"
#include "InventoryController.h"


AWeapon::AWeapon()
{
	ItemID = FName("No ID");

	Name = "Weapon";
	Action = "attach";

}

void AWeapon::Attack_Implementation()
{
}

void AWeapon::Interact_Implementation(APlayerController* Controller)
{
	AInventoryController* IController = Cast<AInventoryController>(Controller);
	if(IController->ActiveWeapon != this)
	{
		if(IController->AddItemToInventoryByID(ItemID))
			Destroy();
	}
}

void AWeapon::Use_Implementation(APlayerController* Controller)
{
	if(AInventoryController* IController = Cast<AInventoryController>(Controller))
	{
		if(IController->ActiveWeapon)
		{
			IController->ActiveWeapon->DestroyWeapon();
		}

		AFPCharacter* FPCharacter = Cast<AFPCharacter>(IController->GetCharacter());
		const UWorld* World = IController->GetWorld();
		UClass* const ActorClassToSpawn = GetClass();
		if (World && ActorClassToSpawn)
		{
			FActorSpawnParameters SpawnParameters = FActorSpawnParameters();
			SpawnParameters.Template = this;
			if(auto* Spawned = IController->GetWorld()->SpawnActor<AWeapon>(ActorClassToSpawn,  FVector::ZeroVector, FRotator::ZeroRotator, SpawnParameters))
			{
				Spawned->AttachToActor(FPCharacter, FAttachmentTransformRules::KeepRelativeTransform);
				Spawned->AttachToComponent(FPCharacter->Cam, FAttachmentTransformRules::KeepRelativeTransform);
				Spawned->SetActorRelativeLocation(Position);
				IController->ActiveWeapon = Spawned;
			}
		}
	}
}

bool AWeapon::DestroyWeapon()
{
	return Destroy();
}

