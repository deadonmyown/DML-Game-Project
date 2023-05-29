// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TargetType.generated.h"

UENUM()
enum ETargetType
{
	TT_None UMETA(DisplayName = "None"),
	TT_Rabbit UMETA(DisplayName = "Rabbit"),
	TT_Deer UMETA(DisplayName = "Deer"),
	TT_Wolf UMETA(DisplayName = "Wolf"),
	TT_Wood UMETA(DisplayName = "Wood"),
	TT_Plant UMETA(DisplayName = "Plant"),
};
