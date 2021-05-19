#include "ToonTanks/Components/HealthComponent.h"
#include "ToonTanks/GameModes/TankGameModeBase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame. You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// Set player's original health.
	this -> CurrHealth = this -> DefaultHealth;

	// Store the game world's game mode object
	this -> GameModePtr = Cast<ATankGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	
	// Dynamically binds the Takedamage function when current Health component's owner(an AActor object) is damaged in anyway.
	GetOwner() -> OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::TakeDamage);

}

void UHealthComponent::TakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamagedCauser) 
{	
	// If no damage occurs or the player is already died.
	if (Damage == 0 || this -> CurrHealth <= 0)
	return;

	// Ensure that the new health is in the range of 0.f - 100.f inclusive.
	this -> CurrHealth = FMath::Clamp(this -> CurrHealth - Damage, 0.f, this -> DefaultHealth);

	// Check if the new health is equal to or under zero.
	if (this -> CurrHealth <= 0) {
		// If GameModePtr exists
		if (this -> GameModePtr) {
			// Call ActorDied function on health component's owner. 
			this -> GameModePtr -> ActorDied(GetOwner());
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("Health Component has no GameModePtr attached!"));
		}
		

	}
}


