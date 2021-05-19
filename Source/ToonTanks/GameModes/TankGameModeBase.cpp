#include "ToonTanks/GameModes/TankGameModeBase.h"
#include "ToonTanks/Pawns/PawnTank.h"
#include "ToonTanks/Pawns/PawnTurret.h"
#include "Kismet/GameplayStatics.h"
#include "ToonTanks/PlayerControllers/PlayerControllerBase.h"

void ATankGameModeBase::BeginPlay() 
{
    Super::BeginPlay();

    // Initialize the start countdown, activate all turrets, check for pawns and call the blueprint function GameStart().
    this -> HandleGameStart();
}

void ATankGameModeBase::ActorDied(AActor* DeadActor) 
{   
    // Check if the player is dead(destroyed).
    if (DeadActor == this -> PlayerTank) {
        // Call player's HandleDestruction function.
        this -> PlayerTank -> HandleDestruction();
        // Handle player dead situation.
        this -> HandleGameOver(false);

        // Check if the player controller object still exists.
        if (this -> PlayerControllerPtr) {
            // Disable player input.
            this -> PlayerControllerPtr -> SetPlayerEnableState(false);
        }
    }
    // Check if one Turret object is dead(destroyed).
    else if (APawnTurret* DestroyedTurret = Cast<APawnTurret>(DeadActor)) {
        // Call turret object's HandleDestruction function.
        DestroyedTurret -> HandleDestruction();

        // If no more turret objects exist
        if ((--this -> TargetTurrets)  == 0) {
            // Handle player win situation.
            this -> HandleGameOver(true);
        }
    }
}

void ATankGameModeBase::HandleGameStart() 
{
    // Get the number of turret objects in the game
    this -> TargetTurrets = this -> GetTargetTurretCount();

    // Get the current world's APawnTank object(the player 0).
    this -> PlayerTank = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
    // Get the current world's player controller object.
    this -> PlayerControllerPtr = Cast<APlayerControllerBase>(UGameplayStatics::GetPlayerController(this, 0));

    // Start the game.
    this -> GameStart();

    // Check if the player controller object still exists.
    if (this -> PlayerControllerPtr) {
        // Disable player input.
        this -> PlayerControllerPtr -> SetPlayerEnableState(false);

        // Use a timer handle.
        FTimerHandle PlayerEnableHandle;
        // PlayerEnableDelegate holds a pointer to PlayerControllerPtr, binds with its SetPlayerEnableState function , and value to pass when situation happens.
        FTimerDelegate PlayerEnableDelegate = FTimerDelegate::CreateUObject(this -> PlayerControllerPtr, &APlayerControllerBase::SetPlayerEnableState, true);

        // Set the timer which enables player input after the start delay time.
        GetWorld() -> GetTimerManager().SetTimer(PlayerEnableHandle, PlayerEnableDelegate, this -> StartDelay, false);
    }
}

void ATankGameModeBase::HandleGameOver(bool PlayerWon) 
{
    this -> GameOver(PlayerWon);
}

int32 ATankGameModeBase::GetTargetTurretCount() 
{
    // A TArray of AActor pointers which stores all turret object pointers.
    TArray<AActor*> TurretActors;

    // Get all Turrent objects in the game world.
    // StaticClass() returns a UClass object representing this class at runtime.
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), APawnTurret::StaticClass(), TurretActors);

    // Return the number of all Turrent objects in the game world.
    return TurretActors.Num();
}
