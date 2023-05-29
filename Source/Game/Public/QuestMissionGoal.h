// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "QuestMissionGoal.generated.h"

UENUM(BlueprintType, Category="MissionGoal")
enum EQuestMissionGoal
{
	EQMG_None UMETA(DisplayName = "None"),
	EQMG_Kill UMETA(DisplayName = "Kill"),
	EQMG_BringCorpse UMETA(DisplayName = "BringCorpse"),
	EQMG_Collect UMETA(DisplayName = "Collect"),
	EQMG_Chopping UMETA(DisplayName = "Chopping"),
};
