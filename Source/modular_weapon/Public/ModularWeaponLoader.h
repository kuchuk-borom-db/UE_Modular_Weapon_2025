// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DA/ModularWeaponDA.h"
#include "Struct/WeaponPartTypeFunctionStore.h"
#include "UObject/Object.h"
#include "ModularWeaponLoader.generated.h"

UCLASS(BlueprintType)
class MODULAR_WEAPON_API UModularWeaponLoader : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void Initialize(UModularWeaponDA* ModularWeaponDataAsset);
	UPROPERTY()
	TMap<EWeaponPartType, FWeaponPartTypeFunctionStore> WeaponPartTypeFunctionMap;
};
