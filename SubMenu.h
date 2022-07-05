#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include "User.h"

//Admin Menu
class AddUserMenu {
private:
    string username;

public:
    bool isExit = false;

    AddUserMenu(string username) {
        this->username = username;
    }

    void returnMenu() {
        string createuserid, createname, createuseraddr, createusername, createuserpassword;
        int createuserpermission, createuserrole, createuserhp;
        int option;

        do {
            system("CLS");
            cout << "-ADMIN CONSOLE - ONLINE SHOPPING MANAGEMENT SYSTEM-\n";
            cout << "-User: " + username + "\n";
            cout << "===================================================\n";
            cout << "=                   Add User                      =\n";
            cout << "=                   0 - Back                      =\n";
            cout << "= Permission                         Role         =\n";
            cout << "= 1 - Admin                          1 - Admin    =\n";
            cout << "= 2 - Manager                        2 - Manager  =\n";
            cout << "= 3 - Customer                       3 - Customer =\n";
            cout << "===================================================\n";
            cout << "***           Please do not enter space         ***\n";
            cout << "Username :";
            cin >> createusername;
            cout << "\nPassword :";
            cin >> createuserpassword;
            cout << "\nPermission :";
            cin >> createuserpermission;

            while ((createuserpermission != 1 && createuserpermission != 2 && createuserpermission != 3) || !cin) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nPlease enter valid permission.\n";
                cout << "Permission: ";
                cin >> createuserpermission;
            };

            cout << "\nRole :";
            cin >> createuserrole;

            while ((createuserrole != 1 && createuserrole != 2 && createuserrole != 3) || !cin) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nPlease enter valid role.\n";
                cout << "Role: ";
                cin >> createuserrole;
            };

            cout << "\nIdentification Number :";
            cin >> createuserid;
            cout << "\nFull Name :";
            cin >> createname;
            cout << "\nAddress :";
            cin >> createuseraddr;
            cout << "\nContact Number :";
            cin >> createuserhp;

            while (!cin) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nPlease enter valid phone number.\n";
                cout << "Contact Number: ";
                cin >> createuserhp;
            };

            if (createuserid != "0" && createname != "0" && createuseraddr != "0" && createusername != "0" && createuserpassword != "0" &&
                 createuserpermission != 0 && createuserrole != 0 && createuserhp != 0) {
                // Start creating user
                Admin admin(this->username);

                if (!admin.isUserExists(createusername) && !admin.isUserIdExists(createuserid)) {

                    admin.AddUser(createuserid, createname, createuseraddr, createuserhp, createusername, createuserpassword, createuserpermission, createuserrole);

                    cout << "\nNew user created, enter 0 return to Admin Menu.\n";
                }
                else {
                    cout << "\nUsername already exists or Identification Number duplicated, enter 0 return to Admin Menu.\n";
                }

            }
            else {
                cout << "\nStop user creation, enter 0 return to Admin Menu.\n";
            }

            // Back to Admin Menu
            cin >> option;
            cin.ignore(1);

            while (option != 0 || !cin) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nPlease enter 0 to return to Admin Menu.\n";
                cout << "Enter your option: ";
                cin >> option;
                cin.ignore(1);
            };

            if (option == 0) {
                isExit = true;
            }

        } while (!isExit);
    }
};

class DeleteUserMenu {
private:
    string username;

public:
    bool isExit = false;

    DeleteUserMenu(string username) {
        this->username = username;
    }

