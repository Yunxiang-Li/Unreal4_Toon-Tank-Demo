#include "PawnTank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

APawnTank::APawnTank()
{
	// Initialize the USpringArmComponent.
	this -> SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
    this -> SpringArm -> SetupAttachment(this -> RootComponent);

    // Initialize the UCameraComponent.
	this -> Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    this -> Camera -> SetupAttachment(this -> SpringArm);
}

// Called when the game starts or when spawned
void APawnTank::BeginPlay()
{
	Super::BeginPlay();

	// Store the player's controller.
	this -> PlayerControllerPtr = Cast<APlayerController>(GetController());
}

// Called every frame
void APawnTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Rotate and move the tank each tick.
	this -> Rotate();
	this -> Move();

	// Check if the player controller exists.
	if (this -> PlayerControllerPtr) {

		// Structure containing information about one hit of a trace, such as point of impact and surface normal at that point.
		FHitResult TraceHitRes;
		// False for simple collision check.
		this -> PlayerControllerPtr -> GetHitResultUnderCursor(ECC_Visibility, false, TraceHitRes);
		// Get the cursor hit direction.
		FVector HitLocation = TraceHitRes.ImpactPoint;
		// Rotate the tank's turret.
		RotateTurret(HitLocation);
	}
}

// Called to bind functionality to input
void APawnTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Use PlayerInputComponent to binds the CalculateMoveInput function to "MoveForward" axis.
	PlayerInputComponent -> BindAxis("MoveForward", this, &APawnTank::CalculateMoveInput);
	// Use PlayerInputComponent to binds the CalculateRotateInput function to "Turn" axis.
	PlayerInputComponent -> BindAxis("Turn", this, &APawnTank::CalculateRotateInput);

	// Use PlayerInputComponent to binds the APawnTank function to "Fire" action.
	PlayerInputComponent -> BindAction("Fire", IE_Pressed, this, &APawnTank::Fire);
}

void APawnTank::CalculateMoveInput(float value) 
{
	// +X axis 's value = input value * MoveSpeed * current frame's delta time in seconds.
	this -> MoveDirection = FVector(value * this -> MoveSpeed * GetWorld() -> DeltaTimeSeconds, 0, 0);
}

void APawnTank::CalculateRotateInput(float value) 
{
	// Rotate amount = input value * RotateSpeed * current frame's delta time in seconds.
	float RotateAmount{value * RotateSpeed * GetWorld() -> DeltaTimeSeconds};

	// Second parameter of FRotator indicates the rotation around the up axis (around Z axis).
	FRotator rotator = FRotator(0, RotateAmount, 0);
	// Set the RotationDirection to be the FQuat initialized with the rotator we defined above.
	this -> RotationDirection = FQuat(rotator);
}

void APawnTank::Move() 
{
	// Adds a FVector change to the location of this component in its local reference frame.
	AddActorLocalOffset(this -> MoveDirection, true);
}

void APawnTank::Rotate() 
{	
	// Adds a FQuat change to the location of this component in its local reference frame.
	AddActorLocalRotation(this -> RotationDirection, true);
}

void APawnTank::HandleDestruction() 
{
	Super::HandleDestruction();
	// Hide player's all components.
	this -> IsPlayerAlive = false;

	// Hide pawn tank object.
	this -> SetActorHiddenInGame(true);
	// Disable pawn tank's tick function.
	this -> SetActorTickEnabled(false);
}

bool APawnTank::GetIsPlayerAlive() 
{
	return this -> IsPlayerAlive;
}