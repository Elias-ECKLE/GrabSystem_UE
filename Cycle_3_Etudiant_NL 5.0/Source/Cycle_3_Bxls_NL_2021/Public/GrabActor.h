// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/GameplayStatics.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

//includes added---------------------------
#include "DrawDebugHelpers.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "GameFramework/PlayerController.h"
//----------------------------------------

#include "GrabActor.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CYCLE_3_BXLS_NL_2021_API UGrabActor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabActor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void GrabPressed(UPhysicsHandleComponent* ptrPhysicsHandle,float distanceRaycast);
	

	UFUNCTION(BlueprintCallable)
	void GrabReleased(UPhysicsHandleComponent* value);

	UFUNCTION(BlueprintCallable)
	void setHandleLocation_Rotation(UPhysicsHandleComponent* ptrPhysicsHandle,float coeffGrab);
};
