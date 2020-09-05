// Fill out your copyright notice in the Description page of Project Settings.


#include "Drawer.h"

// Sets default values
ADrawer::ADrawer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	root = CreateDefaultSubobject<USceneComponent>(TEXT("root"));
	RootComponent = root;


	originMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("originMesh"));
	originMesh->AttachTo(root);
}

// Called when the game starts or when spawned
void ADrawer::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADrawer::draw()
{

}

void ADrawer::show()
{

}

void ADrawer::hide()
{

}

// Called every frame
void ADrawer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

