#include <iostream>
#include "validator.h"
#include "FrequencyHandler.h"
using namespace std;


/*
	Printout the main loop for the program.
*/
void displayMenu() {
	FrequencyHandler fh;
	do {
		cout << "1. Find Item Frequency " << endl;
		cout << "2. Print out Items Frequency" << endl;
		cout << "3. Show frequency histogram" << endl;
		cout << "4. Exit" << endl;

		int userChoice = Validator::ValidateUserInput("Please enter your choice from 1 to 4.");

		switch (userChoice)
		{
		case 1:
			fh.SearchItem();
			break;
		case 2:
			fh.ShowItemFrequency();
			break;
		case 3:
			fh.ShowHistogram();
			break;
		case 4:
			//Exit the loop
			exit(0);
			break;
		default:
			break;
		}
	} while (true);
}

int main(int argc, char** argsv) {
	displayMenu();
	return 0;
}

