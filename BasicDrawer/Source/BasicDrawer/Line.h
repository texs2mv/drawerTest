// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/SplineMeshComponent.h"

#include "Line.generated.h"

UCLASS()
class BASICDRAWER_API ALine : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALine();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void setStartAndEnd(FVector begin, FVector end);

	UPROPERTY()
	USceneComponent* root;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USplineMeshComponent* spline_mesh;

};
