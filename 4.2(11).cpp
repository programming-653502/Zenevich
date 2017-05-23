#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>

using namespace std;

int main()
{
	fstream file("C:\\Users\\Алексей\\Desktop\\File 4-2(11).txt", ios::in);

	//на случай, если файл не найден
	if (file.fail())
	{
		cout << "File does not exist!";

		exit(0);
	}
	
	//чтение файла
	file.seekg(0, ios::end);

	int file_length = file.tellg();

	file.seekg(0, ios::beg);

	char* file_buffer = new char[file_length];

	file.read(file_buffer, file_length);

	int number_of_abc = 26;

	int* number_of_letters = new int[number_of_abc];

	for (int i = 0; i < number_of_abc; i++) number_of_letters[i] = 0;

	//запись вхождений символов в файле
	for (int i = 0; i < file_length; i++)
	{
		if (file_buffer[i] >= 'a' && file_buffer[i] <= 'z')
		{
			number_of_letters[file_buffer[i] - 'a']++;
		}
	}

	//массив гистограммы
	char** histogram = new char*[100];
	for (int i = 0; i < 100; i++)
		histogram[i] = new char[number_of_abc];

	int summation_of_letters = 0;

	for (char i = 0; i <number_of_abc; i++) summation_of_letters += number_of_letters[i];

	//на случай, если в файле нет нужных символов
	if (summation_of_letters == 0)
	{
		cout << "There is no letters!";

		exit(0);
	}

	//построение гистограммы
	for (char i = 0; i < number_of_abc; i++)
	{
		int letter_percentage = (number_of_letters[i] * 100 / summation_of_letters);

		for (char j = 0; j < 100; j++)
		{
			if (j < letter_percentage) histogram[j][i] = '=';
			else histogram[j][i] = ' ';
		}
	}

	//вывод гистограммы
	for (int i = 99; i >= 0; i--)
	{
		for (char j = 0; j < number_of_abc; j++) cout << histogram[i][j] << " ";

		cout << endl;
	}

	for (char j = 'a'; j <= 'z'; j++) cout << j << " ";

	cout << endl << endl;

	//вывод кол-ва символов
	for (char i = 'a'; i <= 'z'; i++)
		if (number_of_letters[i - 'a'] != 0)
			cout << i << ": " << number_of_letters[i - 'a'] << endl;

	delete[] file_buffer;
	delete[] number_of_letters;
	delete[] histogram;
	
	file.close();
	_getch();
	return 0;
}
