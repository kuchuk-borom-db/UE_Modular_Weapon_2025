// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EWeaponPartType : uint8
{
	Barrel UMETA(DisplayName = "Barrel"),
	Muzzle UMETA(DisplayName = "Muzzle"),
	Hull UMETA(DisplayName = "Hull"),
	Magazine UMETA(DisplayName = "Magazine"),
	Stock UMETA(DisplayName = "Stock"),
	Scope UMETA(DisplayName = "Scope")
};
