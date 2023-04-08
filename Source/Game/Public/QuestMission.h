// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class GAME_API QuestMission
{
public:
	QuestMission();
	~QuestMission();

	FString Description;
	int MissionCurrentProgress;
	int MissionMaxProgress;
	int Reward;

	int MissionProgress(int progress);
};
