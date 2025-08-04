// Fill out your copyright notice in the Description page of Project Settings.

#include "BullCowCartridge.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "RandomGenerator.h"

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
            PrintLine(FString::Printf(TEXT("You have %i lives left."), Lives));
            Lives--;
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
    PrintLine(TEXT("Welcome to BullCow game"));
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

    SetHiddenWord(StringHiddenWordBook[GetNum]);
    SetHiddenWordLength();
    SetLives(HiddenWordLength*2);
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
    PrintLine(TEXT("Guess the %i letter word."), HiddenWordLength);
    PrintLine(TEXT("Press Enter to get started."));
}

bool UBullCowCartridge::CheckUserInput(const FString &UserInput) const
{

    if (UserInput == HiddenWord)
        return true;
    else if (!UserInput.IsEmpty())
    {
        int32 Bulls{};
        int32 Cows{};
        int32 InputSize{UserInput.Len()};
        auto CompareFunction = [&](int32 LoopLimit, int32 &SmallerSize) mutable {
            int32 index{};
            for (int32 i{}; i < LoopLimit; ++i)
            {
                if (i >= SmallerSize)
                    break;
                if (UserInput[i] == HiddenWord[i])
                {
                    Bulls++;
                }
                else if (HiddenWord.FindChar(UserInput[i], index))
                {
                    Cows++;
                }
            }
        };
        if (HiddenWordLength >= InputSize)
            CompareFunction(HiddenWordLength, InputSize);
        else if (HiddenWordLength < InputSize)
            CompareFunction(InputSize, static_cast<int32>(HiddenWordLength));
        PrintLine(TEXT("You got %i Bulls and %i Cows !"), Bulls, Cows);
    }
    return false;
}
