//	author: Torben LYczkowski
//	date:	09.05.2022
// No rights claimed

#pragma once
#include<iostream>
#include<mysql.h>
#include <string>




using std::cout;
using std::endl;
using std::cin;
using std::string;



class Menu {
public:
	static void MenuHandeling();
private:
	static bool isInt(string);
	static string input();
protected:
};

class db_manageRows {
public:
	static void readRow(string);
	static void deleteRow();
	static void readAll();
	static void insertToDB();
	static int countDataRows();
private:
	static string input();
	
};

class db_response {
public:
	static void connectionFunction();
};