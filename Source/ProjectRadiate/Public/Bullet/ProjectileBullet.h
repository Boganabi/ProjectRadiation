// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bullet/BulletActor.h"
#include "ProjectileBullet.generated.h"

/**
 * 
 */
enum DamageCalculationType : uint8
{
	OverTime,
	OverDistance
};

UCLASS()
class PROJECTRADIATE_API AProjectileBullet : public ABulletActor
{
	GENERATED_BODY()

		AProjectileBullet();

protected:
	virtual float CalculateDamage() override;
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void OnBulletCollision(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);



public:
	DamageCalculationType type = DamageCalculationType::OverDistance;
	float speed = 0.0f;

	virtual void Launch() override;
	void SetSeed(float speed);


	
};
