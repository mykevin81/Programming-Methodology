//Recursion.cpp: the implement file for the Recursion.h file


#include <iostream>
#include "Recursion.h"

using namespace std;

recursion::recursion() :array()
{
	//default constructor
}

void recursion::input()
{
	cout << "Please enter 10 integer" << endl;
	for (int i = 0; i < 10; i++)
	{
		cin >> array[i];
	}
}

void recursion::output(int first, int last)
{
	//base case
	if (first == last)
		cout << array[first] << endl;

	//recursion
	else if (first < last)
	{
		output(first + 1, last);
		cout << array[first] << endl;
	}

}

int recursion::largest(int index, int size)
{
	// base case
	if (index == size)
		return array[index];

	// Call the function recursively
	int result = largest(index + 1, size);

	//return the largest
	if (array[index] > result)
		return array[index];
	else
		return result;
}

int recursion::klargest(int k, int first, int last)
{
	//base case
	if (first == last && k == first + 1) 
		return array[first];
	
	else if (array[first] < array[last] && k < last + 1) 
		return klargest(k + 1, first + 1, last);

	else if (array[first] > array[last] && k == last + 1)
		return array[first];
	else if (array[first] > array[last] && k < last + 1)
		return klargest(k + 1, first + 1, last - 1);
}

/*=========================Optional Extra function================================*/

void recursion::QuickSort(int startIndex, int endIndex)
{
	int middle;
	if (startIndex < endIndex)
	{
		middle = partition(startIndex, endIndex);
		QuickSort(startIndex, middle);   // sort first section
		QuickSort(middle + 1, endIndex);    // sort second section
	}
	return;
}

int recursion::partition(int startIndex, int endIndex)
{
	int x = array[startIndex];
	int i = startIndex - 1;
	int j = endIndex + 1;
	int temp;
	do
	{
		do
		{
			j --;
		} while (x >array[j]);

		do
		{
			i++;
		} while (x <array[i]);

		if (i < j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	} while (i < j);
	return j;           // returns middle subscript  
}



ostream& operator<<(ostream& outS, const recursion& rhs)
{
	for (int i = 0; i < 10; i++)
	{
		outS << rhs.array[i] << ", ";
	}

	return outS;
}

