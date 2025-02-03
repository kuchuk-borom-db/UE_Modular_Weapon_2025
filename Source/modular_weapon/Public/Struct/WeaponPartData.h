#pragma once

#include "CoreMinimal.h"
#include "Engine/SkeletalMesh.h"
#include "WeaponPart/WeaponPartFunction.h"
#include "WeaponPartData.generated.h"

USTRUCT(BlueprintType)
struct MODULAR_WEAPON_API FWeaponPartData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UWeaponPartFunction> WeaponPartFunction; //Something like this
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<USkeletalMesh*, FString> Parts;
};
