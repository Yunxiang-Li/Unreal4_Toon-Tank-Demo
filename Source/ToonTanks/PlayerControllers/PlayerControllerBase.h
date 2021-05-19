#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerControllerBase.generated.h"

/**
 * @brief This class represents the player control behaviors which inherits from the APlayerController class.
 * 
 */
UCLASS()
class TOONTANKS_API APlayerControllerBase : public APlayerController
{
	GENERATED_BODY()

public:

	/**
	 * @brief Handle player object's input control part. 
	 * 
	 * @param SetPlayerEnable A boolean value indicates whether player object should accept input.
	 */
	void SetPlayerEnableState(bool SetPlayerEnable);

};
