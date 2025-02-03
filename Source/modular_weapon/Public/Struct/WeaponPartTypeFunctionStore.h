// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "WeaponPart/WeaponPartFunction.h"
#include "WeaponPart/WeaponPartTypeFunction.h"
#include "WeaponPartTypeFunctionStore.generated.h"

/**
 * 
 */
USTRUCT()
struct MODULAR_WEAPON_API FWeaponPartTypeFunctionStore
{
	GENERATED_BODY()
	UPROPERTY()
	UWeaponPartTypeFunction* PartTypeFunction;
	UPROPERTY()
	TMap<FString, UWeaponPartFunction*> PartFunction;
};
