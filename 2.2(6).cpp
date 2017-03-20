#include "stdafx.h"
#include <iostream>

using namespace std;

double iterative_sin(double e, double x, int& i)
{
	double sum = 0;
	double term = x;

	do
	{
		sum += term;
		term *= -x * x / ((2 * i) * (2 * i + 1));
		i++;
	} while (abs(sin(x) - sum) >= e);

	return sum;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	double e;
	double x;
	cout << "Введите е от 0 до 1 (или символ для выхода): ";
	while (cin >> e)
	{
		if (e > 0 && e < 1)
		{
			cout << "Введите x в радианах (от -6.28 до 6.28): ";
			if (cin >> x)
			{
				if (x >= -6.28 && x <= 6.28)
				{
					int i = 1;

					cout << "Левая часть: " << sin(x) << endl;
					cout << "Правая часть: " << iterative_sin(e, x, i) << endl;
					cout << "n: " << i << endl;
				}
				else cout << "Неверный ввод х!" << endl;
			}

		}
		else cout << "Неверный ввод е!" << endl;

		cout << "Введите е от 0 до 1 (или символ для выхода): ";
	}

	return 0;
}
