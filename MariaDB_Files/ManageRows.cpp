#include"Header.h"

void db_manageRows::countDataRows() {
	////Einf�gen
	////string test = "INSERT INTO personaldaten (Vorname, Nachname, Geschlecht, Ort, Strasse, Hausnummer) VALUES ('Klaus', 'M�ller', 'M', 'Daheim', 'MeineStr', 3)";

	////int query_state = mysql_query(conn, test.c_str());

	////get what is in first place* resTest[0]
	//mysql_query(conn, "SELECT Nachname FROM personaldaten"); // f�hrt die SQL aus
	//
	//res = mysql_store_result(conn);	//speichert das ergebnis der SQL

	//MYSQL_ROW resTest = mysql_fetch_row(res);	//zieht sie Row mit dem ergebnis in ein array

	//cout << resTest[0] << endl;

	////z�hlt die Rows in personaldaten

	mysql_query(conn, "SELECT COUNT(*) FROM personaldaten");

	res = mysql_store_result(conn);

	MYSQL_ROW testCount = mysql_fetch_row(res);

	cout << "You have " << testCount[0] << " Rows of Data!\n";

	system("pause");
}