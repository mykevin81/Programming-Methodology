// Project 7.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "Recursion.h"

using namespace std;


int main()
{
	bool repeat = true;
	char answer;
	int choice, result;
	int k;
	recursion arr;

	//Input fix array value of size 10
	arr.input();
	cout << "The array is stored, NO other array input is required" << endl << endl;

	while (repeat == true)
	{
		
		cout << "here is a few things you can do:" << endl;
		cout << "1. Print the array in recursive order" << endl
			<< "2. Find the largest in array recursively" << endl
			<< "3. Find the k largest in array recursively" << endl
			<< "4. Sort the array using Quck Sort Method" << endl;
		cin >> choice;

		switch (choice)
			{
				case 1:
					cout << "here is the element in the array displayed recursively" << endl;
					arr.output(0, 9);
					break;
				case 2:
					result = arr.largest(0, 9);
					cout << result << endl;
					break;
				case 3:
					cout << "Please input the value of k.(1~10)" << endl;
					cin >> k;
					result = arr.klargest(k, 0, 9);
					cout << "the k-th largest value is: " << result << endl;
					break;
				case 4:
					arr.QuickSort(0, 9);
					break;
			}

/*=========================program termination================================*/
		cout << "would you like to do something else?(y/n)" << endl;
		cin >> answer;

		if (answer == 'y')
		{
			repeat = true;
			system("cls");
		}
		else if (answer == 'n')
		{
			repeat = false;
			cout << "Thank you for running my program" << endl;
		}
		else
		{
			repeat = false;
			cout << "sorry! your answer is not recognize" << endl;
		}
		
	}
/*=========================program termination================================*/
	cout << "Exiting Program" << endl;
	system("pause");
	return 0;
}
