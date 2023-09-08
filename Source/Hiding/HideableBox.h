// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "HideableBox.generated.h"

UCLASS()
class HIDING_API AHideableBox : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	UBoxComponent* HideableCollider;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	UStaticMeshComponent* MeshComponent;
	
public:	
	// Sets default values for this actor's properties
	AHideableBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// virtual void NotifyHit(
	// UPrimitiveComponent* MyComp,
	// AActor* Other,
	// UPrimitiveComponent* OtherComp,
	// bool bSelfMoved,
	// FVector HitLocation,
	// FVector HitNormal,
	// FVector NormalImpulse,
	// const FHitResult& Hit
	// ) override;
};
