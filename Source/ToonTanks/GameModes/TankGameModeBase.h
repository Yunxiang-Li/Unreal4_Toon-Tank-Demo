#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TankGameModeBase.generated.h"

// Forward declaration.
class APawnTurret;
class APawnTank;
class APlayerControllerBase;

/**
 * @brief This class represents the game mode base of the Toon Tank game which inherits from the AGameModeBase class.
 * 
 */
UCLASS()
class TOONTANKS_API ATankGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:

	/**
	 * @brief All hebaviors after a certain AActor object died(destroyed).
	 * 
	 * @param DeadActor A pointer to a AActor object(maybe a PawnTank object or a PawnTurret object).
	 */
	void ActorDied(AActor* DeadActor);

protected:

	// A integer indicates the delay seconds of game start.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game Loop")
	int32 StartDelay{3};

	// Called when the game starts or when spawned.
	virtual void BeginPlay() override;

	/**
	 * @brief All behaviors for game start. This functions is not going to be implemented in this C++ class but in a derived blueprint.
	 * 
	 */
	UFUNCTION(BlueprintImplementableEvent)
	void GameStart();

	/**
	 * @brief All behaviors for game over. This functions is not going to be implemented in this C++ class but in a derived blueprint.
	 * 
	 * @param PlayerWon A boolean value check if the player won or not.
	 */
	UFUNCTION(BlueprintImplementableEvent)	
	void GameOver(bool PlayerWon);

private:

	// Store the pointer to a APawnTank object indicates the player.
	APawnTank* PlayerTank;

	// Store the number of Turrets the player needs to destory to win.
	int32 TargetTurrets;

	// Store the pointer to player controller object.
	APlayerControllerBase* PlayerControllerPtr;

	/**
	 * @brief Initialize the start countdown, activate all turrets, check for pawns and call the blueprint function GameStart().
	 * 
	 */
	void HandleGameStart();

	/**
	 * @brief Handle game over situations according to the input bool flag by calling blueprint function GameOver(bool).
	 * 
	 * @param PlayerWon A bool indicates if player won or not( true if player destroyed all turrets and false if player died)
	 */
	void HandleGameOver(bool PlayerWon);

	/**
	 * @brief Get the number of all Turret objects.
	 * 
	 * @return int32 An int32 value indicates the number of all Turret objects.
	 */
	int32 GetTargetTurretCount();
};
