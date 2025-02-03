// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Enum/WeaponPartType.h"
#include "Struct/WeaponPartData.h"
#include "ModularWeaponDA.generated.h"

/**
 * Class to hold Data about modular weapon parts
 */
UCLASS(Blueprintable, BlueprintType)
class MODULAR_WEAPON_API UModularWeaponDA : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
	TMap<EWeaponPartType, FWeaponPartData> Data;
};
