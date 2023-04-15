// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "QuestMissionInfo.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable, EditInlineNew,DefaultToInstanced)
class GAME_API UQuestMissionInfo : public UObject
{
	GENERATED_BODY()

public:
	UQuestMissionInfo();
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    TEnumAsByte<enum EQuestMissionGoal> MissionGoal;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    TEnumAsByte<enum ETargetType> Target;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FString Description;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int MissionCurrentProgress;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int MissionMaxProgress;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int Reward;

	UPROPERTY(BlueprintReadOnly)
	bool IsComplete;

	UFUNCTION()
	int MissionProgress(int progress);
};
