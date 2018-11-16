/*****************************************************
** Program Name: Midterm
** File Name: a03.cpp
** Author: Ojhan Ardalan
** Date: November 13 2018
** Description: CISP 360 Midterm
** Sources: None
********************************************************/

#include <iostream>
using namespace std;

int main() {
	int evenSum = 0, evenCount = 0, oddSum = 0, oddCount = 0, ans = 0; //initializes all the variables that will be needed, including the counts and sums

	while (ans != -999) { //loops until the user inputs -999
		cout << "Enter a non negative integer (or -999 to quit): "; //asks the user for input
		cin >> ans; //stores the input in ans

		if (ans < 0 && ans != -999) //if the answer is negative and not the sentinel value, the user will be told that their answer must be non-negative
			cout << "Make sure your answer is non-negative" << endl;

		else if (ans != -999) { //if the answer is not negative and not the sentinel value, the program will continue
			if (ans % 2 == 0) { //if the answer is even, the evenSum will add the answer to itself and evenCount will increase by one
				evenSum += ans;
				evenCount++;
			}
			else { //if the answer is odd, the oddSum will add the answer to itself and oddCount will increase by one
				oddSum += ans;
				oddCount++;
			}
		}
	}
	cout << "\nThere were " << evenCount << " even numbers and their sum is " << evenSum << endl; //outputs the counts and sums.
	cout << "There were " << oddCount << " odd numbers and their sum is " << oddSum << endl;

}



