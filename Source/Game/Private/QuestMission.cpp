// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestMission.h"

QuestMission::QuestMission(): MissionCurrentProgress(0), MissionMaxProgress(0), Reward(0)
{
}

QuestMission::~QuestMission()
{
}

int QuestMission::MissionProgress(int progress)
{
	MissionCurrentProgress += progress;
	UE_LOG(LogTemp, Display, TEXT("Mission progress:"));
	UE_LOG(LogTemp, Display, TEXT("Current progress = %i"), MissionCurrentProgress);
	UE_LOG(LogTemp, Display, TEXT("Current max = %i"), MissionMaxProgress);
	if(MissionCurrentProgress >= MissionMaxProgress)
	{
		UE_LOG(LogTemp, Display, TEXT("Mission completed"));
		
		return Reward;
	}
	return 0;
}

