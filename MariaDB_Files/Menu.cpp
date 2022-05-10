//	author: Torben LYczkowski
//	date:	09.05.2022
// No rights claimed

#include"Header.h"


void Menu::MenuHandeling() {
	cout << "|--------------Welcome!---------------|\n";
	string exitLoop;
	while (exitLoop != "exit" || exitLoop != "Exit") {
		cout << "|-------------------------------------|\n";
		cout << " To Exit the programm write exit !\n";
		cout << "|-------------------------------------|\n";
		cout << " Would you like to input ne data or read?\n";
		cout << "|-------------------------------------|\n";
		cout << " For input type i/I and for reading type r/R\n";
			string userDecision;
			userDecision = input();
			if ((userDecision == "i" || userDecision == "I")) {
				db_response::connectionFunction();
				db_manageRows::insertToDB();
			}
			if ((userDecision == "r" || userDecision == "R")) {
				db_response::connectionFunction();
				cout << "If u want to read all Sets of Data type all or row for reading a specific row: ";
				string allCheck;
				allCheck = input();
				if (allCheck == "all" || allCheck == "All" || allCheck == "ALL") {
					db_manageRows::readAll();
				}
				else {
					//getting a input from input function wich determinites what row u want to read
					db_manageRows::countDataRows();//call funktion over how much rows are in the table
					string rowNumber;
					cout << "\n|-------------------------------------|\n";
					cout << " Wich Row would u like to read?\t";
					rowNumber = input();
					cout << "|-------------------------------------|\n";
					//casting string to integer to check if its possible to give it to the SQL
					if (isInt(rowNumber)) {
						db_manageRows::readRow(rowNumber);
						cout << "\n\n";
					}
					else {
						cout << "Pleas enter a leagal Value between 0 and " << db_manageRows::countDataRows() << endl;
					}
				}
				system("pause");
				system("cls");
		}
	}
};
string Menu::input() {
	//is the inputfunction for the constructing of the input string for the DB-table
	//and checking if the user wants to close the programm
	string inputString;
	cin >> inputString;
	if (inputString == "exit" || inputString == "Exit") {
		cout << "|-------------------------------------|\n";
		cout << " The Program is shutting down!\n";
		cout << "|-------------------------------------|\n";
		exit(0);
		return "exit";
	}
	cout << "|-------------------------------------|\n";
	return inputString;
}
bool Menu::isInt(string number) {
	int size = number.size();
	for (int i = 0; i < size; i++) {
		if (isdigit(number[i])) {
			return true;
		}
		else {
			return false;
		}
	}
}

