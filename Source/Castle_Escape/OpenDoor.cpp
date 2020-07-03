// Copyright Michael S. Walker 2020
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Actor.h"
#include "OpenDoor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	CurrentYaw = InitialYaw = GetOwner()->GetActorRotation().Yaw;
	TargetYaw += InitialYaw;
	InitialTargetYaw = TargetYaw;
	if (PressurePlate == NULL)
	{
		UE_LOG(LogTemp, Error, TEXT("%s has the open door component on it, but no pressurplate set!"), *GetOwner()->GetName())
	}

	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
}

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (PressurePlate != NULL && PressurePlate->IsOverlappingActor(ActorThatOpens))
	{
		TargetYaw = InitialTargetYaw;
		OpenDoor(DeltaTime);
	}
	else if (CurrentYaw != InitialYaw && !PressurePlate->IsOverlappingActor(ActorThatOpens))
	{
		TargetYaw = InitialYaw;
		OpenDoor(DeltaTime);
	}
}

void UOpenDoor::OpenDoor(float DeltaTime)
{
	FRotator DoorRotation = GetOwner()->GetActorRotation();
	CurrentYaw = FMath::FInterpTo(CurrentYaw, TargetYaw, DeltaTime, 1.f);
	DoorRotation.Yaw = CurrentYaw;
	GetOwner()->SetActorRotation(DoorRotation);
}
