// Fill out your copyright notice in the Description page of Project Settings.


#include "Point.h"

// Sets default values
APoint::APoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = root;

	point_mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Point Mesh"));
	point_mesh->AttachTo(root);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> sphereMesh(TEXT("StaticMesh'/Game/StarterContent/Props/MaterialSphere.MaterialSphere'"));
	UStaticMesh* asset= sphereMesh.Object;

	static ConstructorHelpers::FObjectFinder<UMaterial>	pointMaterial(TEXT("Material'/Game/StarterContent/Materials/M_Ground_Grass.M_Ground_Grass'"));

	point_mesh->SetStaticMesh(asset);
	point_mesh->SetMaterial(0, pointMaterial.Object);

}




void APoint::setScale(float scale) {
	point_mesh->SetWorldScale3D(FVector(scale, scale, scale));
}

// Called when the game starts or when spawned
void APoint::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

