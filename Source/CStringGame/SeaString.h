// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CurseSymbol.h"
#include <random>
#include <algorithm>
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
	
	// User Functions and Variables
	void PrintCString( char* p);
	FString fWord;

	// ************************** Unreal Functions *********************************************//

	//Once correct symbol has has been selected move and select the next symbol in CString
	UFUNCTION(BlueprintCallable)
	void MoveSelectedSymbol();

	UFUNCTION(BlueprintCallable)
	int32 GetSelectedSymbol() const;
	
	UFUNCTION(BlueprintCallable)
	void PrintSelectedSymbol();

	UFUNCTION(BlueprintCallable)
	FString GetFWord();

	UFUNCTION(BlueprintCallable)
	int32 GetCurrentInd() const;
	 
private:
	char symbols[6] = {'!', '#', '&', '/','$','?'};
	static constexpr int wordLength= 5;
	static constexpr int spaces = wordLength - 1;
	static constexpr int totalCharLength = wordLength + spaces;
	char word[totalCharLength] = {1,1,1,1,1,1,1,1,0};
	char* selectedSymbol;
	int32 currentIndex = 0;
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_int_distribution<int> indexPicker;
};
