#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectileBase.generated.h"

// Forward declaration.
// UProjectileMovementComponent updates the position of another component during its tick.
class UProjectileMovementComponent;

/**
 * @brief The base class of all Projectile related derived classes which inherits from the AActor class.
 * 
 */
UCLASS()
class TOONTANKS_API AProjectileBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectileBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	// Store the UProjectileMovementComponent and UStaticMeshComponent of the projectiles.
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))   
	UProjectileMovementComponent* ProjectileMovement;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))      
	UStaticMeshComponent* ProjectileMesh;

	// Store the pointer to the UParticleSystemCoponent object(particle trail effect).
	UPROPERTY(EditAnywhere, Category = "Effects")
	UParticleSystemComponent* ParticleTrail;

	// A template class that provides UClass type safety.
    UPROPERTY(EditDefaultsOnly, Category = "Damage")
	TSubclassOf<UDamageType> DamageType;

	// Initialize the projectile's movement speed.
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	float MovementSpeed{1300.f};

	// Initialize the projectile's damage.
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage", meta = (AllowPrivateAccess = "true"))	
	float Damage{50.f};

	// Store the pointer to the hit particle object.
	UPROPERTY(EditAnywhere, Category = "Effects")
	UParticleSystem* HitParticle;

	// Store the pointer to the HitSound USoundBase object.
	UPROPERTY(EditAnywhere, Category = "Effects")
	USoundBase* HitSound;
	// Store the pointer to the LaunchSound USoundBase object.
	UPROPERTY(EditAnywhere, Category = "Effects")
	USoundBase* LaunchSound;

	// Store a subclass of UMatineeCameraShake class which indicates the hit camera shake.
	UPROPERTY(EditAnywhere, Category = "Effects")
	TSubclassOf<UMatineeCameraShake> HitShake;

	/**
	 * @brief Declare the OnHit delegate function.
	 * 
	 * @param HitComp The pointer to the binding object's UPrimitiveComponent.
	 * @param OtherActor The pointer to the other AActor object(collides with the binding object). 
	 * @param OtherHitComp The pointer to the other AActor object's UPrimitiveComponent.
	 * @param NormalInpulse A FVector object indicates an instantaneous force of the hit.
	 * @param HitRes A reference to a const FHitResult object which stores the hit result.
	 */
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherHitComp, FVector NormalInpulse, const FHitResult& HitRes);
};
