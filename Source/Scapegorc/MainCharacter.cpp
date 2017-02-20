// Fill out your copyright notice in the Description page of Project Settings.

#include "Scapegorc.h"
#include "MainCharacter.h"
#include "PaperFlipbookComponent.h"


AMainCharacter::AMainCharacter() {
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->TargetArmLength = 500.0f;
	CameraBoom->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->ProjectionMode = ECameraProjectionMode::Orthographic;
	Camera->OrthoWidth = 2048.0f;
	Camera->SetupAttachment(CameraBoom);


	
}
void AMainCharacter::BeginPlay() {
	Super::BeginPlay();

	//GetSprite()->SetFlipbook(Idle);
}


void AMainCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Move", this, &AMainCharacter::Move);

	

	//PlayerInputComponent->BindTouch(IE_Pressed, this, &AMainCharacter::TouchStarted);
	//PlayerInputComponent->BindTouch(IE_Released, this, &AMainCharacter::TouchStopped);



}

void AMainCharacter::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);

	//UpdateFlipbook();
}

void AMainCharacter::Move(float Value) {
	AddMovementInput(FVector(1.0f, 0.0f, 0.0f), Value);
}