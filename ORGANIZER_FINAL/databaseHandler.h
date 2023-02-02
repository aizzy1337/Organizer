#pragma once
//biblioteki potrzebne do obs³ugi po³¹czenia z baz¹ danych
#include <iostream>
#include <Windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include "consoleHandler.h"
#include <string>
#include <vector>

struct dataStructNotes {

	std::vector<int> id;
	std::vector <std::string> title;
	std::vector <std::string> text;
	std::vector<int> inMain;

};

struct dataStructBudget {

	std::vector<int> id;
	std::vector<int> income;
	std::vector<int> outcome;
	std::vector <std::string> date_col;

};

struct dataStructTasks {

	std::vector<int> id;
	std::vector <std::string> list;
	std::vector <std::string> task;
	std::vector<int> priority;
	std::vector<int> inMain;

};

struct dataStructCalendar {

	std::vector<int> id;
	std::vector <std::string> date_col;
	std::vector <std::string> hourS_col;
	std::vector <std::string> hourF_col;
	std::vector <std::string> event;
	std::vector<int> notification;

};

class databaseHandler{

protected:

	SQLHANDLE sqlConnectionHandle; //obiekt do obs³ugi po³¹czenia
	SQLHANDLE sqlStatementHandle; //obiekt do obs³ugi zapytan
	SQLHANDLE sqlEnviromentHandle; //obiekt do po³aczenia z SQLSERVER
	SQLWCHAR connectionString[2048]; //string polaczeniowy

	void openConnection() {

		//inicjalizacja obiektow
		sqlConnectionHandle = NULL;
		sqlStatementHandle = NULL;

		//alokacja obiektow
		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlEnviromentHandle)) {
			closeConnection();
		}
		if (SQL_SUCCESS != SQLSetEnvAttr(sqlEnviromentHandle,SQL_ATTR_ODBC_VERSION,(SQLPOINTER)SQL_OV_ODBC3,0)) {
			closeConnection();
		}
		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, sqlEnviromentHandle, &sqlConnectionHandle)) {
			closeConnection();
		}

		//³¹czenie z baz¹ oraz obs³uga b³êdów
		std::cout << "Probuje laczyc sie z baza...\n";
		switch (SQLDriverConnect(
				sqlConnectionHandle,
				NULL,
				(SQLWCHAR*)L"DRIVER={SQL Server};SERVER=localhost, 1434; DATABASE=master;Trusted=true;",
				SQL_NTS,
				connectionString,
				1024,
				NULL,
				SQL_DRIVER_NOPROMPT
				)) {

			case SQL_SUCCESS:
				console.changeColor(2);
				std::cout << "Polaczono z baza!\n";
				console.changeColor(1);
				break;
			case SQL_SUCCESS_WITH_INFO:
				console.changeColor(2);
				std::cout << "Polaczono z baza!\n";
				console.changeColor(1);
				break;
			case SQL_INVALID_HANDLE:
				console.changeColor(4);
				std::cout << "Blad w polaczeniu!\n";
				console.changeColor(1);
				closeConnection();
			case SQL_ERROR:
				console.changeColor(4);
				std::cout << "Blad w polaczeniu!\n";
				console.changeColor(1);
				closeConnection();
			default:
				break;

		}

		//utworzenie bazy jesli nie istnieje
		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, sqlConnectionHandle, &sqlStatementHandle)) {
			closeConnection();
		}

		if (SQL_SUCCESS != SQLExecDirect(sqlStatementHandle, (SQLWCHAR*)L"CREATE DATABASE organizer_db", SQL_NTS)) {
			console.changeColor(4);
			std::cout << "Baza istnieje.\n";
			console.changeColor(1);
		}
		else {

			console.changeColor(2);
			std::cout << "Tworze baze programu...\n";
			console.changeColor(1);

		}

		//wybranie bazy
		if (SQL_SUCCESS != SQLExecDirect(sqlStatementHandle, (SQLWCHAR*)L"USE organizer_db", SQL_NTS)) {
			console.changeColor(2);
			std::cout << "Polaczono z baza.\n";
			console.changeColor(1);
		}
		else {

			console.changeColor(4);
			std::cout << "Blad laczenia z baza!\n";
			console.changeColor(1);
			closeConnection();

		}

	}
	void closeConnection() {
		//zamkniecie polaczenie, zwolnienie handlerow
		SQLFreeHandle(SQL_HANDLE_STMT, sqlStatementHandle);
		SQLDisconnect(sqlConnectionHandle);
		SQLFreeHandle(SQL_HANDLE_STMT, sqlConnectionHandle);
		SQLFreeHandle(SQL_HANDLE_STMT, sqlEnviromentHandle);
	}

};

static databaseHandler database;

class databaseInsertHandler: public databaseHandler {

public:

