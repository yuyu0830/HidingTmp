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
	ParkourCheckDistance = 100.f;
}


// Called every frame
void UParkourBehaviour::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UParkourBehaviour::TryParkour(AActor* Player)
{
	FVector PlayerLocation = Player->GetActorLocation();
	FVector PlayerDirection = Player->GetActorForwardVector();
	FVector FrontLocation = PlayerLocation + PlayerDirection * ParkourCheckDistance;
	
	FVector FrontTopLocation = FrontLocation + FVector(0, 0, 50);
	FVector FrontBottomLocation = FrontLocation - FVector(0, 0, 50);
	DrawDebugPoint(Player->GetWorld(), FrontTopLocation, 200, FColor(52, 220, 239), true);
	DrawDebugPoint(Player->GetWorld(), FrontBottomLocation, 200, FColor(52, 220, 239), true);

	FHitResult FrontHitResult;
	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(Player);
	
	if (Player->GetWorld()->LineTraceSingleByChannel(FrontHitResult, FrontBottomLocation, FrontTopLocation, ECC_Visibility, CollisionParams))
	{
		UE_LOG(LogTemp, Log, TEXT("HIT Something!"));
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("HIT nothing..."));
	}	
	
	//DrawDebugSphere(Player->GetWorld(), PlayerLocation, 200, 26, FColor(181, 0, 0), true, -1, 0, 2);
	//UE_LOG(LogTemp, Log, TEXT("Component Parkour!"));
	// if (!Player) return;
	// FVector PlayerChestLocation = Player->GetActorLocation();
	// FVector PlayerDirection = Player->GetActorForwardVector();
	// FVector ChestFrontLocation = PlayerChestLocation + PlayerDirection * ParkourCheckDistance;
	//
	// // UE_LOG(LogTemp, Log, TEXT("Location : %s"), *PlayerChestLocation.ToString());
	// // UE_LOG(LogTemp, Log, TEXT("Direction : %s"), *PlayerDirection.ToString());
	// // UE_LOG(LogTemp, Log, TEXT("FrontLocation : %s"), *ChestFrontLocation.ToString());
	//
	// FHitResult ChestHitResult;
	//
	// FCollisionQueryParams CollisionParams;
	// CollisionParams.AddIgnoredActor(Player);

	// if (GetWorld()->LineTraceSingleByChannel(ChestHitResult, PlayerChestLocation, ChestFrontLocation, ECC_Visibility, CollisionParams))
	// {
	// 	UE_LOG(LogTemp, Log, TEXT("HIT Something!"));
	// }
	// else
	// {
	// 	UE_LOG(LogTemp, Log, TEXT("HIT nothing..."));
	// }	

	// FHitResult RightHitResult;

}
