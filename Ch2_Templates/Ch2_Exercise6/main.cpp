// 2.6 LAB: Zip code and population (class templates)


#include<iostream>
#include <fstream>
#include <vector>
#include <string>
#include "StatePair.h"
using namespace std;

int main() {
	ifstream inFS; // File input stream
	int zip;
	int population;
	string abbrev;
	string state;
	unsigned int i;

	// ZIP code - state abbrev. pairs
	vector<StatePair <int, string>> zipCodeState;

	// state abbrev. - state name pairs
	vector<StatePair<string, string>> abbrevState;

	// state name - population pairs
	vector<StatePair<string, int>> statePopulation;

	// Fill the three ArrayLists

	// Try to open zip_code_state.txt file
	inFS.open("zip_code_state.txt");
	if (!inFS.is_open()) {
		cout << "Could not open file zip_code_state.txt." << endl;
		return 1; // 1 indicates error
	}
	while (!inFS.eof()) {
		StatePair <int, string> temp;
		inFS >> zip;
		if (!inFS.fail()) {
			temp.SetKey(zip);
		}
		inFS >> abbrev;
		if (!inFS.fail()) {
			temp.SetValue(abbrev);
		}
		zipCodeState.push_back(temp);
	}
	inFS.close();
	
   // Try to open abbreviation_state.txt file
	inFS.open("abbreviation_state.txt");
	if (!inFS.is_open()) {
		cout << "Could not open file abbreviation_state.txt." << endl;
		return 1; // 1 indicates error
	}
	while (!inFS.eof()) {
		StatePair <string, string> temp;
		inFS >> abbrev;
		if (!inFS.fail()) {
			temp.SetKey(abbrev);
		}
		getline(inFS, state); //flushes endline
		getline(inFS, state);
		if (!inFS.fail()) {
			temp.SetValue(state);
		}
		
		abbrevState.push_back(temp);
	}
	inFS.close();
	
	// Try to open state_population.txt file
	inFS.open("state_population.txt");
	if (!inFS.is_open()) {
		cout << "Could not open file state_population.txt." << endl;
		return 1; // 1 indicates error
	}
	while (!inFS.eof()) {
		StatePair <string, int> temp;
		getline(inFS, state);
		if (!inFS.fail()) {
			temp.SetKey(state);
		}
		inFS >> population;
		if (!inFS.fail()) {
			temp.SetValue(population);
		}
		getline(inFS, state); //flushes endline
		statePopulation.push_back(temp);
	}
	inFS.close();
	
	cin >> zip;

	string zipAbbrev = "";
	for (i = 0; i < zipCodeState.size(); ++i) {
		// TODO: Using ZIP code, find state abbreviation
		if( zipCodeState[i].GetKey() == zip) { // <-- zipCodeState[i] accesses the i'th element in vector StatePair<int, string> || This turns zipCodeState[i] into a StatePair<int, string> object
											   // ^-- .GetKey() calls the getter method in StatePair.h which returns the key, which is the ZIP code as an int
			zipAbbrev = zipCodeState[i].GetValue(); // <-- Once the two zips match, .GetValue retrieves the string from the StatePair<int, string> object
			break;
		}
	}


	string stateName = "";
	for (i = 0; i < abbrevState.size(); ++i) {
		// TODO: Using state abbreviation, find state name
		if( abbrevState[i].GetKey() == zipAbbrev ) {
			stateName = abbrevState[i].GetValue();
			break;
		}
	}


	int statePop = -1;
	for (i = 0; i < statePopulation.size(); ++i) {
		// TODO: Using state name, find population. Print pair info.
		if( statePopulation[i].GetKey() == stateName ) {
			statePop = statePopulation[i].GetValue();
			break;
		}
	}

	cout << stateName << ": " << statePop << endl;

}