	//dodawanie danych - modul notaki
	void insertData(std::wstring Title, std::wstring Text, SQLINTEGER InMain) {

		openConnection();

		if (sqlConnectionHandle) {
			//sprawdzenie czy istnieje tablica, utworzenie lub nie
			if (SQL_SUCCESS != SQLExecDirect(sqlStatementHandle,
				(SQLWCHAR*)L"CREATE TABLE notes (id INT NOT NULL PRIMARY KEY IDENTITY, title VARCHAR(MAX) NULL, text VARCHAR(MAX) NULL, inMain INT NULL)",
				SQL_NTS)) {
				console.changeColor(4);
				std::cout << "Tablica notatek istnieje.\n";
				console.changeColor(1);
			}
			else {

				console.changeColor(2);
				std::cout << "Tworze tablice notatek...\n";
				console.changeColor(1);

			}

			//dodanie pozycji
			SQLBindParameter(sqlStatementHandle,
				1,
				SQL_PARAM_INPUT,
				SQL_C_WCHAR,
				SQL_VARCHAR,
				Title.length(),
				0,
				(SQLWCHAR*)Title.c_str(),
				Title.length(),
				NULL);
			SQLBindParameter(sqlStatementHandle,
				2,
				SQL_PARAM_INPUT,
				SQL_C_WCHAR,
				SQL_VARCHAR,
				Text.length(),
				0,
				(SQLWCHAR*)Text.c_str(),
				Text.length(),
				NULL);
			SQLBindParameter(sqlStatementHandle,
				3,
				SQL_PARAM_INPUT,
				SQL_INTEGER,
				SQL_INTEGER,
				1,
				0,
				&InMain,
				1,
				NULL);

			if (SQL_SUCCESS != SQLExecDirect(sqlStatementHandle,
				(SQLWCHAR*)L"INSERT INTO notes(title,text,inMain) VALUES (?,?,?)",
				SQL_NTS)) {
				console.changeColor(4);
				std::cout << "Blad dodawania danych.\n";
				console.changeColor(1);
			}
			else {

				console.changeColor(2);
				std::cout << "Dodaje dane...\n";
				console.changeColor(1);

			}

		}

		closeConnection();

	}

	//dodawanie danych - modul lista zadan
	void insertData(std::wstring List, std::wstring Task, SQLINTEGER Priority, SQLINTEGER InMain) {

		openConnection();

		if (sqlConnectionHandle) {
			//sprawdzenie czy istnieje tablica, utworzenie lub nie
			if (SQL_SUCCESS != SQLExecDirect(sqlStatementHandle,
				(SQLWCHAR*)L"CREATE TABLE tasks (id INT NOT NULL PRIMARY KEY IDENTITY, list VARCHAR(MAX) NULL, task VARCHAR(MAX) NULL, priority INT NULL, inMain INT NULL)",
				SQL_NTS)) {
				console.changeColor(4);
				std::cout << "Tablica listy zadan istnieje.\n";
				console.changeColor(1);
			}
			else {

				console.changeColor(2);
				std::cout << "Tworze listy zadan notatek...\n";
				console.changeColor(1);

			}

			//dodanie pozycji
			SQLBindParameter(sqlStatementHandle,
				1,
				SQL_PARAM_INPUT,
				SQL_C_WCHAR,
				SQL_VARCHAR,
				List.length(),
				0,
				(SQLWCHAR*)List.c_str(),
				List.length(),
				NULL);
			SQLBindParameter(sqlStatementHandle,
				2,
				SQL_PARAM_INPUT,
				SQL_C_WCHAR,
				SQL_VARCHAR,
				Task.length(),
				0,
				(SQLWCHAR*)Task.c_str(),
				Task.length(),
				NULL);
			SQLBindParameter(sqlStatementHandle,
				3,
				SQL_PARAM_INPUT,
				SQL_INTEGER,
				SQL_INTEGER,
				1,
				0,
				&Priority,
				1,
				NULL);
			SQLBindParameter(sqlStatementHandle,
				4,
				SQL_PARAM_INPUT,
				SQL_INTEGER,
				SQL_INTEGER,
				1,
				0,
				&InMain,
				1,
				NULL);

			if (SQL_SUCCESS != SQLExecDirect(sqlStatementHandle,
				(SQLWCHAR*)L"INSERT INTO tasks(list,task,priority,inMain) VALUES (?,?,?,?)",
				SQL_NTS)) {
				console.changeColor(4);
				std::cout << "Blad dodawania danych.\n";
				console.changeColor(1);
			}
			else {

				console.changeColor(2);
				std::cout << "Dodaje dane...\n";
				console.changeColor(1);

			}

		}

		closeConnection();

	}

