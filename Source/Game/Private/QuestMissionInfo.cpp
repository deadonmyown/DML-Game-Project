// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestMissionInfo.h"


UQuestMissionInfo::UQuestMissionInfo(): MissionCurrentProgress(0), MissionMaxProgress(0), Reward(0)
{
}

void UQuestMissionInfo::MissionProgress(int progress, AInventoryController* IController)
{
	MissionCurrentProgress += progress;
	UE_LOG(LogTemp, Display, TEXT("Mission progress:"));
	UE_LOG(LogTemp, Display, TEXT("Current progress = %i"), MissionCurrentProgress);
	UE_LOG(LogTemp, Display, TEXT("Current max = %i"), MissionMaxProgress);
	if(MissionCurrentProgress >= MissionMaxProgress)
	{
		UE_LOG(LogTemp, Display, TEXT("Mission completed"));
		IsComplete = true;
	}
	IController->UpdateMissionInfo();
}

void UQuestMissionInfo::MissionRegress(int regress, AInventoryController* IController)
{
	MissionCurrentProgress += regress;
	UE_LOG(LogTemp, Display, TEXT("Mission progress:"));
	UE_LOG(LogTemp, Display, TEXT("Current progress = %i"), MissionCurrentProgress);
	UE_LOG(LogTemp, Display, TEXT("Current max = %i"), MissionMaxProgress);
	if(MissionCurrentProgress < MissionMaxProgress)
	{
		UE_LOG(LogTemp, Display, TEXT("Mission not completed"));
		IsComplete = false;
	}
	IController->UpdateMissionInfo();
}

bool UQuestMissionInfo::GetReward(AInventoryController* IController)
{
	if(IController && IsComplete && !IsGetReward)
	{
		IController->Money += Reward;
		IsGetReward = true;
		return true;
	}
	return false;
}

void UQuestMissionInfo::ClearMissionInfo()
{
	IsComplete = false;
	MissionCurrentProgress = 0;
}


