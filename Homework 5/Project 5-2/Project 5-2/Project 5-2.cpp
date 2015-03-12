//Project 5-2.cpp: test file for Account
//Author: Kevin Hwang
//ID: 911144369
//Due Date: 10/31/2014
#include <iostream>
#include "account.h"

using namespace std;

int main()
{
	Account account;
	int deposit, answer;
	char r;
	bool repeat = true;
	double amount;

	//repeat loop for continuous transaction
	while (repeat == true)
	{
		cout << "Welcome to BANK, what would you like to do?" << endl;
		cout << "1. Check your balance" << endl;
		cout << "2. Deposit" << endl;
		cout << "3. Withdraw" << endl << "Input: ";
		cin >> answer;
		cout << endl;

		//check for exception
		try
		{
			switch (answer)
			{
				//Check balance
				case 1:
					cout << "Your balance is: " << account.getBalance() << endl << endl;
					break;
				
				//Deposit money
				case 2:
					cout << "How much would you like to deposit" << endl << "Amount: $";
					cin >> amount;
					account.deposit(amount);
					cout << "deposit completed! Your balance is now: " << account.getBalance() << endl << endl;
					break;
				
				//Withdraw money
				case 3:
					cout << "How much would you like to withdraw" << endl << "Amount: $";
					cin >> amount;
					account.withdraw(amount);
					cout << "Transaction completed! Your balance is now " << account.getBalance() << endl << endl;
					break;
			}
		}

		//catch the exception
		catch (exception & e)
		{
			cerr << e.what() << endl;
		}

		cout << "Would you like to continue on other transaction?(y/n)" << endl << "Input: ";
		cin >> r;
		cout << endl;
		if (r == 'y')
		{
			repeat = true;
			system("CLS");
		}
		else
			repeat = false;
	}
	return 0;
}