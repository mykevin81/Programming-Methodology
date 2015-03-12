#include<iostream>
#include"figure.h"
#include"rectangle.h"
#include"triangle.h"


void figure::draw()
{
	cout << "Calling Figure::draw()" << endl;
}

void figure::erase()
{
	cout << "Calling Figure::erase()" << endl;
}

void figure::center()
{
	draw();
	erase();
	cout << "center is being called" << endl;
}