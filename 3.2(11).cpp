#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void menu();
void resize();
void rebuild();
void map();
void insert();
void pathfinder(int i, int j);
void author();

char **labyrinth;
int n;
bool quit;
int i, j;

void main()
{
	setlocale(LC_ALL, "Russian");

	resize();
	rebuild();

	while (true) menu();
}

void menu()
{
	bool looper = true;

	cout << "1. Изменить размерность.\n";
	cout << "2. Перестроить.\n";
	cout << "3. Показать карту.\n";
	cout << "4. Найти выход.\n";
	cout << "5. Автор.\n";
	cout << "0. Выйти.\n";
	cout << "Выберите пункт меню: ";

	while (looper)
	{
		char checker[50], switcher = NULL;
		cin >> checker;
		if (strlen(checker) == 1) switcher = checker[0];
		switch (switcher)
		{
		case '1': {resize(); rebuild(); looper = false; break; };
		case '2': {rebuild(); looper = false; break; };
		case '3': {map(); looper = false; break; };
		case '4': {insert(); pathfinder(i - 1, j - 1); if (!quit) cout << "Из заданой точки нельзя покинуть лабиринт." << endl << "Перед повторным поиском перестройте лабиринт." << endl; looper = false; break; };
		case '5': {author(); looper = false; break; };
		case '0': {exit(0); looper = false; break; };
		default: {cout << "Повтрите ввод: "; continue; };
		};
	}
}

void resize()
{
	cout << "Введите размерность лабиринта: ";
	cin >> n;

	labyrinth = new char*[n];
	for (int i = 0; i < n; i++)
		labyrinth[i] = new char[n];
}

void rebuild()
{
	cout << "Введите плотность лабиринта (процент непроходимых клеток): ";

	int density;
	cin >> density;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			labyrinth[i][j] = (rand() % 100 > density) ? '.' : 'H';
}

void map()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << labyrinth[i][j];
		cout << endl;
	}
	cout << endl;
}

void insert()
{
	cout << "Введите точку начала пути (x,y): ";
	cin >> i >> j;
	quit = false;
}

void pathfinder(int i, int j)
{
	int overheat = 0;
	if (labyrinth[i][j] == 'H')
	{
		cout << "Поле непроходимо." <<  endl;
		quit = true;
	}

	while (!quit && overheat < 5)
	{
		if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
		{
			cout << "Выход есть. Смотрите карту." << endl;
			quit = true;
		}
		else if (!quit && labyrinth[i + 1][j] == '.')
		{
			labyrinth[i][j] = 'x';
			pathfinder(i + 1, j);
		}
		else if (!quit && labyrinth[i - 1][j] == '.')
		{
			labyrinth[i][j] = 'x';
			pathfinder(i - 1, j);
		}
		else if (!quit && labyrinth[i][j + 1] == '.')
		{
			labyrinth[i][j] = 'x';
			pathfinder(i, j + 1);
		}
		else if (!quit && labyrinth[i][j - 1] == '.')
		{
			labyrinth[i][j] = 'x';
			pathfinder(i, j - 1);
		}
		else if (!quit && labyrinth[i + 1][j] != '.' && labyrinth[i - 1][j] != '.' && labyrinth[i][j + 1] != '.' && labyrinth[i][j - 1] != '.')
		{
			labyrinth[i][j] = 'x';
			break;
		}
		overheat++;
	}
}

void author()
{
	cout << "Автор: Zinya the Slayer" << endl;
	cout << "Студент: Зеневич Алексей" << endl;
	cout << "Группа: 653502" << endl;
	cout << "Версия: PreRelease 0.1" << endl;
}
