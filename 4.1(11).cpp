#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int n;

	cout << "¬ведите кол-во строк: ";
	cin >> n;

	string *input = new string[n];

	cout << "¬водите строки:\n";

	for (int i = 0; i < n; i++) cin >> input[i];

	for (int i = 0; i < n; i++)
	{
		int j;

		j = 40 - (input[i].length() - 2) / 2;

		for (; j > 0; j--)
		{
			input[i] = " " + input[i];
		}
	}

	for (int i = 0; i < n; i++) cout << input[i] << endl;

	system("pause");

    return 0;
}

