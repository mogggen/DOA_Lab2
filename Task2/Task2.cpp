#include "pch.h"
#include <iostream>
constexpr auto SIZE = 256;

using namespace std;

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

void Task2() {
	char arr[SIZE];
	cout << "See if your string is a palindrome: ";
	cin >> arr;


	if (is_palindrome(arr))
		cout << "your text is palindrome" << endl;
	else
		cout << "no palindrome" << endl;
}

int main()
{
	main();
}