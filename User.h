#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Component.h"

using namespace std;

class User {
private:
    string username, password;
public:
    User(){}

    User(const string& username, const string& password) {
        this->username = username;
        this->password = password;
    }

    /*int Auth(const string& username, const string& password) {*/
    int Auth() {
        ifstream file("User.txt");
        string 
            fid, fname, faddr, fhp
            , fusername, fpassword, permission, role;

        while (file && !file.eof()) {
            getline(file, fid, ';');
            getline(file, fname, ';');
            getline(file, faddr, ';');
            getline(file, fhp, ';');
            getline(file, fusername, ';');
            getline(file, fpassword, ';'); 
            getline(file, role, ';');
            getline(file, permission);

            if (fusername == this->username && fpassword == this->password) {
                switch (stoi(role)) {
                case 1:
                    file.close();
                    return 1;
                case 2:
                    file.close();
                    return 2;
                case 3:
                    file.close();
                    return 3;
                }
            }
        }
        file.close();

        return 0;
    }

    void SearchUser(const string& username) {
        ifstream file("User.txt");
        string
            fid, fname, faddr, fhp
            , fusername, fpassword, permission, role;

        while (file && !file.eof()) {
            getline(file, fid, ';');
            getline(file, fname, ';');
            getline(file, faddr, ';');
            getline(file, fhp, ';');
            getline(file, fusername, ';');
            getline(file, fpassword, ';');
            getline(file, role, ';');
            getline(file, permission);

            if (fusername == username) {
                cout << "\n" + fid + " | " + fname + " | " + faddr + " | " + fhp + " | "
                    + fusername + " | " + fpassword + " | " + role + " | " + permission;
                file.close();
                break;
            }
        }
        file.close();
    }

    bool isUserExists(const string& username) {
        ifstream file("User.txt");
        string
            fid, fname, faddr, fhp
            , fusername, fpassword, permission, role;

        while (file && !file.eof()) {
            getline(file, fid, ';');
            getline(file, fname, ';');
            getline(file, faddr, ';');
            getline(file, fhp, ';');
            getline(file, fusername, ';');
            getline(file, fpassword, ';');
            getline(file, role, ';');
            getline(file, permission);

            if (fusername == username) {
                file.close();
                return true;
            }
        }
        file.close();
        return false;
    }

    bool isUserIdExists(const string& userid) {
        ifstream file("User.txt");
        string
            fid, fname, faddr, fhp
            , fusername, fpassword, permission, role;

        while (file && !file.eof()) {
            getline(file, fid, ';');
            getline(file, fname, ';');
            getline(file, faddr, ';');
            getline(file, fhp, ';');
            getline(file, fusername, ';');
            getline(file, fpassword, ';');
            getline(file, role, ';');
            getline(file, permission);

            if (fid == userid) {
                file.close();
                return true;
            }
        }
        file.close();
        return false;
    }

    bool isCustomer(const string userid) {
        ifstream file("User.txt");
        string
            fid, fname, faddr, fhp
            , fusername, fpassword, permission, role;

        while (file && !file.eof()) {
            getline(file, fid, ';');
            getline(file, fname, ';');
            getline(file, faddr, ';');
            getline(file, fhp, ';');
            getline(file, fusername, ';');
            getline(file, fpassword, ';');
            getline(file, role, ';');
            getline(file, permission);

            if (fid == userid && permission == "3") {
                file.close();
                return true;
            }
        }
        file.close();
        return false;
    }

    void viewCustomer() {
        ifstream file("User.txt");
        string
            fid, fname, faddr, fhp
            , fusername, fpassword, permission, role;

        cout << "-----------------------------------------------------------------------\n";
        cout << "=                         Customer Details                            =\n";
        cout << "-----------------------------------------------------------------------\n";
        cout << "Id | Name | Address | Contact | Username | Password | Permission | Role\n";
        cout << "-----------------------------------------------------------------------";

        while (file && !file.eof()) {
            getline(file, fid, ';');
            getline(file, fname, ';');
            getline(file, faddr, ';');
            getline(file, fhp, ';');
            getline(file, fusername, ';');
            getline(file, fpassword, ';');
            getline(file, role, ';');
            getline(file, permission);

            if (role == "3" && permission == "3") {
                cout << "\n" + fid + " | " + fname + " | " + faddr + " | " + fhp + " | "
                    + fusername + " | " + fpassword + " | " + role + " | " + permission;
            }
        }
        cout << "\n-----------------------------------------------------------------------\n";
        file.close();
    }

};

