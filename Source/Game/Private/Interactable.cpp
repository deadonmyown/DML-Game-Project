#include "Interactable.h"

AInteractable::AInteractable()
{
	Name = "Interactable";
	Action = "interact";

}

void AInteractable::Interact_Implementation(APlayerController* Controller)
{
	
}

void AInteractable::Use_Implementation(APlayerController* Controller)
{
	UE_LOG(LogTemp, Display, TEXT("Interactable item, Name: %s, Action: %s"), *Name, *Action);
}

FString AInteractable::GetInteractText() const 
{
	return FString::Printf(TEXT("%s: Press F to %s"), *Name, *Action); 
}