	//dodawanie danych - modul budzet
	void insertData(std::wstring Date, SQLINTEGER Income, SQLINTEGER Outcome) {

		openConnection();

		if (sqlConnectionHandle) {
			//sprawdzenie czy istnieje tablica, utworzenie lub nie
			if (SQL_SUCCESS != SQLExecDirect(sqlStatementHandle,
				(SQLWCHAR*)L"CREATE TABLE budget (id INT NOT NULL PRIMARY KEY IDENTITY, date_col VARCHAR(MAX) NOT NULL, income INT NULL, outcome INT NULL)",
				SQL_NTS)) {
				console.changeColor(4);
				std::cout << "Tablica budzetu istnieje.\n";
				console.changeColor(1);
			}
			else {

				console.changeColor(2);
				std::cout << "Tworze tablice budzetu...\n";
				console.changeColor(1);

			}

			//dodanie pozycji
			SQLBindParameter(sqlStatementHandle,
				1,
				SQL_PARAM_INPUT,
				SQL_C_WCHAR,
				SQL_VARCHAR,
				Date.length(),
				0,
				(SQLWCHAR*)Date.c_str(),
				Date.length(),
				NULL);
			SQLBindParameter(sqlStatementHandle,
				2,
				SQL_PARAM_INPUT,
				SQL_INTEGER,
				SQL_INTEGER,
				1,
				0,
				&Income,
				1,
				NULL);
			SQLBindParameter(sqlStatementHandle,
				3,
				SQL_PARAM_INPUT,
				SQL_INTEGER,
				SQL_INTEGER,
				1,
				0,
				&Outcome,
				1,
				NULL);

			if (SQL_SUCCESS != SQLExecDirect(sqlStatementHandle,
				(SQLWCHAR*)L"INSERT INTO budget(date_col,income,outcome) VALUES (?,?,?)",
				SQL_NTS)) {
				console.changeColor(4);
				std::cout << "Blad dodawania danych.\n";
				console.changeColor(1);
			}
			else {

				console.changeColor(2);
				std::cout << "Dodaje dane...\n";
				console.changeColor(1);

			}

		}

		closeConnection();

	}

	//dodawanie danych - modul kalendarz
	void insertData(std::wstring Date, std::wstring HourS, std::wstring HourF, std::wstring Event, SQLINTEGER Notification) {

		openConnection();

		if (sqlConnectionHandle) {
			//sprawdzenie czy istnieje tablica, utworzenie lub nie
			if (SQL_SUCCESS != SQLExecDirect(sqlStatementHandle,
				(SQLWCHAR*)L"CREATE TABLE calendar (id INT NOT NULL PRIMARY KEY IDENTITY, date_col VARCHAR(MAX) NULL, hourS_col VARCHAR(MAX) NULL, hourF_col VARCHAR(MAX) NULL, event VARCHAR(MAX) NULL, notification INT NULL)",
				SQL_NTS)) {
				console.changeColor(4);
				std::cout << "Tablica kalendarza istnieje.\n";
				console.changeColor(1);
			}
			else {

				console.changeColor(2);
				std::cout << "Tworze tablice kalendarza...\n";
				console.changeColor(1);

			}

			//dodanie pozycji
			SQLBindParameter(sqlStatementHandle,
				1,
				SQL_PARAM_INPUT,
				SQL_C_WCHAR,
				SQL_VARCHAR,
				Date.length(),
				0,
				(SQLWCHAR*)Date.c_str(),
				Date.length(),
				NULL);
			SQLBindParameter(sqlStatementHandle,
				2,
				SQL_PARAM_INPUT,
				SQL_C_WCHAR,
				SQL_VARCHAR,
				HourS.length(),
				0,
				(SQLWCHAR*)HourS.c_str(),
				HourS.length(),
				NULL);
			SQLBindParameter(sqlStatementHandle,
				3,
				SQL_PARAM_INPUT,
				SQL_C_WCHAR,
				SQL_VARCHAR,
				HourF.length(),
				0,
				(SQLWCHAR*)HourF.c_str(),
				HourF.length(),
				NULL);
			SQLBindParameter(sqlStatementHandle,
				4,
				SQL_PARAM_INPUT,
				SQL_C_WCHAR,
				SQL_VARCHAR,
				Event.length(),
				0,
				(SQLWCHAR*)Event.c_str(),
				Event.length(),
				NULL);
			SQLBindParameter(sqlStatementHandle,
				5,
				SQL_PARAM_INPUT,
				SQL_INTEGER,
				SQL_INTEGER,
				1,
				0,
				&Notification,
				1,
				NULL);

			if (SQL_SUCCESS != SQLExecDirect(sqlStatementHandle,
				(SQLWCHAR*)L"INSERT INTO calendar(date_col,hourS_col,hourF_col,event,notification) VALUES (?,?,?,?,?)",
				SQL_NTS)) {
				console.changeColor(4);
				std::cout << "Blad dodawania danych.\n";
				console.changeColor(1);
			}
			else {

				console.changeColor(2);
				std::cout << "Dodaje dane...\n";
				console.changeColor(1);

			}

		}

		closeConnection();

	}

};

