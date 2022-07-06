#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Common.h"

using namespace std;

class Product {
private:
	int productid, stockquantity, isFragile;
	string productname;
	double productprice;

public:
	Product(int productid, string productname, double productprice, int stockquantity, int isFragile) {
		this->productid = productid;
		this->productname = toLower(productname);
		this->productprice = productprice;
		this->stockquantity = stockquantity;
        this->isFragile = isFragile;
	}

    Product(int productid) {
        this->productid = productid;
        this->productname = "";
    }

    Product(string productname) {
        this->productid = 0;
        this->productname = productname;
    }

    Product() {
        this->productid = 0;
        this->productname = "";
        this->productprice = 0;
        this->stockquantity = 0;
        this->isFragile = 0;
    }

    bool createProduct() {
        ifstream infile("Product.txt");
        ofstream file("Product.txt", ios::app);

        if (infile.is_open()) {
            file << "\n" + to_string(this->productid) + ";" + this->productname + ";" + to_string(ceil(this->productprice*100)/100) + ";" + to_string(this->stockquantity) + ";" + to_string(this->isFragile);
        }

        infile.close();
        file.close();

        return true;
    }

    bool deleteProduct() {

        ifstream file("Product.txt");
        ifstream fileO("Product.txt");
        ofstream fileNew("producttemp.txt");

        string
            pid, pname, pprice, pstock, pisfragile, toDelete, line;

        while (file && !file.eof()) {
            getline(file, pid, ';');
            getline(file, pname, ';');
            getline(file, pprice, ';');
            getline(file, pstock, ';');
            getline(file, pisfragile);

            pid = removeNewLine(pid);

            if (pid == to_string(this->productid)) {
                toDelete = "\n" + pid + ";" + pname + ";" + pprice + ";" + pstock + ";" + pisfragile;
                file.close();
                break;
            }
        }
        file.close();

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
        remove("Product.txt");

        if (rename("producttemp.txt", "Product.txt") == 0) {
            return true;
        }
        else {
            return false;
        };
    }

    string viewProduct() {
        ifstream file("Product.txt");
        string
            pid, pname, pprice, pstock, pisfragile, result;

        result += "--------------------------------------------------------------------------\n";
        result += "Product Id | Name | Price Per Unit | In Stock | Fragile (1 - No / 2 - Yes)\n";
        result += "--------------------------------------------------------------------------";

        while (file && !file.eof()) {
            getline(file, pid, ';');
            getline(file, pname, ';');
            getline(file, pprice, ';');
            getline(file, pstock, ';');
            getline(file, pisfragile);

            result += "\n" + pid + " | " + pname + " | " + pprice + " | " + pstock + " | " + pisfragile;
        }
        result += "\n--------------------------------------------------------------------------\n";
        file.close();

        return result;
    }

    string searchProduct() {
        
        ifstream file("Product.txt");
        string
            pid, pname, pprice, pstock, pisfragile, result;

        while (file && !file.eof()) {
            getline(file, pid, ';');
            getline(file, pname, ';');
            getline(file, pprice, ';');
            getline(file, pstock, ';');
            getline(file, pisfragile);

            if (pname == this->productname) {
                result += "\n" + pid + " | " + pname + " | " + pprice + " | " + pstock + " | " + pisfragile + "\n";
                file.close();
                break;
            }
        }
        file.close();

        return result;
    }

