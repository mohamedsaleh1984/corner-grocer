/*
	Student Name:	Mohamed Saleh
	File Name:		FrequencyHandler.h
	Purpose:		Header file for Core Functions
*/

#pragma once
#ifndef __FREQUENCY_HANDLER_H
#define __FREQUENCY_HANDLER_H

#include <iostream>
#include <exception>
#include <iomanip>
#include <fstream>
#include <math.h>
#include <map>
#include "validator.h"
#include <vector>
#include "Item.h"

const string FILE_NAME = "CS210_Project_Three_Input_File.txt";
/// <summary>
/// Core Class to handle Building Frequency Table, check if file exsists, write freqTable to file
/// </summary>
class FrequencyHandler {
public:
	FrequencyHandler() {
		//Help to generate random numbers to assign colors for Histograms
		srand(time(NULL));
		//Build/Assign Frequency Table and Write down the file;
		CreateFrquencyTable();
	}

	void SearchItem();
	void ShowItemFrequency();
	void ShowHistogram();
	
private:
	void CreateFrquencyTable();
	int GetItemIndex(string word);
	void PrintColumn(Item item);
	void WriteFrequencyTable();
	vector<string> ReadFileToVector();
	vector<Item> CreateFrquencyTableFromList(vector<string> wordList);
	vector<Item> freqTable;								//Hold the Frequency Data
};

#endif // !__FREQUENCY_HANDLER_H
