// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CurseSymbol.h"
#include <random>
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SeaString.generated.h"

UCLASS()
class CSTRINGGAME_API ASeaString : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASeaString();
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void PrintCString( char* p);
	void PrintSelectedSymbol();
	
	//Once correct symbol has has been selected move and select the next symbol in CString
	void MoveSelectedSymbol();

	 UFUNCTION(BlueprintCallable)
	 int32 GetSelectedSymbol() const;
	 
private:
	char symbols[6] = {'!', '#', '&', '/','$','?'};
	static constexpr int wordLength= 5;
	char word[wordLength] = {1,1,1,1,0};
	char* selectedSymbol;
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_int_distribution<int> indexPicker;
};
