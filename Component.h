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
        result += "=                           Product Details                              =\n";
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

            if (pname == this->productname || removeNewLine(pid) == to_string(this->productid)) {

                pid = removeNewLine(pid);
                toDelete = "\n" + pid + ";" + pname + ";" + pprice + ";" + pstock + ";" + pisfragile;

                if (newproductprice != -1) { updatePrice = to_string(newproductprice); }
                else { updatePrice = pprice; };
                if (newstockquantity != -1) { updateQuantity = to_string(newstockquantity + stoi(pstock)); }
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

    bool isProductFragile(int productid) {
        ifstream file("Product.txt");
        string
            pid, pname, pprice, pstock, pisfragile;

        while (file && !file.eof()) {
            getline(file, pid, ';');
            getline(file, pname, ';');
            getline(file, pprice, ';');
            getline(file, pstock, ';');
            getline(file, pisfragile);

            if (removeNewLine(pid) == to_string(productid) && stoi(pisfragile) == 2) {
                file.close();
                return true;
            }
        }
        file.close();
        return false;
    }

    string getProductName(int productid) {
        ifstream file("Product.txt");
        string
            pid, pname, pprice, pstock, pisfragile, result;

        while (file && !file.eof()) {
            getline(file, pid, ';');
            getline(file, pname, ';');
            getline(file, pprice, ';');
            getline(file, pstock, ';');
            getline(file, pisfragile);

            if (this->productid == stoi(removeNewLine(pid))) {
                return pname;
                file.close();
                break;
            }
        }
        return "Product name not found";
        file.close();
    }

    string getProductPrice(int productid) {
        ifstream file("Product.txt");
        string
            pid, pname, pprice, pstock, pisfragile, result;

        while (file && !file.eof()) {
            getline(file, pid, ';');
            getline(file, pname, ';');
            getline(file, pprice, ';');
            getline(file, pstock, ';');
            getline(file, pisfragile);

            if (this->productid == stoi(removeNewLine(pid))) {
                return pprice;
                file.close();
                break;
            }
        }
        return "Product price not found";
        file.close();
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

    void setOrderId(int orderid) {
        this->orderid = orderid;
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
        result += "=             Order Details           =\n";
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

        ifstream fileItem("OrderItem.txt");
        ofstream fileNewItem("orderitemtemp.txt");

        string
            oiid, pid, quantity, toRemain;

        while (fileItem && !fileItem.eof()) {
            getline(fileItem, oiid, ';');
            getline(fileItem, pid, ';');
            getline(fileItem, quantity);

            oiid = removeNewLine(oiid);

            if (oiid != to_string(this->orderid)) {
                toRemain += "\n" + oiid + ";" + pid + ";" + quantity;
            }else {
                Product product(stoi(pid));
                product.editProduct(-1, stoi(quantity), 0);
            }
        }
        fileItem.close();

        //cout << toRemain;
        fileNewItem << toRemain;

        fileNewItem.close();

        remove("Order.txt");
        remove("OrderItem.txt");

        if (rename("ordertemp.txt", "Order.txt") == 0 && rename("orderitemtemp.txt", "OrderItem.txt") == 0) {
            return true;
        }
        else {
            return false;
        };
    }

    int sumOrder() {

        ifstream fileItem("OrderItem.txt");

        string
            oiid, pid, quantity;

        int sum = 0;

        while (fileItem && !fileItem.eof()) {
            getline(fileItem, oiid, ';');
            getline(fileItem, pid, ';');
            getline(fileItem, quantity);

            oiid = removeNewLine(oiid);

            if (oiid == to_string(this->orderid)) {
                Product product = Product(orderid);
                string x = product.getProductPrice(stoi(pid));
                if (product.getProductPrice(stoi(pid)) != "Product price not found") {
                    sum += stoi(quantity) * stoi(product.getProductPrice(stoi(pid)));
                }
            }

        }
        fileItem.close();

        return sum;
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

    bool updateOrderItemNumber(int newItemNo, int orderid) {
        ifstream file("Order.txt");
        ifstream fileO("Order.txt");
        ofstream fileNew("ordertemp2.txt");

        string
            oid, cid, itemno
            , updateItemNo
            , toUpdate, toDelete, line;

        while (file && !file.eof()) {

            getline(file, oid, ';');
            getline(file, cid, ';');
            getline(file, itemno);

            if (removeNewLine(oid) == to_string(orderid)) {

                oid = removeNewLine(oid);
                toDelete = "\n" + oid + ";" + cid + ";" + itemno;

                updateItemNo = to_string(newItemNo + stoi(itemno));

                toUpdate = "\n" + oid + ";" + cid + ";" + updateItemNo;
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
        remove("Order.txt");
        if (rename("ordertemp2.txt", "Order.txt") == 0) {
            return true;
        }
        else {
            return false;
        };
    }

};

class OrderItem : public Order{
private:
    int orderid, productid, quantity;
public:

    OrderItem() {
        this->orderid = 0;
        this->productid = 0;
        this->quantity = 0;
    }

    OrderItem(int orderid) {
        this->orderid = orderid;
        this->productid = 0;
        this->quantity = 0;
    }

    OrderItem(int orderid, int productid) {
        this->orderid = orderid;
        this->productid = productid;
        this->quantity = 0;
    }

    OrderItem(int orderid, int productid, int quantity) {
        this->orderid = orderid;
        this->productid = productid;
        this->quantity = quantity;
    }

    // Return available stock
    int stockQuantity(int productid) {
        ifstream file("Product.txt");
        string
            pid, pname, pprice, pstock, pisfragile;
        int stockQuantity = 0;

        while (file && !file.eof()) {
            getline(file, pid, ';');
            getline(file, pname, ';');
            getline(file, pprice, ';');
            getline(file, pstock, ';');
            getline(file, pisfragile);

            if (removeNewLine(pid) == to_string(productid)) {
                stockQuantity = stoi(pstock);
                file.close();
            }
        }
        file.close();

        return stockQuantity;
    }

    bool createOrderItem() {
        ifstream infile("OrderItem.txt");
        ofstream file("OrderItem.txt", ios::app);

        if (infile.is_open()) {
            file << "\n" + to_string(this->orderid) + ";" + to_string(this->productid) + ";" + to_string(this->quantity);
        }

        infile.close();
        file.close();

        // Update remaining stock quantity
        Product product(this->productid);
        product.editProduct(-1, -this->quantity, 0);

        updateOrderItemNumber(1,this->orderid);

        return true;
    }

    string viewOrderItem() {
        ifstream file("OrderItem.txt");
        string
            oid, pid, quantity, result;

        result += "--------------------------------\n";
        result += "=      Order Item Details      =\n";
        result += "--------------------------------\n";
        result += "Order Id | Product Id | Quantity\n";
        result += "--------------------------------";

        while (file && !file.eof()) {
            getline(file, oid, ';');
            getline(file, pid, ';');
            getline(file, quantity);

            result += "\n" + oid + " | " + pid + " | " + quantity;
        }
        result += "\n--------------------------------\n";
        file.close();

        return result;
    }

    bool deleteOrderItem() {

        ifstream file("OrderItem.txt");
        ifstream fileO("OrderItem.txt");
        ofstream fileNew("orderitemtemp.txt");

        string
            oid, pid, noofitem, toDelete, line;

        while (file && !file.eof()) {
            getline(file, oid, ';');
            getline(file, pid, ';');
            getline(file, noofitem);

            oid = removeNewLine(oid);

            if (oid == to_string(this->orderid) && pid == to_string(this->productid)) {
                toDelete = "\n" + oid + ";" + pid + ";" + noofitem;
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

        // Update remaining stock quantity
        Product product(this->productid);
        product.editProduct(-1, stoi(noofitem), 0);

        updateOrderItemNumber(-1, this->orderid);

        remove("OrderItem.txt");

        if (rename("orderitemtemp.txt", "OrderItem.txt") == 0) {

            return true;
        }
        else {
            return false;
        };
    }

    string searchOrderItem() {

        ifstream file("OrderItem.txt");
        string
            oid, pid, quantity, result;


        while (file && !file.eof()) {
            getline(file, oid, ';');
            getline(file, pid, ';');
            getline(file, quantity);

            if (removeNewLine(oid) == to_string(this->orderid)) {
                result += "\n" + oid + " | " + pid + " | " + quantity + "\n";
            }
        }
        file.close();

        return result;
    }

    bool editOrderItem(int editquantity) {
        ifstream file("OrderItem.txt");
        ifstream fileO("OrderItem.txt");
        ofstream fileNew("orderitemtemp.txt");

        string
            oid, pid, quantity
            , updateQuantity
            , toUpdate, toDelete, line;

        while (file && !file.eof()) {

            getline(file, oid, ';');
            getline(file, pid, ';');
            getline(file, quantity);

            if (removeNewLine(oid) == to_string(this->orderid) && removeNewLine(pid) == to_string(this->productid)) {

                oid = removeNewLine(oid);
                toDelete = "\n" + oid + ";" + pid + ";" + quantity;

                if (editquantity != 0) { updateQuantity = to_string(editquantity); }
                else { updateQuantity = quantity; };

                // Update remaining stock quantity
                Product product(this->productid);
                product.editProduct(-1, stoi(quantity) - editquantity, 0);

                toUpdate = "\n" + oid + ";" + pid + ";" + updateQuantity;
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
        remove("OrderItem.txt");
        if (rename("orderitemtemp.txt", "OrderItem.txt") == 0) {
            return true;
        }
        else {
            return false;
        };
    }

    bool isValidQuantity() {

        if (this->quantity <= stockQuantity(this->productid)) {
            return true;
        }
        else {
            return false;
        }

    }

    bool isOrderItemExists() {
        ifstream file("OrderItem.txt");
        string
            oid, pid, quantity;

        while (file && !file.eof()) {
            getline(file, oid, ';');
            getline(file, pid, ';');
            getline(file, quantity);

            if (removeNewLine(oid) == to_string(this->orderid) && pid == to_string(this->productid)) {
                file.close();
                return true;
            }
        }
        file.close();
        return false;
    }

    bool isOrderItemExistsBatch() {
        ifstream file("OrderItem.txt");
        string
            oid, pid, quantity;

        while (file && !file.eof()) {
            getline(file, oid, ';');
            getline(file, pid, ';');
            getline(file, quantity);

            if (removeNewLine(oid) == to_string(this->orderid)) {
                file.close();
                return true;
            }
        }
        file.close();
        return false;
    }
};

class Cart {
private:
    string username, userid, productname;
    int productid, quantity, amount, packagefee;
public:

    Cart(string username, string userid) {
        this->userid = userid;
        this->username = username;
    }

    Cart(string username, string userid, int productid, string productname, int quantity, int amount, int packagefee) {
        this->userid = userid;
        this->username = username;
        this->productid = productid;
        this->productname = productname;
        this->quantity = quantity;
        this->amount = amount;
        this->packagefee = packagefee;
    }

    bool addItem() {
        ifstream infile("Cart-"+ this->userid +".txt");
        ofstream file("Cart-" + this->userid + ".txt", ios::app);

        if (infile.is_open()) {
            file << "\n" 
                + userid 
                + ";" + this->username 
                + ";" + to_string(this->productid)
                + ";" + productname
                + ";" + to_string(quantity)
                + ";" + to_string(amount)
                + ";" + to_string(packagefee)
                ;
        }

        infile.close();
        file.close();

        return true;
    }

    string checkOut() {
        int neworderid = getNewOrderId(); 
        string
            cid, username, pid, pname, quantity, amount, packagefee
            , signal;

        ifstream cartFile("Cart-" + this->userid + ".txt");
        Order order(neworderid, cid, 0);

        if (order.createOrder()) {

            while (cartFile && !cartFile.eof()) {
                getline(cartFile, cid, ';');
                getline(cartFile, username, ';');
                getline(cartFile, pid, ';');
                getline(cartFile, pname, ';');
                getline(cartFile, quantity, ';');
                getline(cartFile, amount, ';');
                getline(cartFile, packagefee);

                OrderItem orderitem(neworderid, stoi(pid), stoi(quantity));

                if (orderitem.isValidQuantity()) {
                    if (!orderitem.isOrderItemExists()) {
                        if (orderitem.createOrderItem()) {
                            signal = "success";
                        }
                        else {
                            signal = "fail";
                        }
                    }
                    else {
                        signal = "exist";
                    }
                }
                else {
                    signal = "outofstock";
                }

            }
        }
        else {
            signal = "orderfail";
        }

        cartFile.close();
        return signal;
        
    }

    string viewBill() {
        string
            cid, username, pid, pname, quantity, amount, packagefee
            , result;
        int total = 0, presum = 0;

        ifstream billFile("Bill-" + this->userid + ".txt");

        result += "---------------------------------------------\n";
        result += "=                     Bill                  =\n";
        result += "---------------------------------------------\n";
        result += " Product Name | Quantity | Amount | Packaging\n";
        result += "---------------------------------------------";

        while (billFile && !billFile.eof()) {
            getline(billFile, cid, ';');
            getline(billFile, username, ';');
            getline(billFile, pid, ';');
            getline(billFile, pname, ';');
            getline(billFile, quantity, ';');
            getline(billFile, amount, ';');
            getline(billFile, packagefee);

            result += "\n" + pname + " | " + quantity + " | " + amount + " | " + packagefee;
            //presum = stoi(amount) + stoi(packagefee);
            //total += presum;
        }
        result += "\n---------------------------------------------\n";
        //result += "Total Amount:" + to_string(total) + "\n";
        billFile.close();

        return result;
    }

    bool createBill() {
        string
            cid, username, pid, pname, quantity, amount, packagefee
            , result;
        int total = 0;

        ifstream cartFile("Cart-" + this->userid + ".txt");
        ofstream billFile("Bill-" + this->userid + ".txt");

        while (cartFile && !cartFile.eof()) {
            getline(cartFile, cid, ';');
            getline(cartFile, username, ';');
            getline(cartFile, pid, ';');
            getline(cartFile, pname, ';');
            getline(cartFile, quantity, ';');
            getline(cartFile, amount, ';');
            getline(cartFile, packagefee);

            result += "\n" + pname + " ; " + quantity + " ; " + amount + " ; " + packagefee;
        }

        billFile << result;

        billFile.close();
        cartFile.close();

        return true;
    }

    // Return available stock
    int stockQuantity() {
        ifstream file("Product.txt");
        string
            pid, pname, pprice, pstock, pisfragile;
        int stockQuantity = 0;

        while (file && !file.eof()) {
            getline(file, pid, ';');
            getline(file, pname, ';');
            getline(file, pprice, ';');
            getline(file, pstock, ';');
            getline(file, pisfragile);

            if (removeNewLine(pid) == to_string(this->productid)) {
                stockQuantity = stoi(pstock);
                file.close();
            }
        }
        file.close();

        return stockQuantity;
    }

    bool isItemExists() {
        ifstream file("Cart.txt");
        string
            cid, username, pid, pname, quantity, amount, packagefee;

        while (file && !file.eof()) {
            getline(file, cid, ';');
            getline(file, username, ';');
            getline(file, pid, ';');
            getline(file, pname, ';');
            getline(file, quantity, ';');
            getline(file, amount, ';');
            getline(file, packagefee);

            if (removeNewLine(cid) == this->userid && pid == to_string(this->productid)) {
                file.close();
                return true;
            }
        }
        file.close();
        return false;
    }
};