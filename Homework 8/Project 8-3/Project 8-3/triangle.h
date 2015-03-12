//tringle.h

#ifndef CIRCLE_H
#define CIRCLE_H

#include<iostream>
#include"figure.h"

using namespace std;

class Triangle: public figure
{

	private:
		int height;
		int width;
		int center_point;
};

#endif
