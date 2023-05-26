#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "ManPickup.generated.h"


/**
 * 
 */
UCLASS()
class GAME_API AManPickup : public AInteractable
{
	GENERATED_BODY()

public:
	AManPickup();
	
	virtual void Interact_Implementation(APlayerController* Controller) override;

	virtual void Use_Implementation(APlayerController* Controller) override;

protected:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* PickupMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ItemID;
};
