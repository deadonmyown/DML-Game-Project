// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "QuestStorage.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable, EditInlineNew,DefaultToInstanced)
class GAME_API UQuestStorage : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Instanced)
	TArray<class UQuestMissionInfo*> Quests;
	
};
