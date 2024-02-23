// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <random>
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CurseSymbol.generated.h"

UCLASS()
class CSTRINGGAME_API ACurseSymbol : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACurseSymbol();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, Category="My Physics");
	FVector velocity = FVector(0,0,100);

	

	//Member Functions

	//Getters and Setters

	 UFUNCTION(BlueprintCallable)
	 int32 GetPickedSymbol() const;

	void SetSymbol(char symbol);
	bool GetIsEaten() const;
	void SetIsEaten();

private:
	UPROPERTY(VisibleAnywhere, Category="Symbol Type");
	int32 pickedSymbol;
	int32 symbols[6] = {'!', '#', '&', '/','$','?'};
	bool isEaten = false;
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_int_distribution<int> indexPicker;
	
};
UENUM(BlueprintType)
enum CurseNames
	{
		Defualt = 0,
		ExclamationPoint = 33,
		Pound = 35,
		Ampersand = 38,
		Slash = 47,
		MoneySign = 36,
		Questionmark = 63
	};