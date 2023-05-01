// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestInfo.h"

#include "QuestMissionInfo.h"

void UQuestInfo::QuestProgress()
{
	int count(0);
	for(UQuestMissionInfo* Mission : Missions)
	{
		if(Mission->IsComplete)
			count++;
	}
	if(count == Missions.Num())
		IsComplete = true;
}
