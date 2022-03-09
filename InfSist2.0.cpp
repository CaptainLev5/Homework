#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <sstream>

using namespace std;

class Products
{
public:
	string nazvanie;
	double price;
	string date;

public:

void menu()
{
	setlocale(LC_ALL, "rus");
	cout << "     ���������� ��������       \n";
	cout << "================================\n";
	cout << " 1. �������� ������ �������.\n";
	cout << " 2. �������� ����� � ������.\n";
	cout << " 3. ����� ����� � ������.\n";
	cout << " 4. �������� ������ �� ������.\n";
	cout << " 5. ����� �� ���� ����������.\n";
	cout << " 6. ������� ���� � �����.\n";
	cout << "================================\n";
}


void EnteringOrders(Products* order, int B, const char list[]) // ������� ���������� � ����.
{
	ofstream OrderList("D:\\Proga\\zakazi.txt", ios::app);

	for (int j = 0; j < B; j++)
	{
		cin.get();
		cout << "\n ������� �������� ��������:  ";
		getline(cin, order[j].nazvanie);
		cout << endl;
		cout << "\n ������� ���� �������� (�����):  ";
		cin >> order[j].price;
		cout << endl;
		cout << "\n ������� ����:  ";
		cin >> order[j].date;
		cout << endl;

		cin.get();
		cout << endl;
		cout << "������� ������� ��������!\n" << endl;
		system("pause");

		OrderList << "----------------------------------------------------------------\n";
		OrderList << "��������: " << order[j].nazvanie << " | " << "����: " << order[j].price << " ������" << " | ";
		OrderList << "���� ������: " << order[j].date << '\n';
		OrderList << "----------------------------------------------------------------\n\n";
		cout << endl;
	}
}
int AddNewOrders(const char list[]) // ������� ���������� � ����
{
	int B;
	cout << "������� ��������� ������ ��������?\n" << endl;
	cin >> B;
	cout << endl;

	if (B < 1) // �������� �� ����� ����� �������
		cout << "������������ �����!\n" << endl;
	system("pause");
	if (B < 1) // ���� �� ����� - ���������� �������
		return 0;

	Products* order = new Products[B]; // �����. ������ ���-�� �������� ���������
	EnteringOrders(order, B, list); // ������� ����������
	delete[] order;
	return 0;
}

void numberChoice(const char list[]) // ����� ������� �������
{
	int i = 0;
	int j = -1;
	ifstream OrderList("D:\\Proga\\zakazi.txt");

	while (i <= 5)
	{
		system("cls");
		menu(); // �������� ���� ����������
		cin >> i;
		switch (i)  // �������� ����� ������������� �����
		{
		case 1: // ����� ��������� ������
		{
			ifstream OrderList(list);
			while (OrderList)
			{
				string s;
				getline(OrderList, s);
				cout << s << endl;
				j = j + 1;
			}

			if (j < 1)  // �������� �� ������ ����
				cout << "��� �������!\n" << endl;

			cout << "��������� �����? ";
			system("pause");
			break;
		}

		case 2: // ���������� � ����
		{
			AddNewOrders(list);
			break;
		}
		case 3:
		{
			ifstream in;
			in.open("D:\\Proga\\zakazi.txt");

			string search;
			string line;
			cout << "������� ��, ��� ������ �����" << endl;
			cin >> search;

			while (getline(in, line)) {
				if (line.find(search) != -1) {
					cout << line.find(search) << endl;
					continue;
				}
			}

			in.close();

			//ifstream OrderList(list);
			//findOrder(OrderList);
			system("pause");

			break;
		}
		case 4: // �������� �� �����
		{
			ifstream in;
			in.open("D:\\Proga\\zakazi.txt");
			ofstream out;
			out.open("D:\\Proga\\zakazi1.txt");

			string search;
			string line;
			cout << "������� ��, ��� ������ �������" << endl;
			cin >> search;

			while (getline(in, line))
			{
				if (line.find(search) != -1)
				{
					cout << "Delete!" << endl;
					continue;
				}
				else
					out << line << endl;
			}

			in.close();
			out.close();

			remove("D:\\Proga\\zakazi.txt");
			rename("D:\\Proga\\zakazi1.txt", "D:\\Proga\\zakazi.txt");

			system("pause");
			break;
		}
		case 5: // �����
		{
			cout << "\n�� ��������!\n";
			system("pause");
			exit(0);
			break;
		}
		case 6:
		{
			remove("D:\\Proga\\zakazi.txt");
			cout << "�������� ������� ���������.\n";
			exit(0);
			break;
		}
		default:
		{
			break;
		}

		}
	}
}
};

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const char list[] = "D:\\Proga\\zakazi.txt";

	numberChoice(list);
}