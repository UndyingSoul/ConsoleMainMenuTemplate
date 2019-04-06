/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*::                         SETTINGS                         ::*/
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/

// Module enable/disable here
#define UM_CONSOLE_DISPLAY_MANAGER
#define UM_OUTPUT_TOOLS
#define UM_MATH
#define UM_FILE_HANDLER


/*########################### START ##############################*/
#pragma once
#ifndef UNDYING_SOUL_USEFUL_METHODS
#define UNDYING_SOUL_USEFUL_METHODS

#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>
#include <string>

/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*::  Function that clears the input buffer                   ::*/
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
void clearInputBuffer() {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*::  Returns true or false depending on valid user input     ::*/
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
bool again() {
	std::string choice;
	do {
		std::cout << "Again? ";
		std::cin >> choice;
		clearInputBuffer();
		std::cout << "\n\n";
		if (choice == "yes" || choice == "Yes" || choice == "YES"
			|| choice == "y" || choice == "Y" || choice == "1"
			|| choice == "yep" || choice == "Yep" || choice == "YEP"
			|| choice == "true" || choice == "True" || choice == "TRUE"
			|| choice == "mhm" || choice == "Mhm" || choice == "MHM"
			|| choice == "totally" || choice == "Totally" || choice == "TOTALLY"
			|| choice == "absolutely" || choice == "Absolutely" || choice == "ABSOLUTELY"
			|| choice == "affirmative" || choice == "Affirmative" || choice == "AFFIRMATIVE"
			|| choice == "indefinately" || choice == "Indefinately" || choice == "INDEFINATELY"
			|| choice == "yeah" || choice == "Yeah" || choice == "YEAH") {
			return true;
		}
		if (choice == "no" || choice == "No" || choice == "NO"
			|| choice == "n" || choice == "N" || choice == "0"
			|| choice == "nope" || choice == "Nope" || choice == "NOPE"
			|| choice == "false" || choice == "False" || choice == "FALSE"
			|| choice == "uhuh" || choice == "Uhuh" || choice == "UhUh"
			|| choice == "UHUH" || choice == "hail no" || choice == "hail nah"
			|| choice == "nah" || choice == "Nah" || choice == "NAH"
			|| choice == "no way" || choice == "No way" || choice == "NO WAY"
			|| choice == "no Way" || choice == "caninot" || choice == "Caninot"
			|| choice == "nupe" || choice == "Nupe" || choice == "NUPE"
			|| choice == "definately not" || choice == "Definately not"
			|| choice == "naw" || choice == "Naw" || choice == "NAW"
			|| choice == "nay" || choice == "Nay" || choice == "NAY"
			|| choice == "negative" || choice == "Negative" || choice == "NEGATIVE" || choice == "Im good"
			|| choice == "nah bro" || choice == "Nah bro" || choice == "NAH BRO"
			|| choice == "Nah Bro" || choice == "nah Bro" || choice == "nah broskie") {
			return false;
		}
		else {
			std::cout << "Incorrect input, try again with 'yes', or 'no' this time.\n";
		}
	} while (true);
}

/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*::  Pauses intil the user enters any character              ::*/
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
char getNextChar() {
	int character;
	while (_kbhit())
	{
		character = _getch(); // Empty the input buffer
	}
	character = _getch(); // Wait for a key
	while (_kbhit())
	{
		character = _getch(); // Empty the input buffer (some keys sends two messages)
	}
	return character;
}

void pauseNoOutput()
{
	getNextChar();
}

void pause()
{
	std::cout << std::endl << "Press any key to continue . . .";
	getNextChar();
}


/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*::  Cross-platform sleep function (in milliseconds)         ::*/
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
void sleep(int milliseconds)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}


#ifdef UM_CONSOLE_DISPLAY_MANAGER
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*::  A utility for managing console colors/display/ui        ::*/
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
enum colors {
	BLACK = 0, RED, GREEN, YELLOW, BLUE, PURPLE, CYAN, GREY,
	LIGHTGREY, LIGHTRED, LIGHTGREEN, LIGHTYELLOW, LIGHTBLUE,
	LIGHTPURPLE, LIGHTCYAN, WHITE, DEFAULT
};

