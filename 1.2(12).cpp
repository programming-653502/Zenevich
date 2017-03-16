#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	unsigned int m, n = 1, t = 1;
	char b[50] = "", a[50] = "";
	bool c = true;

	for (; c;)
	{
		c = false;
		cout << "Введите натуральное число: ";
		cin >> a;

		for (int i = 0; i < strlen(a); i++)
			if (a[i]<'0' || a[i]>'9')
			{
				c = true;
				break;
			}

		if (!c) m = atoi(a);
		if (m == 0) c = true;
	}
	
	cout << "Результат вычислений:" << endl;

	for (;;)
	{
		t *= 2;
		n = t - 1;
		if (n > m) break;
		_itoa_s(n, b, 2);
		cout << n << "\t" << b << endl;
	}

	system("pause");
	return 0;
} 
