// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Drawer.h"
#include "Point.h"

#include <iostream>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "PointDrawer.generated.h"

/**
 * 
 */
UCLASS()
class BASICDRAWER_API APointDrawer : public ADrawer
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	int drawPoint(FVector position, float radius, FColor color);

	UFUNCTION(BlueprintCallable)
	TArray<int> drawPoints(TArray<FVector> positions, float radius, FColor color);

	UFUNCTION(BlueprintCallable)
	TArray<FVector> randomPositions(int n, FVector2D x_range, FVector2D y_range, FVector2D z_range);

	float randomRange(FVector2D range);
	
protected:
	
	std::map<int, APoint*> pointMap;

	void draw();

	void hide();

	void show();
private:
	int counter = 0;
};
