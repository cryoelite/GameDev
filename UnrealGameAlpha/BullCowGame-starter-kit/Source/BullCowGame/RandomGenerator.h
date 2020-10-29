#pragma once
#include "CoreMinimal.h"

class URandomGenerator
{
    int32 RandVal{};

    int32 Limit{};

public:
    URandomGenerator()=default;
    void init(const int32 &InpLim);
    int32 GenerateRand();
};