static databaseInsertHandler databaseInsert;

class databaseUpdateHandler : public databaseHandler {

public:

	//modyfikowanie danych - modul notaki
	void updateData(SQLINTEGER ID, std::wstring Title, std::wstring Text, SQLINTEGER InMain) {

		openConnection();

		if (sqlConnectionHandle) {
			//sprawdzenie czy istnieje tablica, utworzenie lub nie
			if (SQL_SUCCESS != SQLExecDirect(sqlStatementHandle,
				(SQLWCHAR*)L"CREATE TABLE notes (id INT NOT NULL PRIMARY KEY IDENTITY, title VARCHAR(MAX) NULL, text VARCHAR(MAX) NULL, inMain INT NULL)",
				SQL_NTS)) {
				console.changeColor(4);
				std::cout << "Tablica notatek istnieje.\n";
				console.changeColor(1);
			}
			else {

				console.changeColor(2);
				std::cout << "Tworze tablice notatek...\n";
				console.changeColor(1);

			}

			//dodanie pozycji
			SQLBindParameter(sqlStatementHandle,
				1,
				SQL_PARAM_INPUT,
				SQL_C_WCHAR,
				SQL_VARCHAR,
				Title.length(),
				0,
				(SQLWCHAR*)Title.c_str(),
				Title.length(),
				NULL);
			SQLBindParameter(sqlStatementHandle,
				2,
				SQL_PARAM_INPUT,
				SQL_C_WCHAR,
				SQL_VARCHAR,
				Text.length(),
				0,
				(SQLWCHAR*)Text.c_str(),
				Text.length(),
				NULL);
			SQLBindParameter(sqlStatementHandle,
				3,
				SQL_PARAM_INPUT,
				SQL_INTEGER,
				SQL_INTEGER,
				1,
				0,
				&InMain,
				1,
				NULL);
			SQLBindParameter(sqlStatementHandle,
				4,
				SQL_PARAM_INPUT,
				SQL_INTEGER,
				SQL_INTEGER,
				10,
				0,
				&ID,
				10,
				NULL);

			if (SQL_SUCCESS != SQLExecDirect(sqlStatementHandle,
				(SQLWCHAR*)L"UPDATE notes SET title = ?, text = ?, inMain = ? WHERE id = ?",
				SQL_NTS)) {
				console.changeColor(4);
				std::cout << "Blad modyfikowania danych.\n";
				console.changeColor(1);
			}
			else {

				console.changeColor(2);
				std::cout << "Modyfikuje dane...\n";
				console.changeColor(1);

			}

		}

		closeConnection();

	}

	//modyfikowanie danych - modul lista zadan
	void updateData(SQLINTEGER ID, std::wstring List, std::wstring Task, SQLINTEGER Priority, SQLINTEGER InMain) {

		openConnection();

		if (sqlConnectionHandle) {
			//sprawdzenie czy istnieje tablica, utworzenie lub nie
			if (SQL_SUCCESS != SQLExecDirect(sqlStatementHandle,
				(SQLWCHAR*)L"CREATE TABLE tasks (id INT NOT NULL PRIMARY KEY IDENTITY, list VARCHAR(MAX) NULL, task VARCHAR(MAX) NULL, priority INT NULL, inMain INT NULL)",
				SQL_NTS)) {
				console.changeColor(4);
				std::cout << "Tablica listy zadan istnieje.\n";
				console.changeColor(1);
			}
			else {

				console.changeColor(2);
				std::cout << "Tworze listy zadan notatek...\n";
				console.changeColor(1);

			}

			//dodanie pozycji
			SQLBindParameter(sqlStatementHandle,
				1,
				SQL_PARAM_INPUT,
				SQL_C_WCHAR,
				SQL_VARCHAR,
				List.length(),
				0,
				(SQLWCHAR*)List.c_str(),
				List.length(),
				NULL);
			SQLBindParameter(sqlStatementHandle,
				2,
				SQL_PARAM_INPUT,
				SQL_C_WCHAR,
				SQL_VARCHAR,
				Task.length(),
				0,
				(SQLWCHAR*)Task.c_str(),
				Task.length(),
				NULL);
			SQLBindParameter(sqlStatementHandle,
				3,
				SQL_PARAM_INPUT,
				SQL_INTEGER,
				SQL_INTEGER,
				1,
				0,
				&Priority,
				1,
				NULL);
			SQLBindParameter(sqlStatementHandle,
				4,
				SQL_PARAM_INPUT,
				SQL_INTEGER,
				SQL_INTEGER,
				1,
				0,
				&InMain,
				1,
				NULL);
			SQLBindParameter(sqlStatementHandle,
				5,
				SQL_PARAM_INPUT,
				SQL_INTEGER,
				SQL_INTEGER,
				1,
				0,
				&ID,
				1,
				NULL);

			if (SQL_SUCCESS != SQLExecDirect(sqlStatementHandle,
				(SQLWCHAR*)L"UPDATE tasks SET list = ?, task = ?, priority = ?, inMain = ? WHERE id = ?",
				SQL_NTS)) {
				console.changeColor(4);
				std::cout << "Blad modyfikowania danych.\n";
				console.changeColor(1);
			}
			else {

				console.changeColor(2);
				std::cout << "Modyfikuje dane...\n";
				console.changeColor(1);

			}

		}

		closeConnection();

	}

