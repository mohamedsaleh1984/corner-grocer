
#include "FrequencyHandler.h"
//Colors 
//Used Reference:: https://gist.github.com/vratiu/9780109

#define COLOR_RESET			"\033[0m"
#define RED_COLOR			"\033[0;31m"
#define GREEN_COLOR			"\033[0;32m"
#define YELLOW_COLOR		"\033[0;33m"
#define BLUE_COLOR			"\033[0;34m"
#define PURPLE_COLOR		"\033[0;35m"
#define CYAN_COLOR			"\033[0;36m"


/// <summary>
/// Check if item is the Frequency Table.
/// </summary>
void FrequencyHandler::SearchItem() {
	string strLine;

	cout << "Please enter item name." << endl;
	getline(cin, strLine);

	int iNdx = GetItemIndex(strLine);

	if (iNdx == -1) {
		cout << RED_COLOR << "Item not found" << COLOR_RESET << endl;
	}
	else {
		cout << GREEN_COLOR << freqTable.at(iNdx).GetFrequency() << COLOR_RESET << endl;
	}
}

/// <summary>
/// Helper method to Read File lines
/// </summary>
/// <returns>vector holds file lines assuming each line is ONE WORD</returns>
vector<string> FrequencyHandler::ReadFileToVector() {
	string line;						//Read Line
	vector<string> vec;					//vector to hold 
	ifstream file(FILE_NAME);			//Read File	

	if (file.is_open()) {
		while (getline(file, line))
			vec.push_back(line);
	}
	else
		cout << "Failed to open file" << endl;

	//Close file
	file.close();

	return vec;
}

/// <summary>
/// Show Frequency table (Menu Option 2)
/// </summary>
void FrequencyHandler::ShowItemFrequency() {

	for (int i = 0; i < this->freqTable.size(); i++) {
		cout << freqTable[i].GetName() << " " << freqTable[i].GetFrequency() << endl;
	}
}

/// <summary>
/// Helper method to check if item exist in the table or not.
/// </summary>
/// <param name="word"></param>
/// <returns></returns>
int FrequencyHandler::GetItemIndex(string word) {
	for (int i = 0; i < this->freqTable.size(); i++) {
		if (freqTable[i].GetName() == word)
			return i;
	}
	return -1;
}

/// <summary>
/// Present Frequency Table as Histogram.
/// </summary>
void FrequencyHandler::ShowHistogram() {
	for (size_t i = 0; i < this->freqTable.size(); i++)
	{
		PrintColumn(freqTable[i]);
	}
}

/// <summary>
/// Print out each Items and it's Frequency.
/// </summary>
/// <param name="item"></param>
void FrequencyHandler::PrintColumn(Item item) {
	//generate string with specific len (freq)
	std::string bar(item.GetFrequency(), '*');

	vector<string> colors = {
		RED_COLOR,
		GREEN_COLOR,
		YELLOW_COLOR,
		BLUE_COLOR,
		PURPLE_COLOR,
		CYAN_COLOR };

	int colorIndex = rand() % colors.size();

	cout << left
		<< setw(15)
		<< item.GetName()
		<< "::"
		<< colors[colorIndex]
		<< bar
		<< COLOR_RESET
		<< endl;
}

/// <summary>
/// Create Frequency Table
/// </summary>
/// <returns></returns>
void FrequencyHandler::CreateFrquencyTable() {
	vector<string>  words = ReadFileToVector();
	vector<Item> freqTable = CreateFrquencyTableFromList(words);
	WriteFrequencyTable();
	this->freqTable = freqTable;
}

/// <summary>
/// Write Frequency Table to frequency.dat
/// </summary>
void FrequencyHandler::WriteFrequencyTable() {
	if (this->freqTable.size() == 0)
		return;

	//to check if file is already exsist.
	ifstream cfile("frequency.dat");		
	if (cfile.is_open()) {
		cfile.close();
		return;
	}

	//Create frequency.dat
	ofstream file("frequency.dat");
	for (int i = 0; i < this->freqTable.size(); i++) {
		file << freqTable[i].GetName() << " " << freqTable[i].GetFrequency() << endl;
	}
	file.close();
}

/// <summary>
/// Create Frequency Table from Word List
/// </summary>
/// <param name="wordList"></param>
/// <returns></returns>
vector<Item> FrequencyHandler::CreateFrquencyTableFromList(vector<string> wordList) {

	for (int i = 0; i < wordList.size(); i++) {
		string word = wordList[i];
		int iIndex = GetItemIndex(word);
		if (iIndex >= 0) {
			freqTable.at(iIndex).Increment();
		}
		else {
			Item newItem(word);
			freqTable.push_back(newItem);
		}
	}

	return freqTable;
}