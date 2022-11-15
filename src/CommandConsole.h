//
// Created by tseed on 2022-11-14.
//

#ifndef BDOTRADER_COMMANDCONSOLE_H
#define BDOTRADER_COMMANDCONSOLE_H


#include "NodeTracker.h"

class CommandConsole {
public:
    CommandConsole();

private:
    NodeTracker nodeTracker;

    void displayMainMenu();
    void navigateMainMenu(const std::string& userInput);
    void addNodeMenu();
    static int parseInput(const std::string& userInput);
};


#endif //BDOTRADER_COMMANDCONSOLE_H
