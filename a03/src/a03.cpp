/*****************************************************
** Program Name: Functions
** File Name: a03.cpp
** Author: Ojhan Ardalan
** Date: November 8 2018
** Description: Calculates the cost of becoming a member at a fitness center
** Sources: None
********************************************************/

#include <iostream>
using namespace std;

void information(); //declares the information function
void getInfo(bool &senior, int &months, int &personal); //declares the getInfo function with the senior, months, and personal arguments
double calcCost(bool senior, int months, int presonal); //declares the calcCost function with the senior, months, and personal arguments


int main() {
	bool s = false; //boolean value for if the user is a senior
	int m = 0; //int value for the number of months
	int p = 0; //int value for the number of personal sessions
	char answer = 'c'; //char value to record the users response


	while (answer != 'b') { //loops until the user enters b
		cout << "Hello, this program will calculate the total cost of a gym membership.\n\n"
			 << "Please enter \"a\" to calculate cost of membership, or enter \"b\" to quit the program. ";
		cin >> answer;

		if (answer == 'a'){
			cout << endl; //creates a new line
			information(); //calls the information function
			getInfo(s, m, p); //calls the getInfo function
			cout << "Your total membership fee is $" << calcCost(s, m, p) << "\n\n"; //tells the user their total membership fee
		}
		else if (answer != 'b') //if the answer is neither a or b, the user is told they have submitted an incorrect response
			cout << "Incorrect response\n\n";


	}

	cout << "Thank you for using my gym calculation program." << endl;
}

void information() { //this function that prints out all cost and discount information
	cout << "General Membership Fee: $50.00 / month.\n"
		 << "Senior Citizen Discount: 30% for any member over the age of 60.\n"
		 << "(If the membership is bought and paid for 12 or more months, the discount is 15% each month.\n"
		 << "Personal Training Session: $30.00 per session.\n"
		 << "(If 5 or more sessions are bought and paid for, there will be a 20% discount on each session).\n\n";
}

void getInfo(bool &senior, int &months, int &personal) { //this function will gather the users information
	char ans1 = 'n';
	int ans2 = 0;

	cout << "Are you over the age of 60? (y or n) ";
	cin >> ans1;
	if (ans1 == 'y') //will check to see if the user is a senior
		senior = true;

	cout << "Please enter the number of months you would like to prepay for the membership ";
	cin >> ans2;
	months = ans2; //stores how many months the user is purchasing

	cout << "Please enter the number of personal training sessions you would like to purchase ";
	cin >> ans2;
	personal = ans2; //stores how many personal training sessions the user is purchasing
}

double calcCost(bool senior, int months, int personal) { //this function calculates the cost of membership based on the user's info
	double cost = 0;
	double base1 = 50; //50$ is the base price per month
	double base2 = 30; //30$ is the base price per personal training session

	if (senior == true)
		base1 *= .7; //will take off 30% if the user is a senior
	if (months >= 12)
		base1 *= .85; //will take of  15% if the user purchases 12 or more months
	cost = months * base1;

	if (personal > 5)
		base2 *= .8; //will take off 20@ if the user purchases 10 or more personal training sessions
	cost += personal * base2;

	return cost; //returns the cost
}
