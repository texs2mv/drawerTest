// Fill out your copyright notice in the Description page of Project Settings.


#include "PointDrawer.h"

void APointDrawer::draw()
{

}

void APointDrawer::show()
{
	for (auto it = pointMap.begin(); it != pointMap.end(); it++)
	{
		it->second->SetActorHiddenInGame(false);
	}
}

void APointDrawer::hide()
{
	for (auto it = pointMap.begin(); it != pointMap.end(); it++)
	{
		it->second->SetActorHiddenInGame(true);
	}
}

int APointDrawer::drawPoint(FVector position, float radius, FColor color)
{
	FVector origin = GetActorLocation();
	APoint* newPoint = Cast<APoint> (GetWorld()->SpawnActor<APoint>(
		APoint::StaticClass(),
		origin + position,
		FRotator(0, 0, 0)
	));

	newPoint->setScale(radius/ 30.0);
	
	pointMap[counter] = newPoint;
	counter++;
	return counter - 1;
}

TArray<int> APointDrawer::drawPoints(TArray<FVector> positions, float radius, FColor color)
{
	TArray<int> ids;
	for (int i = 0; i < positions.Num(); i++) {
		ids.Add(drawPoint(positions[i], radius, color));
	}
	return ids;
}


float APointDrawer::randomRange(FVector2D range) {
	return (rand() % ((int)range[1] - (int)range[0])) + (int)range[0];
}

TArray<FVector> APointDrawer::randomPositions(int n, FVector2D x_range, FVector2D y_range, FVector2D z_range) {
	srand(time(NULL));
	TArray<FVector> positions;
	positions.Init(FVector(0, 0, 0), n);
	for (int i = 0; i < n; i++) {
		positions[i] = FVector(randomRange(x_range), randomRange(y_range), randomRange(z_range));
	}
	return positions;
}