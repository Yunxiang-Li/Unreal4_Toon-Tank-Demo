#pragma once

#include "CoreMinimal.h"
#include "ToonTanks/Pawns/PawnBase.h"
#include "PawnTurret.generated.h"

// Forward declaration.
class APawnTank;

/**
 * @brief This class represents all behaviors that a pawn turret object should have which inherits from the APawnBase class.
 * 
 */
UCLASS()
class TOONTANKS_API APawnTurret : public APawnBase
{
	GENERATED_BODY()

public:
  	// Called every frame.
	virtual void Tick(float DeltaTime) override;
	
	/**
	 * @brief Play death effects: particle, sound and camera shake. Moreover destory the turret object.
	 * 
	 */
	virtual void HandleDestruction() override;

private:

	// Unique handle that can be used to distinguish timers that have identical delegates.
	FTimerHandle FireRateTimerHandle;

	// Set the fire rate(The amount of time (in seconds) between set and firing. If <= 0.f, clears existing timers).
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	float FireRate{2.f};

	// Set the fire range of the pawn turret object.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	float FireRange{500.f};

	// Store the pointer of the pawn tank object.
	APawnTank* PlayerPawn;

	/**
	 * @brief Check the fire condition and if suitable then fires.
	 * 
	 */
	void CheckFireCondition();

	/**
	 * @brief Return the distance between the pawn tank object and the pawn turret object.
	 * 
	 * @return float A float value indicates the distance.
	 */
	float ReturnDistanceToPlayer();

protected:
	// Called when the game starts or when spawned.
	virtual void BeginPlay() override;
};
