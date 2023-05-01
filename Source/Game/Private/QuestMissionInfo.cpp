// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestMissionInfo.h"

UQuestMissionInfo::UQuestMissionInfo(): MissionCurrentProgress(0), MissionMaxProgress(0), Reward(0)
{
}

int UQuestMissionInfo::MissionProgress(int progress)
{
	MissionCurrentProgress += progress;
	UE_LOG(LogTemp, Display, TEXT("Mission progress:"));
	UE_LOG(LogTemp, Display, TEXT("Current progress = %i"), MissionCurrentProgress);
	UE_LOG(LogTemp, Display, TEXT("Current max = %i"), MissionMaxProgress);
	if(MissionCurrentProgress >= MissionMaxProgress)
	{
		UE_LOG(LogTemp, Display, TEXT("Mission completed"));
		IsComplete = true;
		return Reward;
	}
	return 0;
}


