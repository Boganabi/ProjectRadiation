// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/WeaponComponent.h"

// Sets default values for this component's properties
UWeaponComponent::UWeaponComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

    gunBody = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Gun"));
    
	// ...
}


// Called when the game starts
void UWeaponComponent::BeginPlay()
{
	Super::BeginPlay();
	currentAmmoAmount = ammoCapacity;
	// ...
	
}


// Called every frame
void UWeaponComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (currentReloadCooldown > 0.0f && bIsReloading)
    {
        currentReloadCooldown -= DeltaTime;
    }
    else if (currentReloadCooldown <= 0.0f && bIsReloading)
    {
        bIsReloading = false;
    }
    if (currentPerBulletCooldown > 0.0f && !bIsReloading)
    {
        currentPerBulletCooldown -= DeltaTime;
    }
    else if (currentReloadCooldown <= 0.0f && bIsReloading)
    {
        currentAmmoAmount = ammoCapacity;
        currentReloadCooldown = reloadCooldown;
        bIsReloading = false;
    }
}

void UWeaponComponent::Shoot()
{
    if (currentAmmoAmount > 0 && currentPerBulletCooldown <= 0.0f)
    {
        if (bullet)
        {
            UClass* test = bullet.Get();
            ABulletActor* newBullet = NewObject<ABulletActor>();
            if (newBullet)
            {
                currentAmmoAmount -= 1.0f;
                newBullet->SetActorLocation(barrelEnd.GetLocation());
                newBullet->SetActorRotation(barrelEnd.GetRotation());
                //Debug.Log(barrelEnd.gameObject.transform.rotation.eulerAngles);
                newBullet->SetTrajectory(barrelEnd.GetLocation());
                currentPerBulletCooldown = maxPerBulletCooldown;
                // newBullet.Launch();
            }
            else
            {
                //Translate
                //Debug.LogError("BULLET NOT CREATED.");
            }
        }
        else
        {
            //TRanslate
           // Debug.LogError("BULLET DOES NOT EXIST");
        }
    }
}

void UWeaponComponent::Reload()
{
    if (currentAmmoAmount < ammoCapacity)
    {
        bIsReloading = true;
        currentReloadCooldown = reloadCooldown;

    }
}