    bool editProduct(double newproductprice, int newstockquantity, int newisfragile) {
        ifstream file("Product.txt");
        ifstream fileO("Product.txt");
        ofstream fileNew("producttemp.txt");

        string
            pid, pname, pprice, pstock, pisfragile
            , updatePrice, updateQuantity, updateIsFragile
            , toUpdate, toDelete, line;

        while (file && !file.eof()) {

            getline(file, pid, ';');
            getline(file, pname, ';');
            getline(file, pprice, ';');
            getline(file, pstock, ';');
            getline(file, pisfragile);

            if (pname == this->productname) {

                pid = removeNewLine(pid);
                toDelete = "\n" + pid + ";" + pname + ";" + pprice + ";" + pstock + ";" + pisfragile;

                if (newproductprice != 0) { updatePrice = to_string(newproductprice); }
                else { updatePrice = pprice; };
                if (newstockquantity != 0) { updateQuantity = to_string(newstockquantity); }
                else { updateQuantity = pstock; };
                if (newisfragile != 0) { updateIsFragile = to_string(newisfragile); }
                else { updateIsFragile = pisfragile; };

                toUpdate = "\n" + pid + ";" + pname + ";" + updatePrice + ";" + updateQuantity + ";" + updateIsFragile;
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
        remove("Product.txt");
        if (rename("producttemp.txt", "Product.txt") == 0) {
            return true;
        }
        else {
            return false;
        };
    }

    bool isProductExists() {
        ifstream file("Product.txt");
        string
            pid, pname, pprice, pstock, pisfragile;

        while (file && !file.eof()) {
            getline(file, pid, ';');
            getline(file, pname, ';');
            getline(file, pprice, ';');
            getline(file, pstock, ';');
            getline(file, pisfragile);

            if (removeNewLine(pid) == to_string(this->productid) || pname == this->productname) {
                file.close();
                return true;
            }
        }
        file.close();
        return false;
    }

};

class Order {
private:
    int orderid, numberofitem;
    string customerid;
public:

    Order(){
        this->orderid = 0;
        this->customerid = "";
        this->numberofitem = 0;
    }

    Order(int orderid) {
        this->orderid = orderid;
        this->customerid = "";
        this->numberofitem = 0;
    }

    Order(int orderid, string customerid, int numberofitem) {
        this->orderid = orderid;
        this->customerid = customerid;
        this->numberofitem = numberofitem;
    }

    bool createOrder() {
        ifstream infile("Order.txt");
        ofstream file("Order.txt", ios::app);

        if (infile.is_open()) {
            file << "\n" + to_string(this->orderid) + ";" + this->customerid + ";" + to_string(this->numberofitem);
        }

        infile.close();
        file.close();

        return true;
    }

    string viewOrder() {
        ifstream file("Order.txt");
        string
            oid, cid, noofitem,result;

        result += "---------------------------------------\n";
        result += "Order Id | Customer Id | Number of Item\n";
        result += "---------------------------------------";

        while (file && !file.eof()) {
            getline(file, oid, ';');
            getline(file, cid, ';');
            getline(file, noofitem);

            result += "\n" + oid + " | " + cid + " | " + noofitem;
        }
        result += "\n---------------------------------------\n";
        file.close();

        return result;
    }

    bool deleteOrder() {

        ifstream file("Order.txt");
        ifstream fileO("Order.txt");
        ofstream fileNew("ordertemp.txt");

        string
            oid, cid, noofitem, toDelete, line;

        while (file && !file.eof()) {
            getline(file, oid, ';');
            getline(file, cid, ';');
            getline(file, noofitem);

            oid = removeNewLine(oid);

            if (oid == to_string(this->orderid)) {
                toDelete = "\n" + oid + ";" + cid + ";" + noofitem ;
                file.close();
                break;
            }
        }
        file.close();

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
        remove("Order.txt");

        if (rename("ordertemp.txt", "Order.txt") == 0) {
            return true;
        }
        else {
            return false;
        };
    }

    string searchOrder() {

        ifstream file("Order.txt");
        string
            oid, cid, noofitem, result;

        while (file && !file.eof()) {
            getline(file, oid, ';');
            getline(file, cid, ';');
            getline(file, noofitem);

            if (removeNewLine(oid) == to_string(this->orderid)) {
                result += "\n" + oid + " | " + cid + " | " + noofitem + "\n";
                file.close();
                break;
            }
        }
        file.close();

        return result;
    }

    bool isOrderExists() {
        ifstream file("Order.txt");
        string
            oid, cid, itemno;

        while (file && !file.eof()) {
            getline(file, oid, ';');
            getline(file, cid, ';');
            getline(file, itemno);

            if (removeNewLine(oid) == to_string(this->orderid)) {
                file.close();
                return true;
            }
        }
        file.close();
        return false;
    }
};

class OrderItem : private Order{
};

class Cart {};