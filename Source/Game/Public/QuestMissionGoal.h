// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "QuestMissionGoal.generated.h"

UENUM(BlueprintType, Category="MissionGoal")
enum EQuestMissionGoal
{
	EQMG_Kill UMETA(DisplayName = "Kill"),
	EQMG_Collect UMETA(DisplayName = "Collect"),
};
