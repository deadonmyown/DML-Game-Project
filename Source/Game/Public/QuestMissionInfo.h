// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "QuestMissionInfo.generated.h"

/**
 * 
 */
UCLASS()
class GAME_API UQuestMissionInfo : public UObject
{
	GENERATED_BODY()

public:
	UQuestMissionInfo();
	
	UPROPERTY()
	FString Description;
	UPROPERTY()
	int MissionCurrentProgress;
	UPROPERTY()
	int MissionMaxProgress;
	UPROPERTY()
	int Reward;

	UFUNCTION()
	int MissionProgress(int progress);
};
