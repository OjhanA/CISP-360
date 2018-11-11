/*****************************************************
** Program Name: Input/Output
** File Name: a02.cpp
** Author: Ojhan Ardalan
** Date: October 31 2018
** Description: Calculates the shortest distance between two cars
** Sources: None
********************************************************/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
	double carA = 0.0; //variable for car A
	double carB = 0.0; //variable for car B
	double hours = 0.0; //variable for the amount of hours
	double minutes = 0.0; //variable for the amount of minutes
	double distance = 0.0; //variable for the distance

	cout << "Enter the speed for Car A: "; //asks for the speed of car A
	cin >> carA;

	cout << "Enter the speed for Car B: "; //asks for the speed of car B
	cin >> carB;

	cout << "Enter elapsed time as hours and minutes: "; //asks for time elapsed
	cin >> hours >> minutes;

	hours += minutes / 60.0; //converts minutes to hours
	carA *= hours; //calculates distance for car A
	carB *= hours; //calculates distance for car B

	distance = sqrt(pow(carA, 2) + pow(carB, 2)); //calculates the shortest distance between car A and B

	cout << "The shortest distance between the cars is " << distance << " miles." << endl; //prints out the shortest distance

}


