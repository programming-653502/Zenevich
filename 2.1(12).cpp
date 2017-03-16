#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;

void menu();
void rewrite();
void type();
void perimeter();
void area();
void radius();
void author();
void quit();

double A[2], B[2], C[2];
double a, b, c;
double S, p;

void main()
{
	setlocale(LC_ALL, "Russian");

	while (true)
	{
		cout << "������� ���������� ������ ������������ (x,y ����� ������):" << endl;
		cout << "A(x,y): ";
		cin >> A[0] >> A[1];
		cout << "B(x,y): ";
		cin >> B[0] >> B[1];
		cout << "C(x,y): ";
		cin >> C[0] >> C[1];

		a = sqrt(powf((C[0] - B[0]), 2) + powf((C[1] - B[1]), 2));
		b = sqrt(powf((C[0] - A[0]), 2) + powf((C[1] - A[1]), 2));
		c = sqrt(powf((A[0] - B[0]), 2) + powf((A[1] - B[1]), 2));

		p = a + b + c;
		p /= 2;
		S = sqrt(p*(p - a)*(p - b)*(p - c));

		if (S != 0) break;

		cout << "��������� ���������� �� ������������� ������������." << endl;
	}

	cout << "����� ������ ������������:" << endl << "a=" << a << "; b=" << b << "; c=" << c << endl;

	while (true) menu();
}

void menu()
{
	bool looper = true;

	cout << "1. ������ ���������� ������.\n";
	cout << "2. ���������� ���.\n";
	cout << "3. ����� ��������.\n";
	cout << "4. ����� �������.\n";
	cout << "5. ����� ������� �������� � �������� �����������.\n";
	cout << "6. �����.\n";
	cout << "7. �����.\n";
	cout << "�������� ����� ����: ";

	for (; looper;)
	{
		char checker[50], switcher = '0';
		cin >> checker;
		if (strlen(checker) == 1) switcher = checker[0];
		switch (switcher)
		{
		case '1': {rewrite(); looper = false; break; };
		case '2': {type(); looper = false; break; };
		case '3': {perimeter(); looper = false; break; };
		case '4': {area(); looper = false; break; };
		case '5': {radius(); looper = false; break; };
		case '6': {author(); looper = false; break; };
		case '7': {quit(); looper = false; break; };
		default:  {cout << "�������� ����: "; continue; };
		};
	}
}

void rewrite()
{
	cout << "������� ���������� ������ ������������:" << endl;
	cout << "A(x,y): ";
	cin >> A[0] >> A[1];
	cout << "B(x,y): ";
	cin >> B[0] >> B[1];
	cout << "C(x,y): ";
	cin >> C[0] >> C[1];

	a = sqrt(powf((C[0] - B[0]), 2) + powf((C[1] - B[1]), 2));
	b = sqrt(powf((C[0] - A[0]), 2) + powf((C[1] - A[1]), 2));
	c = sqrt(powf((A[0] - B[0]), 2) + powf((A[1] - B[1]), 2));

	cout << "����� ������ ������������:" << endl << "a=" << a << "; b=" << b << "; c=" << c << endl;

	menu();
}

void type()
{
	if (a == b == c) cout << "����������� ����������";
	else if ((a == b) || (a == c) || (b == c)) cout << "����������� ��������������";
	else cout << "����������� ��������������";

	if ((powf(a, 2) == powf(b, 2) + powf(c, 2)) || (powf(b, 2) == powf(a, 2) + powf(c, 2)) || (powf(c, 2) == powf(b, 2) + powf(a, 2))) cout << " � �������������." << endl;
	else cout << "." << endl;
}

void perimeter()
{
	double P;

	P = a + b + c;

	cout << "�������� ������������: " << P << endl;
}

void area()
{
	cout << "������� ������������: " << S << endl;
}

void radius()
{
	double R, r;

	R = a*b*c / S / 4;
	r = S / p;

	cout << "������ �������� ����������: " << r << endl;
	cout << "������ �������� ����������: " << R << endl;
}

void author()
{
	cout << "�����: Zinya the Slayer" << endl;
	cout << "�������: ������� �������" << endl;
	cout << "������: 653502" << endl;
	cout << "������: PreRelease 0.1 (��� �������� �� ���� ����-�)" << endl;
}

void quit()
{
	exit(0);
}