	//modyfikowanie danych - modul budzet
	void updateData(SQLINTEGER ID, std::wstring Date, SQLINTEGER Income, SQLINTEGER Outcome) {

		openConnection();

		if (sqlConnectionHandle) {
			//sprawdzenie czy istnieje tablica, utworzenie lub nie
			if (SQL_SUCCESS != SQLExecDirect(sqlStatementHandle,
				(SQLWCHAR*)L"CREATE TABLE budget (id INT NOT NULL PRIMARY KEY IDENTITY, date_col VARCHAR(MAX) NOT NULL, income INT NULL, outcome INT NULL)",
				SQL_NTS)) {
				console.changeColor(4);
				std::cout << "Tablica budzetu istnieje.\n";
				console.changeColor(1);
			}
			else {

				console.changeColor(2);
				std::cout << "Tworze tablice budzetu...\n";
				console.changeColor(1);

			}

			//dodanie pozycji
			SQLBindParameter(sqlStatementHandle,
				1,
				SQL_PARAM_INPUT,
				SQL_C_WCHAR,
				SQL_VARCHAR,
				Date.length(),
				0,
				(SQLWCHAR*)Date.c_str(),
				Date.length(),
				NULL);
			SQLBindParameter(sqlStatementHandle,
				2,
				SQL_PARAM_INPUT,
				SQL_INTEGER,
				SQL_INTEGER,
				1,
				0,
				&Income,
				1,
				NULL);
			SQLBindParameter(sqlStatementHandle,
				3,
				SQL_PARAM_INPUT,
				SQL_INTEGER,
				SQL_INTEGER,
				1,
				0,
				&Outcome,
				1,
				NULL);
			SQLBindParameter(sqlStatementHandle,
				4,
				SQL_PARAM_INPUT,
				SQL_INTEGER,
				SQL_INTEGER,
				1,
				0,
				&ID,
				1,
				NULL);

			if (SQL_SUCCESS != SQLExecDirect(sqlStatementHandle,
				(SQLWCHAR*)L"UPDATE budget SET date_col = ?, income = ?, outcome = ? WHERE id = ?",
				SQL_NTS)) {
				console.changeColor(4);
				std::cout << "Blad modyfikowania danych.\n";
				console.changeColor(1);
			}
			else {

				console.changeColor(2);
				std::cout << "Modyfikuje dane...\n";
				console.changeColor(1);

			}

		}

		closeConnection();

	}

	//modyfikowanie danych - modul kalendarz
	void updateData(SQLINTEGER ID, std::wstring Date, std::wstring HourS, std::wstring HourF, std::wstring Event, SQLINTEGER Notification) {

		openConnection();

		if (sqlConnectionHandle) {
			//sprawdzenie czy istnieje tablica, utworzenie lub nie
			if (SQL_SUCCESS != SQLExecDirect(sqlStatementHandle,
				(SQLWCHAR*)L"CREATE TABLE calendar (id INT NOT NULL PRIMARY KEY IDENTITY, date_col VARCHAR(MAX) NULL, hourS_col VARCHAR(MAX) NULL, hourF_col VARCHAR(MAX) NULL, event VARCHAR(MAX) NULL, notification INT NULL)",
				SQL_NTS)) {
				console.changeColor(4);
				std::cout << "Tablica kalendarza istnieje.\n";
				console.changeColor(1);
			}
			else {

				console.changeColor(2);
				std::cout << "Tworze tablice kalendarza...\n";
				console.changeColor(1);

			}

			//dodanie pozycji
			SQLBindParameter(sqlStatementHandle,
				1,
				SQL_PARAM_INPUT,
				SQL_C_WCHAR,
				SQL_VARCHAR,
				Date.length(),
				0,
				(SQLWCHAR*)Date.c_str(),
				Date.length(),
				NULL);
			SQLBindParameter(sqlStatementHandle,
				2,
				SQL_PARAM_INPUT,
				SQL_C_WCHAR,
				SQL_VARCHAR,
				HourS.length(),
				0,
				(SQLWCHAR*)HourS.c_str(),
				HourS.length(),
				NULL);
			SQLBindParameter(sqlStatementHandle,
				3,
				SQL_PARAM_INPUT,
				SQL_C_WCHAR,
				SQL_VARCHAR,
				HourF.length(),
				0,
				(SQLWCHAR*)HourF.c_str(),
				HourF.length(),
				NULL);
			SQLBindParameter(sqlStatementHandle,
				4,
				SQL_PARAM_INPUT,
				SQL_C_WCHAR,
				SQL_VARCHAR,
				Event.length(),
				0,
				(SQLWCHAR*)Event.c_str(),
				Event.length(),
				NULL);
			SQLBindParameter(sqlStatementHandle,
				5,
				SQL_PARAM_INPUT,
				SQL_INTEGER,
				SQL_INTEGER,
				1,
				0,
				&Notification,
				1,
				NULL);
			SQLBindParameter(sqlStatementHandle,
				6,
				SQL_PARAM_INPUT,
				SQL_INTEGER,
				SQL_INTEGER,
				1,
				0,
				&ID,
				1,
				NULL);

			if (SQL_SUCCESS != SQLExecDirect(sqlStatementHandle,
				(SQLWCHAR*)L"UPDATE calendar SET date_col = ?, hourS_col = ?, hourF_col = ?, event = ?, notification = ? WHERE id = ?",
				SQL_NTS)) {
				console.changeColor(4);
				std::cout << "Blad modyfikowania danych.\n";
				console.changeColor(1);
			}
			else {

				console.changeColor(2);
				std::cout << "Modyfikuje dane...\n";
				console.changeColor(1);

			}

		}

		closeConnection();

	}

};

