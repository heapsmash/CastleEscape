// Copyright Michael S. Walker 2020

#include "OpenDoor.h"
#include "GameFramework/Actor.h"

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
	InitialYaw = CurrentYaw = GetOwner()->GetActorRotation().Yaw; 
	TargetYaw = InitialYaw + 90.f;

}

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// UE_LOG(LogTemp, Warning, TEXT("%s "), *GetOwner()->GetActorRotation().ToString());
	// UE_LOG(LogTemp, Warning, TEXT("Yaw is: %f"), GetOwner()->GetActorRotation().Yaw);

	FRotator OpenDoor(0.f, 0.f, 0.f); 
	float CurrentYaw = GetOwner()->GetActorRotation().Yaw;
	// OpenDoor.Yaw = FMath::FInterpConstantTo(CurrentYaw, TargetYaw, DeltaTime, 45.f);
	OpenDoor.Yaw = FMath::FInterpTo(CurrentYaw, TargetYaw, DeltaTime, 2.f);
	GetOwner()->SetActorRotation(OpenDoor);


	// ...
}
