// vector.h : This is the header file for implemented vector class
// or project specific include files that are used frequently, but
// are changed infrequently
//

#ifndef vector_H
#define vector_H

#include<iostream>

using namespace std;

class vector
{
	private:
		double * array;
		int array_size;

	public:

		~vector(); //destructor

		vector(); //default constructor

		vector(int arr_size);	//constructor

		vector(const vector & some_vector); //copy constructor
		
		vector operator=(const vector& rhs); //assignment

		//member functions
		int capacity();
		bool empty();
		void erase(int min_location, int max_location);
		void insert(int location, int insert_size);
		void pop_back();
		void push_back(double num);
		void resize(int size);
		void shrink_to_fit();
		int size();

		void Display_All();

		friend ostream& operator<<(ostream& output, const vector & rhs);
};
#endif