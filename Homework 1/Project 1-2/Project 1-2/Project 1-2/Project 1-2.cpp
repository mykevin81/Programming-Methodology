// Project 1-2.cpp : Selection Sort Algorithm using vectors
//Author: Kevin Hwang   
//ID: 911144369
//Due: 9-11-2014

#include <iostream>
#include <vector>

using namespace std;
void selectSort(vector<int>& v, int n)
{

	int min, temp;

	for (int i = 0; i < n - 1; i++)
	{
		//set min to the current index of array
		min = i;

		for (int j = i + 1; j < n; j++)
		{

			if (v[j] < v[min])
				min = j;
			//min will keep track of the index that min is in, this is needed when a swap happens
		}

		//swaping
		if (min != i)
		{
			temp = v[i];
			v[i] = v[min];
			v[min] = temp;
		}
	}
}

int main()
{
	int size = 1000;
	vector<int> a(size);

	cout << "enter the size of the vector: ";
	cin >> size;

	cout << "enter each individual integer" << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> a[i];
	}
	selectSort(a, size);

	cout << "The vector have been sorted!! Displaying now" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << endl;
	}
	system("pause");
	return 0;
}