class Admin: public User{
private:
    string username;

public:
    Admin(string username) {
        this->username = username;
    }

    bool AddUser(string createuserid, string createname, string createuseraddr, int createuserhp
        ,string createusername, string createuserpassword, int createuserpermission, int createuserrole) {

        ifstream infile("User.txt");
        ofstream file("User.txt", ios::app);

        if (infile.is_open()) {
            file << "\n" + createuserid + ";" + createname + ";" + createuseraddr + ";" + to_string(createuserhp) + ";"
                + createusername + ";" + createuserpassword + ";" + to_string(createuserpermission) + ";" + to_string(createuserrole);
        }

        infile.close();
        file.close();

        return true;
    }

    bool DeleteUser(string username) {
        ifstream file("User.txt");
        ifstream fileO("User.txt");
        ofstream fileNew("usertemp.txt");

        string
            fid, fname, faddr, fhp
            , fusername, fpassword, permission, role, toDelete, line;

        while (file && !file.eof()) {
            
            getline(file, fid, ';');
            getline(file, fname, ';');
            getline(file, faddr, ';');
            getline(file, fhp, ';');
            getline(file, fusername, ';');
            getline(file, fpassword, ';');
            getline(file, role, ';');
            getline(file, permission);

            if (fusername == username) {

                toDelete = "\n" + fid + ";" + fname + ";" + faddr + ";" + fhp + ";" + fusername + ";" + fpassword + ";" + role + ";" + permission;
                file.close();
                break;
            }
        }

        while (fileO && !fileO.eof()) {
            getline(fileO, line);
            line = "\n" + line;

            if (line == toDelete) {
                line.replace(line.find(toDelete), toDelete.length(), "");
            }

            if (line != "\n") {
                fileNew << line;
            }
        }

        fileO.close();
        fileNew.close();
        remove("User.txt");
        
        if (rename("usertemp.txt", "User.txt") == 0) {
            return true;
        }
        else {
            return false;
        };
    }

    bool EditUser(const string& username, string newAddr, string newPassword, int newHp, int newPermission, int newRole) {
        ifstream file("User.txt");
        ifstream fileO("User.txt");
        ofstream fileNew("usertemp.txt");

        string
            fid, fname, faddr, fhp
            , fusername, fpassword, permission, role
            , updateAddr, updatePassword, updateHp, updatePermission, updateNewRole
            , toUpdate, toDelete, line;

        while (file && !file.eof()) {

            getline(file, fid, ';');
            getline(file, fname, ';');
            getline(file, faddr, ';');
            getline(file, fhp, ';');
            getline(file, fusername, ';');
            getline(file, fpassword, ';');
            getline(file, role, ';');
            getline(file, permission);

            if (fusername == username) {

                toDelete = "\n" + fid + ";" + fname + ";" + faddr + ";" + fhp + ";" + fusername + ";" + fpassword + ";" + role + ";" + permission;

                if (newAddr != "0") { updateAddr = newAddr; } else { updateAddr = faddr; };
                if (newPassword != "0") { updatePassword = newPassword; } else { updatePassword = fpassword; };
                if (newHp != 0) { updateHp = to_string(newHp); } else { updateHp = fhp; };
                if (newPermission != 0) { updatePermission = to_string(newPermission); } else { updatePermission = permission; };
                if (newRole != 0) { updateNewRole = to_string(newRole); } else { updateNewRole = role; };

                toUpdate = "\n" + fid + ";" + fname + ";" + updateAddr + ";" + updateHp + ";" + fusername + ";" + updatePassword + ";" + updateNewRole + ";" + updatePermission;
                file.close();
                break;
            }
        }

        while (fileO && !fileO.eof()) {
            getline(fileO, line);
            line = "\n" + line;

            if (line == toDelete) {
                line.replace(line.find(toDelete), toDelete.length(), toUpdate);
            }

            if (line != "\n") {
                fileNew << line;
            }
        }

        fileO.close();
        fileNew.close();
        remove("User.txt");
        if (rename("usertemp.txt", "User.txt") == 0) {
            return true;
        }
        else {
            return false;
        };
    }

