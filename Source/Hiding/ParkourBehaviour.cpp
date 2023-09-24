// Fill out your copyright notice in the Description page of Project Settings.


#include "ParkourBehaviour.h"

// Sets default values for this component's properties
UParkourBehaviour::UParkourBehaviour()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}


// Called when the game starts
void UParkourBehaviour::BeginPlay()
{
	Super::BeginPlay();
	
	// ...
}


// Called every frame
void UParkourBehaviour::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UParkourBehaviour::TryParkour(const AActor* Player)
{
	FVector PlayerLocation = Player->GetActorLocation();
	FVector PlayerDirection = Player->GetActorForwardVector();
	FVector FrontLocation = PlayerLocation + (PlayerDirection * ParkourCheckDistance);

	UE_LOG(LogTemp, Log, TEXT("Distance : %.4f"), ParkourCheckDistance);
	
	FHitResult HitResult;
	FCollisionQueryParams CollisionParams;
	
	CollisionParams.AddIgnoredActor(Player);
	
	DrawDebugLine(Player->GetWorld(), FrontLocation + FVector(0, 0, 50), FrontLocation - FVector(0, 0, 50), FColor::Emerald, true, -1, 0, 10);
	
	if (!Player->GetWorld()->LineTraceSingleByChannel(
		HitResult,
		FrontLocation + FVector(0, 0, 50),
		FrontLocation - FVector(0, 0, 50),
		ECC_Visibility,
		CollisionParams))
	{
		UE_LOG(LogTemp, Log, TEXT("Nothing..."));
		return;
	}
	
	UE_LOG(LogTemp, Log, TEXT("HIT Something!"));
	
	CollisionParams.AddIgnoredActor(HitResult.GetActor());
	
	ParkourTargetLocation = HitResult.ImpactPoint;

	
	if (Player->GetWorld()->LineTraceSingleByChannel(
		HitResult,
		ParkourTargetLocation,
		ParkourTargetLocation + FVector(0, 0, 180.f),
		ECC_Visibility,
		CollisionParams))
	{
		UE_LOG(LogTemp, Log, TEXT("Something In Parkour Spot"));
		return;
	}
	
	UE_LOG(LogTemp, Log, TEXT("Can Parkour!"));
	
	FVector JumpoverLocation = PlayerLocation + (PlayerDirection * JumpoverCheckDistance);
	DrawDebugLine(Player->GetWorld(), JumpoverLocation + FVector(0, 0, 50), JumpoverLocation - FVector(0, 0, 50), FColor::Purple, true, -1, 0, 10);
	
}
