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

void UParkourBehaviour::TryParkour(const AActor* Player)
{
	FVector PlayerLocation = Player->GetActorLocation();
	FVector PlayerDirection = Player->GetActorForwardVector();
	FVector FrontLocation = PlayerLocation + PlayerDirection * ParkourCheckDistance;
	
	FVector FrontTopLocation = FrontLocation + FVector(0, 0, 50);
	FVector FrontBottomLocation = FrontLocation - FVector(0, 0, 50);

	//UE_LOG(LogTemp, Log, TEXT("Location : %s"), *PlayerLocation.ToString());
	//UE_LOG(LogTemp, Log, TEXT("Direction : %s"), *PlayerDirection.ToString());
	//UE_LOG(LogTemp, Log, TEXT("FrontLocation : %s"), *FrontLocation.ToString());
	//DrawDebugPoint(Player->GetWorld(), FrontTopLocation, 90, FColor(52, 220, 239), true);
	//DrawDebugPoint(Player->GetWorld(), FrontBottomLocation, 90, FColor(52, 220, 239), true);
	
	FHitResult FrontHitResult;
	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(Player);
	
	if (!Player->GetWorld()->LineTraceSingleByChannel(FrontHitResult, FrontTopLocation, FrontBottomLocation, ECC_Visibility, CollisionParams))
	{
		UE_LOG(LogTemp, Log, TEXT("Nothing..."));
		return;
	}
	
	UE_LOG(LogTemp, Log, TEXT("HIT Something!"));
	AActor* HitActor = FrontHitResult.GetActor();
	
	if (!HitActor)
	{
		UE_LOG(LogTemp, Log, TEXT("There is no Actor... Error"));
		return;
	}
	
	FVector origin;
	FVector boxExtent;
	HitActor->GetActorBounds(false, origin, boxExtent);
	UE_LOG(LogTemp, Log, TEXT("Direction : %s"), *origin.ToString());
	UE_LOG(LogTemp, Log, TEXT("FrontLocation : %s"), *boxExtent.ToString());

	float HeightOfWall = origin.Z + boxExtent.Z / 2;
	float PlayerFoot = PlayerLocation.Z - 90.f;

	UE_LOG(LogTemp, Log, TEXT("HeightGap : %.4f"), HeightOfWall - PlayerFoot);
	// if (Player->GetWorld()->LineTraceSingleByChannel(FrontHitResult, FrontTopLocation, FrontBottomLocation, ECC_Visibility, CollisionParams))
	// {
	// 	UE_LOG(LogTemp, Log, TEXT("HIT Something!"));
	// 	AActor* HitActor = FrontHitResult.GetActor();
	// 	
	// 	if (HitActor)
	// 	{
	// 		UE_LOG(LogTemp, Log, TEXT("Get Actor Complete!"));
	// 		FVector origin;
	// 		FVector boxExtent;
	// 		HitActor->GetActorBounds(false, origin, boxExtent);
	// 		UE_LOG(LogTemp, Log, TEXT("Direction : %s"), *origin.ToString());
	// 		UE_LOG(LogTemp, Log, TEXT("FrontLocation : %s"), *boxExtent.ToString());
	// 	}
	// 	
	// 	//UStaticMeshComponent* Mesh = Cast<UStaticMeshComponent>(HitActor);
	//
	// }
	// else
	// {
	// 	UE_LOG(LogTemp, Log, TEXT("HIT nothing..."));
	// 	return;
	// }	
	
	FVector PlayerTopLocation = PlayerLocation + FVector(0, 0, 50);
	FVector PlayerBottomLocation = PlayerLocation - FVector(0, 0, 50);

	
	
}
