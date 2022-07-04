#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Common.h"

using namespace std;

class Product {
private:
	int productid, stockquantity;
	string productname;
	double productprice;

public:
	Product(int productid, string productname, double productprice, int stockquantity) {
		this->productid = productid;
		this->productname = toLower(productname);
		this->productprice = productprice;
		this->stockquantity = stockquantity;
	}

    Product(int productid) {
        this->productid = productid;
        this->productname = "";
    }

    bool createProduct() {
        ifstream infile("Product.txt");
        ofstream file("Product.txt", ios::app);

        if (infile.is_open()) {
            file << "\n" + to_string(this->productid) + ";" + this->productname + ";" + to_string(ceil(this->productprice*100)/100) + ";" + to_string(this->stockquantity);
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
            pid, pname, pprice, pstock, toDelete, line;

        while (file && !file.eof()) {
            getline(file, pid, ';');
            getline(file, pname, ';');
            getline(file, pprice, ';');
            getline(file, pstock);

            pid = removeNewLine(pid);

            if (pid == to_string(this->productid)) {
                toDelete = "\n" + pid + ";" + pname + ";" + pprice + ";" + pstock;
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

    bool isProductExists() {
        ifstream file("Product.txt");
        string
            pid, pname, pprice, pstock;
        regex newlines_re("\n+");

        while (file && !file.eof()) {
            getline(file, pid, ';');
            getline(file, pname, ';');
            getline(file, pprice, ';');
            getline(file, pstock);

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
	class OrderItem{};
};

class Cart {};