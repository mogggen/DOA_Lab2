#include "pch.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	Task6();
}

void Task6(){
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