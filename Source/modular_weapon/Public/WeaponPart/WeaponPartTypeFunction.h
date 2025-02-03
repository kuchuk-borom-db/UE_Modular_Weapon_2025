// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "WeaponPartTypeFunction.generated.h"

UCLASS(Blueprintable)
class MODULAR_WEAPON_API UWeaponPartTypeFunction : public UObject
{
	GENERATED_BODY()

public :
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Foo();
	virtual void Foo_Implementation(); // Default implementation
};
