#pragma once

#include "CoreMinimal.h"
#include "WeaponPartSKMData.h"
#include "WeaponPart/WeaponPartTypeFunction.h"
#include "WeaponPartData.generated.h"

USTRUCT(BlueprintType)
struct MODULAR_WEAPON_API FWeaponPartData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UWeaponPartTypeFunction> WeaponPartTypeFunction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, FWeaponPartSKMData> Parts;
};
