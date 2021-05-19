#include "ToonTanks/Pawns/PawnBase.h"
#include "Components/CapsuleComponent.h"
#include "ToonTanks/Actors/ProjectileBase.h"
#include "ToonTanks/Components/HealthComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APawnBase::APawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Initialize the UCapsuleComponent.
	this -> CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	// Set it as the root component.
	this -> RootComponent = CapsuleComp;

	// Initialize the UStaticMeshComponents.
	this -> BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	this -> BaseMesh -> SetupAttachment(this -> RootComponent);

	this -> TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	this -> TurretMesh -> SetupAttachment(this -> BaseMesh);

	// Initialize the USceneComponent.
	this -> ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	this -> ProjectileSpawnPoint -> SetupAttachment(TurretMesh);

	// Initialize the health component.
	this -> HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health Component"));
}

void APawnBase::RotateTurret(FVector LookAtTarget) 
{
	// Input FVector's X and Y position and set the Z position to be the turret mesh's original Z position which means no movement in Z axis.
	FVector LookAtTargetOffset = FVector(LookAtTarget.X, LookAtTarget.Y, this -> TurretMesh -> GetComponentLocation().Z);

	// Get the turret mesh's curret location.
	FVector CurrentLocation = this -> TurretMesh -> GetComponentLocation();

	// Convert a newly constructed FVector(LookAtTargetOffset - CurrentLocation) to a FRotator.
	FRotator Rotation = FVector(LookAtTargetOffset - CurrentLocation).Rotation();

	// Set the turret mesh's new Rotator.
	this -> TurretMesh -> SetWorldRotation(Rotation);
}

void APawnBase::Fire() 
{	

	// First check if ProjectileClass is not nullptr.
	if (ProjectileClass) {
		// Get projectile spawn point's location and rotation.
		FVector SpawnLocation = this -> ProjectileSpawnPoint -> GetComponentLocation();
		FRotator SpawnRotation = this -> ProjectileSpawnPoint -> GetComponentRotation();

		// Get the pointer of the spawned AProjectileBase object.
		AProjectileBase* TempProjectile = GetWorld() -> SpawnActor<AProjectileBase>(ProjectileClass, SpawnLocation, SpawnRotation);

		// Set this AProjectileBase object to be owned by the PawnBase class.
		TempProjectile -> SetOwner(this);
	}
}

void APawnBase::HandleDestruction() 
{	
	// Plays the death particle effect at the pawnbase derived object's location(default rotation).
	UGameplayStatics::SpawnEmitterAtLocation(this, this -> DeathParticle, GetActorLocation());

	// Play the pawn base derived object's death sound effect.
	UGameplayStatics::SpawnSoundAtLocation(this, this -> DeathSound, GetActorLocation());

	// Play death shake.
	GetWorld() -> GetFirstPlayerController() -> ClientStartCameraShake(this -> DeathShake);
}


