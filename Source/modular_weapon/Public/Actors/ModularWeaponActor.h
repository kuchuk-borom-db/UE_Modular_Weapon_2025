// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ModularWeaponActor.generated.h"

UCLASS(BlueprintType)
class MODULAR_WEAPON_API AModularWeaponActor : public AActor
{
	GENERATED_BODY()

public:
	AModularWeaponActor();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
