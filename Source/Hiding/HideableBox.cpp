// Fill out your copyright notice in the Description page of Project Settings.


#include "HideableBox.h"

// Sets default values
AHideableBox::AHideableBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	HideableCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	HideableCollider->SetCollisionObjectType(ECollisionChannel::ECC_GameTraceChannel1);
	
	SetRootComponent(HideableCollider);

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	MeshComponent->SetupAttachment(HideableCollider);


}

// Called when the game starts or when spawned
void AHideableBox::BeginPlay()
{
	Super::BeginPlay();
	
	FVector MeshComponentScale = MeshComponent->GetComponentScale();

	MeshComponentScale += FVector(150.f);
	
	HideableCollider->SetBoxExtent(MeshComponentScale);
	HideableCollider->SetWorldLocation(MeshComponent->GetComponentLocation());
}

// Called every frame
void AHideableBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHideableBox::NotifyActorBeginOverlap(AActor* OtherActor)
{
	//UE_LOG(LogTemp, Log, TEXT("In!!!!"));
}

// void AHideableBox::NotifyHit(
// 	UPrimitiveComponent* MyComp,
// 	AActor* Other,
// 	UPrimitiveComponent* OtherComp,
// 	bool bSelfMoved,
// 	FVector HitLocation,
// 	FVector HitNormal,
// 	FVector NormalImpulse,
// 	const FHitResult& Hit
// 	)
// {
// 	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);
// 	UE_LOG(LogTemp, Log, TEXT("HIT!!!!"));
// }

