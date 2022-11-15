//
// Created by tseed on 2022-11-14.
//

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "CommandConsole.h"

CommandConsole::CommandConsole() { displayMainMenu(); }

void CommandConsole::displayMainMenu() {
    std::cout << "\n" << "Select Commands\n";
    std::cout << "1. Add Node\n";
//    std::cout << "2. View Nodes\n";
//    std::cout << "3. Exit \n";

    std::string userInput;
    std::getline(std::cin, userInput);
    navigateMainMenu(userInput);
}

void CommandConsole::navigateMainMenu(const std::string& userInput){
    int parsedInput = parseInput(userInput);
    std::cout << "Running Command: " << parsedInput << "\n";

    switch (parsedInput) {
        case 0:
            return displayMainMenu();
        case 1:
            CommandConsole::addNodeMenu();
        default:
            std::cerr << "Input out of range!\n" << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
            return displayMainMenu();
    }
}

int CommandConsole::parseInput(const std::string& userInput){
    int parsedInput;
    try { parsedInput = std::stoi(userInput); }
    catch (std::invalid_argument&) {
        std::cerr << "Invalid Input: " << userInput << "\n" << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        return 0;                                               // Return of 0 denotes an error.
    }
    return parsedInput;
}

void CommandConsole::addNodeMenu() {
    std::cout << "\n" << "Trade Node Name: \n";
    std::string name;
    std::getline(std::cin, name);

    confirmation:
    std::cout << "\n" << "Confirm Node Name: " << name << "\n";
    std::cout << "1. Correct\n";
    std::cout << "2. Incorrect\n";

    std::string confirmation;
    std::getline(std::cin, confirmation);
    int parsedConfirm = parseInput(confirmation);

    switch (parsedConfirm){
        case 0:
            goto confirmation;
            case 1:
            {
                try{ nodeTracker.addNewTradeNode(TradeNode(name)); }
                catch (std::invalid_argument&) {
                    std::cerr << "Node " << name << " already exists." << std::flush;
                    std::this_thread::sleep_for(std::chrono::milliseconds(300));
                    break;
                }
                std::cout << "Created new node: " << name << "\n";
                break;
            }
            case 2:
                return CommandConsole::addNodeMenu();
            default:
                std::cerr << "Input out of range!\n" << std::flush;
                std::this_thread::sleep_for(std::chrono::milliseconds(300));
                goto confirmation;
    }
    return displayMainMenu();
}