    void returnMenu() {
        string createusername;
        int option;

        do {
            system("CLS");
            cout << "-ADMIN CONSOLE - ONLINE SHOPPING MANAGEMENT SYSTEM-\n";
            cout << "-User: " + username + "\n";
            cout << "===================================================\n";
            cout << "=                 Delete User                     =\n";
            cout << "=                   0 - Back                      =\n";
            cout << "===================================================\n";
            cout << "***          Please do not enter space          ***\n";
            cout << "Username :";
            cin >> createusername;

            if (createusername != "0" && this->username != createusername) {
                // Start creating user
                Admin admin(this->username);

                if (admin.isUserExists(createusername) && createusername != "0") {
                    if (admin.DeleteUser(createusername)) {
                        cout << "\nUser deleted, enter 0 return to Admin Menu.\n";
                    };
                }
                else {
                    cout << "\nUser not exists, enter 0 return to Admin Menu.\n";
                }
            }
            else if (this->username == createusername) {
                cout << "\nYou can't delete your own account, please use other admin account to perform this action.\n";
                cout << "\nCancel user deletion, enter 0 return to Admin Menu.\n";
            }
            else {
                cout << "\nCancel user deletion, enter 0 return to Admin Menu.\n";
            }

            // Back to Admin Menu
            cin >> option;
            cin.ignore(1);

            while (option != 0 || !cin) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nPlease enter 0 to return to Admin Menu.\n";
                cout << "Enter your option: ";
                cin >> option;
                cin.ignore(1);
            };

            if (option == 0) {
                isExit = true;
            }

        } while (!isExit);
    }
};

class EditViewSearchUserMenu {
private:
    string username;

public:
    bool isExit = false;

    EditViewSearchUserMenu(string username) {
        this->username = username;
    }

    void returnMenu() {
        string createusername;
        int option;

        do {
            system("CLS");
            cout << "-ADMIN CONSOLE - ONLINE SHOPPING MANAGEMENT SYSTEM-\n";
            cout << "-User: " + username + "\n";
            cout << "===================================================\n";
            cout << "=                  User Details                   =\n";
            cout << "=                   1 - Edit                      =\n";
            cout << "=                   2 - View                      =\n";
            cout << "=                   3 - Search                    =\n";
            cout << "=                   0 - Back                      =\n";
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

            Admin admin(this->username);

            switch (option) {
                case 1: {

                    string editAddr = "0", editPassword = "0";
                    int editHp = 0, editPermission = 0, editRole = 0;

                    admin.ViewUser();
                    cout << "\nPlease enter a user name to edit.\n";
                    cin >> createusername;

                    if (admin.isUserExists(createusername) && createusername != "0") {

                        cout << "\nCurrent record:";
                        admin.SearchUser(createusername);

                        cout << "\n";
                        cout << "\nPlease enter details (enter 0 if unchange): \n";
                        cout << "\nAddress: ";
                        cin >> editAddr;
                        cout << "\nPassword: ";
                        cin >> editPassword;
                        cout << "\nContact: ";
                        cin >> editHp;
                        while (!cin) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "\nPlease enter valid phone number.\n";
                            cout << "Contact: ";
                            cin >> editHp;
                        };
                        cout << "\nPermission: ";
                        cin >> editPermission;
                        while ((editPermission != 1 && editPermission != 2 && editPermission != 3 && editPermission != 0) || !cin) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "\nPlease enter valid phone number.\n";
                            cout << "Contact: ";
                            cin >> editPermission;
                        };
                        cout << "\nRole: ";
                        cin >> editRole;
                        while ((editRole != 1 && editRole != 2 && editRole != 3 && editRole != 0) || !cin) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "\nPlease enter valid phone number.\n";
                            cout << "Contact: ";
                            cin >> editRole;
                        };

                        if (admin.EditUser(createusername, editAddr, editPassword, editHp, editPermission, editRole)) {
                            cout << "\nSuccessfully update user details.";
                            cout << "\n";
                            cout << "\nEdited record:";
                            admin.SearchUser(createusername);
                        }
                        else {
                            cout << "\nFailed to update user details.";
                        };

                        cout << "\n";
                        cout << "\nPlease enter 0 to return to Admin Menu.\n";

                    }
                    else if (createusername == "0") {
                        cout << "\nStop user edit, enter 0 return to Admin Menu.\n";
                    }
                    else {
                        cout << "\nUser not exists, enter 0 return to Admin Menu.\n";
                    }
                    break;

                }
                case 2: {
                    admin.ViewUser();
                    cout << "\nPlease enter 0 to return to Admin Menu.\n";
                    break;
                }
                case 3: {
                    admin.ViewUser();
                    cout << "\nPlease enter a user name to search.\n";
                    cin >> createusername;
                    if (admin.isUserExists(createusername) && createusername != "0") {

                        admin.SearchUser(createusername);
                        cout << "\n";
                        cout << "\nPlease enter 0 to return to Admin Menu.\n";

                    }
                    else if (createusername == "0") {
                        cout << "\nStop user search, enter 0 return to Admin Menu.\n";
                    }
                    else {
                        cout << "\nUser not exists, enter 0 return to Admin Menu.\n";
                    }
                    break;
                }
                case 0: {
                    cout << "\nStop user search, enter 0 return to Admin Menu.\n";
                }
            };

            // Back to Admin Menu
            cin >> option;
            cin.ignore(1);

            while (option != 0 || !cin) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nPlease enter 0 to return to Admin Menu.\n";
                cout << "Enter your option: ";
                cin >> option;
                cin.ignore(1);
            };

            if (option == 0) {
                isExit = true;
            }

        } while (!isExit);
    }
};

