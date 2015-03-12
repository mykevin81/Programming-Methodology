//Description: Declear the header file for exception
//Author: Kevin Hwang
//ID: 911144369
//Due Date: 10/30/2014

#include<iostream>
#include"Product.h"

using namespace std;

int getProductID(int ids[], string names[], int numProducts, string target) throw(Exception_ID_Not_Found)
{
	Exception_ID_Not_Found e;

	for (int i = 0; i < numProducts; i++)
	{
		if (names[i] == target)
			return ids[i];
	}
	

	bool r = false;
	//If there is no product found, throw exception
	if (r == false)
	{
		throw e;
	}
}


