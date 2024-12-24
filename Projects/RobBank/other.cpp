#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

/////////////////////////////
// Bank Rob Text Adventure //
/////////////////////////////

void game(const std::string& PlayerName) {
    std::cout << "Let's Begin The Robbing Adventure, " << PlayerName << "!\n";
    std::string asciiArt = 
        " ___________________________________\n"
        "|#######====================#######|\n"
        "|#(1)*UNITED STATES OF AMERICA*(1)#|\n"
        "|#**          /===\\   ********  **#|\n"
        "|*# {G}      | (\") |             #*|\n"
        "|#*  ******  | /v\\ |    O N E    *#|\n"
        "|#(1)         \\===/            (1)#|\n"
        "|##=========ONE DOLLAR===========##|\n"
        "------------------------------------\n";
    std::cout << asciiArt << '\n';

    std::string YouChoose;
    std::cout << "Choose an option:\n";
    std::cout << "1. Rob The Rich\n";
    std::cout << "2. Rob The Poor\n";
    std::getline(std::cin, YouChoose);

    if (YouChoose == "1") {
        std::string yesOrNo;
        std::cout << "You Robbed The Rich Person\n";

        int lootAmount = 1 + (std::rand() * 200);
        std::cout << PlayerName << " robbed the person and stole $" << lootAmount << "!\n";

        std::cout << "Do you want to kill this person?\n";
        std::cout << "Yes or No (y/n): ";
        std::getline(std::cin, yesOrNo);

        if (yesOrNo == "y") {
            std::cout << "POW POW POW!\n";
            std::cout << "You killed the person! Cops are coming... You run away and make it home without any trouble!\n";
            std::cout << "\033[1;32mGOOD ENDING\033[0m\n";

        } else if (yesOrNo == "n") {
            std::cout << "You left the person behind. Unfortunately, they called the cops and gave away your location.\n";
            std::cout << "You were caught and could not get away. Game over!\n";
            std::cout << "\033[1;31mBAD ENDING\033[0m\n";

        } else {
            std::cout << "Invalid choice. You hesitated, and the person overpowered you. You got caught!\n";
        }

    } else if (YouChoose == "2") {
        std::cout << "You chose to rob the poor. Let's begin!\n";
        int lootAmount = 1 + (std::rand() % 5);
        std::cout << "You robbed a poor person and got $" << lootAmount << ".\n";
        std::cout << "However, you feel terrible about it. Your conscience weighs heavily on you. Game over.\n";
        std::cout << "\033[1;31mBAD ENDING\033[0m\n";

    } else {
        std::cout << "Invalid choice. Please restart the game and choose either 1 or 2.\n";
    }
}

//////////////////
// Main Actions //
//////////////////

int main() {
    std::srand(std::time(0));

    // Create a character Name
    std::string PlayerName;
    std::cout << "What do you want to name your character (12 characters)?: ";
    std::getline(std::cin, PlayerName);
    
    // Check if PlayerName is not empty
    while (PlayerName.empty()) {
        std::cout << "[!] Cannot leave the name blank." << std::endl;
        std::cout << "What do you want to name your character?: ";
        std::getline(std::cin, PlayerName);
    }

    // Check if PlayerName length is within the limit
    if (PlayerName.length() <= 12) {
        game(PlayerName);
    } else {
        std::cout << "Player name is too long. Please restart the program and choose a shorter name.\n";
    }
    
    return 0;
}
