#include<iostream>
#include"linkedList_structNode.h"
#include"LinkedList_structNode_Exceptions.h"

using namespace std;

int main()
{
	List alist;
	List blist;

	for (int i = 0; i < 5; i++)
	{
		alist.insert(i, i + 1);
	}

	blist = alist;
	cout << alist;

	alist.reverse();

	cout << alist;
	cout << blist;

	system("pause");

	return 0;

}