#pragma once
#include <random>
#include "CoreMinimal.h"
class URandomGenerator
{
    std::uniform_int_distribution<int32> IntDist;
    std::default_random_engine DefRandEng;

public:
    URandomGenerator();
    void init(const int32 &limit);
    int32 GenerateRand();
};