#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    std::cout <<"\n----------------------------------------------------------------------\n";
    std::cout << "To yek Secret Agent hasti va mikhay ghofle Level " << Difficulty;
    std::cout << " secure room ro beshkani!\nCode dorost ro benevis...\n";
}

bool PlayGame(int Difficulty)
{

    PrintIntroduction(Difficulty);

    // Declare 3 number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;


    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print sum and prduct to the terminal
    std::cout << std::endl;
    std::cout << "+ 3ta shomare hast\n";
    std::cout << "+ Jame Code ha mosavi hast ba: " << CodeSum << std::endl;
    std::cout << "+ Zarbe Code ha mosavi hast ba: " << CodeProduct << std::endl;

    // This is what Player guesses
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessC >> GuessB;
    
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // This shows if Player's Anwsers are eqal to correct Anwsers
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "*** Afarin! Edame Bede! ***\n";
        return true;
    }

    else
    {
        std::cout << "*** Bakhti! Dobare, Ye bar Fayede nadare! ***\n";
        return false;
    }
}

int main()
{
    srand(time(NULL)); // creates new random sequence based on time of day
    
    int LevelDifficulty = 1;
    int const MaxDifficulty = 10;

    while (LevelDifficulty <= MaxDifficulty) // Loop game until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //Clears any errors
        std::cin.ignore(); // Ignores the buffers

        if (bLevelComplete)
        {
            // increase the level difficulty
            ++LevelDifficulty;
        }
        
    }
    
    std::cout << "\n ***Afarin to tamame Level haro dorost javab dadi! ***\n";
    return 0;
}