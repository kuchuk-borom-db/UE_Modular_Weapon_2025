// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponPart/WeaponPartFunction.h"
#include "WeaponPartSKMData.generated.h"

/**
 * 
 */


USTRUCT(Blueprintable)
struct MODULAR_WEAPON_API FWeaponPartSKMData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UWeaponPartFunction> PartFunctionClass;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	USkeletalMesh* Mesh;
};
