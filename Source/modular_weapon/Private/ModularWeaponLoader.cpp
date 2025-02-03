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
			UE_LOG(LogTemp, Error, TEXT("WeaponPartTypeFunction is not valid for key: %d"),
			       static_cast<int32>(Data.Key));
			continue;
		}

		UWeaponPartTypeFunction* PartTypeFunction = NewObject<UWeaponPartTypeFunction>(
			this, Data.Value.WeaponPartTypeFunction.Get());
		FWeaponPartTypeFunctionStore A;
		A.PartTypeFunction = PartTypeFunction;
		TMap<FString, UWeaponPartFunction*> PartFunctionMap;
		//Iterate the individual parts and create instances for them too
		for (const TTuple<FString, FWeaponPartSKMData>& Part : Data.Value.Parts)
		{
			if (Part.Key.IsEmpty() || !Part.Value.PartFunctionClass)
			{
				UE_LOG(LogTemp, Error,
				       TEXT("Part's Name is empty or It's Part function is missing. This may be intentional"))
				continue;
			}

			if (!Part.Value.PartFunctionClass->IsValidLowLevel())
			{
				UE_LOG(LogTemp, Error, TEXT("WeaponPartFunction is not valid for Part: %s for key %d"),
				       *Part.Key, static_cast<int32>(Data.Key));

				continue;
			}
			UWeaponPartFunction* PartFunction = NewObject<
				UWeaponPartFunction>(this, Part.Value.PartFunctionClass.Get());
			PartFunctionMap.Add(Part.Key, PartFunction);
		}
		A.PartFunction = PartFunctionMap;
		WeaponPartTypeFunctionMap.Add(Data.Key, A);
	}
	UE_LOG(LogTemp, Display, TEXT("Initialized Modular Weapon Data asset"));
}
