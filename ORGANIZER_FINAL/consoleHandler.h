#pragma once
#include <iostream>
#include <Windows.h>

class consoleHandler {

	HANDLE con;

public:

	void openConsole() {

		AllocConsole();
		con = GetStdHandle(STD_OUTPUT_HANDLE);
		FILE* fpstdin = stdin, * fpstdout = stdout, * fpstderr = stderr;
		freopen_s(&fpstdin, "CONIN$", "r", stdin);
		freopen_s(&fpstdout, "CONOUT$", "w", stdout);
		freopen_s(&fpstderr, "CONOUT$", "w", stderr);

	}

	void changeColor(int x) {

		if (con && x >= 0 && x <= 255) {
			SetConsoleTextAttribute(con, x);
		}

	}

	void closeConsole() {

		FreeConsole();

	}
};

static consoleHandler console;