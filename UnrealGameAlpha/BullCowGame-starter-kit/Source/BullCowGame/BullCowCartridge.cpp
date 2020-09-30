// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    
    HiddenWord=TEXT("CAKE");
    int32 HwordLength{HiddenWord.Len()};

    PrintLine(TEXT("Welcome to BullCow game yo"));
    PrintLine(TEXT("Press Enter to get started."));
    FString Opp{TEXT("Guess the ")};
    Opp.AppendInt(HwordLength);
    Opp.Append(TEXT(" letter word"));
    PrintLine(Opp);

}

void UBullCowCartridge::OnInput(const FString &Input) // When the player hits enter
{
    ClearScreen();
    FString HiddenWord{TEXT("cow")};

    PrintLine(Input);
}