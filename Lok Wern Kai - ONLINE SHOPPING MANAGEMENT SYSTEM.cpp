// Lok Wern Kai - ONLINE SHOPPING MANAGEMENT SYSTEM.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//----------------------------------------
// Author: Wern Kai
// Created Date: 24-June-2022
// Description: Main
// Version: 1.0
// Modify By: DATE | NAME | DETAILS
//----------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include "Menu.h"
using namespace std;

int main()
{   
    MainMenu screen;

    do {
        screen.returnMenu();

        switch (screen.getPermission()) {
            case 1: {
                AdminMenu adminScreen(screen.getUsername());

                do {
                    adminScreen.returnMenu();
                } while (!adminScreen.getIsExit());

                screen.setPermission(9);
                screen.setIsExit(false);

                break;
            }
            case 2: { //manager
                ManagerMenu managerScreen(screen.getUsername());

                do {
                    managerScreen.returnMenu();
                } while (!managerScreen.getIsExit());

                screen.setPermission(9);
                screen.setIsExit(false);

                break;
            }
            case 3: { //customer
                CustomerMenu customerScreen(screen.getUsername());

                do {
                    customerScreen.returnMenu();
                } while (!customerScreen.getIsExit());

                screen.setPermission(9);
                screen.setIsExit(false);

                break;
            }
            case 0: //invalid
                cout << screen.getUsername() + " is invalid";
                break;
        }
    } while (!screen.getIsExit());
    
}

