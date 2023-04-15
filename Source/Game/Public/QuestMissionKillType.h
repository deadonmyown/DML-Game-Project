// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "QuestMissionType.h"
#include "QuestMissionKillType.generated.h"

/**
 * 
 */
UCLASS()
class GAME_API UQuestMissionKillType : public UQuestMissionType
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TEnumAsByte<enum ETargetType> Target;
};
