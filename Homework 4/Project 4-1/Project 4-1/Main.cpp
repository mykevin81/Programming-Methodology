
#include<iostream>
#include<vector>
#include"Polynomial.h"

using namespace std;



int main()
{
	string again;
	bool repeat = true;
	int answer, size;
	char sign;
	
	cout << "Please input how many items in the polynomial" << endl;
	cin >> size;
	
	vector<int>new_sign;
	vector<int>new_coef;
	vector<int>new_power;

	new_sign.resize(size);
	new_coef.resize(size);
	new_power.resize(size);
	//input all the coefficient and power vector
	for (int i = 0; i < size; i++)
	{
		cout << "Enter the " << i + 1 << "st term of sign: ";
		cin >> sign;
		new_sign[i] = sign;
		cout << "Enter the " << i + 1 << "st term of coefficient: ";
		cin >> answer;
		new_coef[i] = answer;
		cout << "Enter the " << i + 1 << "st term of power: ";
		cin >> answer;
		new_power[i] = answer;
	}

	Polynomial poly(new_sign, new_coef, new_power);
	
	

	while (repeat == true)
	{
		cout << endl << "What would you like to do" << endl << endl;

		cout << "1. Display the degree of polynomial" << endl
			<< "2. Display the coefficient of a certain power" << endl
			<< "3. Change the coefficient of a certain power" << endl
			<< "4. Multiply the polynomial by a scalar" << endl
			<< "5. Add two polynomial together" << endl
			<< "6. Print the polynomial" << endl;
		cin >> answer;

		switch (answer)
		{
			//display degree
			case 1:
				poly.degree(poly);
				break;
			
			//display coefficient
			case 2:
				cout << "please enter the power: ";
				cin >> answer;
				poly.coefficient(answer);
				break;
			
			//change the coefficient
			case 3:
				int c, p;
				cout << "please enter the power: ";
				cin >> p;
				cout << "please enter the new coefficient: ";
				cin >> c;
				poly.changeCoefficient(c, p);
				break;
			
			//multiply the polynomial
			case 4:
				cout << "please enter the scalar: ";
				cin >> answer;
				poly.multiply(answer);
				break;
			
			//add two together
			case 5:
				poly.add;
				break;

			//print the polynomial
			case 6:
				poly.print();
				break;
		}

		cout << "Back to main menu?(yes/no)" << endl;
		cin >> again;
		if (again == "no")
			repeat = false;
		else
			repeat = true;
	}
	
	system("pause");
	return 0;
}