#include "RandomGenerator.h"
#include<chrono>

void URandomGenerator::init(const int32 &limit)
{
    DefRandEng=std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count());
    IntDist=std::uniform_int_distribution<int>(0,limit);
}

URandomGenerator::URandomGenerator()
{}
int32 URandomGenerator::GenerateRand()
{
    return IntDist(DefRandEng);
}