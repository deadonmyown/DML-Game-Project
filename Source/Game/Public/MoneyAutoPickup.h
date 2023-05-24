#pragma once

#include "CoreMinimal.h"
#include "AutoPickup.h"
#include "MoneyAutoPickup.generated.h"

UCLASS()
class GAME_API AMoneyAutoPickup : public AAutoPickup
{
	GENERATED_BODY()

public:
	AMoneyAutoPickup();
	
	virtual void Collect_Implementation(APlayerController* Controller) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Value;
	
};
