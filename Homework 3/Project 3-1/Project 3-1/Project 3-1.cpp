// Project 3-1.cpp : add word using seekg & seekp
//Name: Kevin Hwang
//ID: 911144369
//Due Date: 10/03/2014

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	string line;
	string temp;
	
	//open the file to with parameters
	fstream file("file1.txt", ios::in | ios::out);

	if (!file.is_open())
		cout << "File read error!" << endl;

	else
	{
		
		//find the missing start and end
		file.seekg(120);
		
		//use seekg() to get everything after 24 into a string
		while (!file.eof())
		{ 
			getline(file, temp);
			line = line + temp + '\n';
		}

		
		file.close();

		//use seekp() to add 25 ~ 70 into the file
		file.open("file1.txt");
		file.seekp(120);
				

		for (int i = 25; i < 71; i++)
		{
			file.width(5);
			cout.width(5);
			file << to_string(i) + '\n';
		}
		file.close();
		
		//insert the stored string at the end of the file
		file.open("file1.txt");
		file.seekp(0, ios::end);
		file << line;
		file.close();
	}


	
	system("pause");
	return 0;
}

