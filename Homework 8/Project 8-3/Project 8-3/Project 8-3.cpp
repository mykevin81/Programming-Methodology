// Project 8-3.cpp : Defines the entry point for the console application.
//

#include<iostream>

#include "figure.h"

#include "rectangle.h"

#include "triangle.h"

using std::cout;

int main()

{

	Triangle tri;

	tri.draw();



	cout << "\nDerived class Triangle object calling" << " center().\n";

	tri.center();



	Rectangle rect;

	rect.draw();

	cout << "\nDerived class Rectangle object calling" << " center().\n";

	rect.center();

	cout << "============================================================" << endl;
	cout << "Below is the Part II" << endl << endl;

	figure * fig1 = &tri;
	figure * fig2 = &rect;

	fig1->draw();
	fig1->erase();
	cout << "\nDerived class Triangle object calling" << " center().\n";
	fig1->center();

	fig2->draw();
	fig2->erase();
	cout << "\nDerived class Rectangle object calling" << " center().\n";
	fig2->center();



	system("pause");

	return 0;

}