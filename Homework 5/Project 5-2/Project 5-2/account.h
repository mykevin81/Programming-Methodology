//Account.h: header file for Account
//Author: Kevin Hwang
//ID: 911144369
//Due Date: 10/31/2014
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include<stdexcept>
#include<iostream>

using namespace std;

class Account{
private:
	double balance;
public:
	
	Account();

	Account(double initialDeposit);

	double getBalance();

	double deposit(double amount);

	double withdraw(double amount);
};

class Exception_Negative_Deposit : public exception
{

public:
	virtual const char* what() const throw()
	{
		//the output message for exception
		return "Error Code 5: Deposit amount is negative!";
	}
};

class Exception_Overdraw : public exception
{

public:
	virtual const char* what() const throw()
	{
		//the output message for exception
		return "Error code 8: Account overdraw!";
	}
};

class Exception_Negative_Withdraw : public exception
{

public:
	virtual const char* what() const throw()
	{
		//the output message for exception
		return "Error Code 13: Withdraw amount is negative!";
	}
};



#endif