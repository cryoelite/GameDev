#include "RandomGenerator.h"

void URandomGenerator::init(const int32 &InpLimit)
{
    Limit=InpLimit;
}

int32 URandomGenerator::GenerateRand()
{
    /* PerlinRand=FMath::PerlinNoise1D(CurrentVal);
    CurrentVal+=0.01f;
    PerlinRand+=1.0;
    float PercentLimit{(PerlinRand*Limit)/2};
    int32 RandVal{static_cast<int>(floor(PercentLimit))}; */
    RandVal=FMath::RandRange(0,Limit);
    return RandVal;
    
}