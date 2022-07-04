#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include "User.h"
#include "SubMenu.h"

using namespace std;

class ManagerMenu {

private:
    string username;

public:
    //bool isLogout = false;
    bool isExit = false;

    ManagerMenu(string username) {
        this->username = username;
    }

    ~ManagerMenu() {
        this->username = "";
    }

    void returnMenu() {
        int option;
        //bool isExit = false;

        do {
            system("CLS");
            cout << "-ADMIN CONSOLE - ONLINE SHOPPING MANAGEMENT SYSTEM-\n";
            cout << "-User: " + username + "\n";
            cout << "===================================================\n";
            cout << "=                 Manager Menu                    =\n";
            cout << "=                1 - Add Product                  =\n";
            cout << "=                2 - Edit/View/Search Product     =\n";
            cout << "=                3 - Delete Product               =\n";
            cout << "=                4 - Add Order                    =\n";
            cout << "=                5 - Edit/View/Search Order       =\n";
            cout << "=                6 - Delete Order                 =\n";
            cout << "=                0 - Logout                       =\n";
            cout << "===================================================\n";
            cout << "***          Please do not enter space          ***\n";
            cout << "Enter your option: ";
            cin >> option;
            cin.ignore(1);
            cout << "\n";

            while ((option != 1 && option != 2 && option != 3 && option != 0) || !cin) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter valid option.\n";
                cout << "Enter your option: ";
                cin >> option;
                cin.ignore(1);
                cout << "\n";
            };

            switch (option) {
            case 1: {
                AddProductMenu addproductmenu(this->username);
                do {
                    addproductmenu.returnMenu();
                } while (!addproductmenu.isExit);
                break;
            }
            case 2: {
                EditViewSearchProductMenu userdetailsmenu(this->username);
                do {
                    userdetailsmenu.returnMenu();
                } while (!userdetailsmenu.isExit);
                break;
            }
            case 3: {
                DeleteProductMenu delproductmenu(this->username);
                do {
                    delproductmenu.returnMenu();
                } while (!delproductmenu.isExit);
                break;
            }
            case 4: {
                //DeleteUserMenu delusermenu(this->username);
                //do {
                //    delusermenu.returnMenu();
                //} while (!delusermenu.isExit);
                break;
            }
            case 5: {
                //DeleteUserMenu delusermenu(this->username);
                //do {
                //    delusermenu.returnMenu();
                //} while (!delusermenu.isExit);
                break;
            }
            case 6: {
                //DeleteUserMenu delusermenu(this->username);
                //do {
                //    delusermenu.returnMenu();
                //} while (!delusermenu.isExit);
                break;
            }
            case 0: {
                cout << "logout";
                isExit = true;
                break;
            }
            }

        } while (!isExit);
    }
};

class CustomerMenu {

private:
    string username;

public:
    //bool isLogout = false;
    bool isExit = false;

    CustomerMenu(string username) {
        this->username = username;
    }

    ~CustomerMenu() {
        this->username = "";
    }

    void returnMenu() {
        int option;
        //bool isExit = false;

        do {
            system("CLS");
            cout << "-         ONLINE SHOPPING MANAGEMENT SYSTEM       -\n";
            cout << "-User: " + username + "\n";
            cout << "===================================================\n";
            cout << "=                  Customer Menu                  =\n";
            cout << "=                1 - Search Product               =\n";
            cout << "=                2 - Cart                         =\n";
            cout << "=                3 - Bill                         =\n";
            cout << "=                0 - Logout                       =\n";
            cout << "===================================================\n";
            cout << "***          Please do not enter space          ***\n";
            cout << "Enter your option: ";
            cin >> option;
            cin.ignore(1);
            cout << "\n";

            while ((option != 1 && option != 2 && option != 3 && option != 0) || !cin) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter valid option.\n";
                cout << "Enter your option: ";
                cin >> option;
                cin.ignore(1);
                cout << "\n";
            };

            switch (option) {
            case 1: {
                //AddUserMenu addusermenu(this->username);
                //do {
                //    addusermenu.returnMenu();
                //} while (!addusermenu.isExit);
                break;
            }
            case 2: {
                //EditViewSearchUserMenu userdetailsmenu(this->username);
                //do {
                //    userdetailsmenu.returnMenu();
                //} while (!userdetailsmenu.isExit);
                break;
            }
            case 3: {
                //DeleteUserMenu delusermenu(this->username);
                //do {
                //    delusermenu.returnMenu();
                //} while (!delusermenu.isExit);
                break;
            }
            case 4: {
                //DeleteUserMenu delusermenu(this->username);
                //do {
                //    delusermenu.returnMenu();
                //} while (!delusermenu.isExit);
                break;
            }
            case 0: {
                cout << "logout";
                isExit = true;
                break;
            }
            }

        } while (!isExit);
    }
};


