// Fill out your copyright notice in the Description page of Project Settings.


#include "FPCharacter.h"
#include "PickupableItem.h"
#include "Vendor.h"

// Sets default values
AFPCharacter::AFPCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	IsQuestAvailable = false;
	IsOverlapItem = false;
	Health = 100;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	bUseControllerRotationYaw = false;

	Cam = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	Cam->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	Cam->SetRelativeLocation(FVector(35,0,60));

	Inventory = CreateDefaultSubobject<UInventoryComponent>("Inventory");
	Inventory->Capacity = 20;
	
}

// Called when the game starts or when spawned
void AFPCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFPCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("Move Right/Left", this, &AFPCharacter::HorizontalMovement);
	InputComponent->BindAxis("Move Forward/Backward", this, &AFPCharacter::VerticalMovement);
	InputComponent->BindAxis("Horizontal Rotation", this, &AFPCharacter::HorizontalRotation);
	InputComponent->BindAxis("Vertical Rotation", this, &AFPCharacter::VerticalRotation);

	InputComponent->BindAction("Interact", IE_Pressed, this, &AFPCharacter::Interact);
	InputComponent->BindAction("LMBAction", IE_Pressed, this, &AFPCharacter::CheckAttack);
}

void AFPCharacter::HorizontalMovement(float input)
{
	if(input)
	{
		AddMovementInput(GetActorRightVector(), input);
	}
}

void AFPCharacter::VerticalMovement(float input)
{
	if(input)
	{
		AddMovementInput(GetActorForwardVector(), input);
	}
}

void AFPCharacter::HorizontalRotation(float input)
{
	if(input)
	{
		AddActorLocalRotation(FRotator(0, input, 0));
	}
}

void AFPCharacter::VerticalRotation(float input)
{
	if(input)
	{
		float tempRotation = Cam->GetRelativeRotation().Pitch + input;
		
		//UE_LOG(LogTemp, Display, TEXT("rotation: %f"), tempRotation);
		
		if((tempRotation  < 65)  && (tempRotation > -65))
		{
			//UE_LOG(LogTemp, Display, TEXT("rotation before: %f"), Cam->GetRelativeRotation().Pitch);
			Cam->AddLocalRotation(FRotator(input, 0, 0));
			//UE_LOG(LogTemp, Display, TEXT("rotation after: %f"), Cam->GetRelativeRotation().Pitch);
		}
	}
}

void AFPCharacter::Interact()
{
	TArray<AActor*> OverlappingActors;
	if(IsOverlapItem)
	{
		GetOverlappingActors(OverlappingActors, APickupableItem::StaticClass());
		if(OverlappingActors.Num() > 0)
		{
			APickupableItem* FirstItem = Cast<APickupableItem>(OverlappingActors[0]);
			FirstItem->PickupItem(this);
		}
	}
	else
	{
		GetOverlappingActors(OverlappingActors);
		for(AActor* Actor : OverlappingActors)
		{
			AVendor* Vendor = Cast<AVendor>(Actor);
			if(Vendor)
			{
				//TODO: Cho-to
			}
		}
	}
}

void AFPCharacter::CheckAttack()
{
	if(EquippedWeapon)
	{
		EquippedWeapon->Attack();
	}
}



void AFPCharacter::QuestTest()
{
	if(CurrentMission != nullptr)
	{
		if(const int Reward = CurrentMission->MissionProgress(1); Reward != 0)
		{
			Silversmith += Reward;
			CurrentMission = nullptr;
		}
		UE_LOG(LogTemp, Display, TEXT("Ur silversmith: %i"), Silversmith);
	}
}

void AFPCharacter::SetQuest(UQuestInfo* Quest)
{
	CurrentQuest = Quest;

	//TODO: Update UI and maybe implementation of QuestComponent.
}


void AFPCharacter::UseItem(AItem* Item)
{
	if(Item)
	{
		Item->Use(this);
		Item->OnUse(this); //bp
	}
}






