// 
//


#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include "Polynomial.h"



Polynomial::Polynomial()
{
	//default constructor
}

//polynomial constructor
Polynomial::Polynomial(vector<int> sign2, vector<int> Coef2, vector<int> Power2)
{
	Sign.resize(sign2.size());
	Coef.resize(Coef2.size());
	Power.resize(Power2.size());
	for (int i = 0; i < Coef.size(); i++)
	{
		Coef[i] = Coef2[i];
		Power[i] = Power2[i];
	}
}

//display the largest power
int Polynomial::degree(Polynomial P)
{
	return P.Power[0];
}

//find the power and return the ciefficient
int Polynomial::coefficient(int power)
{
	//loop through Power vector
	for (int i = 0; i < Power.size(); i++)
	{
		if (Power[i] == power)
		{
			return Coef[i];
		}
	}
}

//find the corresponding power and change the coefficient
void Polynomial::changeCoefficient(int newCoefficient, int power)
{
	for (int i = 0; i < Power.size(); i++)
	{
		if (Power[i] == power)
			Coef[i] = newCoefficient;
	}
}

//multiply all the coefficient by the scalar
void Polynomial::multiply(int scalar)
{
	for (int i = 0; i < Coef.size(); i++)
	{
		Coef[i] = Coef[i] * scalar;
	}
}

void Polynomial::add(Polynomial p1, Polynomial p2)
{
	for (int i = 0; i < Power.size(); i++)
	{
		//check if same power
		if (p1.Power[i] == p2.Power[i])
		{
			//add together if sign is same
			if (p1.Sign[i] == p2.Sign[i])
				Coef[i] = p1.Coef[i] + p2.Coef[i];
			else
				Coef[i] = p1.Coef[i] - p2.Coef[i];
		}
		else if (p1.Power[i] > p2.Power[i])
				Coef = Coef.insert (i, p1.Coef[i]);
		else
			Coef = Coef.insert(i, p2.Coef[i]);
	}


}

//Done
void Polynomial::print()  
{
	//if nothing exists
	if (Power.size() == 0) {
		return;
	}
	//loop through all and cout all
	for (int i = 0; i < Power.size(); i++)
		cout << Sign[i] << Coef[i] << "X^" << Power[i];
	cout << Coef[0];
}

//Overload operand
Polynomial Polynomial::operator / (int scalar)
{
	vector<int>new_sign;
	vector<int>new_coef;
	vector<int>new_power;

	new_sign.resize(Sign.size());
	new_coef.resize(Coef.size());
	new_power.resize(Power.size());

	for (int i = 0; i < Coef.size(); i++)
	{
		new_sign[i] = Sign[i];
		new_coef[i] = Coef[i] / scalar;
		 new_power[i] = Power[i];
	}

	Polynomial result(new_sign, new_coef, new_power);
	return result;
}

Polynomial Polynomial::operator-() const
{
	vector<int>new_sign;
	vector<int>new_coef;
	vector<int>new_power;

	new_sign.resize(Sign.size());
	new_coef.resize(Coef.size());
	new_power.resize(Power.size());

	for (int i = 0; i < Sign.size(); i++)
	{
		if (Sign[i] == '+')
			new_sign[i] = '-';
		else if (Sign[i] == '-')
			new_sign[i] = '+';
		new_coef[i] = Coef[i];
		new_power[i] = Power[i];
	}

	Polynomial result(new_sign, new_coef, new_power);
	return result;
	
}

ostream& operator<<(ostream& out, const Polynomial& p1)
{
	out << p1.Sign << p1.Coef << "x^" << p1.Power;
}