class AdminMenu {

private:
    string username;

public:
    bool isExit = false;

    AdminMenu(string username) {
        this->username = username;
    }

    ~AdminMenu() {
        this->username = "";
    }

    void returnMenu() {
        int option;

        do {
            system("CLS");
            cout << "-ADMIN CONSOLE - ONLINE SHOPPING MANAGEMENT SYSTEM-\n";
            cout << "-User: " + username + "\n";
            cout << "===================================================\n";
            cout << "=                 Admin Menu                      =\n";
            cout << "=                1 - Add User                     =\n";
            cout << "=                2 - Edit/View/Search User        =\n";
            cout << "=                3 - Delete User                  =\n";
            cout << "=                0 - Logout                       =\n";
            cout << "===================================================\n";
            cout << "***          Please do not enter space          ***\n";
            cout << "Enter your option: ";
            cin >> option;
            cin.ignore(1);
            cout << "\n";

            while ((option != 1 && option != 2 && option != 3 && option != 0) || !cin) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter valid option.\n";
                cout << "Enter your option: ";
                cin >> option;
                cin.ignore(1);
                cout << "\n";
            };

            switch (option) {
                case 1: {
                    AddUserMenu addusermenu(this->username);
                    do {
                        addusermenu.returnMenu();
                    } 
                    while (!addusermenu.isExit);
                    break;
                }
                case 2: {
                    EditViewSearchUserMenu userdetailsmenu(this->username);
                    do {
                        userdetailsmenu.returnMenu();
                    } while (!userdetailsmenu.isExit);
                    break;
                }
                case 3: {
                    DeleteUserMenu delusermenu(this->username);
                    do {
                        delusermenu.returnMenu();
                    } while (!delusermenu.isExit);
                    break;
                }
                case 0: {
                    cout << "logout";
                    isExit = true;
                    break;
                }
            }

        } while (!isExit);
    }

};

class MainMenu {

private:
    string password;

public:
     int permission = 9;
     string username;
     bool isExit = false;

     void returnMenu(){
        int option;

        do {
            system("CLS");
            cout << "-Welcome to ONLINE SHOPPING MANAGEMENT SYSTEM-\n";
            cout << "==============================================\n";
            cout << "=                    Menu                    =\n";
            cout << "=                  1 - Login                 =\n";
            cout << "=                  0 - Exit                  =\n";
            cout << "==============================================\n";
            cout << "Enter your option: ";
            cin >> option;
            cin.ignore(1);

            while ((option != 1 && option != 0) || !cin){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nPlease enter valid option.\n";
                cout << "Enter your option: ";
                cin >> option;
                cin.ignore(1);
            };

            switch (option) {
                case 1: {
                    User user;
                    int loginOption;

                    cout << "\nUsername:";
                    cin >> username;
                    cout << "Password:";
                    cin >> password;

                    permission = user.Auth(username, password);

                    while (permission == 0) {
                        cout << "\nUser not register or incorrect passowrd.\n";
                        cout << "Please contact admin or login with registered user/correct passowrd.\n";
                        cout << "\n(1 - Relogin, 0 - Return to Menu)\n";
                        cout << "Enter your option: ";
                        cin >> loginOption;

                        if (loginOption == 1) {
                            cout << "\nUsername:";
                            cin >> username;
                            cout << "Password:";
                            cin >> password;
                            permission = user.Auth(username, password);
                        }
                        else if (loginOption == 0) {
                            returnMenu();
                        }
                    };

                    isExit = true;
                    break;
                }
                case 0:
                    cout << "\nExiting system...\n";
                    isExit = true;
                    break;
            }
        }while(!isExit);
     }
};

