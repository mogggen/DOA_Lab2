#include "pch.h"
#include <iostream>
#include <ctime>
constexpr auto SIZE = 100;

using namespace std;

void array_row_cols(int arr[SIZE][SIZE], int cols, int rows)
{
	int rowSum = 0;
	int colsSum[SIZE];

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

void Task3() {
	srand((unsigned)time(0));
	int rows, cols;
	cout << "Numbers of rows: ";
	cin >> cols;
	cout << "Numbers of columns: ";
	cin >> rows;
	int arr[SIZE][SIZE];
	for (int yy = 0; yy < cols; yy++)
		for (int xx = 0; xx < rows; xx++)
			arr[xx][yy] = rand() % 10;
	array_row_cols(arr, rows, cols);
}

int main()
{
	Task3();
}