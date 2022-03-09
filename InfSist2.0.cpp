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
	cout << "     Управление заказами       \n";
	cout << "================================\n";
	cout << " 1. Смотреть список заказов.\n";
	cout << " 2. Добавить заказ в список.\n";
	cout << " 3. Найти заказ в списке.\n";
	cout << " 4. Удаление заказа из списка.\n";
	cout << " 5. Выйти из меню управления.\n";
	cout << " 6. Удалить файл и выйти.\n";
	cout << "================================\n";
}


void EnteringOrders(Products* order, int B, const char list[]) // функция добавления в сист.
{
	ofstream OrderList("D:\\Proga\\zakazi.txt", ios::app);

	for (int j = 0; j < B; j++)
	{
		cin.get();
		cout << "\n Введите название продукта:  ";
		getline(cin, order[j].nazvanie);
		cout << endl;
		cout << "\n Введите цену продукта (число):  ";
		cin >> order[j].price;
		cout << endl;
		cout << "\n Введите дату:  ";
		cin >> order[j].date;
		cout << endl;

		cin.get();
		cout << endl;
		cout << "Продукт успешно добавлен!\n" << endl;
		system("pause");

		OrderList << "----------------------------------------------------------------\n";
		OrderList << "Название: " << order[j].nazvanie << " | " << "Цена: " << order[j].price << " рублей" << " | ";
		OrderList << "Дата заказа: " << order[j].date << '\n';
		OrderList << "----------------------------------------------------------------\n\n";
		cout << endl;
	}
}
int AddNewOrders(const char list[]) // функция добавления в лист
{
	int B;
	cout << "Сколько продуктов хотите добавить?\n" << endl;
	cin >> B;
	cout << endl;

	if (B < 1) // проверка на целое число заказов
		cout << "Некорректное число!\n" << endl;
	system("pause");
	if (B < 1) // если не целое - завершение функции
		return 0;

	Products* order = new Products[B]; // динам. массив кол-ва введённых продуктов
	EnteringOrders(order, B, list); // функция добавления
	delete[] order;
	return 0;
}

void numberChoice(const char list[]) // выбор функций системы
{
	int i = 0;
	int j = -1;
	ifstream OrderList("D:\\Proga\\zakazi.txt");

	while (i <= 5)
	{
		system("cls");
		menu(); // вызываем меню управления
		cin >> i;
		switch (i)  // введённое число соответствует кейсу
		{
		case 1: // показ исходного списка
		{
			ifstream OrderList(list);
			while (OrderList)
			{
				string s;
				getline(OrderList, s);
				cout << s << endl;
				j = j + 1;
			}

			if (j < 1)  // проверка на пустой лист
				cout << "Нет заказов!\n" << endl;

			cout << "Вернуться назад? ";
			system("pause");
			break;
		}

		case 2: // добавление в лист
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
			cout << "Введите то, что хотите найти" << endl;
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
		case 4: // удаление из листа
		{
			ifstream in;
			in.open("D:\\Proga\\zakazi.txt");
			ofstream out;
			out.open("D:\\Proga\\zakazi1.txt");

			string search;
			string line;
			cout << "Введите то, что хотите удалить" << endl;
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
		case 5: // выход
		{
			cout << "\nДо свидания!\n";
			system("pause");
			exit(0);
			break;
		}
		case 6:
		{
			remove("D:\\Proga\\zakazi.txt");
			cout << "Удаление успешно проведено.\n";
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