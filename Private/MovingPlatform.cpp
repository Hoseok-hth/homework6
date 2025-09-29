// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

DEFINE_LOG_CATEGORY(LogSparta);
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
	EndLocation = StartLocation + MaxRange;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AMovingPlatform::MoveActor, StepTime, true);

	
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
	
	FVector Current = GetActorLocation();
	FVector Target = isForward ? EndLocation : StartLocation;
	UE_LOG(LogSparta, Error, TEXT("current: %f"), Current.X);
	UE_LOG(LogSparta, Error, TEXT("target: %f"),Target.X);
	// 한 스텝 이동
	FVector Direction = (Target - Current).GetSafeNormal();
	FVector NewLocation = Current + Direction * StepDistance;

	SetActorLocation(NewLocation);

	// 목표 위치 도달 체크
	if (FVector::Dist(NewLocation, Target) <= StepDistance)
	{
		NewLocation = Target;
		isForward = !isForward; // 방향 반전
	}
	
}

