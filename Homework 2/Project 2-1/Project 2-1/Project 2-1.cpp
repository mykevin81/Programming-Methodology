// Project 2-1.cpp : Vector Matrix Multiplication. 
////Author: Kevin Hwang   
//ID: 911144369
//Due: 9-24-2014

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void multiply_matrices(vector<vector<int>>A, vector<vector<int>>B)
{
	vector<vector<int> > matrixR;
	
	
	//resizing the result matrix
	matrixR.resize(A.size());
	for (int i = 0; i < A.size(); i++)
	{
		matrixR[i].resize(B[0].size());
	}

	//matrix multiplication;
	for (int k = 0; k < A.size(); k++)
	{
		for (int i = 0; i < B[0].size(); i++)
		{
			for (int j = 0; j < B.size(); j++)
			{
				matrixR[k][i] = A[k][j] * B[j][i];
			}
		}
	}

	//print out all the resulting matrix
	cout << "Here is the result: " << endl;
	for (int i = 0; i < matrixR.size(); i++)
	{
		for (int j = 0; j < matrixR[0].size(); j++)
		{
			cout << matrixR[i][j] << " ";

		}
		cout << endl;
	}
}

int main()
{
	int a_rows, a_cols, b_rows, b_cols;
	vector<vector<int> > matrixA, matrixB;

		cout << "Please input the dimansion for matrix A" << endl << "Row: ";
		cin >> a_rows;
		cout << "Column: ";
		cin >> a_cols;



		cout << "Please input the dimansion for matrix B" << endl << "Row: ";
		cin >> b_rows;
		cout << "Column: ";
		cin >> b_cols;



		//Check if the matrix is multipliable
		if (a_cols != b_rows)
		{
			cout << "Invalid Matrix Dimension" << endl << "please re-enter the matrix dimansion";
			system("pause");
			return 0;
		}

	
	//Resizing matrix A according to user
	matrixA.resize(a_rows);
	for (int i = 0; i < a_rows; i++)
	{
		matrixA[i].resize(a_cols);
	}

	//Resizing matrix B according to user
	matrixB.resize(b_rows);
	for (int i = 0; i < b_rows; i++)
	{
		matrixB[i].resize(b_cols);
	}


	
		//input data for matrix A
		cout << "enter the data for matrix A" << endl;
		for (int i = 0; i < a_rows; i++)
		{
			for (int j = 0; j < a_cols; j++)
			{
				cin >> matrixA[i][j];
				if (!cin)
				{
					cout << "invalid entry, please re-enter matrix A";
				}
			}
			cout << endl;
		}
	

		//input data for matrix B
		cout << "enter the data for matrix B" << endl;
		for (int i = 0; i < b_rows; i++)
		{
			for (int j = 0; j < b_cols; j++)
			{
				cin >> matrixB[i][j];
				if (!cin)
				{
					cout << "invalid entry, please re-enter matrix A";

				}
			}
			cout << endl;
		}

	//calculate and print out the matrix
	multiply_matrices(matrixA, matrixB);

	system("pause");
	return 0;
}




