// Project 2-2.cpp : Merge the three files into one
//Name: Kevin Hwang
//ID: 911144369
//Due Date:9/24/2014

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void sort(string text1, string text2, string text3)
{
	int max=0;
	string line;

	ifstream file;


	
	file.open(text1);
	if (file.is_open())
	{
		while (getline(file, line))
		{
			if (stoi(line) > max)
			{
				max = stoi(line);
			}
		}
		file.close();
	}
	
	//----------------------------
	file.open(text2);
	if (file.is_open())
	{
		while (getline(file, line))
		{
			if (stoi(line) > max)
			{
				max = stoi(line);
			}
		}
		file.close();
	}
	
	//------------------------------
	file.open(text3);
	if (file.is_open())
	{
		while (getline(file, line))
		{
			if (stoi(line) > max)
			{
				max = stoi(line);
			}
		}
		file.close();
	}
	

	else cout << "Unable to open file";
	cout << max << endl;

	ofstream outPut;
	ofstream("Result.txt");
	outPut.open("Result.txt");


	//enter the collective data into the result
	for (int i = 0; i <= max; i++)
	{
		file.open(text1);
		while (getline(file, line))
			{
			if (stoi(line) == i)
				{
					outPut << i << endl;
				}
			}
		file.close();
		//-------------------------------
		file.open(text2);
		while (getline(file, line))
		{
			if (stoi(line) == i)
			{
				outPut << i << endl;
			}
		}
		file.close();
		//------------------------------
		file.open(text3);
		while (getline(file, line))
		{
			if (stoi(line) == i)
			{
				outPut << i << endl;
			}
		}
		file.close();
	}

	//close all files
	outPut.close();
	
	


	

}

int main()
{
	string txt1, txt2, txt3;
	
	//ask user for the file name
	cout << "Please enter the name of first file: ";
	getline (cin,txt1);
	txt1 = txt1 + ".txt";
	cout << "Please enter the name of second file: ";
	getline(cin, txt2);
	txt2 = txt2 + ".txt";
	cout << "Please enter the name of third file: ";
	getline (cin, txt3);
	txt3 = txt3 + ".txt";

	sort(txt1, txt2, txt3);

	cout << "The result will be in Result.txt" << endl;

	system("pause");

	return 0;
}
