// vector.cpp : source file that includes just the standard includes
// Project 1.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "vector.h"
#include<iostream>

using namespace std;


vector::~vector()  //destructor
{
	if (array != NULL)
	{
		delete[] array;
		array = NULL;
		array_size = 0;
	}
}

vector::vector():array(NULL),array_size(0) //default constructor
{
	//intentionally left empty
}

vector::vector(int arr_size) //constructor
{
	array_size = arr_size;
	array = new double[array_size];
}

vector::vector(const vector & some_vector)  //copy constructor
{
	array_size = some_vector.array_size;
	
	if (array_size <= 0)
		array = NULL;
	else
		array = new double[array_size];
	
	for (int i = 0; i < array_size; i++)
	{
		array[i] = some_vector.array[i];
	}
}

vector vector::operator=(const vector& rhs)  //assignment
{
	if (array_size > 0)
		delete[] array; //remove old memory

	array_size = rhs.array_size;
	if (array_size <= 0)
		array = NULL;
	else
		array = new double[array_size];
	for (int i = 0; i < array_size; i++)
	{
		array[i] = rhs.array[i];
	}

	return(*this);
}


//--------------member functions----------------------\\

int vector::capacity()  //Returns the number of elements that the vector could store without allocating more storage.
{
	return array_size;
}

bool vector::empty()	//Tests if the vector container is empty.
{

	for (int i = 0; i < array_size; i++)
	{
		if (array[i] != NULL)
			return false;
	}

	return true;
	
}

void vector::erase(int min_index, int max_index)	//Removes an element or a range of elements in a vector from the specified positions.
{
	int difference = max_index - min_index;
	
	//erase the targeted array element
	for (int i = min_index - 1; i < max_index; i++)
	{
		array[i] = NULL;
	}

	//fill the gaps
	for (int i = max_index; i < size() - max_index; i++)
	{
		array[max_index - difference] = array[i];			
	}

}

void vector::insert(int index, int insert_size)	//Inserts an element or a number of elements into the vector at a specified position.
{

	resize(capacity() + insert_size);	//add the space needed for the range of items

	int temp_size = insert_size + size() - index + 1;

	//create a temp array to store after
	double * temp_array;
	temp_array = new double[temp_size];


	cout << "Enter the " << insert_size << " element(s)" << endl;
	for (int i = 0; i < insert_size; i++)
	{
		cin >> temp_array[i];
	}
	

	//copy the rest into temp_array
	for (int i = index; i < size();i++)
	{
		temp_array[insert_size - index + i] = array[i - 1];
	}

	//put all temp array back to array
	for (int i = 0; i < temp_size;i++)
	{
		array[index + i - 1] = temp_array[i];
	}


}

void vector::pop_back()	//Deletes the element at the end of the vector.
{
	array[size()-1] = NULL;
}

void vector::push_back(double element)	//Adds an element to the end of the vector.
{
	
	//check if more space is needed
	if (size() == capacity())
	{
		resize(capacity() + 1);
	}

	//push_back element
	array[size()] = element;

}

void vector::resize(int size)	//Specifies a new size for a vector.
{
	if (size < 0)
	{
		cout << "size cannot be less then 0" << endl;
		return;
	}
	
	//case1: shrinking array
	if (array_size > size)
	{
		//create a temp array to store after
		double * temp_array;
		temp_array = new double[size];

		for (int i = 0; i < size; i++)
		{
			temp_array[i] = array[i];
		}
		//resize the array
		array = new double[size];
		array_size = size;

		//clean the memory
		for (int i = 0; i < size; i++)
		{
			array[i] = NULL;
		}

		//put all element back to the array
		for (int i = 0; i < array_size; i++)
		{
			array[i] = temp_array[i];
		}
	}
	
	//case2: enlarge array
	else if (array_size < size)
	{
		int old_array_size = array_size;

		//create a temp array to store after
		double * temp_array;
		temp_array = new double[old_array_size];

		for (int i = 0; i < old_array_size; i++)
		{
			temp_array[i] = array[i];
		}
		//resize the array
		array = new double[size];
		array_size = size;

		//clean the memory
		for (int i = 0; i < size; i++)
		{
			array[i] = NULL;
		}

		//put all element back to the array
		for (int i = 0; i < old_array_size; i++)
		{
			array[i] = temp_array[i];
		}
	}

	//case3: when size == array_size
	else
		cout << "The array size is already " << size << endl;
}

void vector::shrink_to_fit()	//Discards excess capacity.
{
	resize(size());
}

int vector::size()			//Returns the number of elements stored in the vector.
{
	int count = 0;

	for (int i = 0; i < array_size; i++)
	{
		if (array[i] != NULL)
			count++;
	}

	return count;
}

void vector::Display_All()
{
	for (int i = 0; i < size(); i++)
	{
		cout << array[i] << endl;
	}
}

ostream& operator<<(ostream& output, const vector& rhs)		//output the elements in a vector.
{
	output << rhs.array;

	return output;
}