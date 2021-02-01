#include "lab2lib.h"
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

void Task1()
{
	cout << "Pass an integer (0 to end array): ";
	int arr[256];
	for (int i = 0; i < 256; i++)
	{
		cin >> arr[i];
		if (arr[i] == 0)
		{
			break;
		}

	}

	if (is_sorted(arr, sizeof arr / sizeof *arr))
		cout << "sorted array" << endl;
	else
		cout << "shuffled array" << endl;
}
bool is_sorted(int arr[], int length)
{
	int cur = arr[0];

	for (int i = 1; i < length; i++)
	{
		if (arr[i] >= cur)
			cur = arr[i];
		else if (arr[i] == 0) break;
		else
			return false;
	}
	return true;
}

void Task2()
{
	char arr[256];
	cout << "See if your string is a palindrome: ";
	cin >> arr;


	if (is_palindrome(arr))
		cout << "your text is palindrome" << endl;
	else
		cout << "no palindrome" << endl;
}
bool is_palindrome(char txt[])
{
	int length = 0;
	while (txt[length] != '\0') length++;

	for (int i = 0; i < length - i - 1; i++)
	{
		if (txt[i] != txt[length - i - 1])
			return false;
	}

	return true;
}

void Task3() {
	srand((unsigned)time(0));
	int rows, cols;
	cout << "Numbers of rows: ";
	cin >> cols;
	cout << "Numbers of columns: ";
	cin >> rows;
	int arr[256][256];
	for (int yy = 0; yy < cols; yy++)
		for (int xx = 0; xx < rows; xx++)
			arr[xx][yy] = rand() % 10;
	array_row_cols(arr, rows, cols);
}
void array_row_cols(int arr[256][256], int cols, int rows)
{
	int rowSum = 0;
	int colsSum[256];

	for (int y = 0; y < rows + 1; y++)
	{
		rowSum = 0;
		for (int x = 0; x < cols + 1; x++)
		{
			if (y < rows)
			{
				if (x < cols)
				{
					rowSum += arr[x][y];
					if (y == 0)
						colsSum[x] = arr[x][y];
					else
						colsSum[x] += arr[x][y];
					cout << arr[x][y] << "\t";
				}
				else
				{
					if (y == 0)
						colsSum[x] = rowSum;
					else
						colsSum[x] += rowSum;
					cout << rowSum << "\t";
				}
			}
			else
			{
				if (x < cols)
				{
					cout << colsSum[x] << "\t";
					rowSum += colsSum[x];
				}
				else
					cout << colsSum[x] + rowSum << "\t"; // or just take 2 * all colsSum, duh!
			}
		}
		cout << endl;
	}
}

void Task4()
{
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

void Task5()
{
	constexpr auto LENGTH = 100;
	cout << "Pass an int to the array(0 to finish array): ";
	int arr[LENGTH];
	for (int i = 0; i < LENGTH; i++)
	{
		cin >> arr[i];
		if (arr[i] == 0)
		{
			shrink_array(arr, i);
			break;
		}
	}
}
void shrink_array(int *arr, int length)
{
	//sum up the pairs
	for (int i = 0; i < length; i += 2)
	{
		arr[i] += arr[i + 1];
		arr[i + 1] = 0;
	}

	int index = 0;
	bool found0 = false;

	//move all sums left-most
	for (int i = 0; i < length; i++)
	{
		if (arr[i] == 0 && !found0)
		{
			index = i;
			found0 = true;
		}
		else if (arr[i] != 0 && found0)
		{
			arr[index] = arr[i];
			arr[i] = 0;
			index = 0;
			i = index;
			found0 = false;
		}
	}

	for (int i = 0; i < length; i++)
		cout << arr[i] << "\t";
}

void Task6() {
	char choise;
	vector<string> vect;

	while (true)
	{
		cout << "Menu:\n1. initialise database\n2. insert\n3. search\n4. delete\n5. print\n6. quit\n";
		cout << "Make your choice: ";
		cin >> choise;

		switch (choise)
		{
		case '1':
			bool certain;
			cout << "are you sure?\n1: yes\n0: no\n";
			cin >> certain;
			if (certain)
				vect.clear();

			break;

		case '2':
		{
			string name;
			cout << "enter a name (q/Q to stop): ";
			while (true)
			{

				cin >> name;
				if (name != "Q" && name != "q")
					vect.push_back(name);
				else
					break;
			}
			break;
		}

		case '3':
		{
			cout << "Search for a name (or parts of it): ";
			string search;
			cin >> search;
			for (unsigned j = 0; j < vect.size(); j++)
			{
				for (unsigned i = 0; i < vect[j].length() - search.length() + 1; i++)
				{
					if (vect[j].substr(i, search.length()) == search)
					{
						cout << vect[j] << endl;
						break;
					}
				}
			}
			break;
		}

		case '4':
		{
			string del;
			cin >> del;
			int first = vect.size();
			for (unsigned i = 0; i < vect.size(); i++)
				if (vect[i] == del) vect.erase(vect.begin() + i);
			if (vect.size() == first)
				cout << "Name not found!" << endl;
			break;
		}

		case '5':
			for (unsigned i = 0; i < vect.size(); i++)
				cout << vect[i] << endl;
			break;

		case '6':
			break;

		default:
			cout << "please enter a number between 1-6 as a choise.";
		}

		if (choise == '6') break;
	}
}