//Manager Product Menu
class AddProductMenu {
private:
    string username;

public:
    bool isExit = false;

    AddProductMenu(string username) {
        this->username = username;
    }

    void returnMenu() {
        string productname;
        double productprice;
        int option, productid, stockquantity, isfragile;

        do {
            system("CLS");
            cout << "-ADMIN CONSOLE - ONLINE SHOPPING MANAGEMENT SYSTEM-\n";
            cout << "-User: " + username + "\n";
            cout << "===================================================\n";
            cout << "=                  Add Product                    =\n";
            cout << "=                   0 - Back                      =\n";
            cout << "===================================================\n";
            cout << "***           Please do not enter space         ***\n";
            cout << "***   Insert 0 in Product Id to return to Menu  ***\n";
            cout << "***************************************************\n";
            cout << "Product Id :";
            cin >> productid;

            while (!cin) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nPlease enter valid product id.\n";
                cout << "Product Id : ";
                cin >> productid;
            };

            cout << "Product Name :";
            cin >> productname;

            cout << "Price Per Unit :";
            cin >> productprice;

            while (!cin) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nPlease enter valid product price.\n";
                cout << "Price Per Unit : ";
                cin >> productprice;
            };

            cout << "Quantity :";
            cin >> stockquantity;

            while (!cin) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nPlease enter valid product quantity.\n";
                cout << "Quantity :";
                cin >> stockquantity;
            };

            cout << "Fragile (1 - No, 2 - Yes) :";
            cin >> isfragile;
            cin.ignore(1);

            while ((isfragile != 1 && isfragile != 2) || !cin) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nPlease enter vailid option.\n";
                cout << "Fragile (1 - No, 2 - Yes) :";
                cin >> isfragile;
            };


            if (productname != "0" && productid != 0) {
                // Start creating product
                Manager manager(this->username);
                string signal = manager.AddProduct(productid, productname, productprice, stockquantity, isfragile);

                if (signal == "success") {
                    cout << "\nProduct created, enter 0 return to Manager Menu.\n";
                }
                else if (signal == "fail") {
                    cout << "\nProduct fail to create, enter 0 return to Manager Menu.\n";
                }
                else if (signal == "duplicate") {
                    cout << "\nProduct already exists or Product Id duplicated, enter 0 return to Manager Menu.\n";
                }

            }
            else {
                cout << "\nStop user creation, enter 0 return to Manager Menu.\n";
            }

            // Back to Manager Menu
            cin >> option;
            cin.ignore(1);

            while (option != 0 || !cin) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nPlease enter 0 to return to Manager Menu.\n";
                cout << "Enter your option: ";
                cin >> option;
                cin.ignore(1);
            };

            if (option == 0) {
                isExit = true;
            }

        } while (!isExit);
    }
};

class DeleteProductMenu {
private:
    string username;

public:
    bool isExit = false;

    DeleteProductMenu(string username) {
        this->username = username;
    }

