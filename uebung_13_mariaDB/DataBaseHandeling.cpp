//	author: Torben LYczkowski
//	date:	09.05.2022
// No rights claimed

#include"Header.h"



MYSQL* conn;	//pointer to connection handler
MYSQL_RES* res; /* holds the result set */
MYSQL_ROW row;	//holds the row as an array where each collum is a position


void db_response::connectionFunction() {
	conn = mysql_init(0);
	/*if (conn) {
		cout << "Database Connected!" << endl;
	}
	else {
		cout << "Failed to connect!" << endl;
		cout << "Start DB! Than restart the Programm!" << endl;
		exit(0);
	}*/
	conn = mysql_real_connect(conn, "localhost", "root", "", "personaldaten_bingen", 3306, NULL, 0);
	if (conn) {
		cout << "Database Connected to MYSQL psersonaldaten_bingen" << "\n\n"; //<< conn
	}
	else {
		cout << "Failed to connect!" << endl;
		cout << "Start DB! Than restart the Programm!" << endl;
		exit(0);
	}
}
int db_manageRows::countDataRows() {
	//this funtion is part of db_managerows and is private to count the rows of data
	mysql_query(conn, "SELECT COUNT(*) FROM personaldaten");

	res = mysql_store_result(conn);

	MYSQL_ROW testCount = mysql_fetch_row(res);

	cout << "You have " << testCount[0] << " Rows of Data!\n\n";
	//gives back the number of row that are in the tabel, not counting the IDs
	char* toChange;	//char pointer to the id of the catched row
	toChange = testCount[0];	//assigining the pointer
	int returnValue = (int)*toChange - 48;	//typecasting the char to teh to returnd value -48 cause of ACI2
	return returnValue;
}
void db_manageRows::readRow(string rowNumber) {

	
	//sql query to read a specific line form table need adjustment for missing IDs, otherwise program error
	string selectRow = "SELECT * FROM personaldaten WHERE ID = " + rowNumber;
	mysql_query(conn, selectRow.c_str());//string.c_str forces type casting

	res = mysql_store_result(conn);

	MYSQL_ROW readRow = mysql_fetch_row(res);

	if (readRow == NULL) {
		cout << "Please enter a Value between 0 and "<< countDataRows();

	}
	else {
		int forLimit = res->field_count; //limit is the count of collums
		//tabel collums are like places in an array
		for (int y = 1; y < forLimit; y++) {
			cout << readRow[y];
			if (y < forLimit - 1 && y != 0) {
				cout << " ,";
			}
		}
	}


}
void db_manageRows::readAll() {

	int allRows = countDataRows();
	cout << allRows << "\n\n";
	string selectRow;
	for (int y = 1; y <= allRows; y++) {
		selectRow = std::to_string(y);//typecast for-loop counter to string to put it in the SQL-Query using std::to_string for the string.lib
		selectRow = "SELECT * FROM personaldaten WHERE ID = " + selectRow;
		mysql_query(conn, selectRow.c_str());//string.c_str forces type casting

		res = mysql_store_result(conn);

		MYSQL_ROW readRowAll = mysql_fetch_row(res);

		int forLimit = res->field_count;
		//tabel collums are like places in an array
		for (int y = 1; y < forLimit; y++) {
			cout << readRowAll[y];
			if (y < forLimit - 1 && y != 0) {
				cout << " ,";
			}
			else {
				cout << "\n";
			}
		}
	}
}


//------------------
//insert class
void db_manageRows::insertToDB() {
	//string test = "INSERT INTO personaldaten (Vorname, Nachname, Geschlecht, Ort, Strasse, Hausnummer) VALUES('Klaus', 'Müller', 'M', 'Daheim', 'MeineStr', '3')";
	//construct dynamic query string to be put in ti DB
	string test = "INSERT INTO personaldaten (Vorname, Nachname, Geschlecht, Ort, Strasse, Hausnummer) VALUES ('";
	cout << " Input your Data!\n Firstname: ";
	test += input();
	test += "', '";
	cout << " Lastname: ";
	test += input();
	test += "', '";
	cout << " Gender: ";
	test += input();
	test += "', '";
	cout << " Place of Living: ";
	test += input();
	test += "', '";
	cout << " Street: ";
	test += input();
	test += "', '";
	cout << " Unitnumber: ";
	test += input();
	test += "')";

	//cout << test; to print the query befor executing it

	int query_state = mysql_query(conn, test.c_str());
}//posting the query to DB

string db_manageRows::input() {
	//is the inputfunction for the constructing of the input string for the DB-table
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