#pragma once

#include "CoreMinimal.h"
#include "ToonTanks/Pawns/PawnBase.h"
#include "PawnTank.generated.h"

// Forward declaration
class USpringArmComponent;
class UCameraComponent;
/**
 * @brief This class represents all behaviors a pawn tank should have which inherits from the APawnBase class.
 * 
 */
UCLASS()
class TOONTANKS_API APawnTank : public APawnBase
{
	GENERATED_BODY()

public:
	// Constructor
	APawnTank();

	// Called every frame.
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input.
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/**
	 * @brief Play death effects: particle, sound and camera shake. 
	 * Moreover, Inform GameMode that player died, stop movement input and hide all components.
	 * 
	 */
	virtual void HandleDestruction() override;

	/**
	 * @brief Check whether the player(pawn tank object) is alive or not.
	 * 
	 * @return true player is alive.
	 * @return false player is dead
	 */
	bool GetIsPlayerAlive();

protected:
	// Called when the game starts or when spawned.
	virtual void BeginPlay() override;

private:
	// This component tries to maintain its children at a fixed distance from the parent
	// but will retract the children if there is a collision, and spring back when there is no collision.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArm;

	// A capsule generally used for simple collision.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* Camera;

	// A FVector indicates the pawn tank object's current moving direction.	
	FVector MoveDirection;
	// A Floating point quaternion that can represent a rotation about an axis in 3-D space.
	FQuat RotationDirection;

	// PlayerControllers are used by human players to control Pawns.
	APlayerController* PlayerControllerPtr;

	// Initialize the tank's move speed.
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	float MoveSpeed {500.f};
	// Initialize the tank's rotate speed.
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	float RotateSpeed = {100.f};
	
	// A boolean value indicates whether the player is still alive or not.
	bool IsPlayerAlive{true};

	/**
	 * @brief Calculate the tank's move direction according to the pressed key's defined float value(W/D keys will be +1, S/A will be -1).
	 * 
	 * @param value A float indicates the pressed key's defined float value.
	 */
	void CalculateMoveInput(float value);

	/**
	 * @brief Calculate the tank's rotate direction according to the pressed key's defined float value(W/D keys will be +1, S/A will be -1).
	 * 
	 * @param value A float indicates the pressed key's defined float value.
	 */
	void CalculateRotateInput(float value);

	/**
	 * @brief Move the tank according to its move direction.
	 * 
	 */
	void Move();

	/**
	 * @brief Rotate the tank according to its rotate direction.
	 * 
	 */
	void Rotate();

};
