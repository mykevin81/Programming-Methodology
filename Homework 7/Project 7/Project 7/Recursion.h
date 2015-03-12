// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#ifndef RECURSION_H
#define RECURSION_H

#include <iostream>

using namespace std;

class recursion
{
	private:
		int array[10];
	public:
		//default constructor
		recursion();
			
		void input();									//ask user to input integer in fixed-size array
		void output(int first, int last);				//recursively output the array
		int largest(int index, int size);				//recursively find largest in array
		int klargest(int k, int first, int last);		//recursively find largest k-th element

		//optional
		void QuickSort(int startIndex, int endIndex);
		int partition(int startIndex, int endIndex);
		friend ostream& operator<<(ostream&  outS, const recursion& rhs);
};

#endif