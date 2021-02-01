#include "pch.h"
#include <iostream>
constexpr auto LENGTH = 100;;

using namespace std;

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

void Task5() {
	cout << "Pass an int to the array(0 to finish array): ";
	int arr[LENGTH];
	for (int i = 0; i < LENGTH; i++)
	{
		cin >> arr[i];
		if (arr[i] == 0)
		{
			shrink_array(arr, i);
			cout << endl;
			break;
		}
	}
}

int main()
{
	Task5();
}