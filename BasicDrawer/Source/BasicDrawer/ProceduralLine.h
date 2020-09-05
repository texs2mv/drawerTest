// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "ProceduralMeshComponent.h"

#include "ProceduralLine.generated.h"

UCLASS()
class BASICDRAWER_API AProceduralLine : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProceduralLine();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	TArray<FVector> vertices;
	TArray<int32> triangles;
	TArray<FColor> vertexColors;
	TArray<FVector2D> UV0;
	float lineWidth = 5;

	

	void setStartAndEnd(FVector begin, FVector end);
	void setWidth(float thickness);
	void addTriangle(FVector a, FVector b, FVector c);


	UPROPERTY()
	USceneComponent* root;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UProceduralMeshComponent* mesh;
	



};
