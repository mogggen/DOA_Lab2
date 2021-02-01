#include "pch.h"
#include <iostream>
constexpr auto SIZE = 100;

using namespace std;

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

void Task1() {
	cout << "Pass an integer (0 to end array): ";
	int arr[SIZE];
	for (int i = 0; i < SIZE; i++)
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

int main()
{
	Task1();
}