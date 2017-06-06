#include "stdafx.h"
#include "iostream"
#include "string"
#include "conio.h"
using namespace std;

struct Word {
	char letter;
	Word *next;
	Word *previous;
};

Word *head = NULL;
Word *tail = NULL;

	
void list(char c) // создание списков
{
	Word *current;
		if (head == NULL)
		{
			head = new Word;
			head->letter = c;
			head->next = NULL;
			head->previous = NULL;
			tail = head;
		}
		else
		{
			current = new Word;
			current->letter = c;
			current->next = NULL;
			current->previous = tail;
			tail->next = current;
			tail = current;
		}
}

void main()
{
	for (;;)
	{
		char choice;
		int count = 0;
		char input[255] = {};

		system("cls");

		cout << "Enter your string: ";
		cin.getline(input, 255);
		for (int i = 0; i < strlen(input); i++)
		{
			// игнор знаков 
			if ((input[i] >= 65 && input[i] <= 90) || (input[i] >= 97 && input[i] <= 122) || (input[i]>=48 && input[i]<=57)) 
			{
				list(input[i]);
				count++;
			}
			else
			{
				continue;
			}
		}

		if (count == 0)
		{
			cout << "You didn't enter the words" << endl;
			goto a;
		}

		Word *begin = head;
		Word *end = tail;

		while (begin != end)
		{
			if ((begin->letter) != (end->letter))
			{
				break;
			}
			else
			{
				begin = begin->next;
				end = end->previous;
			}
		}

		if (begin == end)
		{
			cout << "Your string is a palindrome" << endl;      //должна быть именно(!) строка-палиндром
		}
		else cout << "Your string is not a palindrome" << endl;

		begin = NULL;
		end = NULL;
		head = NULL;
		tail = NULL;

	  a:cout << endl << endl << "Press any key to reload " << endl;
		cout << "Press 1 to exit";
		choice=_getch();
		if (choice == '1') exit(1);
	}
}