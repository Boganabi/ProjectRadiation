// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Bullet/BulletActor.h"
#include "WeaponComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTRADIATE_API UWeaponComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWeaponComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	float currentAmmoAmount = 0;
	float currentReloadCooldown = 0.0f;
	bool bIsReloading = false;
	float currentPerBulletCooldown = 0.0f;
	USkeletalMeshComponent* gunBody;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TSubclassOf<ABulletActor> bullet;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float ammoCapacity	= 0.0f;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float damageOverride = 0.0f;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float speedOverride = 0.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float reloadCooldown = 0.0f;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float maxPerBulletCooldown = 0.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FTransform barrelEnd;

	UFUNCTION()
	virtual void Shoot();
	UFUNCTION()
	virtual void Reload();
};
