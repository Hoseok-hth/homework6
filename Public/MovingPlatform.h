// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimerManager.h"
#include "MovingPlatform.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogSparta, Warning, All);
UCLASS()
class HOMEWORK6_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	UStaticMeshComponent* StaticMeshComp;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item|Properties")
	float RotationSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
	float MovingSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
	FVector MaxRange;
	FVector3d StartLocation;
	FVector3d EndLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
	float StepDistance = 10.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
	float StepTime = 0.1f;

	FTimerHandle TimerHandle;

	// 함수를 블루프린트에서 호출 가능하도록 설정
	UFUNCTION(BlueprintCallable, Category = "Item|Actions")
	void ResetActorPosition();

	void MoveActor();

	bool isForward = true;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
