#include <iostream>

int main(){

    // variables
    int num;
    int num1;
    int results;
    char opt;
    std::string await;

    // user input
    std::cout << "First Number: ";
    std::cin >> num;

    std::cout << "Secoud Number: ";
    std::cin >> num1;

    std::cout << "Choose (+ - * /): ";
    std::cin >> opt;

    // different blocks of code based on the calculator
    switch (opt)
    {

    case '+':
        results = num + num1;
        std::cout << "Results: " << results;
        break;
    case '-':
        results = num - num1;
        std::cout << "Results: " << results;
        break;
    case '*':
        results = num * num1;
        std::cout << "Results: " << results;
        break;
    case '/':
        results = num / num1;
        std::cout << "Results: " << results;
        break;
    
    // if user types wrong opt shows this message
    default:
        std::cout << "Wrong OPT Try Again!\n";
    }

    // Asking user how exit
    std::cout << "\nClick ESC To Close.";
    std::cin.ignore();
    std::cin.get();

    return 0;
}