void setConsoleTextColor(colors textColor) {

	// Set default foreground color
	if (textColor == DEFAULT) {
		printf("\x1B[39m");
	}

	// Set bright foreground color
	else if (textColor > GREY) {
		// Set bright mode
		printf("\x1B[1m");
		// Set color
		printf("\x1B[3%im", textColor - LIGHTGREY);
	}

	// Set normal foreground color
	else {
		// Set normal mode
		printf("\x1B[22m");
		// Set color
		printf("\x1B[3%im", textColor);
	}
}

void setConsoleBackgroundColor(colors backgroundColor) {

	// Set default background color
	if (backgroundColor == DEFAULT)
		printf("\x1B[49m");

	// Set bright background color
	else if (backgroundColor > GREY) {
		// Set bright mode
		printf("\x1B[1m");
		// Set color
		printf("\x1B[4%im", backgroundColor - LIGHTGREY);
	}

	// Set normal background color
	else {
		// Set normal mode
		printf("\x1B[22m");
		// Set color
		printf("\x1B[4%im", backgroundColor);
	}
}

void consoleColor(colors textColor, colors backgroundColor) {
	setConsoleTextColor(textColor);
	setConsoleBackgroundColor(backgroundColor);
}

void colorReset() {
	consoleColor(DEFAULT, DEFAULT);
}

bool goToXY(unsigned short x, unsigned short y) {
	if ((x == 0) || (y == 0))
		return false;
	printf("\x1B[%i;%iH", y, x);
	return true;
}

void clearScreen(bool moveToStart = true) {
	printf("\x1B[2J");
	if (moveToStart)
		goToXY(1, 1);
}
#endif // UM_CONSOLE_DISPLAY_MANAGER

#ifdef UM_OUTPUT_TOOLS
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*::  A slow typing utility that outputs messages slowre      ::*/
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
#include <string>
#include <iostream>

void slowType(const std::string & message, unsigned int millisecondsPerCharacter = 50)
{
	// Range loops are "for each" constructs; here: for each character in the string
	for (const char character : message)
	{
		// flush is used to make sure the buffer is emptied to the terminal immediately
		std::cout << character << std::flush;

		// Ask the thread to sleep for at least n millis.
		sleep(millisecondsPerCharacter);
	}
}

/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*::  A utility that outputs character by character as entered::*/
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
void hackerTyper(const std::string & message)
{
	// Range loops are "for each" constructs; here: for each character in the string
	for (const char character : message)
	{

		pauseNoOutput();

		// flush is used to make sure the buffer is emptied to the terminal immediately
		std::cout << character << std::flush;
	}
}

/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*::  A usable progress bar that ouputs a nice UI (finicky)   ::*/
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
void printProgress(double percentage)
{
	// Change these to change the size of the progress bar.
	static constexpr auto PBSTR = "################################################################";
	static constexpr int PBWIDTH = 64;

	int val = (int)(percentage * 100);
	int lpad = (int)(percentage * PBWIDTH);
	int rpad = PBWIDTH - lpad;
	printf("\r\t%3d%% [%.*s%*s]", val, lpad, PBSTR, rpad, "");
	fflush(stdout);
}

void spinner(int spin_seconds) {
	static char const spin_chars[] = "/-\\|";
	unsigned long i, num_iterations = (spin_seconds * 5);
	for (i = 0; i < num_iterations; ++i) {
		printf("%c ", spin_chars[i % 4]);
		fflush(stdout);
		sleep(200);
		printf("\b\b");
	}
}
#endif // UM_OUTPUT_TOOLS

#ifdef UM_MATH
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*::  Some math functions that are useful                     ::*/
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
constexpr auto pi = 3.1415926535897932384626433832795028841971693993751058209749445923078164;

double deg2rad(double degrees) {
	return degrees * pi / 180.0;
}

double rad2deg(double radians) {
	return radians * 180 / pi;
}
#endif // UM_MATH


#ifdef UM_FILE_HANDLER
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*::  Some useful file handling functions.                    ::*/
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
#include <fstream>
#include <string>

void checkFile(std::string fileName) {
	std::ifstream file(fileName);
	std::string errorText("Could not open file \"" + fileName + "\".");
	if (!file) {
		throw errorText;
	}
	file.close();
}

void printFileToConsole(std::string fileName) {
	std::ifstream file(fileName);
	if (file.good()) {
		std::string tmp;
		while (getline(file, tmp, '\n')) {
			printf("%s\n", tmp.c_str());
		}
		file.close();
	}
}
#endif // UM_FILE_HANDLER
#endif // !UNDYING_SOUL_USEFUL_METHODS
/*######################### END-OF-FILE ##########################*/