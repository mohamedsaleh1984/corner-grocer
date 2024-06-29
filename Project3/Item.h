/*
	Student Name:	Mohamed Saleh
	File Name:		item.h
	Purpose:		a representation of Item Frequency.
*/

#pragma once
#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>
using namespace std;

class Item {
public:
	//Set the frequency to 1 once an instance created of the class
	Item(string name) :name(name), frequency(1) {}
	//Getter for Name
	string GetName()const {
		return name;
	}

	//Getter for frequency
	int GetFrequency() const {
		return frequency;
	}

	//Increament the frequency.
	void Increment() {			
		frequency++;
	}
private:
	int frequency;				//Frequency
	string name;				//Name
};
#endif