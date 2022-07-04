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

        switch (screen.permission) {
            case 1: {
                AdminMenu adminScreen(screen.username);

                do {
                    adminScreen.returnMenu();
                } while (!adminScreen.isExit);

                screen.permission = 9;
                screen.isExit = false;

                break;
            }
            case 2: { //manager
                ManagerMenu managerScreen(screen.username);

                do {
                    managerScreen.returnMenu();
                } while (!managerScreen.isExit);

                screen.permission = 9;
                screen.isExit = false;

                break;
            }
            case 3: { //customer
                CustomerMenu customerScreen(screen.username);

                do {
                    customerScreen.returnMenu();
                } while (!customerScreen.isExit);

                screen.permission = 9;
                screen.isExit = false;

                break;
            }
            case 0: //invalid
                cout << screen.username + " is invalid";
                break;
        }
    } while (!screen.isExit);
    
}

