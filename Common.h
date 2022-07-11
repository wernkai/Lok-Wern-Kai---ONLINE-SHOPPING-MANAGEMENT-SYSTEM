#pragma once
#include <cctype>
#include <string>
#include <regex>

using namespace std;

string toLower(string data) {

	string result = "";

	for (int i = 0; i < data.length(); i++) {
		result += tolower(data[i]);
	};

	return result;
};

string removeNewLine(string data) {
	
	string result = "";
	regex newlines_re("\n+");

	result = regex_replace(data, newlines_re, "");

	return result;
}

int getNewOrderId() {
    ifstream file("Order.txt");
    string
        oid, cid, noofitem;
    int result = 0;

    while (file && !file.eof()) {
        getline(file, oid, ';');
        getline(file, cid, ';');
        getline(file, noofitem);

        if (oid != "") {

            if (result < stoi(removeNewLine(oid))) {
                result = stoi(removeNewLine(oid));
            }

        }
    }

    file.close();

    return result + 1;
}