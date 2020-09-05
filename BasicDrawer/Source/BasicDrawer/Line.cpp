// Fill out your copyright notice in the Description page of Project Settings.


#include "Line.h"

// Sets default values
ALine::ALine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = root;

	spline_mesh = CreateDefaultSubobject<USplineMeshComponent>(TEXT("Spline Mesh"));
	spline_mesh->AttachTo(root);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> sphereMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Pipe.Shape_Pipe'"));
	//static ConstructorHelpers::FObjectFinder<UStaticMesh> sphereMesh(TEXT("StaticMesh'/Game/StarterContent/Props/MaterialSphere.MaterialSphere'"));
	UStaticMesh* asset = sphereMesh.Object;

	spline_mesh->SetMobility(EComponentMobility::Movable);
	spline_mesh->SetStaticMesh(asset);
	spline_mesh->SetForwardAxis(ESplineMeshAxis::Y, true);
	//spline_mesh->SetWorldScale3D(FVector(0.1, 0.1, 0.1));
	
	

}

void ALine::setStartAndEnd(FVector begin, FVector end) {
	//FVector origin = GetActorLocation();

	FVector randDirection = FVector(0, 0, 0);
	FVector lineDirection = end - begin;

	FVector tangent = FVector::CrossProduct(lineDirection, randDirection);
	//spline_mesh->SetStartAndEnd(begin, tangent, end, tangent,truea);
	/*spline_mesh->SetStartPosition(origin + GetActorRotation().RotateVector(begin));
	spline_mesh->SetEndPosition(origin + GetActorRotation().RotateVector(end));*/
	spline_mesh->SetStartPosition(begin);
	spline_mesh->SetEndPosition(end);
	spline_mesh->SetStartTangent(tangent);
	spline_mesh->SetEndTangent(tangent);
}

// Called when the game starts or when spawned
void ALine::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

