#include "stdafx.h"
#include "iostream"
#include "conio.h"
#include "ctime"

using namespace std;

int check()   // �������� �����
{
	char input[255];
	for (;;)
	{
		int count = 0;
		cin.getline(input, 255);
		for (int i = 0; input[i] != '\0'; i++)
		{
			if (input[i] < '0' || input[i]> '9')
			{
				count--;
				cout << "Try again" << endl;
				cin.clear();
				break;
			}
			else count++;
		}
		if (count == strlen(input)) break;
	}
	cin.clear();
	return atoi(input);
}

// ��� �����:
struct stack
{
	int i; // �����
	int d; // ��������
	struct stack *next;
};

void push(stack *&MainStack, int d, int i) // ���������� �����
{
	stack *NewStack = new stack;
	NewStack->d = d;
	NewStack->i = i;
	NewStack->next = MainStack; 
	MainStack = NewStack;
}

void pop(stack *&MainStack) // ����������� �� �����
{
	stack *buffer = MainStack;
	MainStack = MainStack->next;
	delete buffer;
}

// ��� ������:
struct node
{
	int d;
	int i;
	node *left;
	node *right;
};

void Build_Tree(stack *&MainStack, node *&root) //���������� ����
{
	if (root == NULL)
	{
		root = new node;
		root->i = MainStack->i;
		root->d = MainStack->d;
		root->left = NULL;
		root->right = NULL;
		return;
	}
	if (MainStack->d < root->d)
	{
		Build_Tree(MainStack, root->left);
	}
	else
	{
		Build_Tree(MainStack, root->right);
	}

}

void Show(node *&root)		// ������� �� �����������
{				// �.�. � ���������� ���� �� ����� �������
	if (root != 0)
	{
		Show(root->left);
		cout << root->i << "\t";
		cout << root->d << endl;
		Show(root->right);
	}

}

void Objective(node *&root, int &sum)
{
	if (root != 0)
	{
		sum += root->d;
		Objective(root->left, sum);
		Objective(root->right, sum);
	}
}

void main()
{
	for (;;)
	{
		system("cls");
		srand(unsigned(time(0)));
		int n = 0, e = 0;
		char choice = NULL;

		cout << "Input the number of trees: ";
		n = check();

		cout << "Input the number of elements of stack: "; // ��� ���������� ��������
		e = check();					// ��� ������� ���������� ����������� ����� ����� � ��� �����		   

		system("cls");

		for (int i = 1; i < n + 1; i++)
		{
			int sum = 0;
			cout << "Tree num." << i << ":" << endl << endl;
			node  *root = NULL;
			stack *MainStack = NULL;

			for (int j = 0; j < e; j++)
			{
				push(MainStack, rand() % 100 + 1, i);
			}

			for (int j = 0; j < e; j++)
			{
				Build_Tree(MainStack, root);
				pop(MainStack);

			}

			cout << "Index\tValue" << endl;
			Show(root);
			Objective(root, sum);
			cout << endl << "Sum of binary tree elements : " << sum;

			if (i != n)
			{
				cout << endl << "Press any key to continue: ";
				_getch();
				cout << endl << "-----------------------------------" << endl;
			}

			else
			{
				cout << endl << "-----------------------------------" << endl;
				cout << "Press Enter to reload program\nor Esc to Exit:" << endl;
				while (choice != 13 || choice != 27)
				{
					choice = _getch();
					if (choice == 13) break;
					if (choice == 27) exit(1);
				}
			}
		}
	}
}