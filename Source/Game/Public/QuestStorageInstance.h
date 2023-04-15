// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "QuestStorageInstance.generated.h"

/**
 * 
 */
UCLASS()
class GAME_API UQuestStorageInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<class UQuestMissionInfo*> Quests;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<class UQuestInfo*> QuestTest;
};
