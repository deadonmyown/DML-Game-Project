#pragma once

#include "CoreMinimal.h"
#include "BaseItem.h"
#include "ItemFunctionalityInterface.h"
#include "GameFramework/Actor.h"
#include "Interactable.generated.h"

UCLASS()
class GAME_API AInteractable : public ABaseItem
{
	GENERATED_BODY()

public:
	AInteractable();

	UFUNCTION(BlueprintNativeEvent)
	void Interact(APlayerController* Controller);
	virtual void Interact_Implementation(APlayerController* Controller);

	virtual void Use_Implementation(APlayerController* Controller) override;

	UPROPERTY(EditDefaultsOnly)
	FString Name;

	UPROPERTY(EditDefaultsOnly)
	FString Action;

	UFUNCTION(BlueprintCallable, Category = "Pickup")
	FString GetInteractText() const;
};
