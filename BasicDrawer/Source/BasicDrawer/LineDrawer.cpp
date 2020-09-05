// Fill out your copyright notice in the Description page of Project Settings.


#include "LineDrawer.h"

int ALineDrawer::drawLine(FVector begin, FVector end, float thickness = 12)
{
	
	AProceduralLine* line = Cast<AProceduralLine>(GetWorld()->SpawnActor<AProceduralLine>(
		AProceduralLine::StaticClass(),
		FVector(0, 0, 0),
		FRotator(0, 0, 0)
	));

	line->setWidth(thickness);
	
	line->setStartAndEnd(
		GetActorLocation() + GetActorRotation().RotateVector(begin), 
		GetActorLocation() + GetActorRotation().RotateVector(end)
	);	

	lineMap[counter] = line;
	counter++;
	return counter - 1;
}

TArray<int> ALineDrawer::drawLines(TArray<FVector> beginArrs, TArray<FVector> endArrs, float thickness) {
	TArray<int> ids;
	for (int i = 0; i < beginArrs.Num(); i++) {
		ids.Add(drawLine(beginArrs[i], endArrs[i], thickness));
	}
	return ids;
}

void ALineDrawer::draw()
{
}

void ALineDrawer::hide()
{
	for (auto it = lineMap.begin(); it != lineMap.end(); it++)
	{
		it->second->SetActorHiddenInGame(true);
	}
}

void ALineDrawer::show()
{
	for (auto it = lineMap.begin(); it != lineMap.end(); it++)
	{
		it->second->SetActorHiddenInGame(false);
	}
}


float ALineDrawer::randomRange(FVector2D range) {
	return (rand() % ((int)range[1] - (int)range[0])) + (int)range[0];
}

FVector ALineDrawer::polarToCartesian(float r, float alpha, float polar){
	return FVector(r * sin(polar) * cos(alpha), r * sin(polar) * sin(alpha), r * cos(polar));
}

TArray<FVector> ALineDrawer::randomBegins(int n, FVector2D x_range, FVector2D y_range, FVector2D z_range) {
	srand(time(NULL));
	TArray<FVector> positions;
	positions.Init(FVector(0, 0, 0), n);
	for (int i = 0; i < n; i++) {
		positions[i] = FVector(randomRange(x_range), randomRange(y_range), randomRange(z_range));
	}
	return positions;
}

TArray<FVector> ALineDrawer::randomEnds(TArray<FVector> begins, FVector2D size_range) {
	srand(time(NULL));
	TArray<FVector> ends;

	ends.Init(FVector(0, 0, 0), begins.Num());
	float l_size;
	float alpha;
	float polar;
	for (int i = 0; i < begins.Num(); i++) {
		l_size = randomRange(size_range);
		polar = randomRange(FVector2D(0, 360));
		alpha = randomRange(FVector2D(0, 360));

		ends[i] = begins[i] + polarToCartesian(l_size, alpha, polar);
	}
	return ends;
}