// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::OnInput(const FString &Input) // When the player hits enter
{
    ClearScreen();
    FString OutputString{TEXT("You have ")};
    OutputString.AppendInt(Lives);
    OutputString.Append(TEXT("Lives"));
    PrintLine(Input);
    PrintLine(OutputString);
    if (CheckUserInput(Input))
    {
        PrintLine("Yay");
    }
    else
    {
        PrintLine("Bhak");
        Lives--;
    }
}

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    Greet();
    InitialiseGameVars();
    Question();
}

void UBullCowCartridge::Greet()
{
    PrintLine(TEXT("Welcome to BullCow game yo"));
}

void UBullCowCartridge::InitialiseGameVars()
{

    SetHiddenWord(TEXT("cake"));
    SetHiddenWordLength();
    SetLives(HiddenWordLength);
}

void UBullCowCartridge::Question() const
{
    FString OutputString{TEXT("Guess the ")};
    OutputString.AppendInt(HiddenWordLength);
    OutputString.Append(TEXT(" letter word"));
    PrintLine(OutputString);
    PrintLine(TEXT("Press Enter to get started."));
}

void UBullCowCartridge::SetHiddenWord(const FString &TempHiddenWord)
{
    HiddenWord = TempHiddenWord;
}

void UBullCowCartridge::SetLives(const int32 &NewLifeVal)
{
    Lives = NewLifeVal;
}

void UBullCowCartridge::SetHiddenWordLength()
{
    HiddenWordLength=HiddenWord.Len();
}

bool UBullCowCartridge::CheckUserInput(const FString &UserInput) const
{
    if (UserInput == HiddenWord && Lives>0)
        return true;
    else
        return false;
}
