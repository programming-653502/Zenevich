#include "stdafx.h"
#include "iostream"
#include "string"
#include "fstream"
#include "conio.h"
#include "windows.h"
using namespace std;

ofstream fout("cpp_in.txt", ios::app);
ifstream fin("cpp_in.txt");

int check() //�������� �����
{
	char input[255];
	for (;;) {
		int count = 0;
		cin.getline(input, 255);
		for (int i = 0; input[i] != '\0'; i++) {
			if (input[i] < '0' || input[i]> '9') {
				count--;
				cout << "������ �����" << endl;
				cin.clear();
				break;
			}
			else
				count++;
		}
		if (count == strlen(input))
			break;
	}
	cin.clear();
	return atoi(input);
}

struct studentList
{
	string name;
	string faculty;
	short year;
	short warning;
	int group;
	int roomNumber;

	studentList *next;
	studentList *prev;
};
studentList *head = NULL;
studentList *tail = NULL;

void addElement(string _name, string _faculty, short _year, short _warning, int _group) //���������� �������� � ������
{
	studentList *Buffer;
	if (head == NULL)
	{
		head = new studentList;
		head->name = _name;
		head->faculty = _faculty;
		head->year = _year;
		head->warning = _warning;
		head->group = _group;
		head->roomNumber = 0;
		head->next = NULL;
		head->prev = NULL;
		tail = head;
	}
	else
	{
		Buffer = new studentList;
		Buffer->name = _name;
		Buffer->faculty = _faculty;
		Buffer->year = _year;
		Buffer->warning = _warning;
		Buffer->group = _group;
		Buffer->roomNumber = 0;
		Buffer->next = NULL;
		Buffer->prev = tail;
		tail->next = Buffer;
		tail = Buffer;
	}
}

void newStudent()
{
	string name;
	string faculty; int choice = 0;
	short year;
	int group;

	system("cls");
	cout << "������� ��� ��������: ";
	getline(cin, name);

	cout << "�������� ��������� ��������:\n";
	cout << "1.��� 2.��� 3.��� 4.���� 5.��� 6.���� 7.��:\n";
	do {
		choice = check();
		if (choice > 7 || choice < 1)
			cout << "������ �����\n";
	} while (choice == 0 || choice > 7 || choice < 1);

	switch (choice)
	{
	case 1: 
		faculty = "���";
		break;
	case 2:
		faculty = "���";
		break;
	case 3:
		faculty = "���";
		break;
	case 4:
		faculty = "����";
		break;
	case 5:
		faculty = "���";
		break;
	case 6:
		faculty = "����";
		break;
	case 7:
		faculty = "��";
		break;
	}

	cout << "������� ���� ��������: ";
	do {
		year = check();
		if (year < 1 || year >5)
			cout << "�������� ���� �� 1 �� 5\n";
	} while (year == 0 || year < 1 || year > 5);

	cout << "������� ������ ��������: ";
	do {
		group = check();
		if(group < 10000 || group > 1000000)
			cout << "����� ������ ������ ���� �� 5 �� 6 ��������\n";
	} while (group < 10000 || group > 1000000);

	addElement(name, faculty, year, 0, group);
}

void showAll()
{
	system("cls");
	studentList *buffer = head;

	while (buffer != NULL)
	{
		cout << "������� �: " << buffer->roomNumber << endl;
		cout << "���: " << buffer->name << endl;
		cout << "���������: " << buffer->faculty << endl;
		cout << "������: " << buffer->group << endl;
		cout << "����: " << buffer->year << endl;
		cout << "��������������: " << buffer->warning << endl << endl;
		buffer = buffer->next;
	}
}

class Room {
private:
	bool available;
	short floor;
	int number;
	studentList *student;

public:
	Room() {}
	Room(int _number,short _floor)
	{
		available = true;
		number = _number;
		floor = _floor;
	}
	bool getAvailability()
	{
		return available;
	}
	void setAvailability(int choice)
	{
		if (choice == 1) available = false;
		if (choice == 2) available = true;
	}
	void setStudent()
	{
		student = tail;
	}

};

void roomFilling(Room *room) //���������� ������ �� �����������/������ 
{
	short floor;
	for (int i = 0; i < 210; i++)
	{
		if (i < 30) {
			if (i < 15) floor = 1;
			else floor = 2;
		}
		else if (i >= 30 && i < 60) {
			if (i < 45) floor = 3;
			else floor = 4;
		}
		else if (i >= 60 && i < 90) {
			if (i < 75) floor = 5;
			else floor = 6;
		}
		else if (i >= 90 && i < 120) {
			if (i < 105) floor = 7;
			else floor = 8;
		}
		else if (i >= 120 && i < 150) {
			if (i < 135) floor = 9;
			else floor = 10;
		}
		else if (i >= 150 && i < 180) {
			if (i < 165) floor = 11;
			else floor = 12;
		}
		else if (i >= 180 && i < 210) {
			if (i < 195) floor = 13;
			else floor = 14;
		}
		room[i] = { i , floor };
	}
}

