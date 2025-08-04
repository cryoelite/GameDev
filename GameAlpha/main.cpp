
//Chronolock: A text based puzzle game !!
#include <iostream>
#include <random>
#include <windows.h>
#include <sstream>
#include <string>
#include <chrono>
#include <limits>
#undef max

enum class STATE
{
    CONTINUE,
    STOP,
};
enum class ANSWER
{
    CORRECT,
    WRONG,
};
using namespace std;
void WelcomeText()
{
    cout << "Welcome to Chrono Pocket: A lock picking adventure! \n";
    cout << "Brace! Unending waves of lock puzzles are going to come at you \n";
    cout << "Should you wish to exit and view highscore, simply input any character\n";
}

void DisplayInfo(int& Level, int& MultipleValue, int& SumValue)
{
    cout << "\nYou are currently at level " << Level << endl;
    cout << "Your AI assistant tells you the following information"<< endl;
    cout << "> There are 3 numbers to be inputted in the lock, all are positive non-repetitive integers" << endl;
    cout << "> The sum of these numbers is " << SumValue << endl;
    cout << "> The multiple of these numbers is " << MultipleValue << endl;
}

STATE InputInfo(int& UserFirstNum, int& UserSecondNum, int& UserThirdNum)
{
    stringstream InputStringStream{};
    int* PointerToCurrentVal[3] = { &UserFirstNum, &UserSecondNum, &UserThirdNum };
    string InputString{};
    cout << "\nEnter the 3 numbers below: " << endl;
    getline(cin, InputString);

    InputStringStream.str(InputString);
    int Index{};
    while (std::getline(InputStringStream, InputString, ' '))
    {
        int TempValue{};
        try {
            TempValue = std::stoi(InputString, nullptr, 10);
        }
        catch (...)
        {
            TempValue = -1;
        }
        if (TempValue == -1)
        {
            cout << "\nExiting... \n";
            return STATE::STOP;
        }
        *PointerToCurrentVal[Index] = TempValue;
        Index++;
    }

    return STATE::CONTINUE;
}

void SetDifficultyMultiplier(int& Level, int& DifficultyMultiplier)
{
    DifficultyMultiplier = Level * 100 * Level;
}

void SetRandomValues(int& FirstNum, int& SecondNum, int& ThirdNum, int& DifficultyMultiplier)
{
    default_random_engine DefaultRandomEngine(static_cast<unsigned int>(chrono::system_clock::now().time_since_epoch().count()));
    uniform_int_distribution<int> UniformIntDistribution(1, DifficultyMultiplier);

    FirstNum = UniformIntDistribution(DefaultRandomEngine);
    SecondNum = UniformIntDistribution(DefaultRandomEngine);
    ThirdNum = UniformIntDistribution(DefaultRandomEngine);
}

ANSWER CompareNumbers(int& SumValue, int& MultipleValue, int& UserSumValue, int& UserMultipleValue)
{

    if (SumValue == UserSumValue && MultipleValue == UserMultipleValue)
    {
        cout << "\nCorrect Answer !\nProceeding to the next level...\n";
        return ANSWER::CORRECT;
    }
    else if (SumValue != UserSumValue)
    {
        cout << "Wrong Sum!\nYour sum is: " << UserSumValue << endl;
    }
    else
    {
        cout << "Wrong Multiple!\nYour multiple is: " << UserMultipleValue << endl;
    }
    return ANSWER::WRONG;
}

int main()
{
   
    HANDLE handle{ GetStdHandle(STD_OUTPUT_HANDLE) };

    SetConsoleTextAttribute(handle, 12);
    WelcomeText();

    int Level{ 1 };
    int DifficultyMultiplier{};

    int FirstNum{};
    int SecondNum{};
    int ThirdNum{};
    int MultipleValue{};
    int SumValue{};

    int UserFirstNum{};
    int UserSecondNum{};
    int UserThirdNum{};
    int UserMultipleValue{};
    int UserSumValue{};

    SetConsoleTextAttribute(handle, 15);

    auto CalculateSum = [](int& FirstVal, int& SecondVal, int& ThirdVal, int& SumVal) mutable {
        SumVal = FirstVal + SecondVal + ThirdVal;
    };
    auto CalculateMultiple = [](int& FirstVal, int& SecondVal, int& ThirdVal, int& MultipleVal) mutable {
        MultipleVal = FirstVal * SecondVal * ThirdVal;
    };

    while (true)
    {
        SetDifficultyMultiplier(Level, DifficultyMultiplier);
        SetRandomValues(FirstNum, SecondNum, ThirdNum, DifficultyMultiplier);
        CalculateMultiple(FirstNum, SecondNum, ThirdNum, MultipleValue);
        CalculateSum(FirstNum, SecondNum, ThirdNum, SumValue);
        DisplayInfo(Level, MultipleValue, SumValue);
        STATE InputState = InputInfo(UserFirstNum, UserSecondNum, UserThirdNum);
        if (InputState == STATE::STOP)
            break;

        CalculateMultiple(UserFirstNum, UserSecondNum, UserThirdNum, UserMultipleValue);
        CalculateSum(UserFirstNum, UserSecondNum, UserThirdNum, UserSumValue);

        ANSWER Result{ CompareNumbers(SumValue, MultipleValue, UserSumValue, UserMultipleValue) };

        if (Result == ANSWER::WRONG)
            break;

        Level++;
    }

    [&]() {
        cout << "\nCongratulations!! \nYou were able to solve " << Level - 1;
        cout << " locks." << endl;
    }();
    return 0;
}