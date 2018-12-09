/*****************************************************
** Program Name: Structs
** File Name: a06.cpp
** Author: Ojhan Ardalan
** Date: December 8 2018
** Description: Stores the 12 months and their high and low temperatures in an array
** Sources: None
********************************************************/

#include <iostream>
#include <fstream>
using namespace std;

//declares a Temperature struct
struct Temperature {
	string month;
	int highTemp;
	int lowTemp;
};

//declares the functions
void loadData(ifstream &infile, Temperature temp[], int &size);
Temperature averageHigh(Temperature temp[], int size);
Temperature averageLow(Temperature temp[], int size);


int main() {
	ifstream inFile;
	inFile.open("temps.txt"); //opens the temps.txt file

	int size = 0; //declares the size variable
	Temperature highMonth; //declares the highMonth variable
	Temperature lowMonth; //declares the lowMonth variable
	Temperature temp[12]; //declares an array of Temperatures

	loadData(inFile, temp, size); //calls the loadData function to load the data from the temps.txt file
	highMonth = averageHigh(temp, size); //calls the averageHigh function to find the Temperature with the highest temp and stores it
	lowMonth = averageLow(temp, size); //calls the averageLow function to find the Temperature with the lowest temp and stores it

	cout << "Maximum temp was " << highMonth.highTemp << " degrees in " << highMonth.month << "." << endl; //prints the high temp and month
	cout << "Minimum temp was " << lowMonth.lowTemp << " degrees in " << lowMonth.month << "." << endl; //prints the low temp and month

	inFile.close(); //closes the temps.txt file
}

/*****************************************************
** Function Name: loadData
** Parameters: ifstream &infile, Temperature temp[], int &size
** Description: laods the .txt file information into the Temperature array
********************************************************/
void loadData(ifstream &infile, Temperature temp[], int &size) { //the loadData function
	int i = 0;
	while(!infile.eof()) { //loops though the file
			infile >> temp[i].month; //inputs the month into the Temperature array
			infile >> temp[i].highTemp >> temp[i].lowTemp; //inputs the temps into the Temperature array
			i++;
			size++; //increases the size
		}
}

/*****************************************************
** Function Name: averageHigh
** Parameters: Temperature temp[], int size
** Description: finds the Temperature with the highest temp
********************************************************/
Temperature averageHigh(Temperature temp[], int size) {
	int high = temp[0].highTemp; //sets the highest temp to the temp of the first Temperature
	int index = 0; //the index of the Temperature with the highest temp

	for (int i = 1; i < size; i++) { //loops through the array
		if (temp[i].highTemp > high) { //checks if the current high temp is higher than the stored high temp
			high = temp[i].highTemp; //sets the new high temp
			index = i; //sets the index of the Temperature with the highest temp
		}
	}
	return temp[index]; //returns the Temperature with the highest temp
}

/*****************************************************
** Function Name: averageLow
** Parameters: Temperature temp[], int size
** Description: finds the Temperature with the lowest temp
********************************************************/
Temperature averageLow(Temperature temp[], int size) {
	int low = temp[0].lowTemp; //sets the lowest temp to the temp of the first Temperature
	int index = 0; //the index of the Temperature with the lowest temp

	for (int i = 1; i < size; i++) { //loops through the array
		if (temp[i].lowTemp < low) {//checks if the current low temp is lower than the stored low temp
			low = temp[i].lowTemp; //sets the new low temp
			index = i; //sets the index of the Temperature with the lowest temp
		}
	}
	return temp[index]; //returns the Temperature with the lowest temp
}


