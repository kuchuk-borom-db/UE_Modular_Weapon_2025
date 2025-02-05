// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Struct/WeaponPartSkmCompData.h"
#include "ModularWeaponActor.generated.h"

UCLASS(BlueprintType)
class MODULAR_WEAPON_API AModularWeaponActor : public AActor
{
	GENERATED_BODY()

public:
	AModularWeaponActor();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<USkeletalMeshComponent*, FWeaponPartSkmCompData > Parts;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
