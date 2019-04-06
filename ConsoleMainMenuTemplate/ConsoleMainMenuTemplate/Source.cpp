#include "Useful Methods.h"
#include <fstream>

using namespace std;

/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*::  Function Prototypes                                     ::*/
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/

int driver();

/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*::  Functions                                               ::*/
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/

int main() {
	char choice;
	do
	{
		std::cout << "What would you like to do?\n"
			<< "1) Driver\n"
			<< "2) Exit\n";
		choice = getNextChar();
		std::cout << "\n\n";
		switch (choice)
		{
		case '1':
			driver();
			break;
		case '2':
			return 0;
			break;
		default:
			std::cout << "Invalid input, please try again.\n";
		}
	} while (true);
	return 0;
}

/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*::  Function name:                                          ::*/
/*::  Description:                                            ::*/
/*::  Usage:                                                  ::*/
/*::  Helpful Information:                                    ::*/
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/

int driver() {
	//Driver Stuff
	
	return 0;
}