static databaseUpdateHandler databaseUpdate;

class databaseDeleteHandler : public databaseHandler {

public:

	//usuwanie danych
	void deleteData(SQLINTEGER ID, std::wstring Table) {

		openConnection();

		if (sqlConnectionHandle) {
			//sprawdzenie czy istnieje tablica, utworzenie lub nie
			if (SQL_SUCCESS != SQLExecDirect(sqlStatementHandle,
				(SQLWCHAR*)L"CREATE TABLE notes (id INT NOT NULL PRIMARY KEY IDENTITY, title VARCHAR(MAX) NULL, text VARCHAR(MAX) NULL, inMain INT NULL)",
				SQL_NTS)) {
				console.changeColor(4);
				std::cout << "Tablica notatek istnieje.\n";
				console.changeColor(1);
			}
			else {

				console.changeColor(2);
				std::cout << "Tworze tablice notatek...\n";
				console.changeColor(1);

			}

			//dodanie pozycji
			SQLBindParameter(sqlStatementHandle,
				1,
				SQL_PARAM_INPUT,
				SQL_INTEGER,
				SQL_INTEGER,
				1,
				0,
				&ID,
				1,
				NULL);

			std::wstring query = L"DELETE FROM " + Table + L" WHERE id = ?";

			if (SQL_SUCCESS != SQLExecDirect(sqlStatementHandle,
				(SQLWCHAR*)query.c_str(),
				SQL_NTS)) {
				console.changeColor(4);
				std::cout << "Blad usuwania danych.\n";
				console.changeColor(1);
			}
			else {

				console.changeColor(2);
				std::cout << "Usuwam dane...\n";
				console.changeColor(1);

			}

		}

		closeConnection();

	}

};

static databaseDeleteHandler databaseDelete;

class databaseSelectHandler : public databaseHandler {

public:

	dataStructNotes dataNotes;
	dataStructBudget dataBudget;
	dataStructTasks dataTasks;
	dataStructCalendar dataCalendar;

	//pobieranie danych - modul notaki
	void selectDataNotes() {

		openConnection();

		if (sqlConnectionHandle) {
			//sprawdzenie czy istnieje tablica, utworzenie lub nie
			if (SQL_SUCCESS != SQLExecDirect(sqlStatementHandle,
				(SQLWCHAR*)L"CREATE TABLE notes (id INT NOT NULL PRIMARY KEY IDENTITY, title VARCHAR(MAX) NULL, text VARCHAR(MAX) NULL, inMain INT NULL)",
				SQL_NTS)) {
				console.changeColor(4);
				std::cout << "Tablica notatek istnieje.\n";
				console.changeColor(1);
			}
			else {

				console.changeColor(2);
				std::cout << "Tworze tablice notatek...\n";
				console.changeColor(1);

			}

			//dodanie pozycji

			if (SQL_SUCCESS != SQLExecDirect(sqlStatementHandle,
				(SQLWCHAR*)L"SELECT id, title, text, inMain FROM notes",
				SQL_NTS)) {
				console.changeColor(4);
				std::cout << "Blad pobierania danych.\n";
				console.changeColor(1);
			}
			else {

				console.changeColor(2);
				std::cout << "Pobieram dane...\n";
				console.changeColor(1);

			}

			SQLINTEGER _id, _inMain;
			SQLCHAR _title[1000], _text[1000];

			SQLBindCol(sqlStatementHandle,
				1,
				SQL_INTEGER,
				&_id,
				5,
				NULL);
			SQLBindCol(sqlStatementHandle,
				2,
				SQL_C_CHAR,
				&_title,
				1000,
				NULL);
			SQLBindCol(sqlStatementHandle,
				3,
				SQL_C_CHAR,
				&_text,
				1000,
				NULL);
			SQLBindCol(sqlStatementHandle,
				4,
				SQL_INTEGER,
				&_inMain,
				1,
				NULL);

			dataNotes.id.clear();
			dataNotes.title.clear();
			dataNotes.text.clear();
			dataNotes.inMain.clear();

			bool flag = 1;
			while (flag) {

				switch (SQLFetch(sqlStatementHandle))
				{
				case SQL_SUCCESS:
				case SQL_SUCCESS_WITH_INFO:
					dataNotes.id.push_back(_id);
					dataNotes.title.push_back((const char*)_title);
					dataNotes.text.push_back((const char*)_text);
					dataNotes.inMain.push_back(_inMain);
					break;
				default:
					flag = 0;
					break;
				}

			}

		}

		closeConnection();

	}

