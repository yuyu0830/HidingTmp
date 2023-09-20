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
	bool bIsParkouring;
public:	
	// Sets default values for this component's properties
	UParkourBehaviour();

	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void TryParkour(AActor* Player);
		
};
