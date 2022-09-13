// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet/BulletActor.h"

// Sets default values
ABulletActor::ABulletActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("body"));
	body->SetStaticMesh(mesh);

}

// Called when the game starts or when spawned
void ABulletActor::BeginPlay()
{
	Super::BeginPlay();
	body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	currentLifetime = initialLifetime;
}

// Called every frame
void ABulletActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (currentLifetime <= 0.0f)
	{
		Destroy();
	}
	else
	{
		currentLifetime -= DeltaTime;
	}

}

void ABulletActor::SetTrajectory(FVector direction)
{
	trajectory = direction;
}

void ABulletActor::SetPosition(FVector position)
{
	initialPosition = position;
	SetActorLocation(initialPosition);
}

void ABulletActor::SetAngle(FQuat angle)
{
	initialAngle = angle;
	SetActorRotation(initialAngle, ETeleportType::None);
}

void ABulletActor::SetStartDamage(float damage)
{
	startDropoffDamage = damage;
}

void ABulletActor::SetEndDamage(float damage)
{
	endDropoffDamage = damage;
}

