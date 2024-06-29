/*
	Student Name:	Mohamed Saleh
	File Name:		validator.h
	Purpose:		make sure to fetch correct input from the user.
*/

#pragma once
#ifndef VALIDATOR_H
#define VALIDATOR_H
#include <iostream>
#include <string>
using namespace std;

/// Handle user input and validates the given input within range.
class Validator {
public:
	int static ValidateUserInput(string statement) {
		bool needInput = true;						//flag to check if we still need a valid number or not
		string userInput;							//fetch user input
		int returnValue;							//converted value from string to int.

		do {
			try {
				//printout the statement
				cout << statement << endl;

				//fetch input from user
				std::getline(std::cin, userInput);

				returnValue = stoi(userInput);

				if (returnValue < 0) {
					cout << "Invalid input, please enter non-negative number" << endl;
				}
				else if (returnValue > 4) {
					cout << "Invalid input, Please enter a value between 1 and 4" << endl;
				}
				else {
					needInput = false;
					//convert string to integer
					returnValue = stoi(userInput);
				}

			}//in case of any excption remain in the loop until user enter valid number within the range.
			catch (...) {
				needInput = true;
			}

		} while (needInput);

		return returnValue;
	}

};

#endif