void distribution(int facultyRooms, Room *room, int version) //������������� �� ��������
{
	bool flag = false;

	for (int i = facultyRooms; i < facultyRooms + 30; i++)
		if (room[i].getAvailability()) 
		{
			room[i].setStudent();
			room[i].setAvailability(1);
			cout << "������� ��� ������� ������ � ������� � " << i << endl << endl;
			tail->roomNumber = i;
			flag = true;
			break;
		}
	if (!flag)
	{
		tail->roomNumber = -1;
		cout << "��� ����� ������ ��� ����� ����������\n";
	}

	if (version == 1)
	{
		cout << "������� Enter ��� ������ � ����";
		_getch();
	}
}

void floorInfo(Room *room)
{
	system("cls");
	int firstCount = 0;  //����� �������
	int secondCount = 0; //������� ������
	int thirdCount = 0;  //������� ������� �� �����
	for (int i = 0; i < 210; i++) 
	{
		if (room[i].getAvailability() == false) 
		{
			firstCount++;
			thirdCount++;
		}
		if (i == 0)
			cout << "���:\n";
		else if (i == 30)
			cout << "���:\n";
		else if (i == 60)
			cout << "���:\n";
		else if (i == 90)
			cout << "����:\n";
		else if (i == 120)
			cout << "���:\n";
		else if (i == 150)
			cout << "����:\n";
		else if (i == 180)
			cout << "��:\n";
		else if (i % 15 == 0) 
		{
			secondCount++;
			cout << "�� " << secondCount << " � " << secondCount+1 << " ������ ����� " << thirdCount << " �������\n";
			thirdCount = 0;
		}
	}
	cout << endl << "����� ������� ����: " << firstCount << endl;
	cout << "����� ��������� ����: " << (210 - firstCount) << endl;
}

void roomInfo(int roomNumber,Room *room)
{
	if (room[roomNumber].getAvailability()) cout << "������� ��������\n";
	else
	{
		studentList *buffer = head;
		int count = 0;
		while (buffer != NULL)
		{
			if (count == roomNumber)
			{
				cout << "-------------------------------------------\n";
				cout << "������� ������\n";
				cout << "���: " << buffer->name << endl;
				cout << "���������: " << buffer->faculty << endl;
				cout << "������: " << buffer->group << endl;
				cout << "����: " << buffer->year << endl;
				cout << "��������������: " << buffer->warning << endl << endl;
			}
			count++;
			buffer = buffer->next;
		}
	}
}

void sendWarning(int choice, Room *room)
{
	system("cls");
	if (choice == 1)
	{
		bool flag = false;
		string findName;
		studentList *buffer = head;

		cout << "������� ���: \n";
		getline(cin, findName);
		while (buffer != NULL)
		{
			if (buffer->name == findName)
			{
				flag = true;
				buffer->warning++;
				cout << "�������������� ������\n";
				if (buffer->warning > 2) cout << "\n������� ������������ � ���������\n";
				break;
			}
			buffer = buffer->next;
		}
		if (!flag) cout << "C������ �� ������\n";
	}

	if (choice == 2)
	{
		bool flag = false;
		int findRoom;
		studentList *buffer = head;

		cout << "������� ����� �������: \n";
		cin >> findRoom;

		if (room[findRoom].getAvailability())
		{
			cout << "������� �� ������\n";
			return;
		}
		else {
			while (buffer != NULL)
			{
				if (buffer->roomNumber == findRoom)
				{
					flag = true;
					buffer->warning++;
					cout << "�������������� ������\n";
					if (buffer->warning > 2) cout << "\n������� ������������ � ���������\n";
					break;
				}
				buffer = buffer->next;
			}
			if (!flag) cout << "C������ �� ������\n";
		}
	}
	
}

void addToFile()
{
	ofstream fout("cpp_in.txt", ios::app);
	studentList *buffer = head;
	while (buffer != NULL)
	{
		fout << buffer->roomNumber << "\n";
		fout << buffer->name << "\n";
		fout << buffer->faculty << "\n";
		fout << buffer->group << "\n";
		fout << buffer->year << "\n";
		fout << buffer->warning << "\n";
		fout << "\n";
		buffer = buffer->next;
	}
	fout.close();
}

