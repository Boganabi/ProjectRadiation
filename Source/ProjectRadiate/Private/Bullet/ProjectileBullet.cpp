// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet/ProjectileBullet.h"


AProjectileBullet::AProjectileBullet()
{
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("body"));
	body->SetStaticMesh(mesh);
	body->SetVisibility(true);
	SetRootComponent(body);

}

float AProjectileBullet::CalculateDamage()
{
	if (type == DamageCalculationType::OverDistance)
	{
		FVector endPosition = body->GetComponentTransform().GetLocation();
		FVector finalPosition = endPosition - initialPosition;
		if (finalPosition.Size() < startDropoffDistance)
		{
			return startDropoffDamage;
		}
		else if (finalPosition.Size() < endDropoffDamage)
		{
			return startDropoffDamage - FMath::Lerp<float>(startDropoffDamage, endDropoffDamage, 
				(finalPosition.Size() - startDropoffDistance) / (endDropoffDistance - startDropoffDistance));
		}
		else
		{
			return endDropoffDamage;
		}
	}
	else
	{
		if (currentLifetime < startDropoffDistance)
		{
			return startDropoffDamage;
		}
		else if (currentLifetime < endDropoffDistance)
		{
			return startDropoffDamage - FMath::Lerp<float>(startDropoffDamage, endDropoffDamage, 
				(currentLifetime - startDropoffDistance) / (endDropoffDistance - startDropoffDistance));
		}
		else
		{
			return endDropoffDamage;
		}
	}
}

void AProjectileBullet::BeginPlay()
{
	Super::BeginPlay();
	
	if (body)
	{
		body->OnComponentHit.AddDynamic(this, &AProjectileBullet::OnBulletCollision);
		Launch();
	}

}

void AProjectileBullet::OnBulletCollision(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor->Tags.Contains("Ground") || OtherActor->Tags.Contains("Wall"))
	{
		Destroy();
	}
}

void AProjectileBullet::Launch()
{
	ABulletActor::Launch();

	body->AddForce(trajectory * speed);
}

void AProjectileBullet::SetSeed(float newspeed)
{
	speed = newspeed;
}
