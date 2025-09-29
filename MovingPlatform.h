// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

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

	// �Լ��� �������Ʈ���� ȣ�� �����ϵ��� ����
	UFUNCTION(BlueprintCallable, Category = "Item|Actions")
	void ResetActorPosition();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
