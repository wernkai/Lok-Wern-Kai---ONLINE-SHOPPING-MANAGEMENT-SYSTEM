#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include "User.h"
#include "SubMenu.h"

using namespace std;

class ManagerMenu {

private:
    string username;
    bool isExit = false;

public:

    ManagerMenu(string username) {
        this->username = username;
    }

    ~ManagerMenu() {
        this->username = "";
    }

    bool getIsExit() {
        return this->isExit;
    }

    void returnMenu() {
        int option;

        do {
            system("CLS");
            cout << "-ADMIN CONSOLE - ONLINE SHOPPING MANAGEMENT SYSTEM-\n";
            cout << "-User: " + username + "\n";
            cout << "===================================================\n";
            cout << "=                   Manager Menu                  =\n";
            cout << "=                1 - Add Product                  =\n";
            cout << "=                2 - Edit/View/Search Product     =\n";
            cout << "=                3 - Delete Product               =\n";
            cout << "=                4 - Add Order                    =\n";
            cout << "=                5 - View/Search Order            =\n";
            cout << "=                6 - Delete Order                 =\n";
            cout << "=                7 - Add Order Item               =\n";
            cout << "=                8 - Edit/View/Search Order Item  =\n";
            cout << "=                9 - Delete Order Item            =\n";
            cout << "=                0 - Logout                       =\n";
            cout << "===================================================\n";
            cout << "***          Please do not enter space          ***\n";
            cout << "Enter your option: ";
            cin >> option;
            cin.ignore(1);
            cout << "\n";

            while ((option != 1 && option != 2 && option != 3 && option != 4 && option != 5 && option != 6 
                && option != 7 && option != 8 && option != 9 && option != 0) || !cin) {
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
                } while (!addproductmenu.getIsExit());
                break;
            }
            case 2: {
                EditViewSearchProductMenu userdetailsmenu(this->username);
                do {
                    userdetailsmenu.returnMenu();
                } while (!userdetailsmenu.getIsExit());
                break;
            }
            case 3: {
                DeleteProductMenu delproductmenu(this->username);
                do {
                    delproductmenu.returnMenu();
                } while (!delproductmenu.getIsExit());
                break;
            }
            case 4: {
                AddOrderMenu addordermenu(this->username);
                do {
                    addordermenu.returnMenu();
                } while (!addordermenu.getIsExit());
                break;
            }
            case 5: {
                ViewSearchOrderMenu orderdetailsmenu(this->username);
                do {
                    orderdetailsmenu.returnMenu();
                } while (!orderdetailsmenu.getIsExit());
                break;
            }
            case 6: {
                DeleteOrderMenu delordermenu(this->username);
                do {
                    delordermenu.returnMenu();
                } while (!delordermenu.getIsExit());
                break;
            }
            case 7: {
                AddOrderItemMenu addorderitemmenu(this->username);
                do {
                    addorderitemmenu.returnMenu();
                } while (!addorderitemmenu.getIsExit());
                break;
            }
            case 8: {
                EditViewSearchOrderItemMenu orderitemdetailsmenu(this->username);
                do {
                    orderitemdetailsmenu.returnMenu();
                } while (!orderitemdetailsmenu.getIsExit());
                break;
            }
            case 9: {
                DeleteOrderItemMenu delorderitemmenu(this->username);
                do {
                    delorderitemmenu.returnMenu();
                } while (!delorderitemmenu.getIsExit());
                break;
            }
            case 0: {
                cout << "logout";
                this->isExit = true;
                break;
            }
            }

        } while (!this->isExit);
    }
};

class CustomerMenu {

private:
    string username;
    bool isExit = false;

public:

    CustomerMenu(string username) {
        this->username = username;
    }

    ~CustomerMenu() {
        this->username = "";
    }

    bool getIsExit() {
        return this->isExit;
    }

    void returnMenu() {
        int option;

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
                this->isExit = true;
                break;
            }
            }

        } while (!this->isExit);
    }
};

class AdminMenu {

private:
    string username;
    bool isExit = false;

public:

    AdminMenu(string username) {
        this->username = username;
    }

    ~AdminMenu() {
        this->username = "";
    }

    bool getIsExit() {
        return this->isExit;
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
                    while (!addusermenu.getIsExit());
                    break;
                }
                case 2: {
                    EditViewSearchUserMenu userdetailsmenu(this->username);
                    do {
                        userdetailsmenu.returnMenu();
                    } while (!userdetailsmenu.getIsExit());
                    break;
                }
                case 3: {
                    DeleteUserMenu delusermenu(this->username);
                    do {
                        delusermenu.returnMenu();
                    } while (!delusermenu.getIsExit());
                    break;
                }
                case 0: {
                    cout << "logout";
                    this->isExit = true;
                    break;
                }
            }

        } while (!this->isExit);
    }

};

class MainMenu {

private:
    string password;
    bool isExit = false;
    int permission = 9;
    string username;

public:
     bool getIsExit() {
         return this->isExit;
     }

     void setIsExit(bool isexit) {
         this->isExit = isexit;
     }

     int getPermission() {
         return this->permission;
     }

     void setPermission(int permission) {
         this->permission = permission;
     }

     string getUsername() {
         return this->username;
     }

     void setUsername(string username) {
         this->username = username;
     }

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
                cout << "\nEnter your option: ";
                cin >> option;
                cin.ignore(1);
            };

            switch (option) {
                case 1: {
                    int loginOption;

                    cout << "\nUsername:";
                    cin >> username;
                    cout << "Password:";
                    cin >> password;

                    User user(username, password);
                    permission = user.Auth();

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

                            User user(username, password);
                            permission = user.Auth();
                        }
                        else if (loginOption == 0) {
                            returnMenu();
                        }
                    };

                    this->isExit = true;
                    break;
                }
                case 0:
                    cout << "\nExiting system...\n";
                    this->isExit = true;
                    break;
            }
        }while(!this->isExit);
     }
};