    void ViewUser() {
        ifstream file("User.txt");
        string
            fid, fname, faddr, fhp
            , fusername, fpassword, permission, role;

        cout << "-----------------------------------------------------------------------\n";
        cout << "=       Permission                                 Role               =\n";
        cout << "=       1 - Admin                                  1 - Admin          =\n";
        cout << "=       2 - Manager                                2 - Manager        =\n";
        cout << "=       3 - Customer                               3 - Customer       =\n";
        cout << "-----------------------------------------------------------------------\n";
        cout << "Id | Name | Address | Contact | Username | Password | Permission | Role\n";
        cout << "-----------------------------------------------------------------------";

        while (file && !file.eof()) {
            getline(file, fid, ';');
            getline(file, fname, ';');
            getline(file, faddr, ';');
            getline(file, fhp, ';');
            getline(file, fusername, ';');
            getline(file, fpassword, ';');
            getline(file, role, ';');
            getline(file, permission);

            cout << "\n" + fid + " | " + fname + " | " + faddr + " | " + fhp + " | "
                + fusername + " | " + fpassword + " | " + role + " | " + permission;
        }
        cout << "\n-----------------------------------------------------------------------\n";
        file.close();
    }
};

class Manager : public User {
private:
    string username;

public:
    Manager(string username) {
        this->username = username;
    }

    string AddProduct(int productid, string productname, double productprice, int stockquantity, int isfragile) {

        Product product(productid, productname, productprice, stockquantity, isfragile);
        string signal = "";

        if (!product.isProductExists()) {
            if (product.createProduct()) {
                signal = "success";
            }
            else {
                signal = "fail";
            };
        }
        else {
            signal = "duplicate";
        }
        return signal;
    }

    string DeleteProduct(int productid) {
        Product product(productid);
        string signal = "";

        if (product.isProductExists()) {
            if (product.deleteProduct()) {
                signal = "success";
            }
            else {
                signal = "fail";
            };
        }
        else {
            signal = "notfound";
        }
        return signal;
    }

    string EditProduct(string productname, double editproductprice, int editstockquantity, int editisfragile) {

        Product product = Product(productname);
        string signal = "";    

        if (product.isProductExists()) {
            if (product.editProduct(editproductprice, editstockquantity, editisfragile)) {
                signal = "success";
            }
            else {
                signal = "fail";
            };
        }
        else {
            signal = "notfound";
        }
        return signal;
    }

    string ViewProduct() {
        Product product = Product();
        return product.viewProduct();
    }

    string SearchProduct(string productname) {
        Product product = Product(productname);

        if (product.isProductExists()) {
            return product.searchProduct();
        }
        else
            return "\nProduct not exists.\n";
    }

    string AddOrder(int orderid, string customerid, int numberofitem) {
        Order order(orderid, customerid, numberofitem);
        string signal = "";

        if (!order.isOrderExists()) {// && isCustomer(customerid)

            if (isUserIdExists(customerid) && isCustomer(customerid)) {
                if (order.createOrder()) {
                    signal = "success";
                }
                else {
                    signal = "fail";
                };
            }
            else {
                signal = "customer404";
            }
        }
        else {
            signal = "duplicate";
        }
        return signal;
    }

    string DeleteOrder(int orderid) {
        Order order(orderid);
        string signal = "";

        if (order.isOrderExists()) {
            if (order.deleteOrder()) {
                signal = "success";
            }
            else {
                signal = "fail";
            };
        }
        else {
            signal = "notfound";
        }
        return signal;
    }

    void EditOrder() {

    }

    string ViewOrder() {
        Order order = Order();
        return order.viewOrder();
    }

    string SearchOrder(int orderid) {
        Order order = Order(orderid);

        if (order.isOrderExists()) {
            return order.searchOrder();
        }
        else
            return "\nProduct not exists.\n";
    }
};

class Customer : private User {
public:
    Customer() {}

    void SearchProduct() {

    }

    void AddToCart() {

    }

    void DisplayBill() {

    }
};