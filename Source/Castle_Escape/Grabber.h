// Copyright Michael S. Walker 2020

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Grabber.generated.h"

UCLASS()
class CASTLE_ESCAPE_API AGrabber : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGrabber();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
