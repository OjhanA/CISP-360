/*****************************************************
** Program Name: Arrays and Strings
** File Name: a04.cpp
** Author: Ojhan Ardalan
** Date: November 15 2018
** Description: Stores the highest and lowest temperatures for each month of the year
** Sources: None
********************************************************/

#include <iostream>
#include <fstream>
using namespace std;

//declares the functions
void loadData(ifstream &infile, string months[], int temp[][2], int &rows);
void tempHigh(string months[], int temp[][2], int rows, string &month, int &hightemp);
void tempLow(string months[], int temp[][2], int rows, string &month, int &lowtemp);

int main() {
	ifstream inFile;
	inFile.open("temps.txt"); //opens the temps.txt file

	int rows = 0; //declares the rows variable
	int highTemp = 0, lowTemp = 0; //declares the highTemp and lowTemp variables
	string highMonth = "January"; //declares the highMonth variable
	string lowMonth = "January"; //declares the lowMonth variable
	int temp[12][2] = {{0},{0}}; //declares a 2D array of temp
	string months[12] = {"0"}; //declares an array of months

	loadData(inFile, months, temp, rows); //calls the loadData function to load the data from the temps.txt file
	tempHigh(months, temp, rows, highMonth, highTemp); //calls the tempHigh function to find the high temp and month
	tempLow(months, temp, rows, lowMonth, lowTemp); //calls the tempLow function to find the low temp and month

	cout << "Maximum temp was " << highTemp << " degrees in " << highMonth << "." << endl; //prints the high temp and month
	cout << "Minimum temp was " << lowTemp << " degrees in " << lowMonth << "." << endl; //prints the low temp and month

	inFile.close(); //closes the temps.txt file
}

void loadData(ifstream &infile, string months[], int temp[][2], int &rows) { //the loadData function
	int i = 0;
	while(!infile.eof()) { //loops though the file
			infile >> months[i]; //inputs the month into the array of months
			infile >> temp[i][0] >> temp[i][1]; //inputs the temps into the temp array
			i++;
			rows++; //increases the number of rows by one
		}
}

void tempHigh(string months[], int temp[][2], int rows, string &month, int &hightemp) { //the tempHigh function
	int currentMax = 0; //sets the current max to the first cell
	for (int i = 1; i < rows; i ++) { //loops through the array
		if (temp[i][0] > temp[currentMax][0]) //checks to see if the current temp is greater than the current max
			currentMax = i; //if the current is bigger, the new max will be the current
	}

	month = months[currentMax]; //sets the month to the month with the highest temp
	hightemp = temp[currentMax][0]; //sets  highTemp to the highest temp
}

void tempLow(string months[], int temp[][2], int rows, string &month, int &lowtemp) { //the tempLow function
	int currentMin = 0; //sets the current min to the first cell
	for (int i = 1; i < rows; i ++) { //loops through the aray
		if (temp[i][1] < temp[currentMin][1]) //checks to see if the current temp is smaller than the current min
			currentMin = i; //if the current is smaller, the new min will be the current
	}

	month = months[currentMin]; //sets the month to the month with the lowest temp
	lowtemp = temp[currentMin][1]; //sets  lowtemp to the lowest temp
}



