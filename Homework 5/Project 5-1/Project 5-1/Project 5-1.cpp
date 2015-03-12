// Project 5-1.cpp : Exception practice
//Author: Kevin Hwang
//ID: 911144369
//Due Date: 10/30/2014

#include <iostream>
#include "Product.h"

using namespace std;


int main() // Sample code to test the getProductID function
{
	int productIds[] = { 4, 5, 8, 10, 13 };
	string products[] = { "computer", "flash drive", "mouse", "printer", "camera" };

	//check all for exception
	try
	{
		cout << getProductID(productIds, products, 5, "mouse") << endl;
		cout << getProductID(productIds, products, 5, "camera") << endl;
		cout << getProductID(productIds, products, 5, "laptop") << endl;
	}
	//if exception found output exception error message
	catch (exception & e)
	{
		cerr << e.what() << endl;
	}

	system("pause");
	return 0;
}
