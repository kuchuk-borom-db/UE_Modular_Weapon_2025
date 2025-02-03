// Fill out your copyright notice in the Description page of Project Settings.


#include "ModularWeaponLoader.h"

#include "WeaponPart/WeaponPartTypeFunction.h"

void UModularWeaponLoader::Initialize(UModularWeaponDA* ModularWeaponDataAsset)
{
	if (!ModularWeaponDataAsset)
	{
		UE_LOG(LogTemp, Error, TEXT("ModularWeaponDataAsset is NULL"));
		return;
	}

	for (const TTuple<EWeaponPartType, FWeaponPartData>& Data : ModularWeaponDataAsset->Data)
	{
		if (!Data.Value.WeaponPartTypeFunction)
		{
			UE_LOG(LogTemp, Error, TEXT("WeaponPartTypeFunction is NULL for key: %d"), static_cast<int32>(Data.Key));
			continue;
		}

		if (!Data.Value.WeaponPartTypeFunction->IsValidLowLevel())
		{
			UE_LOG(LogTemp, Error, TEXT("WeaponPartTypeFunction is not valid for key: %d"), static_cast<int32>(Data.Key));
			continue;
		}

		UWeaponPartTypeFunction* Function = NewObject<UWeaponPartTypeFunction>(
			this, Data.Value.WeaponPartTypeFunction);
		WeaponPartTypeFunctionMap.Add(Data.Key, Function);
	}
}