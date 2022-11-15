//
// Created by tseed on 2022-11-14.
//

#ifndef BDOTRADER_COMMANDCONSOLE_H
#define BDOTRADER_COMMANDCONSOLE_H


class CommandConsole {
public:
    CommandConsole();

private:
    static void displayMainMenu();
    static void navigateMainMenu(std::string userInput);
    static int parseInput(std::string userInput);
};


#endif //BDOTRADER_COMMANDCONSOLE_H
