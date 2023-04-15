// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "QuestInfo.generated.h"

/**
 * 
 */
UCLASS()
class GAME_API UQuestInfo : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<class UQuestMissionInfo*> Quests;
	
	UPROPERTY(BlueprintReadOnly)
	bool IsComplete;

	
};
