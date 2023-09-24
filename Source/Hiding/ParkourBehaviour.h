// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DrawDebugHelpers.h"
#include "Components/ActorComponent.h"
#include "ParkourBehaviour.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class HIDING_API UParkourBehaviour : public UActorComponent
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	float ParkourCheckDistance;

	UPROPERTY(EditAnywhere)
	float JumpoverCheckDistance;
	
	UPROPERTY(VisibleAnywhere, Blueprintable, meta=(AllowPrivateAccess = "true"))
	bool bIsParkouring;
	
	FVector ParkourTargetLocation;

	
	
public:	
	// Sets default values for this component's properties
	UParkourBehaviour();

	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void TryParkour(const AActor* Player);
	bool GetIsParkouring() { return bIsParkouring; }
};
