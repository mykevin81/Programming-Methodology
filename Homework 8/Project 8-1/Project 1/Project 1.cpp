// Project 1.cpp : Defines the entry point for the console application.
//

#include<iostream>
#include"vector.h"

using namespace std;

int main()
{
	vector v1(0);
	bool repeat = true;
	int answer;
	int index;
	int index2;
	double element;
	char again;
	bool check;
	
	while (repeat == true)
	{
		cout << "what would you like to do?" << endl << endl;

		cout << "1. See the capacity of this array." << endl;
		cout << "2. Check if the array is empty." << endl;
		cout << "3. Erase one or multiple array elements." << endl;
		cout << "4. Insert element(s) at certain index." << endl;
		cout << "5. Delete the last element." << endl;
		cout << "6. Add an element at the end of array." << endl;
		cout << "7. Resize the array." << endl;
		cout << "8. Discards excess capacity." << endl;
		cout << "9. See the number of element in the array." << endl;
		cout << "10. Display every element in the array." << endl;
		cout << "-----------------------------------------" << endl;

		cin >> answer;

		switch (answer)
		{
			case 1:
				index = v1.capacity();
				cout << "The array can hold up to " << index << " element(s)" << endl;
				break;
			
			case 2:
				check = v1.empty();
				if (check == true)
					cout << "The array is empty" << endl;
				else
					cout << "The array is not empty" << endl;
				break;

			case 3:
				cout << "1. single element" << endl << "2. multiple element" << endl;
				cin >> answer;
				if (answer == 1)
				{
					cout << "enter the target index" << endl;
					cin >> index;
					v1.erase(index, index);
				}
				else if (answer == 2)
				{
					cout << "enter the minimum target index" << endl;
					cin >> index;
					cout << "enter the maximum target index" << endl;
					cin >> index2;

					v1.erase(index, index2);
				}

				break;

			case 4:
				cout << "Enter the target index" << endl;
				cin >> index;
				cout << "Enter the number of elements you want to insert" << endl;
				cin >> index2;

				v1.insert(index, index2);
				break;

			case 5:
				v1.pop_back();
				break;

			case 6:
				cout << "Enter the number that you want to insert" << endl;
				cin >> element;
				v1.push_back(element);
				break;
			case 7:
				cout << "Enter the new size" << endl;
				cin >> index;
				v1.resize(index);
				break;

			case 8:
				v1.shrink_to_fit();
				break;

			case 9:
				index = v1.size();
				cout << "There are " << index << " element(s) in this array" << endl;
				break;

			case 10:
				v1.Display_All();
		}
	

		cout << "would you like to do something else?(y/n)" << endl;
		cin >> again;
		if (again == 'n')
			repeat = false;
		else
			repeat = true;

		system("CLS");
	}


	system("pause");
	return 0;
}