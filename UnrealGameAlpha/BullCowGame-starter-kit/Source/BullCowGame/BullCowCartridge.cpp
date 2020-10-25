// Fill out your copyright notice in the Description page of Project Settings.

#include "BullCowCartridge.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "RandomGenerator.h"

URandomGenerator RandEng{URandomGenerator()};

void UBullCowCartridge::OnInput(const FString &Input) // When the player hits enter
{
    ClearScreen();

    if (Lives > 0 && !bGameOver)
    {

        if (CheckUserInput(Input))
        {
            PrintLine("You have successfully guessed the word");
            bGameOver = true;
            PrintLine(TEXT("Press enter to start anew!"));
        }
        else if (!Input.IsEmpty())
        {
            Lives--;

            PrintLine(FString::Printf(TEXT("You have %i lives left."), Lives));
        }
        else
            PrintLine(FString::Printf(TEXT("You have %i lives left."), Lives));
    }
    else if (!bGameOver)
    {
        bGameOver = true;
        PrintLine(TEXT("You have run out of lives."));
        PrintLine(FString::Printf(TEXT("The word was %s"), *HiddenWord));
    }
    else
    {
        ClearScreen();
        bGameOver = false;
        GameStateManager();
    }
}
void UBullCowCartridge::Greet()
{
    PrintLine(TEXT("Welcome to BullCow game yo"));
}
void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    CreateHiddenWordBook();
    RandEng.init(HiddenWordBookLength);
    GameStateManager();
}

void UBullCowCartridge::GameStateManager()
{
    Greet();
    InitialiseGameVars();
    Question();
}

void UBullCowCartridge::CreateHiddenWordBook()
{
    FString path{FPaths::ProjectContentDir()};
    path /= "HiddenWords/HiddenWordsBook.txt";
    TArray<FString> TempStringArray{};
    FFileHelper::LoadFileToStringArray(TempStringArray, *path);
    
    for (auto &word : TempStringArray)
    {
        TSet<TCHAR> TempSet;
        for (TCHAR &letter : word)
        {
            TempSet.Add(letter);
        }
        if (TempSet.Num() >= 4 && TempSet.Num() == word.Len())
            HiddenWordBook.Add(word);
    } 
    auto TempWords{HiddenWordBook.Array()};
    for (auto &word : TempWords)
    {
        StringHiddenWordBook.Add(word);
    } 
    HiddenWordBookLength = StringHiddenWordBook.Num();
}

void UBullCowCartridge::InitialiseGameVars()
{
    int32 GetNum{RandEng.GenerateRand()};
    PrintLine(TEXT("%i yo"), GetNum);
    SetHiddenWord(StringHiddenWordBook[GetNum]);
    SetHiddenWordLength();
    SetLives(HiddenWordLength);
}
void UBullCowCartridge::SetHiddenWord(const FString &TempHiddenWord)
{
    HiddenWord = TempHiddenWord;
}
void UBullCowCartridge::SetHiddenWordLength()
{
    HiddenWordLength = HiddenWord.Len();
}
void UBullCowCartridge::SetLives(const int32 &NewLifeVal)
{
    Lives = NewLifeVal;
}
void UBullCowCartridge::Question() const
{
    FString OutputString{TEXT("Guess the ")};
    OutputString.AppendInt(HiddenWordLength);
    OutputString.Append(TEXT(" letter word !"));
    PrintLine(OutputString);
    PrintLine(TEXT("Press Enter to get started."));
}

bool UBullCowCartridge::CheckUserInput(const FString &UserInput) const
{

    if (UserInput == HiddenWord)
        return true;
    else if (!UserInput.IsEmpty())
    {
        int32 UserInputLength{UserInput.Len()};
        int32 CorrectGuesses{};
        int j{};
        if (UserInputLength == HiddenWordLength)
        {
            for (int i{}; i < HiddenWordLength; ++i)
            {
                if (HiddenWord[i] == UserInput[i])
                    CorrectGuesses++;
            }
        }
        else if (UserInputLength < HiddenWordLength)
        {

            for (int i{}; i < HiddenWordLength; ++i, ++j)
            {
                if (j < UserInputLength && HiddenWord[i] == UserInput[j])
                    CorrectGuesses++;
            }
        }
        else
        {
            for (int i{}; i < UserInputLength; ++i, ++j)
            {
                if (j < UserInputLength && HiddenWord[j] == UserInput[i])
                    CorrectGuesses++;
            }
        }
        PrintLine("Wrong guess !");
        PrintLine(FString::Printf(TEXT("You had %i letters at correct places"), CorrectGuesses));
    }
    return false;
}
