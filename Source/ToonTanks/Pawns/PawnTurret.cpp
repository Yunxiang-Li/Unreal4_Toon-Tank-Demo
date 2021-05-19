#include "PawnTurret.h"
#include "PawnTank.h"

#include "Kismet/GameplayStatics.h"

// Called when the game starts or when spawned
void APawnTurret::BeginPlay()
{
	Super::BeginPlay();
    // Sets the FireRateTimerHandle timer to call the "CheckFireCondition" function at a set interval(FireRate).
    // If a timer is already set for this handle, it will replace the current timer.
    GetWorld() -> GetTimerManager().SetTimer(this -> FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, this -> FireRate, true);

    // Set the player pawn object pointer(pawn tank object pointer).
    this -> PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void APawnTurret::HandleDestruction() 
{   
    // Call base function to play all effects.
    Super::HandleDestruction();
    // Destroy the turret object.
    Destroy();
}

// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    // If player is not exist or the player is outside of the turret's fire range.
    if (!this -> PlayerPawn || ReturnDistanceToPlayer() > this -> FireRange) {
        return;
    }
    
    // Get player(tank)'s current location.
    FVector PlayerLocation = this -> PlayerPawn -> GetActorLocation();
    // Let the turret rotate according to player's current location.
    RotateTurret(PlayerLocation);
}

void APawnTurret::CheckFireCondition() 
{   
    // Check if the pawn tank object is not null and is not destoryed
    if (!this -> PlayerPawn || !(this -> PlayerPawn -> GetIsPlayerAlive())) {
        return;
    }
    
    // Check if the distance between turrent and the tank is less than or equal to the defined FireRange.
    if (ReturnDistanceToPlayer() <= this -> FireRange) {
        Fire();
    }
}

float APawnTurret::ReturnDistanceToPlayer() 
{
    // Check if the pawn tank object is not null
    if (!this -> PlayerPawn) {
        return 0.f;
    }

    // Get distance between pawn turret object's location(a FVector) and pawn tank object's location(a FVector).
    float Distance = FVector::Dist(this -> PlayerPawn -> GetActorLocation(), this -> GetActorLocation());

    return Distance;
}