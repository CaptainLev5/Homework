#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

int linesearch(int mass[], int n, int x)
{
	for (int i = 1; i < n; i++)
		if (mass[i] == x)
			return i;
	return -1;
}

int search_barier(int mass[], int n, int x)
{
	int i;
	n++;
	mass[n] = x;
	for (i = 0; mass[i] != x; i++);
	if (i == n)
		cout << "Number not found";
	else
		return i;
}

void buble_sortARRAY_LR(int arr[], int WB)
{
	for (int i = 0; i < WB; i++)
	{
		for (int j = i + 1; j < WB; j++)
		{
			if (*(arr + j) < *(arr + i))
				swap(*(arr + j), *(arr + i));
		}
	}
}
int binarysearch(int mass[], int n, int x)
{

	int left = 0;
	int right = n;
	bool flag = false;

	int mid;

	buble_sortARRAY_LR(mass, n);

	while ((left <= right) && (flag != true))
	{
		mid = (left + right) / 2;

		if (mass[mid] == x)
			flag = true; //��������� ���� �� ���������� ���������
		if (mass[mid] > x)
			right = mid - 1; // ���������, ����� ����� ����� ���������
		else
			left = mid + 1;
	}

	if (flag)
		cout << "(��������) ������ �������� " << x << " � ������� �����: " << mid << endl;
	else
		cout << "������ �������� � ������� ���" << endl;
	return -1;
}

int main()
{
	setlocale(LC_ALL, "rus");
	int n;
	do
	{
		cout << "Enter array of massive: ";
		cin >> n;
	} while (n > 1000);
	int mass[1000];

	srand(time(NULL));
	for (int i = 0; i < n; i++)
		mass[i] = 1 + rand() % 50;

	for (int i = 0; i < n; i++)
	{
		cout << "Mass [" << i + 1 << "] = " << mass[i] << endl;
	}

	cout << "Enter x to find: " << endl;
	int x;
	cin >> x;


	if (linesearch(mass, n, x) == -1)
		cout << "\nDidn't find!(1) " << endl;

	if (search_barier(mass, n, x) == -1)
		cout << "\nDidn't find!(2) " << endl;


	cout << "(��������) ������ �������� " << x << " � ������� �����: "
		<< linesearch(mass, n, x) + 1 << endl;

	cout << "(���������) ������ �������� " << x << " � ������� �����: " << search_barier(mass, n, x) + 1 << endl;
	cout << binarysearch(mass, n, x) << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Mass [" << i << "] = " << mass[i] << endl;
	}
	return 0;
}