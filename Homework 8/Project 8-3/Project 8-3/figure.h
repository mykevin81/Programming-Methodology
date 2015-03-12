//figure.h

#ifndef FIGURE_H
#define FIGURE_H

#include<iostream>

class figure
{
	public:
		void draw();
		void erase();
		void center();
};


class square:public figure
{
	private:
		int height;
		int center_point;
};

class circle:public figure
{
	private:
		int radius;
		int center;

};


#endif