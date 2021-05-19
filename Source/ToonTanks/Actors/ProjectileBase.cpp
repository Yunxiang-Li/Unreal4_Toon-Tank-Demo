#include "ToonTanks/Actors/ProjectileBase.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
AProjectileBase::AProjectileBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Initialize the UStaticMeshComponent.
	this -> ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projectile Mesh"));
    this -> RootComponent = this -> ProjectileMesh;

	// Initialize the ParticleTrail (a pointer to the UParticleSystemComponent object).
	this -> ParticleTrail = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle Trail"));
	// Attach the ParticleTrail to the root component.
	this -> ParticleTrail -> SetupAttachment(this -> RootComponent);

	// Dynamically binds the OnHit funtion when projectilemesh collides with something.
	this -> ProjectileMesh -> OnComponentHit.AddDynamic(this, &AProjectileBase::OnHit);

	// Initialize the UProjectileMovementComponent.
	this -> ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));

	// Set projectile's initial speed and max speed.
	this -> ProjectileMovement -> InitialSpeed = this -> MovementSpeed;
	this -> ProjectileMovement -> MaxSpeed = this -> MovementSpeed;

	// Set how long the projectile lives before dstroying.
	this -> InitialLifeSpan = 3.f;
}

// Called when the game starts or when spawned
void AProjectileBase::BeginPlay()
{
	Super::BeginPlay();

	// Play the projectile launched sound effect.
	UGameplayStatics::PlaySoundAtLocation(this, this -> LaunchSound, GetActorLocation());
	
}

void AProjectileBase::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherHitComp, FVector NormalInpulse, const FHitResult& HitRes) 
{
	// Get current ProjectileBase object's owner.
	AActor* ProjectileOwner = GetOwner();

	// Check if Owner is not nullptr.
	if (!ProjectileOwner)
	return;

	// Check if the other AActor object is not nullptr and is not the current ProjectileBase object itself.
	// Also check if the other AActor object is not the current ProjectileBase object's owner.
	if (OtherActor && OtherActor != this && OtherActor != ProjectileOwner) {
		// Hurts the specified actor with generic damage.

		// Owner -> GetInstigatorController() returns the controller of the pawnbase derived object which was responsible for causing this damage.
		UGameplayStatics::ApplyDamage(OtherActor, this -> Damage, ProjectileOwner -> GetInstigatorController(), this, this -> DamageType);

		// Plays the hit particle effect at the pawnbase derived object's location(default rotation).
		UGameplayStatics::SpawnEmitterAtLocation(this, this -> HitParticle, GetActorLocation());

		// Play the projectile hit sound effect.
		UGameplayStatics::SpawnSoundAtLocation(this, this -> HitSound, GetActorLocation());

		// Play Hit shake.
		GetWorld() -> GetFirstPlayerController() -> ClientStartCameraShake(this -> HitShake);

		Destroy();
	}

	// TODO: Add more effects.
}

