// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Drawer.h"
#include <iostream>

#include <map>
#include "Line.h"
#include "ProceduralLine.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>


#include "LineDrawer.generated.h"

/**
 * 
 */
UCLASS()
class BASICDRAWER_API ALineDrawer : public ADrawer
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	int drawLine(FVector begin, FVector end, float thickness);

	UFUNCTION(BlueprintCallable)
	TArray<int> drawLines(TArray<FVector> beginArrs, TArray<FVector> endArrs, float thickness);
	
	UFUNCTION(BlueprintCallable)
	TArray<FVector> randomBegins(int n, FVector2D x_range, FVector2D y_range, FVector2D z_range);

	UFUNCTION(BlueprintCallable)
	TArray<FVector> randomEnds(TArray<FVector> begins, FVector2D size_range);

	float randomRange(FVector2D range);
	FVector polarToCartesian(float r, float alpha, float polar);
	

protected:
	std::map<int, AProceduralLine*> lineMap;
	
	void draw();

	void hide();

	void show();
private:
	int counter = 0;
};
