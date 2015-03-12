#ifndef RECTANGLE_H
#define RECTANGLE_H

#include<iostream>
#include"figure.h"

using namespace std;

class Rectangle:public figure
{

	private:
		int height;
		int weight;
		int center_point;
};

#endif