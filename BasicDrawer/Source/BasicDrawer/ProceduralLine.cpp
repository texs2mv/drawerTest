// Fill out your copyright notice in the Description page of Project Settings.


#include "ProceduralLine.h"

// Sets default values
AProceduralLine::AProceduralLine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = root;

	mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("GeneratedMesh"));

	
	
	mesh->AttachTo(RootComponent);

}

void AProceduralLine::addTriangle(FVector a, FVector b, FVector c) {
	vertices.Add(a);
	vertices.Add(b);
	vertices.Add(c);
	UV0.Add(FVector2D(0, 0));
	UV0.Add(FVector2D(0, 10));
	UV0.Add(FVector2D(10, 10));

	vertices.Add(a);
	vertices.Add(c);
	vertices.Add(b);
	UV0.Add(FVector2D(0, 0));
	UV0.Add(FVector2D(0, 10));
	UV0.Add(FVector2D(10, 10));

	int lenght = triangles.Num();
	for (int i = lenght; i < lenght + 6; i++) {
		triangles.Add(i);
		vertexColors.Add(FColor(254, 254, 254, 254));
	}
}


void AProceduralLine::setWidth(float thickness) {
	lineWidth = thickness;
}

void AProceduralLine::setStartAndEnd(FVector begin, FVector end) {
	

	addTriangle(begin, begin - FVector(0, 0, lineWidth), end);
	addTriangle(end, end - FVector(0, 0, lineWidth), begin - FVector(0, 0, lineWidth));

	addTriangle(begin, begin - FVector(0, lineWidth, 0), end);
	addTriangle(end, end - FVector(0, lineWidth, 0), begin - FVector(0, lineWidth, 0));

	addTriangle(begin, begin - FVector(lineWidth, 0, 0), end);
	addTriangle(end, end - FVector(lineWidth, 0, 0), begin - FVector(lineWidth, 0, 0));


	mesh->CreateMeshSection(1, vertices, triangles, TArray<FVector>(), UV0, vertexColors, TArray<FProcMeshTangent>(), false);
	

	
}




/** * Create/replace a section for this procedural mesh component. * @param SectionIndex Index of the section to create or replace. * @param Vertices Vertex buffer of all vertex positions to use for this mesh section. * @param Triangles Index buffer indicating which vertices make up each triangle. Length must be a multiple of 3. * @param Normals Optional array of normal vectors for each vertex. If supplied, must be same length as Vertices array. * @param UV0 Optional array of texture co-ordinates for each vertex. If supplied, must be same length as Vertices array. * @param VertexColors Optional array of colors for each vertex. If supplied, must be same length as Vertices array. * @param Tangents Optional array of tangent vector for each vertex. If supplied, must be same length as Vertices array. * @param bCreateCollision Indicates whether collision should be created for this section. This adds significant cost. */ //UFUNCTION(BlueprintCallable, Category = "Components|ProceduralMesh", meta = (AutoCreateRefTerm = "Normals,UV0,VertexColors,Tangents")) // void CreateMeshSection(int32 SectionIndex, const TArray& Vertices, const TArray& Triangles, const TArray& Normals, // const TArray& UV0, const TArray& VertexColors, const TArray& Tangents, bool bCreateCollision);   TArray<FVector> vertices;   vertices.Add(FVector(0, 0, 0)); vertices.Add(FVector(0, 100, 0)); vertices.Add(FVector(0, 0, 100));   TArray<int32> Triangles; Triangles.Add(0); Triangles.Add(1); Triangles.Add(2);   TArray<FVector> normals; normals.Add(FVector(1, 0, 0)); normals.Add(FVector(1, 0, 0)); normals.Add(FVector(1, 0, 0));   TArray<FVector2D> UV0; UV0.Add(FVector2D(0, 0)); UV0.Add(FVector2D(0, 10)); UV0.Add(FVector2D(10 ,10));   TArray<FColor> vertexColors; vertexColors.Add(FColor(100,100,100,100)); vertexColors.Add(FColor(100, 100, 100, 100)); vertexColors.Add(FColor(100, 100, 100, 100));     TArray<FProcMeshTangent> tangents; tangents.Add(FProcMeshTangent(1, 1, 1)); tangents.Add(FProcMeshTangent(1, 1, 1)); tangents.Add(FProcMeshTangent(1, 1, 1));     mesh->CreateMeshSection(1, vertices, Triangles, normals, UV0, vertexColors, tangents, false);   // With default options //     mesh->AttachTo(RootComponent); }
// Called when the game starts or when spawned
void AProceduralLine::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProceduralLine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

