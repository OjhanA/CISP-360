/*****************************************************
** Program Name: Assignment 01 Basic elements of C++
** File Name: a01.cpp
** Author: Ojhan Ardalan
** Date: October 25 2018
** Description: Calculates voltage given current and resistance
** Sources: None
********************************************************/

#include <iostream>
using namespace std;

int main(){

	double resistance = 0; //Creates a variable for resistance
	double current = 0; //Creates a variable for current

	cout << "Please input the resistance: "; //Asks the user for input
	cin >> resistance; //Stores the input in a variable

	cout << "Please input the current: ";
	cin >> current;

	cout << "Your voltage is: " << resistance * current << endl; //Calculates the voltage and prints it
	return 0;
}
