/*****************************************************
** Program Name: Dynamic Arrays
** File Name: a05.cpp
** Author: Ojhan Ardalan
** Date: November 29 2018
** Description: Prints the max, min, and average values from a dynamic array
** Sources: None
********************************************************/

#include <iostream>
using namespace std;

void findMax(int nums[], int &max, int size); //declares the findMax function
void findMin(int nums[], int &min, int size); //declares the findMin function
void calcAverage(int nums[], double &avg, int size, int max, int min); //declares the calcAverage function

int main() {
	int max = 0; //the max of the array
	int min = 0; //the min of the array
	double avg = 0; //the average of the array (excluding max and min)
	int* ptr = 0; //the pointer used to create the dynamic array
	int size = 0; //the size of the array

	cout << "How many integers? ";
	cin >> size; //asks the user for the size of the array and stores it

	ptr = new int[size]; //creates a new dynamic array with the correct size

	for (int i = 0; i < size; i++) { //loops through the array
		cout << "Integer " << i + 1 << " "; //asks the user for ints to place in the array
		cin >> ptr[i]; //places the user input in the array
	}

	findMax(ptr, max, size); //calls the findMax function
	findMin(ptr, min, size); //calls the findMin function
	calcAverage(ptr, avg, size, max, min); //calls the calcAverage function

	cout << "Min: " << min << endl; //prints the min
	cout << "Max: " << max << endl; //prints the max
	cout << "Average (excluding min and max): " << avg << endl; //prings the average

	delete [] ptr; //deallocates the pointer
	ptr = 0;

}


/*****************************************************
** Function Name: findMax
** Parameters: array nums[], reference of int max, and int size
** Description: find the max of the array and stores it in max
********************************************************/
void findMax(int nums[], int &max, int size) {
	max = nums[0]; //sets the max to the first element
	for (int i = 1; i < size; i++){ //loops through the array
		if (nums[i] > max) //if the current element is larger than the max, it will become the new max
			max = nums[i];
	}
}


/*****************************************************
** Function Name: findMin
** Parameters: array nums[], reference of int min, and int size
** Description: find the min of the array and stores it in min
********************************************************/
void findMin(int nums[], int &min, int size) {
	min = nums[0]; //sets the min to the first element
	for (int i = 1; i < size; i++){ //loops through the array
		if (nums[i] < min) //if the current element is larger than the min, it will become the new min
			min = nums[i];
	}
}


/*****************************************************
** Function Name: calcAverage
** Parameters: array nums[], reference of int avg, int size, int max, and int min
** Description: find the average of the array excluding the max and min and stores it in avg
********************************************************/
void calcAverage(int nums[], double &avg, int size, int max, int min) {
	int count = 0; //counter for the number of max and mins
	for (int i = 0; i < size; i++) { //loops through the array
		if (nums[i] != max && nums[i] != min ) //if the current element is neither the max nor the min, it will be added to the sum
			avg += nums[i];
		else //if the element is a max or a min, the counter will increase
			count++;
	}
	avg /= (size - count); //divides the sum by the size subtracted by the number of max/mins
}
