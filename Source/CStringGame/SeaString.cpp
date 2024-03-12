// Fill out your copyright notice in the Description page of Project Settings.


#include "SeaString.h"

// Sets default values
ASeaString::ASeaString()
	//:
	// rng(rd()),
	// indexPicker(0,6)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Last char of string neds to be 0 so C-String ends
	// word[4] = 0;
	// for(char* p = word; word != 0; p++)
	// {
	// 	char newSymbol = symbols[indexPicker(rng)];
	// 	*p= newSymbol;
	// }


}

// Called when the game starts or when spawned
void ASeaString::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASeaString::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

