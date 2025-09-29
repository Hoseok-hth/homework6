// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
	// Tick 함수를 켜줍니다.
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);


}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	

	/*FVector CurrentLocation = GetActorLocation();

	if (CurrentLocation.X > MaxRange.X + StartLocation.X) {
		MovingSpeed *= -1;
	}
	else if (CurrentLocation.X < StartLocation.X) {
		MovingSpeed *= -1;
	}
	FVector NewLocation = CurrentLocation + (GetActorForwardVector() * MovingSpeed * DeltaTime);
	SetActorLocation(NewLocation);*/

	

}

// BlueprintCallable 함수 구현
void AMovingPlatform::ResetActorPosition()
{
	// (0, 0, 0) 위치로 되돌립니다.
	SetActorLocation(FVector::ZeroVector);
}

void AMovingPlatform::MoveActor()
{
}

