#include "AutoPickup.h"
#include "InventoryController.h"

AAutoPickup::AAutoPickup()
{
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>("PickupMesh");
	RootComponent = PickupMesh;

	ItemID = FName("No ID");
}

void AAutoPickup::Collect_Implementation(APlayerController* Controller)
{
	AInventoryController* IController = Cast<AInventoryController>(Controller);
	if(IController->AddItemToInventoryByID(ItemID))
		Destroy();
}

void AAutoPickup::Use_Implementation(APlayerController* Controller)
{
	UE_LOG(LogTemp, Display, TEXT("ItemID: %s"), *ItemID.ToString());
}

FName AAutoPickup::GetItemID()
{
	return ItemID;
}
