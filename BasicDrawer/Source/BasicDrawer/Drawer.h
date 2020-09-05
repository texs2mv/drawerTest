// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "DrawDebugHelpers.h"

#include "Drawer.generated.h"

UCLASS()
class BASICDRAWER_API ADrawer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADrawer();

	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	virtual void draw();

	UFUNCTION(BlueprintCallable)
	virtual void show();

	UFUNCTION(BlueprintCallable)
	virtual void hide();



public:	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector worldPosition;

	UPROPERTY()
	USceneComponent* root;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* originMesh;




};
