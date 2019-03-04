// AfterInterview2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

typedef vector<int> int_vec;		// Define a integer vector datatype

// Prototype Functions
void showArray(int_vec *arr);		// Function: Display array
void sortArray(int_vec *arr);		// Function: Sort arry in asceding order
void reverseArray(int_vec *arr);	// Function: Reverse array in place
int getRandNotVector(int_vec *arr); // Function: Get a randon number not inside of a sorted array
int getRandonNumber(int N);			// Function: Get a randon number from 1 to N

// Main Function 
int main()
{
	// Create a seed to generate the randon numbers 
	srand(time(NULL));				

	// Example Array
	int_vec arr = { 4,3,40,1,5,2};	
	cout << "Array used for the demonstration: "; showArray(&arr);
	
	// Reverse Array in Place
	reverseArray(&arr);
	cout << "Reverse array in place:           "; showArray(&arr);
	
	// Sort Array
	sortArray(&arr);
	cout << "Sort Array in asceding order:     "; showArray(&arr);

	// Get a randon number not inside of a sorted array
	int rnumber = getRandNotVector(&arr);
	cout << "Get a number out of the array:    "; cout << rnumber;

	cout << endl;
	system("pause");
}

// Function: Sort arry in asceding order
//		Example: sortArray(arr);
void sortArray(int_vec *arr)
{
	int temp;
	for (int i = 0; i < arr->size(); i++)
	{
		for (int j = i + 1; j < arr->size(); j++)
		{
			if (arr->at(i) > arr->at(j))
			{
				temp = arr->at(i);
				arr->at(i) = arr->at(j);
				arr->at(j) = temp;
			}
		}
	}
}


// Get a randon number not inside of a sorted array
//		Example: getRandNotVector(arr);
int getRandNotVector(int_vec *arr)
{	
	int secretNum = getRandonNumber(arr->size() - 1);

	for (int i = 0; i < arr->size(); i++)
	{
		if (secretNum < arr->at(i))
			return secretNum; 
		if ((secretNum == arr->at(i)))
		{
			secretNum = getRandonNumber(arr->at(arr->size() - 1));
			i = -1;
		}	
	}
}

// Reverse Array in Place
//		Example: reverseArray(arr);
void reverseArray(int_vec *arr)
{
	int N = (arr->size() % 2 == 0) ? arr->size() / 2 : (arr->size() - 1) / 2;
	int temp;

	for (int i = 0; i < N; i++)
	{
		temp = arr->at(i);
		arr->at(i) = arr->at(arr->size() - i - 1);
		arr->at(arr->size() - i - 1) = temp;
	}
}

int getRandonNumber(int N)
{
	// Return a random number from 1 to N
	return std::rand() % N + 1;	
}

void showArray(int_vec *arr)
{
	for (int i = 0; i < arr->size(); i++)
	{
		cout << arr->at(i) << " ";
	}
	cout << endl;
}