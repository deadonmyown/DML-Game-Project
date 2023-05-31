#pragma once

#include "CoreMinimal.h"
#include "BaseItem.h"
#include "ItemFunctionalityInterface.h"
#include "GameFramework/Actor.h"
#include "AutoPickup.generated.h"

UCLASS()
class GAME_API AAutoPickup : public ABaseItem
{
	GENERATED_BODY()

public:

	AAutoPickup();

	UFUNCTION(BlueprintNativeEvent)
	void Collect(APlayerController* Controller);
	virtual void Collect_Implementation(APlayerController* Controller);

	virtual void Use_Implementation(APlayerController* Controller) override;

	FName GetItemID();

protected:
	UPROPERTY(EditAnywhere)
	USceneComponent* DefaultSceneRoot;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* PickupMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ItemID;
};
