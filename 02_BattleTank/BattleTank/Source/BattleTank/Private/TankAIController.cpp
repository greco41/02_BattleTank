// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Tank.h"
#include "BattleTank.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("AIController not finding player tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AIController found player tank %s"), *(PlayerTank->GetName()));
	}
	UE_LOG(LogTemp, Warning, TEXT("AIController Begin Play"));

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank()){
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}

ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const {
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) {return nullptr;}
	return Cast<ATank>(PlayerPawn);
}