	//pobieranie danych - modul bud¿et
	void selectDataBudget() {

		openConnection();

		if (sqlConnectionHandle) {
			//sprawdzenie czy istnieje tablica, utworzenie lub nie
			if (SQL_SUCCESS != SQLExecDirect(sqlStatementHandle,
				(SQLWCHAR*)L"CREATE TABLE budget (id INT NOT NULL PRIMARY KEY IDENTITY, date_col VARCHAR(MAX) NOT NULL, income INT NULL, outcome INT NULL)",
				SQL_NTS)) {
				console.changeColor(4);
				std::cout << "Tablica budzetu istnieje.\n";
				console.changeColor(1);
			}
			else {

				console.changeColor(2);
				std::cout << "Tworze tablice budzetu...\n";
				console.changeColor(1);

			}

			//dodanie pozycji
			if (SQL_SUCCESS != SQLExecDirect(sqlStatementHandle,
				(SQLWCHAR*)L"SELECT id, income, outcome, date_col FROM budget",
				SQL_NTS)) {
				console.changeColor(4);
				std::cout << "Blad pobierania danych.\n";
				console.changeColor(1);
			}
			else {

				console.changeColor(2);
				std::cout << "Pobieram dane...\n";
				console.changeColor(1);

			}

			SQLINTEGER _id, _income, _outcome;
			SQLCHAR _date_col[6];

			SQLBindCol(sqlStatementHandle,
				1,
				SQL_INTEGER,
				&_id,
				5,
				NULL);
			SQLBindCol(sqlStatementHandle,
				2,
				SQL_INTEGER,
				&_income,
				7,
				NULL);
			SQLBindCol(sqlStatementHandle,
				3,
				SQL_INTEGER,
				&_outcome,
				7,
				NULL);
			SQLBindCol(sqlStatementHandle,
				4,
				SQL_C_CHAR,
				&_date_col,
				7,
				NULL);

			dataBudget.id.clear();
			dataBudget.income.clear();
			dataBudget.outcome.clear();
			dataBudget.date_col.clear();

			bool flag = 1;
			while (flag) {

				switch (SQLFetch(sqlStatementHandle))
				{
				case SQL_SUCCESS:
				case SQL_SUCCESS_WITH_INFO:
					dataBudget.id.push_back(_id);
					dataBudget.income.push_back(_income);
					dataBudget.outcome.push_back(_outcome);
					dataBudget.date_col.push_back((const char*)_date_col);
					break;
				default:
					flag = 0;
					break;
				}

			}

		}

		closeConnection();

	}

