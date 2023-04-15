// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "QuestMissionType.generated.h"

/**
 * 
 */
UCLASS(Abstract, BlueprintType, Blueprintable, EditInlineNew,DefaultToInstanced)
class GAME_API UQuestMissionType : public UObject
{
	GENERATED_BODY()

public:
	UQuestMissionType();
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TEnumAsByte<enum EQuestMissionGoal> MissionGoal;
};
