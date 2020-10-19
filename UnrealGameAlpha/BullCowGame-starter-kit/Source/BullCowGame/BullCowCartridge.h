// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Console/Cartridge.h"
#include "BullCowCartridge.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BULLCOWGAME_API UBullCowCartridge : public UCartridge
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void OnInput(const FString &Input) override;

	void Greet();
	void CreateHiddenWordBook();
	void GameStateManager();
	void InitialiseGameVars();
	void SetHiddenWord(const FString &TempHIddenWord);
	void SetHiddenWordLength();
	void SetLives(const int32 &NewLifeVal);
	void Question() const;
	bool CheckUserInput(const FString &UserInput) const;
	// Your declarations go below!
private:
	bool bGameOver{};
	TSet<FString> HiddenWordBook{};
	int32 HiddenWordBookLength{}; 
	TArray<FString> StringHiddenWordBook{};
	FString HiddenWord{};
	int32 HiddenWordLength{};
	int32 Lives{};


};
