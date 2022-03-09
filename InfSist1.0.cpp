#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <sstream>

using namespace std;

struct Products
{
	string nazvanie;
	double price;
	string date;
};

void menu()
{
	setlocale(LC_ALL, "rus");
	cout << "     Óïðàâëåíèå çàêàçàìè       \n";
	cout << "================================\n";
	cout << " 1. Ñìîòðåòü ñïèñîê çàêàçîâ.\n";
	cout << " 2. Äîáàâèòü çàêàç â ñïèñîê.\n";
	cout << " 3. Íàéòè çàêàç â ñïèñêå.\n";
	cout << " 4. Óäàëåíèå çàêàçà èç ñïèñêà.\n";
	cout << " 5. Âûéòè èç ìåíþ óïðàâëåíèÿ.\n";
	cout << " 6. Óäàëèòü ôàéë è âûéòè.\n";
	cout << "================================\n";
}


void EnteringOrders(Products* order, int B, const char list[]) // ôóíêöèÿ äîáàâëåíèÿ â ñèñò.
{
	ofstream OrderList("D:\\Proga\\zakazi.txt", ios::app);

	for (int j = 0; j < B; j++)
	{
		cin.get();
		cout << "\n Ââåäèòå íàçâàíèå ïðîäóêòà:  ";
		getline(cin, order[j].nazvanie);
		cout << endl;
		cout << "\n Ââåäèòå öåíó ïðîäóêòà (÷èñëî):  ";
		cin >> order[j].price;
		cout << endl;
		cout << "\n Ââåäèòå äàòó:  ";
		cin >> order[j].date;
		cout << endl;

		cin.get();
		cout << endl;
		cout << "Ïðîäóêò óñïåøíî äîáàâëåí!\n" << endl;
		system("pause");

		OrderList << "----------------------------------------------------------------\n";
		OrderList << "Íàçâàíèå: " << order[j].nazvanie << " | " << "Öåíà: " << order[j].price << " ðóáëåé" << " | ";
		OrderList << "Äàòà çàêàçà: " << order[j].date << '\n';
		OrderList << "----------------------------------------------------------------\n\n";
		cout << endl;
	}
}
int AddNewOrders(const char list[]) // ôóíêöèÿ äîáàâëåíèÿ â ëèñò
{
	int B;
	cout << "Ñêîëüêî ïðîäóêòîâ õîòèòå äîáàâèòü?\n" << endl;
	cin >> B;
	cout << endl;

	if (B < 1) // ïðîâåðêà íà öåëîå ÷èñëî çàêàçîâ
		cout << "Íåêîððåêòíîå ÷èñëî!\n" << endl;
	system("pause");
	if (B < 1) // åñëè íå öåëîå - çàâåðøåíèå ôóíêöèè
		return 0;

	Products* order = new Products[B]; // äèíàì. ìàññèâ êîë-âà ââåä¸ííûõ ïðîäóêòîâ
	EnteringOrders(order, B, list); // ôóíêöèÿ äîáàâëåíèÿ
	delete[] order;
	return 0;
}

void numberChoice(const char list[]) // âûáîð ôóíêöèé ñèñòåìû
{
	int i = 0;
	int j = -1;
	ifstream OrderList("D:\\Proga\\zakazi.txt");

	while (i <= 5)
	{
		system("cls");
		menu(); // âûçûâàåì ìåíþ óïðàâëåíèÿ
		cin >> i;
		switch (i)  // ââåä¸ííîå ÷èñëî ñîîòâåòñòâóåò êåéñó
		{
		case 1: // ïîêàç èñõîäíîãî ñïèñêà
		{
			ifstream OrderList(list);
			while (OrderList)
			{
				string s;
				getline(OrderList, s);
				cout << s << endl;
				j = j + 1;
			}

			if (j < 1)  // ïðîâåðêà íà ïóñòîé ëèñò
				cout << "Íåò çàêàçîâ!\n" << endl;

			cout << "Âåðíóòüñÿ íàçàä? ";
			system("pause");
			break;
		}

		case 2: // äîáàâëåíèå â ëèñò
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
			cout << "Ââåäèòå òî, ÷òî õîòèòå íàéòè" << endl;
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
		case 4: // óäàëåíèå èç ëèñòà
		{
			ifstream in;
			in.open("D:\\Proga\\zakazi.txt");
			ofstream out;
			out.open("D:\\Proga\\zakazi1.txt");

			string search;
			string line;
			cout << "Ââåäèòå òî, ÷òî õîòèòå óäàëèòü" << endl;
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
		case 5: // âûõîä
		{
			cout << "\nÄî ñâèäàíèÿ!\n";
			system("pause");
			exit(0);
			break;
		}
		case 6:
		{
			remove("D:\\Proga\\zakazi.txt");
			cout << "Óäàëåíèå óñïåøíî ïðîâåäåíî.\n";
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

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const char list[] = "D:\\Proga\\zakazi.txt";

	numberChoice(list);
}
