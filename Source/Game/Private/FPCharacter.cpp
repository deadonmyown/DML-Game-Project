// Fill out your copyright notice in the Description page of Project Settings.


#include "FPCharacter.h"
#include "Interactable.h"
#include "AutoPickup.h"
#include "InventoryItem.h"
#include "InventoryController.h"

// Sets default values
AFPCharacter::AFPCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	IsQuestAvailable = false;
	Health = 100;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	bUseControllerRotationYaw = false;

	Cam = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	Cam->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	Cam->SetRelativeLocation(FVector(35,0,60));

	// Create the collection sphere
	CollectionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollectionSphere"));
	CollectionSphere->SetupAttachment(RootComponent);
	CollectionSphere->SetSphereRadius(200.f);
	
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

	CollectAutoPickups();
	CheckForInteractables();
}

void AFPCharacter::CollectAutoPickups()
{
	// Get all overlapping Actors and store them in an array
	TArray<AActor*> CollectedActors;
	CollectionSphere->GetOverlappingActors(CollectedActors);

	AInventoryController* IController = Cast<AInventoryController>(GetController());

	// For each collected Actor
	for (int32 iCollected = 0; iCollected < CollectedActors.Num(); ++iCollected)
	{
		// Cast the actor to AAutoPickup
		AAutoPickup* const TestPickup = Cast<AAutoPickup>(CollectedActors[iCollected]);
		// If the cast is successful and the pickup is valid and active 
		if (IsValid(TestPickup))
		{
			TestPickup->Collect(IController);
		}
	}
}

void AFPCharacter::CheckForInteractables()
{
	// Create a LineTrace to check for a hit
	FHitResult HitResult;

	int32 Range = 500;
	FVector StartTrace = Cam->GetComponentLocation();
	FVector EndTrace = (Cam->GetForwardVector() * Range) + StartTrace;

	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);

	AInventoryController* IController = Cast<AInventoryController>(GetController());

	if (IController)
	{
		// Check if something is hit
		if (GetWorld()->LineTraceSingleByChannel(HitResult, StartTrace, EndTrace, ECC_Visibility, QueryParams))
		{
			// Cast the actor to AInteractable
			AInteractable* Interactable = Cast<AInteractable>(HitResult.GetActor());
			// If the cast is successful
			if (Interactable)
			{
				IController->CurrentInteractable = Interactable;
				return;
			}
		}

		IController->CurrentInteractable = nullptr;
	}
}

// Called to bind functionality to input
void AFPCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("Move Right/Left", this, &AFPCharacter::HorizontalMovement);
	InputComponent->BindAxis("Move Forward/Backward", this, &AFPCharacter::VerticalMovement);
	InputComponent->BindAxis("Horizontal Rotation", this, &AFPCharacter::HorizontalRotation);
	InputComponent->BindAxis("Vertical Rotation", this, &AFPCharacter::VerticalRotation);

	/*InputComponent->BindAction("Interact", IE_Pressed, this, &AFPCharacter::Interact);
	InputComponent->BindAction("LMBAction", IE_Pressed, this, &AFPCharacter::CheckAttack);*/
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



void AFPCharacter::QuestTest()
{
	if(CurrentMission != nullptr)
	{
		if(AInventoryController* controller = Cast<AInventoryController>(GetController()))
		{
			if(const int Reward = CurrentMission->MissionProgress(1); Reward != 0)
			{
				controller->Money += Reward;
				CurrentMission = nullptr;
			}
			UE_LOG(LogTemp, Display, TEXT("Ur silversmith: %i"), controller->Money);
		}
	}
}

void AFPCharacter::SetQuest(UQuestInfo* Quest)
{
	CurrentQuest = Quest;

	//TODO: Update UI and maybe implementation of QuestComponent.
}






