#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
 {
    srand(static_cast<unsigned int>(time(0)));
    int secretNumber = rand() % 100 + 1;
    int userGuess;
    std::cout << "Guess the number between 1 and 100: ";
    do{
       std::cin >> userGuess;
        if (userGuess == secretNumber) {
            std::cout << "Congratulations! You guessed the correct number." << std::endl;
        } else if (userGuess < secretNumber) {
            std::cout << "Too low. Try again: ";
        } else {
            std::cout << "Too high. Try again: ";
        }
    }
    while (userGuess != secretNumber);
    return 0;
}
