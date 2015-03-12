//account.cpp: cpp file for the account.h
//Author: Kevin Hwang
//ID: 911144369
//Due Date: 10/31/2014

#include "account.h"

using namespace std;

Account::Account() :balance(0)
{

}

Account::Account(double initialDeposit) :balance(initialDeposit)
{

}

double Account::getBalance()
{
	return balance;
}
//return the balance;

double Account::deposit(double amount)throw(Exception_Negative_Deposit)
{
	Exception_Negative_Deposit e;
	if (amount > 0)
	{
		balance += amount;
		return balance;
	}
	else
		throw e;
	// throw exception if deposit amount is negative
}


double Account::withdraw(double amount)throw(Exception_Negative_Withdraw, Exception_Overdraw)
{
	Exception_Negative_Withdraw e1;
	Exception_Overdraw e2;

	if (amount > balance)
		throw e2;
		//throw overdraw exception
	else if (amount < 0)
		throw e1;
		//throw negative withdraw 
	else
	{
		balance -= amount;
		return balance;
	}
}