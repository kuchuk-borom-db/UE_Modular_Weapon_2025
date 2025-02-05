// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponPartData.h"
#include "Enum/WeaponPartType.h"
#include "UObject/Object.h"
#include "WeaponPartSkmCompData.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct MODULAR_WEAPON_API FWeaponPartSkmCompData 
{
	GENERATED_BODY()
	EWeaponPartType PartType;
	FWeaponPartData WeaponPartData;
};
