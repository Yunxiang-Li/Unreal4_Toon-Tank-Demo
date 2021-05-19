#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnBase.generated.h"

// Forward declaration.
class UCapsuleComponent;
class AProjectileBase;
class UHealthComponent;

/**
 * @brief The base class of all pawn related derived classes which inherits from the APawn class.
 * 
 */
UCLASS()
class TOONTANKS_API APawnBase : public APawn
{
	GENERATED_BODY()

public:
	// Constructor, sets default values for this pawn's properties.
	APawnBase();

	/**
	 * @brief Play death effects: particle, sound and camera shake.
	 * 
	 */
	virtual void HandleDestruction();

private:
	// A capsule generally used for simple collision.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UCapsuleComponent* CapsuleComp;

	// A static mesh is a piece of geometry that consists of a static set of polygons.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretMesh;
	
	// Store the health component;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UHealthComponent* HealthComponent;

	// Has a transform allowing it to be physically present in the game world at a certain location.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* ProjectileSpawnPoint;

	// Store the projectile type(AProjectileBase object) as a subclass.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Projectile Type", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AProjectileBase> ProjectileClass;

	// Store the pointer to the death particle object.
	UPROPERTY(EditAnywhere, Category = "Effects")
	UParticleSystem* DeathParticle;

	// Store the pointer to the death sound USoundBase object.
	UPROPERTY(EditAnywhere, Category = "Effects")
	USoundBase* DeathSound;

	// Store a subclass of UMatineeCameraShake class which indicates the death camera shake.
	UPROPERTY(EditAnywhere, Category = "Effects")
	TSubclassOf<UMatineeCameraShake> DeathShake;

protected:
	/**
	 * @brief Update the turret mesh rotation by facing the input FVector passed by derived classes.
	 * 
	 * @param LookAtTarget 
	 */
	void RotateTurret(FVector LookAtTarget);

	/**
	 * @brief Spawn a projectile object at the projectile spawn position.
	 * 
	 */
	void Fire();
	
};


