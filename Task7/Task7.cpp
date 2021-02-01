#include "pch.h"
#include "lab2lib.h"
#include <iostream>

using namespace std;

int main()
{
	char input;
	while (true)
	{
		for (int i = 0; i < 8; i++)
		{
			if (i == 0) cout << "Menu:" << endl;
			else if (i == 7) cout << "0: Exit" << endl;
			else cout << i << ": Task " << i << endl;
		}
		cout << "Your choice: ";
		cin >> input;

		switch (input)
		{
		case '1':
			Task1();
			break;

		case '2':
			Task2();
			break;

		case '3':
			Task3();
			break;

		case '4':
			Task4();
			break;

		case '5':
			Task5();
			break;

		case '6':
			Task6();
			break;


		case '0':
			return 0;

		default:
			cout << "There are no such task" << endl;
		}
	}
}