
#pragma once

#include "CoreMinimal.h"
#include "ManPickup.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "Arrow.generated.h"

UCLASS()
class GAME_API AArrow : public AManPickup
{
	GENERATED_BODY()

public:
	AArrow();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	USphereComponent* AttackSphere;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int Damage;

	UFUNCTION()
	void Shoot(APlayerController* Controller, class ABow* Bow);

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float Speed;

public:
	virtual void Tick(float DeltaTime) override;
};