void addFromFile(Room *room)
{
	string name;
	string faculty;
	short year;
	short warning;
	int group;
	int roomNumber;
	ifstream fin("cpp_in.txt", ios::in);

	for (; !fin.eof();)
	{
		fin >> roomNumber;
		fin >> name;
		fin >> faculty;
		fin >> group;
		fin >> year;
		fin >> warning;
		if (fin.eof()) break;
		addElement(name, faculty, year, warning, group);
		distribution(roomNumber, room, 2);
	}
	fin.close();
	fout.close();
}

void deleting(int forDelete, Room* room)
{
	studentList *buffer = head;
	while (buffer != NULL)
	{
		if (buffer->roomNumber == forDelete)
		{
			if (buffer->next)
			{
				buffer->next->prev = buffer->prev;
			}
			else
			{
				tail = buffer->prev;
				if (tail) tail->next = NULL;
			}
			if (buffer->prev)
			{
				buffer->prev->next = buffer->next;
			}
			else
			{
				head = buffer->next;
				if (head) head->prev = NULL;
			}
			delete(buffer);
			buffer = NULL;
		}
		else
			buffer = buffer->next;
	}
	room[forDelete].setAvailability(2);
}


void main()
{
	system("color F1");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	Room room[210];
	roomFilling(room);
	
	for (;;)
	{
		system("cls");
		int secondCaseChoice;
		int thirdCaseChoice = 0;
		int fouthCaseChoice = 0;
		int fifthCaseChoice = 0;
		int choice = 0;
		cout << "���� ������ ��������� �����\n\n";
		cout << "1.��������� ��������\n\n";
		cout << "2.��������� ��������\n\n";                   
		cout << "3.������ �������\n\n";
		cout << "4.���������� � �������\n\n";
		cout << "5.�������� �������������� ��������\n\n";
		cout << "6.��������� ��� ���������� � �����\n\n";     
		cout << "7.�������� ��������� �� �����\n\n";                     
		cout << "8.����� �� ���������\n";
		while (!choice)
			choice = check();
		switch (choice)
		{

		case 1: 
			newStudent();
			if      (tail->faculty=="���")    distribution(0, room, 1);
			else if (tail->faculty == "���")  distribution(30, room, 1);
			else if (tail->faculty == "���")  distribution(60, room, 1);
			else if (tail->faculty == "����") distribution(90, room, 1);
			else if (tail->faculty == "���")  distribution(120, room, 1);
			else if (tail->faculty == "����") distribution(150, room, 1);
			else if (tail->faculty == "��")   distribution(180, room, 1);
			break;

		case 2:
			system("cls");
			showAll();
			cout << "\n\n����� ������� ����������?\n";

			do
				secondCaseChoice = check();
			while (secondCaseChoice < 0 || secondCaseChoice > 210);

			if (room[secondCaseChoice].getAvailability())
			{
				cout << "������� ������\n";
			}
			else {
				deleting(secondCaseChoice, room);
				cout << "������� ������� ���������\n";
			}
			
			cout << "������� Enter ��� ������ � ����";
			_getch();
			break;

		case 3:
			system("cls");
			cout << "1.������� ���� �������\n2.���������� �� ������\n";

			do
				thirdCaseChoice = check();
			while (thirdCaseChoice == 0 || thirdCaseChoice < 1 || thirdCaseChoice >2);
			
			if (thirdCaseChoice == 1) showAll();
			if (thirdCaseChoice == 2) floorInfo(room);
			cout << "������� Enter ��� ������ � ����";
			_getch();
			break;

		case 4:
			system("cls");
			cout << "������� ����� �������: ";

			do 
				fouthCaseChoice = check();
			while (fouthCaseChoice < 0 || fouthCaseChoice > 210);

			roomInfo(fouthCaseChoice,room);
			cout << "������� Enter ��� ������ � ����";
			_getch();
			break;

		case 5:
			system("cls");
			cout << "1.����� �������� �� �����\n2.�� ������ �������\n";

			do
				fifthCaseChoice = check();
			while (fifthCaseChoice <= 0 || fifthCaseChoice > 2);

			sendWarning(fifthCaseChoice,room);
			cout << "������� Enter ��� ������ � ����";
			_getch();
			break;

		case 6: 
			addToFile();
			cout << "\n �������� ������� ���������\n";
			cout << "������� Enter ��� ������ � ����";
			_getch();
			break;

		case 7: 
			addFromFile(room);
			cout << "\n �������� ������� ���������\n";
			cout << "������� Enter ��� ������ � ����";
			_getch();
			break;

		case 8:
			exit(1);
			break;

		default :
			continue;
		}
	}
}