	//pobieranie danych - modul lista zadañ
	void selectDataTasks() {

		openConnection();

		if (sqlConnectionHandle) {
			//sprawdzenie czy istnieje tablica, utworzenie lub nie
			if (SQL_SUCCESS != SQLExecDirect(sqlStatementHandle,
				(SQLWCHAR*)L"CREATE TABLE tasks (id INT NOT NULL PRIMARY KEY IDENTITY, list VARCHAR(MAX) NULL, task VARCHAR(MAX) NULL, priority INT NULL, inMain INT NULL)",
				SQL_NTS)) {
				console.changeColor(4);
				std::cout << "Tablica listy zadan istnieje.\n";
				console.changeColor(1);
			}
			else {

				console.changeColor(2);
				std::cout << "Tworze listy zadan notatek...\n";
				console.changeColor(1);

			}

			//dodanie pozycji
			if (SQL_SUCCESS != SQLExecDirect(sqlStatementHandle,
				(SQLWCHAR*)L"SELECT id, list, task, priority, inMain FROM tasks",
				SQL_NTS)) {
				console.changeColor(4);
				std::cout << "Blad pobierania danych.\n";
				console.changeColor(1);
			}
			else {

				console.changeColor(2);
				std::cout << "Pobieram dane...\n";
				console.changeColor(1);

			}

			SQLINTEGER _id, _inMain, _priority;
			SQLCHAR _list[1000], _task[1000];

			SQLBindCol(sqlStatementHandle,
				1,
				SQL_INTEGER,
				&_id,
				5,
				NULL);
			SQLBindCol(sqlStatementHandle,
				2,
				SQL_C_CHAR,
				&_list,
				1000,
				NULL);
			SQLBindCol(sqlStatementHandle,
				3,
				SQL_C_CHAR,
				&_task,
				1000,
				NULL);
			SQLBindCol(sqlStatementHandle,
				4,
				SQL_INTEGER,
				&_priority,
				7,
				NULL);
			SQLBindCol(sqlStatementHandle,
				5,
				SQL_INTEGER,
				&_inMain,
				7,
				NULL);

			dataTasks.id.clear();
			dataTasks.inMain.clear();
			dataTasks.list.clear();
			dataTasks.priority.clear();
			dataTasks.task.clear();

			bool flag = 1;
			while (flag) {

				switch (SQLFetch(sqlStatementHandle))
				{
				case SQL_SUCCESS:
				case SQL_SUCCESS_WITH_INFO:
					dataTasks.id.push_back(_id);
					dataTasks.inMain.push_back(_inMain);
					dataTasks.list.push_back((const char*)_list);
					dataTasks.task.push_back((const char*)_task);
					dataTasks.priority.push_back(_priority);
					break;
				default:
					flag = 0;
					break;
				}

			}

		}

		closeConnection();

	}

	//pobieranie danych - modul kalendarz
	void selectDataCalednar() {

		openConnection();

		if (sqlConnectionHandle) {
			//sprawdzenie czy istnieje tablica, utworzenie lub nie
			if (SQL_SUCCESS != SQLExecDirect(sqlStatementHandle,
				(SQLWCHAR*)L"CREATE TABLE calendar (id INT NOT NULL PRIMARY KEY IDENTITY, date_col VARCHAR(MAX) NULL, hourS_col VARCHAR(MAX) NULL, hourF_col VARCHAR(MAX) NULL, event VARCHAR(MAX) NULL, notification INT NULL)",
				SQL_NTS)) {
				console.changeColor(4);
				std::cout << "Tablica kalendarza istnieje.\n";
				console.changeColor(1);
			}
			else {

				console.changeColor(2);
				std::cout << "Tworze tablice kalendarza...\n";
				console.changeColor(1);

			}

			//dodanie pozycji
			if (SQL_SUCCESS != SQLExecDirect(sqlStatementHandle,
				(SQLWCHAR*)L"SELECT * FROM calendar",
				SQL_NTS)) {
				console.changeColor(4);
				std::cout << "Blad pobierania danych.\n";
				console.changeColor(1);
			}
			else {

				console.changeColor(2);
				std::cout << "Pobieram dane...\n";
				console.changeColor(1);

			}

			SQLINTEGER _id, _notification;
			SQLCHAR _date_col[10], _hourS_col[5], _hourF_col[5], _event[1000];

			SQLBindCol(sqlStatementHandle,
				1,
				SQL_INTEGER,
				&_id,
				5,
				NULL);
			SQLBindCol(sqlStatementHandle,
				2,
				SQL_C_CHAR,
				&_date_col,
				10,
				NULL);
			SQLBindCol(sqlStatementHandle,
				3,
				SQL_C_CHAR,
				&_hourS_col,
				5,
				NULL);
			SQLBindCol(sqlStatementHandle,
				4,
				SQL_C_CHAR,
				&_hourF_col,
				5,
				NULL);
			SQLBindCol(sqlStatementHandle,
				5,
				SQL_C_CHAR,
				&_event,
				1000,
				NULL);
			SQLBindCol(sqlStatementHandle,
				6,
				SQL_INTEGER,
				&_notification,
				1,
				NULL);

			dataCalendar.id.clear();
			dataCalendar.date_col.clear();
			dataCalendar.hourS_col.clear();
			dataCalendar.hourF_col.clear();
			dataCalendar.event.clear();
			dataCalendar.notification.clear();

			bool flag = 1;
			while (flag) {

				switch (SQLFetch(sqlStatementHandle))
				{
				case SQL_SUCCESS:
				case SQL_SUCCESS_WITH_INFO:
					dataCalendar.id.push_back(_id);
					dataCalendar.date_col.push_back((const char*)_date_col);
					dataCalendar.hourS_col.push_back((const char*)_hourS_col);
					dataCalendar.hourF_col.push_back((const char*)_hourF_col);
					dataCalendar.event.push_back((const char*)_event);
					dataCalendar.notification.push_back(_notification);
					break;
				default:
					flag = 0;
					break;
				}

			}

		}

		closeConnection();

	}

};

static databaseSelectHandler databaseSelect;