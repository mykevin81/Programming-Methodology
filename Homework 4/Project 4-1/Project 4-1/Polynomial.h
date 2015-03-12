#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include<string>
#include<vector>

using namespace std;

class Polynomial{

private:
	vector <int> Sign;	//array for sign
	vector <int> Coef;	//array for coefficient
	vector <int> Power;	//array for power
	
public:
		Polynomial(); //Default constructor

		Polynomial(vector<int>sign, vector<int>Coef2, vector<int>Power2);

		void convert(string input);
		int degree(Polynomial P);
		int coefficient(int power);
		void changeCoefficient(int newCoefficient, int power);
		void multiply(int scalar);
		void add(Polynomial p1, Polynomial p2);
		void print();

		//Overload Operators
		Polynomial operator / (int scalar);
		Polynomial operator - () const;
		friend ostream& operator<<(ostream& out, const Polynomial& P);

};
#endif