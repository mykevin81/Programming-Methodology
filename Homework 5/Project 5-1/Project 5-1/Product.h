//Description: Declear the header file for exception
//Author: Kevin Hwang
//ID: 911144369
//Due Date: 10/30/2014
#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <stdexcept>

using namespace std;


class Exception_ID_Not_Found: public exception
{

	public:
		virtual const char* what() const throw()
		{
			//the output message for exception
			return "Product not found!";
		}
		
		
	
};

int getProductID(int ids[], string names[], int numProducts, string target) throw(Exception_ID_Not_Found);

#endif