    void returnMenu() {
        int option, productid;

        do {
            system("CLS");
            cout << "-ADMIN CONSOLE - ONLINE SHOPPING MANAGEMENT SYSTEM-\n";
            cout << "-User: " + username + "\n";
            cout << "===================================================\n";
            cout << "=                 Delete Product                  =\n";
            cout << "=                   0 - Back                      =\n";
            cout << "===================================================\n";
            cout << "***          Please do not enter space          ***\n";
            cout << "***   Insert 0 in Product Id to return to Menu  ***\n";
            cout << "***************************************************\n";

            Manager manager(this->username);
            cout << manager.ViewProduct();

            cout << "\nProduct Id :";
            cin >> productid;
            while (!cin) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nPlease enter valid product id.\n";
                cout << "Product Id : ";
                cin >> productid;
            };

            if (productid != 0) {
                // Start delect product
                string signal = manager.DeleteProduct(productid);

                if (signal == "success") {
                    cout << "\nProduct deleted, enter 0 return to Manager Menu.\n";
                }
                else if (signal == "fail") {
                    cout << "\nProduct fail to delete, enter 0 return to Manager Menu.\n";
                }
                else if (signal == "notfound") {
                    cout << "\nProduct not exists in database, enter 0 return to Manager Menu.\n";
                }

            }
            else {
                cout << "\nStop product deletion, enter 0 return to Manager Menu.\n";
            }

            // Back to Admin Menu
            cin >> option;
            cin.ignore(1);

            while (option != 0 || !cin) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nPlease enter 0 to return to Manager Menu.\n";
                cout << "Enter your option: ";
                cin >> option;
                cin.ignore(1);
            };

            if (option == 0) {
                isExit = true;
            }

        } while (!isExit);
    }
};

class EditViewSearchProductMenu {
private:
    string username;

public:
    bool isExit = false;

    EditViewSearchProductMenu(string username) {
        this->username = username;
    }

    void returnMenu() {
        string productname;
        int option;

        do {
            system("CLS");
            cout << "-ADMIN CONSOLE - ONLINE SHOPPING MANAGEMENT SYSTEM-\n";
            cout << "-User: " + username + "\n";
            cout << "===================================================\n";
            cout << "=                 Product Details                 =\n";
            cout << "=                   1 - Edit                      =\n";
            cout << "=                   2 - View                      =\n";
            cout << "=                   3 - Search                    =\n";
            cout << "=                   0 - Back                      =\n";
            cout << "===================================================\n";
            cout << "***          Please do not enter space          ***\n";
            cout << "***************************************************\n";
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

            Manager manager(this->username);

            switch (option) {
                case 1: {

                    double editproductprice;
                    int editstockquantity, editisfragile;

                    cout << manager.ViewProduct();
                    cout << "\nPlease enter a product name to edit.\n";
                    cin >> productname;

                    if (productname != "0") {

                        cout << "\nCurrent record:";
                        cout << manager.SearchProduct(productname);

                        cout << "\n";
                        cout << "\nPlease enter details (enter 0 if unchange): \n";
                        cout << "\nPrice Per Unit: ";
                        cin >> editproductprice;
                        while (!cin) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "\nPlease enter valid product price.\n";
                            cout << "Price Per Unit : ";
                            cin >> editproductprice;
                        };
                        cout << "\nStock Quantity: ";
                        cin >> editstockquantity;
                        while (!cin) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "\nPlease enter valid product quantity.\n";
                            cout << "Quantity :";
                            cin >> editstockquantity;
                        };
                        cout << "\nFragile (1 - No, 2 - Yes, 0 - Unchange): ";
                        cin >> editisfragile;            
                        cin.ignore(1);
                        while ((editisfragile != 1 && editisfragile != 2 && editisfragile !=0) || !cin) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "\nPlease enter vailid option.\n";
                            cout << "Fragile (1 - No, 2 - Yes, 0 - Unchange) :";
                            cin >> editisfragile;
                        };

                        string signal = manager.EditProduct(productname, editproductprice, editstockquantity, editisfragile);

                        if (signal == "success") {
                            cout << "\nEdited record:";
                            cout << manager.SearchProduct(productname);
                            cout << "\nProduct updated, enter 0 return to Manager Menu.\n";
                        }
                        else if (signal == "fail") {
                            cout << "\nProduct fail to update, enter 0 return to Manager Menu.\n";
                        }
                        else if (signal == "notfound") {
                            cout << "\nProduct not exists in database, enter 0 return to Manager Menu.\n";
                        }

                    }
                    else if (productname == "0") {
                        cout << "\nStop product edit, enter 0 return to Manager Menu.\n";
                    }
                    break;

                }
                case 2: {
                    cout << manager.ViewProduct();
                    cout << "\nPlease enter 0 to return to Manager Menu.\n";
                    break;
                }
                case 3: {
                    cout << manager.ViewProduct();
                    cout << "\nPlease enter a product name to search.\n";
                    cin >> productname;

                    if (productname != "0") {
  
                        Manager manager(this->username);
                        cout << manager.SearchProduct(productname);
                        cout << "\nPlease enter 0 to return to Manager Menu.\n";

                    }
                    else {
                        cout << "\nStop product searching, enter 0 return to Manager Menu.\n";
                    }
                    break;
                }
                case 0: {
                    cout << "\nStop product search, enter 0 return to Manager Menu.\n";
                }
            };

            // Back to Admin Menu
            cin >> option;
            cin.ignore(1);

            while (option != 0 || !cin) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nPlease enter 0 to return to Manager Menu.\n";
                cout << "Enter your option: ";
                cin >> option;
                cin.ignore(1);
            };

            if (option == 0) {
                isExit = true;
            }

        } while (!isExit);
    }
};

