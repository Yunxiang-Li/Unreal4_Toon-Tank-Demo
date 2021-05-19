#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

//Forward declaration.
class ATankGameModeBase;

/**
 * @brief This class represents a health component which inherits from the UActorComponent class.
 * 
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TOONTANKS_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	/**
	 * @brief 
	 * 
	 * @param DamagedActor A pointer to a AActor object indicates the damage taker(player).
	 * @param Damage A float indicates the damage. 
	 * @param DamageType  A const pointer to a UDamageType object indicates the type of damage.
	 * @param InstigatedBy A pointer to a AController object indicates the controller responsible for the damage.
	 * @param DamagedCauser A pointer to a AActor object indicates the Actor that directly caused the damage.
	 */
	UFUNCTION()
	void TakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamagedCauser);

private:

	// Default health of the player(Toon Tank object).
	UPROPERTY(EditAnywhere)
	float DefaultHealth{100.f};

	// Store the player's current health.
	float CurrHealth{100.f};

	// Store the pointer to a ATankGameModeBase object indicates the game mode.
	ATankGameModeBase* GameModePtr;
		
};
