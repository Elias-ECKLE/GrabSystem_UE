// Fill out your copyright notice in the Description page of Project Settings.


#include "GrabActor.h"

// Sets default values for this component's properties
UGrabActor::UGrabActor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabActor::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGrabActor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	
}

void UGrabActor::GrabPressed(UPhysicsHandleComponent* ptrPhysicsHandle, float distanceRaycast)
{
	//init vectors
	FVector startVector_Raycast = this->GetOwner()->GetActorLocation();
	FVector actorForward = GetOwner()->GetActorForwardVector();
	FVector endVector_Raycast = startVector_Raycast+(actorForward * distanceRaycast);

	FHitResult Hit;
	FCollisionQueryParams params;
	FCollisionObjectQueryParams objectsParam;
	objectsParam.AddObjectTypesToQuery(ECollisionChannel::ECC_PhysicsBody);


	//debug direction et collision ligne
	DrawDebugLine(GetWorld(), startVector_Raycast, endVector_Raycast, FColor::Red, false, 5.0f, 0, 5.0f);

	//creation raycast, si le raycast touche bien un objet alors on affiche grabCollision
	if (this->GetOwner()->GetWorld()->LineTraceSingleByObjectType(Hit, startVector_Raycast, endVector_Raycast, objectsParam, params)) {
		UE_LOG(LogTemp, Warning, TEXT("grabCollision"));

		//grabed object :
		ptrPhysicsHandle->GrabComponentAtLocation(Hit.GetComponent(),"none", Hit.Location);	
	}
	
	


}

void UGrabActor::GrabReleased(UPhysicsHandleComponent* ptrPhysicsHandle)
{
	//quand on release la touche alors l'objet grabed est relaché
	if (ptrPhysicsHandle != nullptr) {
		ptrPhysicsHandle->ReleaseComponent();
		UE_LOG(LogTemp, Warning, TEXT("grabReleased"));
	}

	
}

void UGrabActor::setHandleLocation_Rotation(UPhysicsHandleComponent* ptrPhysicsHandle,float coeffGrab)
{
	//coeffGrab = coeff grab déplacement
	//FVector actorLocation = this->GetOwner()->GetActorLocation();
	//FVector actorForward = GetOwner()->GetActorForwardVector();
	FVector newLocation;
	FRotator newRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(newLocation,newRotation);


	ptrPhysicsHandle->SetTargetLocationAndRotation(newLocation,newRotation);
	



}