//Maanger Order Menu
class AddOrderMenu {
private:
    string username;

public:
    bool isExit = false;

    AddOrderMenu(string username) {
        this->username = username;
    }

    void returnMenu() {
        string productname;
        double productprice;
        int option, productid, stockquantity, isfragile;

        do {
            system("CLS");
            cout << "-ADMIN CONSOLE - ONLINE SHOPPING MANAGEMENT SYSTEM-\n";
            cout << "-User: " + username + "\n";
            cout << "===================================================\n";
            cout << "=                   Add Order                     =\n";
            cout << "=                   0 - Back                      =\n";
            cout << "===================================================\n";
            cout << "***           Please do not enter space         ***\n";
            cout << "***   Insert 0 in Product Id to return to Menu  ***\n";
            cout << "***************************************************\n";
            cout << "Product Id :";
            cin >> productid;

            while (!cin) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nPlease enter valid product id.\n";
                cout << "Product Id : ";
                cin >> productid;
            };

            cout << "Product Name :";
            cin >> productname;

            cout << "Price Per Unit :";
            cin >> productprice;

            while (!cin) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nPlease enter valid product price.\n";
                cout << "Price Per Unit : ";
                cin >> productprice;
            };

            cout << "Quantity :";
            cin >> stockquantity;

            while (!cin) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nPlease enter valid product quantity.\n";
                cout << "Quantity :";
                cin >> stockquantity;
            };

            cout << "Fragile (1 - No, 2 - Yes) :";
            cin >> isfragile;
            cin.ignore(1);

            while ((isfragile != 1 && isfragile != 2) || !cin) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nPlease enter vailid option.\n";
                cout << "Fragile (1 - No, 2 - Yes) :";
                cin >> isfragile;
            };


            if (productname != "0" && productid != 0) {
                // Start creating product
                Manager manager(this->username);
                string signal = manager.AddProduct(productid, productname, productprice, stockquantity, isfragile);

                if (signal == "success") {
                    cout << "\nProduct created, enter 0 return to Manager Menu.\n";
                }
                else if (signal == "fail") {
                    cout << "\nProduct fail to create, enter 0 return to Manager Menu.\n";
                }
                else if (signal == "duplicate") {
                    cout << "\nProduct already exists or Product Id duplicated, enter 0 return to Manager Menu.\n";
                }

            }
            else {
                cout << "\nStop user creation, enter 0 return to Manager Menu.\n";
            }

            // Back to Manager Menu
            cin >> option;
            cin.ignore(1);

            while (option != 0 || !cin) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nPlease enter 0 to return to Manager Menu.\n";
                cout << "Enter your option: ";
                cin >> option;
                cin.ignore(1);
            };

            if (option == 0) {
                isExit = true;
            }

        } while (!isExit);
    }
};

class DeleteOrderMenu {};

class EditViewSearchOrderMenu {};

