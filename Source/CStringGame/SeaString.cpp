// Fill out your copyright notice in the Description page of Project Settings.


#include "SeaString.h"

// Sets default values
ASeaString::ASeaString()
	:
	rng(rd()),
	indexPicker(0,5)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Last char of string neds to be 0 so C-String ends
	word[totalCharLength] = 0;
	for(char* p = word; *p != 0; p++)
	{
		char newSymbol = symbols[indexPicker(rng)];
		*p = newSymbol;
	}
	Spacer(word);
	selectedSymbol = word;

	//sets FSTring
	fWord = word;
	PrintSelectedSymbol();
	
	// UPROPERTY(VisibleAnywhere, Category="Symobl Type");
	// int32 intSelectedSymbol = int32(*selectedSymbol);
}

// Called when the game starts or when spawned
void ASeaString::BeginPlay()
{
	Super::BeginPlay();
	//PrintCString(word);
}

// Called every frame
void ASeaString::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ASeaString::PrintCString(char* p)
{
	FString msg = "test";
	// UE_LOG(LogTemp, Display, TEXT("Heres the string: %s"), *msg);
	for(; *p != 0; p++)
	{
		//UE_LOG(LogTemp, Display, TEXT("Heres the string: %s"), *msg);
		//UE_LOG(LogTemp, Display, TEXT("Heres the string: %c"), *p);
	} 
}
void ASeaString::PrintSelectedSymbol()
{
	UE_LOG(LogTemp, Display, TEXT("The String is:%s"),*fWord);
}

 int32 ASeaString::GetSelectedSymbol() const
 {
	int32 intSelectedSymbol = int32(*selectedSymbol);
	return intSelectedSymbol;
 }

void ASeaString::MoveSelectedSymbol()
 {
	selectedSymbol++;
	currentIndex++;
	if(*selectedSymbol == ' ')
	{
		selectedSymbol++;
		currentIndex++;
	}
	if(currentIndex > totalCharLength)
		{
			currentIndex = 0;
		}
 }
 FString ASeaString::GetFWord()
 {
	return fWord;
 }

int32 ASeaString::GetCurrentInd() const
{
	return currentIndex;
}
void ASeaString::Spacer(char* p)
{
	p++;
	for(int i = 0; i < spaces; i++)
	{
		*p = ' ';
		p += 2;
	}
}