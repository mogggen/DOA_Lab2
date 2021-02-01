#include "pch.h"
#include <iostream>

using namespace std;

void swap_sort(int &a, int &b, int &c, bool order)
{
	int temp;
		if (order)
		{
			if (b < a)
			{
				temp = a;
				a = b;
				b = temp;
			}
			if (c < b)
			{
				temp = b;
				b = c;
				c = temp;
			}
			if (b < a)
			{
				temp = a;
				a = b;
				b = temp;
			}
		}
		else
		{
			if (c > b)
			{
				temp = b;
				b = c;
				c = temp;
			}
			if (b > a)
			{
				temp = a;
				a = b;
				b = temp;
			}
			if (c > b)
			{
				temp = b;
				b = c;
				c = temp;
			}
		}
}

void Task4() {
	while (true)
	{
		int a, b, c;
		bool order;

		cout << "give a (or 0 to quit): ";
		cin >> a;
		if (a == 0) break;
		cout << "give b: ";
		cin >> b;
		cout << "give c: ";
		cin >> c;
		cout << "sort in ascending/descending order(1/0): ";
		cin >> order;

		swap_sort(a, b, c, order);
		cout << a << "," << b << "," << c << endl;
	}
	cout << "Bye bye!" << endl;
}

int main()
{
	Task4();
}