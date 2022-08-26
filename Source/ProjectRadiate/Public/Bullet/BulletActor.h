// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BulletActor.generated.h"

UCLASS()
class PROJECTRADIATE_API ABulletActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABulletActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UStaticMeshComponent* body;
	FVector trajectory;
	float currentLifetime = 0.0f;
	FVector initialPosition = FVector(0.0f, 0.0f, 0.0f);
	FQuat initialAngle = FQuat();

	virtual float CalculateDamage() { return 0.0f; };

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	float initialLifetime = 1.0f;
	float startDropoffDistance = 0.0f;
	float endDropoffDistance = 0.0f;
	float startDropoffDamage = 0.0f;
	float endDropoffDamage = 0.0f;

	void SetTrajectory(FVector direction);
	void SetPosition(FVector position);
	void SetAngle(FQuat angle);
	void SetStartDamage(float damage);
	void SetEndDamage(float damage);
	virtual void Launch() {};


};
