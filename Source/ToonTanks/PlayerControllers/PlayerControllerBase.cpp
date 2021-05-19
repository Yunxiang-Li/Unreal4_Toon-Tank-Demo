#include "ToonTanks/PlayerControllers/PlayerControllerBase.h"


void APlayerControllerBase::SetPlayerEnableState(bool SetPlayerEnable) 
{
    if (SetPlayerEnable) {

        // Enables the player (pawn tank object) to accept input handled by a PlayerController object.
        GetPawn() -> EnableInput(this);
    }
    else {
        // Disables the player (pawn tank object) to accept input 
        GetPawn() -> DisableInput(this);
    }
    
    // If player accept input then show the mouse cursor.
    this -> bShowMouseCursor = SetPlayerEnable;
}
