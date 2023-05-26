#include "ManPickup.h"
#include "InventoryController.h"

AManPickup::AManPickup()
{
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>("PickupMesh");
	RootComponent = Cast<USceneComponent>(PickupMesh);

	ItemID = FName("No ID");

	Name = "Item";
	Action = "pickup";
}

void AManPickup::Interact_Implementation(APlayerController* Controller)
{
	Super::Interact_Implementation(Controller);

	AInventoryController* IController = Cast<AInventoryController>(Controller);
	if(IController->AddItemToInventoryByID(ItemID))
		Destroy();
}

void AManPickup::Use_Implementation(APlayerController* Controller)
{
	UE_LOG(LogTemp, Display, TEXT("Manual pickup item, Name: %s, Action: %s"), *Name, *Action);
	UE_LOG(LogTemp, Display, TEXT("ItemID: %s"), *ItemID.ToString());
	if(AInventoryController* IController = Cast<AInventoryController>(Controller))
	{
		FInventoryItem* Item = IController->FindItemByID(ItemID);
		IController->RemoveItem(*Item);
	}
}
